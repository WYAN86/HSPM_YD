#ifndef SYSVoltBASE_H
#define SYSVoltBASE_H
#include "DSP2833x_Device.h"
//=====================================================

typedef struct{
	void 	(*pfnCalc)();	//���㺯��ָ��
	void	(*pfnReset)();	//��λ����ָ��
	void 	(*pfnInit)();	//��ʼ������ָ��
	
	
	float32 fUu_base; 	//U����Ʋ�
	float32 fUv_base;	//v����Ʋ�
	float32	fUw_base;	//w����Ʋ�
	Uint16  uCarrCount;	//�ز��������ֵ
	Uint16  uChopCount;
	Uint16  uUu_Fib;    //д����˰���Ʋ�����
	Uint16  uUv_Fib;    //д����˰���Ʋ�����
	Uint16  uUw_Fib;    //д����˰���Ʋ�����
	Uint16  chopwave_Fib;
	

}TypeVoltBaseCal;



//===================��ѹ���������Ĭ�ϳ�ʼ������========================================
#define SysVoltBaseCal_DEFAULTS {\
							(void (*)(Uint32))fnSysVoltBaseCalc, \
							(void (*)(Uint32))fnSysVoltBaseReset, \
							(void (*)(Uint32))fnSysVoltBaseInit, \
							0.0,0.0,0.0,25000,0,0,0\
	                            }

extern void fnSysVoltBaseInit(TypeVoltBaseCal *p);
extern void fnSysVoltBaseReset(TypeVoltBaseCal *p);
extern void fnSysVoltBaseCalc(TypeVoltBaseCal *p);
extern TypeVoltBaseCal  SysVoltBase;
#endif
