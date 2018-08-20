
/*
//===========================================================================
//
// �ļ���:    SysCtl_Moore.c
//
// ��;:   	  ϵͳ״̬��
//
// ������     fnSysMooreReset()     //ϵͳ
//
//            fnSysMooreOut()       //״̬���
//
//===========================================================================
*/
#include "DSP2833x_Device.h"
#include "SysCtl_AllHeaders.h"
#include "DSP2833x_GlobalPrototypes.h"
//#pragma DATA_SECTION(HMIBuffer, "XDATARAM")
  
void fnSystemReadyParam(void);
void fnSystemRUNParam(void);
void fnVarCopyToRam(Uint16 *HeadAddr,float32 *pVarAddr,Uint16 AddrBias);

extern void fnSystemResetParam(void);
extern void fnSysRatedParameter(void);
//extern void fnParaUpdateHVOFF_SysSamScaParameter(void);
extern PIREG PhrPI;

/***********************************************************
//�������ƣ�fnSysFaultReset
//�������ܣ����ϸ�λ���ڲ�������λ
//������������
************************************************************/
void fnSysFaultReset(void)
{
   SysErrIndexReg.all = 0;
   ARMFaultReg.all = 0;
   DSPFaultCodeReg.all = 0;
}

/***********************************************************
//�������ƣ�fnSysMooreCal
//�������ܣ�״ִ̬��
//�����������ṹ��ָ��TypeSysMoore *p
************************************************************/
void fnSysMooreCal(TypeSysMoore *p)
{
//	Uint32 uState;
  SysCtlReg.all = (Uint16)*pCsvParamSysCtlWord;
  float32 fdata;
  Uint32  udata;
  //float32  udata;
  float32  fARMInterMultiple;
  Uint16   uCarrier;
  Uint16   fDspFiberChopEnable;
 //   dsp_to_arm_fault = DSPFaultCodeReg.all;
//	dsp_to_arm_state = p->SysStateNew;
	if(SysErrIndexReg.bit.SysHFaultFlag == TRUE)//ϵͳ�ع���
    {
//		p->SysStateNew = SysErr;//ϵͳ����״̬

		DEP_DSP_GPWM_ENABLE = 0;

		if(SysCtlReg.bit.ResetInstr == TRUE)//ϵͳ��λ,��ЧӲ����λ
		{
			fnSysFaultReset();
			fnSystemResetParam();
			SysErrIndexReg.bit.SysHFaultFlag = FALSE;
			//p->SysStateNew = SystemReady;

			SysCtlReg.bit.ResetInstr = FALSE;
			 *(sInComm.DSP_RAM+536) = 0;
			 *(sInComm.DSP_RAM+537) = 0;
		}

    }
	else//�ǹ���״̬�߼��л�
    {

		if(p->SysStateNew==SystemRun)
		{
			fnSystemRUNParam();
		}
		else
		{
			DEP_DSP_GPWM_ENABLE = 0;
			fnSystemReadyParam();
		}

 	}

	//�ز�Ƶ���ϴ�
	//*pCsvCarrierFre = 50000.0 / vDSP_GPWM_CARRIER[0]->Reg.CARRIER;

	if(SysConTest.Enable)
	{
		SysConTest.Enable = 0; //20171124gai
		fARMInterMultiple = *pCsvARMInterMultiple;
		fDspFiberChopEnable = (Uint32)*pCsvDspFiberChopEnable;

		udata = (Uint32)*pCsvCarrierFre;
		//udata = (float32)*pCsvCarrierFre;

		if (udata== 0)
			uCarrier = 65530;   //50000 / 0.77k
		else if (udata== 1)
			uCarrier = 25000;   //50000 / 2k
		else if (udata== 2)
			uCarrier = 12500;   //4k
		else if (udata== 3)
			uCarrier = 8333;    //6k
		else if (udata== 4)
			uCarrier = 6250;    //8k
		else if (udata== 5)
			uCarrier = 5000;
		else if (udata== 6)
			uCarrier = 4167;
		else if (udata== 7)
			uCarrier = 3571;
		else if (udata== 8)
			uCarrier = 3125;
		else if (udata== 9)
			uCarrier = 2778;
		else if (udata== 10)
			uCarrier = 2500;
		else if (udata== 11)
			uCarrier = 2273;
		else if (udata== 12)
			uCarrier = 2083;
		else if (udata== 13)
			uCarrier = 1923;
		else if (udata== 14)
			uCarrier = 1786;
		else if (udata== 15)
			uCarrier = 1667;
		else if (udata== 16)
			 uCarrier = 1563;
		else if (udata== 17)
			 uCarrier = 1471;
		else if (udata== 18)
			uCarrier = 1389;
		else if (udata== 19)
			 uCarrier = 1316;
		else if (udata== 20)
			 uCarrier = 1250;
		else if (udata== 21)
			 uCarrier = 1190;
		else if (udata== 22)
			uCarrier = 1136;
		else if (udata== 23)
			uCarrier = 1087;
		else if (udata== 24)
			 uCarrier = 1042;
		else if (udata== 25)
			 uCarrier = 1000;
		else if (udata== 26)
			 uCarrier = 962;
		else if (udata== 27)
			 uCarrier = 926;
		else if (udata== 28)
			 uCarrier = 893;
		else if (udata== 29)
			uCarrier = 862;
		else if (udata== 30)
			 uCarrier = 833;
		else if (udata== 31)
			 uCarrier = 806;
		else if (udata== 32)
			uCarrier = 781;
		else if (udata== 33)
			 uCarrier = 758;
		else if (udata== 34)
			 uCarrier = 735;
		else if (udata== 35)
			 uCarrier = 714;
		else if (udata== 36)
			 uCarrier = 694;
		else if (udata== 37)
			 uCarrier = 676;
		else if (udata== 38)
			 uCarrier = 658;
		else if (udata== 39)
			 uCarrier = 641;
		else if (udata== 40)
			 uCarrier = 625;
		else if (udata== 41)
			 uCarrier = 610;
		else if (udata== 42)
			uCarrier = 595;
		else if (udata== 43)
			 uCarrier = 581;
		else if (udata== 44)
			uCarrier = 568;
		else if (udata== 45)
			uCarrier = 556;
		else if (udata== 46)
			 uCarrier = 543;
		else if (udata== 47)
			uCarrier = 532;
		else if (udata== 48)
			uCarrier = 521;
		else if (udata== 49)
			uCarrier = 510;
		else if (udata== 50)
			uCarrier = 500;
		else
			uCarrier = 25000;



		vDSP_GPWM_CARRIER[0]->Reg.CARRIER = uCarrier;
		vDSP_GPWM_CARRIER[2]->Reg.CARRIER = uCarrier;
		vDSP_GPWM_CARRIER[4]->Reg.CARRIER = uCarrier;
		vDSP_FIBER_CHOP->Reg.DSP_FIBER_CHOP_ENABLE = fDspFiberChopEnable;

		if (udata>=1 && udata<=10 )  //0.76k~20k
		{
			if ((fARMInterMultiple >= 1) && (fARMInterMultiple <= 5))
		        vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE = fARMInterMultiple; //luochonggai20171122
		}
		else if (udata>=11 && udata<=20 ) //22k~40k
		{
			if ((fARMInterMultiple >= 2) && (fARMInterMultiple <= 5))
				vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE = fARMInterMultiple;
			else if(vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE < 2)
				vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE = 2;
		}
		else if (udata>=21 && udata<=30 ) //42k~60k
		{
			if ((fARMInterMultiple >= 3) && (fARMInterMultiple <= 5))
				vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE = fARMInterMultiple;
			else if(vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE < 3)
				vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE = 3;
		}
		else if (udata>=31 && udata<=40 ) //62k~80k
		{
			if ((fARMInterMultiple >= 4) && (fARMInterMultiple <= 5))
				vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE = fARMInterMultiple;
			else if(vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE < 4)
				vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE = 4;
		}
		else if (udata>=41 && udata<=50 ) //82k~100k
		{
			vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE = 5;  //luochonggai20171122
		}
		else if(udata == 0)
		{
			vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE = 1;
		}


		fdata = uCarrier * 0.02 *  vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE; //����us��2PI/T
		SysVVVFCtrl.fVFPhseCoffic =  PI2 * 0.000001 * fdata;
		SysVoltBase.uCarrCount = uCarrier;

		ChopWave (&SysChoppedWave);

	}
	else
	{
		switch(vDSP_GPWM_CARRIER[0]->Reg.CARRIER)
		{
		case 65530:
			*pCsvCarrierFre = 0.38;
			 break;
		case 25000:
			*pCsvCarrierFre = 1;
			break;
		case 12500:
			*pCsvCarrierFre = 2;
			break;
		case 8333:
			*pCsvCarrierFre = 3;
			break;
		case 6250:
			*pCsvCarrierFre = 4;
			break;
		case 5000:
			*pCsvCarrierFre = 5;
			break;
		case 4167:
			*pCsvCarrierFre = 6;
			break;
		case 3571:
			*pCsvCarrierFre = 7;
			break;
		case 3125:
			*pCsvCarrierFre = 8;
			break;
		case 2778:
			*pCsvCarrierFre = 9;
			break;
		case 2500:
			*pCsvCarrierFre = 10;
			break;
		case 2273:
			*pCsvCarrierFre = 11;
			break;
		case 2083:
			*pCsvCarrierFre = 12;
			break;
        case 1923:
			*pCsvCarrierFre = 13;
			break;
		case 1786:
			*pCsvCarrierFre = 14;
			break;
		case 1667:
			*pCsvCarrierFre = 15;
			break;
		case 1563:
			*pCsvCarrierFre = 16;
			break;
		case 1471:
			*pCsvCarrierFre = 17;
			break;
		case 1389:
			*pCsvCarrierFre = 18;
			break;
		case 1316:
			*pCsvCarrierFre = 19;
			break;
		case 1250:
			*pCsvCarrierFre = 20;
			break;
		case 1190:
			*pCsvCarrierFre = 21;
			break;
		case 1136:
			*pCsvCarrierFre = 22;
			break;
		case 1087:
			*pCsvCarrierFre = 23;
			break;
		case 1042:
			*pCsvCarrierFre = 24;
			break;	
		case 1000:
			*pCsvCarrierFre = 25;
			break;
		case 962:
			*pCsvCarrierFre = 26;
			break;
        case 926:
			*pCsvCarrierFre = 27;
			break;
		case 893:
			*pCsvCarrierFre = 28;
			break;
		case 862:
			*pCsvCarrierFre = 29;
			break;
		case 833:
			*pCsvCarrierFre = 30;
			break;
		case 806:
			*pCsvCarrierFre = 31;
			break;
		case 781:
			*pCsvCarrierFre = 32;
			break;
		case 758:
			*pCsvCarrierFre = 33;
			break;
		case 735:
			*pCsvCarrierFre = 34;
			break;
		case 714:
			*pCsvCarrierFre = 35;
			break;
		case 694:
			*pCsvCarrierFre = 36;
			break;
		case 676:
			*pCsvCarrierFre = 37;
			break;
		case 658:
			*pCsvCarrierFre = 38;
			break;
		case 641:
			*pCsvCarrierFre = 39;
			break;
		case 625:
			*pCsvCarrierFre = 40;
			break;
		case 610:
			*pCsvCarrierFre = 41;
			break;
		case 595:
			*pCsvCarrierFre = 42;
			break;
		case 581:
			*pCsvCarrierFre = 43;
			break;
		case 568:
			*pCsvCarrierFre = 44;
			break;
		case 556:
			*pCsvCarrierFre = 45;
			break;
		case 543:
			*pCsvCarrierFre = 46;
			break;
		case 532:
			*pCsvCarrierFre = 47;
			break;
		case 521:
			*pCsvCarrierFre = 48;
			break;
		case 510:
			*pCsvCarrierFre = 49;
			break;
		case 500:
			*pCsvCarrierFre = 50;
			break;
		default:
			*pCsvCarrierFre = 0;
		}

		*pCsvChopwaveFre = 5000.0 / vDSP_GPWM_CARRIER[6]->Reg.CARRIER;
		*pCsvChopDutyCycle = (vDSP_GPWM_COMP[6]->all / *pCsvChopwaveFre)/5000;
	    *pCsvARMInterMultiple = vDSP_INT_MULTIPLE->Reg.DSP_MULTIPLE;
	    *pCsvDspFiberChopEnable = vDSP_FIBER_CHOP->Reg.DSP_FIBER_CHOP_ENABLE;//����ն��ʹ��

	}



}


/***********************************************************
//�������ƣ�fnSystemInitParam
//�������ܣ�������ʼ��
//������������
************************************************************/
void fnSystemInitParam(void)
{
	SysErrIndexReg.all = 0;
	ARMFaultReg.all = 0;
	DSPFaultCodeReg.all = 0;
	
	vDSP_GPWM_ENABLE->all = 0;

	SysSampOffset.SampOffsetOnce = 0;
	SysSampOffset.pfnSysOffsetInit(&SysSampOffset);
	SysVoltBase.pfnInit(&SysVoltBase);// ������ѹ�ӿڳ�ʼ��
	SysVVVFCtrl.pfnInit(&SysVVVFCtrl);// VVVF���Ƴ�ʼ��
	fnInitInterg_Encode();

	SysVVVFCtrl.fVFPhseCoffic =  0.0157; //lcgai20171127
	SysVoltBase.uCarrCount = 25000; //lcgai20171127
}
/***********************************************************
//�������ƣ�fnSystemResetParam
//�������ܣ�������λ
//������������
************************************************************/
void fnSystemResetParam(void)
{
	SysVoltBase.pfnReset(&SysVoltBase);// ������ѹ�ӿڸ�λ
	SysVVVFCtrl.pfnReset(&SysVVVFCtrl);// VVVF���Ʋ�����λ
}
/***********************************************************
//�������ƣ�fnSystemReadyParam
//�������ܣ�ϵͳ����״̬��������
//������������
************************************************************/
void fnSystemReadyParam(void)
{
  float32 fFreqStart = 0.0;
    FreqEn_DSPtoARM  = 0;
	fnSysRatedParameter();//���������
	
//	fnARMFaultDetec();//ARM����ϼ��


    SysBaseValue.pfnSysBaseValueCal(&SysBaseValue);//ϵͳ��ֵ����,SysCtl_Drive.c

    fnParaUpdateSysSamScaParameter();//��������ϵ������

	SysConTest.fVoltageAmp_temp = 0.0;//���翹�������ֵ���㡣

	SysCtlParameter.uStartMode = (Uint16)*pCsvParaStartMod; //���Ʒ�ʽ

	//===========��Ưʹ��============
	SysSampOffset.uSampleOffsetEn = (Uint16)*pCsvParaSampleOffset; //��Ưʹ��

	//===========���л��������趨============
	SysEnviConfg.uConRunType = (Uint16)*pCsvParaConRunType;
	//SysEnviConfg.uConStrat = (TypeSysControlStrat)*pCsvParaConStrategy;	//revised by SX 20180427
	SysEnviConfg.uVFDLoadType = (TypeSysVFDLoad)*pCsvParaVFDLoadType;

	//===========VF���߲����趨============
	fFreqStart = *pCsvParamFreqStart;
	SysVVVFCtrl.fFreqRefMin = fFreqStart/SysRatedParameter.fMotorRatedFre;
	SysVVVFCtrl.fVoltRefMin = *pCsvParamVF_VoltMin;
	SysVVVFCtrl.fFreqRefPoint1 = *pCsvParamVF_FreqPoint1;
	SysVVVFCtrl.fVoltRefPoint1 = *pCsvParamVF_VoltPoint1;
	SysVVVFCtrl.fFreqRefPoint2 = *pCsvParamVF_FreqPoint2;
	SysVVVFCtrl.fVoltRefPoint2 = *pCsvParamVF_VoltPoint2;
	SysVVVFCtrl.fFreqRefBase = *pCsvParamVF_FreqMax;
	SysVVVFCtrl.fVoltRefMax = *pCsvParamVF_VoltMax;

	//fnInitVCinput_off();  //Remarked by SX 20180508
	PMSM.Init_Ready(&PMSM);
	SysVoltBase.fUu_base =0.0;
	SysVoltBase.fUv_base =0.0;
	SysVoltBase.fUw_base =0.0;

	//===========���в�������============
	fnSystemRUNParam();
}
/***********************************************************
//�������ƣ�fnSystemReadyParam
//�������ܣ�ϵͳ����״̬��������
//������������
************************************************************/
void fnSystemRUNParam(void)
{
   SysCtlReg.all = (Uint16)*pCsvParamSysCtlWord;
   SysProParamReg.fOCProtect = *pCsvParamOCPrtVal;//����˲ʱ����ֵ
//	fnARMFaultDetec();

   SysEnviConfg.uConStrat = (TypeSysControlStrat)*pCsvParaConStrategy;		//Added by SX 20180427
   PMSM.Init_Run(&PMSM);		//Added by SX 20180508

   //���в���������HMIRAM
   fnVarCopyToRam(sInComm.DSP_RAM,&PMSM.Iq_ref,140);//          //ת�ص�������ֵ
   fnVarCopyToRam(sInComm.DSP_RAM,&PMSM.Iq,142);	      // ת�ص���ʵ��ֵ
   fnVarCopyToRam(sInComm.DSP_RAM,&PMSM.Id_ref,144);//		  //���ŵ�������ֵ  SpeedTest
   fnVarCopyToRam(sInComm.DSP_RAM,&PMSM.Id,146);	      // ���ŵ���ʵ��ֵ
   fnVarCopyToRam(sInComm.DSP_RAM,&fTimeCount,150);//		 //���ж�����ʱ�䣬revised by yp 20180131

/* remarked by sunxin 20180417
 *
   float spd_tmp;
   spd_tmp = PMSM.SpeedRef * 60 / PI2 / PMSM.p;
   fnVarCopyToRam(sInComm.DSP_RAM,&spd_tmp,502);	   // ת��ת��ʵ��ֵ  revised by yp 20180131
   spd_tmp = PMSM.Speed_est * 60 / PI2 / PMSM.p;
   fnVarCopyToRam(sInComm.DSP_RAM,&spd_tmp,506);	   // ����ת�� revised by yp 20180131
*/

}
/***********************************************************
//�������ƣ�fnSysParamterRef
//�������ܣ��������Բ���ˢ��
//������������
************************************************************/
void fnSysParamterRef(void)
{
    if(*pARMParamRdFlag == 0xce)
    {
      if(SysSampOffset.SampOffsetOnce == 0)
      {
     	SysSampOffset.pfnSysOffsetInit(&SysSampOffset);
     	SysSampOffset.SampOffsetOnce = 1;
      }
    }
    DAOut.uDA_NumCh1 = (Uint16)*pCsvParamDACH1;
    if(DAOut.uDA_NumCh1>30) DAOut.uDA_NumCh1 = 30;
    if(DAOut.uDA_NumCh1<1)  DAOut.uDA_NumCh1 = 1;
    DAOut.uDA_NumCh2 = (Uint16)*pCsvParamDACH2;
    if(DAOut.uDA_NumCh2>30) DAOut.uDA_NumCh2 = 30;
    if(DAOut.uDA_NumCh2<1)  DAOut.uDA_NumCh2 = 1;
    *RdDSPtoARM = 0xfa;//DSP��ѭ���������еı�־��

}
/***********************************************************
//�������ƣ�fnVarCopyToRam
//�������ܣ��������ݻ�������
//���������� HeadAddr��Ŀ����ʼ��ַ
          pVarAddr�������ݲ�����ʼ��ַ
          AddrBias��ƫ�Ƶ�ַ
************************************************************/
void fnVarCopyToRam(Uint16 *HeadAddr,float32 *pVarAddr,Uint16 AddrBias)
{
	Uint16 *pParaAddr;
	Uint16 uParaL,uParaH;
	pParaAddr = (Uint16*)pVarAddr;
	uParaL = *pParaAddr;
	uParaH = *(pParaAddr + 1);
	*(HeadAddr + AddrBias) = uParaL;
	*(HeadAddr + AddrBias + 1) = uParaH;
}
/***********************************************************
//�������ƣ�fnSysRatedParameter
//�������ܣ����������
//������������
************************************************************/
void fnSysRatedParameter(void)                                                                        
{                                                                                                      
	 SysRatedParameter.fMotorRatedVoltage = *pCsvParamMotorRatedVoltage;  //������ѹ                        
	 SysRatedParameter.fMotorRatedCurrent = *pCsvParamMotorRatedCurrent;  //��������                        
	 SysRatedParameter.fMotorRatedFre = *pCsvParamMotorRatedFre;          //����Ƶ��                        
	 SysRatedParameter.fMotorRatedPower = *pCsvParamMotorRatedPower;      //��������                        
	 SysRatedParameter.fMotorRateSpeed = *pCsvParamMotorRateSpeed;        //����ת��                        
	 SysRatedParameter.fMotorPoleNum = *pCsvParamMotorPoleNum;            //���������                          
	 SysRatedParameter.fMotorRatedSlip = *pCsvParamMotorRatedSlip;        //��������                           
	 SysRatedParameter.fVFDInputVolatge = *pCsvParamVFDInputVolatge;      //��Ƶ��������ѹ                      
	 SysRatedParameter.fVFDInputCurrent = *pCsvParamVFDInputCurrent;      //��Ƶ����������                  
	 SysRatedParameter.fVFDRatedPower = *pCsvParamVFDRatedPower;          //��Ƶ�������                      
	 SysRatedParameter.fVFDInputFre = *pCsvParamVFDInputFre;              //��Ƶ�������Ƶ��                  
	 SysRatedParameter.fVFDOutputVoltage = *pCsvParamVFDOutputVoltage;    //��Ƶ��������ѹ                  
     SysRatedParameter.fVFDOutputCurrent = *pCsvParamVFDOutputCurrent;    //��Ƶ����������

}
/***********************************************************
//�������ƣ�fnSysHMICommInit
//�������ܣ�HMIͨѶ�ӿڳ�ʼ��
//������������
************************************************************/
void fnSysHMICommInit(void)
{
	sInComm.u2LineNumber = 11;  //
	                            //    
	sInComm.u2SerialNumber = 11;//
	                            //
	sInComm.u2ProductNumber = 8;//���س���汾��008 V06
	                            //
	sInComm.u2FactoryNumber = 6;//
	                            //
	sInComm.DSP_RAM = &HMIBuffer[0];//

	                           //
	sInComm.ARMHandshakeWord=(Uint16 *)0x2803FE;
	sInComm.DSPHandshakeWord=(Uint16 *)0x2803FF;

	sInComm.ReceiveStartAdd=(Uint16 *)0x280000;
	sInComm.DSPtoARMStartAdd=(Uint16 *)0x280000;
	sInComm.WaveID_ADD=(Uint16 *)0x280000;
	sInComm.WaveData_StartADD=(Uint16 *)0x280000;
    sInComm.pfnInit(&sInComm);
}




//===========================================================================
// No more.
//===========================================================================
