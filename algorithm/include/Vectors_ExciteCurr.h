/* =================================================================================
File name:       Vectors_ExciteCurr.H                     
                    
Originator:	justin_zh@yeah.net 

Description: ͬ�������Ϣ�ų�����ͷ�ļ�


=====================================================================================
 History:
-------------------------------------------------------------------------------------
 05-06-2014	Version 1.0                                                 
------------------------------------------------------------------------------*/
#ifndef VECTOR_EXCITECURR_H
#define VECTOR_EXCITECURR_H

typedef struct {  /*�������*/
				  float32  fFref;       //���룺����Ƶ��
				  float32  fPhxAct;     //���룺��ǰת�Ӵ���

				  /*�������*/
				  float32  fFrLow;      //���������űջ����õ�Ƶ�ʹյ�
				  float32  fExCurrSet;  //���������ŵ����ⲿ����
				  float32  fPhxRef;     //������ʵ��ת������
				  float32  fPhxKp;      //������ת������Kp
				  float32  fPhxKi;      //������ת������Ki
				  float32  fPhxUpLmt;   //������ת�����Ż�������ֵ
				  float32  fPhxLwLmt;   //������ת�����Ż������Сֵ
				  
				  //==�м����=======
				  float32   fPhxUpTemp;
				  float32   fPhxLwTemp;
                  
				  /*�������*/
				  float32  fExCurrOut;  //��������ŵ�������

		 	 	  void  (*pfnCalc)();
		 	 	  void  (*pfnReset)();	 
				 } SYNEXCITECURRENT;	            

typedef SYNEXCITECURRENT *SYNEXCITECURRENT_handle;

/*-----------------------------------------------------------------------------
Default initalizer for the SYNEXCITECURRENT object.
-----------------------------------------------------------------------------*/                     
#define SYNEXCITECURRENT_DEFAULTS {  0,0.0,\
                                 0.2,0.0,0.98,0.0,0.0,0.3,-0.3,\
								 0.2,\
                                 0,0,\
              			         (void (*)(Uint32))fnExCurr_Calc,\
              			         (void (*)(Uint32))fnExCurr_Reset}
              			  
/*------------------------------------------------------------------------------
Prototypes for the functions in Vectors_ExciteCurr.C
------------------------------------------------------------------------------*/
void fnExCurr_Calc(SYNEXCITECURRENT_handle);
void fnExCurr_Reset(SYNEXCITECURRENT_handle);

#endif
//============end of the file ===========
//==========no more======================


