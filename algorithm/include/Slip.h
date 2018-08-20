
/*File name:       SLIP.H  */                   
                    





typedef struct { 
                  /*�������*/
                  float32  fIsmSet;  	// ���룺���ŵ�������  
				  float32  fIstSet;		// ���룺ת�ص�������

				  /*�������*/
				  float32  fSlipRate;   // �����������
				  float32  fSlipRr;     // ������ת�ӵ���
				  float32  fSlipLlr;    // ������ת��©��
				  float32  fSlipLm;     // ����������
                  
				  /*�м����*/
				  float32  fTrdSlip;

				  /*�������*/
				  float32  fSlipSet;	// ��������ݸ������������ת�� 
                  /*����ָ��*/
		 	 	  void  (*pfnSetcalc)();	// ָ����㺯��ָ��
				  void  (*pfnSetinti)();	// ָ����㺯��ָ��

				}SLIP;	            

                     
#define SLIP_DEFAULTS { 0,0,\
                        0,0,0,0,\
						0, \
                        0, \
              			(void (*)(Uint32))fnSlipset_Calc,\
              			(void (*)(Uint32))fnSlipset_Inti}


void fnSlipset_Calc(SLIP *p);
void fnSlipset_Inti(SLIP *p);



