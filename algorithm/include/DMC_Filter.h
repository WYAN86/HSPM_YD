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
#pragma CODE_SECTION(fnCalFilter1order, "ramfuncs")
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
		 	 	  void  (*pfnIniFilter1order)();      //��ʼ������ָ��
				  void  (*pfnCalFilter1order)();      //���㺯��ָ��
				  void  (*pfnResFilter1order)();      //��λ����ָ��
				 } SFILTER1OR;
				 
typedef SFILTER1OR *sFilter1order_handle;	
/*-----------------------------------------------------------------------------
��ʼ���˲���
-----------------------------------------------------------------------------*/                     
#define SFILTER1OR_DEFAULTS { 0.0, 0.0, 0.0, \
                                 0.0, \
                                 0.0, 0.0, 0.0, 0.0, 0.0, \
                                 (void (*)(Uint32))fnIniFilter1order,\
              			         (void (*)(Uint32))fnCalFilter1order,\
              			         (void (*)(Uint32))fnResFilter1order }
//#define PI 3.1415926
/*------------------------------------------------------------------------------
Prototypes for the functions in CLARKE.C
------------------------------------------------------------------------------*/
void fnIniFilter1order(sFilter1order_handle);
void fnCalFilter1order(sFilter1order_handle);
void fnResFilter1order(sFilter1order_handle);

