/* =================================================================================
File name:       CUR_VOL_MODEL.H                     
                    
Originator:	

Description: ������ѹ���ģ�ͽṹ��
=====================================================================================
 History:
-------------------------------------------------------------------------------------
 07-09-2013	Version 1.0                                                
------------------------------------------------------------------------------*/
#ifndef CUR_VOL_MODEL_H
#define CUR_VOL_MODEL_H  
typedef struct {/*�������*/
				//1
				float32	fIu;       //�������������������ѹ
				float32	fIv;
				float32	fUu;
				float32	fUv;
				float32 fIdSet;
				float32 fIqSet;
				float32 fSetSpd;  // �������������ת��
				float32 fSlip;
			
				/*�������*/
				//2
				float32	fTs;       //���������PWM�ж�ʱ��
				float32	fLm;       //�������������
				float32	fLs;       //�������������©��
				float32	fLr;       //���������ת��©��
				float32	fRr;       //���������ת�ӵ���
				float32	fRs;       //������������ӵ���

				float32  fKp;      //������ת��ʶ�����ϵ��
				float32  fKimin;   //������ת��ʶ�����ϵ����Сֵ
				float32  fKimid;   //������ת��ʶ�����ϵ���м�ֵ
                float32  fKimax;   //������ת��ʶ�����ϵ�����ֵ
				float32  fmin;     //������ת��ʶ����Сֵ
				float32  fmax;     //������ת��ʶ�����ֵ
				
				float32  fCutFre_dc;//�������˳�ֱ�������ĵ�ͨ�˲���ֹƵ��
                float32  fCutFre_sw;//����������ģ�ͺ͵�ѹģ�͵��л�Ƶ��

				float32  fFrmin;   //������ת�ٹ���Ki�м�ֵƵ��
				float32  fFrmid;
				float32  fFrmax;
				
				Uint16   uMethod;  //������ʸ�����Ʒ�����־λ		
				Uint16   uParatest;  //������������ʶ��־λ	
				Uint16   uFlyStart;	
				Uint16   uFlyCount;
				float32  fFrRefstop;

				/*�м����*/
				//3
				float32	fLs_sigm;  //�м������©��ϵ��ls_sigm = ls - lm * lm/lr
				float32	fTr;       //�м������ת��ʱ�䳣��
				float32	fTr_invt;  //�м������ת��ʱ�䳣������
				float32	fTsTr_invt;
				float32	fTs_invt;
				float32 fLrDivLm;
				float32 fIdSet_former;

				float32	fIAlpha_former;
				float32	fErAlpha;
				float32	fErBeta;
				float32	fIBeta_former;
				float32	fPhr_Cur_former;
				float32	fPhr_Cur;
				float32	fPhr_Cur_Alpha;
				float32	fPhr_Cur_Beta;

				float32	fErAlpha_Disdc;
				float32	fErBeta_Disdc;
				float32	fPhr_Vol_Alpha;
				float32	fPhr_Vol_Beta;
				float32	fPhr_Alpha;
				float32	fPhr_Beta;
				float32	fPhr_D;
				float32	fPhr_Q;

				float32  fKiTemp;    //�м������Ki�����м�ֵ

				/*�������*/
				//4
				float32	fAng;
				float32	fPhr;        //���������ת�Ӵ���
				float32 fSpeedTest;  //�������������ת��

				/*����*/
				void     (*pfnInit)();		// ��ʼ������ָ��
				void     (*pfnCalc)();		// ���㺯��ָ��
				 
} SPDESTCURVOL;
#define SPDESTCURVOL_DEFAULTS  {0,0,0,0,0,0,0,0,\
								0.00025,1.51177,1.5788,1.5788,0.03102,0.03907,\
								1.0,0.0001,0.1,0.1,-1000.0,1000.0,\
								0.03,15.0,\
								0.2,0.3,0.4,\
								0,0,0,0,0.0,\
								0,0,0,0,0,0,0,\
								0,0,0,0,0,0,0,0,\
								0,0,0,0,0,0,0,0,\
								0,\
								0,0,0,\
								(void (*)(Uint32))fnSpdest_init,\
								(void (*)(Uint32))fnSpdest_calc}


void fnSpdest_init(SPDESTCURVOL *p);
void fnSpdest_calc(SPDESTCURVOL *p);

#endif










