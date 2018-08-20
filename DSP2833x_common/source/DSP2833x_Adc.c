// TI File $Revision: /main/5 $
// Checkin $Date: October 23, 2007   13:34:09 $
//###########################################################################
//
// FILE:	DSP2833x_Adc.c
//
// TITLE:	DSP2833x ADC Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x Header Files V1.20 $
// $Release Date: August 1, 2008 $
//###########################################################################


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_GlobalPrototypes.h"
#define ADC_usDELAY  5000L

//---------------------------------------------------------------------------
// InitAdc:
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
void InitAdc(void)
 {
  extern void DSP28x_usDelay(Uint32 Count);
  EALLOW;
  SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
  EDIS;
  AdcRegs.ADCTRL3.all = 0x00E0;  // Power up bandgap/reference/ADC circuits
 }
void fnInitAdc(void)
{
 AdcRegs.ADCTRL1.bit.CPS = 1;//Fclk = Clk/2
 AdcRegs.ADCTRL1.bit.ACQ_PS = 1;//2��ʱ�ӵĲɱ�ʱ��
 AdcRegs.ADCTRL1.bit.CONT_RUN = 0;//��ͣת��ģʽ
 AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;//0˫����������ģʽ1����ģʽ
 AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;//��λSEQ1--CONV00
 AdcRegs.ADCTRL2.bit.RST_SEQ2 = 1;//��λSEQ2--CONV08
 AdcRegs.ADCTRL3.bit.ADCCLKPS = 1;//clk = HSPCLK/4
 AdcRegs.ADCTRL3.bit.SMODE_SEL = 0;//˳�����ģʽ
 AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 7;//SEQ1���ת����8
 AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;//ʹ���ж�����
 AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2 = 1;//
 
 AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0;	//����ADCINA0��Ϊ��1���任
 AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 8;	//����ADCINB0��Ϊ��2���任
 AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 1;	//����ADCINA1��Ϊ��3���任
 AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 9;	//����ADCINB1��Ϊ��4���任
 AdcRegs.ADCCHSELSEQ2.bit.CONV04 = 2;	//����ADCINA2��Ϊ��5���任
 AdcRegs.ADCCHSELSEQ2.bit.CONV05 = 10;	//����ADCINB2��Ϊ��6���任
 AdcRegs.ADCCHSELSEQ2.bit.CONV06 = 3; 	//����ADCINA3��Ϊ��7���任
 AdcRegs.ADCCHSELSEQ2.bit.CONV07 = 11;	//����ADCINB3��Ϊ��8���任
 AdcRegs.ADCCHSELSEQ3.bit.CONV08 = 4;
 AdcRegs.ADCCHSELSEQ3.bit.CONV09 = 5;////
 AdcRegs.ADCCHSELSEQ3.bit.CONV10 = 6;////
 AdcRegs.ADCCHSELSEQ3.bit.CONV11 = 7;////
 AdcRegs.ADCCHSELSEQ4.bit.CONV12 = 13;
 AdcRegs.ADCCHSELSEQ4.bit.CONV13 = 13;
 AdcRegs.ADCCHSELSEQ4.bit.CONV14 = 14;
 AdcRegs.ADCCHSELSEQ4.bit.CONV15 = 14;

}

//===========================================================================
// End of file.
//===========================================================================
