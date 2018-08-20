/*
// Version: V1.0
// Date: 	Mar 3, 2013
// Author:	KEGY @YD
//===========================================================================
//
// �ļ���:    SPEED_KPKI.h
//
// ��;:   	  ת�ٻ�KpKi����
//
// ˵����
//===========================================================================
*/
typedef struct {  
				  /*�������*/
				  float32  fFrRef;  	        // ����: ����Ƶ��
				  
				  /*�������*/  
				  Uint16   uMethod;		        // ����: ʸ�����Ʒ���ѡ�� 
				  float32  fSpdKpmin_VC;		// ����: VC�ٶȻ�Kp��Сֵ 
				  float32  fSpdKpmax_VC;        // ����: VC�ٶȻ�Kp���ֵ
				  float32  fSpdKpmin_SLVC;		// ����: SLVC�ٶȻ�Kp��Сֵ 
				  float32  fSpdKpmax_SLVC;      // ����: SLVC�ٶȻ�Kp���ֵ
				  float32  fSpdKi_VC_SLVC;      // ����: �ٶȻ�Ki

				  /* ��� */
				  float32  fSpdKp;		        // ������ٶȻ�Kp
				  float32  fSpdKi;		        // ������ٶȻ�Ki

				  /*����*/
				  void     (*pfnCalc)();		// ���㺯��ָ��
				  void     (*pfnReset)();	    // ��λ����ָ��
				 
				 } SPEEDKPKI;	            

#define SPEEDKPKI_DEFAULTS {  0,\
	                          0,2.0,4.0,2.0,4.0,0.1,\
							  2.0,0.1,\
							  (void (*)(Uint32))fnSppiCalc,\
							  (void (*)(Uint32))fnSppiReset }   
//===========================================================================
//SPEEDKPKI�Ĳ�����������
void fnSppiCalc(SPEEDKPKI *p);
void fnSppiReset(SPEEDKPKI *p);



//===========================================================================
// No more.
//===========================================================================
