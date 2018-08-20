/* 
//=======================================================
// 
// �ļ���:	DSP2833x_SysPerInit.c
//
// ��;:	ϵͳ�����ʼ��
//
// ˵��:	

//========================================================
*/
#include "DSP2833x_Device.h"    
#include "DSP2833x_GlobalPrototypes.h"
#include "DSP2833x_Examples.h"

extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;

void fnSysPeripheralInit(void)
{
	fnDisDog();//��ֹ���Ź�
	fnInitClock();//����ʱ��

	//================��ʼ��Flash========================================
	MemCopy((Uint16*)&RamfuncsLoadStart, (Uint16*)&RamfuncsLoadEnd, (Uint16*)&RamfuncsRunStart);

	fnInitFlash();

	//==============�����ⲿ�ռ�=====================================
	fnInitXintf();
	//==============��ʼ���ж�������һ��ȷ��״̬===================
	fnInitPieVectTable();
	//==============��ʼ���ж����ã������ж�ʹ������=================
	fnInitPieCtrl();
	//============����Gpio=========================================
	fnInitGpio();
	//============��ʼ��AD=========================================
	InitAdc();//
		   //
	fnInitAdc();//

	//==========��ʼ��EPWM==========================================
	//InitPwm();
}



//======================================


