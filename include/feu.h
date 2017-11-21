/*
 文件名：feu.h
 功能：	 铁塔feu单元SDK库的接口文件
 日期：  2016-10-31
*/

#ifndef __FEU_SDK__
#define __FEU_SDK__

//标准数据类型定义
typedef char			CHAR;			//标准CHAR
typedef int			INT;			//标准INT



#if defined(WIN32) || defined(WINNT)
typedef signed __int64      INT64,  *PINT64;
#else
typedef long long           __int64;
typedef long long           INT64,  *PINT64;

#endif


#ifdef	__cplusplus
extern "C" {
#endif

	//远程控制超时时间(豪秒)
#define RC_TIMEOUT  20000

	/***********************************************************************/
	//                                                                      //
	//                        定义回调的函数指针                             //
	//                                                                     //
	/***********************************************************************/

	//1远程控制回调函数指针定义（包含遥控，遥调，联动）
	//功能说明：向FSU下发远程控制的命令。
	//          
	//参数说明：1、iDeviceId 设备号，
	//          2、iCellId   采集点
	//	        3、szCmd ，  命令字
	//          4、iActiveNo 命令编码，用于识别返回执行结果   
	//              
	//返回值说明：0 接收成功。
	typedef int(*RCFunc)(__int64 iDeviceId, int iCellId, char *szCmd, int iActiveNo);



	//2喂狗回调函数指针定义
	//功能说明：FEU向FSU喂狗，防止FEU出现跑非的情况。
	//          
	//参数说明：1、iHandle 线程ID，
	//          2、iTimeOut为超时值，毫秒为单位，功能复用，
	//              当iTimeOut > 0,若该线程未被管理则代表注册，若已经管理，代表喂狗，
	//              当iTimeOut =0 代表注销。
	//	         3、pV1，pV1扩展使用，厂家自己定义
	//返回值说明：0 成功。
	typedef int(*WDFunc)(int iHandle, int iTimeOut, void *pV1, void *pV2);



	/*
	//3网络配置回调函数指针定义
	//功能说明：从平台修改VPN网络信息。
	//参数说明：pXmlParam 为XML格式的字符串，使用GBK编码，格式如下：
	<VpnSet">
	<VpnServer>
	<IPSecIP>101.227.248.109</IPSecIP>
	<IPSECUSER>ttcw2015</IPSECUSER>
	<IPSECPWD>ttcw@2015</IPSECPWD>
	</VpnServer>
	<VpnServer>
	<IPSecIP>101.227.248.113</IPSecIP>
	<IPSECUSER>ttcw2015</IPSECUSER>
	<IPSECPWD>ttcw@2015</IPSECPWD>
	</VpnServer>
	<VpnServer>
	<IPSecIP>101.227.248.240</IPSecIP>
	<IPSECUSER>ttcw2015</IPSECUSER>
	<IPSECPWD>ttcw@2015</IPSECPWD>
	</VpnServer>
	</VpnSet>
	*/
	typedef int(*NTFunc)(char * pXmlParam);



	//4升级通知回调函数指针定义
	//功能说明：FEU需要升级时，从平台下发升级命令，FEU通知FSU，FSU停止FEU的运行后，
	//         通过FTP下载服务器指定的FEU库文件，完成后再启动FEU。
	//参数说明：1、pFileName 文件名称，
	//	       2、szVersion 版本号
	typedef int(*SUPFunc)(char * pFileName, char *szVersion);


	//5FTP服务启动回调函数指针定义
	//功能说明：启动FTP服务器使用。
	//          
	//参数说明：无
	typedef int(*FtpStartFunc)();



	//6FTP服务停止回调函数指针定义
	//功能说明：停止FTP服务器使用。
	//          
	//参数说明：无
	typedef int(*FtpStopFunc)();



	//7FTP服务参数修改回调函数指针定义
	//功能说明：修改FTP服务用户权限参数时使用。
	//          
	//参数说明：1、szuser 用户名
	//         2、szPwd 密码
	//	       3、szPath 路径（FSU为用户分配的路径，应当针对特定的功能，暂时定义）
	//         4、iMode 权限(按Linux定义权限执行)
	typedef int(*FtpMFunc)(char *szuser, char *szPwd, char *szPath, int  iMode);



	//8心跳超时回调函数指针定义
	//功能说明：当FEU识别到心跳超时时，通知FSU。
	//          
	//参数说明：无
	typedef int(*CSFunc)();



	//9获取FSU版本号回调函数指针定义
	//功能说明：FEU在注册时需要获取FSU的版本时使用。
	//         FSU通过填写版本串缓冲区参数返回。
	//参数说明：1、szVer 版本串缓冲区, 
	//	       2、iSize 版本串缓冲区的大小
	//              
	typedef int(*GVERFunc)(char *szVer, int iSize);



	//10 FSU时钟同步回调函数注册
	//功能说明：当FEU收到时钟同步报文时调用。
	//          
	//参数说明：cur_time ：整数的时间，从1970-1-1 0:0:0 到现在得秒数
	//                 
	typedef int(*SCLKFunc)(int cur_time);


    
    //11获得cpu、mem函数
    //功能说明：获得cpu、mem使用率函数
    //参数说明：1、cpu cpu使用率, 
    //	       2、mem 内存使用率
    //              
    typedef int(*GCMFunc)(float *fCpu, float *fMem);



	//12获取VPN状态回调函数指针定义
	//功能说明：FEU获取FSU当前VPN状态，使用XML格式返回。
	//          
	//参数说明：1、szVpnStat xml文本返回缓冲区, 
	//				XML格式的字符串，使用GBK编码，格式如下：
	//				<VpnStat><Stat>1</Stat><IPAddr></IPAddr><MacId></MacId><ImsiId></ImsiId><NetworkType></NetworkType>
	//				<Carrier></Carrier><NMVendor></NMVendor><NMType></NMType></VpnStat>
	//	       2、iLen 缓冲区长度
	// 
	typedef int(*GVpnFunc)(char *szVpnStat, int iLen);

	/***********************************************************************/
	//                                                                      //
	//                         FEU参数设置                                  //
	//                                                                     //
	/***********************************************************************/

	//1运行参数设置 
	//功能说明：当FSU启动FEU，传递参数文件给FEU，FEU通过参数文件的
	//	       标识更改自己的运行参数，或运行过程中，参数发生变化
	//	       调用，通知FEU
	//参数说明：pFileName文件名指针，XML格式 ，参照ConfigSet.xml。。
	//返回值说明：0 成功。
	int  FEU_SetRunConfig(char* pFileName);

    /*
	//2日志输出控制
	//功能说明：控制日志输出，通过加载ConfigSet.xml文件指定的控制文件来实现。
	//参数说明：无
	//返回值说明：0 成功
	ConfigSet.xml文件包含
	<LogSet title="日志配置">
	<Path title="路径" />
	<Size title="空间大小" />
	<LogCtrlFile title="日志开关控制文件 调用FEU_CtrlLogOut()函数时加载">LogCtrl.xml</LogCtrlFile>
	</LogSet>
	为控制日志输出配置
	*/
	int FEU_CtrlLogOut();




	//3告警过滤参数设置 
	//功能说明：当FSU启动FEU，传递参数文件给FEU，FEU通过参数文件的
	//	    标识更改自己的运行参数，或运行过程中，参数发生变化
	//	    调用，通知FEU
	//参数说明：pFileName文件名指针，XML格式， 参照AlarmFilt.xml。
	//返回值说明：0 成功。
	int  FEU_SetAlarmFiltCfg(char* pFileName);

	//4告警联动参数设置 
	//功能说明：当FSU启动FEU，传递参数文件给FEU，FEU通过参数文件的
	//	    标识更改自己的运行参数，或运行过程中，参数发生变化
	//	    调用，通知FEU
	//参数说明：pFileName文件名指针，XML格式,参照AlarmActLink.xml。
	//返回值说明：0 成功。
	int  FEU_SetAlarmActiveLink(char* pFileName);




	/***********************************************************************/
	//                                                                     //
	//                         FEU功能函数注册                             //
	//                                                                     //
	/***********************************************************************/

    //1FTP服务参数修改回调函数设置 
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc 回调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_FTPModifyParam(FtpMFunc pCallProc);

	//2远程控制回调函数设置
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc 回调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_RC(RCFunc pCallProc);

	//3喂狗回调函数设置
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc 回调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_WatchDog(WDFunc pCallProc);

	//4心跳超时回调函数设置
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc 回调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_ComStat(CSFunc pCallProc);

	//5获取FSU版本信息回调函数设置
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc 回调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_GetFsuVersion(GVERFunc pCallProc);

	//6 获取FSU的VPN状态的回调函数设置
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc 回调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_GetVpnStat(GVpnFunc pCallProc);

	//7 FSU时钟同步的回调函数设置
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc 回调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_SetFsuTime(SCLKFunc pCallProc);

    //8获取资源利用率
	//功能说明：获取FSU的CPU，内存利用率的回调函数注册。
	//参数说明：pCallProc 回调函数的指针。	
	//返回值说明：0 ：注册成功 -1：函数句柄为空
	int  FEU_SetCallProc_GetFSUResource (GCMFunc  pCallProc);




	//9FTP服务启动回调函数设置 
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_FTPStart(FtpStartFunc pCallProc);

	//10FTP服务停止回调函数设置  
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_FTPStop(FtpStopFunc pCallProc);

	//11网络参数修改回调函数设置
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_NetParamModify(NTFunc pCallProc);

	//12FEU升级通知回调函数设置
	//功能说明：FSU向FEU传递回调函数指针
	//参数说明：pCallProc调函数的指针。
	//返回值说明：0 成功。
	int  FEU_SetCallProc_SdkUpdate(SUPFunc pCallProc);

	
	/***********************************************************************/
	//                                                                      //
	//                         SDK运行操作                                  //
	//                                                                     //
	/***********************************************************************/

	//1FEU启动运行函数
	//功能说明：启动FEU运行。
	//参数说明：无。
	//返回值说明：0 成功。
	int  FEU_RunStart();



	//2FEU停止运行函数
	//功能说明：停止FEU运行。
	//参数说明：无。
	//返回值说明：0 成功。
	int  FEU_RunStop();

	/***********************************************************************/
	//                                                                      //
	//                            FEU交互                                   //
	//                                                                     //
	/***********************************************************************/

	//1实时遥测数据提交函数
	//功能说明：FSU提交实时采集到的数据(性能上报使用)
	//参数说明： 1、iDeviceId 设备号，
	//          2、iCellId   采集点
	//  	    3、szVal ，  字符串的值  
	//返回值说明：0 成功。
	INT  FEU_AiData(INT64 iDeviceId, INT iCellId, CHAR* szVal);



	//2遥信关联遥测的实时数据提交函数
	//功能说明：FSU提交由遥测数据触发的遥信数据，用于判断告警使用
	//参数说明：1、iDeviceId 设备号，
	//         2、iCellId   采集点
	//	       3、szVal ，  字符串的值（遥测值）  
	//返回值说明：0 成功。
	//例如：温度超高告警（采集点编码：0418005001），需要把当前的温度值通过szVal传递。
	INT  FEU_AiDrvAlarm(INT64 iDeviceId, INT iCellId, CHAR* szVal);



	//3遥信的实时数据提交函数
	//功能说明：FSU提交由遥测数据触发的遥信数据，用于判断告警使用
	//参数说明：1、iDeviceId 设备号，
	//         2、iCellId   采集点
	//	       3、iStat ，  遥信值（定义：0 为正常，1非正常态，FEU可作为告警处理）  
	//返回值说明：0 成功。
	int  FEU_DiData(INT64 iDeviceId, INT iCellId, INT iStat);



	//4遥控的实时数据提交函数
	//功能说明：FSU提交由遥测数据触发的遥信数据，用于判断告警使用
	//参数说明：1、iDeviceId 设备号，
	//         2、iCellId   采集点
	//	       3、iStat ，  遥信值（定义：0 为正常，1非正常态）  
	//返回值说明：0 成功。
	int  FEU_DoData(INT64 iDeviceId, INT iCellId, INT iStat);



	//5遥调的实时数据提交函数
	//功能说明：FSU提交实时采集到的数据(性能上报使用)
	//参数说明：1、iDeviceId 设备号，
	//         2、iCellId   采集点
	//	       3、szVal ，  字符串的值  
	//返回值说明：0 成功。
	INT  FEU_AoData(INT64 iDeviceId, INT iCellId, CHAR* szVal);



	//6远程控制结果返回函数
	//功能说明：FSU向FEU提交远程控制的返回结果
	//参数说明：1、iDeviceId 设备号，
	//         2、iCellId   采集点
	//	       3、iActiveNo 远程控制编码（按FEU提交的返回）
	//	       4、iResult	0失败 1成功
	//返回值说明：0 成功。
	int  FEU_RCActionRet(__int64 iDeviceId, int iCellId, int iActiveNo, int iResult);



	/*
	//7VPN状态通知
	//功能说明：当FSU发现VPN状态发生时，调用本函数通知FEU（上线调一次，离线调一次）。
	//参数说明：pXmlInfo 为XML格式的字符串，使用GKB编码，格式如下：
	<VpnStat><Stat>1</Stat><IPAddr></IPAddr><MacId></MacId><ImsiId></ImsiId><NetworkType></NetworkType>
	<Carrier></Carrier><NMVendor></NMVendor><NMType></NMType></VpnStat>
	//返回值说明：0 成功
	*/
	int	 FEU_ReceiveVpnInfo(char *pXmlInfo);



	//8字典表查询函数
	//功能说明：查询采集点所在字典表的信息
	//参数说明：1、iDeviceId 设备号，等于0时，返回所以字典表的信息，
	//            仅包含中间类型为0时（00000040600000），返回字典表对应采集点的字典配置信息。
	//	          当是具体的设备编码时，返回具体设备的信元配置信息。
	//         2、iCellId   采集点
	//	       3、pXmOutPacket 返回字典表信息缓冲区（XML格式）
	//         4、iSize 返回字典表缓冲区的大小
	//返回值说明：0成功
	/*
	pXmOutPacket 格式：
	<DictInfoS>
	<DictInfo>
	<CellType>0</CellType>
	<CellID>0419003001</CellID>
	<CellName">非智能设备采集器通信状态</CellName>
	<CellUnit></CellUnit>
	<CellAlmName>告警</CellAlmName>
	<CellResName>正常</CellResName>
	<CellAlmLevel>三级告警</CellAlmLevel>
	<CellSetupVal></CellSetupVal>
	<CellLimit>1</CellLimit>
	<RestoreDiff></RestoreDiff>
	<CellDelay>180</CellDelay>
	<CellResDelay >20</CellResDelay>
	<CellCyc></CellCyc>
	<CellAbsVal></CellAbsVal>
	<CellPerVal></CellPerVal>
	<MaxVal>1</MaxVal>
	<MinVal>0</MinVal>
	<IsNotUse>0</IsNotUse>
	<SendMode></SendMode>
	</DictInfo>
	<DictInfo></DictInfo>
	</DictInfoS>
	*/
	int  FEU_GetDictCfg(__int64 iDeviceId, int iCellId, char *pXmlOutBuf, int iSize);



	//9获取FEU版本信息
	//功能说明：FSU向FEU获取版本信息
	//参数说明：1、szBuf 返回的缓存区
	//		   2、iMaxLen 能返回的最大长度（保证20字节）
	//返回值说明：0 成功。
	int  FEU_Get_FEU_Version(char *szBuf, int iMaxLen);



    //10获取注册状态
	//功能说明：FSU向FEU获取注册状态
	//参数说明：无。
	//返回值说明：0 未注册 1 注册成功 -1 注册失败 -2 SC为空。
	int  FEU_GetRegistStat();



#ifdef	__cplusplus
}
#endif


#endif
