/*
File name:       CLARKE.H
                    
#pragma CODE_SECTION(fnIclarke_Calc, "ramfuncs")

typedef struct { 
                  �������
                  float32  fAs;  	// ��������ඨ������ϵA��  
				  float32  fBs;		// ��������ඨ������ϵB��
				  float32  fCs;		// ��������ඨ������ϵC��  
				  �������
				  float32  fAlpha;	// ���룺���ྲֹ����ϵA�� 
				  float32  fBeta;	// ���룺���ྲֹ����ϵB�� 
                  ����ָ��
		 	 	  void  (*pfnIcalc)();	// ָ����㺯��ָ��
				}ICLARKE;	            

                     
#define ICLARKE_DEFAULTS { 0, \
                          0, \
						  0,\
                          0, \
                          0, \
              			  (void (*)(Uint32))fnIclarke_Calc }


void fnIclarke_Calc(ICLARKE *p);*/




