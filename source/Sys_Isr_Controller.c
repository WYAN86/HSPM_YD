
/*
//===========================================================================
//
// �ļ���:    SysCtl_ISR.c
//
// ��;:   	  ϵͳ���ж�
//
//===========================================================================
*/
#include "DSP2833x_Device.h"     // Headerfile Include File
#include "DSP2833x_GlobalPrototypes.h"
#include "SysCtl_AllHeaders.h"

extern void DATAPeriodDSPtoARM(void);
extern void DATAPeriodARMtoDSP(void);
extern void SysCurProtect(void);
//extern PMSM_Control PMSM;

/***********************************************************
//�������ƣ�SysCtl_ISR
//�������ܣ�ϵͳ���жϴ���
//������������
************************************************************/
__interrupt	void SysCtl_ISR(void)
{
	StartCpuTimer0();
    CpuTimer0Regs.TCR.bit.TRB = 1;
	
    DATAPeriodARMtoDSP();    //ARM��DSP���������ݴ���
	//=====================AD����=======================================
	//
    AnalogInput.pfnAISample(&AnalogInput); //ȡAD�������

    SysCurProtect();//ϵͳ��������

//=======================�㷨================================

	 if(SysMoore.SysStateNew == SystemRun)
	 {

	   switch(SysEnviConfg.uVFDLoadType)
	   {
	     case AsynMotor:   //�첽���
	     {
	  	   if((SysEnviConfg.uConStrat == PGVVVF)||(SysEnviConfg.uConStrat == NPGVVVF))//VVVF����
	  	   {
	  		 SysVVVFCtrl.pfnCalc(&SysVVVFCtrl);
		   }
	  	   else if(SysEnviConfg.uConStrat == VC)           //�и�ʸ��
	  	   {

	  	   }
	  	   else if(SysEnviConfg.uConStrat == SLVC)        //�޸�ʸ��
	  	   {
	  		 fnVectorCtrlInterface();
	  	   }
	    	 break;
	     }
	     case SynMotor:    //ͬ�����
	     {
		   if((SysEnviConfg.uConStrat == PGVVVF)||(SysEnviConfg.uConStrat == NPGVVVF))  //VVVF����
		   {
			   //I_f control   Added by YP 20180119 || revised by SX 20180419
			   if(PMSM.fre >= 30)
			   {
				   PMSM.Observer(&PMSM);
			   }
			   PMSM.Ia = AnalogInput.fADResult[0]/PMSM.Cur_base;
			   PMSM.Ib = AnalogInput.fADResult[1]/PMSM.Cur_base;
			   PMSM.Ic = AnalogInput.fADResult[2]/PMSM.Cur_base;
			   PMSM.Vdc = AnalogInput.fADResult[6]/PMSM.Vol_base;
			   //PMSM.Ts = vDSP_GPWM_CARRIER[0]->Reg.CARRIER*0.02*fusToS * vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE;
			   PMSM.I_f_Calc(&PMSM);
			   PMSM.Uu = (Uint16)(PMSM.Ta * vDSP_GPWM_CARRIER[0]->Reg.CARRIER);//U���˰��ѹ			  												   //
			   PMSM.Uv = (Uint16)(PMSM.Tb * vDSP_GPWM_CARRIER[0]->Reg.CARRIER);//V���˰��ѹ
			   PMSM.Uw = (Uint16)(PMSM.Tc * vDSP_GPWM_CARRIER[0]->Reg.CARRIER);//W���˰��ѹ
			   InvModuWave(PMSM.Uu,PMSM.Uv,PMSM.Uw);
			   DEP_DSP_GPWM_ENABLE = 1;
		   }
		   else if(SysEnviConfg.uConStrat == VC)   //�и�ʸ��
		   {
			   PMSM.Swit(&PMSM);
			   PMSM.Observer(&PMSM);
			   PMSM.Ia = AnalogInput.fADResult[0]/PMSM.Cur_base;
			   PMSM.Ib = AnalogInput.fADResult[1]/PMSM.Cur_base;
			   PMSM.Ic = AnalogInput.fADResult[2]/PMSM.Cur_base;
			   PMSM.Vdc = AnalogInput.fADResult[6]/PMSM.Vol_base;
			   PMSM.I_f_Calc(&PMSM);
			   PMSM.Uu = (Uint16)(PMSM.Ta * vDSP_GPWM_CARRIER[0]->Reg.CARRIER);//U���˰��ѹ			  												   //
			   PMSM.Uv = (Uint16)(PMSM.Tb * vDSP_GPWM_CARRIER[0]->Reg.CARRIER);//V���˰��ѹ
			   PMSM.Uw = (Uint16)(PMSM.Tc * vDSP_GPWM_CARRIER[0]->Reg.CARRIER);//W���˰��ѹ
			   InvModuWave(PMSM.Uu,PMSM.Uv,PMSM.Uw);
			   DEP_DSP_GPWM_ENABLE = 1;
		   }
		   else if(SysEnviConfg.uConStrat == SLVC)  //�޸�ʸ��
		   {
			   //sensorless vector control   Added by YP 20180119 || revised by SX 20180419
			   PMSM.Observer(&PMSM);
			   PMSM.Ia = AnalogInput.fADResult[0]/PMSM.Cur_base;
			   PMSM.Ib = AnalogInput.fADResult[1]/PMSM.Cur_base;
			   PMSM.Ic = AnalogInput.fADResult[2]/PMSM.Cur_base;
			   PMSM.Vdc = AnalogInput.fADResult[6]/PMSM.Vol_base;
			   //PMSM.Ts = vDSP_GPWM_CARRIER[0]->Reg.CARRIER*0.02*fusToS * vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE;
			   PMSM.SLVC_Calc(&PMSM);
			   PMSM.Uu = (Uint16)(PMSM.Ta * vDSP_GPWM_CARRIER[0]->Reg.CARRIER);//U���˰��ѹ			  												   //
			   PMSM.Uv = (Uint16)(PMSM.Tb * vDSP_GPWM_CARRIER[0]->Reg.CARRIER);//V���˰��ѹ
			   PMSM.Uw = (Uint16)(PMSM.Tc * vDSP_GPWM_CARRIER[0]->Reg.CARRIER);//W���˰��ѹ
			   InvModuWave(PMSM.Uu,PMSM.Uv,PMSM.Uw);
			   DEP_DSP_GPWM_ENABLE = 1;
		   }
	    	 break;
	     }
	     case Reactor:   //�翹������
	     {
	    	 SysConTest.pfnCalc(&SysConTest);
	    	 break;
	     }
	     default:break;
	   }
	   //commented by YP 20180119 because SVPWM is used instead of SPWM
		// SysVoltBase.pfnCalc(&SysVoltBase);  //ϵͳ��ѹ�������㣬�㷨ͳһ�ӿ�
	 }
	 else
	 {
		 SysConTest.fVoltageAmpSet = 0;
		 SysConTest.fVoltageAmp_temp = 0;
		 SysConTest.fVoltageAmpSetLast = 0;

		 DEP_DSP_GPWM_ENABLE = 0;
	 }

	 if(SysEnviConfg.uVFDLoadType == Reactor)
		 	 *pCsvParamVol_ManualSet = SysConTest.fVoltageAmpSet;
//===================�㷨����=============================================

	 DATAPeriodDSPtoARM();//DSP�����������ϴ�
	 if(SysMoore.SysStateNew != SysErr)
	 {
	    fnVarScopeAssign();//���ʾ�������ݸ���
	 }

  	StopCpuTimer0();
	fTimeCount = (CpuTimer0Regs.PRD.all - CpuTimer0Regs.TIM.all)*0.0133333;  //�����ж�ִ��ʱ��

	PieCtrlRegs.PIEACK.bit.ACK1 = 1;//
}

__interrupt	void local_DINTCH1_ISR(void)
{
	//int i;
	// To receive more interrupts from this PIE group, acknowledge this interrupt
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;
}

__interrupt void epwm1_isr(void)
{
   //EPwm1TimerIntCount++;

   // Clear INT flag for this timer
   EPwm1Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

__interrupt void epwm2_isr(void)
{
   //EPwm2TimerIntCount++;

   // Clear INT flag for this timer
   EPwm2Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

__interrupt void epwm3_isr(void)
{
   //EPwm3TimerIntCount++;

   // Clear INT flag for this timer
   EPwm3Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

__interrupt void epwm4_isr(void)
{
   //EPwm4TimerIntCount++;

   // Clear INT flag for this timer
   EPwm4Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
/***********************************************************
//�������ƣ�DATAPeriodDSPtoARM
//�������ܣ�����ϵͳ���������ݴ��� DSP->ARM
//������������
************************************************************/
void DATAPeriodDSPtoARM(void)
{
	FltWord_DSPtoARM = SysErrIndexReg.all;
 	if(*pARMParamRdFlag == 0xce)
	MemCopy((Uint16*)&SysSamDSPtoARM.fSamDSPtoARMIu,(Uint16*)&SysSamDSPtoARM.fSamDSPtoARMIu + 18,(Uint16*)&DMABuf1[80]);//�������ݴ���
 	sInComm.pfnWaveDisplay(&sInComm);//ʵʱ�������ݴ���
	DAC_DSPtoARM1 = DAOut.fDA_DataCh1;//DAͨ��1���ݴ���
	DAC_DSPtoARM2 = DAOut.fDA_DataCh2;//DAͨ��2���ݴ���
}
/***********************************************************
//�������ƣ�DATAPeriodARMtoDSP
//�������ܣ�����ϵͳ���������ݴ��� ARM->DSP
//������������
************************************************************/
void DATAPeriodARMtoDSP(void)
{
    SysMoore.SysStateNew = (TypeSysMooreState)StMach_ARMtoDSP;//��ARM��״̬��
    SysVVVFCtrl.fFreqRefGive = FreqRef_ARMtoDSP;  //��ARM�������Ƶ��
}
/***********************************************************
//�������ƣ�SysCurProtect
//�������ܣ�ϵͳ˲ʱ��������
//������������
************************************************************/
void SysCurProtect(void)
{
    if(SysMoore.SysStateNew == SystemRun && \
    		(AnalogInput.fADResult[0] > SysProParamReg.fOCProtect || \
    		 AnalogInput.fADResult[1] > SysProParamReg.fOCProtect || \
			 AnalogInput.fADResult[2] > SysProParamReg.fOCProtect ))
    {
    	DEP_DSP_GPWM_ENABLE = 0;
    	//SysMoore.SysStateNew = SysErr;
    	SysErrIndexReg.bit.SysHFaultFlag = TRUE;
    }
}
//===========================================================================
// No more.
//===========================================================================

