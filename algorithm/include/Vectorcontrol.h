/* =================================================================================
File name:       VECTORCONTROL.H                     
                    
Description: 
Header file containing constants, data type definitions, and 
function prototypes for the vector control.

=====================================================================================
 History:
-------------------------------------------------------------------------------------
2013.05.20   kegy  1.0                                                
------------------------------------------------------------------------------*/
#include "DSP2833x_Device.h"     // Headerfile Include File

#pragma CODE_SECTION(fnVector_calc, "ramfuncs")
//#pragma CODE_SECTION(fnVector_init, "ramfuncs") 

typedef struct {  Uint16   uCtrMethod;    //���룺���ٶȱ����������ٶȱ��������Ʒ���ѡ��0��ʾ���ٶȱ�������1��ʾ���ٶȱ�����                  
                  Uint32   uSoftstart;    //���룺������ʱ���趨
				  Uint16   uParatest;
                  Uint16   uReverse;
                  float32  fUdcVector;
				  float32  fFrRef;
				  float32  fFrAct;
				  float32  fFrTest;
				  float32  fIdAct;
				  float32  fIqAct;
				  float32  fFsRate;
				  float32  fIqExc;       //���룺ת�ٹ���ʱ��ת�ؼ�������
				  float32  fIdRef;
				  
				  float32  fLr;          //���룺�����������ѹ������
				  float32  fLm;
				  float32  fNP;
				  float32  fUbVector;
				  float32  fUuIn;
				  float32  fUvIn;
				  float32  fIuIn;
				  float32  fIvIn;

				  Uint32   uStartCount;   //�м����������������
				  Uint32   uExciteCount;
				  float32  fExciteTime;   //���������ת�ٹ��㼤��ʱ��
				  float32  fIdSet;
				  float32  fIqSet;
				  float32  fFsyn;
				  float32  fTetoIq;
				  Uint16   uFrCount;
				  float32  fFsSet;
 
                  float32  fUsd;          //�����dq���ѹ      
				  float32  fUsq;
				  float32  fThetaVector;  //������ų�����Ƕ�

				  float32  fSptestKp;       //���룺ת�ٹ��㻷KP
                  float32  fSptestKimin;    //���룺ת�ٹ��㻷KI��Сֵ
				  float32  fSptestKimid;    //���룺ת�ٹ��㻷KI�м�ֵ
				  float32  fSptestKimax;    //���룺ת�ٹ��㻷KI���ֵ

				  Uint32   uFlagFlystart;
				  float32  fFrRefFly;

				  float32  fSptestKpFly;       //���룺ת�ٹ��㻷KP(����ʱ)
                  float32  fSptestKiminFly;    //���룺ת�ٹ��㻷KI��Сֵ(����ʱ)
				  float32  fSptestKimidFly;    //���룺ת�ٹ��㻷KI�м�ֵ(����ʱ)
				  float32  fSptestKimaxFly;    //���룺ת�ٹ��㻷KI���ֵ(����ʱ)

				  Uint16   uPhrCount;
				  float32  fPhrActFilter;
				  Uint16   uUq_startflag;

		 	 	  void  (*pfnVectorcalc)();
		 	 	  void  (*pfnVectorinit)();	 
				 } VECTORCONTROL;
				 	            
/*-----------------------------------------------------------------------------
Default initalizer for the PARK object.
-----------------------------------------------------------------------------*/                     
#define VECTORCONTROL_DEFAULTS {  0,0,0,0,0,0,0,0,0,0,0,0,0,\
                                  0,0,0,0,0,0,0,0,\
                                  0,0,0,0,0,0,0,0,0,\
								  0,0,0,\
								  3.6,0.0002,0.2,0.2,\
								  0,1.0,\
								  36.0,0.0004,5.0,5.0,0,0.0,0,\
              			         (void (*)(Uint32))fnVector_calc,\
              			         (void (*)(Uint32))fnVector_init }  
/*------------------------------------------------------------------------------
Prototypes for the functions in PARK.C
------------------------------------------------------------------------------*/
void fnVector_calc(VECTORCONTROL *v);
void fnVector_init(VECTORCONTROL *v);

//extern VCANDSLVCORPARA VC_SLVC_PARAMETER;
extern float32 fFrAct;
extern Uint16 uInterCount;	
extern Uint32 uSoftStartCount;
extern VECTORCONTROL Vector_Control;


