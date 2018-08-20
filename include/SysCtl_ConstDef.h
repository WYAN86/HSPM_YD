
/*
//===========================================================================
//
// �ļ���:	sysCtl_ConstDef.h
//
// ��;:	
//		1. �����׼��������
//		2. ������ѧ����
//		3. ����DSPʱ��Ƶ�ʼ�������ó���
//		4. �������������ó���
//
//===========================================================================
*/

#ifndef SYSCTL_CONSTDEF_H
#define SYSCTL_CONSTDEF_H

//===========================================================================
// ����28335����������
//===========================================================================
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int                int16;
typedef long               int32;
typedef long long          int64;
typedef unsigned int       Uint16;
typedef unsigned long      Uint32;
typedef unsigned long long Uint64;
typedef float              float32;
typedef long double        float64;
#endif
//==========  �߼���������  ==========
#define TRUE		1
#define FALSE		0
//==========  CPUʱ������.  ====================
//	SYSCLKOUT = CLKIN * DSP28_PLLCR / N(DSP28_DIVSEL)
//	CLKIN is a 30MHz;  DSP28_PLLCR=10;   DSP28_DIVSEL=2;
// 	SYSCLKOUT = 150 MHz
//======================================================

#define NORMALMOD           0x00   //������
#define FLYMOD              0x01   //�ɳ���
#define BRAKEMOD            0x02   //�ƶ���

//===== �������ͺ궨�� ======

#define HErr_OVFault              0x80   //��ѹ
//======���㳣���궨��=======
#define fPeriodCounter       2500 //27719.0
#define uPeriodCounter       25000
#define PeriodTimeus          500.0
#define PeriodTime (fusToS)*(PeriodTimeus)//ϵͳ�������ڣ�S��λ
                                         //
#define D1ByPeriod (1.0)/(PeriodTimeus)//���ڵ���
                                       //
#define uSTous 1000000.0//s ת��usת��ϵ��
                        //
#define TimerCoffic (uSTous)*(D1ByPeriod)//��ʱ��ʱ��ϵ��
                                         //
#define fusToS 0.000001//usת��Sϵ��
                       //
#define KAnalog 0.0004884//  2/4095   ///0.00015259022//AD��������ϵ��10/65535
                              //
//#define DC_VoltScalCoe  0.5979004//0.322372// 1000/3102 ֱ��ĸ�ߵ�ѹ����ϵ��//15.7.1ZH.J ��Ϊ 2449/4096

#define Rec_CurrScalCoe 0.6105// 2500/4095�������������ϵ��

#define PowerCalLPFCutFre 30.0//
                              //
#define PowerCalLPFSampFre 5988.0//

#define DAOutCoffic 204.75 ///0-20mA

//#define fDetatheta           0.015707963

#define LowSpeed 5.0

#define MidSpeed 25.0

#define HighSpeed 40.0

#define PhseCoffic 0.0014891148924     ///237us

#define AnalogIToVolt 0.12696          //ģ��忨20mA����תΪ2.5392V��DSP��2.5392/20 = 0.12696��

#define SpeedObserveUTO 0.009

#define KCapSpeedClk 9000000.0

#define KOmegBase 0.10471975512

#define ParaMesTime 0.2

#define ParaMes_DetaTheta 0.05215

#define VFDCurLPFTCon    0.0104876

#define PI            3.14159265
#define PI2      	  6.28318531 
#define N_PI2		  (-1.0)*(PI2)//                                    //
#define f4_D_3PI      (4.0/3.0)*(PI)//
#define f2_D_3PI      (2.0/3.0)*(PI)//

#define VFPhseCoffic  0.00314159265
#endif  



//===========================================================================
// NO MORE
//===========================================================================

