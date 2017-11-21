#ifndef _PM5K_PCM_API_H_
#define _PM5K_PCM_API_H_

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
 *			文件:		Pm5kPcmApi.h
 *			版本:		1.0
 *			作者:		ZCQ
 *			日期:		2011/12/15
 *
 *			亚奥数码技术有限公司版权所有 2011-2012
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
 * 版本 1.0   2011/12/15
 * 初始化版本 
 ************************************************************************************************************************************************************************
*/




/*
 ************************************************************************************************************************************************************************
 * 引用文件
 ************************************************************************************************************************************************************************
*/

#include "Pm5kType.h"



/*
 ************************************************************************************************************************************************************************
 * 常数与宏定义
 ************************************************************************************************************************************************************************
*/

#define PM5K_PCM_INVALID_HANDLE								((void *)(0xFFFFFFFFL))
#define PM5K_PCM_INVALID_SHARE_PORT_ID						(0xFFFFFFFFL)

#define PM5K_PCM_DEV_PROPERTY_VAL_TYPE_UNKNOW				0x00
#define PM5K_PCM_DEV_PROPERTY_VAL_TYPE_F32					0x01
#define PM5K_PCM_DEV_PROPERTY_VAL_TYPE_BYTE					0x02

#define PM5K_PCM_DEV_WORK_PARAM_TYPE_UNKNOW					0x00
#define PM5K_PCM_DEV_WORK_PARAM_TYPE_DEF					0x01
#define	PM5K_PCM_DEV_WORK_PARAM_TYPE_HT						0x02
#define	PM5K_PCM_DEV_WORK_PARAM_TYPE_LFP4850				0x03
#define	PM5K_PCM_DEV_WORK_PARAM_TYPE_WEIBO_J05				0x04
#define	PM5K_PCM_DEV_WORK_PARAM_TYPE_DLT645EM				0x05
#define PM5K_PCM_DEV_WORK_PARAM_TYPE_YADA_20XX				0x06
#define PM5K_PCM_DEV_WORK_PARAM_TYPE_SOCOMEC				0x07
#define PM5K_PCM_DEV_WORK_PARAM_TYPE_SICONUPS				0x08
#define PM5K_PCM_DEV_WORK_PARAM_TYPE_SC200					0x09
#define PM5K_PCM_DEV_WORK_PARAM_TYPE_HYK					0x0A
#define PM5K_PCM_DEV_WORK_PARAM_TYPE_WONTEX					0x0B
#define PM5K_PCM_DEV_WORK_PARAM_TYPE_SM50EX					0x0C


#define PM5K_PCM_DEV_AUTH_ACK_UNKNOW						0
#define PM5K_PCM_DEV_AUTH_ACK_SUCCESS						1
#define PM5K_PCM_DEV_AUTH_ACK_FAIL							2

/*这里定义智能设备类型，必须与智能设备类型配置文件中的定义保持一致；本库每增加一种智能设备支持都必须在此添加相应的类型定义，并且在实现文件的函数
* Pm5k_Pcm_GetDevInterface中添加相应的调用代码，同时添加相应的头文件引用*/
#define PM5K_PCM_DEV_TYPE_UNKNOW							0
/*艾默生开关电源M500S*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_M500S						1
/*中达开关电源CUC06*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_CUC06						2
/*中恒开关电源SM60*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SM60						3
/*格力空调第二版*/
#define PM5K_PCM_DEV_TYPE_KT_GL_V2							4
/*美的空调第三版*/
#define PM5K_PCM_DEV_TYPE_KT_MD_V3							5
/*艾默生电源PSM_A9*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_PSM_A9						6
/*格力空调第一版*/
#define PM5K_PCM_DEV_TYPE_KT_GL_V1							7
/*中达开关电源MCS6000*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_MCS6000						8
/*中达UPS电源DELTAUPS*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_DELTAUPS					9
/*新宏博三相自动重合闸APS*/
#define PM5K_PCM_DEV_TYPE_QY_XHB_APS						10
/*恒通电表HT 需要配置带入唤醒字节数和倍率*/
#define PM5K_PCM_DEV_TYPE_DB_HT								11
/*山特UPS电源*/
#define PM5K_PCM_DEV_TYPE_DY_SANTAK_UPS						12
/*珠江电源CU6300*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU6300						13
/*中恒电源SC200机房 15模块*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SC200						14
/*中恒电源SM4500C*/
#define	PM5K_PCM_DEV_TYPE_DY_ZH_SM4500C						15
/*中达斯米克电源MCS3000基站*/
#define	PM5K_PCM_DEV_TYPE_DY_ZD_MCS3000JZ					16
/*中达斯米克电源MCS3000机房*/
#define	PM5K_PCM_DEV_TYPE_DY_ZD_MCS3000JF					17
/*开关电源艾默生M810G交直流 M810G对下一个端口，对上因为模块和点较多按原P2000模型虚拟成交直流和整流2个设备*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M810G_JZL					18
/*开关电源艾默生M810G整流模块*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M810G_ZL					19
/*松下空调*/
#define PM5K_PCM_DEV_TYPE_KT_SX								20
/*三菱电机空调*/
#define PM5K_PCM_DEV_TYPE_KT_SLDJ							21
/*美的空调485*/
#define PM5K_PCM_DEV_TYPE_KT_MD_RS485						22
/*力博特空调*/
#define PM5K_PCM_DEV_TYPE_KT_LBT							23
/*佳力图空调*/
#define PM5K_PCM_DEV_TYPE_KT_JLT							24
/*春兰空调*/
#define	PM5K_PCM_DEV_TYPE_KT_CL								25
/*美的空调232*/
#define PM5K_PCM_DEV_TYPE_KT_MD_RS232						26
/*海菱空调8006*/
#define PM5K_PCM_DEV_TYPE_KT_HL_8006						27
/*海洛斯空调LINK*/
#define PM5K_PCM_DEV_TYPE_KT_HLS_LINK						28
/*海尔空调*/
#define PM5K_PCM_DEV_TYPE_KT_HE								29
/*威尔信油机ACCESS4000*/
#define PM5K_PCM_DEV_TYPE_YJ_WEX_ACCESS4000					30
/*武汉普兴电池监测仪 需要配置带入Packet序号*/
#define PM5K_PCM_DEV_TYPE_QY_PX_LFP4850						31
/*科勒油机DEC550*/
#define PM5K_PCM_DEV_TYPE_YJ_KL_DEC550						32
/*珠江电源CU2000H*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU2000H						33
/*珠江电源CU2500*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU2500						35
/*中恒直流屏DPZ97*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_DPZ97						36
/*艾默生开关电源M500S机房*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_M500SJF					37
/*阿尔西空调*/
#define PM5K_PCM_DEV_TYPE_KT_AIRSYS							38
/*CITEC登高空调*/
#define PM5K_PCM_DEV_TYPE_KT_DG								39
/*大金空调*/
#define PM5K_PCM_DEV_TYPE_KT_DJ								40
/*卡特比勒油机V3*/
#define PM5K_PCM_DEV_TYPE_YJ_KTBL_V3						41
/*艾默生485空调*/
#define PM5K_PCM_DEV_TYPE_KT_AMS_RS485						42
/*海尔商用空调*/
#define PM5K_PCM_DEV_TYPE_KT_HE_SY							43
/*海信空调*/
#define PM5K_PCM_DEV_TYPE_KT_HX								44
/*海通热管空调*/
#define PM5K_PCM_DEV_TYPE_KT_HTRG							45
/*中博集装架电能监测IMPU-01*/
#define PM5K_PCM_DEV_TYPE_QY_ZB_IMPU01						46
/*兆宇配电箱*/
#define PM5K_PCM_DEV_TYPE_QY_ZY								47
/*艾默生电源PSM_15*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_PSM_15						48
/*通力环电源*/
#define PM5K_PCM_DEV_TYPE_DY_TLH_TBOQ						49
/*中兴电源ZXDU68*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU68						50
/*中恒电源E40*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_E40							51
/*基站开关易达电源*/
#define PM5K_PCM_DEV_TYPE_DY_YD								52
/*基站开关易达电源新*/
#define PM5K_PCM_DEV_TYPE_DY_YD_NEW							53
/*亚奥蓄电池采集器BCM300*/
#define PM5K_PCM_DEV_TYPE_QY_YA_BCM300_48V					54
#define PM5K_PCM_DEV_TYPE_QY_YA_BCM300_24V_1				55
#define PM5K_PCM_DEV_TYPE_QY_YA_BCM300_24V_2				56
/*亚奥蓄电池采集器BCM400*/
#define PM5K_PCM_DEV_TYPE_QY_YA_BCM400						57
/*雅达电表*/
#define PM5K_PCM_DEV_TYPE_DB_YADA_2010						58
#define PM5K_PCM_DEV_TYPE_DB_YADA_2018						59
#define PM5K_PCM_DEV_TYPE_DB_YADA_2040						60
#define PM5K_PCM_DEV_TYPE_DB_YADA_2060						61
#define	PM5K_PCM_DEV_TYPE_DB_YD_DTSD3366D					62
/*维博电表*/
#define	PM5K_PCM_DEV_TYPE_DB_WB_1867B35						63
#define	PM5K_PCM_DEV_TYPE_DB_WB_1876J05						64
/*科泰油机新*/
#define	PM5K_PCM_DEV_TYPE_YJ_KT_KETAINEW					65
/*威尔信油机ACCESS6000*/
#define PM5K_PCM_DEV_TYPE_YJ_WEX_ACCESS6000					66
/*ACR配电屏*/
#define PM5K_PCM_DEV_TYPE_DB_AKR_ACR						67
/*艾默生油机切换器ASCO*/
#define PM5K_PCM_DEV_TYPE_YJ_AMS_ASCO						68
/*动力源电源*/
#define	PM5K_PCM_DEV_TYPE_DY_DLY							69
/*艾默生不间断电源HIPLUSS_U*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_HIPLUSSU					70
/*爱默生NXR系列UPS*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_NXR						71
/*爱默生NX系列UPS*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_NX							72
/*喷淋空调*/
#define PM5K_PCM_DEV_TYPE_KT_PENLIN							73
/*爱克赛UPS 9315 9390*/
#define PM5K_PCM_DEV_TYPE_DY_AKS_9315						74
#define PM5K_PCM_DEV_TYPE_DY_AKS_9390						75
/*UPS_SYSPOW*/
#define PM5K_PCM_DEV_TYPE_DY_SYSPOW_UPS						76
/*开关电源艾默生PSMA机房 交直流*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_PSMA_R_JZL					77
/*开关电源艾默生PSMA机房 整流模块20个*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_PSMA_R_ZL					78
/*威尔信油机PW2.0*/
#define PM5K_PCM_DEV_TYPE_YJ_WEX_PW20						79
/*实达UPS(sitepro)*/
#define PM5K_PCM_DEV_TYPE_DY_SD_SITEPRO						80
/*中恒电源SM50*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SM50						81
/*亚奥蓄电池采集器P5000_BCM300*/
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_48V				82
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_24V_1			83
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_24V_2			84
/*中恒电源SM65机房*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SM65						85
/*SOCOMEC配电屏*/
#define PM5K_PCM_DEV_TYPE_DB_SKM_SOCOMEC					86
/*不间断电源先控UPS*/
#define PM5K_PCM_DEV_TYPE_DY_SICON_UPS						87
/*梅兰日兰UPS*/
#define PM5K_PCM_DEV_TYPE_DY_MLRL_MGEUPS					88
/*亚奥蓄电池采集器P5000_BCM300_V1.2 Lattice替换单片机*/
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_V1_2_48V			89
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_V1_2_24V_1		90
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_V1_2_24V_2		91
/*中恒电源SC100*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SC100						92
/*雅达温度传感器YD8000*/
#define PM5K_PCM_DEV_TYPE_QY_YD_YD8000						93
/*消防系统GST200*/
#define PM5K_PCM_DEV_TYPE_QY_XF_GST200						94
/*亚奥数据采集器RTM电总*/
#define PM5K_PCM_DEV_TYPE_QY_YA_RTM300						95
/*三洋空调第一版*/
#define PM5K_PCM_DEV_TYPE_KT_SY_SANYOV1						96
/*三洋空调第二版*/
#define PM5K_PCM_DEV_TYPE_KT_SY_SANYOV2						97
/*艾默生空调DATAMATE3000系列*/
#define PM5K_PCM_DEV_TYPE_KT_AMS_DATAMATE3000				98
/*辛普森油机SAC2000系列*/
#define PM5K_PCM_DEV_TYPE_YJ_XPS_SAC2000					99
/*阿尔西空调AL3000系列*/
#define PM5K_PCM_DEV_TYPE_KT_AEX_AL3000						100
/*阿尔西空调Airsys99系列*/
#define PM5K_PCM_DEV_TYPE_KT_AEX_AIRSYS99					101
/*科龙空调*/
#define PM5K_PCM_DEV_TYPE_KT_KELONG							102
/*佳力图空调13系列*/
#define PM5K_PCM_DEV_TYPE_KT_JLT_CANATAL13					103
/*佳力图空调ME系列*/
#define PM5K_PCM_DEV_TYPE_KT_JLT_CANATALME					104
/*爱克赛UPS 9305*/
#define PM5K_PCM_DEV_TYPE_DY_AKS_9305						105
/*红外遥控器HYK*/
#define PM5K_PCM_DEV_TYPE_QY_HYK							106
/*中达开关电源MCS6000机房*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_MCS6000JF					107
/*普天DK04C_V2*/
#define PM5K_PCM_DEV_TYPE_DY_PT_DK04CV2						108
/*普天DND逆变器*/
#define PM5K_PCM_DEV_TYPE_DY_PT_PTDND						109
/*威泰迅低压柜*/
#define PM5K_PCM_DEV_TYPE_DY_WTX_WONTEX						110
/*GE_UPS*/
#define PM5K_PCM_DEV_TYPE_DY_GEUPS							111
/*新绿原降雨量传感器*/
#define PM5K_PCM_DEV_TYPE_QY_XLY_RF							112
/*P5000B_BCM300*/
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO1_48V			113
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO1_24V_1		114
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO1_24V_2		115
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO2_48V			116
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO2_24V_1		117
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO2_24V_2		118
/*鹰潭北大青鸟消防*/
#define PM5K_PCM_DEV_TYPE_QY_BDQN_JBF193					119
/*艾默生机房电源M522S*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_M522SJF					120
/*深圳华为电源PSM-8*/
#define PM5K_PCM_DEV_TYPE_DY_HW_PSM_8						121
/*金宏威电源JK1000系列*/
#define PM5K_PCM_DEV_TYPE_DY_JHW_JK1000						122
/*金宏威电源SC2000系列*/
#define PM5K_PCM_DEV_TYPE_DY_JHW_SC2000						123
/*中兴电源ZXDU300V3.0*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU300V30					124
/*珠江电源CU3000*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU3000						125
/*艾默生电源PSM-A 12模块*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_PSM_A						126
/*佛光6300油机*/
#define PM5K_PCM_DEV_TYPE_YJ_FG_HGM6300						127
/*APCSilconUPS*/
#define PM5K_PCM_DEV_TYPE_DY_XK_APCUPS						128
/*C6000空调*/
#define PM5K_PCM_DEV_TYPE_KT_STS_C6000						129
/*C7000空调*/
#define PM5K_PCM_DEV_TYPE_KT_STS_C7000						130
/*UN空调mp3系列*/
#define PM5K_PCM_DEV_TYPE_KT_UN_MP3							131
/*中达电源CU01机房中文版*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_CU01CH_JF					132
/*中达电源MCS6000机房连云港*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_MCS6000_LYGJF				133
/*中达电源CU01机房英文版*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_CU01EN_JF					134
/*特灵水冷空调*/
#define PM5K_PCM_DEV_TYPE_KT_TL_TRANE						135
/*精密配电柜PMAC201*/
#define PM5K_PCM_DEV_TYPE_DB_PMAC201						136
/*康明斯油机*/
#define PM5K_PCM_DEV_TYPE_YJ_KMS							137
/*卡特比勒油机V2*/
#define PM5K_PCM_DEV_TYPE_YJ_KTBL_V2						138
/*GriPower_UPS*/
#define PM5K_PCM_DEV_TYPE_DY_GRIPOWER_UPS					139
/*立科定位报警控制器ATL600*/
#define PM5K_PCM_DEV_TYPE_QY_LK_ATL600						140
/*雅达温湿度传感器YD10HT*/
#define PM5K_PCM_DEV_TYPE_QY_YD_YD10HT						141
/*IMS_DTS系列UPS*/
#define PM5K_PCM_DEV_TYPE_DY_IMS_DTS						142
/*艾默生空调ACM03U系列*/
#define PM5K_PCM_DEV_TYPE_KT_AMS_ACM03U						143
/*北方测控温湿度传感器DB506*/
#define PM5K_PCM_DEV_TYPE_QY_DLBF_CEKONGDB506				144
/*德赛AI2000馈线柜*/
#define PM5K_PCM_DEV_TYPE_DB_DS_AI2000KUIXIAN				145
/*德赛AI2000进线柜*/
#define PM5K_PCM_DEV_TYPE_DB_DS_AI2000JINXIAN				146
/*德赛AI2000联络柜*/
#define PM5K_PCM_DEV_TYPE_DB_DS_AI2000LIANLUO				147
/*德赛AI2000切换柜*/
#define PM5K_PCM_DEV_TYPE_DB_DS_AI2000QIEHUAN				148
/*恒通电表2007*/
#define PM5K_PCM_DEV_TYPE_DB_HT_HT2007						149
/*电柜AB204UI系列*/
#define PM5K_PCM_DEV_TYPE_DB_AB204UI						150
/*泰坦电源TTX-I-E系列*/
#define PM5K_PCM_DEV_TYPE_DY_TT_TTXIE						151
/*瓦特电源CSU03B*/
#define PM5K_PCM_DEV_TYPE_DY_WT_CSU03B						152
/*许继电源WZCK-21系列*/
#define PM5K_PCM_DEV_TYPE_DY_XJ_WZCK21						153
/*易事特不间断电源89系列*/
#define PM5K_PCM_DEV_TYPE_DY_YST_EAST89						154
/*中恒电源SM60机房*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SM60JF						155
/*中兴机房电源ZXDU88交直流屏*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU88_R_JZL				156
/*中兴机房电源ZXDU88整流屏*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU88_R_ZL					157
/*海尔空调电总*/
#define PM5K_PCM_DEV_TYPE_KT_HE_HRSI						158
/*海卡读卡器*/
#define PM5K_PCM_DEV_TYPE_DKQ_HEIKEY						159
/*开普油机KP310*/
#define PM5K_PCM_DEV_TYPE_YJ_KAIPU_KP610						260
/*力博特不间断电源HIPLUSS系列*/
#define PM5K_PCM_DEV_TYPE_DY_LBT_HIPLUSS_UPS					261
/*开关电源艾默生PSMA机房多屏 交直流*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_PSMA_RDUO_JZL			262
/*开关电源艾默生PSMA机房多屏 整流*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_PSMA_RDUO_ZL					263
/*DJB系列UPS*/
#define PM5K_PCM_DEV_TYPE_DY_DJB_UPS								264
/*华自直流屏JK02B系列*/
#define PM5K_PCM_DEV_TYPE_DY_HZ_JK02B								265
/*开关电源中兴ZXDU3000机房 交直流*/
#define	PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU3000_R_JZL					266 
/*开关电源中兴ZXDU3000机房 整流30模块*/
#define	PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU3000_R_ZL					267
/*ABB配电屏EM-M系列*/
#define	PM5K_PCM_DEV_TYPE_DB_ABB_EM_M					268
/*ABB配电屏EM-100系列电流表*/
#define	PM5K_PCM_DEV_TYPE_DB_ABB_EM_100_I					269
/*ABB配电屏EM-400系列*/
#define	PM5K_PCM_DEV_TYPE_DB_ABB_EM_400					270
/*双登锂电池*/
#define	PM5K_PCM_DEV_TYPE_QT_SDBAT					271
/*中兴机房电源ZXDU88交直流多屏*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU88_RDUO_JZL				272
/*中兴机房电源ZXDU88整流屏30模块*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU88_RDUO_ZL					273
/*汰能锂电池*/
#define	PM5K_PCM_DEV_TYPE_QT_PNBAT					274
/*市电/油机切换柜GU660A*/
#define	PM5K_PCM_DEV_TYPE_YJ_GU660A					275
/*施耐德高压柜SPEAM_S40*/
#define	PM5K_PCM_DEV_TYPE_DB_SCHNEIDER_SPEAM_S40					276
/*施耐德高压柜SPEAM_T20*/
#define	PM5K_PCM_DEV_TYPE_DB_SCHNEIDER_SPEAM_T20					277
/* 液位仪XST-1A */
#define	PM5K_PCM_DEV_TYPE_QT_XST_1A					278
/* 凯讯配电屏DMS96A */
#define	PM5K_PCM_DEV_TYPE_DB_DMS96A					279
/* 依米康空调K200 */
#define	PM5K_PCM_DEV_TYPE_KT_YMK_K200					280
/* 中恒高压直流监控器交直流数据 */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_ZHM07_JZL					181
/* 中恒高压直流监控器整流数据 */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_ZHM07_ZL_5					182
/* 施耐德配电屏PM5350 */
#define	PM5K_PCM_DEV_TYPE_DB_SCHNEIDER_PM5350					183
/* 斯菲尔配电屏PA194I-9K4G 7台 */
#define	PM5K_PCM_DEV_TYPE_DB_SFERE_PA194I_9K4G					184
/* 中达高压供电系统直流数据 */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_HVP_JZL					185
/* 中达高压供电系统整流数据 */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_HVP_ZL					186
/*机房易达开关电源交直流屏*/
#define PM5K_PCM_DEV_TYPE_DY_YD_JZL						187
/*机房易达开关电源整流屏*/
#define PM5K_PCM_DEV_TYPE_DY_YD_ZL						188
/*机房中达开关电源*/
#define PM5K_PCM_DEV_TYPE_DY_DELTA_CUC06_R						189
/*科龙不间断电源*/
#define PM5K_PCM_DEV_TYPE_DY_KELONG_UPS						190
/* 扬州中凌电源BC650 */
#define PM5K_PCM_DEV_TYPE_DY_ZHONGLING_BC650						191
/* 中恒机房电源SM50交直流数据_ 江苏 */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_SM50_JZL_JS				192
/* 中恒机房电源SM50整流数据_江苏 */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_SM50_ZL_JS				193
/* 中恒交流屏DPJ93 */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_DPJ93							194
/* 创科喷淋空调 */
#define	PM5K_PCM_DEV_TYPE_KT_CHUANGKE							195
/* 清大直流RD200A */
#define	PM5K_PCM_DEV_TYPE_DY_RD200A									196
/* 卓联配电柜AB-CD194UI_2S4 */											
#define	PM5K_PCM_DEV_TYPE_DB_ZL_CD194UI_2S4				197
/* EAST800不间断电源 */
#define	PM5K_PCM_DEV_TYPE_DY_EAST800							198
/* 中恒ZHM04交流屏 */
#define PM5K_PCM_DEV_TYPE_DY_ZH_ZHM04_AC					199
/* 中达DPS6000直流供电系统交直流数据 */							
#define PM5K_PCM_DEV_TYPE_DY_DELTA_DPS6000_JZL	200
/* 中达DPS6000直流供电系统整流数据 */
#define PM5K_PCM_DEV_TYPE_DY_DELTA_DPS6000_ZL		201
/* 中达机房电源CUC-01HE交直流数据 */
#define PM5K_PCM_DEV_TYPE_DY_DELTA_CUC_01HE_JZL		202
/* 中达机房电源CUC-01HE整流数据 */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_CUC_01HE_ZL		203
/* 武汉洲际电源DK04C_V1 */
#define	PM5K_PCM_DEV_TYPE_DY_ZHOUJI_DK04C_V1			204
/* 油机控制器HGM6100系列 */
#define	PM5K_PCM_DEV_TYPE_YJ_HGM6100							205
/* 总打电源CUC-01HE */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_CUC_01HE				206
/* 烽火电源 */
#define	PM5K_PCM_DEV_TYPE_DY_FENGHUO							207
/* 山鹰消防 */
#define	PM5K_PCM_DEV_TYPE_XF_SHANYING							208
/* 精敏调光仪JMDM-COMTTG */
#define	PM5K_PCM_DEV_TYPE_QT_JMDM_COMTTG					209
/* 斯菲尔配电屏PD194E-9S4G */
#define	PM5K_PCM_DEV_TYPE_DB_PD194E_9S4G					210
/* 恒诺多功能电表3相 */
#define	PM5K_PCM_DEV_TYPE_DB_HENGHUO_3PHASE					211
/* 青岛瑞斯达直流屏PMU-S10 */
#define	PM5K_PCM_DEV_TYPE_DB_PMU_S10_MODEBUS					212
/* 南自测线保护装置PDS-751系列 */
#define PM5K_PCM_DEV_TYPE_DY_PDS751						213
/* LD变压器温控仪 */										
#define	PM5K_PCM_DEV_TYPE_QT_LD								214
/* TTC-310系列温控器 */
#define	PM5K_PCM_DEV_TYPE_QT_TTC310						215
/* 配电屏PMW2000 */
#define	PM5K_PCM_DEV_TYPE_QT_PMW2000					216	
/* 南瑞继保RCS9611CS保护测控装置 */							
#define	PM5K_PCM_DEV_TYPE_QT_NR_RCS9611CS			217
/* 恒诺多功能电表单相 */
#define	PM5K_PCM_DEV_TYPE_DB_HENGHUO_1PHASE					218
/* 配电屏PMW2000H */
#define	PM5K_PCM_DEV_TYPE_DB_PMW2000H					219
/* 保定SF6监控系统HDJK-6000 */
#define	PM5K_PCM_DEV_TYPE_QT_HDJK6000					220
/* 博强锂电池监测仪 */
#define	PM5K_PCM_DEV_TYPE_QT_BQBAT					221
/* 西门子SPSD太阳能 */
#define	PM5K_PCM_DEV_TYPE_QT_SPSD					222
/* 科龙空调电总V3.0 */
#define	PM5K_PCM_DEV_TYPE_KT_KELONGV30					223
/* 南瑞继保RCS9651CS保护测控装置 */
#define	PM5K_PCM_DEV_TYPE_QT_NR_RCS9651CS					224
/* 艾默生机房电源M810G交直流数据3直流屏 */
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M810G3DC_JZL					225
/* 艾默生机房电源M810G整流30模块 */
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M810G3DC_ZL30					226
/* 奥特迅电源 */
#define	PM5K_PCM_DEV_TYPE_DY_AOTEXUN					227
/* 金电电源RM2003系列 */
#define	PM5K_PCM_DEV_TYPE_DY_JD_RM2003					228
/* 不间断电源KSTAR系列 */
#define	PM5K_PCM_DEV_TYPE_DY_KSTAR_UPS					229
/* 新泰达电源电总系列 */
#define	PM5K_PCM_DEV_TYPE_DY_TAIDADZ					230
/* 泰达电源 */
#define	PM5K_PCM_DEV_TYPE_DY_TAIDA					231
/* 山特不间断电源3A3系列 */
#define	PM5K_PCM_DEV_TYPE_DY_SANTAK3A3					232
/* 南都锂电池 */
#define	PM5K_PCM_DEV_TYPE_QT_NANDU					233
/* 中兴电源ZXDU68_T601 */
#define PM5K_PCM_DEV_TYPE_DY_ZXDU_T601			234
/* 德赛AI2000补偿柜 */
#define PM5K_PCM_DEV_TYPE_DB_AI2000BUCHANG			235
/* 多功能电力仪表 */
#define PM5K_PCM_DEV_TYPE_DB_DUODB			236
/* 博尔电力采集模块 */
#define PM5K_PCM_DEV_TYPE_DB_BOERMODULE			237
/* 溯高美配电屏A38系列 */
#define PM5K_PCM_DEV_TYPE_DB_SOCOMEC_A38		238
/* 溯高美配电屏A20系列 */
#define PM5K_PCM_DEV_TYPE_DB_SOCOMEC_A20		239
/* 智能配电管理系统MCGS系列 */
#define	PM5K_PCM_DEV_TYPE_DB_MCGS						240
/* 华为电源V300系列交直流 */
#define	PM5K_PCM_DEV_TYPE_DY_HW_V300_JZL						241
/* 华为电源V300系列20模块 */
#define	PM5K_PCM_DEV_TYPE_DY_HW_V300_ZL						242
/* 海红交流DPJ-G5通信协议带主备分合(双路) */
#define	PM5K_PCM_DEV_TYPE_DB_DPJ_G5_DOUBLE		243
/* LD128E系列消防 */
#define	PM5K_PCM_DEV_TYPE_QT_LD128E		244
/* 辛普森油机SAC7000系列 */
#define	PM5K_PCM_DEV_TYPE_YJ_XPS_SAC7000		245
/* BCM310铁塔测试 */
#define	PM5K_PCM_DEV_TYPE_QT_YAAO_BCMCESHI		246
/* GPS定位系统 */
#define	PM5K_PCM_DEV_TYPE_QT_GPS		247
/* 雅达电表铁塔测试 */
#define	PM5K_PCM_DEV_TYPE_DB_YD_DTSD3366DCESHI					249
/* 传通科技智能门禁 */
#define	PM5K_PCM_DEV_TYPE_MJ_CHUANTONG					250
/* 智能电表PMAC720系列 */
#define	PM5K_PCM_DEV_TYPE_BOER_PMAC720					251
/* 安科瑞ACR配电屏0907系列 */
#define	PM5K_PCM_DEV_TYPE_ACR0907					252
/* 佛光油机PCC2100系列 */
#define	PM5K_PCM_DEV_TYPE_PCC2100					253
/* 潍柴油机H2 */
#define	PM5K_PCM_DEV_TYPE_YJ_WEICHAIH2					255

/* 海红交流带开关量(单路) */
#define	PM5K_PCM_DEV_TYPE_HAIHONG_SINGLE		360
/* 艾默生高压直流电源HVDC_M822E 交直流数据 (交直流和整流公用一个下行口，对上对应两个地址)*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M822E_JZL					256
/* 艾默生高压直流电源HVDC_M822E 整流数据*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M822E_ZL					257
/* 开普油机 GU3311*/
#define	PM5K_PCM_DEV_TYPE_YJ_KAIPU_GU3311					258
/* 中达电源CUC-06 12模块*/
#define	PM5K_PCM_DEV_TYPE_DY_ZD_CUC06_12MODEL					259
/* 艾默生电源M522S_铁塔 */
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M522S_TT					160
/* 动力源电源_铁塔 */
#define	PM5K_PCM_DEV_TYPE_DY_DLY_TT					161
/* 华为电源SMU06C_铁塔 */
#define	PM5K_PCM_DEV_TYPE_DY_HW_SMU06C_TT		162
/* 中达电源CUC06_铁塔 */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_CUC06CESHI		163
/*中恒电源SC100_铁塔*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SC100_TT						164
/*珠江电源CU3000C_铁塔*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU3000C_TT						165
/* 中兴电源ZXDU68_T601_铁塔 */
#define PM5K_PCM_DEV_TYPE_DY_ZXDU_T601_TT			166
/* TCL空调_铁塔 */
#define PM5K_PCM_DEV_TYPE_KT_TCL_TT							167
/* 格力空调第二版_铁塔 */
#define PM5K_PCM_DEV_TYPE_KT_GL_V2_TT			168
/* 科龙空调电总V3.0铁塔 */
#define	PM5K_PCM_DEV_TYPE_KT_KELONGV30_TT					169
/* 美的空调第三版_铁塔 */
#define PM5K_PCM_DEV_TYPE_KT_MD_V3_TT							170
/* 安科瑞电表_铁塔 */
#define PM5K_PCM_DEV_TYPE_DB_AKR_ACR_TT							171
/* 雅达电表2080_铁塔 */
#define PM5K_PCM_DEV_TYPE_DB_YADA2080_TT							172
/* 尚灵AMCT050_铁塔 */
#define PM5K_PCM_DEV_TYPE_DB_SL_AMCT050_TT							173
/* 力创电表DMSD40_铁塔 */
#define PM5K_PCM_DEV_TYPE_DB_LC_DMSD40_TT							174
/* 海特温控_铁塔 */
#define PM5K_PCM_DEV_TYPE_KT_HT_HAYDEN_TT							175
/* 华瑞温控_铁塔 */
#define PM5K_PCM_DEV_TYPE_KT_HR_TT							176
/* 英维克温控_铁塔 */
#define PM5K_PCM_DEV_TYPE_KT_EX_TT							177
/* 高新兴门禁BASS260_铁塔 */
#define PM5K_PCM_DEV_TYPE_MJ_GXX_BASS260_TT							178
/* 中兴门禁ACUC_铁塔 */
#define PM5K_PCM_DEV_TYPE_MJ_ZXDU_ACUC_TT							179




/*
 ************************************************************************************************************************************************************************
 * 数据类型定义
 ************************************************************************************************************************************************************************
*/

typedef void * PM5K_PCM_HANDLE;

/*
 ************************************************************************************************************************************************************************     
 *函数名称: PPM5K_PCM_SEND_TO_DOWN_CALLBACK
 *功能描述: 数据发送回调函数
 *输入描述: 设备句柄、数据缓冲区、数据长度、回调环境
 *输出描述: 无
 *返回描述: 无
 *作者日期: 
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
typedef void (*PPM5K_PCM_SEND_TO_DOWN_CALLBACK)(PM5K_PCM_HANDLE hDev,const void *Buf,PM5K_U32 Len,void *pContext);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: PPM5K_PCM_RECV_FROM_DOWN_CALLBACK
 *功能描述: 数据接收回调函数
 *输入描述: 设备句柄、数据缓冲区、缓冲区大小、超时时间(毫秒)、回调环境
 *输出描述: 实际数据、实际数据长度
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: 
 *全局声明: 无
 *特殊说明: TimeoutMS=PM5K_INFINITE表示无限阻塞，TimeoutMS=0表示不阻塞,超时成功返回长度0.
 ************************************************************************************************************************************************************************       
*/
typedef PM5K_BOOL (*PPM5K_PCM_RECV_FROM_DOWN_CALLBACK)(PM5K_PCM_HANDLE hDev,void *Buf,PM5K_U32 *pLen,PM5K_U32 TimeoutMS,void *pContext);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: PPM5K_PCM_LOG_CALLBACK
 *功能描述: 运行日志输出回调函数
 *输入描述: 日志信息文本串
 *输出描述: 无
 *返回描述: 无
 *作者日期: 
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
typedef void (*PPM5K_PCM_LOG_CALLBACK)(const char *strLogMsg);




typedef struct _PM5K_PCM_DEV_PROPERTY_VAL
{
	PM5K_U32	ValType;
	union
	{
		PM5K_U8									DataBuf[128];
		PM5K_F32								DataFloat;
		PM5K_U8									DataByte;
	}Val;
}PM5K_PCM_DEV_PROPERTY_VAL,*PPM5K_PCM_DEV_PROPERTY_VAL;


typedef struct _PM5K_PCM_DEV_WORK_PARAM_DEF
{
	PM5K_U32		PollTimerMS;			/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;			/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];			/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
	PM5K_BOOL		IsEnableSpecalOption;	/*设备特殊参数使能标记*/
	PM5K_U8			strDevSpecalOption[48];	/*设备特殊参数,格式为空字符结束的标准C语言字符串,最大47个有效字符,建议格式模板为：VarName=Val;VarName=Val;...    */
}PM5K_PCM_DEV_WORK_PARAM_DEF,*PPM5K_PCM_DEV_WORK_PARAM_DEF;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_HT
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
	PM5K_U32		DLT645WakeUpTimes;	/*645协议发送唤醒字节个数*/
	PM5K_F32		Rate;				/*电表倍比*/
}PM5K_PCM_DEV_WORK_PARAM_HT,*PPM5K_PCM_DEV_WORK_PARAM_HT;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_LFP4850
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
	PM5K_U32		PacketNode;			/*Packet序号*/
}PM5K_PCM_DEV_WORK_PARAM_LFP4850,*PPM5K_PCM_DEV_WORK_PARAM_LFP4850;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_DLT645EM
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
	PM5K_U32		DLT645WakeUpTimes;	/*645协议发送唤醒字节个数*/
	PM5K_BOOL		IsP2PConnect;		/*是否为点对点连接，如果使能该项会自动获取电表地址*/
	PM5K_BOOL		IsAPS;				/*是否按标准645地址转换，如果非标，则直接将255以内的地址HEX放入A0*/
	PM5K_U8			UserID[4];			/*用户名*/
	PM5K_U8			Password[3];		/*密码*/
}PM5K_PCM_DEV_WORK_PARAM_DLT645EM,*PPM5K_PCM_DEV_WORK_PARAM_DLT645EM;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_WEIBO_J05
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
    PM5K_U32		maxU;               /*电压量程最大值 */
    PM5K_U32		maxI;               /*电流量程最大值 */
}PM5K_PCM_DEV_WORK_PARAM_WEIBO_J05,*PPM5K_PCM_DEV_WORK_PARAM_WEIBO_J05;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_YADA_20XX
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
    PM5K_U16		PT;
    PM5K_U16		CT; 
}PM5K_PCM_DEV_WORK_PARAM_YADA_20XX,*PPM5K_PCM_DEV_WORK_PARAM_YADA_20XX;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_SOCOMEC
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
    PM5K_U32		CT;
    PM5K_U32		VT; 
}PM5K_PCM_DEV_WORK_PARAM_SOCOMEC,*PPM5K_PCM_DEV_WORK_PARAM_SOCOMEC;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_SICONUPS
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
    PM5K_F32		CurrRate;
}PM5K_PCM_DEV_WORK_PARAM_SICONUPS,*PPM5K_PCM_DEV_WORK_PARAM_SICONUPS;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_SC200
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
    PM5K_U32		ModNum;
}PM5K_PCM_DEV_WORK_PARAM_SC200,*PPM5K_PCM_DEV_WORK_PARAM_SC200;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_HYK
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
    PM5K_U32		Type;
}PM5K_PCM_DEV_WORK_PARAM_HYK,*PPM5K_PCM_DEV_WORK_PARAM_HYK;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_WONTEX
{
	PM5K_U32		PollTimerMS;		/*设备所有数据采集一遍的时间间隔*/
	PM5K_U32		PollTimeoutMS;		/*设备单条命令响应超时时间*/
	PM5K_U8			strDevAddr[32];		/*设备下行协议地址,格式为空字符结束的标准十进制C语言字符串，最大31个有效字符*/
    PM5K_U32		NodeID;
}PM5K_PCM_DEV_WORK_PARAM_WONTEX,*PPM5K_PCM_DEV_WORK_PARAM_WONTEX;


typedef struct _PM5K_PCM_DEV_WORK_PARAM
{
	PM5K_U32	ParamType;
	union
	{
		PM5K_U8									ParamBuf[128];
		PM5K_PCM_DEV_WORK_PARAM_DEF				ParamDefault;
		PM5K_PCM_DEV_WORK_PARAM_HT				ParamHT;		/*特殊参数范例：WakeUpTimes=0;Rate=1;*/
		PM5K_PCM_DEV_WORK_PARAM_LFP4850			ParamLFP4850;	/*特殊参数范例：PacketNode=1;*/
		PM5K_PCM_DEV_WORK_PARAM_WEIBO_J05		ParamWEIBO_J05;	/*特殊参数范例：maxU=380;maxI=200;*/
		PM5K_PCM_DEV_WORK_PARAM_DLT645EM		ParamDLT645EM;	/*特殊参数范例：WT=0;P2P=0;APS=1;U=00000000;P=000000;*/
		PM5K_PCM_DEV_WORK_PARAM_YADA_20XX		ParamYADA_20XX; /*特殊参数范例：PT=1;CT=1*/
		PM5K_PCM_DEV_WORK_PARAM_SOCOMEC			ParamSOCOMEC;	/*特殊参数范例：CT=1;VT=1*/
		PM5K_PCM_DEV_WORK_PARAM_SICONUPS		ParamSICONUPS;	/*特殊参数范例：CurRate=0.95;*/
		PM5K_PCM_DEV_WORK_PARAM_SC200			ParamSC200;		/*特殊参数范例：ModNum=15;*/
		PM5K_PCM_DEV_WORK_PARAM_HYK				ParamHYK;		/*特殊参数范例：Type=12;*/
		PM5K_PCM_DEV_WORK_PARAM_WONTEX			ParamWONTEX;	/*特殊参数范例：NodeID=0;*/
																/*SM50EX特殊参数范例：ModAddr=FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF*/
	}Param;																						
}PM5K_PCM_DEV_WORK_PARAM,*PPM5K_PCM_DEV_WORK_PARAM;




/*
 ************************************************************************************************************************************************************************
 * 函数原型声明
 ************************************************************************************************************************************************************************
*/

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_GetVer
 *功能描述: 获取协议转换库版本
 *输入描述: 无
 *输出描述: 无
 *返回描述: 模块当前版本号
 *作者日期: ZCQ/2012/01/11
 *全局声明: 无
 *特殊说明: 模块版本号16进制格式输出如下形式：abccddee ,其中，a表示主版号，b表示子版号，cc表示年，dd表示月，ee表示日
 ************************************************************************************************************************************************************************       
*/
extern PM5K_U32 Pm5k_Pcm_GetVer(void);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_Init
 *功能描述: 协议转换库初始化
 *输入描述: 可选输入日志输出回调函数，若为NULL则关闭日志输出
 *输出描述: 无
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/01/11
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 该接口用于分配模块需要的系统资源;重复初始化返回成功。
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Init(PPM5K_PCM_LOG_CALLBACK pLogCallback);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_Uninit
 *功能描述: 协议转换库反初始化
 *输入描述: 无
 *输出描述: 无
 *返回描述: 无
 *作者日期: ZCQ/2012/01/12
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 该接口用于释放模块已经分配的系统资源
 ************************************************************************************************************************************************************************       
*/
extern void Pm5k_Pcm_Uninit(void);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_OpenDev
 *功能描述: 初始化设备运行实例
 *输入描述: 设备类型、设备共享端口标识、下行命令发送回调函数及其回调环境、下行命令响应接收回调函数及其回调环境
 *输出描述: 无
 *返回描述: 成功返回设备运行实例句柄，失败返回PM5K_PCM_INVALID_HANDLE
 *作者日期: ZCQ/2012/01/13
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明:	设备共享端口标识表示本设备与其它设备共享使用的端口号，若设备共享端口标识为PM5K_PCM_INVALID_SHARE_PORT_ID则表示独占下行通讯端口。
 ************************************************************************************************************************************************************************       
*/
extern PM5K_PCM_HANDLE Pm5k_Pcm_OpenDev(PM5K_U32 DevType,PM5K_U32 DevSharePortID,PPM5K_PCM_SEND_TO_DOWN_CALLBACK pSendCallBack,void *pSendCallBackContext,PPM5K_PCM_RECV_FROM_DOWN_CALLBACK pRecvCallBack,void *pRecvCallBackContext);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_CloseDev
 *功能描述: 关闭销毁设备运行实例
 *输入描述: 设备运行实例句柄
 *输出描述: 无
 *返回描述: 无
 *作者日期: ZCQ/2012/01/13
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern void Pm5k_Pcm_CloseDev(PM5K_PCM_HANDLE hDev);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_GetDevVer
 *功能描述: 获取设备子模块版本
 *输入描述: 设备运行实例句柄、设备子模块版本指针
 *输出描述: 设备子模块版本
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/01/16
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 模块版本号16进制格式输出如下形式：abccddee ,其中，a表示主版号，b表示子版号，cc表示年，dd表示月，ee表示日
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_GetDevVer(PM5K_PCM_HANDLE hDev,PM5K_U32 *pDevVer);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_GetDevRealTimeData
 *功能描述: 获取智能设备实时运行状态数据
 *输入描述: 设备运行实例句柄、数据接收缓冲区、缓冲区大小
 *输出描述: 实时运行状态数据、数据有效长度
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/01/16
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 若Buf==NULL则只成功输出数据有效长度;数据格式排列遵循亚奥电总协议关于智能设备实时数据的定义要求，但是不包含前导字节DATAFLAG且只支持浮点模拟量和整型多态量;若没有数据则成功输出数据有效长度0;
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_GetDevRealTimeData(PM5K_PCM_HANDLE hDev,PM5K_U8 *Buf,PM5K_U32 *pLen);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_GetDevConfigParam
 *功能描述: 获取智能设备当前配置参数
 *输入描述: 设备运行实例句柄、数据接收缓冲区、缓冲区大小
 *输出描述: 智能设备当前配置参数、数据有效长度
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/01/16
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 若Buf==NULL则只成功输出数据有效长度;数据格式排列遵循亚奥电总协议关于智能设备实时数据的定义要求，但是不包含前导字节DATAFLAG且只支持浮点模拟量和整型多态量;若没有数据则成功输出数据有效长度0;
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_GetDevConfigParam(PM5K_PCM_HANDLE hDev,PM5K_U8 *Buf,PM5K_U32 *pLen);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_SetDevPropertyVal
 *功能描述: 设置智能设备参数和控制智能设备行为动作
 *输入描述: 设备运行实例句柄、操作对象标识、操作参数
 *输出描述: 无
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/01/16
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 操作对象标识编码遵循亚奥电总协议定义，其具体物理意义依赖具体设备对象定义实现;操作参数遵循亚奥电总协议定义且只支持浮点模拟量和整型多态量;
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_SetDevPropertyVal(PM5K_PCM_HANDLE hDev,PM5K_U32 PropertyID,const PM5K_PCM_DEV_PROPERTY_VAL *pPropertyVal);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_SetDevWorkParam
 *功能描述: 设置设备数据采集访问工作参数
 *输入描述: 设备运行实例句柄、采集访问工作参数
 *输出描述: 无
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/01/16
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_SetDevWorkParam(PM5K_PCM_HANDLE hDev,const PM5K_PCM_DEV_WORK_PARAM *pWorkParam);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_Comm_GetSysTimeMS
 *功能描述: 获取系统运行时间
 *输入描述: 无
 *输出描述: 无
 *返回描述: 系统运行时间(毫秒)
 *作者日期: 
 *全局声明: 无
 *特殊说明: 提供系统参考时钟基准，分辨率取决与系统调度时钟频率
 ************************************************************************************************************************************************************************       
*/
extern PM5K_U64	Pm5k_Pcm_Comm_GetSysTimeMS(void);


/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_GetDevAuthenticatedAck
 *功能描述: 查询设备身份鉴定结果
 *输入描述: 设备运行实例句柄
 *输出描述: 无
 *返回描述: 未鉴定(0)/鉴定成功(1)/鉴定失败(2)
 *作者日期: ZCQ/2015/06/05
 *全局声明: sPm5kPcmServerMutex,spPm5kPcmServer
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern int Pm5k_Pcm_GetDevAuthenticatedAck(PM5K_PCM_HANDLE hDev);





/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_Gen_GetDevDataDesc
 *功能描述: 获取智能设备数据节点类型特征信息
 *输入描述: 设备运行实例句柄
 *输出描述: 智能设备数据节点类型特征信息
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/12/17
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 本接口返回指定智能设备实例的全部数据节点的描述信息，智能设备数据节点是能够被独立访问的智能设备有实际完整语义的最小逻辑访问单元。
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Gen_GetDevDataDesc(PM5K_PCM_HANDLE hDev,PPM5K_PCM_DATA_DESC pDevDataDesc);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_Gen_ReadDevReadOnlyData
 *功能描述: 读取智能设备若干连续编号的只读节点数据
 *输入描述: 设备运行实例句柄、希望读取开始节点编号、希望连续读取节点数目、输出缓冲区指针、输出缓冲区大小
 *输出描述: 字节对齐紧凑格式连续存储的只读节点数据值序列、节点数据输出总字节数
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/12/17
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 设备节点零基连续依次编号;若pBuf=NULL则仅仅输出节点数据输出总字节数。
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Gen_ReadDevReadOnlyData(PM5K_PCM_HANDLE hDev,PM5K_U32 StartNodeNo,PM5K_U32 NodeNum,void *pBuf,PM5K_U32 *pLen);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_Gen_ReadDevReadWriteData
 *功能描述: 读取智能设备若干连续编号的可读可写节点数据
 *输入描述: 设备运行实例句柄、希望读取开始节点编号、希望连续读取节点数目、输出缓冲区指针、输出缓冲区大小
 *输出描述: 字节对齐紧凑格式连续存储的可读可写节点数据值序列、节点数据输出总字节数
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/12/18
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 设备节点零基连续依次编号;若pBuf=NULL则仅仅输出节点数据输出总字节数。
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Gen_ReadDevReadWriteData(PM5K_PCM_HANDLE hDev,PM5K_U32 StartNodeNo,PM5K_U32 NodeNum,void *pBuf,PM5K_U32 *pLen);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: Pm5k_Pcm_Gen_WriteDevReadWriteData
 *功能描述: 写入更新智能设备若干连续编号的可读可写节点数据值
 *输入描述: 设备运行实例句柄、希望写入开始节点编号、希望连续写入节点数目、输入缓冲区指针、输入缓冲区大小
 *输出描述: 无
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2012/12/18
 *全局声明: sPm5kPcmServerMutex，spPm5kPcmServer
 *特殊说明: 设备节点零基连续依次编号；输入缓冲区内容为字节对齐紧凑格式连续存储的可读可写节点数据值序列。
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Gen_WriteDevReadWriteData(PM5K_PCM_HANDLE hDev,PM5K_U32 StartNodeNo,PM5K_U32 NodeNum,const void *pBuf,PM5K_U32 Len);






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
/*************************************************************Pm5kPcmApi.h 文件结束******************************************************************************************************/
#endif
