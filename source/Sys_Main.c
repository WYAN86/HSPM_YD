/*
//========================================================
// 
// �ļ���:	Main.c
//
// ��;:	ϵͳ������
//
*/
//==========================================================
#include "DSP2833x_Device.h"     // DSP2833xͷ�ļ�
#include "SysCtl_AllHeaders.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "DSP2833x_Examples.h"



extern void fnSysParamterRef(void);
// Prototype statements for functions found within this file.
__interrupt void epwm1_isr(void);
__interrupt void epwm2_isr(void);
__interrupt void epwm3_isr(void);
__interrupt void epwm4_isr(void);
//=========================================================

void DISABLE_PWM(void)
{
	EALLOW;
	GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;
	EDIS;
	EPwm1Regs.AQCSFRC.all = 5; //0101 A1B1 enforce to low constant
	EPwm2Regs.AQCSFRC.all = 5;
	EPwm3Regs.AQCSFRC.all = 5;
	EPwm4Regs.AQCSFRC.all = 5;
	EPwm1Regs.DBCTL.bit.OUT_MODE = 0;
	EPwm2Regs.DBCTL.bit.OUT_MODE = 0;
	EPwm3Regs.DBCTL.bit.OUT_MODE = 0;
	EPwm4Regs.DBCTL.bit.OUT_MODE = 0;
}

void ENABLE_PWM(void)
{
	EALLOW;
	GpioDataRegs.GPASET.bit.GPIO1 = 1;
	EDIS;
	EPwm1Regs.DBCTL.bit.OUT_MODE = 0;
	EPwm2Regs.DBCTL.bit.OUT_MODE = 0;
	EPwm3Regs.DBCTL.bit.OUT_MODE = 0;
	EPwm4Regs.DBCTL.bit.OUT_MODE = 0;
	EPwm1Regs.AQCSFRC.all = 0xF;
	EPwm2Regs.AQCSFRC.all = 0xF;
	EPwm3Regs.AQCSFRC.all = 0xF;
	EPwm4Regs.AQCSFRC.all = 0xF;
}

void main(void)
{
//	Uint16 i;

	DINT;//���ж�
	                       //
	fnSysPeripheralInit();//ϵͳ�����ʼ,��DSP2833x_SysPerInit.c

	CpuTimer0Regs.PRD.all = 75000000;
	CpuTimer0Regs.TPR.all = 1;
	CpuTimer0Regs.TPRH.all = 0;
	CpuTimer0Regs.TCR.bit.TSS  = 1;   //Stop Timer0 for now
	
	// Interrupts that are used in this example are re-mapped to
	// ISR functions found within this file.
	EALLOW;  // This is needed to write to EALLOW protected registers
	PieVectTable.EPWM1_INT = &epwm1_isr;
	PieVectTable.EPWM2_INT = &epwm2_isr;
	PieVectTable.EPWM3_INT = &epwm3_isr;
	PieVectTable.EPWM4_INT = &epwm4_isr;
	EDIS;    // This is needed to disable write to EALLOW protected registers
	
	fnSysHMICommInit();//HMI��ʼ��

	fnSystemInitParam();//ϵͳ������ʼ��

	//*sInComm.DSPHandshakeWord = (Uint16)0xAA55;

	fnEnableInterrupts();//ϵͳ���ж�
	//SysMoore.SysStateNew = SystemReady;//
	//============��ʼ��DMA=========================================
	DMAInitialize();

	DMASource1 = &DMABuf1[0];
   	DMACH1AddrConfig(DMADest1,DMASource1);
	DMACH1BurstConfig(31,2,2);         //Will set up to use 32-bit datasize, pointers are based on 16-bit words
	DMACH1TransferConfig(3,2,2);      //so need to increment by 2 to grab the correct location
	DMACH1WrapConfig(0x1000,0,0x1000,0);
    DMACH1ModeConfig(DMA_XINT1,PERINT_ENABLE,ONESHOT_ENABLE,CONT_DISABLE,SYNC_DISABLE,SYNC_SRC,OVRFLOW_DISABLE,THIRTYTWO_BIT,CHINT_END,CHINT_ENABLE);

    //=======ϵͳ��ѭ��===============================
 	for(;;)
 	{
		SysMoore.pfnSysMooreCal(&SysMoore);//ϵͳ״ִ̬��
										  //
		sInComm.pfnReadFPGA(&sInComm);//HMI�����ϴ�

		fnSysParamterRef();//���������ݸ���
    }

}
