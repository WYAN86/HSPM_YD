/*
// Version: V1.0
// Date: 	Dec 21, 2012
// Author: Mayongjian
//===========================================================
//
// �ļ���:    MathBasic.h
//
// ��;:   	  ��ѧ���㺯����
//
// LPF()	��ͨ�˲�������ʱʹ�ã����Ƚϵͣ�����Ч�ʲ���
// Max()	������3����ȡ���ֵ
// Min()	������3����ȡ��Сֵ
// uMax()	������3����ȡ���ֵ
// uMin()	������3����ȡ��Сֵ
// uMid()	������3����ȡ�м�ֵ
// Mux3s1()	��ѡһѡ����
// 
//=============================================================
*/

#ifndef MATHBASIC_H
#define MATHBASIC_H
#include "DSP2833x_Device.h"



// ��ѧ��������
// float32��ʽ
#define PI            3.14159265
#define PI2      	  6.28318531
#define SQRT2By3      0.816496581
#define SQRT3_D2      0.866025404
#define SQRT3         1.73205080
#define SQRT2         1.41421356
#define f1_DSQRT2     0.70710678
#define SQRT3_DSQRT2  (SQRT3/SQRT2)
#define TWO_D_SQRT3   1.15470054
#define FOUR_D_3PI    (PI * 4.0 / 3.0)
#define TWO_D_3PI     (PI * 2.0 / 3.0)
#define VarAveToRMS   1.11072073	// = pi / (2 * sqrt(2))
#define N_PI2		  (-1.0)*(PI2)//
#define f4_D_3PI      (4.0/3.0)*(PI)//
#define f2_D_3PI      (2.0/3.0)*(PI)//
#define D2By3         0.66666667//

// float64��ʽ
#define f2_PI      		 3.1415926535897932384626433832795L
#define f2_PI2      	 6.283185307179586476925286766559L
#define f2_SQRT2By3    0.81649658092772603273242802490196L
#define f2_SQRT3_D2		 0.86602540378443864676372317075294L
#define f2_SQRT3       1.7320508075688772935274463415059L
#define f2_SQRT2       1.4142135623730950488016887242097L
#define f2_TWO_D_SQRT3 1.1547005383792515290182975610039L
#define f2_FOUR_D_3PI  (f2_PI * 4.0L / 3.0L)
#define f2_TWO_D_3PI   (f2_PI * 2.0L / 3.0L)
#define f2_VarAveToRMS 1.1107207345395915617539702475152L// = pi / (2 * sqrt(2))

// �꺯������
#define MAX(x,y)	(((x) >= (y)) ? (x) : (y))		// �����ֵ
#define MIN(x,y)	(((x) <= (y)) ? (x) : (y))		// ����Сֵ
#define POW2(x)  	((x) * (x))		
#define POW3(x)  	((x) * (x) * (x))		
#define UP_LIMIT(x, limit)		(x = MIN(x, limit))		// ���޷�
#define DOWN_LIMIT(x, limit)	(MAX(x, limit))				// ���޷�
#define DUAL_LIMIT(x, vmax, vmin)		(DOWN_LIMIT(UP_LIMIT(x, vmax), vmin))		// ˫���޷�
// ��������
extern float32 LPFKY(float fLPFVarIn,float fLPFVarInOld,float fLPFVarOutOld,float fLPFCutFre);
extern float Max(float a,float b,float c);
extern float Min(float a,float b,float c);
extern Uint16 uMax(Uint16 a,Uint16 b,Uint16 c);
extern Uint16 uMin(Uint16 a,Uint16 b,Uint16 c);
extern Uint16 uMid(Uint16 a,Uint16 b,Uint16 c);
extern float32 Mux3s1(Uint16 SelectSig,float32 fIn0,float32 fIn1,float32 fIn2);
extern int HysLoop(float32 fVarIn,float32 fVarCom,float32 fVarDeta);
extern float32 LPFCompensate(float32 fVarIn,float32 fVarInOld,float32 fTCon);
extern float32 Limit(float32 fMinIn,float32 fMaxIn,float32 fDateIn);
//extern float32 LPF(float32 fLPFVarIn,float32 fLPFTCon,float32 fLPFOutOld);
#endif

//========================================================================
// No more.
//========================================================================

