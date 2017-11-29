/*
 ************************************************************************************************************************************************************************
 ************************************************************************************************************************************************************************
 *			程序模块声明
 *
 *			文件:		FtpSendFile.c
 *			版本:		1.0
 *			作者:		XFW
 *			日期:		2016/11/30
 *			程序说明:
 
 *			亚奥数码技术有限公司版权所有 2016-2017
 *			
 ************************************************************************************************************************************************************************
 ************************************************************************************************************************************************************************
*/

/*
 ************************************************************************************************************************************************************************
 * 引用文件
 ************************************************************************************************************************************************************************
*/
#include <errno.h>
#include "FTPSendFile.h"
#include "LogEventServer.h"
#include "NetServer.h"
#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket
#include <sys/socket.h>    // for socket
#include <string.h>        // for bzero
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <unistd.h>
#include "sqlite3.h"
#include <signal.h>
#include <assert.h>

//#include "ConfigServer.h"

/*
 ************************************************************************************************************************************************************************
 * 常数与宏定义
 ************************************************************************************************************************************************************************
*/

#define DEBUG

//#define FTP_SENDFILE_FILE_NAME_LENGTH_MAX		50			//文件名最大字节长度
//#define FTP_SENDFILE_QUEUE_NODE_MAX				100		//队列中缓存的文件个数最大值
#define FTP_SENDFILE_WORKTHREAD_TIME_SLICE_US 	50*1000

#define FTP_SENDFILE_SERVER_IP_DEFAULT		"192.168.1.90"
#define FTP_SENDFILE_USER_NAME_DEFAULT		"xfw"
#define FTP_SENDFILE_PASSWORD_DEFAULT		"111111"
#define FTP_SENDFILE_PORT_DEFAULT			21
#define FTP_SENDFILE_MAX_UPLOAD_FILES		0


#define FTP_SENDFILE_WORK_DIR_DEFAULT		"/dvs/srv/ftp/PIC"
#define FTP_SENDFILE_FILE_MODIFY_TIME_MAX_S	10
#define FTP_SENDFILE_QUEUE_DATABUF_MAX		150
#define FTP_SENDFILE_LOG_FILE		"/tmp/log.txt"
#define FTP_SENDFILE_SYSTEM_CALLER_TIMEOUT			30

#define FTP_SENDFILE_DB_PATH	"/dvs/srv/config/ftpsendfile.db"
#define FTP_SENDFILE_DB_BUSY_TIMEOUT_MS				3000





#ifdef DEBUG
	#define JSYA_Printf printf 
	#define DPrintf printf
#else 
	#define JSYA_Printf(format,...) JSYA_LES_LogPrintf("FTP_SENDFILE",1,format,##__VA_ARGS__)
	#define DPrintf 
#endif	
/*
 ************************************************************************************************************************************************************************
 * 数据类型定义
 ************************************************************************************************************************************************************************
*/
typedef void * FTP_SENDFILE_QUEUE_HANDLE;
typedef struct __attribute__((packed)) _FTP_SENDFILE_QUEUE_DATA
{
	U32 	Reserve;
	//U32 DestDevAddr;
	U32 	DataLength;
	U8  	DataBuf[FTP_SENDFILE_QUEUE_DATABUF_MAX];
}FTP_SENDFILE_QUEUE_DATA,*PFTP_SENDFILE_QUEUE_DATA;

typedef struct __attribute__((packed)) _FTP_SENDFILE_QUEUE_NODE{	
	struct _FTP_SENDFILE_QUEUE_NODE *Next;	
	FTP_SENDFILE_QUEUE_DATA Data;
}FTP_SENDFILE_QUEUE_NODE;

typedef struct{	
	FTP_SENDFILE_QUEUE_NODE *Head;	
	FTP_SENDFILE_QUEUE_NODE *Tail;	
	//U32 Count;
}FTP_SENDFILE_QUEUE,*PFTP_SENDFILE_QUEUE;


typedef struct _FTP_SENDFILE_ACK
{
	 S32  m_RetCode;   /*0表示成功*/
	 U32  m_wReserved;
	 U8  m_strRetMsg[3*1024];
}FTP_SENDFILE_ACK,*PFTP_SENDFILE_ACK;

typedef enum _FTP_SENDFILE_SQLITE_MSG_RET_ENUM
{
	 RET_ENUM_SUCCESS=0,
	 RET_ENUM_FAILURE=1,
}FTP_SENDFILE_SQLITE_MSG_RET_ENUM;


typedef struct _FTP_SENDFILE_SQLITE_MSG
{
	 U8  FileName[40];   
	 U8  SendTime[20]; /*形如20161209110156(YYYYMMDDHHMMSS)*/
	 FTP_SENDFILE_SQLITE_MSG_RET_ENUM Ret;
}FTP_SENDFILE_SQLITE_MSG,*PFTP_SENDFILE_SQLITE_MSG;


typedef struct _FTP_SENDFILE_SERVER
{
	U8 						IsOpen;  													/*模块是否打开*/
	
	pthread_t				MainWorkThreadPID;											/*主工作线程所在进程号*/
	U8 						IsMainWorkThreadReqQuit;									/*主进程请求退出标志*/
	pthread_t				FTPWorkThreadPID;											/*FTP上传文件工作线程所在进程号*/
	U8 						IsFTPWorkThreadReqQuit;										/*线程请求退出标志*/							
	FTP_SENDFILE_CONFIG 	FtpConfig;														/*配置*/	
	//FTP_SENDFILE_QUEUE		SendFileQueue;
	U32						MainWorkThreadRunCount;
	U32						FTPWorkThreadRunCount;
	FTP_SENDFILE_ACK 		FtpSendFileAck;
	U32						MainWorkThreadLastCheckFileTime;			//最后一次检查文件时间，用于比对当前是否需要检查文件
	U32						FTPWorkThreadLastRunTime;					//FTP上传文件工作线程最后一次运行时间，用于检测线程是否被阻塞
	FTP_SENDFILE_QUEUE 		*pQueue;
	U8 						IsMainWorkThreadQuit;
	U8 						IsFTPWorkThreadQuit;
	U32						FTPSendFailCnt;
	U32						FTPSendFailCntContinuous;
	//FTP_SENDFILE_SQLITE_MSG RecordMsg;
}FTP_SENDFILE_SERVER, *PFTP_SENDFILE_SERVER;

/*
 ************************************************************************************************************************************************************************
 * 全局变量
 ************************************************************************************************************************************************************************
*/
static struct _FTP_SENDFILE_SERVER gFtpSendFileServer;
static pthread_mutex_t	FtpSendFileMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t	FtpSendFileSQLiteMutex = PTHREAD_MUTEX_INITIALIZER;
static FTP_SENDFILE_CONFIG gFtpDefConfig={FTP_SENDFILE_USER_NAME_DEFAULT,FTP_SENDFILE_PASSWORD_DEFAULT,FTP_SENDFILE_SERVER_IP_DEFAULT,
										FTP_SENDFILE_PORT_DEFAULT,FTP_SENDFILE_WORK_DIR_DEFAULT,FTP_SENDFILE_MAX_UPLOAD_FILES,0,NULL};

/*
 ************************************************************************************************************************************************************************
 * 函数
 ************************************************************************************************************************************************************************
*/
extern DWORD ConfigServerGetSysRunTime(BOOL IsInMs)
{
	static pthread_mutex_t	sSysRunTimeMutex=PTHREAD_MUTEX_INITIALIZER;
	static FILE 			*pUptimeFile=NULL;
	int 					OldStatus;
	DWORD					dwSysRunTime=0;
	double					RealSysRunTime=0;

	PTHREAD_MUTEX_SAFE_LOCK(sSysRunTimeMutex,OldStatus);
	if(NULL==pUptimeFile)
		pUptimeFile=fopen("/proc/uptime","r");
	if(NULL!=pUptimeFile)
	{
		fseek(pUptimeFile,0,SEEK_SET);
		fscanf(pUptimeFile,"%lf",&RealSysRunTime);
		fclose(pUptimeFile);
		dwSysRunTime=(DWORD)(IsInMs?RealSysRunTime*1000:RealSysRunTime);
	}
	pUptimeFile=NULL;
	PTHREAD_MUTEX_SAFE_UNLOCK(sSysRunTimeMutex,OldStatus);
	return dwSysRunTime;
}

/*
 ************************************************************************************************************************************************************************     
 *函数名称: FTP_SENDFILE_QueuePush
 *功能描述: 向队列添加数据
 *输入描述: 队列、节点数据
 *输出描述: 无
 *返回描述: TRUE成功/FALSE失败
 *作者日期: XFW
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
 */

static U32 FTP_SENDFILE_QueueListInit(FTP_SENDFILE_QUEUE **Queue)
{	
	FTP_SENDFILE_QUEUE *pTemp=NULL;	
	pTemp = (FTP_SENDFILE_QUEUE *)malloc(sizeof(FTP_SENDFILE_QUEUE));	
	if(pTemp==NULL){	
		fprintf(stderr,"%s ERROR:%s\n",__FUNCTION__,strerror(errno));
		return FALSE;	
	}	
	memset(pTemp,0,sizeof(FTP_SENDFILE_QUEUE));	
	*Queue = pTemp;	
	return TRUE;
}

static void FTP_SENDFILE_QueueListDeInit(FTP_SENDFILE_QUEUE **ppQueue)
{	
	FTP_SENDFILE_QUEUE_NODE *pTempHead=NULL;	
	FTP_SENDFILE_QUEUE_NODE *pTemp=NULL;	
	FTP_SENDFILE_QUEUE *pQueue=NULL;		

	DPrintf("@@@@@@@@@@ 准备释放队列所占用的空间...\r\n");
	if(*ppQueue!=NULL){		
		pQueue = *ppQueue;		
		pTempHead = pQueue->Head;		
		while(pTempHead!=NULL){			
			pTemp = pTempHead->Next;			
			free(pTempHead);			
			pTempHead = pTemp;		
		}		
		free(pQueue);		
		*ppQueue = NULL;	
	}
}

static U32 FTP_SENDFILE_QueuePush(FTP_SENDFILE_QUEUE *pQueue,PFTP_SENDFILE_QUEUE_DATA pReq)
{	
	FTP_SENDFILE_QUEUE_NODE *pNewNode=NULL;	
	int OldStatus;
	
	if((pQueue==NULL)||(pReq==NULL))		
		return FALSE;	
	
	pNewNode = (FTP_SENDFILE_QUEUE_NODE *)malloc(sizeof(FTP_SENDFILE_QUEUE_NODE));	
	if(pNewNode==NULL){		
		fprintf(stderr,"%s ERROR:%s\n",__FUNCTION__,strerror(errno));
		return FALSE;	
	}	
	
	memset(pNewNode,0,sizeof(FTP_SENDFILE_QUEUE_NODE));	
	memcpy(&pNewNode->Data,pReq,sizeof(FTP_SENDFILE_QUEUE_DATA));	
	PTHREAD_MUTEX_SAFE_LOCK(FtpSendFileMutex, OldStatus);
	if((pQueue->Head==NULL) && (pQueue->Tail==NULL)){		
		pQueue->Head = pQueue->Tail = pNewNode;	
	}else{		
		pQueue->Tail->Next = pNewNode;		
		pQueue->Tail = pNewNode;	
	}
	PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileMutex, OldStatus);
	return TRUE;
}

/*
 ************************************************************************************************************************************************************************     
 *函数名称: FTP_SENDFILE_QueuePop
 *功能描述: 从队列中弹出数据
 *输入描述: 队列
 *输出描述: 节点数据
 *返回描述: TRUE成功/FALSE失败
 *作者日期: XFW
 *全局声明: 无
 *特殊说明: 
 ************************************************************************************************************************************************************************       
 */
static U32 FTP_SENDFILE_QueueGetHead(FTP_SENDFILE_QUEUE *pQueue)
{	
	if((pQueue==NULL)||(pQueue->Head==NULL))		
		return FALSE;	
	
	return TRUE;
}

static U32 FTP_SENDFILE_QueuePop(FTP_SENDFILE_QUEUE *pQueue,PFTP_SENDFILE_QUEUE_DATA pReq)
{	
	FTP_SENDFILE_QUEUE_NODE *pDelNode=NULL; 
	int OldStatus;
	
	if((pQueue==NULL)||(pQueue->Head==NULL))		
		return FALSE;	
	
	PTHREAD_MUTEX_SAFE_LOCK(FtpSendFileMutex, OldStatus);
	pDelNode = pQueue->Head;		
	if(pReq!=NULL)		
		memcpy(pReq,&pDelNode->Data,sizeof(FTP_SENDFILE_QUEUE_DATA));	
	
	if(pQueue->Head==pQueue->Tail){ 	
		pQueue->Head = pQueue->Tail = NULL; 
	}else{		
		pQueue->Head = pDelNode->Next;	
	}		
	free(pDelNode); 
	PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileMutex, OldStatus);
	return TRUE;
}


static void InitParam(PFTP_SENDFILE_CONFIG pConfig,PFTP_SENDFILE_CONFIG pTempConfig)
{
	if((pConfig==NULL)||(pTempConfig==NULL))
		return;
	
	if(pConfig->UserName[0]=='\0'){
		strncpy(pConfig->UserName,pTempConfig->UserName,sizeof(pConfig->UserName)-1);
	}
	if(pConfig->PassWord[0]=='\0'){
		strncpy(pConfig->PassWord,pTempConfig->PassWord,sizeof(pConfig->PassWord)-1);
	}
	if(pConfig->Port==0){
		pConfig->Port = pTempConfig->Port;
	}
	if(pConfig->WorkDirectory[0]=='\0'){
		strncpy(pConfig->WorkDirectory,pTempConfig->WorkDirectory,sizeof(pConfig->WorkDirectory)-1);
	}
	if(pConfig->FtpServerIP[0]=='\0'){
		strncpy(pConfig->FtpServerIP,pTempConfig->FtpServerIP,sizeof(pConfig->FtpServerIP)-1);
	}
	if(pConfig->MaxRecordPerMonth==0){
		pConfig->MaxRecordPerMonth = pTempConfig->MaxRecordPerMonth;
	}
	if(pConfig->UploadedCnt==0){
		pConfig->UploadedCnt = pTempConfig->UploadedCnt;
	}
}

/*
分割文件全路径,比如:
FileName=/home/pi/test.txt,Dir=/home/pi/,Name=test.txt

pDir pName 可以为空

*/
static U32 FTP_SENDFILE_SplitFileName(U8 *pFileName,U8 *pDir,U8 *pName)
{
	U8 *pStart=NULL,*pTemp=NULL;
	
	if(pFileName==NULL)
		return FALSE;

	pStart=pFileName;
	do
	{
		pStart = strchr(pStart,'/');

		if(pStart==NULL)
			break;

		pTemp=pStart++;
		
	}while(1);
	if(pTemp==NULL)//未找到路径分隔符'/'
		return FALSE;
	
	if(pDir!=NULL)
	{
		strncpy(pDir,pFileName,pTemp-pFileName+1);
		pDir[pTemp-pFileName+1]='\0';
	}
	if(pName!=NULL)
		strcpy(pName,pTemp+1);
	
	return TRUE;
}


/*
	树莓派向Windows FTP上传全路径文件出错(ftpput: unexpected server response to STOR: 550 Filename invalid),
					怀疑是平台间的路径表示不一样
*/

static U32 FTP_SENDFILE_SendByFtp(U8 *pFileName,PFTP_SENDFILE_ACK pAck)
{
	U8 CmdBuf[1024]={0};
	U8 Dir[100]={0};
	U8 Name[100]={0};

	U16 Ret;
	FILE *pFile=NULL;

	
	if(pFileName==NULL)
		return FALSE;
	if(FALSE==FTP_SENDFILE_SplitFileName(pFileName,Dir,Name))
		return FALSE;
	
	/*memset(&CmdBuf,'\0',sizeof(CmdBuf));
	snprintf(CmdBuf,sizeof(CmdBuf)-1,"cd %s",Dir);
	system(CmdBuf);*/
	if(chdir(Dir))
	{
		JSYA_Printf("%s:chdir error:%s\r\n",__FUNCTION__,strerror(errno));
		return FALSE;
	}
	
	memset(&CmdBuf,'\0',sizeof(CmdBuf));
	snprintf(CmdBuf,sizeof(CmdBuf)-1,"busybox ftpput -u %s -p %s -P %u %s %s > %s 2>&1",\
			gFtpSendFileServer.FtpConfig.UserName,gFtpSendFileServer.FtpConfig.PassWord,\
			gFtpSendFileServer.FtpConfig.Port,gFtpSendFileServer.FtpConfig.FtpServerIP,\
			Name,FTP_SENDFILE_LOG_FILE);
	JSYA_Printf("%s:%s\r\n",__FUNCTION__,CmdBuf);
	Ret = system(CmdBuf);
	JSYA_Printf("%s:system(%s) Ret=%d\r\n",__FUNCTION__,CmdBuf,Ret);
	if(Ret)
	{
		if(pAck!=NULL)
		{
			if((Ret==(U16)-1)&&(errno != 0))
				pAck->m_RetCode = errno;
			else
				pAck->m_RetCode = Ret;
			pAck->m_wReserved = 0;
			pFile = fopen(FTP_SENDFILE_LOG_FILE,"r");
			if(NULL!=pFile)
			{
				fread(pAck->m_strRetMsg,1,sizeof(pAck->m_strRetMsg)-1,pFile);
				JSYA_Printf("%s:%s\r\n",__FUNCTION__,pAck->m_strRetMsg);
				fclose(pFile);
			}
		}
		
		return FALSE;
	}
	if(pAck!=NULL)
	{
		pAck->m_RetCode = Ret;
	}
	return TRUE;
}

static U32 FTP_SENDFILE_RecordMsg_Make(PFTP_SENDFILE_SQLITE_MSG pMsg,U8 *pFileName)
{
	//U8 pMsg=NULL,*pTemp=NULL;
	U8 FileName[40];
	U8 TimeBuffer[20];
	time_t rawtime;
	struct tm Localtm = { 0 };
	
	if((pMsg==NULL)||(pFileName==NULL))
		return FALSE;

	if(FALSE == FTP_SENDFILE_SplitFileName(pFileName,NULL,FileName))
		return FALSE;

	memset(TimeBuffer,'\0',sizeof(TimeBuffer));
	time(&rawtime);//==> rawtime=time(NULL);
	localtime_r(&rawtime,&Localtm);
	sprintf(TimeBuffer,"%.4d%.2d%.2d%.2d%.2d%.2d",1900+Localtm.tm_year,\
		1+Localtm.tm_mon,Localtm.tm_mday,Localtm.tm_hour,Localtm.tm_min,Localtm.tm_sec);
	strcpy(pMsg->FileName,FileName);
	strcpy(pMsg->SendTime,TimeBuffer);
		
	return TRUE;
}

static U32 FTP_SENDFILE_CreatConfigTable(char *pDB)
{
	sqlite3 *		DBHandle=NULL;
	int				nrow=0,ncolumn=0;
	char **			azResult;
	char *			zErrMsg=NULL;
	int				rc,Len;
	char			sql[4096]={0};
	char			Utf8Sql[8192]={0};

    rc=sqlite3_open(pDB,&DBHandle);
    if(rc!=SQLITE_OK)
	{
		JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,sqlite3_errstr(rc));
        sqlite3_close(DBHandle);
		return FALSE;
    }
	snprintf(sql,sizeof(sql)-1,\
		"CREATE TABLE config("\
			"UserName TEXT DEFAULT 'fsuUser',"\
			"Password TEXT DEFAULT 'yaao@abc#123',"\
			"ServerIP TEXT NOT NULL DEFAULT '10.2.0.1',"\
			"Port INTEGER NOT NULL DEFAULT 21,"\
			"WorkDirectory TEXT NOT NULL DEFAULT '/dvs/srv/ftp/PIC',"\
			"MaxRcdPerMonth INTEGER NOT NULL DEFAULT 1500,"\
			"AlreadyUploadedCnt INTEGER NOT NULL DEFAULT 0);"\
			);
	Len=sizeof(Utf8Sql);
	rc=sqlite3_busy_timeout(DBHandle,FTP_SENDFILE_DB_BUSY_TIMEOUT_MS);
	if(PublicUtf8StrEncode(sql,Utf8Sql,&Len))
		rc=sqlite3_exec(DBHandle,Utf8Sql,NULL,NULL,&zErrMsg);
	else
		rc=sqlite3_exec(DBHandle,sql,NULL,NULL,&zErrMsg);
	if(rc!=SQLITE_OK)
	{
		if(zErrMsg)
		{
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,zErrMsg);
			sqlite3_free(zErrMsg);
			zErrMsg=NULL;
		}
	}
	
    sqlite3_close(DBHandle);               
    return rc==SQLITE_OK?TRUE:FALSE;
}

static U32 FTP_SENDFILE_CreatSentFileTable(char *pDB)
{
	sqlite3 *		DBHandle=NULL;
	int				nrow=0,ncolumn=0;
	char **			azResult;
	char *			zErrMsg=NULL;
	int				rc,Len;
	char			sql[4096]={0};
	char			Utf8Sql[8192]={0};

    rc=sqlite3_open(pDB,&DBHandle);
    if(rc!=SQLITE_OK)
	{
		JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,sqlite3_errstr(rc));
        sqlite3_close(DBHandle);
		return FALSE;
    }
	snprintf(sql,sizeof(sql)-1,"CREATE TABLE SentFileTable(NodeID INTEGER PRIMARY KEY AUTOINCREMENT,FileName VARCHAR(40),SendTime VARCHAR(20));");
	Len=sizeof(Utf8Sql);
	rc=sqlite3_busy_timeout(DBHandle,FTP_SENDFILE_DB_BUSY_TIMEOUT_MS);
	if(PublicUtf8StrEncode(sql,Utf8Sql,&Len))
		rc=sqlite3_exec(DBHandle,Utf8Sql,NULL,NULL,&zErrMsg);
	else
		rc=sqlite3_exec(DBHandle,sql,NULL,NULL,&zErrMsg);
	if(rc!=SQLITE_OK)
	{
		if(zErrMsg)
		{
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,zErrMsg);
			sqlite3_free(zErrMsg);
			zErrMsg=NULL;
		}
	}
	
    sqlite3_close(DBHandle);               
    return rc==SQLITE_OK?TRUE:FALSE;
}

static U32 FTP_SENDFILE_Insert_FileName(char *pDB,PFTP_SENDFILE_SQLITE_MSG pMsg)
{
	sqlite3 *		DBHandle=NULL;
	int				nrow=0,ncolumn=0;
	char **			azResult;
	char *			zErrMsg=NULL;
	int				rc,Len;
	char			sql[4096]={0};
	char			Utf8Sql[8192]={0};

	if((pMsg==NULL)||(pDB==NULL))
		return FALSE;
    rc=sqlite3_open(pDB,&DBHandle);
    if(rc!=SQLITE_OK)
	{
		JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,sqlite3_errstr(rc));
        sqlite3_close(DBHandle);
		return FALSE;
    }
	snprintf(sql,sizeof(sql)-1,"INSERT INTO SentFileTable VALUES(NULL,'%s','%s');",pMsg->FileName,pMsg->SendTime);
	Len=sizeof(Utf8Sql);
	rc=sqlite3_busy_timeout(DBHandle,FTP_SENDFILE_DB_BUSY_TIMEOUT_MS);
	if(PublicUtf8StrEncode(sql,Utf8Sql,&Len))
		rc=sqlite3_exec(DBHandle,Utf8Sql,NULL,NULL,&zErrMsg);
	else
		rc=sqlite3_exec(DBHandle,sql,NULL,NULL,&zErrMsg);
	if(rc!=SQLITE_OK)
	{
		if(zErrMsg)
		{
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,zErrMsg);
			sqlite3_free(zErrMsg);
			zErrMsg=NULL;
		}
	}
	
    sqlite3_close(DBHandle);               
    return rc==SQLITE_OK?TRUE:FALSE;
}

static U32 FTP_SENDFILE_Select_FileName(char *pDB,PFTP_SENDFILE_SQLITE_MSG pMsg)
{
	sqlite3 *		DBHandle=NULL;
	int				nrow=0,ncolumn=0;
	char **			azResult;
	char *			zErrMsg=NULL;
	int				rc,Len;
	char			SqlBuf[4096]={0};
	char			Utf8Sql[8192]={0};

	if((pMsg==NULL)||(pDB==NULL))
		return FALSE;
    rc=sqlite3_open(pDB,&DBHandle);
    if(rc!=SQLITE_OK)
	{
		JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,sqlite3_errstr(rc));
        sqlite3_close(DBHandle);
		return FALSE;
    }
	
	snprintf(SqlBuf,sizeof(SqlBuf)-1,"SELECT FileName FROM SentFileTable WHERE FileName='%s';",pMsg->FileName);
	rc=sqlite3_busy_timeout(DBHandle,FTP_SENDFILE_DB_BUSY_TIMEOUT_MS);
	rc=sqlite3_get_table(DBHandle,SqlBuf,&azResult,&nrow,&ncolumn,&zErrMsg);
	if(rc!=SQLITE_OK)
	{
		if(zErrMsg)
		{
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,zErrMsg);
			sqlite3_free(zErrMsg);
			zErrMsg=NULL;
		}
		else
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,sqlite3_errstr(rc));
	}
	else
	{
		if(nrow>0)
		{
			pMsg->Ret = RET_ENUM_SUCCESS;
		}
		else
		{
			pMsg->Ret = RET_ENUM_FAILURE;
			JSYA_Printf("查询数据库表(SentFileTable)发现文件%s没有上传记录...\r\n",pMsg->FileName);
		}
	}

	sqlite3_free_table(azResult);
	sqlite3_close(DBHandle);
	return rc==SQLITE_OK?TRUE:FALSE;

}

static void DeSpaceChar(char *str, int Length)
{
	char*s	= str + Length - 1;
	
	while (s > str)
	{
		if (*s == ' ')
			*s	= '\0';
		else
			break;
		s	--;
	}
}

static void Getsqlitechar(char *dst,char *azResult,size_t dwLen)
{
	if(azResult!=NULL)
	{
		int	Len=dwLen;

		if(!PublicUtf8StrDecode(azResult,dst,&Len))
			strncpy(dst,azResult,dwLen-1);
	}
	else
		memset(dst,0,dwLen);
}


static U32 FTP_SENDFILE_GetParamFromDB(char *pDB,PFTP_SENDFILE_CONFIG pConfig)
{
	sqlite3 *		DBHandle=NULL;
	int				nrow=0,ncolumn=0;
	char **			azResult;
	char *			zErrMsg=NULL;
	int				rc,Len;
	char			SqlBuf[4096]={0};
	char			Utf8Sql[8192]={0};

	if((pConfig==NULL)||(pDB==NULL))
		return FALSE;
    rc=sqlite3_open(pDB,&DBHandle);
    if(rc!=SQLITE_OK)
	{
		JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,sqlite3_errstr(rc));
        sqlite3_close(DBHandle);
		return FALSE;
    }
	snprintf(SqlBuf,sizeof(SqlBuf)-1,"SELECT * FROM config;");
	rc=sqlite3_busy_timeout(DBHandle,FTP_SENDFILE_DB_BUSY_TIMEOUT_MS);
	rc=sqlite3_get_table(DBHandle,SqlBuf,&azResult,&nrow,&ncolumn,&zErrMsg);
	if(rc!=SQLITE_OK)
	{
		if(zErrMsg)
		{
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,zErrMsg);
			sqlite3_free(zErrMsg);
			zErrMsg=NULL;
		}
		else
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,sqlite3_errstr(rc));
	}
	else
	{
		if((nrow==1)&&(ncolumn>=7))
		{
			int tcolumn = ncolumn*1;//偏移到第二行(第一行为列名称)
			
			Getsqlitechar(pConfig->UserName,azResult[tcolumn++],FTP_SENDFILE_STRING_LEN_MAX);
			Getsqlitechar(pConfig->PassWord,azResult[tcolumn++],FTP_SENDFILE_STRING_LEN_MAX);
			Getsqlitechar(pConfig->FtpServerIP,azResult[tcolumn++],FTP_SENDFILE_STRING_LEN_MAX);
			pConfig->Port = (U16)atoi(azResult[tcolumn++]);
			Getsqlitechar(pConfig->WorkDirectory,azResult[tcolumn++],FTP_SENDFILE_STRING_LEN_MAX);
			pConfig->MaxRecordPerMonth = (U32)atoi(azResult[tcolumn++]);
			pConfig->UploadedCnt = (U32)atoi(azResult[tcolumn++]);
		}
	}

	sqlite3_free_table(azResult);
	sqlite3_close(DBHandle);
	return rc==SQLITE_OK?TRUE:FALSE;

}

#define FTP_SENDFILE_UPDATE_ALREADY_UPLOADED_CNT 	1
#define FTP_SENDFILE_UPDATE_MAX_RECORD_PER_MONTH	2

static U32 FTP_SENDFILE_UPDATE(char *pDB,U32 Param,void *pValue)
{
	sqlite3 *		DBHandle=NULL;
	int				nrow=0,ncolumn=0;
	char **			azResult;
	char *			zErrMsg=NULL;
	int				rc,Len;
	char			SqlBuf[4096]={0};
	char			Utf8Sql[8192]={0};
	PFTP_SENDFILE_CONFIG pConfig=pValue;
	
	if(pDB==NULL)
		return FALSE;
	
    rc=sqlite3_open(pDB,&DBHandle);
    if(rc!=SQLITE_OK)
	{
		JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,sqlite3_errstr(rc));
        sqlite3_close(DBHandle);
		return FALSE;
    }
	switch(Param)
	{
		
		case FTP_SENDFILE_UPDATE_ALREADY_UPLOADED_CNT:
			snprintf(SqlBuf,sizeof(SqlBuf)-1,"UPDATE config SET AlreadyUploadedCnt=%u;",*(U32 *)pValue);
			break;
		default:
			sqlite3_close(DBHandle);
			return FALSE;
			break;
	}
	Len=sizeof(Utf8Sql);
	rc=sqlite3_busy_timeout(DBHandle,FTP_SENDFILE_DB_BUSY_TIMEOUT_MS);
	if(PublicUtf8StrEncode(SqlBuf,Utf8Sql,&Len))
		rc=sqlite3_exec(DBHandle,Utf8Sql,NULL,NULL,&zErrMsg);
	else
		rc=sqlite3_exec(DBHandle,SqlBuf,NULL,NULL,&zErrMsg);
	if(rc!=SQLITE_OK)
	{
		if(zErrMsg)
		{
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,zErrMsg);
			sqlite3_free(zErrMsg);
			zErrMsg=NULL;
		}
	}
	JSYA_Printf("SQLITE: %s:%s\r\n",__FUNCTION__,Utf8Sql);
    sqlite3_close(DBHandle);         
	return rc==SQLITE_OK?TRUE:FALSE;
}

#define FTP_SENDFILE_SaveUploadedCnt(pValue) FTP_SENDFILE_UPDATE(FTP_SENDFILE_DB_PATH,FTP_SENDFILE_UPDATE_ALREADY_UPLOADED_CNT,(void *)pValue)



static U32 FTP_SENDFILE_SetParamToDB(char *pDB,void *pValue)
{
	sqlite3 *		DBHandle=NULL;
	int				nrow=0,ncolumn=0;
	char **			azResult;
	char *			zErrMsg=NULL;
	int				rc,Len;
	char			SqlBuf[4096]={0};
	char			Utf8Sql[8192]={0};
	PFTP_SENDFILE_CONFIG pConfig=pValue;
	
	if(pDB==NULL)
		return FALSE;
	
    rc=sqlite3_open(pDB,&DBHandle);
    if(rc!=SQLITE_OK)
	{
		JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,sqlite3_errstr(rc));
        sqlite3_close(DBHandle);
		return FALSE;
    }
	strcpy(Utf8Sql,"DELETE FROM config;");
	rc=sqlite3_busy_timeout(DBHandle,FTP_SENDFILE_DB_BUSY_TIMEOUT_MS);
	rc=sqlite3_exec(DBHandle,Utf8Sql,NULL,NULL,&zErrMsg);
	JSYA_Printf("SQLITE: %s:%s\r\n",__FUNCTION__,Utf8Sql);
	if(rc!=SQLITE_OK)
	{
		if(zErrMsg)
		{
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,zErrMsg);
			sqlite3_free(zErrMsg);
			zErrMsg=NULL;
    		sqlite3_close(DBHandle);         
			return rc==SQLITE_OK?TRUE:FALSE;
		}
	}
	
	snprintf(SqlBuf,sizeof(SqlBuf)-1,\
		"INSERT INTO config "\
		"(UserName,Password,ServerIP,Port,WorkDirectory,MaxRcdPerMonth,AlreadyUploadedCnt) "\
		"VALUES ('%s','%s','%s',%u,'%s',%u,%u);",\
		pConfig->UserName,pConfig->PassWord,pConfig->FtpServerIP,pConfig->Port,\
		pConfig->WorkDirectory,pConfig->MaxRecordPerMonth,pConfig->UploadedCnt);
	
	Len=sizeof(Utf8Sql);
	rc=sqlite3_busy_timeout(DBHandle,FTP_SENDFILE_DB_BUSY_TIMEOUT_MS);
	if(PublicUtf8StrEncode(SqlBuf,Utf8Sql,&Len))
		rc=sqlite3_exec(DBHandle,Utf8Sql,NULL,NULL,&zErrMsg);
	else
		rc=sqlite3_exec(DBHandle,SqlBuf,NULL,NULL,&zErrMsg);
	if(rc!=SQLITE_OK)
	{
		if(zErrMsg)
		{
			JSYA_Printf("SQLITE: %s:%s...\r\n",__FUNCTION__,zErrMsg);
			sqlite3_free(zErrMsg);
			zErrMsg=NULL;
		}
	}
	JSYA_Printf("SQLITE: %s:%s\r\n",__FUNCTION__,Utf8Sql);
    sqlite3_close(DBHandle);         
	return rc==SQLITE_OK?TRUE:FALSE;
}

/*
 ************************************************************************************************************************************************************************     
 *函数名称: 
 *功能描述: 
 *输入描述: 
 *输出描述: 
 *返回描述: 
 *作者日期: XFW
 *全局声明: gFtpSendFileServer,FtpSendFileMutex
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
 */
static void *MainWorkProcess(void *pArg)
{

	FTP_SENDFILE_QUEUE_DATA QueueData;

	DIR *dir;
	struct dirent *pDir;
	struct stat FileStat; 
    U8 FileNameTemp[100];
	FTP_SENDFILE_SQLITE_MSG RecordMsg;
	FTP_SENDFILE_QUEUE_DATA SendFileName;
	int OldStatus;
	
	JSYA_Printf("主工作线程(PID=%d 线程号:%u)开始启动...\r\n",getpid(),pthread_self());

	for(; ;)
	{
		gFtpSendFileServer.IsMainWorkThreadQuit = FALSE;
		
		if(gFtpSendFileServer.IsMainWorkThreadReqQuit==TRUE)
		{
			DPrintf("gFtpSendFileServer.IsMainWorkThreadReqQuit is TRUE\n");
			gFtpSendFileServer.IsMainWorkThreadReqQuit = FALSE;
			DPrintf("gFtpSendFileServer.IsMainWorkThreadReqQuit is TRUE,Then set false\n");
			break;
		}
		pthread_testcancel();
		usleep(50*1000);
		gFtpSendFileServer.MainWorkThreadLastCheckFileTime = time(NULL);
		
		for(; ;)
		{
			gFtpSendFileServer.IsMainWorkThreadQuit = FALSE;
			
			if(gFtpSendFileServer.IsMainWorkThreadReqQuit==TRUE){
				DPrintf("gFtpSendFileServer.IsMainWorkThreadReqQuit is TRUE\n");
				break;
			}
			pthread_testcancel();
			usleep(50*1000);
			
			if((gFtpSendFileServer.MainWorkThreadRunCount%1000)== 0)
				JSYA_Printf("主工作线程(PID=%d 线程号:%u RunCount:%u)正在运行...\r\n",getpid(),pthread_self(),gFtpSendFileServer.MainWorkThreadRunCount);

			//定时检测文件
			if(((time(NULL)-gFtpSendFileServer.MainWorkThreadLastCheckFileTime)>=FTP_SENDFILE_FILE_MODIFY_TIME_MAX_S)
				&&(gFtpSendFileServer.FtpConfig.UploadedCnt<gFtpSendFileServer.FtpConfig.MaxRecordPerMonth))
			{
				gFtpSendFileServer.MainWorkThreadLastCheckFileTime = time(NULL);
				if ((dir=opendir(gFtpSendFileServer.FtpConfig.WorkDirectory)) == NULL)
				{
					JSYA_Printf("主工作线程Open dir(%s) error...\r\n",gFtpSendFileServer.FtpConfig.WorkDirectory);
					break;
				}

				while ((pDir=readdir(dir)) != NULL)
			    {
			        if(strcmp(pDir->d_name,".")==0 || strcmp(pDir->d_name,"..")==0)    ///current dir OR parrent dir
			            continue;
			        else if(pDir->d_type == 8)    ///file
			        {
						memset(FileNameTemp,'\0',sizeof(FileNameTemp));
						strcpy(FileNameTemp,gFtpSendFileServer.FtpConfig.WorkDirectory);
			            strcat(FileNameTemp,"/");
			            strcat(FileNameTemp,pDir->d_name); 
						
						if(access(FileNameTemp,0)!=-1)
						{
							JSYA_Printf("主工作线程正在检查文件(%s)\n\r",FileNameTemp);
							if(stat(FileNameTemp,&FileStat)==-1)
							{
								JSYA_Printf("stat(%s) error:(%s)\n\r",FileNameTemp,strerror(errno));
								continue;
							}
							if((gFtpSendFileServer.MainWorkThreadLastCheckFileTime - FileStat.st_mtime)<=(FTP_SENDFILE_FILE_MODIFY_TIME_MAX_S+1))
							{
								JSYA_Printf("主工作线程发现有新修改文件(%s),当前检测开始时间(%u),上次修改时间(%u)\n\r",\
									FileNameTemp,gFtpSendFileServer.MainWorkThreadLastCheckFileTime,FileStat.st_mtime);
								memset(&RecordMsg,0,sizeof(FTP_SENDFILE_SQLITE_MSG));
								if(FALSE == FTP_SENDFILE_RecordMsg_Make(&RecordMsg,FileNameTemp))
									continue; 
								PTHREAD_MUTEX_SAFE_LOCK(FtpSendFileSQLiteMutex,OldStatus);
								if(FTP_SENDFILE_Select_FileName(FTP_SENDFILE_DB_PATH,&RecordMsg)
									&&(RecordMsg.Ret == RET_ENUM_SUCCESS))//检查该文件是否上传成功(比对数据库)
								{
									PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileSQLiteMutex,OldStatus);
									JSYA_Printf("主工作线程读取数据库发现文件(%s)已经上传成功\n\r",FileNameTemp);
									
								}
								else
								{
									PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileSQLiteMutex,OldStatus);
									memset(&SendFileName,'\0',sizeof(SendFileName));	
									SendFileName.DataLength = strlen(FileNameTemp);
									strcpy(SendFileName.DataBuf,FileNameTemp);
									DPrintf("主工作线程 准备插入队列\r\n");
									if(FALSE == FTP_SENDFILE_QueuePush(gFtpSendFileServer.pQueue,&SendFileName)){
										DPrintf("主工作线程 插入队列失败pQueue=%p\r\n",gFtpSendFileServer.pQueue);
									}else{
										JSYA_Printf("主工作线程将文件名称(%s)压入缓冲队列Queue(%p):Head(%p)Tail(%p)\n\r",\
											SendFileName.DataBuf,gFtpSendFileServer.pQueue,gFtpSendFileServer.pQueue->Head,gFtpSendFileServer.pQueue->Tail);
									}
								}
							}
							
						}
						else
							JSYA_Printf("主工作线程发现文件(%s)不存在\n\r",FileNameTemp);
			        }
			        else
			        {
			        	JSYA_Printf("主工作线程发现非正常意义文件(%s/%s),设备类型为:%u(4-dir 10-link file etc...)\n\r",\
							gFtpSendFileServer.FtpConfig.WorkDirectory,pDir->d_name,pDir->d_type);
			        }
			    }
			    closedir(dir);
			}

			//检查FTP工作线程是否被阻塞
			/*if((time(NULL)-gFtpSendFileServer.FTPWorkThreadLastRunTime)>FTP_SENDFILE_SYSTEM_CALLER_TIMEOUT)
			{
				JSYA_Printf("主工作线程发现FTP上传文件工作线程被阻塞,即将关闭busybox ftpput:killall -s 9 -w busybox\n\r");
				system("killall -s 9 -w busybox");//杀死busybox同名进程,-s 发送信号9(SIGKILL)而不是SIGTERM,-w 等待被杀的进程结束
			}*/
			
			gFtpSendFileServer.MainWorkThreadRunCount++;
			usleep(FTP_SENDFILE_WORKTHREAD_TIME_SLICE_US);
		}
		usleep(FTP_SENDFILE_WORKTHREAD_TIME_SLICE_US);	
	}
	gFtpSendFileServer.IsMainWorkThreadQuit = TRUE;
	DPrintf("gFtpSendFileServer.IsMainWorkThreadQuit is TRUE\n");
	return NULL;		
}
static void *FtpWorkProcess(void *pArg)
{

	FTP_SENDFILE_QUEUE_DATA QueueData;
	
	FTP_SENDFILE_SQLITE_MSG Msg;
	int OldStatus;
	
	JSYA_Printf("FTP发送文件工作线程(PID=%d 线程号:%u)开始启动...\r\n",getpid(),pthread_self());
	for(; ;)
	{
		gFtpSendFileServer.IsFTPWorkThreadQuit = FALSE;
		if (gFtpSendFileServer.IsFTPWorkThreadReqQuit==TRUE)
		{
			DPrintf("gFtpSendFileServer.IsFTPWorkThreadReqQuit is TRUE\n");
			gFtpSendFileServer.IsFTPWorkThreadReqQuit		= FALSE;
			DPrintf("gFtpSendFileServer.IsFTPWorkThreadReqQuit is TRUE,Then set false\n");
			break;
		}
		pthread_testcancel();

		for (; ;)
		{
			gFtpSendFileServer.IsFTPWorkThreadQuit = FALSE;
			
			if(gFtpSendFileServer.IsFTPWorkThreadReqQuit==TRUE){
				DPrintf("gFtpSendFileServer.IsFTPWorkThreadReqQuit is TRUE\n");
				break;
			}
				
			pthread_testcancel();
			gFtpSendFileServer.FTPWorkThreadLastRunTime = time(NULL);
			
			if((gFtpSendFileServer.FTPWorkThreadRunCount%1000)==0)
				JSYA_Printf("FTP发送文件工作线程(PID=%d 线程号:%u RunCount:%u)正在运行...\r\n",getpid(),pthread_self(),gFtpSendFileServer.FTPWorkThreadRunCount);

			if((TRUE == FTP_SENDFILE_QueueGetHead(gFtpSendFileServer.pQueue))
				&&(gFtpSendFileServer.FtpConfig.UploadedCnt<gFtpSendFileServer.FtpConfig.MaxRecordPerMonth))//队列非空
			{
				JSYA_Printf("FTP发送文件工作线程发现当前有文件需要上传\r\n");
				memset(&QueueData,'\0',sizeof(FTP_SENDFILE_QUEUE_DATA));
				if(FALSE == FTP_SENDFILE_QueuePop(gFtpSendFileServer.pQueue,&QueueData)){
					DPrintf("FTP发送文件工作线程 FTP_SENDFILE_QueuePop false...\r\n");
					continue;
				}
				/*************************   ftpput [OPTIONS] HOST [REMOTE_FILE] LOCAL_FILE   *********/
				if(access(QueueData.DataBuf,0)!=-1)
				{
					memset(&Msg,0,sizeof(FTP_SENDFILE_SQLITE_MSG));
					//strcpy(Msg.FileName,QueueData.DataBuf);
					if(FALSE == FTP_SENDFILE_RecordMsg_Make(&Msg,QueueData.DataBuf))
						continue; 
					PTHREAD_MUTEX_SAFE_LOCK(FtpSendFileSQLiteMutex,OldStatus);
					if(FTP_SENDFILE_Select_FileName(FTP_SENDFILE_DB_PATH,&Msg)
						&&(Msg.Ret == RET_ENUM_SUCCESS))//检查该文件是否上传成功(比对数据库)
					{
						JSYA_Printf("FTP发送文件工作线程读取数据库发现文件(%s)已经上传成功\n\r",Msg.FileName);
						PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileSQLiteMutex,OldStatus);
						continue;
					}
					else
					{
						//JSYA_Printf("FTP发送文件工作线程读取数据库发现文件(%s)未上传\n\r",Msg.FileName);
					}
					PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileSQLiteMutex,OldStatus);
					if(FALSE == FTP_SENDFILE_SendByFtp(QueueData.DataBuf,&gFtpSendFileServer.FtpSendFileAck))
					{
						gFtpSendFileServer.FTPSendFailCnt++;
						gFtpSendFileServer.FTPSendFailCntContinuous++;
						JSYA_Printf("FTP发送文件工作线程通过FTP上传文件(%s)失败(FailCnt:%u,FailCntContinuous:%u):%s\r\n",QueueData.DataBuf,\
							gFtpSendFileServer.FTPSendFailCnt,gFtpSendFileServer.FTPSendFailCntContinuous,strerror(gFtpSendFileServer.FtpSendFileAck.m_RetCode));
						if(TRUE == FTP_SENDFILE_QueuePush(gFtpSendFileServer.pQueue,&QueueData)){
							JSYA_Printf("FTP发送文件工作线程重新将记录插入到队列中\r\n");
						}
					}
					else
					{
						//JSYA_Printf("FTP发送文件工作线程通过FTP上传文件成功,准备插入数据库\r\n");
						memset(&Msg,0,sizeof(FTP_SENDFILE_SQLITE_MSG));
						if(TRUE == FTP_SENDFILE_RecordMsg_Make(&Msg,QueueData.DataBuf))
						{
							PTHREAD_MUTEX_SAFE_LOCK(FtpSendFileSQLiteMutex,OldStatus);
							if(FTP_SENDFILE_Insert_FileName(FTP_SENDFILE_DB_PATH,&Msg))
								JSYA_Printf("FTP发送文件工作线程将(FileName:%s,SendTime:%s)插入数据库成功\r\n",Msg.FileName,Msg.SendTime);
							else
								JSYA_Printf("FTP发送文件工作线程将(FileName:%s,SendTime:%s)插入数据库失败\r\n",Msg.FileName,Msg.SendTime);
							PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileSQLiteMutex,OldStatus);
							
						}
						gFtpSendFileServer.FtpConfig.UploadedCnt++;	
						gFtpSendFileServer.FTPSendFailCntContinuous = 0;
					}
				}
				else
				{
					JSYA_Printf("FTP发送文件工作线程发现文件(%s)不存在\n\r",QueueData.DataBuf);
				}
				
			}else{
				
			}
				
			
			gFtpSendFileServer.FTPWorkThreadRunCount++;
			usleep(FTP_SENDFILE_WORKTHREAD_TIME_SLICE_US);
		}
		usleep(FTP_SENDFILE_WORKTHREAD_TIME_SLICE_US);
	}
	gFtpSendFileServer.IsFTPWorkThreadQuit = TRUE;
	DPrintf("gFtpSendFileServer.IsFTPWorkThreadQuit is TRUE\n");
	return NULL;
}
extern U32 FtpSendFile_Open(PFTP_SENDFILE_CONFIG pConfig)
{
	
	if(gFtpSendFileServer.IsOpen)
	{
		JSYA_Printf("模块已经打开,请先关闭后再打开...\r\n");
		return TRUE;
	}
	if(pConfig != NULL)
	{
		memset(&gFtpSendFileServer,0,sizeof(FTP_SENDFILE_SERVER));
		gFtpSendFileServer.FtpConfig = *pConfig;
	}
	else
	{
		InitParam(&gFtpSendFileServer.FtpConfig,&gFtpDefConfig);
		
		JSYA_Printf("模块打开,未指定配置参数,启用默认配置(FtpServerIP:%s,UserName:%s,PassWord:%s,WorkDirectory:%s,Port:%u)....\r\n",\
			gFtpSendFileServer.FtpConfig.FtpServerIP,gFtpSendFileServer.FtpConfig.UserName,\
			gFtpSendFileServer.FtpConfig.UserName,gFtpSendFileServer.FtpConfig.WorkDirectory,\
			gFtpSendFileServer.FtpConfig.Port);
	}
	
	FTP_SENDFILE_QueueListInit(&gFtpSendFileServer.pQueue);
	DPrintf(" FTP_SENDFILE_QueueListInit(pQueue=%p)\n",gFtpSendFileServer.pQueue);
	
	gFtpSendFileServer.IsMainWorkThreadQuit = TRUE;
	gFtpSendFileServer.IsFTPWorkThreadQuit = TRUE;
	JSYA_Printf("准备创建模块工作线程(MainWorkThreadPID=0x%x)...\r\n",gFtpSendFileServer.MainWorkThreadPID);
	if(pthread_create(&gFtpSendFileServer.MainWorkThreadPID,NULL,MainWorkProcess,NULL)==0){
		gFtpSendFileServer.IsMainWorkThreadReqQuit = FALSE;
		JSYA_Printf("创建模块工作线程成功(MainWorkThreadPID=0x%x)...\r\n",gFtpSendFileServer.MainWorkThreadPID);
		JSYA_Printf("准备创建模块工作线程(FTPWorkThreadPID=0x%x)...\r\n",gFtpSendFileServer.FTPWorkThreadPID);
		if(pthread_create(&gFtpSendFileServer.FTPWorkThreadPID,NULL,FtpWorkProcess,NULL)==0){
			gFtpSendFileServer.IsFTPWorkThreadReqQuit = FALSE;
			JSYA_Printf("创建模块工作线程成功(FTPWorkThreadPID=0x%x)...\r\n",gFtpSendFileServer.FTPWorkThreadPID);
			gFtpSendFileServer.IsOpen = TRUE;
			return TRUE;
		}else{
			pthread_cancel(gFtpSendFileServer.FTPWorkThreadPID);
			pthread_join(gFtpSendFileServer.FTPWorkThreadPID,NULL);
		}
	}else{
		pthread_cancel(gFtpSendFileServer.MainWorkThreadPID);
		pthread_join(gFtpSendFileServer.MainWorkThreadPID,NULL);
	}	
		
OpenFail:
	JSYA_Printf("模块工作线程创建失败(%s)...\r\n",strerror(errno));
	gFtpSendFileServer.IsOpen = FALSE;
	return FALSE;
}

extern void FtpSendFile_Close(void)
{
	if(gFtpSendFileServer.IsOpen)
	{
		if(gFtpSendFileServer.FTPWorkThreadPID!=INVALID_PTHREAD_ID)
			gFtpSendFileServer.IsFTPWorkThreadReqQuit = TRUE;

		usleep(PTHREAD_DEFAULT_QUIT_TIMEOUT_US);
		if((gFtpSendFileServer.FTPWorkThreadPID!=INVALID_PTHREAD_ID)
			&&(gFtpSendFileServer.IsFTPWorkThreadReqQuit == TRUE)){
			DPrintf("Send cancel To FTPWorkThreadPID\n");
			pthread_cancel(gFtpSendFileServer.FTPWorkThreadPID);
		}
		
		DPrintf("等待FTP发送文件工作线程退出...\r\n");
		pthread_join(gFtpSendFileServer.FTPWorkThreadPID,NULL);
		JSYA_Printf("等待FTP发送文件工作线程退出完成!...\r\n");
		
		if(gFtpSendFileServer.MainWorkThreadPID!=INVALID_PTHREAD_ID)
			gFtpSendFileServer.IsMainWorkThreadReqQuit = TRUE;
		
		usleep(PTHREAD_DEFAULT_QUIT_TIMEOUT_US);
		if((gFtpSendFileServer.MainWorkThreadPID!=INVALID_PTHREAD_ID)
			&&(gFtpSendFileServer.IsMainWorkThreadReqQuit == TRUE)){
			DPrintf("Send cancel To MainWorkThreadPID\n");
			pthread_cancel(gFtpSendFileServer.MainWorkThreadPID);
		}
		
		DPrintf("等待主工作线程退出...\r\n");
		pthread_join(gFtpSendFileServer.MainWorkThreadPID,NULL);
		JSYA_Printf("等待主工作线程退出完成!...\r\n");
		
		memset(&gFtpSendFileServer,0,sizeof(FTP_SENDFILE_SERVER));
		
	}
	FTP_SENDFILE_QueueListDeInit(&gFtpSendFileServer.pQueue);
}
static void print_usage(void)
{
	fprintf(stdout,"This program implements the file to FTP server in the specified directory...\r\n");
	fprintf(stdout,"Usage: ftpsendfile [-u UserName] [-p Password] [-P Port] [-d WordDirtory] [-M MaxUploadFilesCnt] [-h Help] [-s ftpServerIP]\r\n");
	fprintf(stdout,"    ftpsendfile -h\n\n");
	fprintf(stdout,"-u : The user name to be used for server authentication.\n");
	fprintf(stdout,"-p : The password to be used for server authentication.\n");
	fprintf(stdout,"-P : The port which server specified,21 default.\n");
	fprintf(stdout,"-d : The root directory which files is in.\n");
	fprintf(stdout,"-M : Maximum number of uploaded files per month, 0 default.if the value is \"0\",The number of files will be unlimited\n");
	fprintf(stdout,"-s : FTP server IP which the file will be uploaded to\n");
	fprintf(stdout,"-h : Show help\n");
}


static int config_load(int argc,char **argv,PFTP_SENDFILE_CONFIG pConfig)
{
	int i,ch,rc=0,OldStatus;
	FTP_SENDFILE_CONFIG TempConfig;
		
	if(pConfig==NULL)
	{
		return 0;
	}
	memset(pConfig,0,sizeof(FTP_SENDFILE_CONFIG));
	while((ch=getopt(argc,argv,"u:p:P:d:M:s:h"))!=-1){
		switch(ch)
		{
			case 'u':
				if(strlen(optarg)>FTP_SENDFILE_STRING_LEN_MAX){
					fprintf(stderr, "Error: -u argument given but invalid(\"%s\").\n",optarg);
					strcpy(pConfig->UserName,FTP_SENDFILE_USER_NAME_DEFAULT);
				}else{
					strcpy(pConfig->UserName,(void *)optarg);
				}
				break;
			case 'p':
				if(strlen(optarg)>FTP_SENDFILE_STRING_LEN_MAX){
					fprintf(stderr, "Error: -p argument given but invalid(\"%s\").\n",optarg);
					strcpy(pConfig->PassWord,FTP_SENDFILE_PASSWORD_DEFAULT);
				}else{
					strcpy(pConfig->PassWord,(void *)optarg);
				}
				break;
			case 'P':
				if(strlen(optarg)>FTP_SENDFILE_STRING_LEN_MAX){
					fprintf(stderr, "Error: -P argument given but invalid(\"%s\").\n",optarg);
					pConfig->Port = FTP_SENDFILE_PORT_DEFAULT;
				}else{
					pConfig->Port = (U16)atoi((void *)optarg);
				}
				break;
			case 'd':
				if(strlen(optarg)>FTP_SENDFILE_STRING_LEN_MAX){
					fprintf(stderr, "Error: -d argument given but invalid(\"%s\").\n",optarg);
					strcpy(pConfig->WorkDirectory,FTP_SENDFILE_WORK_DIR_DEFAULT);
				}else{
					strcpy(pConfig->WorkDirectory,(void *)optarg);
				}
				break;
			case 'M':
				if(strlen(optarg)>FTP_SENDFILE_STRING_LEN_MAX){
					fprintf(stderr, "Error: -M argument given but invalid.\n");
					pConfig->MaxRecordPerMonth = (U32)FTP_SENDFILE_MAX_UPLOAD_FILES;
				}else{
					pConfig->MaxRecordPerMonth = (U32)atoi((void *)optarg);
				}
				break;
			case 's':
				if(strlen(optarg)>FTP_SENDFILE_STRING_LEN_MAX){
					fprintf(stderr, "Error: -s argument given but invalid.\n");
					strcpy(pConfig->FtpServerIP,FTP_SENDFILE_SERVER_IP_DEFAULT);
				}else{
					strcpy(pConfig->FtpServerIP,(void *)optarg);
				}
				break;
			case 'h':
				rc = 1;
				break;
			case ':':
				fprintf(stderr, "Error: argument -%c given but invalid.\n",optopt);
				rc = 1;
				return rc;
				break;
			default:
				fprintf(stderr, "Error: argument -%c not define.\n",ch,optopt);
				rc = 1;
				return rc;
				break;
		}
	}
	PTHREAD_MUTEX_SAFE_LOCK(FtpSendFileSQLiteMutex,OldStatus);
	FTP_SENDFILE_GetParamFromDB(FTP_SENDFILE_DB_PATH,&TempConfig);
	PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileSQLiteMutex,OldStatus);
	DPrintf("FTP_SENDFILE_GetParamFromDB UserName=\"%s\",PassWord=\"%s\",FtpServerIP=\"%s\",Port=%d,WorkDir=\"%s\",MaxRecordPermonth=%u,UploadedCnt=%u\r\n",\
				TempConfig.UserName,TempConfig.PassWord,TempConfig.FtpServerIP,TempConfig.Port,\
				TempConfig.WorkDirectory,TempConfig.MaxRecordPerMonth,TempConfig.UploadedCnt);
	InitParam(pConfig,&TempConfig);
	DPrintf("TempConfig InitParam:UserName=\"%s\",PassWord=\"%s\",FtpServerIP=\"%s\",Port=%d,WorkDir=\"%s\",MaxRecordPermonth=%u,UploadedCnt=%u\r\n",\
				pConfig->UserName,pConfig->PassWord,pConfig->FtpServerIP,pConfig->Port,\
				pConfig->WorkDirectory,pConfig->MaxRecordPerMonth,pConfig->UploadedCnt);
	InitParam(pConfig,&gFtpDefConfig);
	DPrintf("gFtpDefConfig InitParam:UserName=\"%s\",PassWord=\"%s\",FtpServerIP=\"%s\",Port=%d,WorkDir=\"%s\",MaxRecordPermonth=%u,UploadedCnt=%u\r\n",\
				pConfig->UserName,pConfig->PassWord,pConfig->FtpServerIP,pConfig->Port,\
				pConfig->WorkDirectory,pConfig->MaxRecordPerMonth,pConfig->UploadedCnt);
	return rc;
}

static void signal_handler(int SigNo){
	JSYA_Printf("##########   catch  signal %d\n",SigNo);

	FtpSendFile_Close();
	signal(SigNo,SIG_DFL);
	raise(SigNo);
}

static void signal_nohandler(int SigNo){
	JSYA_Printf("##########   catch  signal %d\n",SigNo);
	signal(SigNo,SIG_DFL);
	raise(SigNo);
}

static void SysSignalProcessorInstall(void)
{
	signal(SIGBUS,signal_nohandler);
	signal(SIGSEGV,signal_handler);
	signal(SIGILL,signal_nohandler);
	signal(SIGFPE,signal_nohandler);
	signal(SIGTRAP,signal_nohandler);
	signal(SIGSYS,signal_nohandler);
	signal(SIGSTKFLT,signal_nohandler);
	signal(SIGABRT,signal_nohandler);

	signal(SIGPWR,signal_nohandler);
	signal(SIGTTIN,signal_nohandler);
	signal(SIGTTOU,signal_nohandler);
	signal(SIGXCPU,signal_nohandler);
	signal(SIGXFSZ,signal_nohandler);
	signal(SIGUSR1,signal_nohandler);
	signal(SIGUSR2,signal_nohandler);

	signal(SIGTERM,signal_handler);
	signal(SIGINT,signal_handler);
	signal(SIGQUIT,signal_handler);
	signal(SIGHUP,signal_nohandler);

	signal(SIGPIPE,signal_nohandler);
	signal(SIGIO,signal_nohandler);
	signal(SIGTSTP,signal_nohandler);
	signal(SIGALRM,signal_nohandler);
	signal(SIGVTALRM,signal_nohandler);
	signal(SIGPROF,signal_nohandler);
}
static int InitFtpSentFileDB(char *pDir)
{
	FILE *fp=NULL;
	int rc=0;
	
	assert(pDir!=NULL);

	if(access(pDir,0)==-1){
		DPrintf("Find %s unaccess,then creat it!\n",pDir);
		fp = fopen(pDir,"wb+");
		if(fp==NULL){
			rc = -1;
			return rc;
		}
		fclose(fp);
		FTP_SENDFILE_CreatConfigTable(pDir);
		FTP_SENDFILE_CreatSentFileTable(pDir);
	}
	return rc;
}

extern int main(int argc,char **argv)
{
	int rc,OldStatus;
	U32 LastUploadedCnt=0;
	U32 IsClearCnt=0;
	time_t  stime;
	struct tm nowTime;
	PFTP_SENDFILE_CONFIG pConfig=NULL; 
	
	SysSignalProcessorInstall();
	
	PTHREAD_MUTEX_SAFE_LOCK(FtpSendFileSQLiteMutex,OldStatus);
	InitFtpSentFileDB(FTP_SENDFILE_DB_PATH);
	PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileSQLiteMutex,OldStatus);
	
	pConfig = (PFTP_SENDFILE_CONFIG)malloc(sizeof(FTP_SENDFILE_CONFIG));
	if(pConfig!=NULL){
		rc = config_load(argc,argv,pConfig);
		LastUploadedCnt = pConfig->UploadedCnt;
		if(rc==0){
			JSYA_Printf("config_load Succ!UserName=\"%s\",PassWord=\"%s\",FtpServerIP=\"%s\",Port=%d,WorkDir=\"%s\",MaxRecordPermonth=%u,UploadedCnt=%u\r\n",\
				pConfig->UserName,pConfig->PassWord,pConfig->FtpServerIP,pConfig->Port,\
				pConfig->WorkDirectory,pConfig->MaxRecordPerMonth,pConfig->UploadedCnt);
			FtpSendFile_Open(pConfig);
			PTHREAD_MUTEX_SAFE_LOCK(FtpSendFileSQLiteMutex,OldStatus);
			FTP_SENDFILE_SetParamToDB(FTP_SENDFILE_DB_PATH,pConfig);
			PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileSQLiteMutex,OldStatus);
			free(pConfig);
		}else{
			print_usage();
			
			return 1;
		}
	}else{
		fprintf(stderr,"%s\n",strerror(errno));
	}
	
	while(1){
		if(LastUploadedCnt!=gFtpSendFileServer.FtpConfig.UploadedCnt){
			PTHREAD_MUTEX_SAFE_LOCK(FtpSendFileSQLiteMutex,OldStatus);
			if(TRUE==FTP_SENDFILE_SaveUploadedCnt(&gFtpSendFileServer.FtpConfig.UploadedCnt)){
				LastUploadedCnt=gFtpSendFileServer.FtpConfig.UploadedCnt; 
				DPrintf("Main SaveUploadedCnt Succ:%u\n",LastUploadedCnt);
			}
			PTHREAD_MUTEX_SAFE_UNLOCK(FtpSendFileSQLiteMutex,OldStatus);	
		}
		//判断是否是月初，若是，则保存计数清零
	 	stime = time(NULL);
	 	localtime_r(&stime, &nowTime);
		if((nowTime.tm_mday==1)&&(nowTime.tm_hour==0)
			&&(nowTime.tm_min==0)&&(!IsClearCnt)){
			gFtpSendFileServer.FtpConfig.UploadedCnt = 0;
			IsClearCnt = 1;
			DPrintf("Main IsClearCnt = 1\n");
		}else if(nowTime.tm_min!=0){
			IsClearCnt = 0;
		}

		//检查FTP工作线程是否被阻塞
		if(((time(NULL)-gFtpSendFileServer.FTPWorkThreadLastRunTime)>FTP_SENDFILE_SYSTEM_CALLER_TIMEOUT)
			&&(gFtpSendFileServer.IsFTPWorkThreadQuit==FALSE))
		{
			JSYA_Printf("主工作线程发现FTP上传文件工作线程被阻塞,即将关闭busybox ftpput:killall -s 9 -w busybox\n\r");
			system("killall -s 9 -w busybox");//杀死busybox同名进程,-s 发送信号9(SIGKILL)而不是SIGTERM,-w 等待被杀的进程结束
		}
		sleep(1);
	}
}
