#include "SysCtl_AllHeaders.h"
/***********************************************************
//�������ƣ�fnVVVFCtrlInterface
//�������ܣ�VVVF�����㷨���㺯����VF�������߼���
//������������
************************************************************/
void fnVVVFCtrlInterface(TypeSysVVVFCal *p)
{
	float Freq_Abs,VfSlope1,VfSlope2,VfSlope3,fDetaTheta;

	FreqEn_DSPtoARM = 0xc3;

	p->fFreqRefGive = FreqRef_ARMtoDSP;  //��ARM�������Ƶ��
   //�Ƕȼ���
	 fDetaTheta = p->fFreqRefGive * SysRatedParameter.fMotorRatedFre * SysVVVFCtrl.fVFPhseCoffic;//���ڽǶȱ仯
	                                                                     //
	 p->fTheta_base += fDetaTheta;//��λ����
	                              //
	 if(p->fTheta_base > PI2)//��ת����2pi
	                         //
	    p->fTheta_base -= PI2;//
		                      //
	 else if(p->fTheta_base < N_PI2)//��תС��-2pi
	                                //
	    p->fTheta_base += PI2;//

  //��ֵ����
    Freq_Abs = fabs(p->fFreqRefGive);

	if (Freq_Abs <= p->fFreqRefMin)
        p->fVoltageAmp = p->fVoltRefMin;
	else if ((Freq_Abs > p->fFreqRefMin)&&(Freq_Abs <= p->fFreqRefPoint1))
       {

        VfSlope1 = (p->fVoltRefPoint1 - p->fVoltRefMin)/(p->fFreqRefPoint1 - p->fFreqRefMin);

        p->fVoltageAmp= p->fVoltRefMin + VfSlope1*(Freq_Abs - p->fFreqRefMin);
       }
	else if ((Freq_Abs > p->fFreqRefPoint1)&&(Freq_Abs <= p->fFreqRefPoint2))
       {
        VfSlope2 = (p->fVoltRefPoint2 - p->fVoltRefPoint1)/(p->fFreqRefPoint2 - p->fFreqRefPoint1);
        p->fVoltageAmp = p->fVoltRefPoint1 + VfSlope2*(Freq_Abs - p->fFreqRefPoint1);
       }
	else if ((Freq_Abs > p->fFreqRefPoint2)&&(Freq_Abs <= p->fFreqRefBase))
       {

        VfSlope3 = (p->fVoltRefMax - p->fVoltRefPoint2)/(p->fFreqRefBase-p->fFreqRefPoint2);

        p->fVoltageAmp = p->fVoltRefPoint2 + VfSlope3*(Freq_Abs - p->fFreqRefPoint2);
       }
    else if (Freq_Abs >= p->fFreqRefBase)
        p->fVoltageAmp = p->fVoltRefMax;
    else
      {;}
	//���Ʋ����
	   SysVoltBase.fUu_base =  p->fVoltageAmp * sin(p->fTheta_base);//U���ѹ
		                                            //
	   SysVoltBase.fUv_base =  p->fVoltageAmp * sin(p->fTheta_base + f4_D_3PI);//V���ѹ
		                                                       //
	   SysVoltBase.fUw_base =  p->fVoltageAmp * sin(p->fTheta_base + f2_D_3PI);//W���ѹ
}

/***********************************************************
//�������ƣ�fnUnitTestingInterface
//�������ܣ��翹�������㷨���㺯��
//������������
************************************************************/
void fnUnitTestingInterface(TypeSysConTestParam *p)
{
 float32 fDetaTheta = 0.0;

 SysRatedParameter.fMotorRatedFre = *pCsvParamMotorRatedFre;         //Ƶ�ʹ̶�Ϊ50Hz
   fDetaTheta = SysRatedParameter.fMotorRatedFre * SysVVVFCtrl.fVFPhseCoffic;// PI2 * PeriodTimeus * 0.000001;
                                                                     //
  p->fTheta_base += fDetaTheta;//��λ����
                              //
 if(p->fTheta_base > PI2)//��ת����2pi
                         //
	 p->fTheta_base -= PI2;//
	                      //
 else if(p->fTheta_base < N_PI2)//��תС��-2pi
                                //
	 p->fTheta_base += PI2;//
	                      //



   //if(SysMoore.SysStateNew == SystemRun)
   {
	   if(p->fVoltageAmp_temp == p->fVoltageAmpSet)
	   {
		   p->fVoltageAmpSet =  *pCsvParamVol_ManualSet;        ///�����ѹ����;
	   }

	   if(fabs(p->fVoltageAmpSet - p->fVoltageAmpSetLast) > 0.1001)
	   {
		   p->fVoltageAmpSet = p->fVoltageAmpSetLast;
	   }

	   p->fVoltageAmpSetLast = p->fVoltageAmpSet;
   }


   if(p->fVoltageAmp_temp < p->fVoltageAmpSet)
	   p->fVoltageAmp_temp = p->fVoltageAmp_temp + 0.000002;
   else if(p->fVoltageAmp_temp > p->fVoltageAmpSet + 0.000003)
	   p->fVoltageAmp_temp = p->fVoltageAmp_temp - 0.000002;
   else
	   p->fVoltageAmp_temp = p->fVoltageAmpSet;


   SysVoltBase.fUu_base =  p->fVoltageAmp_temp * sin(p->fTheta_base);//U���ѹ
	                                            //
   SysVoltBase.fUv_base =  p->fVoltageAmp_temp * sin(p->fTheta_base + f4_D_3PI);//V���ѹ
	                                                       //
   SysVoltBase.fUw_base =  p->fVoltageAmp_temp * sin(p->fTheta_base + f2_D_3PI);//W���ѹ

}
/***********************************************************
//�������ƣ�fnVVVFVarReset
//�������ܣ�VVVF�����㷨��λ����
//������������
************************************************************/
void fnVVVFVarReset(TypeSysVVVFCal *p)
{

}
/***********************************************************
//�������ƣ�fnVVVFVarInit
//�������ܣ�VVVF�����㷨��ʼ������
//������������
************************************************************/
void fnVVVFVarInit(TypeSysVVVFCal *p)
{
	float32 fdata;
	fdata = vDSP_GPWM_CARRIER[0]->Reg.CARRIER * 0.001; //����us
	p->fVFPhseCoffic =  PI2 * 0.000001 * 20 * fdata;

	//SysVoltBase.uCarrCount = vDSP_GPWM_CARRIER[0]->Reg.CARRIER;
}


