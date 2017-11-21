#ifndef _PM5KTTBI_API_H_
#define _PM5KTTBI_API_H_

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef TTFSUBI_ARRAY_SIZE
#define	TTFSUBI_ARRAY_SIZE(a)						(sizeof(a)/sizeof((a)[0]))
#endif
#ifndef TTFSUBI_FREE
#define TTFSUBI_FREE(p)								do{if(p){free(p);(p)=NULL;}}while(0)
#endif
#ifndef TTFSUBI_MALLOC
#define TTFSUBI_MALLOC		malloc
#endif
#ifdef WIN32
#include "stdsoap2.h"
#else
#include "Common.h"
#endif
#include "Commdata.h"

#define TTFSUBI_FSU_DEV_NUM_MAX			64
#define TTFSUBI_FSU_DEV_NODE_NUM_MAX	512


#define	TTFSUBI_MSG_TYPE_LOGIN				101
#define	TTFSUBI_MSG_TYPE_LOGIN_ACK			102
#define	TTFSUBI_MSG_TYPE_LOGOUT				103
#define	TTFSUBI_MSG_TYPE_LOGOUT_ACK			104
#define	TTFSUBI_MSG_TYPE_GET_DATA			401
#define	TTFSUBI_MSG_TYPE_GET_DATA_ACK		402
#define	TTFSUBI_MSG_TYPE_GET_HISDATA		403
#define	TTFSUBI_MSG_TYPE_GET_HISDATA_ACK	404
#define	TTFSUBI_MSG_TYPE_SEND_ALARM			501
#define	TTFSUBI_MSG_TYPE_SEND_ALARM_ACK		502
#define	TTFSUBI_MSG_TYPE_SET_POINT			1001
#define	TTFSUBI_MSG_TYPE_SET_POINT_ACK		1002
#define	TTFSUBI_MSG_TYPE_TIME_CHECK			1301
#define	TTFSUBI_MSG_TYPE_TIME_CHECK_ACK		1302
#define	TTFSUBI_MSG_TYPE_GET_LOGININFO		1501
#define	TTFSUBI_MSG_TYPE_GET_LOGININFO_ACK	1502
#define	TTFSUBI_MSG_TYPE_SET_LOGININFO		1503
#define	TTFSUBI_MSG_TYPE_SET_LOGININFO_ACK	1504
#define	TTFSUBI_MSG_TYPE_GET_FTP			1601
#define	TTFSUBI_MSG_TYPE_GET_FTP_ACK		1602
#define	TTFSUBI_MSG_TYPE_SET_FTP			1603
#define	TTFSUBI_MSG_TYPE_SET_FTP_ACK		1604
#define	TTFSUBI_MSG_TYPE_GET_FSUINFO		1701
#define	TTFSUBI_MSG_TYPE_GET_FSUINFO_ACK	1702
#define	TTFSUBI_MSG_TYPE_SET_FSUREBOOT		1801
#define	TTFSUBI_MSG_TYPE_SET_FSUREBOOT_ACK	1802
#define	TTFSUBI_MSG_TYPE_GET_THRESHOLD		1901
#define	TTFSUBI_MSG_TYPE_GET_THRESHOLD_ACK	1902
#define	TTFSUBI_MSG_TYPE_SET_THRESHOLD		2001
#define	TTFSUBI_MSG_TYPE_SET_THRESHOLD_ACK	2002


#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_FSU				3001
#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_FSU_ACK			3002
#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_SO				3003
#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_SO_ACK			3004
#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_SENSOR			3005
#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_SENSOR_ACK		3006
#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_ACTIVE_ALARM		3007
#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_ACTIVE_ALARM_ACK	3008
#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_HISALARM			3009
#define	TTFSUBI_MSG_TYPE_EX_GET_CONFIG_HISALARM_ACK		3010

#define	TTFSUBI_MSG_TYPE_EX_ADD_CONFIG_FSU				3101
#define	TTFSUBI_MSG_TYPE_EX_ADD_CONFIG_FSU_ACK			3102
#define	TTFSUBI_MSG_TYPE_EX_ADD_CONFIG_SO				3103
#define	TTFSUBI_MSG_TYPE_EX_ADD_CONFIG_SO_ACK			3104
#define	TTFSUBI_MSG_TYPE_EX_ADD_CONFIG_SENSOR			3105
#define	TTFSUBI_MSG_TYPE_EX_ADD_CONFIG_SENSOR_ACK		3106

#define	TTFSUBI_MSG_TYPE_EX_DELETE_CONFIG_FSU			3201
#define	TTFSUBI_MSG_TYPE_EX_DELETE_CONFIG_FSU_ACK		3202
#define	TTFSUBI_MSG_TYPE_EX_DELETE_CONFIG_SO			3203
#define	TTFSUBI_MSG_TYPE_EX_DELETE_CONFIG_SO_ACK		3204
#define	TTFSUBI_MSG_TYPE_EX_DELETE_CONFIG_SENSOR		3205
#define	TTFSUBI_MSG_TYPE_EX_DELETE_CONFIG_SENSOR_ACK	3206

#define	TTFSUBI_MSG_TYPE_EX_PUT_CONFIG_FSU				3301
#define	TTFSUBI_MSG_TYPE_EX_PUT_CONFIG_FSU_ACK			3302
#define	TTFSUBI_MSG_TYPE_EX_PUT_CONFIG_SO				3303
#define	TTFSUBI_MSG_TYPE_EX_PUT_CONFIG_SO_ACK			3304
#define	TTFSUBI_MSG_TYPE_EX_PUT_CONFIG_SENSOR			3305
#define	TTFSUBI_MSG_TYPE_EX_PUT_CONFIG_SENSOR_ACK		3306
#define	TTFSUBI_MSG_TYPE_EX_PUT_CONFIG_ALARM_PARAM		3307
#define	TTFSUBI_MSG_TYPE_EX_PUT_CONFIG_ALARM_PARAM_ACK	3308

#define	TTFSUBI_MSG_TYPE_EX_CONFIG_ADD_DEV				9901
#define	TTFSUBI_MSG_TYPE_EX_CONFIG_ADD_DEV_ACK			9902
#define	TTFSUBI_MSG_TYPE_EX_CONFIG_MODIFY_DEV			9903
#define	TTFSUBI_MSG_TYPE_EX_CONFIG_MODIFY_DEV_ACK		9904
#define	TTFSUBI_MSG_TYPE_EX_CONFIG_DEL_DEV				9905
#define	TTFSUBI_MSG_TYPE_EX_CONFIG_DEL_DEV_ACK			9906
#define	TTFSUBI_MSG_TYPE_EX_CONFIG_QUERY_DEV			9907
#define	TTFSUBI_MSG_TYPE_EX_CONFIG_QUERY_DEV_ACK		9908
#define	TTFSUBI_MSG_TYPE_EX_CONFIG_QUERY_FSU			9909
#define	TTFSUBI_MSG_TYPE_EX_CONFIG_QUERY_FSU_ACK		9910
#define	TTFSUBI_MSG_TYPE_EX_AUTO_SCAN_DEV				9911
#define	TTFSUBI_MSG_TYPE_EX_AUTO_SCAN_DEV_ACK			9912
#define	TTFSUBI_MSG_TYPE_EX_GET_PIC_FILE_LIST			9913
#define	TTFSUBI_MSG_TYPE_EX_GET_PIC_FILE_LIST_ACK		9914
#define	TTFSUBI_MSG_TYPE_EX_GET_PIC_FILE_DATA			9915
#define	TTFSUBI_MSG_TYPE_EX_GET_PIC_FILE_DATA_ACK		9916
#define	TTFSUBI_MSG_TYPE_EX_GET_EVENT_LOG				9917
#define	TTFSUBI_MSG_TYPE_EX_GET_EVENT_LOG_ACK			9918
#define	TTFSUBI_MSG_TYPE_EX_GET_AUTO_DEV_LIST			9919
#define	TTFSUBI_MSG_TYPE_EX_GET_AUTO_DEV_LIST_ACK		9920




#define	TTFSUBI_MSG_TYPE_LOCAL_GET_FSUIP				0x8000FFF0
#define	TTFSUBI_MSG_TYPE_LOCAL_GET_FSUIP_ACK			0x8000FFF1
#define	TTFSUBI_MSG_TYPE_LOCAL_CLIENT_KEEP_ALIVE		0x8000FFF2
#define	TTFSUBI_MSG_TYPE_LOCAL_SERVER_KEEP_ALIVE		0x8000FFF3
#define	TTFSUBI_MSG_TYPE_LOCAL_LOGIN_CALL_FAIL			0x8000FFF4
#define	TTFSUBI_MSG_TYPE_LOCAL_GET_NET_FLOW				0x8000FFF5



#define	TTFSUBI_NAME_LENGTH			40		//名字命名长度	40字节
#define	TTFSUBI_USER_LENGTH			20		//用户名长度	20字节
#define	TTFSUBI_PASSWORD_LEN		20		//口令长度	20字节
#define	TTFSUBI_EVENT_LENGTH		160		//事件信息长度	160字节
#define	TTFSUBI_ALARM_LENGTH		165		//告警事件信息长度	165字节
#define	TTFSUBI_LOGIN_LENGTH		100		//登录事件信息长度	100字节
#define	TTFSUBI_DES_LENGTH			80		//描述信息长度	40字节
#define	TTFSUBI_UNIT_LENGTH			8		//数据单位的长度	8字节
#define	TTFSUBI_STATE_LENGTH		160		//态值描述长度	160字节
#define	TTFSUBI_VER_LENGTH			20		//版本描述的长度	20字节
#define	TTFSUBI_AREACODE_LENGTH		7		//区域编码长度	7字节
#define	TTFSUBI_STATIONCODE_LENGTH	12		//机房编码长度	12字节
#define	TTFSUBI_NODECODE_LENGTH		11		//监控信号编码	11字节
#define	TTFSUBI_EVENT_LENGTH		160		//事件信息长度	160字节
#define	TTFSUBI_FSUID_LEN			14		//FSU ID字符串长度	14字节
#define	TTFSUBI_FSUCODE_LEN			14		//FSU编码字符串长度	14字节
#define	TTFSUBI_IP_LENGTH			15		//IP串长度	15字节
#define	TTFSUBI_DEVICEID_LEN		14		//设备ID长度	14字节
#define	TTFSUBI_DEVICECODE_LEN		14		//设备编码	14字节
#define	TTFSUBI_ID_LENGTH			10		//监控点ID长度	10字节
#define	TTFSUBI_SERIALNO_LEN		10		//告警序号长度	10字节
#define	TTFSUBI_TIME_LEN			19		//时间串长度	19字节
#define TTFSUBI_MAC_LENGTH			12
#define TTFSUBI_IMSI_LENGTH			15
#define TTFSUBI_VERSION_LENGTH		20
#define TTFSUBI_FSUVENDOR_LENGTH	20
#define TTFSUBI_NETWORK_TYPE_LENGTH	20
#define TTFSUBI_FSUTYPE_LENGTH		20
#define TTFSUBI_FSUCLASS_LENGTH		20
#define TTFSUBI_WARN_PACK_NUM_MAX	10

#define TTFSUBI_CARRIER_LENGTH				2
#define TTFSUBI_NMVENDOR_LENGTH				20
#define TTFSUBI_NMTYPE_LENGTH				20
#define TTFSUBI_LOGIN_REG_MODE_OLD			1
#define TTFSUBI_LOGIN_REG_MODE_NEW			2
#define TTFSUBI_DICT_VERSION_STD			1
#define TTFSUBI_DICT_VERSION_SIMPLIFY		2

typedef enum _ttfsubi_EnumRightMode
{
	TTFSUBI_INVALID=0,
	TTFSUBI_READONLY=1,
	TTFSUBI_READ_WRITE=2
}ttfsubi_EnumRightMode;
typedef enum _ttfsubi_EnumResult
{
	TTFSUBI_FAILURE=0,
	TTFSUBI_SUCCESS=1
}ttfsubi_EnumResult;
typedef enum _ttfsubi_EnumType
{
	TTFSUBI_STATION=0,
	TTFSUBI_DEVICE=1,
	TTFSUBI_DI=2,
	TTFSUBI_AI=3,
	TTFSUBI_DO=4,
	TTFSUBI_AO=5,
	TTFSUBI_AREA=9
}ttfsubi_EnumType;
typedef enum _ttfsubi_EnumAlarmLevel
{
	TTFSUBI_NOALARM=0,
	TTFSUBI_CRITICAL=1,
	TTFSUBI_MAJOR=2,
	TTFSUBI_MINOR=3,
	TTFSUBI_HINT=4
}ttfsubi_EnumAlarmLevel;
typedef enum _ttfsubi_EnumEnable
{
	TTFSUBI_DISABLE=0,
	TTFSUBI_ENABLE=1
}ttfsubi_EnumEnable;
typedef enum _ttfsubi_EnumAcceSCMode
{
	TTFSUBI_ASK_ANSWER=0,
	TTFSUBI_CHANGE_TRIGGER=1,
	TTFSUBI_TIME_TRIGGER=2,
	TTFSUBI_STOP=3
}ttfsubi_EnumAcceSCMode;
typedef enum _ttfsubi_EnumState
{
	TTFSUBI_STATE_NOALARM=0,
	TTFSUBI_STATE_CRITICAL=1,
	TTFSUBI_STATE_MAJOR=2,
	TTFSUBI_STATE_MINOR=3,
	TTFSUBI_STATE_HINT=4,
	TTFSUBI_STATE_OPEVENT=5,
	TTFSUBI_STATE_INVALID=6,
}ttfsubi_EnumState;
typedef enum _ttfsubi_EnumFlag
{
	TTFSUBI_WARN_BEGIN=0,
	TTFSUBI_WARN_END=1
}ttfsubi_EnumFlag;
typedef enum _ttfsubi_EnumAlarmMode
{
	TTFSUBI_ALARM_MODE_NOALARM=0,
	TTFSUBI_ALARM_MODE_CRITICAL=1,
	TTFSUBI_ALARM_MODE_MAJOR=2,
	TTFSUBI_ALARM_MODE_MINOR=3,
	TTFSUBI_ALARM_MODE_HINT=4
}ttfsubi_EnumAlarmMode;
typedef int ttfsubi_EnumStationType;	//局站类型0~9
typedef enum _ttfsubi_EnumModifyType
{
	TTFSUBI_MODIFY_ADDNONODES=0,
	TTFSUBI_MODIFY_ADDINNODES=1,
	TTFSUBI_MODIFY_DELETE=2,
	TTFSUBI_MODIFY_MODIFYNONODES=3,
	TTFSUBI_MODIFY_MODIFYINNODES=4
}ttfsubi_EnumModifyType;
typedef int ttfsubi_EnumDeviceType;		//设备类型,标准化类型
typedef int ttfsubi_EnumDeviceCode;		//设备编码
#define TTFSUBI_MAKE_DEVICE_CODE(StationType,DeviceType)	((StationType)*100+(DeviceType))


#define TTFSUBI_FSU_CLASS_INTSTAN			0
#define TTFSUBI_FSU_CLASS_DISSTAN			1
#define TTFSUBI_FSU_CLASS_IHIEXTER			2
#define TTFSUBI_FSU_CLASS_IIHIEXTER			3
#define TTFSUBI_FSU_CLASS_ILOEXTER			4
#define TTFSUBI_FSU_CLASS_IILOEXTER			5

#define TTFSUBI_FSU_CLASS_INTSTAN_NAME		"INTSTAN"
#define TTFSUBI_FSU_CLASS_DISSTAN_NAME		"DISSTAN"
#define TTFSUBI_FSU_CLASS_IHIEXTER_NAME		"IHIEXTER"
#define TTFSUBI_FSU_CLASS_IIHIEXTER_NAME	"IIHIEXTER"
#define TTFSUBI_FSU_CLASS_ILOEXTER_NAME		"ILOEXTER"
#define TTFSUBI_FSU_CLASS_IILOEXTER_NAME	"IILOEXTER"

#define TTFSUBI_LOCKED_NETWORK_TYPE_AUTO			"AUTO"
#define TTFSUBI_LOCKED_NETWORK_TYPE_GSM				"GSM"
#define TTFSUBI_LOCKED_NETWORK_TYPE_CDMA			"CDMA"
#define TTFSUBI_LOCKED_NETWORK_TYPE_WCDMA			"WCDMA"
#define TTFSUBI_LOCKED_NETWORK_TYPE_TDSCDMA			"TDSCDMA"
#define TTFSUBI_LOCKED_NETWORK_TYPE_EVDO			"EVDO"
#define TTFSUBI_LOCKED_NETWORK_TYPE_LTE				"LTE"
#define TTFSUBI_LOCKED_NETWORK_TYPE_GSM_TDSCDMA		"GSM_TDSCDMA"
#define TTFSUBI_LOCKED_NETWORK_TYPE_GSM_WCDMA		"GSM_WCDMA"
#define TTFSUBI_LOCKED_NETWORK_TYPE_CDMA_EVDO		"CDMA_EVDO"








typedef struct _TTFSUBI_TTIME
{
	short	Years;
	char	Month;
	char	Day;
	char	Hour;
	char	Minute;
	char	Second;
}TTFSUBI_TTIME;
typedef struct _TTFSUBI_TSEMAPHORE
{
	ttfsubi_EnumType	Type;
	float				MeasuredVal;
	float				SetupVal;
	ttfsubi_EnumState	Status;
	char				ID[TTFSUBI_ID_LENGTH+4];
	char				RecordTime[TTFSUBI_TIME_LEN+4];				//YYYY-MM-DD<SPACE键>hh:mm:ss(采用24小时的时间制式)
}TTFSUBI_TSEMAPHORE;
typedef struct _TTFSUBI_TTHRESHOLD
{
	ttfsubi_EnumType	Type;
	char				ID[TTFSUBI_ID_LENGTH+4];
	float				Threshold;
	float				AbsoluteVal;
	float				RelativeVal;
	ttfsubi_EnumState	Status;
}TTFSUBI_TTHRESHOLD;
typedef struct _TTFSUBI_TALARM
{
	char				SerialNo[TTFSUBI_SERIALNO_LEN+4];
	char				ID[TTFSUBI_ID_LENGTH+4];
	char				FSUID[TTFSUBI_FSUID_LEN+4];					//资源系统的ID
	char				FsuCode[TTFSUBI_FSUCODE_LEN+4];				//FSU 编码
	char				DeviceID[TTFSUBI_DEVICEID_LEN+4];			//设备ID
	char				DeviceCode[TTFSUBI_DEVICECODE_LEN+4];		//设备编码
	char				AlarmTime[TTFSUBI_TIME_LEN+4];				//告警时间，YYYY-MM-DD<SPACE键>hh:mm:ss（采用24小时的时间制式）
	ttfsubi_EnumState	AlarmLevel;
	ttfsubi_EnumFlag	AlarmFlag;
	char				AlarmDesc[TTFSUBI_DES_LENGTH+4];
}TTFSUBI_TALARM;
typedef struct _TTFSUBI_TGPS
{
	char				FSUID[TTFSUBI_FSUID_LEN+4];				//资源系统的ID
	float				Lag;									//经度
	float				Lat;									//纬度
}TTFSUBI_TGPS;
typedef struct _TTFSUBI_TFSUSTATUS
{
	float		CPUUsage;
	float		MEMUsage;
}TTFSUBI_TFSUSTATUS;

typedef struct _TTFSUBI_LOGIN
{
	char	UserName[TTFSUBI_USER_LENGTH+4];
	char	PaSCword[TTFSUBI_PASSWORD_LEN+4];
	char	FsuId[TTFSUBI_FSUID_LEN+4];
	char	FsuCode[TTFSUBI_FSUCODE_LEN+4];
	char	FsuIP[TTFSUBI_IP_LENGTH+4];
	char	MacId[TTFSUBI_MAC_LENGTH+20];
	char	ImsiId[TTFSUBI_IMSI_LENGTH+17];
	char	NetworkType[TTFSUBI_NETWORK_TYPE_LENGTH+4];			/*2G、3G、4G*/
	char	LockedNetworkType[TTFSUBI_NETWORK_TYPE_LENGTH+4];
	char	Carrier[TTFSUBI_CARRIER_LENGTH+4];					/*CT CM CU*/
	char	NMVendor[TTFSUBI_NMVENDOR_LENGTH+12];
	char	NMType[TTFSUBI_NMTYPE_LENGTH+12];
	char	FSUVendor[TTFSUBI_FSUVENDOR_LENGTH+12];
	char	FSUType[TTFSUBI_FSUTYPE_LENGTH+12];
	char	FSUClass[TTFSUBI_FSUCLASS_LENGTH+12];
	char	Version[TTFSUBI_VERSION_LENGTH+12];
	int		Reg_Mode;
	int		DictVersion;
	int		DevNum;
	char	DeviceIdList[TTFSUBI_FSU_DEV_NUM_MAX][TTFSUBI_DEVICEID_LEN+4];
	char	DeviceCodeList[TTFSUBI_FSU_DEV_NUM_MAX][TTFSUBI_DEVICEID_LEN+4];
}TTFSUBI_LOGIN;
typedef struct _TTFSUBI_LOGIN_ACK
{
	ttfsubi_EnumRightMode	RightLevel;
	char					DataServerIP[32];
}TTFSUBI_LOGIN_ACK;

typedef struct _TTFSUBI_LOGOUT
{
	char	FsuId[TTFSUBI_FSUID_LEN+4];
}TTFSUBI_LOGOUT;
typedef struct _TTFSUBI_LOGOUT_ACK
{
	ttfsubi_EnumResult	Result;
}TTFSUBI_LOGOUT_ACK;

typedef struct _TTFSUBI_SEND_ALARM
{
	TTFSUBI_TALARM	Values[TTFSUBI_WARN_PACK_NUM_MAX];
}TTFSUBI_SEND_ALARM;
typedef struct _TTFSUBI_SEND_ALARM_ACK
{
	ttfsubi_EnumResult	Result;
}TTFSUBI_SEND_ALARM_ACK;


typedef struct _TTFSUBI_GET_DATA_DEV
{
	char	DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char	DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int		NodeNum;
	char	NodeList[TTFSUBI_FSU_DEV_NODE_NUM_MAX][TTFSUBI_ID_LENGTH+4];
}TTFSUBI_GET_DATA_DEV;
typedef struct _TTFSUBI_GET_DATA
{
	char					FsuId[TTFSUBI_FSUID_LEN+4];
	char					FsuCode[TTFSUBI_FSUCODE_LEN+4];
	int						DevNum;
	TTFSUBI_GET_DATA_DEV	DevList[TTFSUBI_FSU_DEV_NUM_MAX];
}TTFSUBI_GET_DATA;
typedef struct _TTFSUBI_GET_DATA_ACK_DEV
{
	char				DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char				DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int					NodeNum;
	TTFSUBI_TSEMAPHORE	*pNodeList;
}TTFSUBI_GET_DATA_ACK_DEV;
typedef struct _TTFSUBI_GET_DATA_ACK
{
	char						FsuId[TTFSUBI_FSUID_LEN+4];
	char						FsuCode[TTFSUBI_FSUCODE_LEN+4];
	ttfsubi_EnumResult			Result;
	int							DevNum;
	TTFSUBI_GET_DATA_ACK_DEV	*pDevList;
}TTFSUBI_GET_DATA_ACK;


typedef struct _TTFSUBI_GET_HISDATA_DEV
{
	char	DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char	DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int		NodeNum;
	char	NodeList[TTFSUBI_FSU_DEV_NODE_NUM_MAX][TTFSUBI_ID_LENGTH+4];
}TTFSUBI_GET_HISDATA_DEV;
typedef struct _TTFSUBI_GET_HISDATA
{
	char					FsuId[TTFSUBI_FSUID_LEN+4];
	char					FsuCode[TTFSUBI_FSUCODE_LEN+4];
	char					StartTime[TTFSUBI_TIME_LEN+4];
	char					EndTime[TTFSUBI_TIME_LEN+4];
	int						DevNum;
	TTFSUBI_GET_HISDATA_DEV	DevList[TTFSUBI_FSU_DEV_NUM_MAX];
}TTFSUBI_GET_HISDATA;
typedef struct _TTFSUBI_GET_HISDATA_ACK_DEV
{
	char				DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char				DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int					NodeNum;
	TTFSUBI_TSEMAPHORE	*pNodeList;
}TTFSUBI_GET_HISDATA_ACK_DEV;
typedef struct _TTFSUBI_GET_HISDATA_ACK
{
	char						FsuId[TTFSUBI_FSUID_LEN+4];
	char						FsuCode[TTFSUBI_FSUCODE_LEN+4];
	ttfsubi_EnumResult			Result;
	int							DevNum;
	TTFSUBI_GET_HISDATA_ACK_DEV	*pDevList;
}TTFSUBI_GET_HISDATA_ACK;


typedef struct _TTFSUBI_SET_POINT_DEV
{
	char				DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char				DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int					NodeNum;
	TTFSUBI_TSEMAPHORE	*pNodeList;
}TTFSUBI_SET_POINT_DEV;
typedef struct _TTFSUBI_SET_POINT
{
	char						FsuId[TTFSUBI_FSUID_LEN+4];
	char						FsuCode[TTFSUBI_FSUCODE_LEN+4];
	int							DevNum;
	TTFSUBI_SET_POINT_DEV		*pDevList;
}TTFSUBI_SET_POINT;
typedef struct _TTFSUBI_SET_POINT_ACK_DEV
{
	char				DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char				DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int					SuccessNodeNum;
	char				SuccessNodeList[TTFSUBI_FSU_DEV_NODE_NUM_MAX][TTFSUBI_ID_LENGTH+4];
	int					FailNodeNum;
	char				FailNodeList[TTFSUBI_FSU_DEV_NODE_NUM_MAX][TTFSUBI_ID_LENGTH+4];
}TTFSUBI_SET_POINT_ACK_DEV;
typedef struct _TTFSUBI_SET_POINT_ACK
{
	char						FsuId[TTFSUBI_FSUID_LEN+4];
	char						FsuCode[TTFSUBI_FSUCODE_LEN+4];
	ttfsubi_EnumResult			Result;
	int							DevNum;
	TTFSUBI_SET_POINT_ACK_DEV	*pDevList;
}TTFSUBI_SET_POINT_ACK;


typedef struct _TTFSUBI_GET_THRESHOLD_DEV
{
	char	DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char	DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int		NodeNum;
	char	NodeList[TTFSUBI_FSU_DEV_NODE_NUM_MAX][TTFSUBI_ID_LENGTH+4];
}TTFSUBI_GET_THRESHOLD_DEV;
typedef struct _TTFSUBI_GET_THRESHOLD
{
	char						FsuId[TTFSUBI_FSUID_LEN+4];
	char						FsuCode[TTFSUBI_FSUCODE_LEN+4];
	int							DevNum;
	TTFSUBI_GET_THRESHOLD_DEV	DevList[TTFSUBI_FSU_DEV_NUM_MAX];
}TTFSUBI_GET_THRESHOLD;
typedef struct _TTFSUBI_GET_THRESHOLD_ACK_DEV
{
	char				DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char				DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int					NodeNum;
	TTFSUBI_TTHRESHOLD	*pNodeList;
}TTFSUBI_GET_THRESHOLD_ACK_DEV;
typedef struct _TTFSUBI_GET_THRESHOLD_ACK
{
	char							FsuId[TTFSUBI_FSUID_LEN+4];
	char							FsuCode[TTFSUBI_FSUCODE_LEN+4];
	ttfsubi_EnumResult				Result;
	int								DevNum;
	TTFSUBI_GET_THRESHOLD_ACK_DEV	*pDevList;
}TTFSUBI_GET_THRESHOLD_ACK;


typedef struct _TTFSUBI_SET_THRESHOLD_DEV
{
	char				DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char				DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int					NodeNum;
	TTFSUBI_TTHRESHOLD	*pNodeList;
}TTFSUBI_SET_THRESHOLD_DEV;
typedef struct _TTFSUBI_SET_THRESHOLD
{
	char						FsuId[TTFSUBI_FSUID_LEN+4];
	char						FsuCode[TTFSUBI_FSUCODE_LEN+4];
	int							DevNum;
	TTFSUBI_SET_THRESHOLD_DEV	*pDevList;
}TTFSUBI_SET_THRESHOLD;
typedef struct _TTFSUBI_SET_THRESHOLD_ACK_DEV
{
	char				DeviceID[TTFSUBI_DEVICEID_LEN+4];
	char				DeviceCode[TTFSUBI_DEVICECODE_LEN+4];
	int					SuccessNodeNum;
	char				SuccessNodeList[TTFSUBI_FSU_DEV_NODE_NUM_MAX][TTFSUBI_ID_LENGTH+4];
	int					FailNodeNum;
	char				FailNodeList[TTFSUBI_FSU_DEV_NODE_NUM_MAX][TTFSUBI_ID_LENGTH+4];
}TTFSUBI_SET_THRESHOLD_ACK_DEV;
typedef struct _TTFSUBI_SET_THRESHOLD_ACK
{
	char							FsuId[TTFSUBI_FSUID_LEN+4];
	char							FsuCode[TTFSUBI_FSUCODE_LEN+4];
	ttfsubi_EnumResult				Result;
	int								DevNum;
	TTFSUBI_SET_THRESHOLD_ACK_DEV	*pDevList;
}TTFSUBI_SET_THRESHOLD_ACK;


typedef struct _TTFSUBI_GET_LOGININFO
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
	char				FsuCode[TTFSUBI_FSUCODE_LEN+4];
}TTFSUBI_GET_LOGININFO;
typedef struct _TTFSUBI_GET_LOGININFO_ACK
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
	char				FsuCode[TTFSUBI_FSUCODE_LEN+4];
	char				IPSecUser[TTFSUBI_USER_LENGTH+4];
	char				IPSecPWD[TTFSUBI_PASSWORD_LEN+4];
	char				IPSecIP[TTFSUBI_IP_LENGTH+4];
	char				SCIP[TTFSUBI_IP_LENGTH+4];

						/*以下12组信息本地使用，本命令B接口不使用*/
	char				MacId[TTFSUBI_MAC_LENGTH+20];
	char				ImsiId[TTFSUBI_IMSI_LENGTH+17];
	char				NetworkType[TTFSUBI_NETWORK_TYPE_LENGTH+4];		/*2G、3G、4G*/
	char				LockedNetworkType[TTFSUBI_NETWORK_TYPE_LENGTH+4];
	char				Carrier[TTFSUBI_CARRIER_LENGTH+4];				/*CT CM CU*/
	char				NMVendor[TTFSUBI_NMVENDOR_LENGTH+12];
	char				NMType[TTFSUBI_NMTYPE_LENGTH+12];
	char				FSUVendor[TTFSUBI_FSUVENDOR_LENGTH+12];
	char				FSUType[TTFSUBI_FSUTYPE_LENGTH+12];
	char				FSUClass[TTFSUBI_FSUCLASS_LENGTH+12];
	char				Version[TTFSUBI_VERSION_LENGTH+12];
	int					DictVersion;

	int					DevNum;
	char				DeviceIdList[TTFSUBI_FSU_DEV_NUM_MAX][TTFSUBI_DEVICEID_LEN+4];
	char				DeviceCodeList[TTFSUBI_FSU_DEV_NUM_MAX][TTFSUBI_DEVICEID_LEN+4];
	ttfsubi_EnumResult	Result;
}TTFSUBI_GET_LOGININFO_ACK;

typedef struct _TTFSUBI_SET_LOGININFO
{
	char	FsuId[TTFSUBI_FSUID_LEN+4];
	char	FsuCode[TTFSUBI_FSUCODE_LEN+4];
	char	IPSecUser[TTFSUBI_USER_LENGTH+4];
	char	IPSecPWD[TTFSUBI_PASSWORD_LEN+4];
	char	IPSecIP[TTFSUBI_IP_LENGTH+4];
	char	SCIP[TTFSUBI_IP_LENGTH+4];
	int		DevNum;
	char	DeviceIdList[TTFSUBI_FSU_DEV_NUM_MAX][TTFSUBI_DEVICEID_LEN+4];
	char	DeviceCodeList[TTFSUBI_FSU_DEV_NUM_MAX][TTFSUBI_DEVICEID_LEN+4];
}TTFSUBI_SET_LOGININFO;
typedef struct _TTFSUBI_SET_LOGININFO_ACK
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
	char				FsuCode[TTFSUBI_FSUCODE_LEN+4];
	ttfsubi_EnumResult	Result;
}TTFSUBI_SET_LOGININFO_ACK;

typedef struct _TTFSUBI_GET_FTP
{
	char	FsuId[TTFSUBI_FSUID_LEN+4];
	char	FsuCode[TTFSUBI_FSUCODE_LEN+4];
}TTFSUBI_GET_FTP;
typedef struct _TTFSUBI_GET_FTP_ACK
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
	char				FsuCode[TTFSUBI_FSUCODE_LEN+4];
	char				UserName[TTFSUBI_USER_LENGTH+4];
	char				Password[TTFSUBI_PASSWORD_LEN+4];
	ttfsubi_EnumResult	Result;
}TTFSUBI_GET_FTP_ACK;

typedef struct _TTFSUBI_SET_FTP
{
	char	FsuId[TTFSUBI_FSUID_LEN+4];
	char	FsuCode[TTFSUBI_FSUCODE_LEN+4];
	char	UserName[TTFSUBI_USER_LENGTH+4];
	char	Password[TTFSUBI_PASSWORD_LEN+4];
	char	UserPath[128];
	int		UserAccessMode;
}TTFSUBI_SET_FTP;
typedef struct _TTFSUBI_SET_FTP_ACK
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
	char				FsuCode[TTFSUBI_FSUCODE_LEN+4];
	ttfsubi_EnumResult	Result;
}TTFSUBI_SET_FTP_ACK;

typedef struct _TTFSUBI_TIME_CHECK
{
	TTFSUBI_TTIME		Time;
}TTFSUBI_TIME_CHECK;
typedef struct _TTFSUBI_TIME_CHECK_ACK
{
	ttfsubi_EnumResult	Result;
}TTFSUBI_TIME_CHECK_ACK;

typedef struct _TTFSUBI_GET_FSUINFO
{
	char	FsuId[TTFSUBI_FSUID_LEN+4];
	char	FsuCode[TTFSUBI_FSUCODE_LEN+4];
	char	strUserIP[32];
}TTFSUBI_GET_FSUINFO;
typedef struct _TTFSUBI_GET_FSUINFO_ACK
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
	char				FsuCode[TTFSUBI_FSUCODE_LEN+4];
	TTFSUBI_TFSUSTATUS	FsuStatus;
	ttfsubi_EnumResult	Result;
}TTFSUBI_GET_FSUINFO_ACK;

typedef struct _TTFSUBI_SET_FSUREBOOT
{
	char	FsuId[TTFSUBI_FSUID_LEN+4];
	char	FsuCode[TTFSUBI_FSUCODE_LEN+4];
}TTFSUBI_SET_FSUREBOOT;
typedef struct _TTFSUBI_SET_FSUREBOOT_ACK
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
	char				FsuCode[TTFSUBI_FSUCODE_LEN+4];
	ttfsubi_EnumResult	Result;
}TTFSUBI_SET_FSUREBOOT_ACK;



typedef struct _TTFSUBI_GET_CONFIG_FSU
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
}TTFSUBI_GET_CONFIG_FSU;
typedef struct _TTFSUBI_GET_CONFIG_FSU_ACK
{
	ttfsubi_EnumResult	Result;
	char				strLongitude[32];
	char				strLatitude[32];
	FSUTABLE			Fsu;
}TTFSUBI_GET_CONFIG_FSU_ACK;
typedef struct _TTFSUBI_GET_CONFIG_SO
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
	WORD				SoCode;
}TTFSUBI_GET_CONFIG_SO;
typedef struct _TTFSUBI_GET_CONFIG_SO_ACK
{
	ttfsubi_EnumResult	Result;
	int					SoNum;
	SOCONFIGTABLE		SoConf[TTFSUBI_FSU_DEV_NUM_MAX];
}TTFSUBI_GET_CONFIG_SO_ACK;
typedef struct _TTFSUBI_GET_CONFIG_SENSOR
{
	char				FsuId[TTFSUBI_FSUID_LEN+4];
	WORD				SoCode;
	WORD				SensorCode;
}TTFSUBI_GET_CONFIG_SENSOR;
typedef struct _TTFSUBI_GET_CONFIG_SENSOR_ACK
{
	ttfsubi_EnumResult	Result;
	int					SensorNum;
	SENSORTABLE			SensorList[TTFSUBI_FSU_DEV_NODE_NUM_MAX];
}TTFSUBI_GET_CONFIG_SENSOR_ACK;
typedef struct _TTFSUBI_GET_CONFIG_ACTIVE_ALARM_ACK
{
	ttfsubi_EnumResult	Result;
	int					AlarmNum;
	ALARMTABLE			*pAlarmList;
}TTFSUBI_GET_CONFIG_ACTIVE_ALARM_ACK;
typedef struct _TTFSUBI_GET_CONFIG_HISALARM
{
	char				StartTime[TTFSUBI_TIME_LEN+4];
	char				EndTime[TTFSUBI_TIME_LEN+4];
}TTFSUBI_GET_CONFIG_HISALARM;
typedef struct _TTFSUBI_GET_CONFIG_HISALARM_ACK
{
	ttfsubi_EnumResult	Result;
	int					AlarmNum;
	ALARMTABLE			*pAlarmList;
}TTFSUBI_GET_CONFIG_HISALARM_ACK;


typedef struct _TTFSUBI_ADD_CONFIG_FSU
{
	FSUTABLE			Fsu;
}TTFSUBI_ADD_CONFIG_FSU;
typedef struct _TTFSUBI_ADD_CONFIG_FSU_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				FsuCode;
}TTFSUBI_ADD_CONFIG_FSU_ACK;
typedef struct _TTFSUBI_ADD_CONFIG_SO
{
	DWORD				FsuCode;
	SOCONFIGTABLE		So;
}TTFSUBI_ADD_CONFIG_SO;
typedef struct _TTFSUBI_ADD_CONFIG_SO_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				FsuCode;
	WORD				SoCode;
}TTFSUBI_ADD_CONFIG_SO_ACK;
typedef struct _TTFSUBI_ADD_CONFIG_SENSOR
{
	DWORD				FsuCode;
	WORD				SoCode;
	SENSORTABLE			Sensor;
}TTFSUBI_ADD_CONFIG_SENSOR;
typedef struct _TTFSUBI_ADD_CONFIG_SENSOR_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				FsuCode;
	WORD				SoCode;
	WORD				SensorCode;
}TTFSUBI_ADD_CONFIG_SENSOR_ACK;

typedef struct _TTFSUBI_DELETE_CONFIG_FSU
{
	DWORD				FsuCode;
}TTFSUBI_DELETE_CONFIG_FSU;
typedef struct _TTFSUBI_DELETE_CONFIG_FSU_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				FsuCode;
}TTFSUBI_DELETE_CONFIG_FSU_ACK;
typedef struct _TTFSUBI_DELETE_CONFIG_SO
{
	DWORD				FsuCode;
	WORD				SoCode;
}TTFSUBI_DELETE_CONFIG_SO;
typedef struct _TTFSUBI_DELETE_CONFIG_SO_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				FsuCode;
	WORD				SoCode;
}TTFSUBI_DELETE_CONFIG_SO_ACK;
typedef struct _TTFSUBI_DELETE_CONFIG_SENSOR
{
	DWORD				FsuCode;
	WORD				SoCode;
	WORD				SensorCode;
}TTFSUBI_DELETE_CONFIG_SENSOR;
typedef struct _TTFSUBI_DELETE_CONFIG_SENSOR_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				FsuCode;
	WORD				SoCode;
	WORD				SensorCode;
}TTFSUBI_DELETE_CONFIG_SENSOR_ACK;

typedef struct _TTFSUBI_PUT_CONFIG_FSU
{
	DWORD				AccessMode;
	char				strLongitude[32];
	char				strLatitude[32];
	FSUTABLE			Fsu;
}TTFSUBI_PUT_CONFIG_FSU;
typedef struct _TTFSUBI_PUT_CONFIG_FSU_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				FsuCode;
}TTFSUBI_PUT_CONFIG_FSU_ACK;
typedef struct _TTFSUBI_PUT_CONFIG_SO
{
	DWORD				FsuCode;
	DWORD				AccessMode;
	SOCONFIGTABLE		So;
}TTFSUBI_PUT_CONFIG_SO;
typedef struct _TTFSUBI_PUT_CONFIG_SO_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				FsuCode;
	WORD				SoCode;
}TTFSUBI_PUT_CONFIG_SO_ACK;
typedef struct _TTFSUBI_PUT_CONFIG_SENSOR
{
	DWORD				FsuCode;
	WORD				SoCode;
	SENSORTABLE			Sensor;
}TTFSUBI_PUT_CONFIG_SENSOR;
typedef struct _TTFSUBI_PUT_CONFIG_SENSOR_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				FsuCode;
	WORD				SoCode;
	WORD				SensorCode;
}TTFSUBI_PUT_CONFIG_SENSOR_ACK;
typedef struct _TTFSUBI_PUT_CONFIG_ALARM_PARAM
{
	WORD				AlarmVarID;
	WORD				AlarmVarVal;
	char				NodeID[TTFSUBI_ID_LENGTH+4];
	char				DeviceID[TTFSUBI_DEVICEID_LEN+4];
}TTFSUBI_PUT_CONFIG_ALARM_PARAM;
typedef struct _TTFSUBI_PUT_CONFIG_ALARM_PARAM_ACK
{
	ttfsubi_EnumResult	Result;
}TTFSUBI_PUT_CONFIG_ALARM_PARAM_ACK;







#define TTFSUBI_PCM_PORT_ID_BASE		1
typedef struct _TTFSUBI_GET_FSU_RUN_STATUS_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				DevFirmwareVer;
	DWORD				DevPcmVer;
	DWORD				DevRunTime;
	time_t				DevRealTime;
	BOOL				DevWanIsReady;
	BOOL				DevVpnIsReady;
	BOOL				DevLoginScIsReady;
	BOOL				SubCpu1IsOffLine;
	BOOL				SubCpu2IsOffLine;
	BOOL				IpcIsOnLine;
	DWORD				WirelessSignalQuality;
	DWORD				SysComNum;
	BOOL				ComPcmDevIsOnLine[32];
	float				CPUUsage;
	float				MEMUsage;
	BYTE				DevLanMac[6];
	char				strDevLanIP[32];
	char				strDevLanSubNet[32];
	char				strDevWanIP[32];
	char				strVpnServerIP[32];
	char				strVpnLocalIP[32];
	char				strScLoginServerIP[32];
	char				strScDataServerIP[32];
	char				strLastConfigInitLog[256];
	char				strFsuName[128];
	char				strLongitude[32];
	char				strLatitude[32];
	char				strWirelessNetType[32];
	char				strSysSoftwareVer[32];
	char				strFsuId[32];
	char				strFsuHardMode[32];
}TTFSUBI_GET_FSU_RUN_STATUS_ACK,*PTTFSUBI_GET_FSU_RUN_STATUS_ACK;

typedef struct _TTFSUBI_LOCAL_GET_NET_FLOW_ACK
{
	U64		RxBytes;
	U64		TxBytes;
}TTFSUBI_LOCAL_GET_NET_FLOW_ACK,*PTTFSUBI_LOCAL_GET_NET_FLOW_ACK;




typedef struct _TTFSUBI_PORT_PCM_DEV_CONF
{
	BOOL				IsNoAutoScan;
	WORD				PcmDevType;
	WORD				IpcNetPort;
	DWORD				DevSoCode;
	char				strPcmDevAddr[32];
	char				strPortBaudrate[32];
	char				strSoName[128];
	char				strIpcIP[32];
	char				strIpcUserName[32];
	char				strIpcPassword[32];
}TTFSUBI_PORT_PCM_DEV_CONF,*PTTFSUBI_PORT_PCM_DEV_CONF;

typedef struct _TTFSUBI_PORT_PCM_DEV_ADD
{
	DWORD						PortID;
	TTFSUBI_PORT_PCM_DEV_CONF	PortConf;
}TTFSUBI_PORT_PCM_DEV_ADD,*PTTFSUBI_PORT_PCM_DEV_ADD;
typedef struct _TTFSUBI_PORT_PCM_DEV_ADD_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				PortID;
}TTFSUBI_PORT_PCM_DEV_ADD_ACK,*PTTFSUBI_PORT_PCM_DEV_ADD_ACK;

typedef struct _TTFSUBI_PORT_PCM_DEV_DEL
{
	DWORD				PortID;
}TTFSUBI_PORT_PCM_DEV_DEL,*PTTFSUBI_PORT_PCM_DEV_DEL;
typedef struct _TTFSUBI_PORT_PCM_DEV_DEL_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				PortID;
}TTFSUBI_PORT_PCM_DEV_DEL_ACK,*PTTFSUBI_PORT_PCM_DEV_DEL_ACK;

typedef struct _TTFSUBI_PORT_PCM_DEV_MODIFY
{
	DWORD						PortID;
	TTFSUBI_PORT_PCM_DEV_CONF	PortConf;
}TTFSUBI_PORT_PCM_DEV_MODIFY,*PTTFSUBI_PORT_PCM_DEV_MODIFY;
typedef struct _TTFSUBI_PORT_PCM_DEV_MODIFY_ACK
{
	ttfsubi_EnumResult	Result;
	DWORD				PortID;
}TTFSUBI_PORT_PCM_DEV_MODIFY_ACK,*PTTFSUBI_PORT_PCM_DEV_MODIFY_ACK;

typedef struct _TTFSUBI_PORT_PCM_DEV_QUERY
{
	DWORD				PortID;
}TTFSUBI_PORT_PCM_DEV_QUERY,*PTTFSUBI_PORT_PCM_DEV_QUERY;
typedef struct _TTFSUBI_PORT_PCM_DEV_QUERY_ACK
{
	ttfsubi_EnumResult			Result;
	DWORD						PortID;
	TTFSUBI_PORT_PCM_DEV_CONF	PortConf;
}TTFSUBI_PORT_PCM_DEV_QUERY_ACK,*PTTFSUBI_PORT_PCM_DEV_QUERY_ACK;

typedef struct _TTFSUBI_PORT_PCM_DEV_AUTO_SCAN_ACK
{
	ttfsubi_EnumResult			Result;
}TTFSUBI_PORT_PCM_DEV_AUTO_SCAN_ACK,*PTTFSUBI_PORT_PCM_DEV_AUTO_SCAN_ACK;




#define TTFSUBI_PIC_FILE_NUM_MAX				2048
typedef struct _TTFSUBI_PIC_GET_PIC_FILE_LIST
{
	char						strStartTime[32];
	char						strEndTime[32];
}TTFSUBI_PIC_GET_PIC_FILE_LIST,*PTTFSUBI_PIC_GET_PIC_FILE_LIST;
typedef struct _TTFSUBI_PIC_GET_PIC_FILE_LIST_ACK
{
	ttfsubi_EnumResult			Result;
	int							FileNum;
	char						strFileList[TTFSUBI_PIC_FILE_NUM_MAX][256];
}TTFSUBI_PIC_GET_PIC_FILE_LIST_ACK,*PTTFSUBI_PIC_GET_PIC_FILE_LIST_ACK;

typedef struct _TTFSUBI_PIC_GET_PIC_FILE_DATA
{
	char						strFileName[256];
}TTFSUBI_PIC_GET_PIC_FILE_DATA,*PTTFSUBI_PIC_GET_PIC_FILE_DATA;
typedef struct _TTFSUBI_PIC_GET_PIC_FILE_DATA_ACK
{
	ttfsubi_EnumResult			Result;
	char						strFileName[256];
	char						strFileDataBase64[512*1024];
}TTFSUBI_PIC_GET_PIC_FILE_DATA_ACK,*PTTFSUBI_PIC_GET_PIC_FILE_DATA_ACK;


typedef struct _TTFSUBI_EVENT_LOG_RECORD
{
	unsigned int				Level;
	char						strOwnerName[128];
	char						strTime[32];
	char						strLog[2048];
}TTFSUBI_EVENT_LOG_RECORD,*PTTFSUBI_EVENT_LOG_RECORD;
#define TTFSUBI_EVENT_LOG_MAX_NUM					1024
typedef struct _TTFSUBI_GET_EVENT_LOG_REQ
{
	unsigned int				Level;
	char						strStartTime[32];
	char						strEndTime[32];
}TTFSUBI_GET_EVENT_LOG_REQ,*PTTFSUBI_GET_EVENT_LOG_REQ;
typedef struct _TTFSUBI_GET_EVENT_LOG_ACK
{
	ttfsubi_EnumResult			Result;
	int							RecordNum;
	TTFSUBI_EVENT_LOG_RECORD	LogTab[TTFSUBI_EVENT_LOG_MAX_NUM];
}TTFSUBI_GET_EVENT_LOG_ACK,*PTTFSUBI_GET_EVENT_LOG_ACK;

typedef struct _TTFSUBI_AUTO_DEV_DESC
{
	DWORD			SmTypeCode;
	char			strSmName[48];
}TTFSUBI_AUTO_DEV_DESC,*PTTFSUBI_AUTO_DEV_DESC;
typedef struct _TTFSUBI_GET_AUTO_DEV_LIST
{
	DWORD			PortId;
}TTFSUBI_GET_AUTO_DEV_LIST,*PTTFSUBI_GET_AUTO_DEV_LIST;
#define	TTFSUBI_AUTO_DEV_NUM_MAX			256
typedef struct _TTFSUBI_GET_AUTO_DEV_LIST_ACK
{
	ttfsubi_EnumResult			Result;
	DWORD						PortId;
	DWORD						DevNum;
	TTFSUBI_AUTO_DEV_DESC		DevList[TTFSUBI_AUTO_DEV_NUM_MAX];
}TTFSUBI_GET_AUTO_DEV_LIST_ACK,*PTTFSUBI_GET_AUTO_DEV_LIST_ACK;








typedef struct _TTFSUBI_LOCAL_GET_FSUIP_ACK
{
	char	FsuIP[TTFSUBI_IP_LENGTH+4];
}TTFSUBI_LOCAL_GET_FSUIP_ACK;




typedef struct _TTFSUBI_MSG
{
	long	MsgType;
	union
	{
		TTFSUBI_LOGIN				Login;
		TTFSUBI_LOGIN_ACK			LoginAck;
		TTFSUBI_LOGOUT				LogOut;
		TTFSUBI_LOGOUT_ACK			LogOutAck;
		TTFSUBI_SEND_ALARM			Alarm;
		TTFSUBI_SEND_ALARM_ACK		AlarmAck;
		TTFSUBI_GET_DATA			GetData;
		TTFSUBI_GET_DATA_ACK		GetDataAck;
		TTFSUBI_GET_HISDATA			GetHisdata;
		TTFSUBI_GET_HISDATA_ACK		GetHisdataAck;
		TTFSUBI_SET_POINT			SetPoint;
		TTFSUBI_SET_POINT_ACK		SetPointAck;
		TTFSUBI_GET_THRESHOLD		GetThreshold;
		TTFSUBI_GET_THRESHOLD_ACK	GetThresholdAck;
		TTFSUBI_SET_THRESHOLD		SetThreshold;
		TTFSUBI_SET_THRESHOLD_ACK	SetThresholdAck;

		TTFSUBI_SET_FSUREBOOT		Reboot;
		TTFSUBI_SET_FSUREBOOT_ACK	RebootAck;
		TTFSUBI_GET_FSUINFO			GetFsuInfo;
		TTFSUBI_GET_FSUINFO_ACK		GetFsuInfoAck;
		TTFSUBI_TIME_CHECK			SetTime;
		TTFSUBI_TIME_CHECK_ACK		SetTimeAck;
		TTFSUBI_SET_FTP				SetFtp;
		TTFSUBI_SET_FTP_ACK			SetFtpAck;
		TTFSUBI_GET_FTP				GetFtp;
		TTFSUBI_GET_FTP_ACK			GetFtpAck;
		TTFSUBI_SET_LOGININFO		SetLoginInfo;
		TTFSUBI_SET_LOGININFO_ACK	SetLoginInfoAck;
		TTFSUBI_GET_LOGININFO		GetLoginInfo;
		TTFSUBI_GET_LOGININFO_ACK	GetLoginInfoAck;

		TTFSUBI_LOCAL_GET_FSUIP_ACK	GetFsuIPAck;

		TTFSUBI_GET_CONFIG_FSU				GetConfFsu;
		TTFSUBI_GET_CONFIG_FSU_ACK			GetConfFsuAck;
		TTFSUBI_GET_CONFIG_SO				GetConfSo;
		TTFSUBI_GET_CONFIG_SO_ACK			GetConfSoAck;
		TTFSUBI_GET_CONFIG_SENSOR			GetConfSensor;
		TTFSUBI_GET_CONFIG_SENSOR_ACK		GetConfSensorAck;
		TTFSUBI_GET_CONFIG_ACTIVE_ALARM_ACK	GetConfActiveAlarmAck;
		TTFSUBI_GET_CONFIG_HISALARM			GetConfHisAlarm;
		TTFSUBI_GET_CONFIG_HISALARM_ACK		GetConfHisAlarmAck;
		
		TTFSUBI_ADD_CONFIG_FSU				AddConfFsu;
		TTFSUBI_ADD_CONFIG_FSU_ACK			AddConfFsuAck;
		TTFSUBI_ADD_CONFIG_SO				AddConfSo;
		TTFSUBI_ADD_CONFIG_SO_ACK			AddConfSoAck;
		TTFSUBI_ADD_CONFIG_SENSOR			AddConfSensor;
		TTFSUBI_ADD_CONFIG_SENSOR_ACK		AddConfSensorAck;

		TTFSUBI_DELETE_CONFIG_FSU			DelConfFsu;
		TTFSUBI_DELETE_CONFIG_FSU_ACK		DelConfFsuAck;
		TTFSUBI_DELETE_CONFIG_SO			DelConfSo;
		TTFSUBI_DELETE_CONFIG_SO_ACK		DelConfSoAck;
		TTFSUBI_DELETE_CONFIG_SENSOR		DelConfSensor;
		TTFSUBI_DELETE_CONFIG_SENSOR_ACK	DelConfSensorAck;

		TTFSUBI_PUT_CONFIG_FSU				PutConfFsu;
		TTFSUBI_PUT_CONFIG_FSU_ACK			PutConfFsuAck;
		TTFSUBI_PUT_CONFIG_SO				PutConfSo;
		TTFSUBI_PUT_CONFIG_SO_ACK			PutConfSoAck;
		TTFSUBI_PUT_CONFIG_SENSOR			PutConfSensor;
		TTFSUBI_PUT_CONFIG_SENSOR_ACK		PutConfSensorAck;
		TTFSUBI_PUT_CONFIG_ALARM_PARAM		PutConfAlarmParam;
		TTFSUBI_PUT_CONFIG_ALARM_PARAM_ACK	PutConfAlarmParamAck;

		TTFSUBI_GET_FSU_RUN_STATUS_ACK		GetFsuRunStatusAck;
		TTFSUBI_PORT_PCM_DEV_AUTO_SCAN_ACK	PortPcmAutoScanAck;
		TTFSUBI_LOCAL_GET_NET_FLOW_ACK		GetNetFlowAck;

		TTFSUBI_PORT_PCM_DEV_ADD			PortPcmDevAdd;
		TTFSUBI_PORT_PCM_DEV_ADD_ACK		PortPcmDevAddAck;
		TTFSUBI_PORT_PCM_DEV_DEL			PortPcmDevDel;
		TTFSUBI_PORT_PCM_DEV_DEL_ACK		PortPcmDevDelAck;
		TTFSUBI_PORT_PCM_DEV_MODIFY			PortPcmDevModify;
		TTFSUBI_PORT_PCM_DEV_MODIFY_ACK		PortPcmDevModifyAck;
		TTFSUBI_PORT_PCM_DEV_QUERY			PortPcmDevQuery;
		TTFSUBI_PORT_PCM_DEV_QUERY_ACK		PortPcmDevQueryAck;

		TTFSUBI_PIC_GET_PIC_FILE_LIST		GetPicFileList;
		TTFSUBI_PIC_GET_PIC_FILE_LIST_ACK	GetPicFileListAck;
		TTFSUBI_PIC_GET_PIC_FILE_DATA		GetPicFileData;
		TTFSUBI_PIC_GET_PIC_FILE_DATA_ACK	GetPicFileDataAck;
		
		TTFSUBI_GET_EVENT_LOG_REQ			GetEventLogReq;
		TTFSUBI_GET_EVENT_LOG_ACK			GetEventLogAck;

		TTFSUBI_GET_AUTO_DEV_LIST			GetAutoDevList;
		TTFSUBI_GET_AUTO_DEV_LIST_ACK		GetAutoDevListAck;
	}MsgBody;
}TTFSUBI_MSG,*PTTFSUBI_MSG;









typedef void (*PTTFSUBI_API_CALLBACK)(const PTTFSUBI_MSG ReqMsg,PTTFSUBI_MSG AckMsg,void *pCallBackContext);
typedef struct _TTFSUBI_API_DATA_FUNC_TAB
{
	BOOL	(*bfaceGetData)(char *DeviceID,char *NodeID, TTFSUBI_TSEMAPHORE *data,DWORD *dwCount,char *nextDeviceId,char *nextNodeId,char *curDeviceid);
	BOOL	(*bfaceGetHistoryData)(char *DeviceID,char *NodeID, char *StartTime,char *EndTime, TTFSUBI_TSEMAPHORE *data,DWORD *dwCount,char *nextDeviceId,char *curDeviceid);
	BOOL	(*bfaceCtrlData)(char *DeviceID,TTFSUBI_TSEMAPHORE *data);
	BOOL	(*bfaceGetAlarm)(TTFSUBI_TALARM *alarm,BOOL bStart);
	DWORD	(*bfaceGetAlarmEx)(TTFSUBI_TALARM *alarm,DWORD dwCount);
	BOOL	(*bfaceSetAlarm)(TTFSUBI_TALARM *alarm,BOOL bStart);
	BOOL	(*bfaceSetAlarmEx)(TTFSUBI_TALARM *alarm,BOOL bStart,BOOL bSuccess);
	BOOL	(*bfaceWriteThresbhold)(char *DeviceID,TTFSUBI_TTHRESHOLD *data);
	BOOL	(*bfaceGetThresbhold)(char *DeviceID,char *NodeID, TTFSUBI_TTHRESHOLD *data,DWORD *dwCount,char *nextDeviceId,char *nextNodeId,char *curDeviceid);
			//修改告警点属性,dwMode=0高频次告警设置,bFlag=TRUE启用,FALSE停用;dwMode=1布撤防设置,bFlag=TRUE启用,FALSE停用;dwMode=2电压不平衡设置,bFlag=TRUE总电压模式,FALSE单体模式 
	BOOL	(*SetSensorProperty)(char *DeviceID,char *NodeID,DWORD dwMode,BOOL bFlag);
			//返回0表示成功，否则表示失败
	int		(*TtfsubiAccessDataBase)(PTTFSUBI_MSG pReq,PTTFSUBI_MSG pAck);				
}TTFSUBI_API_DATA_FUNC_TAB;
typedef struct _TTFSUBI_API_CONF
{
	unsigned short int		FsuServerPort;
	unsigned short int		ScServerPort;
	BOOL					IsDebug;
	BOOL					IsEnableInvalidData;
	int						(*pLog)(const char *pOwnerName,unsigned int Level,const char *pFormat,...);
	const char				*strScServerIP;
	const char				*strFsuID;
	const char				*strFsuCode;
	PTTFSUBI_API_CALLBACK	pCallBack;
	void					*pCallBackContext;
	const char				*strLoginUser;
	const char				*strLoginPwd;
	unsigned int			ScLoginKeepAlivetTimerS;
	TTFSUBI_API_DATA_FUNC_TAB	DataFuncTab;
}TTFSUBI_API_CONF,*PTTFSUBI_API_CONF;
typedef struct _TTFSUBI_API_STAT
{
	DWORD LoginFailCount;
	DWORD LoginOkCount;
	DWORD LoginResErrCount;
	DWORD LoginReqVpnRedialCount;
	DWORD SendAlarmFailCount;
	DWORD SendAlarmOkCount;
	DWORD SendAlarmResErrCount;
	DWORD SendAlarmDiscardCount;
	DWORD SendAlarmReqVpnRedialCount;
	DWORD ServerWorkCount;
	DWORD ServerFailCount;
	DWORD ServerWorkerCount;
	DWORD ServerBusyCount;
	DWORD ServerWorkerFailCount;
}TTFSUBI_API_STAT,*PTTFSUBI_API_STAT;


extern void TtfsubiFreeSoapContext(void);
extern BOOL TtfsubiCreateSoapContext(PTTFSUBI_API_CONF pConf);
extern void TtfsubiNotifyLogin(void);
extern void TtfsubiStopLogin(void);
extern DWORD TtfsubiGetFsuIdMismatchCount(void);
extern void TtfsubiGetRunStat(PTTFSUBI_API_STAT pStat);

/*
pUtf8Str==NULL时只返回输出长度，长度输入时必须比该值大1，自动输出字符串结束符
*/
extern BOOL PublicUtf8StrEncode(const char *pLocalStr,char *pUtf8Str,int *pUtf8StrLen);
/*
pLocalStr==NULL时只返回输出长度，长度输入时必须比该值大1，自动输出字符串结束符
*/
extern BOOL PublicUtf8StrDecode(const char *pUtf8Str,char *pLocalStr,int *pLocalStrLen);


#ifdef __cplusplus
}
#endif

#endif


