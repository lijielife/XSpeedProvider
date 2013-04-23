// CTPWrapper.cpp : ���� DLL Ӧ�ó������ڵ㡣
//
#include "..\header\stdafx.h"
using namespace std;

DFITCTraderApi* _trader;
XSpeedTraderSpi* _spi;

extern "C" 
{

  ///
  CTPWRAPPER_API int Process(void *instance, CTP_REQUEST_TYPE type, void *pReqData, int nRequestID,int p1,char *p2)
  {
    switch(type)
    {
      
    case TraderApiCreate:
      {
        //�������׽ӿ�
        DFITCTraderApi* pTrader = DFITCTraderApi::CreateDFITCTraderApi();

        return (int)pTrader;
      }

    case TraderApiInit:
      {

        //���׽ӿ�
        //DFITCTraderApi* pTrader = (DFITCTraderApi *)instance;
        DFITCTraderApi* pTrader = DFITCTraderApi::CreateDFITCTraderApi();

        cout<<"DFITCTraderApi:"<<pTrader<<"\n";
        //std::printf("DFITCTraderApi:%d \n",pTrader);

        //C#�ص�����
        XSpeedResponseCallback callback = (XSpeedResponseCallback)pReqData;
        cout<<"DFITCTraderApi:"<<callback<<"\n";
        //std::printf("XSpeedResponseCallback:%d \n",callback);

       OutputLog("DFITCTraderApi::CreateDFITCTraderApi");

        //�������׻ص�
        //XSpeedTraderSpi *spi = new XSpeedTraderSpi(callback);
        XSpeedTraderSpi *spi = new XSpeedTraderSpi();

        //ע��ص�
        pTrader->Init(p2,spi);
        OutputLog("DFITCTraderApi::Init");

        //���ûص�����
        spi->callback = callback;

        //������callback֮ǰ�����Ѿ����������������OnFrontConnected��Ӧȴ�޷��׵�C#��
        //����ٴ��ֹ���������Ӧ
        if(spi->connected)
        {
          spi->OnFrontConnected();

          int RequestID = 0;
/*
          struct DFITCUserLoginField value;

          memset(&value,0,sizeof(DFITCUserLoginField));

          value.lRequestID = RequestID++;
          strcpy( value.accountID,"000100000421");
          strcpy( value.passwd,"123");

          OutputLog("DFITCTraderApi::ReqUserLogin");
          pTrader->ReqUserLogin(&value);

           while(true)
          {
            Sleep(50);
            OutputLog("wait login \n");
            if(spi->login)
            {
              OutputLog("DFITCTraderApi::ReqUserLogin Login = true");
              break;
            }
          }


          struct DFITCCapitalField capital;

           capital.lRequestID = RequestID++;
           strcpy( capital.accountID,"000100000421");

           OutputLog("DFITCTraderApi::ReqQryCustomerCapital");

           void* instance =  pTrader;
           ((DFITCTraderApi*)instance)->ReqQryCustomerCapital(&capital);

           Sleep(2000);

           struct DFITCOrderField order;

           order.lRequestID = RequestID++;
           strcpy( order.accountID,"000100000421");

           OutputLog("DFITCTraderApi::ReqQryOrderInfo");
           pTrader->ReqQryOrderInfo(&order);

           Sleep(2000);*/



          //struct DFITCExchangeInstrumentField exchange;

          //exchange.lRequestID = RequestID++;
          //strcpy( exchange.accountID,"000100000421");
          //strcpy( exchange.exchangeID,"DCE");

          //OutputLog("DFITCTraderApi::ReqQryExchangeInstrument");
          //pTrader->ReqQryExchangeInstrument(&exchange);

        }
/*
        DFITCTraderApi* pTrader2 = DFITCTraderApi::CreateDFITCTraderApi();
        XSpeedTraderSpi spi2;
        pTrader2->Init(p2,&spi2);


        if(spi2.connected)
        {
          spi2.OnFrontConnected();

          int RequestID = 0;

          struct DFITCUserLoginField value;

          memset(&value,0,sizeof(DFITCUserLoginField));

          value.lRequestID = RequestID++;
          strcpy( value.accountID,"000100000422");
          strcpy( value.passwd,"123");

          OutputLog("DFITCTraderApi::ReqUserLogin");
          pTrader2->ReqUserLogin(&value);

           while(true)
          {
            Sleep(50);
            OutputLog("wait login \n");
            if(spi2.login)
            {
              OutputLog("DFITCTraderApi::ReqUserLogin Login = true");
              break;
            }
          }

          struct DFITCCapitalField capital;

          memset(&capital,0,sizeof(DFITCCapitalField));

          capital.lRequestID = RequestID++;
          strcpy( capital.accountID,"000100000422");

          Process(pTrader2,ReqQryCustomerCapital, &capital,capital.lRequestID,0,NULL);
        }*/


        //_trader = pTrader;
        //_spi = spi;

        return (int)pTrader;
      }


      ///ɾ���ӿڶ�����
      ///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
    case TraderApiRelease:
      {

        DFITCTraderApi* pTrader = (DFITCTraderApi *)instance;

        pTrader->Release();
        //pTrader->DestoryDFITCTraderApi(pTrader);

        delete instance;
        instance = NULL;

        return 0;
      }
      
      ///�û���¼����
    case TraderApiReqUserLogin:
      {

        //DFITCUserLoginField value;
        //memcpy(&value,pReqData,sizeof(DFITCUserLoginField));

        return ((DFITCTraderApi*)instance)->ReqUserLogin((DFITCUserLoginField*)pReqData);
        //return ((DFITCTraderApi*)instance)->ReqUserLogin(&value);
        //return 0;
      }


      ///�ǳ�����
    case TraderApiReqUserLogout:
      {
        return ((DFITCTraderApi*)instance)->ReqUserLogout((DFITCUserLogoutField*)pReqData);
      }

    case MarketDataCreate:
      {
        //C#�ص�����
        XSpeedResponseCallback callback = (XSpeedResponseCallback)instance;

        //��������ӿ�
        DFITCMdApi* pMdApi = DFITCMdApi::CreateDFITCMdApi();
        //�������׻ص�
        CTPMarketDataSpi *spi = new CTPMarketDataSpi(callback);

        //ע��ص�
        pMdApi->Init(p2,spi);

        return (int)pMdApi;
      }

    case MarketDataRelease:
      {
        DFITCMdApi* pMarketData = (DFITCMdApi *)instance;

        pMarketData->Release();
        pMarketData->DestoryDFITCMdApi(pMarketData);

        delete instance;
        instance = NULL;

        return 0;
      }

       ///��������
    case MarketDataSubscribeMarketData:
      {
        char** p = (char**)calloc(p1, sizeof(char*));

        p = (char**)p2;

        p[0] = *p;

        for(int i=1;i<p1-1;i++)
        {
          p[i] = p[i-1] + strlen(p[i-1]) + 1;
        }

        return ((DFITCMdApi*)instance)->SubscribeMarketData(p, p1);
      }

       ///�˶�����
    case MarketDataUnSubscribeMarketData:
      {
        char** p = (char**)calloc(p1, sizeof(char*));

        //p = (char**)p2;
        OutputDebugStringA(p2);
        p[0] = p2;

        for(int i=1;i<p1-1;i++)
        {
          p[i] = p[i-1] + strlen(p[i-1]) + 1;
        }

        return ((DFITCMdApi*)instance)->UnSubscribeMarketData(p, p1);
      }


    case ReqInsertOrder:
      {
        return ((DFITCTraderApi*)instance)->ReqInsertOrder((DFITCInsertOrderField*)pReqData);
      }

    case ReqInsertLossProfitOrder:
      {
        return ((DFITCTraderApi*)instance)->ReqInsertLossProfitOrder((DFITCLossProfitOrderField*)pReqData);
      }

    case ReqInsertAbiOrder:
      {
        return ((DFITCTraderApi*)instance)->ReqInsertAbiOrder((DFITCAbiOrderField*)pReqData);
      }

    case ReqInsertOptOrder:
      {
        return ((DFITCTraderApi*)instance)->ReqInsertOptOrder((DFITCOptionOrderField*)pReqData);
      }

    case ReqCancelOptOrder:
      {
        return ((DFITCTraderApi*)instance)->ReqCancelOptOrder((DFITCOptionOrderCancelField*)pReqData);
      }

    case ReqCancelOrder:
      {
        return ((DFITCTraderApi*)instance)->ReqCancelOrder((DFITCCancelOrderField*)pReqData);
      }

    case ReqQryPosition:
      {
        return ((DFITCTraderApi*)instance)->ReqQryPosition((DFITCPositionField*)pReqData);
      }

    case ReqQryCustomerCapital:
      {

        struct DFITCCapitalField* capital = (DFITCCapitalField*)pReqData;

        //memset(&capital,0,sizeof(DFITCCapitalField));

        //capital.lRequestID = 10;
        //strcpy( capital.accountID,"000100000421");

        OutputLog("DFITCTraderApi::ReqQryCustomerCapital");

        //return ((DFITCXSPEEDAPI::DFITCTraderApi*)instance)->ReqQryCustomerCapital((DFITCCapitalField*)pReqData);
        return ((DFITCTraderApi*)instance)->ReqQryCustomerCapital(capital);
        //return _trader->ReqQryCustomerCapital(capital);
        
      }

    case ReqQryExchangeInstrument:
      {
        
        //struct DFITCExchangeInstrumentField exchange;

        //exchange.lRequestID = 5;
        //strcpy( exchange.accountID,"000100000421");
        //strcpy( exchange.exchangeID,"DCE");

        //OutputLog("DFITCTraderApi::ReqQryExchangeInstrument");
        //((DFITCTraderApi*)instance)->ReqQryExchangeInstrument(&exchange);

        //return 0;
        return ((DFITCTraderApi*)instance)->ReqQryExchangeInstrument((DFITCExchangeInstrumentField*)pReqData);
      }

    case ReqQryArbitrageInstrument:
      {
        return ((DFITCTraderApi*)instance)->ReqQryArbitrageInstrument((DFITCAbiInstrumentField*)pReqData);
      }

    case ReqQryOrderInfo:
      {
        return ((DFITCTraderApi*)instance)->ReqQryOrderInfo((DFITCOrderField*)pReqData);
      }

    case ReqQryMatchInfo:
      {
        return ((DFITCTraderApi*)instance)->ReqQryMatchInfo((DFITCMatchField*)pReqData);
      }

    case ReqQrySpecifyInstrument:
      {
        return ((DFITCTraderApi*)instance)->ReqQrySpecifyInstrument((DFITCSpecificInstrumentField*)pReqData);
      }



      ///�û���¼����
    case MarketDataReqUserLogin:
      {
        return ((DFITCMdApi*)instance)->ReqUserLogin((DFITCUserLoginField*)pReqData);
      }


      ///�ǳ�����
    case MarketDataReqUserLogout:
      {
        return ((DFITCMdApi*)instance)->ReqUserLogout((DFITCUserLogoutField*)pReqData);
      }

    default:
      {
        return -1;
      }
    }
  };

};

