/* =================================================================================
File name:       PARK.H                     
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
Header file containing constants, data type definitions, and 
function prototypes for the PARK.

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 04-15-2005	Version 3.20                                                 
------------------------------------------------------------------------------*/

typedef struct {  /*�������*/
				  float32  fFref;       //���룺����Ƶ��
				  float32  fPhrAct;     //���룺��ǰת�Ӵ���

				  /*�������*/
				  float32  fFrLow;      //���������űջ����õ�Ƶ�ʹյ�
				  float32  fExccurSet;  //���������ŵ����ⲿ����
				  float32  fPhrRef;     //������ʵ��ת������
				  float32  fPhrKp;      //������ת������Kp
				  float32  fPhrKi;      //������ת������Ki
				  float32  fPhrUpLmt;   //������ת�����Ż�������ֵ
				  float32  fPhrLwLmt;   //������ת�����Ż������Сֵ
                  
				  /*�������*/
				  float32  fExccurOut;  //��������ŵ�������

		 	 	  void  (*pfnExcurcalc)();
		 	 	  void  (*pfnExcurreset)();	 
				 } EXCITCURRENT;	            

typedef EXCITCURRENT *EXCITCURRENT_handle;

/*-----------------------------------------------------------------------------
Default initalizer for the PARK object.
-----------------------------------------------------------------------------*/                     
#define EXCITCURRENT_DEFAULTS {  0,0.0,\
                                 0.06,0.3,0.95,0.0,0.0,0.3,-0.3,\
                                 0, \
              			         (void (*)(Uint32))fnExcur_calc,\
              			         (void (*)(Uint32))fnExcur_reset}
              			  
/*------------------------------------------------------------------------------
Prototypes for the functions in PARK.C
------------------------------------------------------------------------------*/
void fnExcur_calc(EXCITCURRENT_handle);
void fnExcur_reset(EXCITCURRENT_handle);


