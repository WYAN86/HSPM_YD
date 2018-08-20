#include "SysCtl_AllHeaders.h"

/***********************************************************
//�������ƣ�fnSysVoltBaseInit
//�������ܣ�������ѹ�����ʼ��
//������������
************************************************************/
void fnSysVoltBaseInit(TypeVoltBaseCal *p)
{
  p->fUu_base = 0.0;
  p->fUv_base = 0.0;
  p->fUw_base = 0.0;
  p->uCarrCount = uPeriodCounter;
  p->uUu_Fib = 0;
  p->uUv_Fib = 0;
  p->uUw_Fib = 0;
}
/***********************************************************
//�������ƣ�fnSysVoltBaseReset
//�������ܣ�������ѹ����λ
//������������
************************************************************/
void fnSysVoltBaseReset(TypeVoltBaseCal *p)
{
  p->fUu_base = 0.0;
  p->fUv_base = 0.0;
  p->fUw_base = 0.0;
  p->uCarrCount = uPeriodCounter;
  p->uUu_Fib = 0;
  p->uUv_Fib = 0;
  p->uUw_Fib = 0;
}
/***********************************************************
//�������ƣ�fnSysVoltBaseCalc
//�������ܣ�������ѹ����ӿ�float->int
//������������
************************************************************/
void fnSysVoltBaseCalc(TypeVoltBaseCal *p)
{
	float32  fUuBoost = 0.5;
	float32  fUvBoost = 0.5;
	float32  fUwBoost = 0.5;

	fUuBoost = 0.5 * (1.0 + p->fUu_base);//U���ѹ̧��
                                        //
 	fUvBoost = 0.5 * (1.0 + p->fUv_base);//V���ѹ̧��
                                        //
 	fUwBoost = 0.5 * (1.0 + p->fUw_base);//W���ѹ̧��
                                        //
	 p->uUu_Fib = (Uint16)(fUuBoost * p->uCarrCount);//U���˰��ѹ
												   //
	 p->uUv_Fib = (Uint16)(fUvBoost * p->uCarrCount);//V���˰��ѹ
												   //
	 p->uUw_Fib = (Uint16)(fUwBoost * p->uCarrCount);//W���˰��ѹ
										   //
	 if(p->uUu_Fib > p->uCarrCount)
		 p->uUu_Fib = p->uCarrCount;//
						   //
	 if(p->uUv_Fib > p->uCarrCount)
		 p->uUv_Fib = p->uCarrCount;//
						   //
	 if(p->uUw_Fib > p->uCarrCount)
		 p->uUw_Fib = p->uCarrCount;//

	InvModuWave(p->uUu_Fib,p->uUv_Fib,p->uUw_Fib);

	DEP_DSP_GPWM_ENABLE = 1;
	//DEP_DSP_GPWM_ENABLE = 3;

}
