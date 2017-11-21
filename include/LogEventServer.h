#ifndef _LOG_EVENT_SERVER_H_
#define _LOG_EVENT_SERVER_H_

#ifdef	__cplusplus
#if		__cplusplus
extern "C" {
#endif
#endif
/*
 ************************************************************************************************************************************************************************
 ************************************************************************************************************************************************************************
 *			程序模块声明
 *
 *			文件:		LogEventServer.h
 *			版本:		1.0
 *			作者:		曾春桥
 *			日期:		2006/10/08
 *
 *			亚奥数码技术有限公司版权所有 2006-2007
 *
 ************************************************************************************************************************************************************************
 ************************************************************************************************************************************************************************
*/




/*
 ************************************************************************************************************************************************************************
 * 程序模块功能描述
 *
 *
 ************************************************************************************************************************************************************************
*/




/*
 ************************************************************************************************************************************************************************
 * 版本 1.0   2006/10/08
 * 初始化版本 
 ************************************************************************************************************************************************************************
*/




/*
 ************************************************************************************************************************************************************************
 * 引用文件
 ************************************************************************************************************************************************************************
*/

#include "Common.h"




/*
 ************************************************************************************************************************************************************************
 * 常数与宏定义
 ************************************************************************************************************************************************************************
*/


#define LOG_EVENT_PRINTF_ENABLE				1
#define LOG_EVENT_UDP_PRINTF_ENABLE			1
#define LOG_EVENT_LOG_PRINTF_ENABLE			1

#if LOG_EVENT_PRINTF_ENABLE
	#if LOG_EVENT_LOG_PRINTF_ENABLE
		#define PRINTF(format,...)			JSYA_LES_LogPrintf(NULL,LOG_EVENT_LEVEL_DEF,format,##__VA_ARGS__)
	#elif LOG_EVENT_UDP_PRINTF_ENABLE
		#define PRINTF						LES_UdpPrintf
	#else
		#define PRINTF						printf
	#endif
#else
	#define PRINTF							LES_NoPrintf
#endif
#define LOGPRINTF(format,...)				JSYA_LES_LogPrintf(NULL,LOG_EVENT_LEVEL_DEF,format,##__VA_ARGS__)




#define LOG_EVENT_LEVEL_EMERG				0
#define LOG_EVENT_LEVEL_ALERT				1
#define LOG_EVENT_LEVEL_CRIT				2
#define LOG_EVENT_LEVEL_ERR					3
#define LOG_EVENT_LEVEL_WARNING				4
#define LOG_EVENT_LEVEL_NOTICE				5
#define LOG_EVENT_LEVEL_INFO				6
#define LOG_EVENT_LEVEL_DEBUG				7

#define LOG_EVENT_LEVEL_DEF					LOG_EVENT_LEVEL_INFO
#define LOG_EVENT_LEVEL_OUT_LIMIT_DEF		LOG_EVENT_LEVEL_INFO
#define LOG_EVENT_LEVEL_SAVE_LIMIT_DEF		LOG_EVENT_LEVEL_NOTICE


#define LOG_SAVE_DAYS_MIN					1
#define LOG_SAVE_DAYS_MAX					30
#define LOG_SAVE_DAYS_DEF					7


#define LOG_EVENT_OWNER_NAME_DEF			"Unknow"


/*
 ************************************************************************************************************************************************************************
 * 数据类型定义
 ************************************************************************************************************************************************************************
*/


typedef int (*PLES_CALLBACK)(void *pMsgBuf,unsigned long MsgLen,void *pCallbackContext);


	
/*
 ************************************************************************************************************************************************************************
 * 函数原型声明
 ************************************************************************************************************************************************************************
*/


#define LES_InitLogPath								JSYA_LES_InitLogPath
#define LES_NoPrintf								JSYA_LES_NoPrintf
#define LES_ConfigDebugServerAddr					JSYA_LES_ConfigDebugServerAddr
#define LES_UdpPrintf								JSYA_LES_UdpPrintf
#define LES_ConfigCallback							JSYA_LES_ConfigCallback


/*
 ************************************************************************************************************************************************************************     
 *函数名称: JSYA_LES_NoPrintf
 *功能描述: 忽略调试输出哑函数
 *输入描述: 标准可变输入
 *输出描述: 无
 *返回描述: 无
 *作者日期: ZCQ/2007/01/26
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
 */
extern int JSYA_LES_NoPrintf(const char *format, ...);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: JSYA_LES_ConfigDebugServerAddr
 *功能描述: 配置调试接收服务器地址
 *输入描述: 调试接收服务器地址以及端口
 *输出描述: 无
 *返回描述: 无
 *作者日期: ZCQ/2008/03/24
 *全局声明: sLocalMutex,sDebugNetAddr,sIsAddrReady,sLocalFd
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
 */
extern void JSYA_LES_ConfigDebugServerAddr(DWORD dwServerIP,WORD wServerPort);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: JSYA_LES_UdpPrintf
 *功能描述: 调试信息UDP模式格式化输出
 *输入描述: 格式化输出标准可变输入
 *输出描述: 无
 *返回描述: 实际输出字节数
 *作者日期: ZCQ/2013/01/22
 *全局声明: sLocalFd，sLocalMutex,sDebugNetAddr,sIsAddrReady,sSysLogFilePath
 *特殊说明: 自动初始化全局变量；各种输出方式输出优先级：首先回调函数，然后依次是网络输出、日志文件输出、标准输出；同一时间最多只有一种输出方式工作
 ************************************************************************************************************************************************************************       
 */
extern int JSYA_LES_UdpPrintf(const char *format, ...);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: JSYA_LES_LogPrintf
 *功能描述: 系统日志格式化输出
 *输入描述: 日志产生属主名、输出级别、标准格式化输出模板、可变输出变量
 *输出描述: 无
 *返回描述:	实际输出字节数
 *作者日期: ZCQ/2015/08/01
 *全局声明: 无
 *特殊说明: 自动初始化全局变量；输出级别值越小级别越高；同时支持网络输出与数据库存储；自动维护持久存储日志生命周期。
 ************************************************************************************************************************************************************************       
 */
extern int JSYA_LES_LogPrintf(const char *pOwnerName,unsigned int Level,const char *pFormat,...);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: JSYA_LES_ConfigCallback
 *功能描述: 设置日志输出回调函数
 *输入描述: 标准输出标记、回调函数、回调函数环境
 *输出描述: 可选输出原回调函数环境
 *返回描述: 原回调函数
 *作者日期: ZCQ/2009/05/24
 *全局声明: sLocalMutex,sIsStdOut,spCallBackFunc,spCallBackContext
 *特殊说明: 默认无回调函数且禁用标准输出
 ************************************************************************************************************************************************************************       
 */
extern PLES_CALLBACK JSYA_LES_ConfigCallback(BOOL IsStdOut,PLES_CALLBACK pCallback,void *pContext,void **ppOldContext);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: JSYA_LES_InitLogPath,JSYA_LES_InitLogPathEx
 *功能描述: 设置设备日志文件存盘路径
 *输入描述: 设备日志文件存盘路径,设备标识FSUID,日志文件使能标记
 *输出描述: 无
 *返回描述: 无
 *作者日期: ZCQ/2016/08/03
 *全局声明: sLocalMutex,sSysLogFilePath,sIsEnableLogFile,sSysFsuId
 *特殊说明: 系统默认路径空
 ************************************************************************************************************************************************************************       
 */
extern void JSYA_LES_InitLogPathEx(const char *pPath,const char *pFsuID,BOOL IsEnableLogFile);
extern void JSYA_LES_InitLogPath(const char *pPath);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: JSYA_LES_SetLogConfig
 *功能描述: 设置日志服务参数
 *输入描述: 日志输出限制级别、日志存储限制级别、日志保存天数
 *输出描述: 无
 *返回描述: 无
 *作者日期: ZCQ/2015/08/01
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern void JSYA_LES_SetLogConfig(unsigned int OutLevelLimit,unsigned int SaveLevelLimit,unsigned int SaveDays);






/*
 ************************************************************************************************************************************************************************     
 *函数名称:
 *功能描述:
 *输入描述:
 *输出描述:
 *返回描述:
 *作者日期:
 *全局声明:
 *特殊说明:
 ************************************************************************************************************************************************************************       
*/





/*
 ************************************************************************************************************************************************************************
 * 全局变量输出声明
 ************************************************************************************************************************************************************************
*/


#ifdef	__cplusplus
#if		__cplusplus
}
#endif
#endif

/******************************************LogEventServer.h 文件结束******************************************************************************************************/
#endif
