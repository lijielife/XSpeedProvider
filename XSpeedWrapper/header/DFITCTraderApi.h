/**
 * ��Ȩ����(C)2012-2016, �����ɴ���Ϣ�������޹�˾
 * �ļ����ƣ�DFITCTraderApi.h
 * �ļ�˵��������XSpeed���׽ӿ�
 * ��ǰ�汾��1.0.0
 * ���ߣ�XSpeed��Ŀ��
 * �������ڣ�2012��8��28��
 */
 
#ifndef DFITCTRADERAPI_H_
#define DFITCTRADERAPI_H_

#include "DFITCAPISTRUCT.h"

namespace DFITCXSPEEDAPI
{
#ifdef DFITCTRADERAPI_EXPORTS
#define DFITCTRADERAPI_API __declspec(dllexport)
#else
#define DFITCTRADERAPI_API __declspec(dllimport)
#endif

class DFITCTraderSpi
{
public:
	   
    /* ��������������Ӧ:���ͻ����뽻�׺�̨�轨����ͨ������ʱ����δ��¼ǰ�����ͻ���API���Զ������ǰ�û�֮������ӣ�
     * ��������ã����Զ��������ӣ������ø÷���֪ͨ�ͻ��ˣ� �ͻ��˿�����ʵ�ָ÷���ʱ������ʹ���ʽ��˺Ž��е�¼�����÷�������Api��ǰ�û��������Ӻ󱻵��ã��õ��ý�����˵��tcp�����Ѿ������ɹ����û���Ҫ���е�¼���ܽ��к�����ҵ���������¼ʧ����˷������ᱻ���á���
     */	     
    virtual void OnFrontConnected(){};
	
    /**
     * �������Ӳ�������Ӧ�����ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
     * @param  nReason:����ԭ��
     *        0x1001 �����ʧ��
     *        0x1002 ����дʧ��
     *        0x2001 ����������ʱ
     *        0x2002 ��������ʧ�� 
     *        0x2003 �յ�������  
     */
    virtual void OnFrontDisconnected( int nReason ){};
	
    /**
     * ��½������Ӧ:���û�������¼�����ǰ�û�������Ӧʱ�˷����ᱻ���ã�֪ͨ�û���¼�Ƿ�ɹ���
     * @param pUserLoginInfoRtn:�û���¼��Ϣ�ṹ��ַ��
     * @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ���ýṹ���д�����Ϣ��
     */
    virtual void OnRspUserLogin( struct DFITCUserLoginInfoRtnField *pUserLoginInfoRtn,struct DFITCErrorRtnFiled *pErrorInfo ){};
	
    /**
     * �ǳ�������Ӧ:���û������˳������ǰ�û�������Ӧ�˷����ᱻ���ã�֪ͨ�û��˳�״̬��
     * @param pUserLogoutInfoRtn:�����û��˳���Ϣ�ṹ��ַ��
     * @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
     */
    virtual void OnRspUserLogout( struct DFITCUserLogoutInfoRtnField *pUserLogoutInfoRtn,struct DFITCErrorRtnFiled *pErrorInfo ){};
	
    /**
     * �ڻ�ί�б�����Ӧ:���û�¼�뱨����ǰ�÷�����Ӧʱ�÷����ᱻ���á�
     * @param pOrderRtn:�����û��µ���Ϣ�ṹ��ַ��
     * @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
     */
    virtual void OnRspInsertOrder( struct DFITCOrderRspDataRtnField *pOrderRtn,struct DFITCErrorRtnFiled *pErrorInfo ){};
	
    /**
     * �ڻ�ί�г�����Ӧ:���û�������ǰ�÷�����Ӧ�Ǹ÷����ᱻ���á�
     * @param pOrderCanceledRtn:���س�����Ӧ��Ϣ�ṹ��ַ��
     * @param pErrorInfo:������ʧ�ܣ����ش�����Ϣ��ַ��
     */
    virtual void OnRspCancelOrder( struct DFITCOrderRspDataRtnField *pOrderCanceledRtn,struct DFITCErrorRtnFiled *pErrorInfo ){};

    /* ��Ȩί�б�����Ӧ:��ʱ��֧�֡�*/    
    virtual void OnRspInsertOptOrder( DFITCRspInsertOptOrderRtnField *pOptOrder ){};

    
    /* ��Ȩί�г�����Ӧ:��ʱ��֧�֡�*/   
    virtual void OnRspCancelOptOrder( DFITCRspCancelOptOrderRtnField *pOptOrder ){};

    /**
     * ����ر�
     * @param pErrorInfo:������Ϣ�Ľṹ��ַ��
     */
    virtual void OnRtnErrorMsg( struct DFITCErrorRtnFiled *pErrorInfo ){};
	
    /**
     * �ɽ��ر�:��ί�гɹ����׺�η����ᱻ���á�
     * @param pRtnMatchData:ָ��ɽ��ر��Ľṹ��ָ�롣
     */
    virtual void OnRtnMatchedInfo( struct DFITCMatchRtnField *pRtnMatchData ){};
	
    /**
     * ί�лر�:�µ�ί�гɹ��󣬴˷����ᱻ���á�
     * @param pRtnOrderData:ָ��ί�лر���ַ��ָ�롣
     */
    virtual void OnRtnOrder( struct DFITCOrderRtnField *pRtnOrderData ){};
	
    /**
     * �����ر�:�������ɹ���÷����ᱻ���á�
     * @param pCancelOrderData:ָ�򳷵��ر��ṹ�ĵ�ַ���ýṹ�������������Լ�������Ϣ��
     */
    virtual void OnRtnCancelOrder( struct DFITCOrderCanceledRtnField *pCancelOrderData ){};
	
    /**
     * ��ѯ����ί����Ӧ:���û�����ί�в�ѯ�󣬸÷����ᱻ���á�
     * @param pRtnOrderData:ָ��ί�лر��ṹ�ĵ�ַ��
     * @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
     */
    virtual void OnRspQryOrderInfo( struct DFITCOrderCommRtnField *pRtnOrderData, bool bIsLast ){};
	
    /**
     * ��ѯ���ճɽ���Ӧ:���û������ɽ���ѯ��÷����ᱻ���á�
     * @param pRtnMatchData:ָ��ɽ��ر��ṹ�ĵ�ַ��
     * @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
     */
    virtual void OnRspQryMatchInfo( struct DFITCMatchedRtnField *pRtnMatchData, bool bIsLast ){};
	
    /**
     * �ֲֲ�ѯ��Ӧ:���û������ֲֲ�ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
     * @param pPositionInfoRtn:���سֲ���Ϣ�ṹ�ĵ�ַ��
     * @param pErrorInfo:������Ϣ�ṹ������ֲֲ�ѯ���������򷵻ش�����Ϣ��
     * @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
     */
    virtual void OnRspQryPosition( struct DFITCPositionInfoRtnField *pPositionInfoRtn,struct DFITCErrorRtnFiled *pErrorInfo, bool bIsLast ){};
	
    /**
     * �ͻ��ʽ��ѯ��Ӧ:���û������ʽ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
     * @param pCapitalInfoRtn:�����ʽ���Ϣ�ṹ�ĵ�ַ��
     * @param pErrorInfo:������Ϣ�ṹ������ͻ��ʽ��ѯ���������򷵻ش�����Ϣ��
     */
    virtual void OnRspCustomerCapital( struct DFITCCapitalInfoRtnField *pCapitalInfoRtn,struct DFITCErrorRtnFiled *pErrorInfo ){};
	
    /**
     * ��������Լ��ѯ��Ӧ:���û�������Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
     * @param pInstrumentData:���غ�Լ��Ϣ�ṹ�ĵ�ַ��
     * @param pErrorInfo:������Ϣ�ṹ������ֲֲ�ѯ���������򷵻ش�����Ϣ��
     * @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
     */
    virtual void OnRspQryExchangeInstrument( struct DFITCExchangeInstrumentRtnField *pInstrumentData,struct DFITCErrorRtnFiled *pErrorInfo, bool bIsLast ){};
	
    /**
     * ������Լ��ѯ��Ӧ:���û�����������Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
     * @param pAbiInstrumentData:����������Լ��Ϣ�ṹ�ĵ�ַ��
     * @param pErrorInfo:������Ϣ�ṹ������ֲֲ�ѯ���������򷵻ش�����Ϣ��
     * @param bIsLast:�����Ƿ������һ����Ӧ��Ϣ��0 -��   1 -�ǣ���
     */
    virtual void OnRspArbitrageInstrument( struct DFITCAbiInstrumentRtnField *pAbiInstrumentData,struct DFITCErrorRtnFiled *pErrorInfo, bool bIsLast ){};
	
    /**
     * ��ѯָ����Լ��Ӧ:���û�����ָ����Լ��ѯָ���ǰ�÷�����Ӧʱ�÷����ᱻ���á�
     * @param pInstrument:����ָ����Լ��Ϣ�ṹ�ĵ�ַ��
     */
    virtual void OnRspQrySpecifyInstrument( struct DFITCInstrumentRtnField *pInstrument ){};

};//end of DFITCTraderSpi

class DFITCTRADERAPI_API DFITCTraderApi
{
public:
    DFITCTraderApi();
    virtual ~DFITCTraderApi();
	
    /**
     * ��̬����������һ��apiʵ��
     * @return ��������UserApi
     */
    static DFITCTraderApi *CreateDFITCTraderApi();
	
    /**
     * ɾ���ӿڶ���������ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
     */
    virtual void Release();
	
    /**
     * �ͷ���������socket���ӣ�������һ�������̣߳� ͬʱ�÷���ע��һ���ص�������
     * @param pszFrontAddr:����ǰ�������ַ��
     *                     �����ַ�ĸ�ʽΪ:"protocol://ipaddress:port",��"tcp://172.21.200.103:10910"
     *                     ����protocol��ֵΪtcp��ʽ��
     *                     ipaddress��ʾ����ǰ�õ�IP,port��ʾ����ǰ�õĶ˿�     
     * @param *pSpi:��DFITCMdSpi����ʵ��
     * @return 0 - ��ʼ���ɹ�; -1 - ��ʼ��ʧ�ܡ�
     */
    virtual int Init( char *pszFrontAddr,DFITCTraderSpi *pSpi );
	
    /**
     * �ȴ��ӿ��߳̽������С�
     * @return �߳��˳����롣
     */
    virtual int Join();
    
    //����
    virtual void HeartBeat();
	
    /**
     * �û�������½����
     * @param pUserLoginData:ָ���û���¼����ṹ�ĵ�ַ��
     * @return 0 - ��¼�ɹ�; 1 - ��¼ʧ��(��¼ʧ��Ϊ�û������ߵ�¼��������)��
     */ 
    virtual int ReqUserLogin( struct DFITCUserLoginField *pUserLoginData );
	
    /**
     * �û������ǳ�����
     * @param pUserLogoutData:ָ���û���¼����ṹ�ĵ�ַ��
     * @return 0 - ��¼�ɹ�; 1 - �ǳ�ʧ�ܡ�
     */ 
    virtual int ReqUserLogout( struct DFITCUserLogoutField *pUserLogoutData );
	
    /**
     * �ڻ�ί�б�������
     * @param pInsertOrderData:�û����󱨵���Ϣ�ṹ��ַ��
     * @return 0 - �µ��ɹ�; 1 - �µ�ʧ�ܡ�
     */
    virtual int ReqInsertOrder( struct DFITCInsertOrderField *pInsertOrderData );

  
    /* �ڻ�ֹӯֹ�𱨵�����:�ݲ�֧�֡�*/
    virtual int ReqInsertLossProfitOrder( struct DFITCLossProfitOrderField *pOrderData );
	 
    /* �ڻ�������������:�ݲ�֧�֡�*/  
    virtual int ReqInsertAbiOrder( struct DFITCAbiOrderField *pAbiOrder );
    
    /*��Ȩ��������:�ݲ�֧�֡�*/
    virtual int ReqInsertOptOrder( DFITCOptionOrderField *pOptOrder );
        
    /* ��Ȩ��������:�ݲ�֧�֡�*/    
    virtual int ReqCancelOptOrder( DFITCOptionOrderCancelField *pOptOrder );

    /**
     * �ڻ���������
     * @param pCancelOrderData:�û����󳷵���Ϣ�ṹ��ַ��
     * @return 0 - �����ɹ�; 1 - ����ʧ�ܡ�(���ͬʱ�ṩ��̨ί�кźͱ���ί�кţ����̨ά�������ȴ���)
     */
    virtual int ReqCancelOrder( struct DFITCCancelOrderField *pCancelOrderData );
	
    /**
     * �ֲֲ�ѯ����
     * @param pPositionData:ָ������ֲֲ�ѯ�ṹ��ַ��
     * @return 0 - ��ѯ�ɹ�; 1 - ��ѯʧ�ܡ������û���ṩ��Լ���룬���ѯȫ���ֲ���Ϣ����
     */
    virtual int ReqQryPosition( struct DFITCPositionField *pPositionData );
	
    /**
     * �ͻ��ʽ��ѯ����
     * @param pCapitalData:�����ʽ��ѯ�ṹ��ַ��
     * @return 0 - ��ѯ�ɹ�; 1 - ��ѯʧ�ܡ�(�û���Ҫ���ýṹ�ĸ����ֶΡ�)
     */
    virtual int ReqQryCustomerCapital( struct DFITCCapitalField *pCapitalData );
	
    /**
     * ��ѯ��������Լ�б�����������
     * @param pExchangeInstrumentData:��������Լ��ѯ�ṹ��ַ��
     * @return 0 - ��ѯ�ɹ�; 1 - ��ѯʧ�ܡ�
     */
    virtual int ReqQryExchangeInstrument( struct DFITCExchangeInstrumentField *pExchangeInstrumentData );

    /**
     * ��ѯ������������Լ�б�
     * @param pAbtriInstrumentData:������������Լ��ѯ�ṹ��ַ��
     * @return 0 - ��ѯ�ɹ�; 1 - ��ѯʧ�ܡ�
     */
    virtual int ReqQryArbitrageInstrument( struct DFITCAbiInstrumentField *pAbtriInstrumentData );

    /**
     * ����ί�в�ѯ����
     * @param pOrderData:����ί�в�ѯ�ṹ��ַ��
     * @return 0 - ��ѯ�ɹ�; 1 - ��ѯʧ�ܡ�
     */
    virtual int ReqQryOrderInfo( struct DFITCOrderField *pOrderData );

    /**
     * ���ճɽ���ѯ����
     * @param pMatchData:���ճɽ���ѯ�ṹ��ַ��
     * @return 0 - ��ѯ�ɹ�; 1 - ��ѯʧ�ܡ�
     */
    virtual int ReqQryMatchInfo( struct DFITCMatchField *pMatchData );

    /**
     * ָ����Լ��Ϣ��ѯ����
     * @param pInstrument:ָ����Լ��ѯ�ṹ��ַ��
     * @return 0 - ��ѯ�ɹ�; 1 - ��ѯʧ�ܡ�
     */
    virtual int ReqQrySpecifyInstrument( struct DFITCSpecificInstrumentField *pInstrument );

protected:
    static void DestoryDFITCTraderApi( DFITCTraderApi *pApi );
    DFITCTraderSpi *m_pSpi;
};//end of DFITCTraderApi
}//end of namespace
#endif