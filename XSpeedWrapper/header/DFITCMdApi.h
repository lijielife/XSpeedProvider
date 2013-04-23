/**
 * ��Ȩ����(C)2012-2016, �����ɴ���Ϣ�������޹�˾
 * �ļ����ƣ�DFITCMdApi.h
 * �ļ�˵��������XSpeed����API�ӿ�
 * ��ǰ�汾��1.0.0
 * ���ߣ�XSpeed��Ŀ��
 * �������ڣ�2012��8��28��
 */
 
#ifndef DLMDAPI_H_
#define DLMDAPI_H_

namespace DFITCXSPEEDMDAPI
{
#ifdef DFITCMDAPI_EXPORTS
#define MDAPI_API __declspec(dllexport)
#else
#define MDAPI_API __declspec(dllimport)
#endif
	
#include "DFITCApiStruct.h"
	
class DFITCMdSpi
{
public:
    DFITCMdSpi(){}
		
    //��������������Ӧ
    virtual void OnFrontConnected(){};
		
    //�������Ӳ�������Ӧ
    virtual void OnFrontDisconnected( int nReason ){};
	
    /**
     * ��½������Ӧ:���û�������¼�����ǰ�û�������Ӧʱ�˷����ᱻ���ã�֪ͨ�û���¼�Ƿ�ɹ���
     * @param pRspUserLogin:�û���¼��Ϣ�ṹ��ַ��
     * @param pRspInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
     */
    virtual void OnRspUserLogin(struct DFITCUserLoginInfoRtnField *pRspUserLogin, struct DFITCErrorRtnFiled *pRspInfo) {}
		
    /**
     * �ǳ�������Ӧ:���û������˳������ǰ�û�������Ӧ�˷����ᱻ���ã�֪ͨ�û��˳�״̬��
     * @param pRspUsrLogout:�����û��˳���Ϣ�ṹ��ַ��
     * @param pRspInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
     */
    virtual void OnRspUserLogout(struct DFITCUserLogoutInfoRtnField *pRspUsrLogout,struct DFITCErrorRtnFiled *pRspInfo) {}
		
    /*����Ӧ��*/
    virtual void OnRspError(struct DFITCErrorRtnFiled *pRspInfo) {}
	
    /**
     * ���鶩��Ӧ��:���û��������鶩�ĸ÷����ᱻ���á�
     * @param pSpecificInstrument:ָ���Լ��Ӧ�ṹ���ýṹ������Լ�������Ϣ��
     * @param pRspInfo:������Ϣ������������󣬸ýṹ���д�����Ϣ��
     */
    virtual void OnRspSubMarketData(struct DFITCSpecificInstrumentField *pSpecificInstrument, struct DFITCErrorRtnFiled *pRspInfo) {}
	
    /**
     * ȡ����������Ӧ��:���û������˶������÷����ᱻ���á�
     * @param pSpecificInstrument:ָ���Լ��Ӧ�ṹ���ýṹ������Լ�������Ϣ��
     * @param pRspInfo:������Ϣ������������󣬸ýṹ���д�����Ϣ��
     */
    virtual void OnRspUnSubMarketData(struct DFITCSpecificInstrumentField *pSpecificInstrument, struct DFITCErrorRtnFiled *pRspInfo) {}
	
    /**
     * ������ϢӦ��:�����������ɹ��������鷵��ʱ���÷����ᱻ���á�
     * @param pMarketDataField:ָ��������Ϣ�ṹ��ָ�룬�ṹ���а��������������Ϣ��
     */
    virtual void OnMarketData(struct DFITCDepthMarketDataField *pMarketDataField) {}
	virtual void OnRspRegisterPort(struct DFITCErrorRtnFiled *pRspInfo){}
    virtual ~DFITCMdSpi(){}
};//end of DFITCMdSpi
	
class MDAPI_API DFITCMdApi
{
public:
		
    /**
     * ��������APIʵ��
     * @return ��������UserApi
     */
    static DFITCMdApi *CreateDFITCMdApi();
		
    /**
     * ����һ��apiʵ����
     * @return ����UserApi
     */
    static void DestoryDFITCMdApi(DFITCMdApi *mdApi);
		
    /**
     * ����һϵ�г�ʼ������:ע��ص������ӿ�,��������ǰ�á�
     * @param pszSvrAddr:����ǰ�������ַ��
     *                  �����ַ�ĸ�ʽΪ:"protocol://ipaddress:port",��"tcp://127.0.0.1:10915"
     *                  ����protocol��ֵΪtcp����udp,��ʾ��������ķ�ʽ;�����udp������������,udp�Ķ˿ڽ���API����ȷ����
     *                  ipaddress��ʾ����ǰ�õ�IP,port��ʾ����ǰ�õĶ˿�     
     * @param *pSpi:��DFITCMdSpi����ʵ��
     * @return 0 - �ɹ�;1 - ʧ�ܡ�
     */
    virtual int Init( char *pszSvrAddr,DFITCMdSpi *pSpi);

	 /**
     * ɾ���ӿڶ���������ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
     */
    virtual void Release();
		
    /**
     * ��ȡ��ǰ������:ֻ�е�¼�ɹ��󣬲��ܻ����ȷ�Ľ�����
     * @return ���ַ�����ʽ���ص�ǰ�����գ���ȷ�����롣
     */
    virtual const char *GetTradingDay();
		
    /**
     * ��������:�÷�����������ĳ������ĳЩ��Լ��������
     * @param ppInstrumentID[]:ָ�����飬ÿ��ָ��ָ��һ����Լ.  
     * @param nCount:��Լ����
     * @return ĳ����ĳЩ��Լ�ĺ�Լ��Ϣ�����û���ṩ��Լ���루��Լ����������ֵ*ʱ������������������Ϣ����
     */
    virtual int SubscribeMarketData(char *ppInstrumentID[], int nCount);
		
    /**
     * �˶�����:�÷��������˶�ĳ��/ĳЩ��Լ��������
     * @param ppInstrumentID[]:ָ�����飬ÿ��ָ��ָ��һ����Լ.  
     * @param nCount:��Լ����
     * @return ĳ����ĳЩ��Լ�ĺ�Լ��Ϣ
     */
    virtual int UnSubscribeMarketData(char *ppInstrumentID[], int nCount);
		
    /**
     * �û�������½����
     * @param pReqUserLoginField:ָ���û���¼����ṹ�ĵ�ַ��
     * @return 0 - ��¼�ɹ�; 1 - ��¼ʧ��(��¼ʧ��Ϊ�û������ߵ�¼��������)��
     */ 
    virtual int ReqUserLogin(DFITCUserLoginField*pReqUserLoginField);
		
    /**
     * �û������ǳ�����
     * @param pReqUserLogoutField:ָ���û���¼����ṹ�ĵ�ַ��
     * @return 0 - �ǳ��ɹ�; 1 - �ǳ�ʧ�ܡ�
     */ 
    virtual int ReqUserLogout(DFITCUserLogoutField *pReqUserLogoutField);
		
    virtual ~DFITCMdApi();
		
protected:
	  	
    //���캯��
    DFITCMdApi();
		  
private:
    DFITCMdSpi *m_spi;
    };//end of MDAPI_API
} //end of namespace	
#endif