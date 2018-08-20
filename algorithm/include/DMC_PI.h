/*
// Version: V1.0 �ļ�����
// Date: 	Oct 25, 2012
// Author:	csc @YD
//==========================================================================
//
// �ļ���:	DMC_PI.h
//
// ��;:   PIͷ�ļ�
//
//==========================================================================
*/
/*��ʼ��
sPi.fKp 		= 0;
sPi.fKi 		= 0;
sPi.fSampleFreq = 5000;
sPi.fOutMax		= 1;
sPi.fOutMin		= -1;
sPi.fIntgInit	= 0;
sPi.pfnInit(&//sPi);
*/
/*����
sPi.fRef1 = 0;
sPi.fRef2 = 0;
sPi.fFdb1 = 0;
sPi.fFdb2 = 0;
sPi.pfnCalc(&//sPi);
*/
#pragma CODE_SECTION(fnPiCalc, "ramfuncs")

//==========================================================================
// PI״̬��
struct PI_SW_BITS {		// bits	description
    Uint16  IntgULmt:1;     // 0	��������	
	Uint16  IntgLLmt:1;		// 1   	��������
	Uint16  OutULmt:1;		// 2	�������
	Uint16  OutLLmt:1;		// 3	�������
    Uint16  rsvd:12;      	// 4~15 reserved
};
union PI_SW_REG {
   Uint16				all;
   struct PI_SW_BITS   bit;
};

//==========================================================================
// PI�ṹ��
typedef struct {  
				  //����
				  float32  fRef1;   	// ����: �ο�����1
				  float32  fRef2;		// ����: �ο�����2
				  float32  fFdb1;   	// ����: ��������1
				  float32  fFdb2;		// ����: ��������2
				   
				  /*�������*/
				  float32  fKp;			// ����: ����ϵ��
				  float32  fKi;			// ����: ����ϵ��
				  float32  fSampleFreq;	// ����������Ƶ��
				  float32  fOutMax;		// ����: ����ֵ 
				  float32  fOutMin;		// ����: ����ֵ
				  float32  fIntgInit;	// ����: ���ֳ�ʼֵ

				  /*״̬����*/
				  float32  fErr;		// ������������-����
				  float32  fKiTs;		// ����������ϵ����Ki/SampleFreq
				  float32  f2Intg;		// ����: �����ۼ���

				  /*���*/
				  float32  fOut;   			// ���: PI���
				  union    PI_SW_REG sPiSw; // ���: PI״̬��

				  /*����*/
				  void     (*pfnCalc)();		// PI���㺯��ָ��
				  void     (*pfnReset)();		// PI��λ����ָ��
				  Uint16   (*pfnInit)();		// PI��ʼ������ָ��
				 } PIREG;	            

//===========================================================================
//PIREG��Ĭ�ϳ�ʼ������

#define PIREG_DEFAULTS { 0,0,0,0,\
						  0,0,0,0,0,0,\
						  0,0,0,\
						  0,0,\
						  (void (*)(Uint32))fnPiCalc,\
						  (void (*)(Uint32))fnPiReset,\
						  (Uint16 (*)(Uint32))fnPiInit }

//===========================================================================
//PIREG�Ĳ�����������
void fnPiCalc(PIREG *p);
void fnPiReset(PIREG *p);
Uint16 fnPiInit(PIREG *p);


//===========================================================================
// No more.
//===========================================================================
