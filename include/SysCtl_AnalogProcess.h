/*
// Version: V1.0 �ļ�����
//
// Date: 	Dec 18, 2017
//
// Author:	chenchangjiang @YD
//===================================================================
//
// �ļ���:	SysCtl_AnalogProcess.h
//
// ��;:    ģ�������ƽṹ��

//===================================================================
*/
#ifndef SYSCTRL_ANALOGPROCESS_H
#define SYSCTRL_ANALOGPROCESS_H

//============= ģ��������ƽṹ�� ================================
typedef struct {
	            //����
	            int    iSysADResult[8];
                //����
				float32 fAnaInTs;        //ģ���������
				float32 fLVoltAB;
				float32 fLVoltBC;
				//���

				float32 fFreGivenAna;    //ģ�����Ƶ��
				float32 fADResult_Offset[12];//ϵͳģ���������������������ѹ����Ưǰ����ֵ
				float32 fADResult_Offseted[12];//ϵͳģ���������������������ѹ���۳���Ư��Ĳ���ֵ
				float32 fADResult[9];		  //����ʵ��ֵ
                int uADResultAnaIn[16];           //Ƭ��AD����Ĵ���
				//���㺯��
				void (*pfnAISample)();//ģ������������
              //  void (*pfnInit)();//��ʼ������

                }TypeAnalogInput;

//============= ģ������Ĭ�ϱ�����ʼ�� =============================
#define AnalogInput_DEFAULTS {{0},0.0,0.0,0.0,0.0,{0},{0},{0},{0}, \
							  (void (*)(Uint32))fnAISample\
                              }
//============= ģ�����봦�������� ==============================
void fnAISample(TypeAnalogInput *p);

typedef struct {
                //״̬��
	            Uint16  uSampleOffsetEn;//��Ưʹ��
	            Uint16  SampOffsetOnce;//��ȡ��Ư������δ���
				Uint16  uOffsetCount;//��Ư����
                Uint16  uOffsetCounter;//��Ư����
                float32 fOffsetValue[12];//DSP������Ưֵ
				float32 fOffsetAdd[12];
				float32 fOffsetUpValue[12];//DSP������Ư�ϴ�ֵ

				//��������
                void (*pfnSysOffsetInit)();//��Ư������ʼ������
				void (*pfnSysOffsetParameterCal)();//��Ư�������㺯��
               }TypeSysOffsetParameter;

#define SysOffsetParameter_DEFAULTS {0,0,0,0,\
									{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},{0},{0}, \
                                     (void (*)(Uint32))fnSysOffsetInit, \
                                     (void (*)(Uint32))fnSysOffsetParameterCal, \
                                     }

//=================������������=========================================
typedef struct {
                float32 fSysSamValue[12];
				float32 fSysSamOutCRatio;
				float32 fSysSamOutCSamR;
				float32 fSysSamOutVDividR;
				float32 fSysSamOutVDCR;
				float32 fSysSamDCVoltage;
				float32 fSysSamOutVoltage;
				float32 fSysSamOutCurrent;
				float32 fSysSamNTC1;
				float32 fSysSamNTC2;
                } TypeSysSamScaParameter;
//================������������Ĭ�ϱ�����ʼ��===============================
#define SysSamScaParameter_DEFAULTS {{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0},0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}

//=================DSP�������ݴ�����ARM=========================================
typedef struct {
				float32 fSamDSPtoARMIu;
				float32 fSamDSPtoARMIv;
				float32 fSamDSPtoARMIw;

				float32 fSamDSPtoARMUu;
				float32 fSamDSPtoARMUv;
				float32 fSamDSPtoARMUw;

				float32 fSamDSPtoARMUdc;
				float32 fSamDSPtoARMNTC1;
				float32 fSamDSPtoARMNTC2;

				} TypeSamDSPtoARM;
//================�������ݱ���������ARM===============================
#define TypeSamDSPtoARM_DEFAULTS {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}
//=================DA����ѡ��=========================================
typedef struct {
				Uint16 uDA_NumCh1;//ͨ��1���
				Uint16 uDA_NumCh2;//ͨ��2���

				float32 fDA_DataCh1;//ͨ��1����
				float32 fDA_DataCh2;//ͨ��2����
				} TypeDAChoose;
//================DA���ݴ�����ARM===============================
#define TypeDAChoose_DEFAULTS {0,0,0.0,0.0}
//============ ȫ�ֱ�����ȫ�ֺ������� =============================

extern TypeAnalogInput AnalogInput;

extern TypeSysOffsetParameter SysSampOffset;

extern TypeSysSamScaParameter SysSamScaParameter;

extern TypeSamDSPtoARM  SysSamDSPtoARM;

extern TypeDAChoose DAOut;

void fnSysOffsetInit(TypeSysOffsetParameter *p);

void fnSysOffsetParameterCal(TypeSysOffsetParameter *p);

extern void fnParaUpdateSysSamScaParameter(void); 

//extern void fnWhileAISample(void);

#endif
//========================================================================
// No more.
//========================================================================


