//===========================================================================
//
// �ļ���:  SysCtl_AnalogProcess.c
//
// ��;:   	ģ��������
//
//===========================================================================
#include "SysCtl_AllHeaders.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "DSP2833x_Device.h"

#define LowVoltTest  0
//==== Ƭ��RAM ====================================
#pragma CODE_SECTION(fnAISample, "ramfuncs")

#if LowVoltTest
float32 fUdcTest = 400.0;
#endif

/***********************************************************
//�������ƣ�fnAISample
//�������ܣ�AD��������
//�����������ṹ��ָ��TypeAnalogInput *p
************************************************************/
void fnAISample(TypeAnalogInput *p)
{
//	float32 fLVoltAB,fLVoltBC;
	Uint16 CounterTemp = 0;                          //ѭ������
                                                  //
	Uint16 *pADResult = (Uint16*)&AdcRegs.ADCRESULT0;//Ƭ��AD����Ĵ���ָ��


	//
	//============= DSP Ƭ��AD ==================
	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;//����SEQ1
    //==============����DMA=============================
	DMACH1AddrConfig(DMADest1 + uDMA_Addr,DMASource1);
	StartDMACH1();

	uDMA_Addr += 0x80;
    if(uDMA_Addr >= 0x80000) //512K����
    {
    	uDMA_Addr = 0;
    }
	//==================================================
	while(AdcRegs.ADCST.bit.INT_SEQ1!=1)//��ת��״̬λ
    {}
	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;//����жϱ�־
                                    //
	AdcRegs.ADCST.bit.INT_SEQ2_CLR = 1;//����жϱ�־


//===��ȡDSP AD��ģ�����ֵ

	for(CounterTemp = 0;CounterTemp < 8;CounterTemp++)
	{
	  p->iSysADResult[CounterTemp] = (*(pADResult + CounterTemp)>>4);
	}

//	 p->fADResult[0] = ((p->iSysADResult[0] ) * 0.001221) * 96.154 - 239.02; // �̷ɵ��Ӹ���
	 p->fADResult[0] = ((p->iSysADResult[0] ) * 0.001221) * 24.0 - 60; // ����10kW ����A
	 p->fADResult[2] = ((p->iSysADResult[1] ) * 0.001221) * 24.0 - 60; // ����10kW ����C
	 p->fADResult[1] = -(p->fADResult[0] + p->fADResult[2]); // ����10kW ����B
//	 p->fADResult[2] = ((p->iSysADResult[2] ) * 0.0009768 - 2.0) * 304.60; // �̷ɵ��Ӹ���
//	 p->fADResult[3] = ((p->iSysADResult[3] ) * 0.0009768 - 2.0) * 304.60; // �̷ɵ��Ӹ���
//	 p->fADResult[4] = ((p->iSysADResult[4] ) * 0.0009768 - 2.0) * 304.60; // �̷ɵ��Ӹ���
	 p->fADResult[3] = ((p->iSysADResult[2] ) * 0.0009768 - 2.0) * 500.125 *1.1; // ����10kW ��ѹA
	 p->fADResult[4] = ((p->iSysADResult[3] ) * 0.0009768 - 2.0) * 500.125 *1.1; // ����10kW ��ѹB
	 p->fADResult[5] = ((p->iSysADResult[4] ) * 0.0009768 - 2.0) * 500.125 *1.1; // ����10kW ��ѹC

	 //line[0] = p->fADResult[2] - p->fADResult[3];


//	 p->fADResult[5] = (p->iSysADResult[5] * 0.0004884) * 503.02 - 1.307; // �̷ɵ��Ӹ���

	 p->fADResult[6] = (p->iSysADResult[5] * 0.0004884) * 500.125 + 10; // ����10kW ֱ��

	 p->fADResult[7] = (p->iSysADResult[6] * 0.001221);  //����10kW NTC1
	 p->fADResult[8] = (p->iSysADResult[7] * 0.001221);  //����10kW NTC2
/*
 for(CounterTemp = 0;CounterTemp < 8;CounterTemp++)
  {
//	if(CounterTemp == 0 || CounterTemp == 1)
//	{
//	  p->iSysADResult[CounterTemp] = (*(pADResult + CounterTemp)>>4) - 1365;//100A��Ƶ��Ƶ���������0A��Ӧ��DSPΪ1V,��DSP��ΧΪ0~2V��
//	  p->fADResult_Offset[CounterTemp] = -0.0007326 * ((float32)p->iSysADResult[CounterTemp]) * SysSamScaParameter.fSysSamValue[CounterTemp];
//	}
//	else if(CounterTemp == 2 || CounterTemp == 3 || CounterTemp == 4)
//	{
//	  p->iSysADResult[CounterTemp] = (*(pADResult + CounterTemp)>>4) - 2048;
//	  p->fADResult_Offset[CounterTemp] = KAnalog * ((float32)p->iSysADResult[CounterTemp]) * SysSamScaParameter.fSysSamValue[CounterTemp];
//	}
//	else if(CounterTemp == 5)
//	{
//	  p->iSysADResult[CounterTemp] = (*(pADResult + CounterTemp)>>4);
//	  p->fADResult_Offset[CounterTemp] = KAnalog * ((float32)p->iSysADResult[CounterTemp]) * SysSamScaParameter.fSysSamValue[CounterTemp];//
//	}
//
//	p->uADResultAnaIn[CounterTemp] = (*(pADResult + CounterTemp)>>4);
//
//	//======== ��Ư���ʵ��ֵ ====
//	p->fADResult_Offseted[CounterTemp] = p->fADResult_Offset[CounterTemp];
	p->iSysADResult[CounterTemp] = (*(pADResult + CounterTemp)>>4);
  }
 AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;//��λSEQ


	//============ ����ͨ�� =============
	//IU-->ADCINA0;    	IW-->ADCINB0;
	//VU-->ADCINA1;    	VV-->ADCINB1;
	//VW-->ADCINA2;    	VDC-->ADCINB2;
	//NTC1-->ADCINA3;   NTC2-->ADCINB3;
    p->fLVoltAB = p->fADResult_Offseted[2]-p->fADResult_Offseted[3];
    p->fLVoltBC = p->fADResult_Offseted[3]-p->fADResult_Offseted[4];

   //��������
 	p->fADResult[0] = p->fADResult_Offseted[0];  //Iu
 	p->fADResult[1] = -(p->fADResult_Offseted[0] + p->fADResult_Offseted[1]); //Iv
 	p->fADResult[2] = p->fADResult_Offseted[1];  //Iw
 	//������ѹ

 	p->fADResult[3] = p->fADResult_Offseted[2]; //Uu
 	p->fADResult[4] = p->fADResult_Offseted[3]; //Uv
 	p->fADResult[5] = p->fADResult_Offseted[4]; //Uw

// 	p->fADResult[3] = D2By3 * (p->fLVoltAB + 0.5 * p->fLVoltBC ); //Uu
// 	p->fADResult[4] = D2By3 * (-0.5 * p->fLVoltAB + 0.5 * p->fLVoltBC); //Uv
// 	p->fADResult[5] = -(p->fADResult[3] + p->fADResult[4]); //Uw
// 	//ֱ����ѹ
 	p->fADResult[6] = p->fADResult_Offseted[5]; //Vdc  ʵ��ֵ
#if LowVoltTest
 	p->fADResult[6] = fUdcTest;
#endif
*/

 	if(*pARMParamRdFlag == 0xce)
 	{
 	 SysSamDSPtoARM.fSamDSPtoARMIu = p->fADResult[0];
 	 SysSamDSPtoARM.fSamDSPtoARMIv = p->fADResult[1];
 	 SysSamDSPtoARM.fSamDSPtoARMIw = p->fADResult[2];

// 	 if(SysMoore.SysStateNew==SystemRun)
// 	 {
 	 	SysSamDSPtoARM.fSamDSPtoARMUu = p->fADResult[3];
 	 	SysSamDSPtoARM.fSamDSPtoARMUv = p->fADResult[4];
 	 	SysSamDSPtoARM.fSamDSPtoARMUw = p->fADResult[5];
// 	 }
// 	 else
// 	 {
//   	    SysSamDSPtoARM.fSamDSPtoARMUu = 0.0;
// 	    SysSamDSPtoARM.fSamDSPtoARMUv = 0.0;
// 	    SysSamDSPtoARM.fSamDSPtoARMUw = 0.0;
// 	 }

 	 SysSamDSPtoARM.fSamDSPtoARMUdc = p->fADResult[6];
 	}

  	if((SysMoore.SysStateNew == SystemReady) && (SysSampOffset.uSampleOffsetEn == TRUE))
  	{
       SysSampOffset.pfnSysOffsetParameterCal(&SysSampOffset);//����ϵͳ��Ư                                                                //
  	}
}
/***********************************************************
//�������ƣ�fnParaUpdateSysSamScaParameter
//�������ܣ�����ͨ�����������趨
//������������
************************************************************/

void fnParaUpdateSysSamScaParameter(void)
{

 Uint16 uLoopNum;

 SysSamScaParameter.fSysSamOutCurrent = *pCsvParamSamOutCurrent;//��������DSP 3V��Ӧ��������A

 SysSamScaParameter.fSysSamNTC1 = *pCsvParamSamNTC1;//NTC1 DSP 3V��Ӧ����������ֹ����ŷķ
 SysSamScaParameter.fSysSamNTC2 = *pCsvParamSamNTC2;//NTC2 DSP 3V��Ӧ����������ֹ����ŷķ

 SysSamScaParameter.fSysSamOutVoltage = *pCsvParamSamOutVoltage;//������ѹDSP 3V��Ӧ��ѹ����V
  
 SysSamScaParameter.fSysSamDCVoltage = *pCsvParamSamDCVoltage;//ֱ����ѹ����DSP 3V��Ӧ���ĸ�ߵ�ѹ����V


 if(SysBaseValue.fCurrBaseValue == 0.0)//Ϊ�����ĸΪ0
  SysSamScaParameter.fSysSamValue[0] = 0.0;
 else
  SysSamScaParameter.fSysSamValue[0] = SysSamScaParameter.fSysSamOutCurrent /SysBaseValue.fCurrBaseValue;

 SysSamScaParameter.fSysSamValue[1] = SysSamScaParameter.fSysSamValue[0];

 if((SysBaseValue.fVoltBaseValue) == 0.0)//Ϊ�����ĸΪ0
  SysSamScaParameter.fSysSamValue[2] = 0.0;
 else
  SysSamScaParameter.fSysSamValue[2] =  SysSamScaParameter.fSysSamOutVoltage / SysBaseValue.fVoltBaseValue;   //

 SysSamScaParameter.fSysSamValue[4] = SysSamScaParameter.fSysSamValue[3] = SysSamScaParameter.fSysSamValue[2];


 SysSamScaParameter.fSysSamValue[5] = 0.5 * SysSamScaParameter.fSysSamDCVoltage;//DSP 0~3V��Ӧĸ�ߵ�ѹ0~���ֵ

 for(uLoopNum = 0;uLoopNum < 8;uLoopNum ++)
 {
  //fnVarCopyToRam(sInComm.DSP_RAM,&SysSamScaParameter.fSysSamValue[uLoopNum],(BaseAddr_SysSamVal + (uLoopNum << 1)));// 
 }

}

void fnSysBaseValueCal(TypeSysBaseValue *p)
{
 float32 Temp1,Temp2;//
                     //
 p->fVoltBaseValueGrid = SQRT2By3 * SysRatedParameter.fVFDInputVolatge;	                 	                 
 //====��ѹ��ֵ====
 p->fVoltBaseValue = SQRT2By3 * SysRatedParameter.fMotorRatedVoltage;
 	 	 
 //====ת�ٻ�ֵ������====
 p->fSpeedBaseValue = PI2 * SysRatedParameter.fMotorRatedFre;
 	 	 
 //====������ֵ====                                                       
 p->fCurrBaseValue = SQRT2By3 * SysRatedParameter.fMotorRatedPower * 1000.0 / SysRatedParameter.fMotorRatedVoltage;		
  	 
 //====ϵͳ�ǶȻ�ֵ====
 p->fThetaBaseValue = PI2;	 
 	 
 //====���ʻ�ֵ(3/2) * Vbase * Ibase====
 p->fPowerBaseValue = 1.5 * p->fVoltBaseValue * p->fCurrBaseValue;
  	 
 //====ϵͳ�迹��ֵUbase/Ibase====
 p->fZBaseValue = p->fVoltBaseValue/p->fCurrBaseValue;
// ϵͳ���ɻ�ֵ  added by yp 20180131
 p->fYBaseValue = 1/p->fZBaseValue;
	 	 
 //====ϵͳ��л�ֵ====
 p->fLBaseValue = p->fVoltBaseValue/(p->fSpeedBaseValue * p->fCurrBaseValue);
	 	 
 //====ϵͳ������ֵ====
 p->fPhirBaseValue = p->fVoltBaseValue/p->fSpeedBaseValue;
	 	 
 //====��е�ǶȻ�ֵ====
 p->fOmegBaseValue = SysRatedParameter.fMotorRateSpeed * KOmegBase;
	 
 //====ϵͳת�ػ�ֵ====
 p->fTeBaseValue = p->fPowerBaseValue/p->fOmegBaseValue;
	 
 //====ϵͳת��������ֵ====
 Temp1 = POW2(SysRatedParameter.fMotorPoleNum);//
                                               //	 
 Temp2 = POW3(p->fSpeedBaseValue);//
                                  //
 p->fJBaseValue = (Temp1 * p->fPowerBaseValue)/Temp2;
	 
 //====ϵͳĦ��ϵ����ֵ====
 p->fFBaseValue = p->fTeBaseValue/p->fOmegBaseValue;
}

/***********************************************************
//�������ƣ�fnSysOffsetInit
//�������ܣ���Ư��ʼ��
//�����������ṹ��ָ��TypeSysOffsetParameter *p
************************************************************/
void fnSysOffsetInit(TypeSysOffsetParameter *p)
{
	Uint16 i;

	p->uOffsetCounter = 0;//

	for(i=0;i<9;i++)
	{
		p->fOffsetValue[i] = *(pOffsetRam+i);
		p->fOffsetAdd[i] = 0;
	}
}

/***********************************************************
//�������ƣ�fnSysOffsetParameterCal
//�������ܣ���Ư����
//�����������ṹ��ָ��TypeSysOffsetParameter *p
************************************************************/
void fnSysOffsetParameterCal(TypeSysOffsetParameter *p)
{
	Uint32 CounterTemp;

	if(p->uOffsetCounter >= 25000)
	{
		for(CounterTemp = 0;CounterTemp < 9;CounterTemp++)
		{
			p->fOffsetValue[CounterTemp] = p->fOffsetAdd[CounterTemp] / 20000.0;
																			  //
			p->fOffsetAdd[CounterTemp] = 0.0;

			if(CounterTemp>1)
			{
				p->fOffsetUpValue[CounterTemp] = p->fOffsetValue[CounterTemp-1];
			}
			else
				p->fOffsetUpValue[CounterTemp] = p->fOffsetValue[CounterTemp];

			p->fOffsetUpValue[6] = 0.0;
			p->fOffsetUpValue[7] = 0.0;
			p->fOffsetUpValue[8] = 0.0;
			fnVarCopyToRam(sInComm.DSP_RAM,&p->fOffsetUpValue[CounterTemp],(BaseAddr_OffsetCal + (CounterTemp<<1)));//
																  //��Ư����ֵ     
		}
		
		p->uOffsetCounter = 0;
												 
	     p->uSampleOffsetEn = FALSE;
		 *(sInComm.DSP_RAM+926) = 0;
		 *(sInComm.DSP_RAM+927) = 0;
									  
	}
	else if(p->uOffsetCounter < 5000 )
	{
		p->uOffsetCounter++;
	}
	else
	{
		for(CounterTemp = 0;CounterTemp < 8;CounterTemp++)
		{
			p->fOffsetAdd[CounterTemp] += AnalogInput.fADResult_Offset[CounterTemp];
			p->fOffsetAdd[6] = 0.0;//ĸ�ߵ�ѹ��������Ư��ĸ�ߵ�ѹ�ڴ���ʱ��ֵ
			p->fOffsetAdd[7] = 0.0;//NTC1�������費������Ư���������費Ϊ0
			p->fOffsetAdd[8] = 0.0;//NTC2�������費������Ư���������費Ϊ0
		}
		p->uOffsetCounter++;
	}  
}

//===========================================================================
// No more.
//===========================================================================

