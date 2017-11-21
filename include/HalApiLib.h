#ifndef _HAL_API_LIB_H_
#define _HAL_API_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif


#define HAL_API_HARD_TYPE_PM5000TT						0
#define HAL_API_HARD_TYPE_PM5000T2M						1
#define HAL_API_HARD_TYPE_PM5000RRU						2


#define HAL_API_TRUE									1
#define HAL_API_FALSE									0


#define HAL_API_GPIO_INF_MCU_PROGRAMMING				HAL_API_GPIO_SUB_MCU_PROGRAMMING
#define HAL_API_GPIO_INF_MCU_RESET						HAL_API_GPIO_SUB_MCU_RESET
#define HAL_API_GPIO_INF_MCU_WATCH_DOG					HAL_API_GPIO_SUB_MCU_WATCH_DOG

#define HAL_API_GPIO_MAIN_MCU_PROGRAMMING				0
#define HAL_API_GPIO_MAIN_MCU_WATCH_DOG					1
#define HAL_API_GPIO_MAIN_MCU_RESET						2
#define HAL_API_GPIO_SUB_MCU_PROGRAMMING				3
#define HAL_API_GPIO_SUB_MCU_RESET						4
#define HAL_API_GPIO_SUB_MCU_WATCH_DOG					5
#define HAL_API_GPIO_HARDWARE_MODEL_BIT0				6
#define HAL_API_GPIO_HARDWARE_MODEL_BIT1				7
#define HAL_API_GPIO_HARDWARE_MODEL_BIT2				8
#define HAL_API_GPIO_HARDWARE_VER_BIT0					9
#define HAL_API_GPIO_HARDWARE_VER_BIT1					10
#define HAL_API_GPIO_HARDWARE_VER_BIT2					11
#define HAL_API_GPIO_EXT_MCU_PROGRAMMING				12
#define HAL_API_GPIO_EXT_MCU_WATCH_DOG					13
#define HAL_API_GPIO_EXT_MCU_RESET						14
#define HAL_API_GPIO_LIGHT_SYS_BUSY						15
#define HAL_API_GPIO_LIGHT_SYS_UPDATE					16


#define HAL_API_SER_MAIN_MCU							0
#define HAL_API_SER_SUB_MCU								1
#define HAL_API_SER_COM5								2
#define HAL_API_SER_COM6								3
#define HAL_API_SER_COM7								4
#define HAL_API_SER_COM8								5
#define HAL_API_SER_COM9								6
#define HAL_API_SER_COM10								7
#define HAL_API_SER_MODEM								8
#define HAL_API_SER_MODEM_AT_ZJXD_CMCC_4G				9
#define HAL_API_SER_MODEM_MODEM_ZJXD_CMCC_4G			10
#define HAL_API_SER_MODEM_AT_ZJXD_CTCC_3G				11
#define HAL_API_SER_MODEM_MODEM_ZJXD_CTCC_3G			12
#define HAL_API_SER_MODEM_AT_ZJXD_CUCC_3G				13
#define HAL_API_SER_MODEM_MODEM_ZJXD_CUCC_3G			14
#define HAL_API_SER_MODEM_AT_ZJXD_CTCC_CUCC_4G			15
#define HAL_API_SER_MODEM_MODEM_ZJXD_CTCC_CUCC_4G		16
#define HAL_API_SER_MODEM_AT_ZTE_CTCC_4G				17
#define HAL_API_SER_MODEM_MODEM_ZTE_CTCC_4G				18
#define HAL_API_SER_MODEM_AT_ZTE_CMCC_CUCC_4G			19
#define HAL_API_SER_MODEM_MODEM_ZTE_CMCC_CUCC_4G		20
#define HAL_API_SER_MODEM_AT_BX_CMCC_CUCC_4G			21
#define HAL_API_SER_MODEM_MODEM_BX_CMCC_CUCC_4G			22
#define HAL_API_SER_MODEM_AT_BX_ALL_CTCC_4G				23
#define HAL_API_SER_MODEM_MODEM_BX_ALL_CTCC_4G			24
#define HAL_API_SER_MODEM_AT_DT_CMCC_CUCC_4G			25
#define HAL_API_SER_MODEM_MODEM_DT_CMCC_CUCC_4G			26
#define HAL_API_SER_MODEM_AT_DT_ALL_CTCC_4G				27
#define HAL_API_SER_MODEM_MODEM_DT_ALL_CTCC_4G			28
#define HAL_API_SER_MODEM_AT_FH_CMCC_4G					29
#define HAL_API_SER_MODEM_MODEM_FH_CMCC_4G				30
#define HAL_API_SER_MODEM_AT_FH_CUCC_4G					31
#define HAL_API_SER_MODEM_MODEM_FH_CUCC_4G				32
#define HAL_API_SER_MODEM_AT_FH_ALL_CTCC_4G				33
#define HAL_API_SER_MODEM_MODEM_FH_ALL_CTCC_4G			34
#define HAL_API_SER_MODEM_AT_RLP_CMCC_CUCC_4G			35
#define HAL_API_SER_MODEM_MODEM_RLP_CMCC_CUCC_4G		36
#define HAL_API_SER_MODEM_AT_RLP_ALL_CTCC_4G			37
#define HAL_API_SER_MODEM_MODEM_RLP_ALL_CTCC_4G			38
#define HAL_API_SER_MODEM_AT_JSR_ALL_4G					39
#define HAL_API_SER_MODEM_MODEM_JSR_ALL_4G				40
#define HAL_API_SER_MODEM_GPS_FH_CMCC_4G				41
#define HAL_API_SER_MODEM_GPS_FH_CUCC_4G				42
#define HAL_API_SER_MODEM_GPS_FH_ALL_CTCC_4G			43
#define HAL_API_SER_MODEM_AT_DT_ALL_4G					44
#define HAL_API_SER_MODEM_MODEM_DT_ALL_4G				45
#define HAL_API_SER_MODEM_GPS_DT_ALL_4G					46
#define HAL_API_SER_MODEM_AT_FH_ALL_4G					47
#define HAL_API_SER_MODEM_MODEM_FH_ALL_4G				48
#define HAL_API_SER_MODEM_GPS_FH_ALL_4G					49
#define HAL_API_SER_MODEM_AT_DT_CMCC_4G					50
#define HAL_API_SER_MODEM_MODEM_DT_CMCC_4G				51
#define HAL_API_SER_MODEM_AT_ZTE_ALL_4G					52
#define HAL_API_SER_MODEM_MODEM_ZTE_ALL_4G				53
#define HAL_API_SER_MODEM_AT_ZJXD_CUCC_4G				54
#define HAL_API_SER_MODEM_MODEM_ZJXD_CUCC_4G			55
#define HAL_API_SER_MODEM_AT_YAAO_ALL_4G_EC20_R2		56
#define HAL_API_SER_MODEM_MODEM_YAAO_ALL_4G_EC20_R2		57
#define HAL_API_SER_MODEM_GPS_YAAO_ALL_4G_EC20_R2		58
#define HAL_API_SER_MODEM_AT_YAAO_ALL_4G_U9300C			59
#define HAL_API_SER_MODEM_MODEM_YAAO_ALL_4G_U9300C		60


	
#define HAL_API_NET_IF_INVALID							(-1)
#define HAL_API_NET_IF_LAN								0
#define HAL_API_NET_IF_MODEM							1
#define HAL_API_NET_IF_MODEM_ECM_ZJXD_CMCC_4G			2
#define HAL_API_NET_IF_MODEM_ECM_ZTE_CMCC_CUCC_4G		3
#define HAL_API_NET_IF_MODEM_ECM_DT_CMCC_CUCC_4G		4
#define HAL_API_NET_IF_MODEM_ECM_FH_CMCC_4G				5


#define HAL_API_USB_SER_CP2105A							0
#define HAL_API_USB_SER_CP2105B							1
#define HAL_API_USB_SER_CP2105C							2
#define HAL_API_USB_SER_CP2105D							3


#define HAL_API_MODEM_DIALER_STD_MODE_AUTO				0
#define HAL_API_MODEM_DIALER_STD_MODE_2G				1
#define HAL_API_MODEM_DIALER_STD_MODE_3G				2
#define HAL_API_MODEM_DIALER_STD_MODE_4G				3
#define HAL_API_MODEM_DIALER_STD_MODE_2G_3G				4

#define HAL_API_MODEM_NET_TYPE_NONE						0
#define HAL_API_MODEM_NET_TYPE_2G						1
#define HAL_API_MODEM_NET_TYPE_3G						2
#define HAL_API_MODEM_NET_TYPE_4G						3

#define HAL_API_MODEM_OPER_TYPE_NONE					0
#define HAL_API_MODEM_OPER_TYPE_CMCC					1
#define HAL_API_MODEM_OPER_TYPE_CUCC					2
#define HAL_API_MODEM_OPER_TYPE_CTCC					3

#define HAL_API_MODEM_ERROR_OK							0
#define HAL_API_MODEM_ERROR_GEN_ERR						1
#define HAL_API_MODEM_ERROR_SIM_ERR						2
#define HAL_API_MODEM_ERROR_NET_ERR						3
#define HAL_API_MODEM_ERROR_NOT_SUPPORT					4
#define HAL_API_MODEM_ERROR_REBOOT						5
#define HAL_API_MODEM_ERROR_DIALER_ERR					6

#define HAL_API_MODEM_SIGNAL_IS_WEAK(sig)				((sig)==0 || (sig)<(-100))


	
typedef int HAL_API_BOOL;

typedef struct _HAL_API_MODEM_DEV_CONF
{
	unsigned int	SerIndexAT;
	unsigned int	SerIndexModem;
	unsigned int	NetIndex;
	unsigned int	GpsIndex;
	HAL_API_BOOL	NetIsReady;
	HAL_API_BOOL	GpsIsReady;
	char			strSerDevNameAT[128];
	char			strSerDevNameModem[128];
	char			strNetDevName[128];
	char			strGpsDevName[128];
}HAL_API_MODEM_DEV_CONF,*PHAL_API_MODEM_DEV_CONF;

typedef struct _HAL_API_MODEM_DEV_STAT
{
	unsigned int	NetType;
	unsigned int	OperType;
	unsigned int	ErrNo;
	signed int		SignalQuality_dBm;
	char			strIMSI[32];
	char			strIMEI[32];
	char			strManufacturer[32];
	char			strProductModel[32];
}HAL_API_MODEM_DEV_STAT,*PHAL_API_MODEM_DEV_STAT;

typedef struct _HAL_API_MODEM_DEV_DYNAMIC_STAT
{
	unsigned int	NetType;
	unsigned int	OperType;
	signed int		SignalQuality_dBm;
	char			strIMSI[32];
}HAL_API_MODEM_DEV_DYNAMIC_STAT,*PHAL_API_MODEM_DEV_DYNAMIC_STAT;




/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_GpioCtrlFunc
 *功能描述: 执行具体GPIO预定功能
 *输入描述: GPIO编号、功能执行标记
 *输出描述: 无
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/07/30
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GpioCtrlFunc(unsigned int GpioNo,HAL_API_BOOL IsExecFunc);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_GpioGetFunc
 *功能描述: 获取具体GPIO功能状态
 *输入描述: GPIO编号
 *输出描述: GPIO功能状态
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/07/30
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GpioGetFunc(unsigned int GpioNo,HAL_API_BOOL *pIsExecFunc);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_GetSerDevName
 *功能描述: 获取串口设备系统名称
 *输入描述: 串口设备ID、设备名缓冲区、设备名缓冲区大小
 *输出描述: 设备名称及其实际长度
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/07/30
 *全局声明: 无
 *特殊说明: 串口设备名为全路径名称
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GetSerDevName(unsigned int SerID,char *pDevNameBuf,int *pLen);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_GetNetDevName
 *功能描述: 获取网络接口设备系统名称
 *输入描述: 网络接口设备ID、设备名缓冲区、设备名缓冲区大小
 *输出描述: 设备名称及其实际长度
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/07/30
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GetNetDevName(unsigned int NetID,char *pDevNameBuf,int *pLen);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_GetSysHardType
 *功能描述: 获取系统硬件产品型号
 *输入描述: 无
 *输出描述: 无
 *返回描述: 系统硬件产品型号编码
 *作者日期: ZCQ/2016/09/20
 *全局声明: 无
 *特殊说明: 默认返回0/PM5000TT
 ************************************************************************************************************************************************************************       
*/
extern unsigned int HalApi_GetSysHardType(void);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_GetSysHardVer
 *功能描述: 获取系统硬件产品版本
 *输入描述: 无
 *输出描述: 无
 *返回描述: 系统硬件产品版本编码
 *作者日期: ZCQ/2016/09/20
 *全局声明: 无
 *特殊说明: 默认返回1
 ************************************************************************************************************************************************************************       
*/
extern unsigned int HalApi_GetSysHardVer(void);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_ModemSerDevIsReady
 *功能描述: 测试无线模块是否连接就绪
 *输入描述: 无
 *输出描述: 无
 *返回描述: 就绪(HAL_API_TRUE)/未连接(HAL_API_FALSE)
 *作者日期: ZCQ/2015/09/16
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemSerDevIsReady(void);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_ModemNetDevIsReady
 *功能描述: 测试无线模块网络接口是否连接就绪
 *输入描述: 无
 *输出描述: 无
 *返回描述: 就绪(HAL_API_TRUE)/未连接(HAL_API_FALSE)
 *作者日期: ZCQ/2015/09/16
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemNetDevIsReady(void);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_GetModemConfig
 *功能描述: 获取系统无线模块连接配置信息
 *输入描述: 无线模块连接配置信息缓冲区
 *输出描述: 无线模块连接配置信息
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/09/16
 *全局声明: 无
 *特殊说明: 串口设备名为全路径名称
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GetModemConfig(PHAL_API_MODEM_DEV_CONF pConf);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_Init
 *功能描述: 模块全局初始化
 *输入描述: 硬件类型、日志接口回调函数
 *输出描述: 无
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/07/30
 *全局声明: 无
 *特殊说明: 日志接口回调函数置NULL则忽略日志输出
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_Init(unsigned int HardType,int (*pLog)(const char *pOwnerName,unsigned int Level,const char *pFormat,...));

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_UnInit
 *功能描述: 模块全局反初始化
 *输入描述: 无
 *输出描述: 无
 *返回描述: 无
 *作者日期: ZCQ/2015/07/30
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern void HalApi_UnInit(void);








/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_ModemCmdProcAT
 *功能描述: 无线模块AT命令单步过程
 *输入描述: 无线模块AT命令端口设备文件句柄、命令、需要的响应、命令响应超时、可选的需要的响应行输出缓冲区及其大小
 *输出描述: 可选输出需要的响应行及其长度
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/11/10
 *全局声明: 无
 *特殊说明: 无线模块AT命令端口设备文件句柄以标准规范模式打开串口(即行输入模式);strWantedResponse=NULL表示忽略响应;strWantedResponse=""表示捕获首个有效响应行.
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemCmdProcAT(int DevFd,const char *strCmd,const char *strWantedResponse,unsigned int TimeOutMS,char *pOutLine,unsigned int *pOutLineSize);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_ModemCmdProcATEx
 *功能描述: 无线模块AT命令单步过程扩展
 *输入描述: 无线模块AT命令端口设备名、命令、需要的响应、命令响应超时、可选的需要的响应行输出缓冲区及其大小
 *输出描述: 可选输出需要的响应行及其长度
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/11/10
 *全局声明: 无
 *特殊说明: 无线模块AT命令端口设备名必须是全路径名;strWantedResponse=NULL表示忽略响应;strWantedResponse=""表示捕获首个有效响应行.
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemCmdProcATEx(const char *DevNameAT,const char *strCmd,const char *strWantedResponse,unsigned int TimeOutMS,char *pOutLine,unsigned int *pOutLineSize);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_ModemInit
 *功能描述: 无线模块初始化
 *输入描述: 无线模块配置、超时时间、首选拨号制式、可选输入访问点
 *输出描述: 无线模块状态、实际拨号制式
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2016/10/17
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemInit(const HAL_API_MODEM_DEV_CONF *pConf,unsigned int TimeOutS,int DialerStdMode,char *pApn,PHAL_API_MODEM_DEV_STAT pStat,int *pRealDialerStdMode);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_ModemGetStat
 *功能描述: 获取无线模块状态
 *输入描述: 无线模块配置
 *输出描述: 无线模块状态
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/11/10
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemGetStat(const HAL_API_MODEM_DEV_CONF *pConf,PHAL_API_MODEM_DEV_DYNAMIC_STAT pStat);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_ModemReboot
 *功能描述: 无线模块软重启
 *输入描述: 无线模块配置
 *输出描述: 无
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2015/11/16
 *全局声明: 无
 *特殊说明: 重启成功自动内部延迟适当时间以备无线模块启动就绪
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemReboot(const HAL_API_MODEM_DEV_CONF *pConf);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_ModemDisconnect
 *功能描述: 无线模块断开连接
 *输入描述: 无线模块配置
 *输出描述: 无
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2016/07/06
 *全局声明: 无
 *特殊说明: 断开连接成功自动内部延迟适当时间以备无线模块准备重新连接
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemDisconnect(const HAL_API_MODEM_DEV_CONF *pConf);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: HalApi_SetNetDevPrivateVlanTag
 *功能描述: 设置指定网络设备私有定制VLAN标记
 *输入描述: 网络设备名、VLAN标记
 *输出描述: 无
 *返回描述: 成功(HAL_API_TRUE)/失败(HAL_API_FALSE)
 *作者日期: ZCQ/2017/01/09
 *全局声明: 无
 *特殊说明: 不依赖库初始化.
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_SetNetDevPrivateVlanTag(const char *pDevName,unsigned int VlanTag);







#ifdef __cplusplus
}
#endif

#endif

