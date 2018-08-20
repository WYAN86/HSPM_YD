/*
// Version: V1.0
// Date: 	Apr 4, 2013
// Author:	Myj @YD
//===========================================================================
//
// �ļ���:	DSP2833x_SysBoard.h
//
// ��;:
//		1. ������İ�FPGA�Ĵ�����ַ
//		2. ������˰�FPGA�Ĵ�����ַ
//		3. ��������
//===========================================================================
*/

#ifndef DSP2833X_SYSBOARD_H
#define DSP2833X_SYSBOARD_H

//============ϵͳIO=============================
#define IO_Reset GpioDataRegs.GPBDAT.bit.GPIO48

#define pCS_ReadIO ((volatile Uint16 *)0x002808F8)     //ϵͳIO����
#define pCS_WriteIO ((volatile Uint16 *)0x002808F9)    //ϵͳIO���

//============��FPGA������=======================

//==========�忨ȷ����Ϣ��ַ================
#define pBUSBDAddrBase	((volatile Uint16 *)0x00004fe0)  //��һ�����Ϣ
#define RightInfo1  0x01
#define RightInfo2  0x81
#define FaultInfo1  0x11
#define FaultInfo2  0x91

//==========AD����궨��===========================
#define pCS_ADCONV ((volatile Uint16 *)0x002808F5)//AD����
#define pCS_ADRD1 ((volatile Uint16 *)0x002808F6)//��AD1������
#define pCS_ADRD2 ((volatile Uint16 *)0x002808F7)//��AD2������

//==========DA����궨��===========================

#define pDA_Enable ((volatile Uint16 *)0x002808F4) //DA���ʹ��

#define pDA_Out1 ((volatile Uint16 *)0x002808F0)   //DA1���
#define pDA_Out2 ((volatile Uint16 *)0x002808F1)   //DA2���
#define pDA_Out3 ((volatile Uint16 *)0x002808F2)   //DA3���
#define pDA_Out4 ((volatile Uint16 *)0x002808F3)   //DA4���

//===============������λ���źŶ���===================
#define pCS_CoderPosition 	((volatile Uint16 *)0x00004C01)//������λ��
#define pCS_CoderRound 		((volatile Uint16 *)0x00004C02)//������Ȧ��
#define pCS_CoderDirWrite 	((volatile Uint16 *)0x00004C04)//�������������
#define pCS_CoderDirRead 	((volatile Uint16 *)0x00004C03)//������ʵ�����з���
#define pEncoder_ForwordReg (*((volatile Uint16 *)0x00004fc1))//������������
#define pEncoderReadFlag	(*((volatile Uint16 *)0x00004fc3))//ȫ�ֿ��ƼĴ���
#define pEncoderPulseReg	(*((volatile Uint16 *)0x00004fc6))//ȫ�ֿ��ƼĴ���

//=========�ⲿ�������� =====================================
extern void fnInitFibBoardCarClear(Uint16 uSysSeriesNum1);
extern void fnSysCellEn(Uint16 uSysSeriesNum);
extern void fnCellBypassClear(Uint16 Temp);
extern void fnInitFibBoardCar(Uint16 Temp);
extern void fnSysFibBoardInit(void);
extern void fnCellFaultRegClear();
extern void fnCellLockReset(void);
extern void fnSysFibHeartVersion(void);
#endif


