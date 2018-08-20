// ����Զ���������
// 2013.5.24
//###########################################################################
//
// �ļ�����:   COMMInterface.h
//
// ����: �����ͨѶͷ�ļ����������Ͳ�����װ��ͬһ�ṹ��.
//
//###########################################################################
// �汾��: COMMInterface.h V1.3 $
// ������: ����
//###########################################################################


#ifndef COMMINTERFACE_H
#define COMMINTERFACE_H
//#include "DSP2833x_I2c_defines.h"
/***************************������   ������ ���� 2014.2.13****************************************************/
#define READ_PARAM_RTS      0x03 /* ARM������ */
#define READ_PARAM_ACK        0x93 /* ��������Ӧ */
#define WRITE_PARAM_RTS     0x0a /* д���� */
#define WRITE_PARAM_ACK       0x9a /* д������Ӧ */
#define RESTORE_DEF_RTS     0x07 /* �ָ��������� */
#define RESTORE_DEF_ACK       0x97 /* �ָ�����������Ӧ */
#define CHANGE_DEF_RTS      0x08 /* ���ĳ������� */
#define CHANGE_DEF_ACK        0x98 /* ���ĳ���������Ӧ */
#define READ_WAVE_RTS       0x13 /* ���������� */
#define READ_WAVE_ACK         0x83 /* ������������Ӧ */
#define READ_FAULTINFO_RTS  0x09 /* ������Ϣ */
#define READ_FAULTINFO_ACK    0x99 /* ��������Ϣ��Ӧ */
#define WRITE_CHANNEL_RTS   0x10 /* дͨ����Ϣ */
#define WRITE_CHANNEL_ACK     0x80 /* дͨ����Ϣ��Ӧ */
#define READ_FAULTWAVE_RTS  0x14 /* ���ϲ��� */
#define READ_FAULTWAVE_ACK    0x84 /* ���ϲ�����Ӧ */
/***************************************************************************************************************/

#define TimeStamp_Indexed  2198                       /////ʱ���ƫַ
#define WaveData_Indexed  2200                       /////��������ƫַ	
extern void InitWrFlash(Uint16 FlashStAddr,Uint32 *StartAddr,Uint16 LEN);//////��ʼ��FLASH�洢��
extern void DSP28x_usDelay(Uint32 Count);

#define DELAY_US1(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)6.667L ) - 9.0L) / 5.0L)
/*union TranFU
{
  float Float_data;
  Uint32  Long_data;
}TRANS_FU;
*/
typedef struct {

	/*����ָ��*/
	void (*pfnWaveDisplay)();       // ָ������ʾ������ָ��
	void (*pfnReadFPGA)();         // ָ���FPGA������ָ��
	void (*pfnInit)();            // ָ���ʼ��������ָ��
	void (*pfnFWaveLoad)();        // ָ����ϲ��λ��溯����ָ��

	/*�������*/
	Uint32 u2LineNumber;                   // ���룺�����ߺ�
	Uint32 u2SerialNumber;                 // ���룺��Ʒϵ�к�
	Uint32 u2ProductNumber;                // ���룺��Ʒ�汾��
	Uint32 u2FactoryNumber;                // ���룺�ڲ����
	Uint16 * ARMHandshakeWord;             ///// ARM��DSP���͵�������
	Uint16 * DSPHandshakeWord;             ///// DSP��ARM���͵�������
	Uint16 * ReceiveStartAdd;              //////����֡��ʼ��ַ
	Uint16 * DSPtoARMStartAdd;             //////DSP to arm����֡��ʼ��ַ
	Uint16 * WaveID_ADD;                  //////���ز���ID����ʼ��ַ 
	Uint16 * WaveData_StartADD;           //////����������ʼ��ַ
	Uint16 * DSP_RAM;                      ////DSP�ڲ�RAM��ʼ��ַ
	Uint16 uFaultCHADDR[16];               ////����ͨ����ַ
	Uint16 uFaultFlag;                     ////�������ϱ�־����Ϊ1ʱ�������¹��ϣ���¼���Ϻ�100�������Ϣ
										   ////  �������Լ�����������λʱ����ñ�־
	Uint16 uFaultCode;                     ///// ���ϱ��
	Uint16 FlashPramaCount;               /////�洢��FLASH�ڲ���������
	Uint16 uDateInfoAddr;                 ////������Ϣ��ʼ��ַ
	Uint16 uTimeInfoAddr;                 ////ʱ����Ϣ��ʼ��ַ
	float32 *fInitFlashADD;
	Uint16 uInitFlashNum;
	Uint32 u2InitFlashFV;

	/*�ڲ�����*/
	Uint16 ReadFpgaS2[1200];
	Uint16 WaveINTReadNum;                ///�ж϶��������ݴ���
	Uint16 WavePack;                     ////���ز��ΰ�����
	Uint16 uSampRate;                 //////������
	Uint16 uSampInterval;             ////���������
	Uint16 uSampIntervalbuf;             ////�������������
	Uint16 CHANLEADDR[6];
	/*
	һ�α���10������
	20*50*4/2
	*/
//	Uint16 CHANLE0[1000];
//	Uint16 CHANLE1[1000];
//	Uint16 CHANLE2[1000];
//	Uint16 CHANLE3[1000];
//	Uint16 CHANLE4[1000];
//	Uint16 CHANLE5[1000];
	Uint16 WaveID[10];/* ��¼����ID */
	Uint16 ucMaxWaveID;
	/* ���ζ�дָ�� */
	Uint16 uWaveWriePos;
	Uint16 uWaveReadPos;

	Uint32 u2StartAddressRead;
	Uint32 u2StartAddressWrite;
	Uint16 * pFaultWbuf;       /////���ϲ��λ�����
	Uint16 uFaultMNum;        /////����ǰ�������洢����
	Uint16 uFaultANum;        ////���Ϻ󻺳����洢����
	Uint16 uFaultLStop;       ////���ϻ���ֹͣ��־
	Uint16 pTimeInfo[7];   /////��ȡʱ����Ϣ
	Uint16 uRefreshTC;       /////ˢ��ʱ��ļ���

	//I2CMSG *CurrentMsgPtr;

	/*�������*/
	Uint16 uWrFlashErr;           ////дFLASH���̴�����Ϣ

} COMMUN;

void DisplayWave(COMMUN *p);
void InitCommun(COMMUN *p);
void ReadFromFPGA(COMMUN *p);
void FaultWaveMemory(COMMUN *p);


#define COMM_DEFAULTS 	{ \
						(void (*)(Uint32))DisplayWave, \
						(void (*)(Uint32))ReadFromFPGA, \
						(void (*)(Uint32))InitCommun, \
						(void (*)(Uint32))FaultWaveMemory \
						}
void DisplayWave(COMMUN *PP);

extern COMMUN sInComm;
#endif 







