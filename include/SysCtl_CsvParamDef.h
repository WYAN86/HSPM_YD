
#ifndef SYSCTL_CSVPARAMDEF_H
#define SYSCTL_CSVPARAMDEF_H
extern Uint16 HMIBuffer[2000];

//#define pCsvParamHead		    ((float32*)0x119000) // ���붨��Ϊ32λ��ָ�룬����ƫ����Ӧ����2��  �Ƿ�Ӧ�� -
#define pCsvParamHead   (float32*)&HMIBuffer[0]
//===== ϵͳ������ =====
#define pCsvParamSysCtlWord          ((Uint32*) (pCsvParamHead + 268));  //ϵͳ������

#define pCsvParamDebugMD             ((float32*) (pCsvParamHead + 58));  //���Ƶ����

#define pCsvParaSampleOffset       ((float32*) (pCsvParamHead + 463));  //��Ư�趨ֵ��ʼ��ַ
 
#define pCsvParamOCPRO              ((float32*) (pCsvParamHead + 140));  //˲ʱ���� ����ֵ
#define pCsvParaStartMod            ((float32*) (pCsvParamHead + 289));  //������ʽ

//=====�ز�Ƶ��============
#define pCsvCarrierFre				((float32*) (pCsvParamHead + 383))  //����Ƶ�ʣ�Ҳ��DSP���жϱ���
#define pCsvChopwaveFre				((float32*) (pCsvParamHead + 384))  //ն��Ƶ��
#define pCsvChopDutyCycle			((float32*) (pCsvParamHead + 385))  //�ز�ռ�ձ�
#define pCsvARMInterMultiple		((float32*) (pCsvParamHead + 386))  //ARM���жϱ���
#define pCsvDspFiberChopEnable		((float32*) (pCsvParamHead + 387))  //����ն��ʹ��


//=======VF���߲���========
#define pCsvParamFreqStart            ((float32*) (pCsvParamHead + 394));  //ʼ��Ƶ��
#define pCsvParamVF_VoltMin           ((float32*) (pCsvParamHead + 368));  //��͵�ѹ
#define pCsvParamVF_FreqPoint1        ((float32*) (pCsvParamHead + 369));  //Ƶ�ʵ�1
#define pCsvParamVF_VoltPoint1        ((float32*) (pCsvParamHead + 370));  //��ѹ��1
#define pCsvParamVF_FreqPoint2        ((float32*) (pCsvParamHead + 371));  //Ƶ�ʵ�2
#define pCsvParamVF_VoltPoint2        ((float32*) (pCsvParamHead + 372));  //��ѹ��2
#define pCsvParamVF_FreqMax           ((float32*) (pCsvParamHead + 373));  //���Ƶ��
#define pCsvParamVF_VoltMax           ((float32*) (pCsvParamHead + 374));  //��ߵ�ѹ

//=====��������=======
//#define pCsvParamSamCurrentRatio      ((float32*) (pCsvParamHead + 187));  //�������������
//#define pCsvParamSamVoltageRatio      ((float32*) (pCsvParamHead + 188));  //��ѹ���������

//===== ����� =====
#define pCsvParamMotorRatedVoltage   ((float32*) (pCsvParamHead + 450));  //������ѹ                                 
#define pCsvParamMotorRatedCurrent   ((float32*) (pCsvParamHead + 451));  //��������                                 
#define pCsvParamMotorRatedFre       ((float32*) (pCsvParamHead + 452));  //����Ƶ��                                 
#define pCsvParamMotorRatedPower     ((float32*) (pCsvParamHead + 453));  //��������                                 
#define pCsvParamMotorRateSpeed      ((float32*) (pCsvParamHead + 454));  //����ת��                                 
#define pCsvParamMotorPoleNum        ((float32*) (pCsvParamHead + 455));  //���������                                  
#define pCsvParamMotorRatedSlip      ((float32*) (pCsvParamHead + 456));  //����ת����        
#define pCsvParamVFDInputVolatge     ((float32*) (pCsvParamHead + 457));  //��Ƶ��������ѹ                               
#define pCsvParamVFDInputCurrent     ((float32*) (pCsvParamHead + 458));  //��Ƶ����������                           
#define pCsvParamVFDRatedPower       ((float32*) (pCsvParamHead + 459));  //��Ƶ�������                               
#define pCsvParamVFDInputFre         ((float32*) (pCsvParamHead + 460));  //��Ƶ�������Ƶ��                           
#define pCsvParamVFDOutputVoltage    ((float32*) (pCsvParamHead + 461));  //��Ƶ��������ѹ                           
#define pCsvParamVFDOutputCurrent    ((float32*) (pCsvParamHead + 462));  //��Ƶ���������� 

#define pCsvParaConRunType           ((float32*) (pCsvParamHead + 273));  //��Ƶ�����Ʒ�ʽ
#define pCsvParaVFDLoadType          ((float32*) (pCsvParamHead + 274));  //��������
#define pCsvParaConStrategy          ((float32*) (pCsvParamHead + 275));  //���Ʋ���

#define pCsvParamDACH1 				 ((float32*) (pCsvParamHead + 741));
#define pCsvParamDACH2				 ((float32*) (pCsvParamHead + 746));

#define pCsvParamVol_ManualSet       ((float32*) (pCsvParamHead + 20))  //�ֶ����������ѹ����ֵ

#define pCsvParamSamDCVoltage        ((float32*) (pCsvParamHead + 473));  //ֱ����ѹ����DSP 3V��Ӧ���ĸ�ߵ�ѹ����V
#define pCsvParamSamOutCurrent       ((float32*) (pCsvParamHead + 474));  //��������DSP 3V��Ӧ��������A
#define pCsvParamSamOutVoltage       ((float32*) (pCsvParamHead + 475));  //������ѹDSP 3V��Ӧ��ѹ����V
#define pCsvParamSamNTC1             ((float32*) (pCsvParamHead + 476));  //NTC1 DSP 3V��Ӧ����������ֹ����ŷķ
#define pCsvParamSamNTC2             ((float32*) (pCsvParamHead + 477));  //NTC2 DSP 3V��Ӧ����������ֹ����ŷķ

#define pCsvParamOCPrtVal  		((float32*) (pCsvParamHead + 760)); //����˲ʱֵ����
#define pStateNew				((Uint32*) (pCsvParamHead + 261));

//=========ʸ�������㷨=======
#define pCsvParamFreSet			((float32*) (pCsvParamHead + 393));//Ƶ�ʸ���

#define pCsvParamAsynRs           ((float32*) (pCsvParamHead + 57));//���ӵ���
#define pCsvParamAsynRr           ((float32*) (pCsvParamHead + 58));//ת�ӵ���
#define pCsvParamAsynLs           ((float32*) (pCsvParamHead + 59));//����©��
#define pCsvParamAsynLr           ((float32*) (pCsvParamHead + 60));//ת��©��
#define pCsvParamAsynLm           ((float32*) (pCsvParamHead + 61));//����

#define pCsvParamExcitCurrentST   ((float32*) (pCsvParamHead + 33));//���ŵ�����ʼֵ
#define pCsvParamExcitationCurrent   ((float32*) (pCsvParamHead + 34));//��������
#define pCsvParamExcitationTime    ((float32*) (pCsvParamHead + 35));//����ʱ��


#define pCsvParamPhrKp             ((float32*) (pCsvParamHead + 39));//ת�Ӵ����ջ�KP
#define pCsvParamPhrKi             ((float32*) (pCsvParamHead + 40));//ת�Ӵ����ջ�Ki
#define pCsvParamPhrLoopStartFreq  ((float32*) (pCsvParamHead + 54));//ת�Ӵ����ջ���ʼƵ��

#define pCsvParamCNT_FR_VALUE      ((float32*) (pCsvParamHead + 53));//ת�ؼ�������
#define pCsvParamSLVCSpeedKpMAX      ((float32*) (pCsvParamHead + 29));//�ٶȻ�KP���ֵ
#define pCsvParamSLVCSpeedKpMIN      ((float32*) (pCsvParamHead + 28));//�ٶȻ�KP��Сֵ
#define pCsvParamSpeedLoopKi       ((float32*) (pCsvParamHead + 30));//�ٶȻ�Ki
#define pCsvParamSpeedLOutMin       ((float32*) (pCsvParamHead + 31));//�ٶȻ������Сֵ
#define pCsvParamSpeedLOutMax       ((float32*) (pCsvParamHead + 32));//�ٶȻ�������ֵ
#define pCsvParamCurrentKp          ((float32*) (pCsvParamHead + 36));//������Kp
#define pCsvParamCurrentKi          ((float32*) (pCsvParamHead + 37));//������Ki

#define pCsvParamRotorFluxGiven     ((float32*) (pCsvParamHead + 38));//��������ֵ
#define pCsvParamRotorFluxOutMin     ((float32*) (pCsvParamHead + 41));//���������Сֵ
#define pCsvParamRotorFluxOutMax     ((float32*) (pCsvParamHead + 42));//����������ֵ

#define pCsvParamSpeedEstKp     ((float32*) (pCsvParamHead + 43));//���ƻ�KP
#define pCsvParamSpeedEstKiMIN     ((float32*) (pCsvParamHead + 44));//���ƻ�KI��Сֵ
#define pCsvParamSpeedEstKiMID     ((float32*) (pCsvParamHead + 45));//���ƻ�Ki�м�ֵ
#define pCsvParamSpeedEstKiMAX     ((float32*) (pCsvParamHead + 46));//���ƻ�Ki���ֵ

#define pCsvParamSpeedEstFrRefFly  ((float32*) (pCsvParamHead + 47));//�ɳ�������ʼƵ��
#define pCsvParamSpeedEstKpFly     ((float32*) (pCsvParamHead + 48));//�ɳ���������Kp
#define pCsvParamSpeedEstKiMINFly  ((float32*) (pCsvParamHead + 49));//�ɳ���������ki��С
#define pCsvParamSpeedEstKiMIDFly  ((float32*) (pCsvParamHead + 50));//�ɳ���������ki�м�
#define pCsvParamSpeedEstKiMAXFly  ((float32*) (pCsvParamHead + 51));//�ɳ���������KI���
#endif

//============================                                                                                                                                                                                                                                                                                                                       
// No more.
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
