/*
 �ļ�����feu.h
 ���ܣ�	 ����feu��ԪSDK��Ľӿ��ļ�
 ���ڣ�  2016-10-31
*/

#ifndef __FEU_SDK__
#define __FEU_SDK__

//��׼�������Ͷ���
typedef char			CHAR;			//��׼CHAR
typedef int			INT;			//��׼INT



#if defined(WIN32) || defined(WINNT)
typedef signed __int64      INT64,  *PINT64;
#else
typedef long long           __int64;
typedef long long           INT64,  *PINT64;

#endif


#ifdef	__cplusplus
extern "C" {
#endif

	//Զ�̿��Ƴ�ʱʱ��(����)
#define RC_TIMEOUT  20000

	/***********************************************************************/
	//                                                                      //
	//                        ����ص��ĺ���ָ��                             //
	//                                                                     //
	/***********************************************************************/

	//1Զ�̿��ƻص�����ָ�붨�壨����ң�أ�ң����������
	//����˵������FSU�·�Զ�̿��Ƶ����
	//          
	//����˵����1��iDeviceId �豸�ţ�
	//          2��iCellId   �ɼ���
	//	        3��szCmd ��  ������
	//          4��iActiveNo ������룬����ʶ�𷵻�ִ�н��   
	//              
	//����ֵ˵����0 ���ճɹ���
	typedef int(*RCFunc)(__int64 iDeviceId, int iCellId, char *szCmd, int iActiveNo);



	//2ι���ص�����ָ�붨��
	//����˵����FEU��FSUι������ֹFEU�����ܷǵ������
	//          
	//����˵����1��iHandle �߳�ID��
	//          2��iTimeOutΪ��ʱֵ������Ϊ��λ�����ܸ��ã�
	//              ��iTimeOut > 0,�����߳�δ�����������ע�ᣬ���Ѿ���������ι����
	//              ��iTimeOut =0 ����ע����
	//	         3��pV1��pV1��չʹ�ã������Լ�����
	//����ֵ˵����0 �ɹ���
	typedef int(*WDFunc)(int iHandle, int iTimeOut, void *pV1, void *pV2);



	/*
	//3�������ûص�����ָ�붨��
	//����˵������ƽ̨�޸�VPN������Ϣ��
	//����˵����pXmlParam ΪXML��ʽ���ַ�����ʹ��GBK���룬��ʽ���£�
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



	//4����֪ͨ�ص�����ָ�붨��
	//����˵����FEU��Ҫ����ʱ����ƽ̨�·��������FEU֪ͨFSU��FSUֹͣFEU�����к�
	//         ͨ��FTP���ط�����ָ����FEU���ļ�����ɺ�������FEU��
	//����˵����1��pFileName �ļ����ƣ�
	//	       2��szVersion �汾��
	typedef int(*SUPFunc)(char * pFileName, char *szVersion);


	//5FTP���������ص�����ָ�붨��
	//����˵��������FTP������ʹ�á�
	//          
	//����˵������
	typedef int(*FtpStartFunc)();



	//6FTP����ֹͣ�ص�����ָ�붨��
	//����˵����ֹͣFTP������ʹ�á�
	//          
	//����˵������
	typedef int(*FtpStopFunc)();



	//7FTP��������޸Ļص�����ָ�붨��
	//����˵�����޸�FTP�����û�Ȩ�޲���ʱʹ�á�
	//          
	//����˵����1��szuser �û���
	//         2��szPwd ����
	//	       3��szPath ·����FSUΪ�û������·����Ӧ������ض��Ĺ��ܣ���ʱ���壩
	//         4��iMode Ȩ��(��Linux����Ȩ��ִ��)
	typedef int(*FtpMFunc)(char *szuser, char *szPwd, char *szPath, int  iMode);



	//8������ʱ�ص�����ָ�붨��
	//����˵������FEUʶ��������ʱʱ��֪ͨFSU��
	//          
	//����˵������
	typedef int(*CSFunc)();



	//9��ȡFSU�汾�Żص�����ָ�붨��
	//����˵����FEU��ע��ʱ��Ҫ��ȡFSU�İ汾ʱʹ�á�
	//         FSUͨ����д�汾���������������ء�
	//����˵����1��szVer �汾��������, 
	//	       2��iSize �汾���������Ĵ�С
	//              
	typedef int(*GVERFunc)(char *szVer, int iSize);



	//10 FSUʱ��ͬ���ص�����ע��
	//����˵������FEU�յ�ʱ��ͬ������ʱ���á�
	//          
	//����˵����cur_time ��������ʱ�䣬��1970-1-1 0:0:0 �����ڵ�����
	//                 
	typedef int(*SCLKFunc)(int cur_time);


    
    //11���cpu��mem����
    //����˵�������cpu��memʹ���ʺ���
    //����˵����1��cpu cpuʹ����, 
    //	       2��mem �ڴ�ʹ����
    //              
    typedef int(*GCMFunc)(float *fCpu, float *fMem);



	//12��ȡVPN״̬�ص�����ָ�붨��
	//����˵����FEU��ȡFSU��ǰVPN״̬��ʹ��XML��ʽ���ء�
	//          
	//����˵����1��szVpnStat xml�ı����ػ�����, 
	//				XML��ʽ���ַ�����ʹ��GBK���룬��ʽ���£�
	//				<VpnStat><Stat>1</Stat><IPAddr></IPAddr><MacId></MacId><ImsiId></ImsiId><NetworkType></NetworkType>
	//				<Carrier></Carrier><NMVendor></NMVendor><NMType></NMType></VpnStat>
	//	       2��iLen ����������
	// 
	typedef int(*GVpnFunc)(char *szVpnStat, int iLen);

	/***********************************************************************/
	//                                                                      //
	//                         FEU��������                                  //
	//                                                                     //
	/***********************************************************************/

	//1���в������� 
	//����˵������FSU����FEU�����ݲ����ļ���FEU��FEUͨ�������ļ���
	//	       ��ʶ�����Լ������в����������й����У����������仯
	//	       ���ã�֪ͨFEU
	//����˵����pFileName�ļ���ָ�룬XML��ʽ ������ConfigSet.xml����
	//����ֵ˵����0 �ɹ���
	int  FEU_SetRunConfig(char* pFileName);

    /*
	//2��־�������
	//����˵����������־�����ͨ������ConfigSet.xml�ļ�ָ���Ŀ����ļ���ʵ�֡�
	//����˵������
	//����ֵ˵����0 �ɹ�
	ConfigSet.xml�ļ�����
	<LogSet title="��־����">
	<Path title="·��" />
	<Size title="�ռ��С" />
	<LogCtrlFile title="��־���ؿ����ļ� ����FEU_CtrlLogOut()����ʱ����">LogCtrl.xml</LogCtrlFile>
	</LogSet>
	Ϊ������־�������
	*/
	int FEU_CtrlLogOut();




	//3�澯���˲������� 
	//����˵������FSU����FEU�����ݲ����ļ���FEU��FEUͨ�������ļ���
	//	    ��ʶ�����Լ������в����������й����У����������仯
	//	    ���ã�֪ͨFEU
	//����˵����pFileName�ļ���ָ�룬XML��ʽ�� ����AlarmFilt.xml��
	//����ֵ˵����0 �ɹ���
	int  FEU_SetAlarmFiltCfg(char* pFileName);

	//4�澯������������ 
	//����˵������FSU����FEU�����ݲ����ļ���FEU��FEUͨ�������ļ���
	//	    ��ʶ�����Լ������в����������й����У����������仯
	//	    ���ã�֪ͨFEU
	//����˵����pFileName�ļ���ָ�룬XML��ʽ,����AlarmActLink.xml��
	//����ֵ˵����0 �ɹ���
	int  FEU_SetAlarmActiveLink(char* pFileName);




	/***********************************************************************/
	//                                                                     //
	//                         FEU���ܺ���ע��                             //
	//                                                                     //
	/***********************************************************************/

    //1FTP��������޸Ļص��������� 
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc �ص�������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_FTPModifyParam(FtpMFunc pCallProc);

	//2Զ�̿��ƻص���������
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc �ص�������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_RC(RCFunc pCallProc);

	//3ι���ص���������
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc �ص�������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_WatchDog(WDFunc pCallProc);

	//4������ʱ�ص���������
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc �ص�������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_ComStat(CSFunc pCallProc);

	//5��ȡFSU�汾��Ϣ�ص���������
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc �ص�������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_GetFsuVersion(GVERFunc pCallProc);

	//6 ��ȡFSU��VPN״̬�Ļص���������
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc �ص�������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_GetVpnStat(GVpnFunc pCallProc);

	//7 FSUʱ��ͬ���Ļص���������
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc �ص�������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_SetFsuTime(SCLKFunc pCallProc);

    //8��ȡ��Դ������
	//����˵������ȡFSU��CPU���ڴ������ʵĻص�����ע�ᡣ
	//����˵����pCallProc �ص�������ָ�롣	
	//����ֵ˵����0 ��ע��ɹ� -1���������Ϊ��
	int  FEU_SetCallProc_GetFSUResource (GCMFunc  pCallProc);




	//9FTP���������ص��������� 
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc��������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_FTPStart(FtpStartFunc pCallProc);

	//10FTP����ֹͣ�ص���������  
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc��������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_FTPStop(FtpStopFunc pCallProc);

	//11��������޸Ļص���������
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc��������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_NetParamModify(NTFunc pCallProc);

	//12FEU����֪ͨ�ص���������
	//����˵����FSU��FEU���ݻص�����ָ��
	//����˵����pCallProc��������ָ�롣
	//����ֵ˵����0 �ɹ���
	int  FEU_SetCallProc_SdkUpdate(SUPFunc pCallProc);

	
	/***********************************************************************/
	//                                                                      //
	//                         SDK���в���                                  //
	//                                                                     //
	/***********************************************************************/

	//1FEU�������к���
	//����˵��������FEU���С�
	//����˵�����ޡ�
	//����ֵ˵����0 �ɹ���
	int  FEU_RunStart();



	//2FEUֹͣ���к���
	//����˵����ֹͣFEU���С�
	//����˵�����ޡ�
	//����ֵ˵����0 �ɹ���
	int  FEU_RunStop();

	/***********************************************************************/
	//                                                                      //
	//                            FEU����                                   //
	//                                                                     //
	/***********************************************************************/

	//1ʵʱң�������ύ����
	//����˵����FSU�ύʵʱ�ɼ���������(�����ϱ�ʹ��)
	//����˵���� 1��iDeviceId �豸�ţ�
	//          2��iCellId   �ɼ���
	//  	    3��szVal ��  �ַ�����ֵ  
	//����ֵ˵����0 �ɹ���
	INT  FEU_AiData(INT64 iDeviceId, INT iCellId, CHAR* szVal);



	//2ң�Ź���ң���ʵʱ�����ύ����
	//����˵����FSU�ύ��ң�����ݴ�����ң�����ݣ������жϸ澯ʹ��
	//����˵����1��iDeviceId �豸�ţ�
	//         2��iCellId   �ɼ���
	//	       3��szVal ��  �ַ�����ֵ��ң��ֵ��  
	//����ֵ˵����0 �ɹ���
	//���磺�¶ȳ��߸澯���ɼ�����룺0418005001������Ҫ�ѵ�ǰ���¶�ֵͨ��szVal���ݡ�
	INT  FEU_AiDrvAlarm(INT64 iDeviceId, INT iCellId, CHAR* szVal);



	//3ң�ŵ�ʵʱ�����ύ����
	//����˵����FSU�ύ��ң�����ݴ�����ң�����ݣ������жϸ澯ʹ��
	//����˵����1��iDeviceId �豸�ţ�
	//         2��iCellId   �ɼ���
	//	       3��iStat ��  ң��ֵ�����壺0 Ϊ������1������̬��FEU����Ϊ�澯����  
	//����ֵ˵����0 �ɹ���
	int  FEU_DiData(INT64 iDeviceId, INT iCellId, INT iStat);



	//4ң�ص�ʵʱ�����ύ����
	//����˵����FSU�ύ��ң�����ݴ�����ң�����ݣ������жϸ澯ʹ��
	//����˵����1��iDeviceId �豸�ţ�
	//         2��iCellId   �ɼ���
	//	       3��iStat ��  ң��ֵ�����壺0 Ϊ������1������̬��  
	//����ֵ˵����0 �ɹ���
	int  FEU_DoData(INT64 iDeviceId, INT iCellId, INT iStat);



	//5ң����ʵʱ�����ύ����
	//����˵����FSU�ύʵʱ�ɼ���������(�����ϱ�ʹ��)
	//����˵����1��iDeviceId �豸�ţ�
	//         2��iCellId   �ɼ���
	//	       3��szVal ��  �ַ�����ֵ  
	//����ֵ˵����0 �ɹ���
	INT  FEU_AoData(INT64 iDeviceId, INT iCellId, CHAR* szVal);



	//6Զ�̿��ƽ�����غ���
	//����˵����FSU��FEU�ύԶ�̿��Ƶķ��ؽ��
	//����˵����1��iDeviceId �豸�ţ�
	//         2��iCellId   �ɼ���
	//	       3��iActiveNo Զ�̿��Ʊ��루��FEU�ύ�ķ��أ�
	//	       4��iResult	0ʧ�� 1�ɹ�
	//����ֵ˵����0 �ɹ���
	int  FEU_RCActionRet(__int64 iDeviceId, int iCellId, int iActiveNo, int iResult);



	/*
	//7VPN״̬֪ͨ
	//����˵������FSU����VPN״̬����ʱ�����ñ�����֪ͨFEU�����ߵ�һ�Σ����ߵ�һ�Σ���
	//����˵����pXmlInfo ΪXML��ʽ���ַ�����ʹ��GKB���룬��ʽ���£�
	<VpnStat><Stat>1</Stat><IPAddr></IPAddr><MacId></MacId><ImsiId></ImsiId><NetworkType></NetworkType>
	<Carrier></Carrier><NMVendor></NMVendor><NMType></NMType></VpnStat>
	//����ֵ˵����0 �ɹ�
	*/
	int	 FEU_ReceiveVpnInfo(char *pXmlInfo);



	//8�ֵ���ѯ����
	//����˵������ѯ�ɼ��������ֵ�����Ϣ
	//����˵����1��iDeviceId �豸�ţ�����0ʱ�����������ֵ�����Ϣ��
	//            �������м�����Ϊ0ʱ��00000040600000���������ֵ���Ӧ�ɼ�����ֵ�������Ϣ��
	//	          ���Ǿ�����豸����ʱ�����ؾ����豸����Ԫ������Ϣ��
	//         2��iCellId   �ɼ���
	//	       3��pXmOutPacket �����ֵ����Ϣ��������XML��ʽ��
	//         4��iSize �����ֵ�������Ĵ�С
	//����ֵ˵����0�ɹ�
	/*
	pXmOutPacket ��ʽ��
	<DictInfoS>
	<DictInfo>
	<CellType>0</CellType>
	<CellID>0419003001</CellID>
	<CellName">�������豸�ɼ���ͨ��״̬</CellName>
	<CellUnit></CellUnit>
	<CellAlmName>�澯</CellAlmName>
	<CellResName>����</CellResName>
	<CellAlmLevel>�����澯</CellAlmLevel>
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



	//9��ȡFEU�汾��Ϣ
	//����˵����FSU��FEU��ȡ�汾��Ϣ
	//����˵����1��szBuf ���صĻ�����
	//		   2��iMaxLen �ܷ��ص���󳤶ȣ���֤20�ֽڣ�
	//����ֵ˵����0 �ɹ���
	int  FEU_Get_FEU_Version(char *szBuf, int iMaxLen);



    //10��ȡע��״̬
	//����˵����FSU��FEU��ȡע��״̬
	//����˵�����ޡ�
	//����ֵ˵����0 δע�� 1 ע��ɹ� -1 ע��ʧ�� -2 SCΪ�ա�
	int  FEU_GetRegistStat();



#ifdef	__cplusplus
}
#endif


#endif
