/**
 * ��Ȩ����(C)2012-2016, �����ɴ���Ϣ�������޹�˾
 * �ļ����ƣ�DFITCApiStruct.h
 * �ļ�˵��������ӿ���������ݽӿ�
 * ��ǰ�汾��1.0.0
 * ���ߣ�XSpeed��Ŀ��
 * �������ڣ�2012��8��28��
 */

#ifndef DFITCAPISTRUCT_H_
#define DFITCAPISTRUCT_H_

#ifndef DFITCAPIDATATYPE_H
#include "DFITCAPIDATATYPE.h"
#endif


//������
struct DFITCTimeOutField
{
    long lRequestID;                                //����ID
};

//���󱨵���������(��������)
struct DFITCInsertOrderField
{
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCLocalOrderIDType localOrderID;             //����ί�к�
    DFITCInstrumentIDType instrumentID;             //��Լ����
    DFITCPriceType insertPrice;                     //�����۸�
    DFITCAmountType orderAmount;                    //��������
    DFITCBuySellTypeType  buySellType;              //������־
    DFITCOpenCloseTypeType openCloseType;           //��ƽ��־
    DFITCSpeculatorType speculator;                 //Ͷ������
    DFITCIsAutoOrderType isAutoOrder;               //�Ƿ�Ϊ�Զ���
    DFITCOrderTypeType orderType;                   //�������� �޼� ���м�
    DFITCOrderPropertyType orderProperty;           //�������� FAK��FOK
};

///////////////////////////////////////////////
///���󱨵���������(��չ����) �ݲ�֧��
///��չ������Ҫ������
///1.FAK��2.FOK��3.ֹӯֹ��4.�м۵�
///////////////////////////////////////////////
struct DFITCLossProfitOrderField
{
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCLocalOrderIDType localOrderID;             //����ί�к�
    DFITCInstrumentIDType instrumentID;             //��Լ����
    DFITCPriceType insertPrice;                     //�����۸�
    DFITCAmountType orderAmount;                    //��������
    DFITCBuySellTypeType  buySellType;              //������־
    DFITCOpenCloseTypeType openCloseType;           //��ƽ��־
    DFITCSpeculatorType speculator;                 //Ͷ������
    DFITCOrderTypeType orderType;                   //��������
    DFITCOrderPropertyType orderProperty;           //��������
    DFITCPriceType downTriggerPrice;                //�µ������۲�
    DFITCPriceType riseTriggerPrice;                //���Ǵ����۲�
    DFITCLossProfitTypeType lossID;                 //ֹ���־
    DFITCPriceType downCommPrice;                   //�µ�ί�м۲�
    DFITCLossProfitTypeType profitID;               //ֹӯ��־
    DFITCPriceType riseCommPrice;                   //����ί�м۲�
    DFITCIsAutoOrderType isAutoOrder;               //�Ƿ�Ϊ�Զ��� 
};

///////////////////////////////////////////////
///���󱨵���������(��������)
///////////////////////////////////////////////
struct DFITCAbiOrderField
{
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCLocalOrderIDType localOrderID;             //����ί�к�
    DFITCInstrumentIDType instrumentID;             //��Լ����
    DFITCPriceType insertPrice;                     //�����۸�
    DFITCAmountType orderAmount;                    //��������
    DFITCBuySellTypeType  buySellType;              //������־
    DFITCOpenCloseTypeType openCloseType;           //��ƽ��־
    DFITCInstrumentIDType instrumentID1;            //��Լ����1
    DFITCPriceType insertPrice1;                    //�����۸�1
    DFITCAmountType orderAmount1;                   //��������1
    DFITCBuySellTypeType  buySellType1;             //������־1
    DFITCPriceType   predictInsterest;              //Ԥ����Ϣ
    DFITCPriceType   triggerPrice;                  //�����۸�
    DFITCPriceType   upDownPrice;                   //��ͣ��
    DFITCDateType    availableDate;                 //��Ч����
    DFITCAmountType  lowestMatchAmount;             //��С�ɽ���
    DFITCIsAutoOrderType isAutoOrder;               //�Ƿ�Ϊ�Զ���
    DFITCOrderPropertyType orderProperty;           //��������
};

/////////////////////////////////////////////////////////
///��Ȩ���ݽṹ
/////////////////////////////////////////////////////////

///��Ȩ������������
struct DFITCOptionOrderField
{
    DFITCAccountIDType accountID;                    //�ͻ���
    DFITCInstrumentIDType instrumentID;              //��Լ����
    DFITCPriceType insertPrice;                      //ί�м۸�
    DFITCAmountType orderAmount;                     //ί������
    DFITCBuySellTypeType  buySellType;               //������־
    DFITCSpeculatorType speculator;                  //Ͷ������
    DFITCOpenCloseTypeType openCloseType;            //��ƽ��־
    DFITCOrderTypeType orderType;                    //��������
    DFITCIsAutoOrderType isAutoOrder;                //�Ƿ�Ϊ�Զ��� 
    DFITCOptionTypeType  optionType;                 //��Ȩ���:  1:����; 2:����
    DFITCInstrumentTypeType instrumentType;          //��Լ����
};

///��Ȩ������Ӧ��������
struct DFITCRspInsertOptOrderRtnField
{
};

///��Ȩ������������
struct DFITCOptionOrderCancelField
{
    DFITCAccountIDType accountID;                    //�ͻ���
    DFITCExchangeIDType exchangeID;                  //����������
    DFITCClientIDType  matchCode;                    //���ױ���
    DFITCCancelTypeType cancelID;                    //������־
    DFITCSPDOrderIDType spdOrderID;                  //��̨ί�к�
    DFITCIsAutoOrderType isAutoOrder;                //�Ƿ�Ϊ�Զ������걨��ʶ��
    DFITCOptionTypeType  optionType;                 //��Ȩ���:  1:����;  2:����
};
///��Ȩ������Ӧ�ṹ
struct DFITCRspCancelOptOrderRtnField
{
};

///������������
struct DFITCCancelOrderField
{
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCSPDOrderIDType spdOrderID;                 //��̨ί�к�
    DFITCLocalOrderIDType localOrderID;             //����ί�к�
    DFITCInstrumentIDType instrumentID;             //��Լ����
};

///ί����Ӧ����
struct DFITCOrderRspDataRtnField
{
    DFITCLocalOrderIDType localOrderID;             //����ί�к�
    DFITCSPDOrderIDType spdOrderID;                 //��̨ί�к�
    DFITCOrderAnswerStatusType  orderStatus;        //ί��״̬
};

///��ѯ�ʽ���������
struct DFITCCapitalField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
};

///��ѯ�ֲ���������
struct DFITCPositionField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCInstrumentIDType instrumentID;             //��Լ����
};

///��������Լ
struct DFITCExchangeInstrumentField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCExchangeIDType exchangeID;                 //����������
};

///�û���¼��������
struct DFITCUserLoginField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCPasswdType passwd;                         //����
};

///�û��˳�����
struct DFITCUserLogoutField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��ʺ�ID
    DFITCSessionIDType sessionID;                   //�ỰID
};

///ί�лر�
struct DFITCOrderRtnField
{
    DFITCLocalOrderIDType localOrderID;             //����ί�к�
    DFITCSPDOrderIDType spdOrderID;                 //��̨ί�к�
    DFITCOrderAnswerStatusType  orderStatus;        //ί��״̬
    DFITCSessionIDType sessionID;                   //�ỰID
};

///�ɽ��ر�
struct DFITCMatchRtnField
{
    DFITCLocalOrderIDType localOrderID;             //����ί�к�
    DFITCMatchIDType matchID;                       //�ɽ����
    DFITCInstrumentIDType instrumentID;             //��Լ����
    DFITCBuySellTypeType buySellType;               //����
    DFITCOpenCloseTypeType openCloseType;           //��ƽ��־
    DFITCPriceType matchedPrice;                    //�ɽ��۸�
    DFITCAmountType commAmount;                     //ί������
    DFITCAmountType   matchedAmount;                //�ɽ�����
    DFITCDateType matchedTime;                      //�ɽ�ʱ��
    DFITCPriceType insertPrice;                     //����
    DFITCSPDOrderIDType spdOrderID;                 //��̨ί�к�
    DFITCMatchType matchType;                       //�ɽ�����
    DFITCSpeculatorType speculator;                 //Ͷ��
    DFITCExchangeIDType exchangeID;                 //������ID
    DFITCFeeType fee;                               //������	
    DFITCSessionIDType sessionID;                   //�Ự��ʶ	
};

///�����ر�
struct DFITCOrderCanceledRtnField
{
    DFITCLocalOrderIDType   localOrderID;           //����ί�к�
    DFITCInstrumentIDType instrumentID;             //��Լ����
    DFITCPriceType        insertPrice;              //�����۸�
    DFITCBuySellTypeType buySellType;               //��������
    DFITCOpenCloseTypeType openCloseType;           //��ƽ��־
    DFITCAmountType    cancelAmount;                //��������
    DFITCSPDOrderIDType spdOrderID;                 //��̨ί�к�
    DFITCSpeculatorType speculator;                 //Ͷ��
    DFITCExchangeIDType exchangeID;                 //������ID
    DFITCDateType canceledTime;                     //����ʱ��
    DFITCSessionIDType sessionID;                   //�Ự��ʶ	
};

///������Ϣ
struct DFITCErrorRtnFiled
{
    DFITCErrorIDType  nErrorID;                     //����ID
    DFITCLocalOrderIDType localOrderID;             //����ί�к�
    DFITCErrorMsgInfoType errorMsg;                 //������Ϣ
};

///�����ʽ���Ϣ
struct DFITCCapitalInfoRtnField
{
    long requestID;                                 //����ID
    DFITCAccountIDType accountID;                   //�ʽ��ʺ�
    DFITCEquityType preEquity;                      //����Ȩ��
    DFITCEquityType todayEquity;                    //���տͻ�Ȩ��
    DFITCProfitLossType closeProfitLoss;            //ƽ��ӯ��
    DFITCProfitLossType positionProfitLoss;         //�ֲ�ӯ��
    DFITCProfitLossType frozenMargin;               //ί�ж��ᱣ֤��
    DFITCProfitLossType margin;                     //�ֱֲ�֤��
    DFITCProfitLossType fee;                        //����������
    DFITCProfitLossType available;                  //�����ʽ�
    DFITCProfitLossType withdraw;                   //��ȡ�ʽ�
    DFITCRiskDegreeType  riskDegree;                //���ն�
};



///���سֲ���Ϣ
struct DFITCPositionInfoRtnField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��ʺ�ID
    DFITCExchangeIDType exchangeID;                 //����������
    DFITCInstrumentIDType instrumentID;             //��Լ��
    DFITCBuySellTypeType  buySellType;              //����
    DFITCPriceType openAvgPrice;                    //���־���
    DFITCPriceType positionAvgPrice;                //�ֲ־���
    DFITCAmountType positionAmount;                 //�ֲ���
    DFITCAmountType totalAvaiAmount;                //�ܿ���
    DFITCAmountType todayAvaiAmount;                //�����
    DFITCAmountType lastAvaiAmount;                 //�����
    DFITCAmountType todayAmount;                    //���
    DFITCAmountType lastAmount;                     //���
    DFITCAmountType tradingAmount;                  //�ҵ���
    DFITCProfitLossType datePositionProfitLoss;     //���гֲ�ӯ��
    DFITCProfitLossType dateCloseProfitLoss;        //����ƽ��ӯ��
    DFITCProfitLossType floatProfitLoss;            //����ӯ��
    DFITCProfitLossType dMargin;                    //ռ�ñ�֤��
    DFITCSpeculatorType speculator;                 //Ͷ�����
    DFITCClientIDType clientID;                     //���ױ���
    DFITCPriceType    lastPrice;                    //������
};

///�û���¼������Ϣ
struct DFITCUserLoginInfoRtnField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��ʺ�ID
    DFITCAccountLoginResultType loginResult;        //��¼���
    DFITCLocalOrderIDType initLocalOrderID;         //��ʼ����ί�к�
    DFITCSessionIDType sessionID;                   //sessionID
    DFITCErrorIDType  nErrorID;                     //����ID
    DFITCErrorMsgInfoType errorMsg;                 //������Ϣ
};

///�û��˳�������Ϣ
struct DFITCUserLogoutInfoRtnField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCAccountLogoutResultType logoutResult;      //�˳����
    DFITCErrorIDType  nErrorID;                     //����ID
    DFITCErrorMsgInfoType errorMsg;                 //������Ϣ
};

///������Լ��ѯ
struct DFITCAbiInstrumentField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCExchangeIDType exchangeID;                 //����������
};

///������Լ������Ϣ
struct DFITCAbiInstrumentRtnField
{
    long lRequestID;                                //����ID
    DFITCExchangeIDType exchangeID;                 //����������
    DFITCInstrumentIDType InstrumentID;             //��Լ����
    DFITCVarietyNameType VarietyName;               //Ʒ������
};

///ָ���ĺ�Լ
struct DFITCSpecificInstrumentField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
    DFITCInstrumentIDType InstrumentID;             //��Լ����
    DFITCExchangeIDType exchangeID;                 //������ID
};

///��������Լ������Ϣ
struct DFITCExchangeInstrumentRtnField
{
    long lRequestID;                                //����ID
    DFITCExchangeIDType exchangeID;                 //����������
    DFITCInstrumentIDType instrumentID;             //��Լ����
    DFITCVarietyNameType VarietyName;               //Ʒ������
};

///ί�в�ѯ���ݽṹ
struct DFITCOrderField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
};

///�ɽ���ѯ���ݽṹ
struct DFITCMatchField
{
    long lRequestID;                                //����ID
    DFITCAccountIDType accountID;                   //�ʽ��˻�ID
};

///ί�в�ѯ��Ӧ���ݽṹ
struct DFITCOrderCommRtnField
{
    long lRequestID;                                //����ID
    DFITCSPDOrderIDType spdOrderID;                 //��̨ί�к�  
    DFITCOrderAnswerStatusType orderStatus;         //ί��״̬                            
    DFITCInstrumentIDType instrumentID;             //��Լ����
    DFITCBuySellTypeType buySellType;               //����
    DFITCOpenCloseTypeType openClose;               //��ƽ��־
    DFITCPriceType insertPrice;                     //ί�м�
    DFITCAmountType orderAmount;                    //ί������
    DFITCPriceType matchedPrice;                    //�ɽ��۸�
    DFITCAmountType matchedAmount;                  //�ɽ�����
    DFITCAmountType cancelAmount;                   //��������
    DFITCMatchType orderType;                       //ί�е����
    DFITCSpeculatorType speculator;                 //Ͷ��
    DFITCDateType commTime;                         //ί��ʱ��
    DFITCDateType submitTime;                       //�걨ʱ��
    DFITCClientIDType clientID;                     //���ױ���
    DFITCExchangeIDType exchangeID;                 //������ID
    DFITCFrontAddrType operStation;                 //ί�е�ַ
    DFITCAccountIDType  accountID;                  //�ͻ���
};

//�ɽ���ѯ������Ӧ
struct DFITCMatchedRtnField
{
    long lRequestID;                                //����ID
    DFITCSPDOrderIDType spdOrderID;                 //��̨ί�к�
    DFITCExchangeIDType exchangeID;                 //������ID
    DFITCInstrumentIDType instrumentID;             //��Լ����
    DFITCBuySellTypeType  buySellType;              //����
    DFITCOpenCloseTypeType openClose;               //��ƽ
    DFITCPriceType matchedPrice;                    //�ɽ��۸�
    DFITCAmountType matchedAmount;                  //�ɽ�����
    DFITCPriceType matchedMort;                     //�ɽ����
    DFITCSpeculatorType speculator;                 //Ͷ�����
    DFITCDateType matchedTime;                      //�ɽ�ʱ��
    DFITCMatchIDType matchedID;                     //�ɽ����
    DFITCLocalOrderIDType localOrderID;             //����ί�к�
    DFITCClientIDType clientID;                     //���ױ���
    DFITCOrderCommTypeType commOrderType;           //�������
};

///���غ�Լ��Ϣ���ݽṹ
struct DFITCInstrumentRtnField
{
    long lRequestID;
    DFITCInstrumentIDType instrumentID;             //��Լ����
    DFITCRatioType longMarginRatio;                 //��ͷ��֤����
    DFITCRatioType shortMarginRatio;                //��ͷ��֤����
    DFITCRatioType openFeeVolRatio;                 //���������� ����������
    DFITCRatioType closeFeeVolRatio;                //ƽ�������� ����������
    DFITCRatioType closeTodayFeeVolRatio;           //ƽ�������� ����������
    DFITCRatioType openFeeAmtRatio;                 //������������ ��������
    DFITCRatioType closeFeeAmtRatio;                //ƽ���������� ��������
    DFITCRatioType closeTodayFeeAmtRatio;           //ƽ���������� ��������	
};

///�������
struct DFITCDepthMarketDataField
{
    DFITCDateType   tradingDay;                     //������
    DFITCInstrumentIDType  instrumentID;            //��Լ����
    DFITCExchangeIDType exchangeID;                 //����������
    DFITCInstrumentIDType exchangeInstID;           //��Լ�ڽ������Ĵ���
    DFITCPriceType  lastPrice;                      //���¼�
    DFITCPriceType  preSettlementPrice;             //�ϴν����
    DFITCPriceType  preClosePrice;                  //������
    DFITCAmountType preOpenInterest;                //��ֲ���
    DFITCPriceType  openPrice;                      //����
    DFITCPriceType  highestPrice;                   //��߼�
    DFITCPriceType  lowestPrice;                    //��ͼ�
    DFITCAmountType Volume;                         //����
    DFITCPriceType  turnover;                       //�ɽ����
    DFITCAmountType openInterest;                   //�ֲ���
    DFITCPriceType  closePrice;                     //������
    DFITCPriceType  settlementPrice;                //���ν����
    DFITCPriceType  upperLimitPrice;                //��ͣ���
    DFITCPriceType  lowerLimitPrice;                //��ͣ���
    DFITCDeltaType  preDelta;                       //����ʵ��
    DFITCDeltaType  currDelta;                      //����ʵ��
    DFITCDateType UpdateTime;                       //����޸�ʱ��
    DFITCMilliSecType  UpdateMillisec;              //����޸ĺ���
    DFITCPriceType  BidPrice1;                      //�����һ
    DFITCVolumeType BidVolume1;                     //������һ
    DFITCPriceType  AskPrice1;                      //������һ
    DFITCVolumeType AskVolume1;                     //������һ
    DFITCPriceType  BidPrice2;                      //����۶�
    DFITCVolumeType BidVolume2;                     //��������
    DFITCPriceType  AskPrice2;                      //�����۶�
    DFITCVolumeType AskVolume2;                     //��������
    DFITCPriceType  BidPrice3;                      //�������
    DFITCVolumeType BidVolume3;                     //��������
    DFITCPriceType  AskPrice3;                      //��������
    DFITCVolumeType AskVolume3;                     //��������
    DFITCPriceType  BidPrice4;                      //�������
    DFITCVolumeType BidVolume4;                     //��������
    DFITCPriceType  AskPrice4;                      //��������
    DFITCVolumeType AskVolume4;                     //��������
    DFITCPriceType  BidPrice5;                      //�������
    DFITCVolumeType BidVolume5;                     //��������
    DFITCPriceType  AskPrice5;                      //��������
    DFITCVolumeType AskVolume5;                     //��������
    DFITCPriceType  AveragePrice;                   //���վ���
};

#endif
