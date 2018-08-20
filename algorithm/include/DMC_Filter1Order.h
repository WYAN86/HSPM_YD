/* =================================================================================
File name:       DMC_Filter.H                     
                    
Originator:	

Description: һ���˲���ͷ�ļ�
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 12-29-2012	Version 1.0                                                
------------------------------------------------------------------------------*/
//#define PI  3.1415926
#ifndef _DMC_Filter1Order_h_
#define _DMC_Filter1Order_h_
typedef struct {  //����
                  float32  fInput;  	// �˲��������  
				  float32  fSampFre;	// ����Ƶ��  
				  float32  fCutFre;	    // ��ֹƵ��(Hz) 
                  
				  //���
				  float32  fOutput;	    // �˲��������

				  //�м����
                  float32  fOutputOld;  //�˲�����һ�����������ֵ
				  float32  fInputOld;   //�˲�����һ������������ֵ
				  float32  fA0;         //�˲���ϵ��
				  float32  fA1;         //�˲���ϵ��
				  float32  fB0;         //�˲���ϵ��

			      //����
		 	 	  void  (*pfnInit)();      //��ʼ������ָ��
				  void  (*pfnCalc)();      //���㺯��ָ��
				  void  (*pfnRest)();      //��λ����ָ��
				 } SFILTER1ORDER;
				 
typedef SFILTER1ORDER *SFILTER1ORDER_handle;	
/*-----------------------------------------------------------------------------
��ʼ���˲���
-----------------------------------------------------------------------------*/                     
#define SFILTER1ORDER_DEFAULTS { 0.0, 0.0, 0.0, \
                                 0.0, \
                                 0.0, 0.0, 0.0, 0.0, 0.0, \
                                 (void (*)(Uint32))fnFilter1OrderInit\
              			         (void (*)(Uint32))fnFilter1OrderCal\
              			         (void (*)(Uint32))fnFilter1OrderReset}
//#define PI 3.1415926
/*------------------------------------------------------------------------------
Prototypes for the functions in CLARKE.C
------------------------------------------------------------------------------*/
void fnFilter1OrderInit(SFILTER1ORDER_handle);
void fnFilter1OrderCal(SFILTER1ORDER_handle);
void fnFilter1OrderReset(SFILTER1ORDER_handle);

#endif

//=====nomore=====


