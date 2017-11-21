#ifndef _COMMDATA_20150121_H_
#define _COMMDATA_20150121_H_

#ifdef	__cplusplus
#if		__cplusplus
extern "C" {
#endif
#endif

#include		"Common.h"

//#define _THB

#define			VERSION_MONITOR			1

#define         YAOVERFLOW                      999999. /* overflow value             */
#define         INVALIDDATA                     -999999. /* invalid data               */
#define         INVALIDSTATUS                   0xff
#define         INVALIDPDATA                    0xffffffff
#define         INVALIDNODEID                   0xffff

#define         MAX_NAME_LENGTH                 40
#define         MAX_DESC_LENGTH                 256
#define         MAX_UNIT_LENGTH                 12

#define         MAX_PHONENUMLENGTH              20
#define         MAX_IPLENGTH			        20
#define         MAX_USERNAME_LENGTH		        20
#define         MAX_USERPWD_LENGTH		        20
#define         MAX_IDLENGTH			        20
#define         MAX_TIME_LENGTH					20

#define         STRING_LEN_12		            12
#define         STRING_LEN_20		            20
#define         STRING_LEN_40		            40
#define         STRING_LEN_128		            128
#define         STRING_LEN_256		            256

#define         NORMAL_STATE                    0                       /* no alarm                   */
#define         FATAL_ALARM                     1                       /* fatal alarm    �����澯            */
#define         MAIN_ALARM                      2                       /* main alarm     ��Ӧ��ԭ���Ľ����澯            */
#define         COMMON_ALARM                    3                       /* common alarm   ��Ӧ��ԭ������Ҫ�澯            */
#define			PROMPT_ALARM					4						/* ��ʾ�澯 ��Ӧ��ԭ����һ��澯*/	
#define         BREAK_ALARM						255                     /* break line alarm           */

#define         DATA_OP_INSERT                  1
#define         DATA_OP_MODIFY                  2
#define         DATA_OP_DELETE                  3
#define         DATA_OP_SELECT                  4

#define         DATA_TABLE_SU                   1
#define         DATA_TABLE_SO                   2
#define         DATA_TABLE_SENSOR               3
#define         DATA_TABLE_PORT                 4
#define         DATA_TABLE_SM                   5
#define         DATA_TABLE_ACTIVELINK           6
#define         DATA_TABLE_ACTIVETIME           7
#define			DATA_TABLE_VIRTUALNODETABLE		8		 //����ڵ��
#define			DATA_TABLE_ALARMFILTERTABLE		9		 //�澯���˹�����

#define         DATA_TABLE_ALARMTABLE           21
#define         DATA_TABLE_HISTORYTABLE         22
#define         DATA_TABLE_EVENTTABLE           23

//�ǰ´��������Ա�־
#define         MULTIBIT_TYPE                   0x1                    //��λ���������
#define         MULTIBIT_INPUT_TYPE             0x2                    //��λ������
#define         MULTIBIT_OUTPUT_TYPE            0x3                    //��λ�����

#define         ANALOG_TYPE                     0x10                   //ģ�����������
#define         ANALOG_INPUT_TYPE               0x11                   //ģ��������
#define         ANALOG_OUTPUT_TYPE              0x12                   //ģ�������
#define         DIGITAL_TYPE                    0x20                   //�������������
#define         DIGITAL_INPUT_TYPE              0x21                   //����������
#define         DIGITAL_OUTPUT_TYPE             0x22                   //���������
#define         PULSE_TYPE                      0x30                   //�������������
#define         PULSE_INPUT_TYPE                0x31                   //����������
#define         PULSE_OUTPUT_TYPE               0x32                   //���������
#define         MULTISTATE_TYPE                 0x50                   //��̬���������
#define         MULTISTATE_INPUT_TYPE           0x51                   //��̬������
#define         MULTISTATE_OUTPUT_TYPE          0x52                   //��̬�����
#define         DATETIME_TYPE                   0x60                   //�ۺ�ʱ����
#define         DATE_TYPE                       0x61                   //������
#define         TIME_TYPE                       0x62                   //ʱ����
#define         STRING_TYPE                     0x80                   //�ַ����������
#define         STRING_INPUT_TYPE               0x81                   //�ַ�������
#define         STRING_OUTPUT_TYPE              0x82                   //�ַ������

//��ң����������
#define			ATTRIB_YX						0						//ң���ź�(DI)��
#define			ATTRIB_YC						1						//ң���ź�(AI)��
#define			ATTRIB_YK						2						//ң���ź�(DO)��
#define			ATTRIB_YT						3						//ң���ź�(AO)

//���ݾ��ȶ���
#define         PRECISION_FLOAT                 0                       //������
#define         PRECISION_DECBYTE               1                       //ʮ�����ֽ���
#define         PRECISION_DECWORD               2                       //ʮ���Ƶ�����
#define         PRECISION_DECDWORD              3                       //ʮ����˫����
#define         PRECISION_HEXBYTE               4                       //ʮ�������ֽ���
#define         PRECISION_HEXWORD               5                       //ʮ�����Ƶ�����
#define         PRECISION_HEXDWORD              6                       //ʮ������˫����

//�������ݾ��ȣ�������Ԥ����������
#define         PRECISIONDOT(x)                 (LOBYTE(LOWORD((WORD)(x))) & 0x0f)
#define         PRECISIONTYPE(x)                (LOBYTE(LOWORD((WORD)(x))) >> 4)

#define         NODESETUP_DISABLE               0			//��Ч
#define         NODESETUP_NORMAL                1			//����
#define         NODESETUP_ALARMSCREEN           2			//����

//��������ģʽ
#define         ACTIVE_LINK_MODE_BELOW          1			//С������
#define         ACTIVE_LINK_MODE_OVER           2			//��������	
#define         ACTIVE_LINK_MODE_EQU            4			//��������
#define         ACTIVE_LINK_MODE_ALARM          8			//�澯����
#define			ACTIVE_LINK_MODE_NOTEQU			16			//������
#define			ACTIVE_LINK_MODE_HC				32			//�ز�����

//��������ģʽ
#define         ACTIVE_TIME_MODE_WEEKLY         1
#define         ACTIVE_TIME_MODE_TIME           2
#define         ACTIVE_TIME_MODE_DAY            3

//������������
#define         ACTIVE_CTRL_CTRL                1			//��ֵ����
#define         ACTIVE_CTRL_RECORD              2			//����¼��
#define         ACTIVE_CTRL_ALARM               3			//����������

//�����߼�ģʽ
#define			LOGICAL_AND						1			//��
#define			LOGICAL_OR						2			//��
#define			LOGICAL_NOT						4			//��
#define			LOGICAL_SET						8			//���ã�Ŀ�Ľڵ��ֵ���� ԭ��ڵ�
#define			LOGICAL_ADD						16			//�ۼƣ��������м�ص��ۼ�

//���������ģʽ
#define			VIRTUAL_PART_REASON				0			//������е�ԭ��ڵ�
#define			VIRTUAL_PART_RESULT				1			//������еĽ���ڵ�
#define			VIRTUAL_NODE_ID					((WORD)-1)	//������еĽ���ڵ��nodeid=-1


#define			ALARM_PROPERTY_GPC				1			//��Ƶ�θ澯��Alarm.Reserver & 0x01 == 0x01
#define			GPCALARM(Reserver)		 (((BYTE)(Reserver)) & 0x01)


//�����¼�����
#define         EVENT_LINK_ACTIVE_CTRL          1
#define         EVENT_LINK_UNACTIVE_CTRL        2
#define         EVENT_TIME_ACTIVE_CTRL          5
#define         EVENT_TIME_UNACTIVE_CTRL        6
#define         EVENT_TIME_ACTIVE_ALARM         11
#define         EVENT_TIME_UNACTIVE_ALARM       12
#define         EVENT_LINK_ACTIVE_RECORD        21
#define         EVENT_LINK_UNACTIVE_RECORD      22
#define         EVENT_TIME_ACTIVE_RECORD        25
#define         EVENT_TIME_UNACTIVE_RECORD      26


#define         EVENT_NORMAL_CTRL               101
#define         EVENT_NORMAL_ALARM              111
#define         EVENT_NORMAL_CONFIRM            112
#define         EVENT_NORMAL_CANCEL             113
#define         EVENT_CARD_BRUSH                114
#define         EVENT_NORMAL_DOORCTRL           121	/*ң�ؿ�����Ҫд�¼�ԭ�򣬲������*/
#define         EVENT_NORMAL_BCMTEST            122	/*��ز�����Ҫд�¼������Ƹ����*/
#define         EVENT_NORMAL_STATIONBREAK       123
#define         EVENT_USER_RECORD               129
#define         EVENT_USER_LOG                  151
#define			EVENT_STATION_LOG				152
#define			EVENT_USER_INVALID				153		//��Ч��¼
#define			EVENT_CONFIG_USER				192
#define			EVENT_CONFIG_SU					194
#define			EVENT_CONFIG_SO					195
#define			EVENT_CONFIG_SENSOR				196
#define			EVENT_CONFIG_PORT				198
#define			EVENT_CONFIG_SM					199
#define			EVENT_CONFIG_LDPZ				200
#define			EVENT_CONFIG_FILTER				201
#define			EVENT_CONFIG_ALARM				202		//�澯����
#define			EVENT_CONFIG_SCREEN				203		//�澯����
#define			EVENT_CONFIG_ALARMDELAY			206		//�澯�ӳ� �����ݱ��淽ʽ����

#define         SYSTEM_MEMBERID                 (WORD)(-1)


#define         BREAK_LINE_ALARM                1
#define         BREAK_LINE_RECOVER              2

#define			MAX_GROUPCOUNT					4		//ÿ���豸�������
#define			MAX_DEVICE_COUNT				16		//����豸����
#define         MAX_NODECOUNT                   1024
#define			MAX_BUFFER_SM_LENGTH			2048

#define			MAX_ACTIVELINK_COUNT			24

#define			MAX_PORT_COUNT					32
#define			MAX_SM_COUNT					32
#define			MAX_SO_COUNT					64
#define			MAX_SENSOR_COUNT				1024
#define			MAX_FILTER_GROUP				32		//�澯��������		//��8���޸�Ϊ16��

#define			MAX_IPCAMERA_COUNT				4		

#define			MAX_FILTER_REASON				128		//�澯����ԭ��
#define			MAX_FILTER_RESULT				8		//�澯���˽��

#define			MAX_NOT_REPORT_COUNT			1024	//δ�ϱ��澯��Ŀ
#define			MAX_GPC_COUNT					6		//��Ƶ�θ澯������ж�ֵ
#define			MAX_FILTER_COUNT				1024

#define			MAX_AUTOSM_COUNT				256		
#define			MAX_SMFORMAT_COUNT				2048
#define			MAX_SOFORMAT_COUNT				8192

static	char g_szModuleName[20] = "Common";
//���¶��徲̬��ṹ

typedef struct _SMFORMATTABLE
{
	DWORD SmTypeCode;
	char Address[24];
	char CommFormat[44];
	DWORD PollingTime;
	DWORD Timeout;
	DWORD GroupCount;
	char ExParam[132];
	char ProtocolFile[44];
	char Name[44];
	char NodeDesc[44];
	char Productor[44];
	char Version[24];
	char DeviceModel[44];
	char ExParamDesc[132];
	char GetinTime[28];
	char Remark[260];
}SMFORMATTABLE;

typedef struct _NODEFORMATTABLE
{
	DWORD SmTypeCode;
	DWORD NodeNo;
	DWORD NodeID;
	DWORD GroupID;
	DWORD Command;
	DWORD SubCommand;
	char  NodeName[44];
	DWORD ModeNo;
	DWORD Attrib;
	DWORD NodeLength;
	DWORD Offset;
	DWORD precs;
	char  Unit[16];
	char  NodeDesc[256];
}NODEFORMATTABLE;


typedef struct _SOFORMATTABLE
{
	WORD	SoType;
	WORD	SoSubType;
	DWORD	SmTypeCode;
	WORD	FsuType;
	WORD	Res2;
	DWORD	Res3;
	char	Name[MAX_NAME_LENGTH+4];
} SOFORMATTABLE;	//��ض���ģ����Ϣ��	


typedef struct _SENSORFORMATTABLE
{
	WORD	SoType;
	WORD	SoSubType;
	WORD	SensorCode;		
	WORD	NodeId;
	WORD	SenPrecision;
	WORD	Attrib;		//B�ӿڼ�ص�����
	WORD	SensorType;	//�ǰ¼�ص�����
	WORD	Res1;
	WORD	ModeNo;
	WORD	Res2;
	DWORD	Res3;
	DWORD	Res4;
	float	AlarmThresbhold;
	float	HighLimit;
	float	LowLimit;
	float	HighNormal;
	float	LowNormal;
	float	DataModify;
	DWORD	AlarmFlag;
	DWORD	AlarmDelay;
	DWORD	RecoverDelay;
	float	FatalAlarmHigh;
	float	FatalAlarmLow;
	float	MainAlarmHigh;
	float	MainAlarmLow;
	float	CommonAlarmHigh;
	float	CommonAlarmLow;	
	float	PromptAlarmHigh;
	float	PromptAlarmLow;
	DWORD	SaveFlag;
	DWORD	SaveSpan;
	float	RelativeVal;
	float	AbsoluteVal;
	char	Unit[MAX_UNIT_LENGTH + 4];
	char	StandardId[MAX_IDLENGTH+4];
	char	SensorName[MAX_NAME_LENGTH + 4];
	char	DataDesc[MAX_DESC_LENGTH + 4];
}	SENSORFORMATTABLE;		//��ص�ģ����Ϣ��(SensorFormatTable)

typedef struct  _STANDARDDICTTABLE
{

	DWORD	FSuType;
	DWORD	StandardIndex;
	char	StandardID[MAX_IDLENGTH+4];
	WORD	DeviceType;
	WORD	Attrib;
	char	LogicalName[MAX_NAME_LENGTH+4];
	char	StandardName[MAX_NAME_LENGTH+4];
	char	Unit[MAX_UNIT_LENGTH+4];
	char	AlarmDesc[124];
	char	SignDesc[124];
	char	Dsc[124];
	char	Remark[124];
	WORD	AlarmLevel;
	WORD	OverHigh;
	float	AlarmRange;
	DWORD	AlarmDelayTime;
	DWORD	SaveSpan;
	float	RelativeVal;
	float	AbsoluteVal;
	DWORD	Res1;
}	STANDARDDICTTABLE;		//��׼���ֵ��

typedef struct _FSUTABLE
{
	DWORD	FsuCode;
	char	LocalIP[MAX_IPLENGTH+4];
	char	LocalNetMask[MAX_IPLENGTH+4];
	char	LocalGatewayIP[MAX_IPLENGTH+4];
	char	LogServerIP[MAX_IPLENGTH+4];
	DWORD	LogServerPort;
	DWORD	FSuType;
	char	FSUID[MAX_IDLENGTH + 4];
	char	UserName[MAX_USERNAME_LENGTH + 4];
	char	PaSCword[MAX_USERPWD_LENGTH + 4];
	char	FSUSupply[MAX_NAME_LENGTH + 4];
	char	FsuName[MAX_NAME_LENGTH * 2 + 4];
	char	BeginRunTime[MAX_TIME_LENGTH+4];
	char	FtpUser[MAX_USERNAME_LENGTH + 4];
	char	FtpPWD[MAX_USERPWD_LENGTH + 4];
	char	IPSecUser[MAX_USERNAME_LENGTH + 4];
	char	IPSecPWD[MAX_USERPWD_LENGTH + 4];
	char	IPSecIP[MAX_IPLENGTH + 4];
	char	SCIP[MAX_IPLENGTH + 4];
}	FSUTABLE;	//��ص�Ԫ���ñ�

typedef struct _PORTTABLE
{
	WORD	PortID;
	WORD	PortType;
	char	PortCommFormat[STRING_LEN_20+4];
	char	BackCommFormat[STRING_LEN_20+4];
	DWORD	ResponseTime;
	DWORD	Timeout;
	WORD 	IsAutoPort;
	WORD	IsAutoFormat;
	WORD	IsAutoAddr;
	WORD 	Res1;
	char	PortAddress[68];
	char	BackAddress[68];
	char	NetPort[24];
	char	BackNetPort[24];
	char 	Res2[36];
}	PORTTABLE;		//�˿����ñ�




typedef struct _SMTABLE
{
	WORD	PortID;
	WORD	SmID;
	DWORD	SmTypeCode;
	char	Address[24];
	DWORD	PollingTime;
	DWORD	Timeout;
	char	ExParam[STRING_LEN_128 + 4];
	char	SmName[MAX_NAME_LENGTH + 4];
	char	ProtocolFile[STRING_LEN_40 + 4];	
}	SMTABLE;	//����豸���ñ�	

typedef struct _SOCONFIGTABLE
{
	WORD	SoCode;
	WORD	SoType;
	WORD	SoSubType;
	WORD	DeviceCode;
	WORD	Res1;
	WORD	Res2;
	DWORD	Res3;
	char	SoName[MAX_NAME_LENGTH+4];	
	char	DeviceID[MAX_IDLENGTH+4];
	char	NodeDesc[STRING_LEN_40+4];
	char	Productor[STRING_LEN_40+4];
	char	Version[STRING_LEN_20 + 4];
	char	BeginRunTime[MAX_TIME_LENGTH+4];
	char	DeviceModel[STRING_LEN_40 + 4];
}	SOCONFIGTABLE;	//��ض������ñ�

typedef struct _SENSORTABLE
{
	WORD	SoCode;
	WORD	SensorCode;
	WORD	SoType;
	WORD	SoSubType;
	WORD	SmID;
	WORD	NodeId;
	WORD	SenPrecision;
	WORD	Attrib;		//B�ӿڼ�ص�����
	WORD	SensorType;	//�ǰ¼�ص�����
	WORD	Res1;		//�����Ƿ����ø�Ƶ�θ澯,�Ƿ����ø澯����=1 ��Ƶ�θ澯 
	WORD	ModeNo;
	WORD	Res2;
	float	AlarmThresbhold;
	float	HighLimit;
	float	LowLimit;
	float	HighNormal;
	float	LowNormal;
	float	DataModify;
	DWORD	AlarmFlag;
	DWORD	AlarmDelay;
	DWORD	RecoverDelay;
	float	FatalAlarmHigh;
	float	FatalAlarmLow;
	float	MainAlarmHigh;
	float	MainAlarmLow;
	float	CommonAlarmHigh;
	float	CommonAlarmLow;	
	float	PromptAlarmHigh;
	float	PromptAlarmLow;
	DWORD	SaveFlag;
	DWORD	SaveSpan;
	float	RelativeVal;
	float	AbsoluteVal;
	char	Unit[MAX_UNIT_LENGTH + 4];
	char	StandardID[MAX_IDLENGTH+4];	//FSU��Ψһ
	char	SensorName[MAX_NAME_LENGTH + 4];
	char	DataDesc[MAX_DESC_LENGTH + 4];
}	SENSORTABLE;		//��ص�ģ����Ϣ��(SensorFormatTable)


typedef struct _ACTIVELINKTABLE
{
	DWORD	ID;
	WORD	SoCode;
	WORD	LinkSoCode;
	WORD	SensorCode;		
	WORD	LinkSensorCode;
	WORD	ActiveLinkMode;
	WORD	ActiveCtrl;
	DWORD	TimeLength;
	float	Value;
	float	UnValue;
	float	ActiveValue;
	float	UnActiveValue;
	char	Name[MAX_NAME_LENGTH+4];
}	ACTIVELINKTABLE;	//��ֵ�������ñ�

typedef struct _ACTIVETIMETABLE
{
	DWORD	ID;
	WORD	SoCode;
	WORD	ActiveTimeMode;
	WORD	SensorCode;		
	WORD	ActiveCtrl;	
	WORD	ActiveDay;
	WORD	ActiveWeekDay;
	WORD	ActiveHour;
	WORD	ActiveMinute;
	DWORD	TimeLength;
	float	ActiveValue;
	float	UnActiveValue;
	char	Name[MAX_NAME_LENGTH+4];
}	ACTIVETIMETABLE;	//ʱ���������ñ�


typedef struct _FILTERRULETABLE
{
	DWORD  ID;
	WORD  RuleID;
	WORD  FilterPart;		//0 �����˽ڵ�  1 �����жϽڵ�	
	WORD  LogicalMode;		//���˽ڵ����ģʽ��������(1)����(2)
	WORD  OverSo;			//�Ƿ���ض���
	DWORD  DelayTime;		//��ʱ�ж�ʱ��	
	char  StandardID[MAX_IDLENGTH+4];
	
}  FILTERRULETABLE;	//	

typedef struct _VIRTUALNODETABLE
{
	DWORD	ID;
	DWORD	VirtualIndex;
	WORD	SoCode;
	WORD	SensorCode;
	WORD	VirtualPart;
	WORD	LogicalMode;
	DWORD	CompareMode;
	float	ActiveValue;
	DWORD	Reserve;
	char	Dsc[MAX_NAME_LENGTH + 4];
}	VIRTUALNODETABLE;	//��������ñ�

typedef struct _IPCAMERACONFTABLE
{
	WORD	DevID;
	WORD	DevType;
	char	DevIP[MAX_IPLENGTH+4];
	DWORD	DevPort;
	char	UserName[MAX_USERNAME_LENGTH+4];
	char	UserPWD[MAX_USERPWD_LENGTH+4];
	char	DevName[MAX_NAME_LENGTH+4];
	char	DevAccessParam[STRING_LEN_256+4];
}	IPCAMERACONFTABLE;		//IPC���ñ�


//����Ϊ��̬��
typedef struct _ALARMTABLE
{
	DWORD	AlarmNO;		//�澯��ˮ��	
	WORD	SoCode;
	WORD	SensorCode;
	WORD	AlarmLevel;	
	WORD	SoType;
	WORD	SoSubType;
	WORD	SensorType;		
	WORD	ModeNo;	
	WORD	AlarmGpc;		//�Ƿ��Ƶ��
	WORD	AlarmFilter;	//�Ƿ��Ǳ����ε��¸澯������
	WORD	AlarmCount;		//��Ƶ�θ澯ʱ�ۼƴ���
	float   Value;	
	char 	StartTime[MAX_TIME_LENGTH+4];
	char 	EndTime[MAX_TIME_LENGTH+4];
	char	StartReportTime[MAX_TIME_LENGTH+4];
	char	EndReportTime[MAX_TIME_LENGTH+4];
	char	FSUID[MAX_IDLENGTH + 4];
	char	DeviceID[MAX_IDLENGTH+4];
	char	StandardID[MAX_IDLENGTH+4];
	char	AlarmDesc[MAX_NAME_LENGTH+4];
}	ALARMTABLE;


typedef struct _REALDATATABLE
{
	WORD	SoCode;
	WORD	SensorCode;
	char	DeviceID[MAX_IDLENGTH+4];
	char	StandardID[MAX_IDLENGTH+4];
	float	MeasuredVal;			//��ǰֵ
	float	SetupVal;				//����ֵ
	WORD	AlarmLevel;
	WORD	Attrib;					//����
	char	ValueTime[MAX_TIME_LENGTH+4];	//��ǰֵ������ʱ��
}	REALDATATABLE;	//��ʷ���ݱ�


typedef struct _EVENTTABLE
{
	WORD            MemberId;
	WORD            SoCode;
	WORD            SensorCode;
	WORD            SoType;
	BYTE            SoSubType;
	BYTE            EventCode;
	BYTE            EventSetup;
	BYTE            EventStatus;
	double			Value;
	char			StationIP[MAX_IPLENGTH+4];
	char			EventTime[MAX_TIME_LENGTH+4];
	char            Data[MAX_DESC_LENGTH];
}EVENTTABLE;	//�����¼���־��


typedef struct _YADATETIME
{
        WORD            Year;
        BYTE            Month;
        BYTE            Day;
        BYTE            Hour;
        BYTE            Minute;
        BYTE            Second;
        BYTE            MinSecond;
}       YADATETIME;



typedef struct _SHOWTITLE
{
	DWORD           Index;
	char            ShowText[52];
}	SHOWTITLE;

typedef struct _SENSORFORMAT
{
	WORD	SoType;
	WORD	SoSubType;
	WORD	SensorCode;		
	WORD	NodeId;
	DWORD	AlarmFlag;
	float	FatalAlarmHigh;
	float	FatalAlarmLow;
	float	MainAlarmHigh;
	float	MainAlarmLow;
	float	CommonAlarmHigh;
	float	CommonAlarmLow;	
	float	PromptAlarmHigh;
	float	PromptAlarmLow;
}	SENSORFORMAT;		//�򻯼�ص�ģ����Ϣ��

typedef struct _AUTOSMINFO
{
	WORD PortId;			//���ڱ��	
	WORD SmId;				//�豸���	
	DWORD SmTypeCode;		//�豸���
	WORD SoType;			//��ض�������
	WORD SoSubType;			//��ض�������
	DWORD SoCode;			//��ض�����
	WORD DeviceNo;			//�豸���
	WORD Res;				//����
	char SmName[44];		//����豸����
	char SoName[44];		//��ض�������
	char SmProtocol[44];	//����豸����
	char Address[24];		//Ĭ�ϵ�ַ	
	char CommFormat[44];	//Ĭ�ϴ���ģʽ	
	char Productor[44];		//��������	
	char Version[24];		//�汾����	
	char DeviceModel[44];	//�豸�ͺ�	
} AUTOSMINFO;



typedef struct _NODEFORMATTB
{
	DWORD SmTypeCode;
	DWORD GroupID;
	DWORD NodeID;	
	DWORD Attrib;
	DWORD NodeLength;
	DWORD Offset;
}NODEFORMATTB;

typedef struct _fsuinfotable
{
	DWORD ID;				//����
	char FsuID[24];			//Fsu���
	char ParamName[24];		//��������
	char ParamValue[84];	//����ֵ	
}fsuinfotable;

typedef struct _SENSOREX
{
	char StandardID[24];//�ź�ID	
	int AlmReportDelay;	//�澯��ʱѹ��ʱ��	
	float AlmLow;		//�ز���ֵ
	int	Res1;			//����1	,���������ֵ����,=1 ��ʾ��ID�Ǿ����ֵ����Ҫ�ϱ���
	int Res2;			//����2
} SENSOREX;

#ifdef _THB
	void JSYA_LES_LogPrintf(char *szMoudlename,DWORD dwLogLevel,char *param,...);
#endif

#ifdef	__cplusplus
#if		__cplusplus
}
#endif
#endif


#endif
