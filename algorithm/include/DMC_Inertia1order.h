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

typedef struct {  //����
                  float32  fInput;  	// �������  
				  float32  fSampFre;	// ����Ƶ��  
				  float32  fCutFre;	    // ��ֹƵ��(Hz) 
				  float32  fKp;         // �Ŵ�ϵ��
                  
				  //���
				  float32  fOutput;	    // �˲��������

				  //�м����
                  float32  fOutputOld;  //��һ�����������ֵ
				  float32  fInputOld;
				  float32  fA0;         //����ϵ��
				  float32  fA1;         //����ϵ��
				  float32  fB0;         //����ϵ��

			      //����
		 	 	  void  (*pfnIniInertia1order)();      //��ʼ������ָ��
				  void  (*pfnCalInertia1order)();      //���㺯��ָ��
				  void  (*pfnResInertia1order)();      //��λ����ָ��
				 } INERTIA1OR;
				 
typedef INERTIA1OR *sInertia1order_handle;	
/*-----------------------------------------------------------------------------
��ʼ���˲���
-----------------------------------------------------------------------------*/                     
#define INERTIA1OR_DEFAULTS { 0, 0, 0, 1,\
                                 0, \
                                 0, 0, 0, 0, 0,\
                                 (void (*)(Uint32))fnIniInertia1order,\
              			         (void (*)(Uint32))fnCalInertia1order,\
              			         (void (*)(Uint32))fnResInertia1order }
//#define PI 3.1415926
/*------------------------------------------------------------------------------
Prototypes for the functions in CLARKE.C
------------------------------------------------------------------------------*/
void fnIniInertia1order(sInertia1order_handle);
void fnCalInertia1order(sInertia1order_handle);
void fnResInertia1order(sInertia1order_handle);

