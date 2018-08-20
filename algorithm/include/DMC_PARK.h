/*
// Version: V1.0
// Date: 	Mar 3, 2013
// Author:	csc @YD
//===========================================================================
//
// �ļ���:    DMC_PARK.h
//
// ��;:   	  PARK�任
//
// ˵����
//===========================================================================
*/
#pragma CODE_SECTION(fnParkCalc, "ramfuncs")

typedef struct {  
				  // ����
				  float32  fAlpha;  	// ����: alpha����  
				  float32  fBeta;		// ����: beta���� 
				  float32  fCos;		// ����: cos���� 
				  float32  fSin;        // ���룺sin����
				  // ���
				  float32  fDOut;		// �����D��
				  float32  fQOut;		// �����Q��

				 /*����*/
				 void     (*pfnCalc)();		// CLARKE���㺯��ָ��
				 void     (*pfnReset)();	// CLARKE��λ����ָ��
				 void     (*pfnInit)();		// CLARKE��ʼ������ָ��
				 
				 } PARK;	            

#define PARK_DEFAULTS { 0,0,0,0,\
						  0,0,\
						  (void (*)(Uint32))fnParkCalc,\
						  (void (*)(Uint32))fnParkReset,\
						  (void (*)(Uint32))fnParkInit }   
//===========================================================================
//PARK�Ĳ�����������
void fnParkCalc(PARK *p);
void fnParkReset(PARK *p);
void fnParkInit(PARK *p);


//===========================================================================
// No more.
//===========================================================================
