#ifndef _YA_APP_PUBLIC_H_
#define _YA_APP_PUBLIC_H_

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
*			文件:		YaAppPublic.h
*			版本:		1.0
*			作者:		ZCQ
*			日期:		2013/01/23
*
*			亚奥数码技术有限公司版权所有 2006-2013
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
* 版本 1.0   2013/01/23
* 初始化版本 
************************************************************************************************************************************************************************
*/

/*
************************************************************************************************************************************************************************
* 引用文件
************************************************************************************************************************************************************************
*/


#include "Common.h"
#include "Pm5kType.h"


/*
************************************************************************************************************************************************************************
* 常数与宏定义
************************************************************************************************************************************************************************
*/


#define BLOWFISH_WORK_MODE_ECB							0
#define BLOWFISH_WORK_MODE_CBC							1
#define BLOWFISH_WORK_MODE_CFB							2

#define BASE64_BUF_FREE(p)								do{if(NULL!=(p)){free(p);(p)=NULL;}}while(0)


/*
************************************************************************************************************************************************************************
* 数据类型定义
************************************************************************************************************************************************************************
*/


typedef void *BLOWFISH_HANDLE;


/*
************************************************************************************************************************************************************************
* 函数原型声明
************************************************************************************************************************************************************************
*/


#define BlowfishCreateObj	YALAP_BlowfishCreateObj
#define BlowfishDestroyObj	YALAP_BlowfishDestroyObj
#define BlowfishEncrypt		YALAP_BlowfishEncrypt
#define BlowfishDecrypt		YALAP_BlowfishDecrypt
#define Base64Decode		YALAP_Base64Decode
#define Base64Encode		YALAP_Base64Encode
#define MD5_StdEncrypt		YALAP_MD5_StdEncrypt
#define HMAC_MD5_Encrypt	YALAP_HMAC_MD5_Encrypt




/*
 ************************************************************************************************************************************************************************     
 *函数名称: YALAP_BlowfishCreateObj
 *功能描述: 创建河豚加密算法实例对象
 *输入描述: 密匙及其长度、初始链值、32绕标记
 *输出描述: 无
 *返回描述: 对象句柄/失败NULL
 *作者日期: ZCQ/2008/07/01
 *全局声明: BlowfishScmAuiInitP[],BlowfishScmAuiInitS[][]
 *特殊说明: 河豚加密算法采用对称密匙，加解密变换前后保持长度不变
 ************************************************************************************************************************************************************************       
*/
extern BLOWFISH_HANDLE YALAP_BlowfishCreateObj(unsigned char *pKey,size_t KeySize,unsigned int ChainLeft,unsigned int ChainRight,BOOL Is32Round);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: YALAP_BlowfishDestroyObj
 *功能描述: 释放河豚加密算法实例对象
 *输入描述: 对象句柄
 *输出描述: 无
 *返回描述: 无
 *作者日期: ZCQ/2008/06/27
 *全局声明: 无
 *特殊说明: 无
 ************************************************************************************************************************************************************************       
*/
extern void YALAP_BlowfishDestroyObj(BLOWFISH_HANDLE Handle);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: YALAP_BlowfishEncrypt
 *功能描述: 河豚加密算法加密
 *输入描述: 对象句柄、输入明文及其长度、加密模式
 *输出描述: 输出密文
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2008/06/27
 *全局声明: 无
 *特殊说明: 若输出指针为NULL则在输入缓冲区就地输出
 ************************************************************************************************************************************************************************       
*/
extern BOOL YALAP_BlowfishEncrypt(BLOWFISH_HANDLE Handle,unsigned char *pInputBuf,size_t Len,int WorkMode,unsigned char *pOutputBuf);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: YALAP_BlowfishDecrypt
 *功能描述: 河豚加密算法解密
 *输入描述: 对象句柄、输入密文及其长度、加密模式
 *输出描述: 输出明文
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2008/06/27
 *全局声明: 无
 *特殊说明: 若输出指针为NULL则在输入缓冲区就地输出
 ************************************************************************************************************************************************************************       
*/
extern BOOL YALAP_BlowfishDecrypt(BLOWFISH_HANDLE Handle,unsigned char *pInputBuf,size_t Len,int WorkMode,unsigned char *pOutputBuf);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: YALAP_Base64Decode
 *功能描述: Base64解码
 *输入描述: Base64编码的码流及其长度
 *输出描述: 原始码流及其长度
 *返回描述: 成功(原始码流指针)/失败(NULL)
 *作者日期: ZCQ/2008/06/30
 *全局声明: Base64BaseTable
 *特殊说明: 调用者负责释放返回的缓冲区
 ************************************************************************************************************************************************************************       
*/
extern unsigned char *YALAP_Base64Decode(unsigned char *Source,int *pLen);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: YALAP_Base64Encode
 *功能描述: Base64编码
 *输入描述: 原始码流及其长度
 *输出描述: Base64编码的码流及其长度
 *返回描述: 成功(Base64码流指针)/失败(NULL)
 *作者日期: ZCQ/2008/06/30
 *全局声明: Base64BaseTable
 *特殊说明: 调用者负责释放返回的缓冲区
 ************************************************************************************************************************************************************************       
*/
extern unsigned char *YALAP_Base64Encode(unsigned char *Source,int *pLen);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: YALAP_MD5_StdEncrypt
 *功能描述: MD5标准加密(RFC1321)
 *输入描述: 原始信息及其长度
 *输出描述: MD5标准加密结果
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2008/07/02
 *全局声明: 无
 *特殊说明: MD5加密结果总是固定16字节长度
 ************************************************************************************************************************************************************************       
*/
extern BOOL YALAP_MD5_StdEncrypt(unsigned char *pText,int TextLen,unsigned char *pDigest);

/*
 ************************************************************************************************************************************************************************     
 *函数名称: YALAP_HMAC_MD5_Encrypt
 *功能描述: 散列密匙MD5加密(RFC2104)
 *输入描述: 原始信息及其长度、密匙及其长度
 *输出描述: 散列密匙MD5加密结果
 *返回描述: 成功(TRUE)/失败(FALSE)
 *作者日期: ZCQ/2008/07/02
 *全局声明: 无
 *特殊说明: MD5加密结果总是固定16字节长度
 ************************************************************************************************************************************************************************       
*/
extern BOOL YALAP_HMAC_MD5_Encrypt(unsigned char *text,int text_len,unsigned char *key,int key_len,unsigned char *digest);





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

/******************************************YaAppPublic.h 文件结束******************************************************************************************************/
#endif
