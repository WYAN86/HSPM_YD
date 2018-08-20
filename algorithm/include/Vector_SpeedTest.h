
/* File name:       Vector_SpeedTest.H  */ 


typedef struct {  
                  /*�������*/
				  float32  fVola;	 // ���룺A���ѹ
				  float32  fVolb;	 // ���룺B���ѹ
				  float32  fCura;    // ���룺A�����
				  float32  fCurb;    // ���룺B�����
				  float32  fwr;      // ���룺�������
				  float32  fSetSpd;  // ���룺����ת��

				  /*�������*/
				  Uint16   uMethod;  //������ʸ�����Ʒ�����־λ
				  Uint16   uParatest;//������������ʶ��־λ
				  float32  fRs;      //������������ӵ���
				  float32  fRr;      //���������ת�ӵ���
				  float32  fLls;     //�������������©��
				  float32  fLlr;     //���������ת��©��
				  float32  fLm;      //�������������
                  float32  fKp;      //������ת��ʶ�����ϵ��
				  float32  fKimin;   //������ת��ʶ�����ϵ����Сֵ
				  float32  fKimid;   //������ת��ʶ�����ϵ���м�ֵ
                  float32  fKimax;   //������ת��ʶ�����ϵ�����ֵ
				  float32  fmin;     //������ת��ʶ����Сֵ
				  float32  fmax;     //������ת��ʶ�����ֵ				  
				  float32  fPwmTime; //������pwm�ж�ʱ��
				  float32  fFrmin;   //������ת�ٹ���Ki�м�ֵƵ��
   
                  /*�м�������*/
				  float32  fPhrAlpha;  //�м������ת��Alpha����
				  float32  fPhrBeta;   //�м������ת��Beta����
				  float32  fPhsAlpha;  //�м����������Alpha����
				  float32  fPhsBeta;   //�м����������Beta����
				  float32  fPhsq;      //�м����������q�����
				  float32  fPhsd;      //�м����������d�����
				  float32  fKiTemp;    //�м������Ki�����м�ֵ

				  Uint32   uFlyStart;
				  Uint32   uFlyCount;
				  float32  fFrRefstop;


                  /*�������*/
				  float32  fPhrq;
				  float32  fPhrd;
				  float32  fSpd;	// 	
				  float32  fAng;
				  float32  fPhr;

		 	 	  void  (*pfnCalc)();	  	// Pointer to calculation function
				  void  (*pfnInit)();
				 } VECTOR_ST;	           

                   
#define VECTOR_ST_DEFAULTS {0,0,0,0,0,0,\
                           0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
						   0,0,0,0,0,0,0,\
						   0,0,0.0,\
						   0,0,0,0,0,\
              			  (void (*)(Uint32))fnVector_st_Calc,\
              			  (void (*)(Uint32))fnVector_st_Init}

void fnVector_st_Calc(VECTOR_ST *p);
void fnVector_st_Init(VECTOR_ST *p);
 
