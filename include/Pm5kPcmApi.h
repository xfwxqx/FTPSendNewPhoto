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
 *			����ģ������
 *
 *			�ļ�:		Pm5kPcmApi.h
 *			�汾:		1.0
 *			����:		ZCQ
 *			����:		2011/12/15
 *
 *			�ǰ����뼼�����޹�˾��Ȩ���� 2011-2012
 *
 ************************************************************************************************************************************************************************
 ************************************************************************************************************************************************************************
*/




/*
 ************************************************************************************************************************************************************************
 * ����ģ�鹦������
 *
 *
 ************************************************************************************************************************************************************************
*/




/*
 ************************************************************************************************************************************************************************
 * �汾 1.0   2011/12/15
 * ��ʼ���汾 
 ************************************************************************************************************************************************************************
*/




/*
 ************************************************************************************************************************************************************************
 * �����ļ�
 ************************************************************************************************************************************************************************
*/

#include "Pm5kType.h"



/*
 ************************************************************************************************************************************************************************
 * ������궨��
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

/*���ﶨ�������豸���ͣ������������豸���������ļ��еĶ��屣��һ�£�����ÿ����һ�������豸֧�ֶ������ڴ������Ӧ�����Ͷ��壬������ʵ���ļ��ĺ���
* Pm5k_Pcm_GetDevInterface�������Ӧ�ĵ��ô��룬ͬʱ�����Ӧ��ͷ�ļ�����*/
#define PM5K_PCM_DEV_TYPE_UNKNOW							0
/*��Ĭ�����ص�ԴM500S*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_M500S						1
/*�д￪�ص�ԴCUC06*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_CUC06						2
/*�к㿪�ص�ԴSM60*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SM60						3
/*�����յ��ڶ���*/
#define PM5K_PCM_DEV_TYPE_KT_GL_V2							4
/*���Ŀյ�������*/
#define PM5K_PCM_DEV_TYPE_KT_MD_V3							5
/*��Ĭ����ԴPSM_A9*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_PSM_A9						6
/*�����յ���һ��*/
#define PM5K_PCM_DEV_TYPE_KT_GL_V1							7
/*�д￪�ص�ԴMCS6000*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_MCS6000						8
/*�д�UPS��ԴDELTAUPS*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_DELTAUPS					9
/*�º격�����Զ��غ�բAPS*/
#define PM5K_PCM_DEV_TYPE_QY_XHB_APS						10
/*��ͨ���HT ��Ҫ���ô��뻽���ֽ����ͱ���*/
#define PM5K_PCM_DEV_TYPE_DB_HT								11
/*ɽ��UPS��Դ*/
#define PM5K_PCM_DEV_TYPE_DY_SANTAK_UPS						12
/*�齭��ԴCU6300*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU6300						13
/*�к��ԴSC200���� 15ģ��*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SC200						14
/*�к��ԴSM4500C*/
#define	PM5K_PCM_DEV_TYPE_DY_ZH_SM4500C						15
/*�д�˹�׿˵�ԴMCS3000��վ*/
#define	PM5K_PCM_DEV_TYPE_DY_ZD_MCS3000JZ					16
/*�д�˹�׿˵�ԴMCS3000����*/
#define	PM5K_PCM_DEV_TYPE_DY_ZD_MCS3000JF					17
/*���ص�Դ��Ĭ��M810G��ֱ�� M810G����һ���˿ڣ�������Ϊģ��͵�϶ఴԭP2000ģ������ɽ�ֱ��������2���豸*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M810G_JZL					18
/*���ص�Դ��Ĭ��M810G����ģ��*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M810G_ZL					19
/*���¿յ�*/
#define PM5K_PCM_DEV_TYPE_KT_SX								20
/*�������յ�*/
#define PM5K_PCM_DEV_TYPE_KT_SLDJ							21
/*���Ŀյ�485*/
#define PM5K_PCM_DEV_TYPE_KT_MD_RS485						22
/*�����ؿյ�*/
#define PM5K_PCM_DEV_TYPE_KT_LBT							23
/*����ͼ�յ�*/
#define PM5K_PCM_DEV_TYPE_KT_JLT							24
/*�����յ�*/
#define	PM5K_PCM_DEV_TYPE_KT_CL								25
/*���Ŀյ�232*/
#define PM5K_PCM_DEV_TYPE_KT_MD_RS232						26
/*����յ�8006*/
#define PM5K_PCM_DEV_TYPE_KT_HL_8006						27
/*����˹�յ�LINK*/
#define PM5K_PCM_DEV_TYPE_KT_HLS_LINK						28
/*�����յ�*/
#define PM5K_PCM_DEV_TYPE_KT_HE								29
/*�������ͻ�ACCESS4000*/
#define PM5K_PCM_DEV_TYPE_YJ_WEX_ACCESS4000					30
/*�人���˵�ؼ���� ��Ҫ���ô���Packet���*/
#define PM5K_PCM_DEV_TYPE_QY_PX_LFP4850						31
/*�����ͻ�DEC550*/
#define PM5K_PCM_DEV_TYPE_YJ_KL_DEC550						32
/*�齭��ԴCU2000H*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU2000H						33
/*�齭��ԴCU2500*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU2500						35
/*�к�ֱ����DPZ97*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_DPZ97						36
/*��Ĭ�����ص�ԴM500S����*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_M500SJF					37
/*�������յ�*/
#define PM5K_PCM_DEV_TYPE_KT_AIRSYS							38
/*CITEC�Ǹ߿յ�*/
#define PM5K_PCM_DEV_TYPE_KT_DG								39
/*���յ�*/
#define PM5K_PCM_DEV_TYPE_KT_DJ								40
/*���ر����ͻ�V3*/
#define PM5K_PCM_DEV_TYPE_YJ_KTBL_V3						41
/*��Ĭ��485�յ�*/
#define PM5K_PCM_DEV_TYPE_KT_AMS_RS485						42
/*�������ÿյ�*/
#define PM5K_PCM_DEV_TYPE_KT_HE_SY							43
/*���ſյ�*/
#define PM5K_PCM_DEV_TYPE_KT_HX								44
/*��ͨ�ȹܿյ�*/
#define PM5K_PCM_DEV_TYPE_KT_HTRG							45
/*�в���װ�ܵ��ܼ��IMPU-01*/
#define PM5K_PCM_DEV_TYPE_QY_ZB_IMPU01						46
/*���������*/
#define PM5K_PCM_DEV_TYPE_QY_ZY								47
/*��Ĭ����ԴPSM_15*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_PSM_15						48
/*ͨ������Դ*/
#define PM5K_PCM_DEV_TYPE_DY_TLH_TBOQ						49
/*���˵�ԴZXDU68*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU68						50
/*�к��ԴE40*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_E40							51
/*��վ�����״��Դ*/
#define PM5K_PCM_DEV_TYPE_DY_YD								52
/*��վ�����״��Դ��*/
#define PM5K_PCM_DEV_TYPE_DY_YD_NEW							53
/*�ǰ����زɼ���BCM300*/
#define PM5K_PCM_DEV_TYPE_QY_YA_BCM300_48V					54
#define PM5K_PCM_DEV_TYPE_QY_YA_BCM300_24V_1				55
#define PM5K_PCM_DEV_TYPE_QY_YA_BCM300_24V_2				56
/*�ǰ����زɼ���BCM400*/
#define PM5K_PCM_DEV_TYPE_QY_YA_BCM400						57
/*�Ŵ���*/
#define PM5K_PCM_DEV_TYPE_DB_YADA_2010						58
#define PM5K_PCM_DEV_TYPE_DB_YADA_2018						59
#define PM5K_PCM_DEV_TYPE_DB_YADA_2040						60
#define PM5K_PCM_DEV_TYPE_DB_YADA_2060						61
#define	PM5K_PCM_DEV_TYPE_DB_YD_DTSD3366D					62
/*ά�����*/
#define	PM5K_PCM_DEV_TYPE_DB_WB_1867B35						63
#define	PM5K_PCM_DEV_TYPE_DB_WB_1876J05						64
/*��̩�ͻ���*/
#define	PM5K_PCM_DEV_TYPE_YJ_KT_KETAINEW					65
/*�������ͻ�ACCESS6000*/
#define PM5K_PCM_DEV_TYPE_YJ_WEX_ACCESS6000					66
/*ACR�����*/
#define PM5K_PCM_DEV_TYPE_DB_AKR_ACR						67
/*��Ĭ���ͻ��л���ASCO*/
#define PM5K_PCM_DEV_TYPE_YJ_AMS_ASCO						68
/*����Դ��Դ*/
#define	PM5K_PCM_DEV_TYPE_DY_DLY							69
/*��Ĭ������ϵ�ԴHIPLUSS_U*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_HIPLUSSU					70
/*��Ĭ��NXRϵ��UPS*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_NXR						71
/*��Ĭ��NXϵ��UPS*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_NX							72
/*���ܿյ�*/
#define PM5K_PCM_DEV_TYPE_KT_PENLIN							73
/*������UPS 9315 9390*/
#define PM5K_PCM_DEV_TYPE_DY_AKS_9315						74
#define PM5K_PCM_DEV_TYPE_DY_AKS_9390						75
/*UPS_SYSPOW*/
#define PM5K_PCM_DEV_TYPE_DY_SYSPOW_UPS						76
/*���ص�Դ��Ĭ��PSMA���� ��ֱ��*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_PSMA_R_JZL					77
/*���ص�Դ��Ĭ��PSMA���� ����ģ��20��*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_PSMA_R_ZL					78
/*�������ͻ�PW2.0*/
#define PM5K_PCM_DEV_TYPE_YJ_WEX_PW20						79
/*ʵ��UPS(sitepro)*/
#define PM5K_PCM_DEV_TYPE_DY_SD_SITEPRO						80
/*�к��ԴSM50*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SM50						81
/*�ǰ����زɼ���P5000_BCM300*/
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_48V				82
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_24V_1			83
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_24V_2			84
/*�к��ԴSM65����*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SM65						85
/*SOCOMEC�����*/
#define PM5K_PCM_DEV_TYPE_DB_SKM_SOCOMEC					86
/*����ϵ�Դ�ȿ�UPS*/
#define PM5K_PCM_DEV_TYPE_DY_SICON_UPS						87
/*÷������UPS*/
#define PM5K_PCM_DEV_TYPE_DY_MLRL_MGEUPS					88
/*�ǰ����زɼ���P5000_BCM300_V1.2 Lattice�滻��Ƭ��*/
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_V1_2_48V			89
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_V1_2_24V_1		90
#define PM5K_PCM_DEV_TYPE_QY_YA_P5K_BCM300_V1_2_24V_2		91
/*�к��ԴSC100*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SC100						92
/*�Ŵ��¶ȴ�����YD8000*/
#define PM5K_PCM_DEV_TYPE_QY_YD_YD8000						93
/*����ϵͳGST200*/
#define PM5K_PCM_DEV_TYPE_QY_XF_GST200						94
/*�ǰ����ݲɼ���RTM����*/
#define PM5K_PCM_DEV_TYPE_QY_YA_RTM300						95
/*����յ���һ��*/
#define PM5K_PCM_DEV_TYPE_KT_SY_SANYOV1						96
/*����յ��ڶ���*/
#define PM5K_PCM_DEV_TYPE_KT_SY_SANYOV2						97
/*��Ĭ���յ�DATAMATE3000ϵ��*/
#define PM5K_PCM_DEV_TYPE_KT_AMS_DATAMATE3000				98
/*����ɭ�ͻ�SAC2000ϵ��*/
#define PM5K_PCM_DEV_TYPE_YJ_XPS_SAC2000					99
/*�������յ�AL3000ϵ��*/
#define PM5K_PCM_DEV_TYPE_KT_AEX_AL3000						100
/*�������յ�Airsys99ϵ��*/
#define PM5K_PCM_DEV_TYPE_KT_AEX_AIRSYS99					101
/*�����յ�*/
#define PM5K_PCM_DEV_TYPE_KT_KELONG							102
/*����ͼ�յ�13ϵ��*/
#define PM5K_PCM_DEV_TYPE_KT_JLT_CANATAL13					103
/*����ͼ�յ�MEϵ��*/
#define PM5K_PCM_DEV_TYPE_KT_JLT_CANATALME					104
/*������UPS 9305*/
#define PM5K_PCM_DEV_TYPE_DY_AKS_9305						105
/*����ң����HYK*/
#define PM5K_PCM_DEV_TYPE_QY_HYK							106
/*�д￪�ص�ԴMCS6000����*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_MCS6000JF					107
/*����DK04C_V2*/
#define PM5K_PCM_DEV_TYPE_DY_PT_DK04CV2						108
/*����DND�����*/
#define PM5K_PCM_DEV_TYPE_DY_PT_PTDND						109
/*��̩Ѹ��ѹ��*/
#define PM5K_PCM_DEV_TYPE_DY_WTX_WONTEX						110
/*GE_UPS*/
#define PM5K_PCM_DEV_TYPE_DY_GEUPS							111
/*����ԭ������������*/
#define PM5K_PCM_DEV_TYPE_QY_XLY_RF							112
/*P5000B_BCM300*/
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO1_48V			113
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO1_24V_1		114
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO1_24V_2		115
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO2_48V			116
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO2_24V_1		117
#define PM5K_PCM_DEV_TYPE_QY_YA_P5KB_BCM300_NO2_24V_2		118
/*ӥ̶������������*/
#define PM5K_PCM_DEV_TYPE_QY_BDQN_JBF193					119
/*��Ĭ��������ԴM522S*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_M522SJF					120
/*���ڻ�Ϊ��ԴPSM-8*/
#define PM5K_PCM_DEV_TYPE_DY_HW_PSM_8						121
/*�������ԴJK1000ϵ��*/
#define PM5K_PCM_DEV_TYPE_DY_JHW_JK1000						122
/*�������ԴSC2000ϵ��*/
#define PM5K_PCM_DEV_TYPE_DY_JHW_SC2000						123
/*���˵�ԴZXDU300V3.0*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU300V30					124
/*�齭��ԴCU3000*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU3000						125
/*��Ĭ����ԴPSM-A 12ģ��*/
#define PM5K_PCM_DEV_TYPE_DY_AMS_PSM_A						126
/*���6300�ͻ�*/
#define PM5K_PCM_DEV_TYPE_YJ_FG_HGM6300						127
/*APCSilconUPS*/
#define PM5K_PCM_DEV_TYPE_DY_XK_APCUPS						128
/*C6000�յ�*/
#define PM5K_PCM_DEV_TYPE_KT_STS_C6000						129
/*C7000�յ�*/
#define PM5K_PCM_DEV_TYPE_KT_STS_C7000						130
/*UN�յ�mp3ϵ��*/
#define PM5K_PCM_DEV_TYPE_KT_UN_MP3							131
/*�д��ԴCU01�������İ�*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_CU01CH_JF					132
/*�д��ԴMCS6000�������Ƹ�*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_MCS6000_LYGJF				133
/*�д��ԴCU01����Ӣ�İ�*/
#define PM5K_PCM_DEV_TYPE_DY_ZD_CU01EN_JF					134
/*����ˮ��յ�*/
#define PM5K_PCM_DEV_TYPE_KT_TL_TRANE						135
/*��������PMAC201*/
#define PM5K_PCM_DEV_TYPE_DB_PMAC201						136
/*����˹�ͻ�*/
#define PM5K_PCM_DEV_TYPE_YJ_KMS							137
/*���ر����ͻ�V2*/
#define PM5K_PCM_DEV_TYPE_YJ_KTBL_V2						138
/*GriPower_UPS*/
#define PM5K_PCM_DEV_TYPE_DY_GRIPOWER_UPS					139
/*���ƶ�λ����������ATL600*/
#define PM5K_PCM_DEV_TYPE_QY_LK_ATL600						140
/*�Ŵ���ʪ�ȴ�����YD10HT*/
#define PM5K_PCM_DEV_TYPE_QY_YD_YD10HT						141
/*IMS_DTSϵ��UPS*/
#define PM5K_PCM_DEV_TYPE_DY_IMS_DTS						142
/*��Ĭ���յ�ACM03Uϵ��*/
#define PM5K_PCM_DEV_TYPE_KT_AMS_ACM03U						143
/*���������ʪ�ȴ�����DB506*/
#define PM5K_PCM_DEV_TYPE_QY_DLBF_CEKONGDB506				144
/*����AI2000���߹�*/
#define PM5K_PCM_DEV_TYPE_DB_DS_AI2000KUIXIAN				145
/*����AI2000���߹�*/
#define PM5K_PCM_DEV_TYPE_DB_DS_AI2000JINXIAN				146
/*����AI2000�����*/
#define PM5K_PCM_DEV_TYPE_DB_DS_AI2000LIANLUO				147
/*����AI2000�л���*/
#define PM5K_PCM_DEV_TYPE_DB_DS_AI2000QIEHUAN				148
/*��ͨ���2007*/
#define PM5K_PCM_DEV_TYPE_DB_HT_HT2007						149
/*���AB204UIϵ��*/
#define PM5K_PCM_DEV_TYPE_DB_AB204UI						150
/*̩̹��ԴTTX-I-Eϵ��*/
#define PM5K_PCM_DEV_TYPE_DY_TT_TTXIE						151
/*���ص�ԴCSU03B*/
#define PM5K_PCM_DEV_TYPE_DY_WT_CSU03B						152
/*��̵�ԴWZCK-21ϵ��*/
#define PM5K_PCM_DEV_TYPE_DY_XJ_WZCK21						153
/*�����ز���ϵ�Դ89ϵ��*/
#define PM5K_PCM_DEV_TYPE_DY_YST_EAST89						154
/*�к��ԴSM60����*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SM60JF						155
/*���˻�����ԴZXDU88��ֱ����*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU88_R_JZL				156
/*���˻�����ԴZXDU88������*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU88_R_ZL					157
/*�����յ�����*/
#define PM5K_PCM_DEV_TYPE_KT_HE_HRSI						158
/*����������*/
#define PM5K_PCM_DEV_TYPE_DKQ_HEIKEY						159
/*�����ͻ�KP310*/
#define PM5K_PCM_DEV_TYPE_YJ_KAIPU_KP610						260
/*�����ز���ϵ�ԴHIPLUSSϵ��*/
#define PM5K_PCM_DEV_TYPE_DY_LBT_HIPLUSS_UPS					261
/*���ص�Դ��Ĭ��PSMA�������� ��ֱ��*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_PSMA_RDUO_JZL			262
/*���ص�Դ��Ĭ��PSMA�������� ����*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_PSMA_RDUO_ZL					263
/*DJBϵ��UPS*/
#define PM5K_PCM_DEV_TYPE_DY_DJB_UPS								264
/*����ֱ����JK02Bϵ��*/
#define PM5K_PCM_DEV_TYPE_DY_HZ_JK02B								265
/*���ص�Դ����ZXDU3000���� ��ֱ��*/
#define	PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU3000_R_JZL					266 
/*���ص�Դ����ZXDU3000���� ����30ģ��*/
#define	PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU3000_R_ZL					267
/*ABB�����EM-Mϵ��*/
#define	PM5K_PCM_DEV_TYPE_DB_ABB_EM_M					268
/*ABB�����EM-100ϵ�е�����*/
#define	PM5K_PCM_DEV_TYPE_DB_ABB_EM_100_I					269
/*ABB�����EM-400ϵ��*/
#define	PM5K_PCM_DEV_TYPE_DB_ABB_EM_400					270
/*˫��﮵��*/
#define	PM5K_PCM_DEV_TYPE_QT_SDBAT					271
/*���˻�����ԴZXDU88��ֱ������*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU88_RDUO_JZL				272
/*���˻�����ԴZXDU88������30ģ��*/
#define PM5K_PCM_DEV_TYPE_DY_ZX_ZXDU88_RDUO_ZL					273
/*̭��﮵��*/
#define	PM5K_PCM_DEV_TYPE_QT_PNBAT					274
/*�е�/�ͻ��л���GU660A*/
#define	PM5K_PCM_DEV_TYPE_YJ_GU660A					275
/*ʩ�͵¸�ѹ��SPEAM_S40*/
#define	PM5K_PCM_DEV_TYPE_DB_SCHNEIDER_SPEAM_S40					276
/*ʩ�͵¸�ѹ��SPEAM_T20*/
#define	PM5K_PCM_DEV_TYPE_DB_SCHNEIDER_SPEAM_T20					277
/* Һλ��XST-1A */
#define	PM5K_PCM_DEV_TYPE_QT_XST_1A					278
/* ��Ѷ�����DMS96A */
#define	PM5K_PCM_DEV_TYPE_DB_DMS96A					279
/* ���׿��յ�K200 */
#define	PM5K_PCM_DEV_TYPE_KT_YMK_K200					280
/* �к��ѹֱ���������ֱ������ */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_ZHM07_JZL					181
/* �к��ѹֱ��������������� */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_ZHM07_ZL_5					182
/* ʩ�͵������PM5350 */
#define	PM5K_PCM_DEV_TYPE_DB_SCHNEIDER_PM5350					183
/* ˹�ƶ������PA194I-9K4G 7̨ */
#define	PM5K_PCM_DEV_TYPE_DB_SFERE_PA194I_9K4G					184
/* �д��ѹ����ϵͳֱ������ */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_HVP_JZL					185
/* �д��ѹ����ϵͳ�������� */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_HVP_ZL					186
/*�����״￪�ص�Դ��ֱ����*/
#define PM5K_PCM_DEV_TYPE_DY_YD_JZL						187
/*�����״￪�ص�Դ������*/
#define PM5K_PCM_DEV_TYPE_DY_YD_ZL						188
/*�����д￪�ص�Դ*/
#define PM5K_PCM_DEV_TYPE_DY_DELTA_CUC06_R						189
/*��������ϵ�Դ*/
#define PM5K_PCM_DEV_TYPE_DY_KELONG_UPS						190
/* ���������ԴBC650 */
#define PM5K_PCM_DEV_TYPE_DY_ZHONGLING_BC650						191
/* �к������ԴSM50��ֱ������_ ���� */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_SM50_JZL_JS				192
/* �к������ԴSM50��������_���� */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_SM50_ZL_JS				193
/* �к㽻����DPJ93 */
#define	PM5K_PCM_DEV_TYPE_DY_ZH_DPJ93							194
/* �������ܿյ� */
#define	PM5K_PCM_DEV_TYPE_KT_CHUANGKE							195
/* ���ֱ��RD200A */
#define	PM5K_PCM_DEV_TYPE_DY_RD200A									196
/* ׿������AB-CD194UI_2S4 */											
#define	PM5K_PCM_DEV_TYPE_DB_ZL_CD194UI_2S4				197
/* EAST800����ϵ�Դ */
#define	PM5K_PCM_DEV_TYPE_DY_EAST800							198
/* �к�ZHM04������ */
#define PM5K_PCM_DEV_TYPE_DY_ZH_ZHM04_AC					199
/* �д�DPS6000ֱ������ϵͳ��ֱ������ */							
#define PM5K_PCM_DEV_TYPE_DY_DELTA_DPS6000_JZL	200
/* �д�DPS6000ֱ������ϵͳ�������� */
#define PM5K_PCM_DEV_TYPE_DY_DELTA_DPS6000_ZL		201
/* �д������ԴCUC-01HE��ֱ������ */
#define PM5K_PCM_DEV_TYPE_DY_DELTA_CUC_01HE_JZL		202
/* �д������ԴCUC-01HE�������� */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_CUC_01HE_ZL		203
/* �人�޼ʵ�ԴDK04C_V1 */
#define	PM5K_PCM_DEV_TYPE_DY_ZHOUJI_DK04C_V1			204
/* �ͻ�������HGM6100ϵ�� */
#define	PM5K_PCM_DEV_TYPE_YJ_HGM6100							205
/* �ܴ��ԴCUC-01HE */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_CUC_01HE				206
/* ����Դ */
#define	PM5K_PCM_DEV_TYPE_DY_FENGHUO							207
/* ɽӥ���� */
#define	PM5K_PCM_DEV_TYPE_XF_SHANYING							208
/* ����������JMDM-COMTTG */
#define	PM5K_PCM_DEV_TYPE_QT_JMDM_COMTTG					209
/* ˹�ƶ������PD194E-9S4G */
#define	PM5K_PCM_DEV_TYPE_DB_PD194E_9S4G					210
/* ��ŵ�๦�ܵ��3�� */
#define	PM5K_PCM_DEV_TYPE_DB_HENGHUO_3PHASE					211
/* �ൺ��˹��ֱ����PMU-S10 */
#define	PM5K_PCM_DEV_TYPE_DB_PMU_S10_MODEBUS					212
/* ���Բ��߱���װ��PDS-751ϵ�� */
#define PM5K_PCM_DEV_TYPE_DY_PDS751						213
/* LD��ѹ���¿��� */										
#define	PM5K_PCM_DEV_TYPE_QT_LD								214
/* TTC-310ϵ���¿��� */
#define	PM5K_PCM_DEV_TYPE_QT_TTC310						215
/* �����PMW2000 */
#define	PM5K_PCM_DEV_TYPE_QT_PMW2000					216	
/* ����̱�RCS9611CS�������װ�� */							
#define	PM5K_PCM_DEV_TYPE_QT_NR_RCS9611CS			217
/* ��ŵ�๦�ܵ���� */
#define	PM5K_PCM_DEV_TYPE_DB_HENGHUO_1PHASE					218
/* �����PMW2000H */
#define	PM5K_PCM_DEV_TYPE_DB_PMW2000H					219
/* ����SF6���ϵͳHDJK-6000 */
#define	PM5K_PCM_DEV_TYPE_QT_HDJK6000					220
/* ��ǿ﮵�ؼ���� */
#define	PM5K_PCM_DEV_TYPE_QT_BQBAT					221
/* ������SPSD̫���� */
#define	PM5K_PCM_DEV_TYPE_QT_SPSD					222
/* �����յ�����V3.0 */
#define	PM5K_PCM_DEV_TYPE_KT_KELONGV30					223
/* ����̱�RCS9651CS�������װ�� */
#define	PM5K_PCM_DEV_TYPE_QT_NR_RCS9651CS					224
/* ��Ĭ��������ԴM810G��ֱ������3ֱ���� */
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M810G3DC_JZL					225
/* ��Ĭ��������ԴM810G����30ģ�� */
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M810G3DC_ZL30					226
/* ����Ѹ��Դ */
#define	PM5K_PCM_DEV_TYPE_DY_AOTEXUN					227
/* ����ԴRM2003ϵ�� */
#define	PM5K_PCM_DEV_TYPE_DY_JD_RM2003					228
/* ����ϵ�ԴKSTARϵ�� */
#define	PM5K_PCM_DEV_TYPE_DY_KSTAR_UPS					229
/* ��̩���Դ����ϵ�� */
#define	PM5K_PCM_DEV_TYPE_DY_TAIDADZ					230
/* ̩���Դ */
#define	PM5K_PCM_DEV_TYPE_DY_TAIDA					231
/* ɽ�ز���ϵ�Դ3A3ϵ�� */
#define	PM5K_PCM_DEV_TYPE_DY_SANTAK3A3					232
/* �϶�﮵�� */
#define	PM5K_PCM_DEV_TYPE_QT_NANDU					233
/* ���˵�ԴZXDU68_T601 */
#define PM5K_PCM_DEV_TYPE_DY_ZXDU_T601			234
/* ����AI2000������ */
#define PM5K_PCM_DEV_TYPE_DB_AI2000BUCHANG			235
/* �๦�ܵ����Ǳ� */
#define PM5K_PCM_DEV_TYPE_DB_DUODB			236
/* ���������ɼ�ģ�� */
#define PM5K_PCM_DEV_TYPE_DB_BOERMODULE			237
/* �ݸ��������A38ϵ�� */
#define PM5K_PCM_DEV_TYPE_DB_SOCOMEC_A38		238
/* �ݸ��������A20ϵ�� */
#define PM5K_PCM_DEV_TYPE_DB_SOCOMEC_A20		239
/* ����������ϵͳMCGSϵ�� */
#define	PM5K_PCM_DEV_TYPE_DB_MCGS						240
/* ��Ϊ��ԴV300ϵ�н�ֱ�� */
#define	PM5K_PCM_DEV_TYPE_DY_HW_V300_JZL						241
/* ��Ϊ��ԴV300ϵ��20ģ�� */
#define	PM5K_PCM_DEV_TYPE_DY_HW_V300_ZL						242
/* ���콻��DPJ-G5ͨ��Э��������ֺ�(˫·) */
#define	PM5K_PCM_DEV_TYPE_DB_DPJ_G5_DOUBLE		243
/* LD128Eϵ������ */
#define	PM5K_PCM_DEV_TYPE_QT_LD128E		244
/* ����ɭ�ͻ�SAC7000ϵ�� */
#define	PM5K_PCM_DEV_TYPE_YJ_XPS_SAC7000		245
/* BCM310�������� */
#define	PM5K_PCM_DEV_TYPE_QT_YAAO_BCMCESHI		246
/* GPS��λϵͳ */
#define	PM5K_PCM_DEV_TYPE_QT_GPS		247
/* �Ŵ����������� */
#define	PM5K_PCM_DEV_TYPE_DB_YD_DTSD3366DCESHI					249
/* ��ͨ�Ƽ������Ž� */
#define	PM5K_PCM_DEV_TYPE_MJ_CHUANTONG					250
/* ���ܵ��PMAC720ϵ�� */
#define	PM5K_PCM_DEV_TYPE_BOER_PMAC720					251
/* ������ACR�����0907ϵ�� */
#define	PM5K_PCM_DEV_TYPE_ACR0907					252
/* ����ͻ�PCC2100ϵ�� */
#define	PM5K_PCM_DEV_TYPE_PCC2100					253
/* Ϋ���ͻ�H2 */
#define	PM5K_PCM_DEV_TYPE_YJ_WEICHAIH2					255

/* ���콻����������(��·) */
#define	PM5K_PCM_DEV_TYPE_HAIHONG_SINGLE		360
/* ��Ĭ����ѹֱ����ԴHVDC_M822E ��ֱ������ (��ֱ������������һ�����пڣ����϶�Ӧ������ַ)*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M822E_JZL					256
/* ��Ĭ����ѹֱ����ԴHVDC_M822E ��������*/
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M822E_ZL					257
/* �����ͻ� GU3311*/
#define	PM5K_PCM_DEV_TYPE_YJ_KAIPU_GU3311					258
/* �д��ԴCUC-06 12ģ��*/
#define	PM5K_PCM_DEV_TYPE_DY_ZD_CUC06_12MODEL					259
/* ��Ĭ����ԴM522S_���� */
#define	PM5K_PCM_DEV_TYPE_DY_AMS_M522S_TT					160
/* ����Դ��Դ_���� */
#define	PM5K_PCM_DEV_TYPE_DY_DLY_TT					161
/* ��Ϊ��ԴSMU06C_���� */
#define	PM5K_PCM_DEV_TYPE_DY_HW_SMU06C_TT		162
/* �д��ԴCUC06_���� */
#define	PM5K_PCM_DEV_TYPE_DY_DELTA_CUC06CESHI		163
/*�к��ԴSC100_����*/
#define PM5K_PCM_DEV_TYPE_DY_ZH_SC100_TT						164
/*�齭��ԴCU3000C_����*/
#define PM5K_PCM_DEV_TYPE_DY_ZJ_CU3000C_TT						165
/* ���˵�ԴZXDU68_T601_���� */
#define PM5K_PCM_DEV_TYPE_DY_ZXDU_T601_TT			166
/* TCL�յ�_���� */
#define PM5K_PCM_DEV_TYPE_KT_TCL_TT							167
/* �����յ��ڶ���_���� */
#define PM5K_PCM_DEV_TYPE_KT_GL_V2_TT			168
/* �����յ�����V3.0���� */
#define	PM5K_PCM_DEV_TYPE_KT_KELONGV30_TT					169
/* ���Ŀյ�������_���� */
#define PM5K_PCM_DEV_TYPE_KT_MD_V3_TT							170
/* ��������_���� */
#define PM5K_PCM_DEV_TYPE_DB_AKR_ACR_TT							171
/* �Ŵ���2080_���� */
#define PM5K_PCM_DEV_TYPE_DB_YADA2080_TT							172
/* ����AMCT050_���� */
#define PM5K_PCM_DEV_TYPE_DB_SL_AMCT050_TT							173
/* �������DMSD40_���� */
#define PM5K_PCM_DEV_TYPE_DB_LC_DMSD40_TT							174
/* �����¿�_���� */
#define PM5K_PCM_DEV_TYPE_KT_HT_HAYDEN_TT							175
/* �����¿�_���� */
#define PM5K_PCM_DEV_TYPE_KT_HR_TT							176
/* Ӣά���¿�_���� */
#define PM5K_PCM_DEV_TYPE_KT_EX_TT							177
/* �������Ž�BASS260_���� */
#define PM5K_PCM_DEV_TYPE_MJ_GXX_BASS260_TT							178
/* �����Ž�ACUC_���� */
#define PM5K_PCM_DEV_TYPE_MJ_ZXDU_ACUC_TT							179




/*
 ************************************************************************************************************************************************************************
 * �������Ͷ���
 ************************************************************************************************************************************************************************
*/

typedef void * PM5K_PCM_HANDLE;

/*
 ************************************************************************************************************************************************************************     
 *��������: PPM5K_PCM_SEND_TO_DOWN_CALLBACK
 *��������: ���ݷ��ͻص�����
 *��������: �豸��������ݻ����������ݳ��ȡ��ص�����
 *�������: ��
 *��������: ��
 *��������: 
 *ȫ������: ��
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
typedef void (*PPM5K_PCM_SEND_TO_DOWN_CALLBACK)(PM5K_PCM_HANDLE hDev,const void *Buf,PM5K_U32 Len,void *pContext);

/*
 ************************************************************************************************************************************************************************     
 *��������: PPM5K_PCM_RECV_FROM_DOWN_CALLBACK
 *��������: ���ݽ��ջص�����
 *��������: �豸��������ݻ���������������С����ʱʱ��(����)���ص�����
 *�������: ʵ�����ݡ�ʵ�����ݳ���
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: 
 *ȫ������: ��
 *����˵��: TimeoutMS=PM5K_INFINITE��ʾ����������TimeoutMS=0��ʾ������,��ʱ�ɹ����س���0.
 ************************************************************************************************************************************************************************       
*/
typedef PM5K_BOOL (*PPM5K_PCM_RECV_FROM_DOWN_CALLBACK)(PM5K_PCM_HANDLE hDev,void *Buf,PM5K_U32 *pLen,PM5K_U32 TimeoutMS,void *pContext);

/*
 ************************************************************************************************************************************************************************     
 *��������: PPM5K_PCM_LOG_CALLBACK
 *��������: ������־����ص�����
 *��������: ��־��Ϣ�ı���
 *�������: ��
 *��������: ��
 *��������: 
 *ȫ������: ��
 *����˵��: ��
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
	PM5K_U32		PollTimerMS;			/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;			/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];			/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
	PM5K_BOOL		IsEnableSpecalOption;	/*�豸�������ʹ�ܱ��*/
	PM5K_U8			strDevSpecalOption[48];	/*�豸�������,��ʽΪ���ַ������ı�׼C�����ַ���,���47����Ч�ַ�,�����ʽģ��Ϊ��VarName=Val;VarName=Val;...    */
}PM5K_PCM_DEV_WORK_PARAM_DEF,*PPM5K_PCM_DEV_WORK_PARAM_DEF;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_HT
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
	PM5K_U32		DLT645WakeUpTimes;	/*645Э�鷢�ͻ����ֽڸ���*/
	PM5K_F32		Rate;				/*�����*/
}PM5K_PCM_DEV_WORK_PARAM_HT,*PPM5K_PCM_DEV_WORK_PARAM_HT;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_LFP4850
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
	PM5K_U32		PacketNode;			/*Packet���*/
}PM5K_PCM_DEV_WORK_PARAM_LFP4850,*PPM5K_PCM_DEV_WORK_PARAM_LFP4850;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_DLT645EM
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
	PM5K_U32		DLT645WakeUpTimes;	/*645Э�鷢�ͻ����ֽڸ���*/
	PM5K_BOOL		IsP2PConnect;		/*�Ƿ�Ϊ��Ե����ӣ����ʹ�ܸ�����Զ���ȡ����ַ*/
	PM5K_BOOL		IsAPS;				/*�Ƿ񰴱�׼645��ַת��������Ǳ꣬��ֱ�ӽ�255���ڵĵ�ַHEX����A0*/
	PM5K_U8			UserID[4];			/*�û���*/
	PM5K_U8			Password[3];		/*����*/
}PM5K_PCM_DEV_WORK_PARAM_DLT645EM,*PPM5K_PCM_DEV_WORK_PARAM_DLT645EM;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_WEIBO_J05
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
    PM5K_U32		maxU;               /*��ѹ�������ֵ */
    PM5K_U32		maxI;               /*�����������ֵ */
}PM5K_PCM_DEV_WORK_PARAM_WEIBO_J05,*PPM5K_PCM_DEV_WORK_PARAM_WEIBO_J05;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_YADA_20XX
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
    PM5K_U16		PT;
    PM5K_U16		CT; 
}PM5K_PCM_DEV_WORK_PARAM_YADA_20XX,*PPM5K_PCM_DEV_WORK_PARAM_YADA_20XX;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_SOCOMEC
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
    PM5K_U32		CT;
    PM5K_U32		VT; 
}PM5K_PCM_DEV_WORK_PARAM_SOCOMEC,*PPM5K_PCM_DEV_WORK_PARAM_SOCOMEC;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_SICONUPS
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
    PM5K_F32		CurrRate;
}PM5K_PCM_DEV_WORK_PARAM_SICONUPS,*PPM5K_PCM_DEV_WORK_PARAM_SICONUPS;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_SC200
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
    PM5K_U32		ModNum;
}PM5K_PCM_DEV_WORK_PARAM_SC200,*PPM5K_PCM_DEV_WORK_PARAM_SC200;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_HYK
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
    PM5K_U32		Type;
}PM5K_PCM_DEV_WORK_PARAM_HYK,*PPM5K_PCM_DEV_WORK_PARAM_HYK;
typedef struct _PM5K_PCM_DEV_WORK_PARAM_WONTEX
{
	PM5K_U32		PollTimerMS;		/*�豸�������ݲɼ�һ���ʱ����*/
	PM5K_U32		PollTimeoutMS;		/*�豸����������Ӧ��ʱʱ��*/
	PM5K_U8			strDevAddr[32];		/*�豸����Э���ַ,��ʽΪ���ַ������ı�׼ʮ����C�����ַ��������31����Ч�ַ�*/
    PM5K_U32		NodeID;
}PM5K_PCM_DEV_WORK_PARAM_WONTEX,*PPM5K_PCM_DEV_WORK_PARAM_WONTEX;


typedef struct _PM5K_PCM_DEV_WORK_PARAM
{
	PM5K_U32	ParamType;
	union
	{
		PM5K_U8									ParamBuf[128];
		PM5K_PCM_DEV_WORK_PARAM_DEF				ParamDefault;
		PM5K_PCM_DEV_WORK_PARAM_HT				ParamHT;		/*�������������WakeUpTimes=0;Rate=1;*/
		PM5K_PCM_DEV_WORK_PARAM_LFP4850			ParamLFP4850;	/*�������������PacketNode=1;*/
		PM5K_PCM_DEV_WORK_PARAM_WEIBO_J05		ParamWEIBO_J05;	/*�������������maxU=380;maxI=200;*/
		PM5K_PCM_DEV_WORK_PARAM_DLT645EM		ParamDLT645EM;	/*�������������WT=0;P2P=0;APS=1;U=00000000;P=000000;*/
		PM5K_PCM_DEV_WORK_PARAM_YADA_20XX		ParamYADA_20XX; /*�������������PT=1;CT=1*/
		PM5K_PCM_DEV_WORK_PARAM_SOCOMEC			ParamSOCOMEC;	/*�������������CT=1;VT=1*/
		PM5K_PCM_DEV_WORK_PARAM_SICONUPS		ParamSICONUPS;	/*�������������CurRate=0.95;*/
		PM5K_PCM_DEV_WORK_PARAM_SC200			ParamSC200;		/*�������������ModNum=15;*/
		PM5K_PCM_DEV_WORK_PARAM_HYK				ParamHYK;		/*�������������Type=12;*/
		PM5K_PCM_DEV_WORK_PARAM_WONTEX			ParamWONTEX;	/*�������������NodeID=0;*/
																/*SM50EX�������������ModAddr=FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF*/
	}Param;																						
}PM5K_PCM_DEV_WORK_PARAM,*PPM5K_PCM_DEV_WORK_PARAM;




/*
 ************************************************************************************************************************************************************************
 * ����ԭ������
 ************************************************************************************************************************************************************************
*/

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_GetVer
 *��������: ��ȡЭ��ת����汾
 *��������: ��
 *�������: ��
 *��������: ģ�鵱ǰ�汾��
 *��������: ZCQ/2012/01/11
 *ȫ������: ��
 *����˵��: ģ��汾��16���Ƹ�ʽ���������ʽ��abccddee ,���У�a��ʾ����ţ�b��ʾ�Ӱ�ţ�cc��ʾ�꣬dd��ʾ�£�ee��ʾ��
 ************************************************************************************************************************************************************************       
*/
extern PM5K_U32 Pm5k_Pcm_GetVer(void);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_Init
 *��������: Э��ת�����ʼ��
 *��������: ��ѡ������־����ص���������ΪNULL��ر���־���
 *�������: ��
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/01/11
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: �ýӿ����ڷ���ģ����Ҫ��ϵͳ��Դ;�ظ���ʼ�����سɹ���
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Init(PPM5K_PCM_LOG_CALLBACK pLogCallback);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_Uninit
 *��������: Э��ת���ⷴ��ʼ��
 *��������: ��
 *�������: ��
 *��������: ��
 *��������: ZCQ/2012/01/12
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: �ýӿ������ͷ�ģ���Ѿ������ϵͳ��Դ
 ************************************************************************************************************************************************************************       
*/
extern void Pm5k_Pcm_Uninit(void);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_OpenDev
 *��������: ��ʼ���豸����ʵ��
 *��������: �豸���͡��豸����˿ڱ�ʶ����������ͻص���������ص�����������������Ӧ���ջص���������ص�����
 *�������: ��
 *��������: �ɹ������豸����ʵ�������ʧ�ܷ���PM5K_PCM_INVALID_HANDLE
 *��������: ZCQ/2012/01/13
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��:	�豸����˿ڱ�ʶ��ʾ���豸�������豸����ʹ�õĶ˿ںţ����豸����˿ڱ�ʶΪPM5K_PCM_INVALID_SHARE_PORT_ID���ʾ��ռ����ͨѶ�˿ڡ�
 ************************************************************************************************************************************************************************       
*/
extern PM5K_PCM_HANDLE Pm5k_Pcm_OpenDev(PM5K_U32 DevType,PM5K_U32 DevSharePortID,PPM5K_PCM_SEND_TO_DOWN_CALLBACK pSendCallBack,void *pSendCallBackContext,PPM5K_PCM_RECV_FROM_DOWN_CALLBACK pRecvCallBack,void *pRecvCallBackContext);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_CloseDev
 *��������: �ر������豸����ʵ��
 *��������: �豸����ʵ�����
 *�������: ��
 *��������: ��
 *��������: ZCQ/2012/01/13
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern void Pm5k_Pcm_CloseDev(PM5K_PCM_HANDLE hDev);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_GetDevVer
 *��������: ��ȡ�豸��ģ��汾
 *��������: �豸����ʵ��������豸��ģ��汾ָ��
 *�������: �豸��ģ��汾
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/01/16
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: ģ��汾��16���Ƹ�ʽ���������ʽ��abccddee ,���У�a��ʾ����ţ�b��ʾ�Ӱ�ţ�cc��ʾ�꣬dd��ʾ�£�ee��ʾ��
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_GetDevVer(PM5K_PCM_HANDLE hDev,PM5K_U32 *pDevVer);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_GetDevRealTimeData
 *��������: ��ȡ�����豸ʵʱ����״̬����
 *��������: �豸����ʵ����������ݽ��ջ���������������С
 *�������: ʵʱ����״̬���ݡ�������Ч����
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/01/16
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: ��Buf==NULL��ֻ�ɹ����������Ч����;���ݸ�ʽ������ѭ�ǰµ���Э����������豸ʵʱ���ݵĶ���Ҫ�󣬵��ǲ�����ǰ���ֽ�DATAFLAG��ֻ֧�ָ���ģ���������Ͷ�̬��;��û��������ɹ����������Ч����0;
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_GetDevRealTimeData(PM5K_PCM_HANDLE hDev,PM5K_U8 *Buf,PM5K_U32 *pLen);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_GetDevConfigParam
 *��������: ��ȡ�����豸��ǰ���ò���
 *��������: �豸����ʵ����������ݽ��ջ���������������С
 *�������: �����豸��ǰ���ò�����������Ч����
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/01/16
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: ��Buf==NULL��ֻ�ɹ����������Ч����;���ݸ�ʽ������ѭ�ǰµ���Э����������豸ʵʱ���ݵĶ���Ҫ�󣬵��ǲ�����ǰ���ֽ�DATAFLAG��ֻ֧�ָ���ģ���������Ͷ�̬��;��û��������ɹ����������Ч����0;
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_GetDevConfigParam(PM5K_PCM_HANDLE hDev,PM5K_U8 *Buf,PM5K_U32 *pLen);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_SetDevPropertyVal
 *��������: ���������豸�����Ϳ��������豸��Ϊ����
 *��������: �豸����ʵ����������������ʶ����������
 *�������: ��
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/01/16
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: ���������ʶ������ѭ�ǰµ���Э�鶨�壬����������������������豸������ʵ��;����������ѭ�ǰµ���Э�鶨����ֻ֧�ָ���ģ���������Ͷ�̬��;
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_SetDevPropertyVal(PM5K_PCM_HANDLE hDev,PM5K_U32 PropertyID,const PM5K_PCM_DEV_PROPERTY_VAL *pPropertyVal);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_SetDevWorkParam
 *��������: �����豸���ݲɼ����ʹ�������
 *��������: �豸����ʵ��������ɼ����ʹ�������
 *�������: ��
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/01/16
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_SetDevWorkParam(PM5K_PCM_HANDLE hDev,const PM5K_PCM_DEV_WORK_PARAM *pWorkParam);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_Comm_GetSysTimeMS
 *��������: ��ȡϵͳ����ʱ��
 *��������: ��
 *�������: ��
 *��������: ϵͳ����ʱ��(����)
 *��������: 
 *ȫ������: ��
 *����˵��: �ṩϵͳ�ο�ʱ�ӻ�׼���ֱ���ȡ����ϵͳ����ʱ��Ƶ��
 ************************************************************************************************************************************************************************       
*/
extern PM5K_U64	Pm5k_Pcm_Comm_GetSysTimeMS(void);


/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_GetDevAuthenticatedAck
 *��������: ��ѯ�豸��ݼ������
 *��������: �豸����ʵ�����
 *�������: ��
 *��������: δ����(0)/�����ɹ�(1)/����ʧ��(2)
 *��������: ZCQ/2015/06/05
 *ȫ������: sPm5kPcmServerMutex,spPm5kPcmServer
 *����˵��: ��
 ************************************************************************************************************************************************************************       
*/
extern int Pm5k_Pcm_GetDevAuthenticatedAck(PM5K_PCM_HANDLE hDev);





/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_Gen_GetDevDataDesc
 *��������: ��ȡ�����豸���ݽڵ�����������Ϣ
 *��������: �豸����ʵ�����
 *�������: �����豸���ݽڵ�����������Ϣ
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/12/17
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: ���ӿڷ���ָ�������豸ʵ����ȫ�����ݽڵ��������Ϣ�������豸���ݽڵ����ܹ����������ʵ������豸��ʵ�������������С�߼����ʵ�Ԫ��
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Gen_GetDevDataDesc(PM5K_PCM_HANDLE hDev,PPM5K_PCM_DATA_DESC pDevDataDesc);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_Gen_ReadDevReadOnlyData
 *��������: ��ȡ�����豸����������ŵ�ֻ���ڵ�����
 *��������: �豸����ʵ�������ϣ����ȡ��ʼ�ڵ��š�ϣ��������ȡ�ڵ���Ŀ�����������ָ�롢�����������С
 *�������: �ֽڶ�����ո�ʽ�����洢��ֻ���ڵ�����ֵ���С��ڵ�����������ֽ���
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/12/17
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: �豸�ڵ�����������α��;��pBuf=NULL���������ڵ�����������ֽ�����
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Gen_ReadDevReadOnlyData(PM5K_PCM_HANDLE hDev,PM5K_U32 StartNodeNo,PM5K_U32 NodeNum,void *pBuf,PM5K_U32 *pLen);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_Gen_ReadDevReadWriteData
 *��������: ��ȡ�����豸����������ŵĿɶ���д�ڵ�����
 *��������: �豸����ʵ�������ϣ����ȡ��ʼ�ڵ��š�ϣ��������ȡ�ڵ���Ŀ�����������ָ�롢�����������С
 *�������: �ֽڶ�����ո�ʽ�����洢�Ŀɶ���д�ڵ�����ֵ���С��ڵ�����������ֽ���
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/12/18
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: �豸�ڵ�����������α��;��pBuf=NULL���������ڵ�����������ֽ�����
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Gen_ReadDevReadWriteData(PM5K_PCM_HANDLE hDev,PM5K_U32 StartNodeNo,PM5K_U32 NodeNum,void *pBuf,PM5K_U32 *pLen);

/*
 ************************************************************************************************************************************************************************     
 *��������: Pm5k_Pcm_Gen_WriteDevReadWriteData
 *��������: д����������豸����������ŵĿɶ���д�ڵ�����ֵ
 *��������: �豸����ʵ�������ϣ��д�뿪ʼ�ڵ��š�ϣ������д��ڵ���Ŀ�����뻺����ָ�롢���뻺������С
 *�������: ��
 *��������: �ɹ�(TRUE)/ʧ��(FALSE)
 *��������: ZCQ/2012/12/18
 *ȫ������: sPm5kPcmServerMutex��spPm5kPcmServer
 *����˵��: �豸�ڵ�����������α�ţ����뻺��������Ϊ�ֽڶ�����ո�ʽ�����洢�Ŀɶ���д�ڵ�����ֵ���С�
 ************************************************************************************************************************************************************************       
*/
extern PM5K_BOOL Pm5k_Pcm_Gen_WriteDevReadWriteData(PM5K_PCM_HANDLE hDev,PM5K_U32 StartNodeNo,PM5K_U32 NodeNum,const void *pBuf,PM5K_U32 Len);






/*
 ************************************************************************************************************************************************************************     
 *��������:
 *��������:
 *��������:
 *�������:
 *��������:
 *��������:
 *ȫ������:
 *����˵��:
 ************************************************************************************************************************************************************************       
*/




/*
 ************************************************************************************************************************************************************************
 * ȫ�ֱ����������
 ************************************************************************************************************************************************************************
*/



#ifdef	__cplusplus
#if		__cplusplus
}
#endif
#endif
/*************************************************************Pm5kPcmApi.h �ļ�����******************************************************************************************************/
#endif
