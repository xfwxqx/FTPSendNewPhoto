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
 *��������: HalApi_GpioCtrlFunc
 *��������: ִ�о���GPIOԤ������
 *��������: GPIO��š�����ִ�б��
 *�������: ��
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/07/30
 *ȫ������: ��
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GpioCtrlFunc(unsigned int GpioNo,HAL_API_BOOL IsExecFunc);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_GpioGetFunc
 *��������: ��ȡ����GPIO����״̬
 *��������: GPIO���
 *�������: GPIO����״̬
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/07/30
 *ȫ������: ��
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GpioGetFunc(unsigned int GpioNo,HAL_API_BOOL *pIsExecFunc);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_GetSerDevName
 *��������: ��ȡ�����豸ϵͳ����
 *��������: �����豸ID���豸�����������豸����������С
 *�������: �豸���Ƽ���ʵ�ʳ���
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/07/30
 *ȫ������: ��
 *����˵��: �����豸��Ϊȫ·������
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GetSerDevName(unsigned int SerID,char *pDevNameBuf,int *pLen);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_GetNetDevName
 *��������: ��ȡ����ӿ��豸ϵͳ����
 *��������: ����ӿ��豸ID���豸�����������豸����������С
 *�������: �豸���Ƽ���ʵ�ʳ���
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/07/30
 *ȫ������: ��
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GetNetDevName(unsigned int NetID,char *pDevNameBuf,int *pLen);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_GetSysHardType
 *��������: ��ȡϵͳӲ����Ʒ�ͺ�
 *��������: ��
 *�������: ��
 *��������: ϵͳӲ����Ʒ�ͺű���
 *��������: ZCQ/2016/09/20
 *ȫ������: ��
 *����˵��: Ĭ�Ϸ���0/PM5000TT
 ************************************************************************************************************************************************************************       
*/
extern unsigned int HalApi_GetSysHardType(void);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_GetSysHardVer
 *��������: ��ȡϵͳӲ����Ʒ�汾
 *��������: ��
 *�������: ��
 *��������: ϵͳӲ����Ʒ�汾����
 *��������: ZCQ/2016/09/20
 *ȫ������: ��
 *����˵��: Ĭ�Ϸ���1
 ************************************************************************************************************************************************************************       
*/
extern unsigned int HalApi_GetSysHardVer(void);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_ModemSerDevIsReady
 *��������: ��������ģ���Ƿ����Ӿ���
 *��������: ��
 *�������: ��
 *��������: ����(HAL_API_TRUE)/δ����(HAL_API_FALSE)
 *��������: ZCQ/2015/09/16
 *ȫ������: ��
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemSerDevIsReady(void);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_ModemNetDevIsReady
 *��������: ��������ģ������ӿ��Ƿ����Ӿ���
 *��������: ��
 *�������: ��
 *��������: ����(HAL_API_TRUE)/δ����(HAL_API_FALSE)
 *��������: ZCQ/2015/09/16
 *ȫ������: ��
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemNetDevIsReady(void);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_GetModemConfig
 *��������: ��ȡϵͳ����ģ������������Ϣ
 *��������: ����ģ������������Ϣ������
 *�������: ����ģ������������Ϣ
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/09/16
 *ȫ������: ��
 *����˵��: �����豸��Ϊȫ·������
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_GetModemConfig(PHAL_API_MODEM_DEV_CONF pConf);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_Init
 *��������: ģ��ȫ�ֳ�ʼ��
 *��������: Ӳ�����͡���־�ӿڻص�����
 *�������: ��
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/07/30
 *ȫ������: ��
 *����˵��: ��־�ӿڻص�������NULL�������־���
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_Init(unsigned int HardType,int (*pLog)(const char *pOwnerName,unsigned int Level,const char *pFormat,...));

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_UnInit
 *��������: ģ��ȫ�ַ���ʼ��
 *��������: ��
 *�������: ��
 *��������: ��
 *��������: ZCQ/2015/07/30
 *ȫ������: ��
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern void HalApi_UnInit(void);








/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_ModemCmdProcAT
 *��������: ����ģ��AT���������
 *��������: ����ģ��AT����˿��豸�ļ�����������Ҫ����Ӧ��������Ӧ��ʱ����ѡ����Ҫ����Ӧ����������������С
 *�������: ��ѡ�����Ҫ����Ӧ�м��䳤��
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/11/10
 *ȫ������: ��
 *����˵��: ����ģ��AT����˿��豸�ļ�����Ա�׼�淶ģʽ�򿪴���(��������ģʽ);strWantedResponse=NULL��ʾ������Ӧ;strWantedResponse=""��ʾ�����׸���Ч��Ӧ��.
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemCmdProcAT(int DevFd,const char *strCmd,const char *strWantedResponse,unsigned int TimeOutMS,char *pOutLine,unsigned int *pOutLineSize);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_ModemCmdProcATEx
 *��������: ����ģ��AT�����������չ
 *��������: ����ģ��AT����˿��豸���������Ҫ����Ӧ��������Ӧ��ʱ����ѡ����Ҫ����Ӧ����������������С
 *�������: ��ѡ�����Ҫ����Ӧ�м��䳤��
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/11/10
 *ȫ������: ��
 *����˵��: ����ģ��AT����˿��豸��������ȫ·����;strWantedResponse=NULL��ʾ������Ӧ;strWantedResponse=""��ʾ�����׸���Ч��Ӧ��.
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemCmdProcATEx(const char *DevNameAT,const char *strCmd,const char *strWantedResponse,unsigned int TimeOutMS,char *pOutLine,unsigned int *pOutLineSize);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_ModemInit
 *��������: ����ģ���ʼ��
 *��������: ����ģ�����á���ʱʱ�䡢��ѡ������ʽ����ѡ������ʵ�
 *�������: ����ģ��״̬��ʵ�ʲ�����ʽ
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2016/10/17
 *ȫ������: ��
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemInit(const HAL_API_MODEM_DEV_CONF *pConf,unsigned int TimeOutS,int DialerStdMode,char *pApn,PHAL_API_MODEM_DEV_STAT pStat,int *pRealDialerStdMode);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_ModemGetStat
 *��������: ��ȡ����ģ��״̬
 *��������: ����ģ������
 *�������: ����ģ��״̬
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/11/10
 *ȫ������: ��
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemGetStat(const HAL_API_MODEM_DEV_CONF *pConf,PHAL_API_MODEM_DEV_DYNAMIC_STAT pStat);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_ModemReboot
 *��������: ����ģ��������
 *��������: ����ģ������
 *�������: ��
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2015/11/16
 *ȫ������: ��
 *����˵��: �����ɹ��Զ��ڲ��ӳ��ʵ�ʱ���Ա�����ģ����������
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemReboot(const HAL_API_MODEM_DEV_CONF *pConf);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_ModemDisconnect
 *��������: ����ģ��Ͽ�����
 *��������: ����ģ������
 *�������: ��
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2016/07/06
 *ȫ������: ��
 *����˵��: �Ͽ����ӳɹ��Զ��ڲ��ӳ��ʵ�ʱ���Ա�����ģ��׼����������
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_ModemDisconnect(const HAL_API_MODEM_DEV_CONF *pConf);

/*
 ************************************************************************************************************************************************************************     
 *��������: HalApi_SetNetDevPrivateVlanTag
 *��������: ����ָ�������豸˽�ж���VLAN���
 *��������: �����豸����VLAN���
 *�������: ��
 *��������: �ɹ�(HAL_API_TRUE)/ʧ��(HAL_API_FALSE)
 *��������: ZCQ/2017/01/09
 *ȫ������: ��
 *����˵��: ���������ʼ��.
 ************************************************************************************************************************************************************************       
*/
extern HAL_API_BOOL HalApi_SetNetDevPrivateVlanTag(const char *pDevName,unsigned int VlanTag);







#ifdef __cplusplus
}
#endif

#endif

