#include "SysCtl_AllHeaders.h"
//#pragma CODE_SECTION(fnInitVCinput_off, "XPRORAM")
#pragma CODE_SECTION(fnInitVCinput_inter, "ramfuncs")


void fnInitVCinput_off(void);
void fnInitVCinput_inter(void);
void fnInitInterg_Encode(void);
extern VECTOR_ST SpeedTest;

extern INTERG Interg_Vector;
void fnInitVCinput_off(void)
{     
 	 VC_SLVC_PARAMETER.fUrate = SysRatedParameter.fMotorRatedVoltage;      //����ߵ�ѹ�ֵ
	 VC_SLVC_PARAMETER.fIrate = SysRatedParameter.fMotorRatedCurrent;        //��������
	 VC_SLVC_PARAMETER.fPrate = SysRatedParameter.fMotorRatedPower * 1000.0;     //�������ʣ���λ(W)
	 VC_SLVC_PARAMETER.fSliprate = SysRatedParameter.fMotorRatedSlip;//0.018;  //������������ = (ͬ��ת��-�ת��)/ͬ��ת��
	 VC_SLVC_PARAMETER.fRs = * pCsvParamAsynRs; //0.025;       //������������ӵ������ֵ0.00835
	 VC_SLVC_PARAMETER.fRr = * pCsvParamAsynRr;//0.012;       //���������ת�ӵ������ֵ0.00606
	 VC_SLVC_PARAMETER.fLlr = * pCsvParamAsynLr;//0.114;     //���������ת��©�б���ֵ0.12106
	 VC_SLVC_PARAMETER.fLls = * pCsvParamAsynLs;//0.091;     //�������������©�б���ֵ0.08971
	 VC_SLVC_PARAMETER.fLm = * pCsvParamAsynLm;//3.3499;       //������������б���ֵ3.42857
	 VC_SLVC_PARAMETER.fTs = PeriodTime;//0.000237;       //�ж����ڣ���λ(s)
	 VC_SLVC_PARAMETER.fIdRef = * pCsvParamExcitCurrentST;// 0.2;        //ʸ�����Ƶ�����ŵ�����ʼֵ����
	 VC_SLVC_PARAMETER.fIqExc = * pCsvParamExcitationCurrent; //0.15;        //SLVC�𶯼�����������ֵ
	 VC_SLVC_PARAMETER.fTimeExc = * pCsvParamExcitationTime; //1.0;      //SLVC�𶯼���ʱ�䣬��λ(s)
     
     VC_SLVC_PARAMETER.fFrRef = 0.0;
     VC_SLVC_PARAMETER.fFrFbd = 0.0;//RotorSpeed.fRotorFreqPU;     //VC����ʱ�����ʵ��ת�ٷ���

	 VC_SLVC_PARAMETER.uParaTest = 0;//*pCsvParamParamIdentificEN;// 0;       //������ʶʹ�ܣ�1��������ʶ��0���ǲ�����ʶ
     VC_SLVC_PARAMETER.uCtrMethod = 1;//*pCsvParamVCORSLVC;  //0;      //���ٶȻ����ٶȱ�����ʸ������ѡ��0�����ٶ�(VC)��1�����ٶ�(SLVC)

	 VC_SLVC_PARAMETER.fPhrKp = * pCsvParamPhrKp;//0.0;        //ʸ������ת�Ӵ����ջ�Kp
     VC_SLVC_PARAMETER.fPhrKi = * pCsvParamPhrKi;//0.0000;     //ʸ������ת�ӴŴ�ջ�Ki
	 VC_SLVC_PARAMETER.fPhrFrLow =*pCsvParamPhrLoopStartFreq; //0.06;        //ʸ������ת�Ӵ����ջ�Ƶ�ʷ�ֵ��������Ƶ�ʴ��ڴ�ֵʱת�Ӵ����ջ�


	 VC_SLVC_PARAMETER.fTestKp = 0.01;      //������ʶ������Kp
	 VC_SLVC_PARAMETER.fTestKi = 0.0004;    //������ʶ������Ki

	 CNT_FR_VALUE = * pCsvParamCNT_FR_VALUE;//�첽��ת�ؼ�����������
	 if(CNT_FR_VALUE<1)
		CNT_FR_VALUE=1;

	 VC_SLVC_PARAMETER.fSptestFrmin = 0.2;  //ʸ������ת�ٹ��ƻ��м�Ƶ���趨ֵ

	 VC_SLVC_PARAMETER.fCutFre_dc = 0.01;
	 VC_SLVC_PARAMETER.fCutFre_sw = 5.0;

	 VC_SLVC_PARAMETER.pfnVccontrolclear(&VC_SLVC_PARAMETER);  //ʸ�����Ʊ������㣬Ŀǰû���ã���ʱ�����š�
	 VC_SLVC_PARAMETER.pfnVccontrolinit(&VC_SLVC_PARAMETER);   //ʸ�����Ƴ�ʼ��

     uInterCount = 0;	
     uSoftStartCount = 0;

	 uDirCount=4348;
	 uDirCountMax=0.0; 
	 SpeedTest.fFrRefstop = VC_SLVC_PARAMETER.fFrRefFly;   //�����Էɳ�����Ƶ�ʽ��и�ֵ�������ת���𶯷�ʽѡ���ͻ������
}

void fnInitVCinput_inter(void)
{
  /*=============================ʸ�������ٶȱջ���������============================*/
	VC_SLVC_PARAMETER.fSpdKpmax_VC = 25.0;//* pCsvParamVCSpeedKpMAX;  //3.0;         //���ٶȱ�����ʸ�������ٶȱջ�Kp���ֵ
    VC_SLVC_PARAMETER.fSpdKpmax_SLVC = 10.0;//* pCsvParamSLVCSpeedKpMAX; //2.0;       //���ٶȱ�����ʸ�������ٶȱջ�Kp���ֵ
    VC_SLVC_PARAMETER.fSpdKpmin_VC = 25;//* pCsvParamVCSpeedKpMIN;  //2.0;         //���ٶȱ�����ʸ�������ٶȱջ�Kp��Сֵ
    VC_SLVC_PARAMETER.fSpdKpmin_SLVC = 10.0;//* pCsvParamSLVCSpeedKpMIN; //2.0;       //���ٶȱ�����ʸ�������ٶȱջ�Kp��Сֵ
    VC_SLVC_PARAMETER.fSpdKi = * pCsvParamSpeedLoopKi; //0.1;               //ʸ�������ٶȱջ�Ki
	VC_SLVC_PARAMETER.fSpdLw = * pCsvParamSpeedLOutMin; // -0.1;              //ʸ�������ٶȱջ������Сֵ����
    VC_SLVC_PARAMETER.fSpdUp = * pCsvParamSpeedLOutMax; // 0.1;               //ʸ�������ٶȱջ�������ֵ����

/*=============================ʸ�����Ƶ����ջ���������============================*/
	VC_SLVC_PARAMETER.fCurKp = * pCsvParamCurrentKp;//0.2;               //ʸ�����Ƶ����ջ�Kp
	VC_SLVC_PARAMETER.fCurKi = * pCsvParamCurrentKi;//0.04;              //ʸ�����Ƶ����ջ�Ki

/*===========================ʸ������ת�Ӵ����ջ���������============================*/
	VC_SLVC_PARAMETER.fPhrLw = * pCsvParamRotorFluxOutMin; //-0.3;              //ʸ������ת�Ӵ����ջ������Сֵ����
    VC_SLVC_PARAMETER.fPhrUp = * pCsvParamRotorFluxOutMax; //0.3;               //ʸ������ת�Ӵ����ջ�������ֵ����
	VC_SLVC_PARAMETER.fPhrRef = * pCsvParamRotorFluxGiven; //0.92;             //ʸ������ת�Ӵ�������ֵ

/*========================== ʸ������ת�ٹ��Ʊջ���������============================*/
	VC_SLVC_PARAMETER.fSptestKp = * pCsvParamSpeedEstKp;//1.0;//1.0;            //ʸ������ת�ٹ��Ʊջ�Kp
	VC_SLVC_PARAMETER.fSptestKimin = * pCsvParamSpeedEstKiMIN;   //0.001;        //ʸ������ת�ٹ��Ʊջ�Ki��Сֵ
	VC_SLVC_PARAMETER.fSptestKimid = * pCsvParamSpeedEstKiMID;   //0.08;         //ʸ������ת�ٹ��Ʊջ�Ki�м�ֵ 0.1;
	VC_SLVC_PARAMETER.fSptestKimax = * pCsvParamSpeedEstKiMAX;//0.08;         //ʸ������ת�ٹ��Ʊջ�Ki���ֵ 0.1
}

void fnInitInterg_Encode(void)
{
	 Interg_Vector.fKs = 1.0;
	 Interg_Vector.fKp = 314.15926;
	 Interg_Vector.fTs = PeriodTime;
	 Interg_Vector.fFlag = 1;
	 Interg_Vector.fUpLmt = 30000.0;
	 Interg_Vector.fLwLmt = -30000.0;

	 Interg_Vector.fIn = 0.0;
     Interg_Vector.fInformer = 0.0;
     Interg_Vector.fOutformer = 0.0;
     Interg_Vector.fOut = 0.0;
}



