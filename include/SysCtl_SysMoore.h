/*
//===================================================================
//
// �ļ���:	SysCtl_Moore.h
//
// ��;:    ϵͳ״̬��ͷ�ļ�
//
// �ṹ�壺
//         TypeSysMooreState     //ϵͳ״ֵ̬����
//         TypeSysMoore          //ϵͳ״̬��
//
//===================================================================
*/

#ifndef SYSCTL_SYSMOORE_H
#define SYSCTL_SYSMOORE_H


//===== ϵͳ״̬���� ===========================
typedef enum {
				SysErr = 1,         //ϵͳ����
				SysInit = 2,        //ϵͳ��ʼ��
				ControllerReady = 3,//����������
				SysPrecharge = 4,   //ϵͳԤ���
				SystemReady = 5,    //ϵͳ����
				SystemRun = 6      //ϵͳ����
             } TypeSysMooreState;

//===== ϵͳ״̬���ṹ�� ====================================
typedef struct {
                //״ֵ̬���
                TypeSysMooreState SysStateNew;//ϵͳ��״ֵ̬
				TypeSysMooreState SysStateOld;//ϵͳ��״ֵ̬

                //����

				void (*pfnSysMooreCal)();//ϵͳ״̬������

                } TypeSysMoore;

                //��ʼֵ
#define SysMoore_DEFAULTS {SystemReady,SystemReady, \
                          (void (*)(Uint32))fnSysMooreCal}

                //��������
void fnSysMooreCal(TypeSysMoore *p);

extern void fnVarCopyToRam(Uint16 *HeadAddr,float32 *pVarAddr,Uint16 AddrBias);

extern float fTimeCount;

extern float iq_load;

#endif

//========================================================================
// No more.
//========================================================================

