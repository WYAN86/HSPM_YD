/*
// Version: V1.0 �ļ�����
// Date: 	DEC 21, 2012
// Author:	csc @YD
//==========================================================================
//
// �ļ���:	DMC_CLARKE.h
//
// ��;:  CLARKE�任ͷ�ļ�
//
// ˵����
// sCw.Iuvw=1������Ϊuvw���ࣻAlpha = 1/3*(2*fU - fV - fW), Beta = (fV - fW)/1.732
// sCw.Iuv=1������Ϊuv���ࣻAlpha = fU, Beta = (fU + 2*fV)/1.732
//==========================================================================
*/
//�����֣����������ʽѡ��

#pragma CODE_SECTION(fnClarkeCalc, "ramfuncs")

struct CLARKE_CW_BITS {    		// bits  description
    Uint16  Iuvw:1;      		// 0   
	Uint16  Iuv:1;				//
    Uint16  rsvd:14;      		// 14  reserved
};
union CLARKE_CW_REG {
   Uint16                	all;
   struct CLARKE_CW_BITS   	bit;
};
#define CLARKE_UVW    0x0001
#define CLARKE_UV     0x0002

typedef struct {
				  // ����
				  float32  fU;  		// ����: U������
				  float32  fV;			// ����: V������
				  float32  fW;			// ����: W������
				  union    CLARKE_CW_REG   sCw;

				  // ���
				  float32  fAlpha;		// �����Alpha
				  float32  fBeta;		// �����Beta

				 /*����*/
				 void     (*pfnCalc)();		// CLARKE���㺯��ָ��
				 void     (*pfnReset)();	// CLARKE��λ����ָ��
				 void     (*pfnInit)();		// CLARKE��ʼ������ָ��

				 } CLARKE;	            

#define CLARKE_DEFAULTS { 0.0,0.0,0.0,\
						  0,\
						  0.0,0.0,\
						  (void (*)(Uint32))fnClarkeCalc,\
						  (void (*)(Uint32))fnClarkeReset,\
						  (void (*)(Uint32))fnClarkeInit }
//===========================================================================
//CLARKE�Ĳ�����������
void fnClarkeCalc(CLARKE *p);
void fnClarkeReset(CLARKE *p);
void fnClarkeInit(CLARKE *p);


//===========================================================================
// No more.
//===========================================================================
