#ifndef VVVF_H
#define VVVF_H
#include "DSP2833x_Device.h"
//=====================================================

typedef struct{
				void 	(*pfnCalc)();	//���㺯��ָ��
				void	(*pfnReset)();	//��λ����ָ��
				void 	(*pfnInit)();	//��ʼ������ָ��
			//����
	            float32  fFreqRefGive;   //ϵͳ��ARM������Ƶ��
				float32  fFreqRefMin;   //��СƵ��
	            float32  fFreqRefBase;  //��׼Ƶ��
	            float32  fFreqRefPoint1;   //VF����Ƶ�ʵ�1
	            float32  fFreqRefPoint2;  //VF����Ƶ�ʵ�2

	            float32  fVoltRefMin;     //��С��ѹ
	            float32  fVoltRefMax;     //����ѹ
	            float32  fVoltRefPoint1;   //VF���ߵ�ѹ��1
	            float32  fVoltRefPoint2;  //VF���ߵ�ѹ��2

	       //���
	            float32  fTheta_base;    //�Ƕ����
	            float32  fVoltageAmp;    //��ѹ��ֵ/���Ʊ�

	            float32  fVFPhseCoffic;
}TypeSysVVVFCal;

//===================VVVFVar��Ĭ�ϳ�ʼ������========================================
#define VVVFVal_DEFAULTS {\
							(void (*)(Uint32))fnVVVFCtrlInterface, \
							(void (*)(Uint32))fnVVVFVarReset, \
							(void (*)(Uint32))fnVVVFVarInit, \
							0.0,0.0,0.0,0.0,0.0, \
							0.0,0.0,0.0,0.0, \
							0.0,0.0,0.0}

extern TypeSysVVVFCal  SysVVVFCtrl;
extern void fnVVVFCtrlInterface(TypeSysVVVFCal *p);
extern void fnVVVFVarReset(TypeSysVVVFCal *p);
extern void fnVVVFVarInit(TypeSysVVVFCal *p);
//===== �翹�����Բ����ṹ�� ================================
typedef struct {
	                void (*pfnCalc)();	//���㺯��ָ��
                //����
					float32 fVoltageAmpSet;
					float32 fVoltageAmpSetLast;
					float32 fVoltageAmp_temp;
					float32 fTheta_base;

					Uint16  Enable;

                } TypeSysConTestParam;

                //��ʼֵ
#define SysConTestParam_DEFAULTS  {\
                                    (void (*)(Uint32))fnUnitTestingInterface, \
                		            0.0,0.0,0.0,0.0,0}

extern TypeSysConTestParam  SysConTest;
extern void fnUnitTestingInterface(TypeSysConTestParam *p);



#endif
