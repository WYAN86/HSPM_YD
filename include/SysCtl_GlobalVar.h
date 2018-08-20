/*
// Version: V1.0 �ļ�����
// Date: 	Dec 12, 2012
// Author:	chenchangjiang @YD
//==========================================================================
//
// �ļ���:	SysCtl_GlobalVar.h
//
// ��;:    ȫ�ֽṹ���ⲿ����
//
//==========================================================================
*/

#ifndef SYSCTL_GlOBALVAR_H
#define SYSCTL_GlOBALVAR_H

#define BUF_SIZE   0x80  // Sample buffer size
#define FltWord_DSPtoARM   *(volatile Uint16*)&DMABuf1[98] //DSP�����ִ�����ARM
#define FreqEn_DSPtoARM   *(volatile Uint16*)&DMABuf1[100] //Ƶ�ʼ���ʹ��
#define DAC_DSPtoARM1      *(volatile float32*)(0x200040)//������DAC���ݴ���
#define DAC_DSPtoARM2      *(volatile float32*)(0x200042)//������DAC���ݴ���
#define StMach_ARMtoDSP    *(volatile Uint16*)(0x280500) //ARM״̬��
#define FreqRef_ARMtoDSP   *(volatile float32*)(0x280502)//������DAC���ݴ���
#define BaseAddr_OffsetCal   928
//=================ϵͳ���������ṹ��========================================
struct SysErrIndex_BITS {                                 // bits	description
                          Uint16  SysHFaultFlag:1;        //ϵͳ�ع��ϱ�־

						  Uint16  rsvd:15;
                          };
union SysErrIndex_REG {
                       Uint16			      	 all;
                       struct SysErrIndex_BITS   bit;
                      };

//=================ARM���ϱ�־========================================
struct ARMErr_BITS {                                 // bits	description
                          Uint16  ARMHFaultFlag:1;        //ϵͳ�ع��ϱ�־
						  Uint16  rsvd:15; 
                          };
union ARMErr_REG   {
                       Uint16			     all;
                       struct  ARMErr_BITS   bit;
                    };
//=================DSP���ϱ�־========================================
struct DSPErr_BITS {                                 // bits	description
                          Uint16  OCFaultFlag:1;        //ϵͳ�ع��ϱ�־
						  Uint16  rsvd:15; 
                    };
union DSPFault_REG   {
                       Uint16			     all;
                       struct  DSPErr_BITS   bit;
                     };

struct SysCtl_BITS {		                   // bits	description
                     Uint16    StartInstr:1;   //����ָ��
					 Uint16    StopInstr:1;    //ͣ��ָ��
					 Uint16    EStopInstr:1;   //��ָͣ��					 
					 Uint16    ResetInstr:1;   //��λָ��
                     Uint16    OffSetInst:1;  //ϵͳ��Ưָ��
					 Uint16    LVDebugInst:1;  //��ѹ����ָ��
					 Uint16    MotorReverEn:1; //�����ת
					 Uint16    HVDebugInst:1;  //��������ָ��
					 Uint16    SynSwitchInst:1;//ͬ��Ͷ��ָ��
					 Uint16    ErrMaskInstr:1; //��������
                     Uint16    rsvd:6;         // 7-15 reserved
                    };
union SysCtl_REG   {
                     Uint16	   all;
                     struct SysCtl_BITS   bit;
                    };

//===== ��ѹ���Խṹ�� ====================================
typedef struct {
                //
				Uint16  uLVDebugEN;
                float32 fTheta_base;//��λ����
				float32 fUu_base;//U����Ʋ�
				float32 fUv_base;//U����Ʋ�
				float32 fUw_base;//U����Ʋ�

				float32 fUuBoost;
				float32 fUvBoost;
				float32 fUwBoost;

				Uint16 uUu_Fib;
				Uint16 uUv_Fib;
				Uint16 uUw_Fib;
                }LVDebugTEST;

                //��ʼֵ
#define LVDebug_DEFAULTS {0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}
//===== ϵͳ���ƽṹ�� ====================================
typedef struct {
				//
				Uint16  uStartMode;

				}TypeSYSCTRL;

				//��ʼֵ
#define SYSCtrl_DEFAULTS {0}
//===== ���������ṹ�� ================================
typedef struct {
                //����
				float32 fOCProtect;//��������ֵ 
                float32 fOCProtect_Per;//������������ֵ  

                } TypeSysProParameter;
                 
                //��ʼֵ
#define SysProParameter_DEFAULTS {0.0,0.0}
//===== �����ϴ��ṹ�� ====================================
typedef struct {
                float32 VarScope[30];
				Uint16 ScopeCount;
                }SCOPEDATA;

                //��ʼֵ
#define ScopeData_DEFAULTS {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,\
                             0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},0}

//=================�ֵ����=========================================
typedef struct {
                float32 fMotorRatedVoltage;//������ѹ
				float32 fMotorRatedCurrent;//��������
				float32 fMotorRatedFre;//����Ƶ��
				float32 fMotorRatedPower;//��������
				float32 fMotorRateSpeed;//����ת�٣�ת/��
				float32 fMotorPoleNum;//���������
				float32 fMotorRatedSlip;//���ת����
				float32 fVFDInputVolatge;//��Ƶ��������ѹ
				float32 fVFDInputCurrent;//��Ƶ����������
				float32 fVFDRatedPower;//��Ƶ�������
				float32 fVFDInputFre;//��Ƶ�������Ƶ��
				float32 fVFDOutputVoltage;//��Ƶ��������ѹ
				float32 fVFDOutputCurrent;//��Ƶ����������
                } TypeSysRatedParameter;
//================�����Ĭ�ϱ�����ʼ��===============================
#define SysRatedParameter_DEFAULTS {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}
//===== ϵͳ��ֵ�ṹ�� ====================================
typedef struct {   
                //���
				float32  fVoltBaseValueGrid;   //ϵͳ�����ѹ��ֵ
				float32  fVoltBaseValue;   //ϵͳ�����ѹ��ֵ
				float32  fCurrBaseValue;   //ϵͳ������ֵ
				float32  fSpeedBaseValue;  //ϵͳת�ٻ�ֵ
				float32  fThetaBaseValue;  //ϵͳ��ǶȻ�ֵ
				float32  fPowerBaseValue; //ϵͳ���ʻ�ֵ
				float32  fZBaseValue;//ϵͳ�迹��ֵ
				float32  fYBaseValue; //ϵͳ���ɻ�ֵ  added by yp
				float32  fLBaseValue;//ϵͳ��л�ֵ
				float32  fPhirBaseValue;//ϵͳ������ֵ
				float32  fOmegBaseValue;//ϵͳ��е�ǶȻ�ֵ
				float32  fTeBaseValue;//ϵͳת�ػ�ֵ
				float32  fJBaseValue;//ת��������ֵ
				float32  fFBaseValue;//Ħ��ϵ����ֵ
				float32  fHBaseValue;//����ʱ�䳣����ֵ

				//����
				  void   (*pfnSysBaseValueCal)();//ϵͳ��ֵ����
			   } TypeSysBaseValue;

                //��ʼֵ
#define SysBaseValue_DEFAULTS {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0, \
                               0.0,0.0,0.0,0.0,0.0,0.0,0.0, \
                               (void (*)(Uint32))fnSysBaseValueCal, \
                               }
//=================���������趨=========================================

typedef enum {
				AsynMotor = 0,       //�첽���
				SynMotor = 1,        //ͬ�����
				Reactor = 2         //�翹��

			} TypeSysVFDLoad;   //��������

typedef enum {
				PGVVVF = 0,         //VVVF
				NPGVVVF = 1,      //VVVF
				VC = 2,             //VC
				SLVC = 3            //SLVC

			} TypeSysControlStrat;  //���Ʋ���
typedef struct {
			     Uint16 uConRunType;//��Ƶ������
			     TypeSysVFDLoad uVFDLoadType;//��������
			     TypeSysControlStrat uConStrat;//������Ʋ���

			   } TypeSysEnvironParameter;
//================��������Ĭ�ϱ�����ʼ��===============================
#define SysEnvironParameter_DEFAULTS {0,AsynMotor,NPGVVVF}

extern void fnSysBaseValueCal(TypeSysBaseValue *p);
extern TypeSysMoore SysMoore;
extern LVDebugTEST SysLVDebug;
extern union  SysErrIndex_REG SysErrIndexReg;
extern union SysCtl_REG SysCtlReg;
extern union ARMErr_REG ARMFaultReg;
extern union DSPFault_REG DSPFaultCodeReg;
extern TypeSysProParameter SysProParamReg;
extern SCOPEDATA *ScopeDATAUpLoad;
extern TypeSysRatedParameter SysRatedParameter;
extern TypeSysBaseValue SysBaseValue;
extern TypeSysEnvironParameter SysEnviConfg;
extern TypeSYSCTRL SysCtlParameter;
extern void fnSysHMICommInit(void);
extern void fnSysFreCalHMI(void);
extern void fnSystemInitParam(void);
extern void fnSysFreCalInit(void);
extern void fnVFBaseCalculusCal(LVDebugTEST *p);
extern void fnSysCtlLvDebug(void);
extern void fnVarScopeAssign(void);

//extern void InitAlgorithm(void);
//extern void Algorithm(void);


extern Uint32  uDMA_Addr;
extern volatile Uint16 DMABuf1[BUF_SIZE];
extern volatile Uint16 *DMADest1;
extern volatile Uint16 *DMASource1;
extern volatile Uint16 *RdDSPtoARM;
extern volatile Uint16 *pARMParamRdFlag;
extern volatile float32 *pOffsetRam;
extern volatile Uint16 *pWaveParamStart;

//extern INTERG Interg_Vector;
//extern VECTOR_ST SpeedTest;
//extern PIREG PhrPI;
extern Uint16 uDirCount;
extern Uint16 uDirCountMax;
extern Uint32 CNT_FR_VALUE;
extern float32 CutOff_Freq;
#endif  

