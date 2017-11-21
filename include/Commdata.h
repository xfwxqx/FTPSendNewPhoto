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
#define         FATAL_ALARM                     1                       /* fatal alarm    新增告警            */
#define         MAIN_ALARM                      2                       /* main alarm     对应于原来的紧急告警            */
#define         COMMON_ALARM                    3                       /* common alarm   对应于原来的重要告警            */
#define			PROMPT_ALARM					4						/* 提示告警 对应于原来的一般告警*/	
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
#define			DATA_TABLE_VIRTUALNODETABLE		8		 //虚拟节点表
#define			DATA_TABLE_ALARMFILTERTABLE		9		 //告警过滤关联表

#define         DATA_TABLE_ALARMTABLE           21
#define         DATA_TABLE_HISTORYTABLE         22
#define         DATA_TABLE_EVENTTABLE           23

//亚奥传感器属性标志
#define         MULTIBIT_TYPE                   0x1                    //多位输入输出量
#define         MULTIBIT_INPUT_TYPE             0x2                    //多位输入量
#define         MULTIBIT_OUTPUT_TYPE            0x3                    //多位输出量

#define         ANALOG_TYPE                     0x10                   //模拟输入输出量
#define         ANALOG_INPUT_TYPE               0x11                   //模拟输入量
#define         ANALOG_OUTPUT_TYPE              0x12                   //模拟输出量
#define         DIGITAL_TYPE                    0x20                   //数字输入输出量
#define         DIGITAL_INPUT_TYPE              0x21                   //数字输入量
#define         DIGITAL_OUTPUT_TYPE             0x22                   //数字输出量
#define         PULSE_TYPE                      0x30                   //脉冲输入输出量
#define         PULSE_INPUT_TYPE                0x31                   //脉冲输入量
#define         PULSE_OUTPUT_TYPE               0x32                   //脉冲输出量
#define         MULTISTATE_TYPE                 0x50                   //多态输入输出量
#define         MULTISTATE_INPUT_TYPE           0x51                   //多态输入量
#define         MULTISTATE_OUTPUT_TYPE          0x52                   //多态输出量
#define         DATETIME_TYPE                   0x60                   //综合时间量
#define         DATE_TYPE                       0x61                   //日期量
#define         TIME_TYPE                       0x62                   //时间量
#define         STRING_TYPE                     0x80                   //字符输入输出量
#define         STRING_INPUT_TYPE               0x81                   //字符输入量
#define         STRING_OUTPUT_TYPE              0x82                   //字符输出量

//四遥传感器属性
#define			ATTRIB_YX						0						//遥信信号(DI)，
#define			ATTRIB_YC						1						//遥测信号(AI)，
#define			ATTRIB_YK						2						//遥控信号(DO)，
#define			ATTRIB_YT						3						//遥调信号(AO)

//数据精度定义
#define         PRECISION_FLOAT                 0                       //浮点数
#define         PRECISION_DECBYTE               1                       //十进制字节数
#define         PRECISION_DECWORD               2                       //十进制单字数
#define         PRECISION_DECDWORD              3                       //十进制双字数
#define         PRECISION_HEXBYTE               4                       //十六进制字节数
#define         PRECISION_HEXWORD               5                       //十六进制单字数
#define         PRECISION_HEXDWORD              6                       //十六进制双字数

//对于数据精度，有以下预定义宏操作：
#define         PRECISIONDOT(x)                 (LOBYTE(LOWORD((WORD)(x))) & 0x0f)
#define         PRECISIONTYPE(x)                (LOBYTE(LOWORD((WORD)(x))) >> 4)

#define         NODESETUP_DISABLE               0			//无效
#define         NODESETUP_NORMAL                1			//布防
#define         NODESETUP_ALARMSCREEN           2			//撤防

//定义联动模式
#define         ACTIVE_LINK_MODE_BELOW          1			//小于联动
#define         ACTIVE_LINK_MODE_OVER           2			//大于联动	
#define         ACTIVE_LINK_MODE_EQU            4			//等于联动
#define         ACTIVE_LINK_MODE_ALARM          8			//告警联动
#define			ACTIVE_LINK_MODE_NOTEQU			16			//不等于
#define			ACTIVE_LINK_MODE_HC				32			//回差联动

//定义周期模式
#define         ACTIVE_TIME_MODE_WEEKLY         1
#define         ACTIVE_TIME_MODE_TIME           2
#define         ACTIVE_TIME_MODE_DAY            3

//定义联动类型
#define         ACTIVE_CTRL_CTRL                1			//数值控制
#define         ACTIVE_CTRL_RECORD              2			//联动录像
#define         ACTIVE_CTRL_ALARM               3			//联动布撤防

//定义逻辑模式
#define			LOGICAL_AND						1			//与
#define			LOGICAL_OR						2			//或
#define			LOGICAL_NOT						4			//非
#define			LOGICAL_SET						8			//设置，目的节点的值等于 原因节点
#define			LOGICAL_ADD						16			//累计，用于所有监控点累计

//定义虚拟点模式
#define			VIRTUAL_PART_REASON				0			//虚拟点中的原因节点
#define			VIRTUAL_PART_RESULT				1			//虚拟点中的结果节点
#define			VIRTUAL_NODE_ID					((WORD)-1)	//虚拟点中的结果节点的nodeid=-1


#define			ALARM_PROPERTY_GPC				1			//高频次告警，Alarm.Reserver & 0x01 == 0x01
#define			GPCALARM(Reserver)		 (((BYTE)(Reserver)) & 0x01)


//定义事件类型
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
#define         EVENT_NORMAL_DOORCTRL           121	/*遥控开门需要写事件原因，沧州添加*/
#define         EVENT_NORMAL_BCMTEST            122	/*电池测试需要写事件，连云港添加*/
#define         EVENT_NORMAL_STATIONBREAK       123
#define         EVENT_USER_RECORD               129
#define         EVENT_USER_LOG                  151
#define			EVENT_STATION_LOG				152
#define			EVENT_USER_INVALID				153		//无效登录
#define			EVENT_CONFIG_USER				192
#define			EVENT_CONFIG_SU					194
#define			EVENT_CONFIG_SO					195
#define			EVENT_CONFIG_SENSOR				196
#define			EVENT_CONFIG_PORT				198
#define			EVENT_CONFIG_SM					199
#define			EVENT_CONFIG_LDPZ				200
#define			EVENT_CONFIG_FILTER				201
#define			EVENT_CONFIG_ALARM				202		//告警分类
#define			EVENT_CONFIG_SCREEN				203		//告警屏蔽
#define			EVENT_CONFIG_ALARMDELAY			206		//告警延迟 和数据保存方式配置

#define         SYSTEM_MEMBERID                 (WORD)(-1)


#define         BREAK_LINE_ALARM                1
#define         BREAK_LINE_RECOVER              2

#define			MAX_GROUPCOUNT					4		//每类设备最大组数
#define			MAX_DEVICE_COUNT				16		//最大设备数量
#define         MAX_NODECOUNT                   1024
#define			MAX_BUFFER_SM_LENGTH			2048

#define			MAX_ACTIVELINK_COUNT			24

#define			MAX_PORT_COUNT					32
#define			MAX_SM_COUNT					32
#define			MAX_SO_COUNT					64
#define			MAX_SENSOR_COUNT				1024
#define			MAX_FILTER_GROUP				32		//告警过滤组数		//从8组修改为16组

#define			MAX_IPCAMERA_COUNT				4		

#define			MAX_FILTER_REASON				128		//告警过滤原因
#define			MAX_FILTER_RESULT				8		//告警过滤结果

#define			MAX_NOT_REPORT_COUNT			1024	//未上报告警数目
#define			MAX_GPC_COUNT					6		//高频次告警的最大判断值
#define			MAX_FILTER_COUNT				1024

#define			MAX_AUTOSM_COUNT				256		
#define			MAX_SMFORMAT_COUNT				2048
#define			MAX_SOFORMAT_COUNT				8192

static	char g_szModuleName[20] = "Common";
//以下定义静态表结构

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
} SOFORMATTABLE;	//监控对象模板信息表	


typedef struct _SENSORFORMATTABLE
{
	WORD	SoType;
	WORD	SoSubType;
	WORD	SensorCode;		
	WORD	NodeId;
	WORD	SenPrecision;
	WORD	Attrib;		//B接口监控点属性
	WORD	SensorType;	//亚奥监控点属性
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
}	SENSORFORMATTABLE;		//监控点模板信息表(SensorFormatTable)

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
}	STANDARDDICTTABLE;		//标准化字典表

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
}	FSUTABLE;	//监控单元配置表

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
}	PORTTABLE;		//端口配置表




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
}	SMTABLE;	//监控设备配置表	

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
}	SOCONFIGTABLE;	//监控对象配置表

typedef struct _SENSORTABLE
{
	WORD	SoCode;
	WORD	SensorCode;
	WORD	SoType;
	WORD	SoSubType;
	WORD	SmID;
	WORD	NodeId;
	WORD	SenPrecision;
	WORD	Attrib;		//B接口监控点属性
	WORD	SensorType;	//亚奥监控点属性
	WORD	Res1;		//用作是否启用高频次告警,是否启用告警屏蔽=1 高频次告警 
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
	char	StandardID[MAX_IDLENGTH+4];	//FSU下唯一
	char	SensorName[MAX_NAME_LENGTH + 4];
	char	DataDesc[MAX_DESC_LENGTH + 4];
}	SENSORTABLE;		//监控点模板信息表(SensorFormatTable)


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
}	ACTIVELINKTABLE;	//数值联动配置表

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
}	ACTIVETIMETABLE;	//时间联动配置表


typedef struct _FILTERRULETABLE
{
	DWORD  ID;
	WORD  RuleID;
	WORD  FilterPart;		//0 被过滤节点  1 过滤判断节点	
	WORD  LogicalMode;		//过滤节点关联模式，包括与(1)，或(2)
	WORD  OverSo;			//是否跨监控对象
	DWORD  DelayTime;		//延时判断时间	
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
}	VIRTUALNODETABLE;	//虚拟点配置表

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
}	IPCAMERACONFTABLE;		//IPC配置表


//以下为动态表
typedef struct _ALARMTABLE
{
	DWORD	AlarmNO;		//告警流水号	
	WORD	SoCode;
	WORD	SensorCode;
	WORD	AlarmLevel;	
	WORD	SoType;
	WORD	SoSubType;
	WORD	SensorType;		
	WORD	ModeNo;	
	WORD	AlarmGpc;		//是否高频次
	WORD	AlarmFilter;	//是否是被屏蔽导致告警结束的
	WORD	AlarmCount;		//高频次告警时累计次数
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
	float	MeasuredVal;			//当前值
	float	SetupVal;				//设置值
	WORD	AlarmLevel;
	WORD	Attrib;					//属性
	char	ValueTime[MAX_TIME_LENGTH+4];	//当前值发生的时间
}	REALDATATABLE;	//历史数据表


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
}EVENTTABLE;	//操作事件日志表


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
}	SENSORFORMAT;		//简化监控点模板信息表

typedef struct _AUTOSMINFO
{
	WORD PortId;			//串口编号	
	WORD SmId;				//设备编号	
	DWORD SmTypeCode;		//设备编号
	WORD SoType;			//监控对象类型
	WORD SoSubType;			//监控对象类型
	DWORD SoCode;			//监控对象编号
	WORD DeviceNo;			//设备序号
	WORD Res;				//保留
	char SmName[44];		//监控设备名称
	char SoName[44];		//监控对象名称
	char SmProtocol[44];	//监控设备名称
	char Address[24];		//默认地址	
	char CommFormat[44];	//默认串口模式	
	char Productor[44];		//生产厂家	
	char Version[24];		//版本描述	
	char DeviceModel[44];	//设备型号	
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
	DWORD ID;				//主键
	char FsuID[24];			//Fsu编号
	char ParamName[24];		//参数名称
	char ParamValue[84];	//参数值	
}fsuinfotable;

typedef struct _SENSOREX
{
	char StandardID[24];//信号ID	
	int AlmReportDelay;	//告警延时压缩时间	
	float AlmLow;		//回差数值
	int	Res1;			//保留1	,用作精简字典表用,=1 表示该ID是精简字典表需要上报的
	int Res2;			//保留2
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
