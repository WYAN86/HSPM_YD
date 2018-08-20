/* =================================================================================
File name:       vc_slvc_parameter.H                     
                    

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the VC , SLVC and parameter test.

=====================================================================================
 History:
-------------------------------------------------------------------------------------
2013.05.17  kegy  
2014.7.25   Zh.J                                                
------------------------------------------------------------------------------*/

#ifndef vc_slvc_parameter_H 
#define vc_slvc_parameter_H 

typedef struct { /*======�������========*/
				  float32  fIu;          //���룺��Ƶ����������������ѹ
				  float32  fIv; 
				  float32  fIw;  

				  float32  fUu; 
				  float32  fUv; 
				  float32  fUw; 

				  float32  fFrRef;       //���룺Ƶ�ʸ���
				  float32  fFrFbd;       //���룺������ʵ���ٶȷ���

                 /*======�������========*/
                  Uint16   uParaTest;    //���룺�Ƿ�ѡ�������ʶ��1������ʶ��0�ǲ�����ʶ            
				  Uint16   uCtrMethod;   //���룺���Ʒ���ѡ��1 SLVC���ƣ�0 VC����
				  Uint32   uSoftStart;   //���룺Ԥ���ż���ֵ����

				  float32  fRs;          //���룺���ӵ���
				  float32  fRr;          //���룺ת�ӵ���
				  float32  fLls;         //���룺����©��
				  float32  fLlr;         //���룺ת��©��
				  float32  fLm;          //���룺����
				  float32  fNP;          //���룺�ż�����
				  float32  fCos;         //���룺��������

				  float32  fUb;          //���룺��ѹ��ֵ
				  float32  fIb;          //���룺������ֵ
				  float32  fUrate;       //���룺��ѹ�ֵ
				  float32  fIrate;       //���룺�����ֵ
				  float32  fSliprate;    //���룺ת��ֵ������ֵ��
				  float32  fPrate;       //���룺�����

				  float32  fUdc;         //���룺ֱ�����ѹ
				  float32  fTs;          //���룺PWM�ж�����

				  float32  fIqExc;       //���룺ת�ٹ���ʱ��ת�ؼ�������
				  float32  fTimeExc;     //���룺����ʱ��
				  float32  fIdRef;       //���룺��ʼ���Ÿ���
				  

                  float32  fCurKp;       //���룺������KP
                  float32  fCurKi;       //���룺������KI
				  float32  fCurUp;       //���룺�������������
				  float32  fCurLw;       //���룺�������������
				        
				  float32  fSpdKpmax_VC;  //���룺VCת�ٻ�KP���ֵ
				  float32  fSpdKpmax_SLVC;//���룺SLVCת�ٻ�KP���ֵ
				  float32  fSpdKpmin_VC;  //���룺VCת�ٻ�KP��Сֵ
				  float32  fSpdKpmin_SLVC;//���룺SLVCת�ٻ�KP��Сֵ
                  float32  fSpdKi;        //���룺ת�ٻ�KI
				  float32  fSpdUp;        //���룺ת�ٻ��������
				  float32  fSpdLw;        //���룺ת�ٻ��������

				  float32  fPhrRef;      //���룺ת�Ӵ�������
				  float32  fPhrFrLow;    //���룺ת�Ӵ����ջ�Ƶ�ʷ�ֵ��������Ƶ�ʴ��ڴ�ֵʱת�Ӵ����ջ�����
				  float32  fPhrKp;       //���룺ת�Ӵ�����KP
                  float32  fPhrKi;       //���룺ת�Ӵ�����KI
				  float32  fPhrUp;       //���룺ת�Ӵ������������
				  float32  fPhrLw;       //���룺ת�Ӵ������������
		  
				  float32  fSptestKp;       //���룺ת�ٹ��㻷KP
                  float32  fSptestKimin;    //���룺ת�ٹ��㻷KI��Сֵ
				  float32  fSptestKimid;    //���룺ת�ٹ��㻷KI�м�ֵ
				  float32  fSptestKimax;    //���룺ת�ٹ��㻷KI���ֵ
				  float32  fSptestFrmin;    //���룺ת�ٹ��ƻ��м�Ƶ���趨ֵ
				  float32  fSptestUp;       //���룺ת�ٹ��㻷�������
				  float32  fSptestLw;       //���룺ת�ٹ��㻷�������
				      
				  
				  float32  fTestKp;        //���룺������ʶ������KP
                  float32  fTestKi;        //���룺������ʶ������KI
				  float32  fTestUp;        //���룺������ʶ�������������
				  float32  fTestLw;        //���룺������ʶ�����������

				  float32  fCutFre_dc;     //�������˳�ֱ�������ĵ�ͨ�˲���ֹƵ��
                  float32  fCutFre_sw;     //����������ģ�ͺ͵�ѹģ�͵��л�Ƶ��

				  /*======�м����========*/
				  Uint16   Evaluate_period;   //������ִֵ������
				  Uint16   uReverse;          //SLVC�����ת�жϱ�ʶ

				  /*======�������========*/
				  float32  fParaRs;          //������������ӵ��裨����ֵ��
				  float32  fParaRr;          //���������ת�ӵ��裨����ֵ��
				  float32  fParaLls;         //�������������©�У�����ֵ��
				  float32  fParaLlr;         //���������ת��©�У�����ֵ)
				  float32  fParaLm;          //������������У�����ֵ��
				  Uint16   uTestOver;        //������������������ʶ������־
				  Uint16   uTestFault;       //������������������ʶ���Ͻ׶�
				  Uint16   uTestStep;        //������������������ʶ���ڵڼ��׶�

				  float32  fSpeedTest;       //���������SLVC���Ƶ��ת��
				  float32  fIsqSet;          //���������ʸ������ת�ص�������ֵ
				  float32  fIsdSet;          //���������ʸ���������ŵ�������ֵ
				  float32  fIsqAct;          //���������ʸ������ת�ص���ʵ��ֵ
				  float32  fIsdAct;          //���������ʸ���������ŵ���ʵ��ֵ
                  float32  fPhrAct;          //���������ʵ��ת�Ӵ���
				  float32  fUd;              //���������d���ѹ
				  float32  fUq;              //���������q���ѹ
				  float32  fTheta;           //���������ʸ������ͬ���Ƕ�

				  Uint16   uFlyStart;
				  float32  fFrRefFly;

				  float32  fSptestKpFly;       //���룺ת�ٹ��㻷KP(����ʱ)
                  float32  fSptestKiminFly;    //���룺ת�ٹ��㻷KI��Сֵ(����ʱ)
				  float32  fSptestKimidFly;    //���룺ת�ٹ��㻷KI�м�ֵ(����ʱ)
				  float32  fSptestKimaxFly;    //���룺ת�ٹ��㻷KI���ֵ(����ʱ)

				  Uint32   uFaultTest;

		 	 	  void  (*pfnVccontrolcalc)();
		 	 	  void  (*pfnVccontrolinit)();
		 	 	  void  (*pfnVccontrolclear)();	 
				 } VCANDSLVCORPARA;	            

/*-----------------------------------------------------------------------------
Default initalizer for the PARK object.
-----------------------------------------------------------------------------*/                     
#define VCANDSLVCORPARA_DEFAULTS {0,0,0,\
                                  0,0,0,\
                                  0.02,0,\
								  0,0,4000,\
								  0.03907,0.03102,0.067303,0.067303,1.51177,0,0,\
								  0,0,380,0,0.0533,2200,\
								  0,0.000230,\
								  0.2,1.0,0.6,\
								  0.2,0.04,1.0,-1.0,\
								  3.0,2.0,2.0,2.0,0.1,1.0,-1.0,\
								  0.95,0.06,0.1,0.0001,0.3,-0.3,\
								  1.0,0.01,0.1,0.1,0.2,1000.0,-1000.0,\
								  0.01,0.0004,1.0,-1.0,\
								  0.03,15.0,\
								  0,0,\
								  0,0,0,0,0,0,0,0,\
								  0,0,0,0,0,0,0,0,0,\
								  0,1.0,\
								  36.0,0.0004,5.0,5.0,\
								  0,\
              			         (void (*)(Uint32))pfnVccontrolcalc,\
              			         (void (*)(Uint32))pfnVccontrolinit,\
              			         (void (*)(Uint32))pfnVccontrolclear }
/*------------------------------------------------------------------------------
Prototypes for the functions in PARK.C
------------------------------------------------------------------------------*/
void pfnVccontrolcalc(VCANDSLVCORPARA *v);
void pfnVccontrolinit(VCANDSLVCORPARA *v);
void pfnVccontrolclear(VCANDSLVCORPARA *v);

extern VCANDSLVCORPARA VC_SLVC_PARAMETER;

extern void fnInitVCinput_off(void);
extern void fnInitVCinput_inter(void);
extern void fnVectorCtrlInterface(void);
extern void fnInitInterg_Encode(void);

#endif






              			  


