
#include "DSP2833x_Device.h"    
#include "SysCtl_AllHeaders.h"


union TranFU
{
	float Float_data;
	Uint32  Long_data;
}TRANS_FU;
//------д�ڲ�FLASH-----------//
void MyCallbackFunction(void); 
void Example_MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);
Uint16 fWriteIntFlash(Uint16 *uBuffer,Uint16 ulength);

void WriteToFPGA(COMMUN *p);
//Uint16 CopyZoneDefaul(Uint16 StartAddr,Uint16 LEN,COMMUN *p);

/***************************���ú���****************************************************/
Uint16 GetFuncIDByte(Uint16 ucFunID);/* ��ȡ������ */
Uint16 RetFuncID(Uint16 ucFunID,Uint16 ucDeviceID);/* ���ع����� */
Uint16 GetFirstChar(Uint16 ucWord);/* ��ȡһ���ֽ��еĵ�һ���ֽ� */
Uint16 GetLastChar(Uint16 ucWord);/* ��ȡһ���ֽ��еĵڶ����ֽ� */

Uint16 GetFirstChar(Uint16 ucWord)
{
    return ucWord>>8;
}
Uint16 GetLastChar(Uint16 ucWord)
{
    return ucWord&0xff;
}
Uint16 GetFuncIDByte(Uint16 ucFunID)
{
    return ucFunID>>8;
}
Uint16 RetFuncID(Uint16 ucFunID,Uint16 ucDeviceID)
{
    return (ucFunID<<8 | (ucDeviceID&0x00ff));
}

void DisplayWave(COMMUN *p)
{

	    /* һ����������Ϊ4�ֽ�,ʹ����������������ַ���� */
		*(pWaveParamStart)=p->DSP_RAM[p->CHANLEADDR[0]>>1];           ///������CHANLE0�ڴ�CHANLEADDR[0]��Ӧ��RAM������
		*(pWaveParamStart+1)=p->DSP_RAM[(p->CHANLEADDR[0]>>1)+1];

		*(pWaveParamStart+2)=p->DSP_RAM[p->CHANLEADDR[1]>>1];          ///ͬ��
		*(pWaveParamStart+3)=p->DSP_RAM[(p->CHANLEADDR[1]>>1)+1];

		*(pWaveParamStart+4)=p->DSP_RAM[p->CHANLEADDR[2]>>1];
		*(pWaveParamStart+5)=p->DSP_RAM[(p->CHANLEADDR[2]>>1)+1];

		*(pWaveParamStart+6)=p->DSP_RAM[p->CHANLEADDR[3]>>1];
		*(pWaveParamStart+7)=p->DSP_RAM[(p->CHANLEADDR[3]>>1)+1];

		*(pWaveParamStart+8)=p->DSP_RAM[p->CHANLEADDR[4]>>1];
		*(pWaveParamStart+9)=p->DSP_RAM[(p->CHANLEADDR[4]>>1)+1];

		*(pWaveParamStart+10)=p->DSP_RAM[p->CHANLEADDR[5]>>1];
		*(pWaveParamStart+11)=p->DSP_RAM[(p->CHANLEADDR[5]>>1)+1];

}

void FaultWaveMemory(COMMUN *p)
{
	Uint16 i,value;   
	float32 *address;
	/* ��¼�ϴι�����Ϣ ���ϴι��ϻ�û�д��꣬�������¼�µĹ�����Ϣ*/	
	if (1 == p->uFaultLStop)
	{
		return;
	}	
	
	/* �޹��ϣ�ѭ����¼ǰ400�������Ϣ */	
	if (0 == p->uFaultFlag)
	{
		for(i=0;i<16;i++)
		{
			address=(float32*)(p->DSP_RAM+(p->uFaultCHADDR[i]>>1));
			value=*address;
			*(p->pFaultWbuf+1000*i+p->uFaultMNum)=*(p->DSP_RAM+(value>>1));
			*(p->pFaultWbuf+1000*i+p->uFaultMNum+1)=*(p->DSP_RAM+(value>>1)+1);
		}
		p->uFaultMNum+=2;
		if(p->uFaultMNum>798) p->uFaultMNum=0;
	}	
 	else
	{
		for(i=0;i<16;i++)
		{
			address=(float32*)(p->DSP_RAM+(p->uFaultCHADDR[i]>>1));
			value=*address;
			*(p->pFaultWbuf+800+1000*i+p->uFaultANum)=*(p->DSP_RAM+(value>>1));
			*(p->pFaultWbuf+800+1000*i+p->uFaultANum+1)=*(p->DSP_RAM+(value>>1)+1);
		}
		p->uFaultANum+=2;
		if(p->uFaultANum>198) 
		{
			p->uFaultANum=0;
			p->uFaultLStop=1;
		}
	}

}

/*��ʼ��ͨѶ���ܺ���*/
void InitCommun(COMMUN *p)
{
	p->uFaultMNum=0;
	p->uFaultANum=0;
	p->uFaultLStop=0;        ////���ֹͣ�����־
	p->uFaultFlag=0;         ////������ϱ�־


    /* ���ζ�дָ�� */
    p->uWaveWriePos = 0;
    p->uWaveReadPos = 0;
    p->WavePack = 0;
    p->ucMaxWaveID=0;
}

/*��FPGA������*/
void ReadFromFPGA(COMMUN *p)
{
	Uint16 ReadNum,ByteNum=0,HandshakeCode;
	HandshakeCode=*(p->ARMHandshakeWord)&0x00ff;    ////��������

	switch(HandshakeCode)                          ////����������ִ����Ӧ����
	{
	case READ_PARAM_RTS:     /////������
		for(ReadNum=0;ReadNum<3;ReadNum++)
		{
			p->ReadFpgaS2[ReadNum]=*(p->ReceiveStartAdd+ReadNum);
		}
		p->WaveINTReadNum=0;
		
		WriteToFPGA(p);
		break;
	case WRITE_PARAM_RTS:    ////д����,���ݳ��Ȳ�����֡ͷ֡β
	    for(ReadNum=0;ReadNum<3;ReadNum++)
		{
			p->ReadFpgaS2[ReadNum]=*(p->ReceiveStartAdd+ReadNum);
		}
		ByteNum= p->ReadFpgaS2[2]/2;
		for(ReadNum=3;ReadNum<ByteNum + 3;ReadNum++)
		{
			p->ReadFpgaS2[ReadNum] = *(p->ReceiveStartAdd+ReadNum);
		}
		p->WaveINTReadNum=0;
		WriteToFPGA(p);
		
		//FPGA_SetCarrier(p->ReadFpgaS2[1],p->ReadFpgaS2[2]);
		break;
	case RESTORE_DEF_RTS:    ////�ָ���������
		for(ReadNum=0;ReadNum<2;ReadNum++)
		{
			p->ReadFpgaS2[ReadNum]=*(p->ReceiveStartAdd+ReadNum);
		}
		
		*(p->DSPtoARMStartAdd)=RetFuncID(RESTORE_DEF_ACK,p->ReadFpgaS2[0]);
        /* ��ʼ��ַ */
        *(p->DSPtoARMStartAdd+1)=0;
        /* ���� */
        *(p->DSPtoARMStartAdd+2)=2;
		/* Ĭ�Ͽ��Զ�д�ɹ� */
		* (p->DSPtoARMStartAdd+3)=0x01;
		//* (p->DSPtoARMStartAdd+3)=0x0f;
		*(p->DSPHandshakeWord)=RESTORE_DEF_ACK;
		if(RESTORE_DEF_RTS == GetFuncIDByte(p->ReadFpgaS2[0]))
		//uReDefSuc=CopyZoneDefaul(0,1000,p);
//		CopyZoneDefaul(0,1000,p);
		break;
	case CHANGE_DEF_RTS:   ////����������ã������صĲ���д�뵽������flash
        for(ReadNum=0;ReadNum<3;ReadNum++)
		{
			p->ReadFpgaS2[ReadNum]=*(p->ReceiveStartAdd+ReadNum);
		}
		p->ReadFpgaS2[3] = 0;
		ByteNum= p->ReadFpgaS2[2]/2;
		for(ReadNum=4;ReadNum<ByteNum + 3;ReadNum++)
		{
			p->ReadFpgaS2[ReadNum] = *(p->ReceiveStartAdd+ReadNum);
		}
        WriteToFPGA(p);
		break;
	case WRITE_CHANNEL_RTS:    /* дͨ����Ϣ */
		for(ReadNum=0;ReadNum<9;ReadNum++)   
		{
			p->ReadFpgaS2[ReadNum]=*(p->ReceiveStartAdd+ReadNum);
		}
        WriteToFPGA(p);
		p->uSampRate=p->ReadFpgaS2[8];     ////������
        /*  ϵͳ������Ϊ2K�����Բ��β��������Ϊ2K���˴�������ٸ���������ȥ���岨�� */
        p->uSampRate=2000/p->uSampRate;                        
        p->uSampIntervalbuf=p->uSampRate;
		p->uSampInterval=p->uSampIntervalbuf;
		for(ReadNum=0;ReadNum<6;ReadNum++)   
		{ 
			p->CHANLEADDR[ReadNum]=p->ReadFpgaS2[ReadNum+2];
		}
       	* (p->DSPtoARMStartAdd)=RetFuncID(WRITE_CHANNEL_ACK,p->ReadFpgaS2[0]);
        * (p->DSPtoARMStartAdd+1)=0;
		*(p->DSPHandshakeWord)=WRITE_CHANNEL_ACK;
		break;
    case READ_WAVE_RTS:    ///����������
		break;    
	case READ_FAULTWAVE_RTS:     /////�����ϲ��� ���ȶ�ȡ������Ϣ���ٶ�ȡ���ϲ���
		break;
	default:

		break;
	}
    
	*(p->ARMHandshakeWord) = 0;
}

/*�����·������������֡*/
void WriteToFPGA(COMMUN *p)
{
	Uint16 ReadNum,ByteNum=0,DataNum =0;
	Uint16 StartAddress; 

 //   static Uint16 bHasReadWave = I2C_FALSE;
 //   static Uint16 uLastTimeStamp = 0;
 //   Uint16 uRequireSendStamp =0;
	switch(GetFirstChar(p->ReadFpgaS2[0]))
	{
	case READ_PARAM_RTS://///������
		StartAddress=p->ReadFpgaS2[1]/2;
		ByteNum= p->ReadFpgaS2[2]/2;
        /* ������ */
        *(p->DSPtoARMStartAdd) = RetFuncID(READ_PARAM_ACK,p->ReadFpgaS2[0]);
        *(p->DSPtoARMStartAdd + 1)=StartAddress*2;
        *(p->DSPtoARMStartAdd + 2)=ByteNum*2;
        
		for(ReadNum=0;ReadNum<ByteNum;ReadNum++)      ////���ݵ�ַ����RAM������
		{
			*(p->DSPtoARMStartAdd+3+ReadNum)= *(p->DSP_RAM+StartAddress+ReadNum);
		}
		*(p->DSPHandshakeWord)=READ_PARAM_ACK;	
		break;
	case WRITE_PARAM_RTS:
		StartAddress=p->ReadFpgaS2[1]/2;
		ByteNum=p->ReadFpgaS2[2]/2;
		for(ReadNum=0;ReadNum<ByteNum;ReadNum++)
		{
			* (p->DSP_RAM+StartAddress+ReadNum)= p->ReadFpgaS2[3+ReadNum];
		}
        /* �������� */
        *(p->DSPtoARMStartAdd) = RetFuncID(WRITE_PARAM_ACK,p->ReadFpgaS2[0]);
        *(p->DSPtoARMStartAdd + 1)=StartAddress*2;
        *(p->DSPtoARMStartAdd + 2)=ByteNum*2;
		*(p->DSPHandshakeWord)=WRITE_PARAM_ACK;

	    //�ز�Ƶ�ʸ���
	    if(StartAddress == 766 //����Ƶ��
	    || StartAddress == 768 //ն��Ƶ��
		|| StartAddress == 770 //ն��ռ�ձ�
		|| StartAddress == 772 //DSP���ж�Ƶ�ʱ���
		|| StartAddress == 774 //����ն��ʹ��
		|| (StartAddress == 0 && ByteNum == 1000) //��ʼ������Ҫ����
		)  //1532/2=766
	    {
	    	SysConTest.Enable = 1;
	    }


		break;
    case CHANGE_DEF_RTS:  
    	StartAddress=p->ReadFpgaS2[1]/2; 
        DataNum= p->ReadFpgaS2[2]/4;
        for(ReadNum=0;ReadNum<DataNum;ReadNum++)
		{	
	// 	    Write_MR25H40_nDW(StartAddress+ReadNum*2,(Uint32*)(p->ReadFpgaS2+ReadNum*2+4),1);
		}

		* (p->DSPtoARMStartAdd)=RetFuncID(CHANGE_DEF_ACK,p->ReadFpgaS2[0]);
		/* ��ʼ��ַ */
		* (p->DSPtoARMStartAdd+1)=0x0;
        /* ���� */
        * (p->DSPtoARMStartAdd+2)=0x2;
        /* �ɹ���־ */
        * (p->DSPtoARMStartAdd+3)=0x1;
		
		*(p->DSPHandshakeWord)=CHANGE_DEF_ACK;
        break;
    case WRITE_CHANNEL_RTS:    /* дͨ����Ϣ */
		p->uSampRate=p->ReadFpgaS2[8];     ////������
        /* ϵͳ������Ϊ2K�����Բ��β��������Ϊ2K���˴�������ٸ���������ȥ���岨�� */
        p->uSampRate=2000/p->uSampRate;                        
        p->uSampIntervalbuf=p->uSampRate;
		p->uSampInterval=p->uSampIntervalbuf;
		for(ReadNum=0;ReadNum<6;ReadNum++)   
		{ 
			p->CHANLEADDR[ReadNum]=p->ReadFpgaS2[ReadNum+2];
		}
       	* (p->DSPtoARMStartAdd)=RetFuncID(WRITE_CHANNEL_ACK,p->ReadFpgaS2[0]);
        * (p->DSPtoARMStartAdd+1)=0;
		*(p->DSPHandshakeWord)=WRITE_CHANNEL_ACK;
		break;    
	default:
		break;
	}
}

void InitWrFlash(Uint16 FlashStAddr,Uint32 *StartAddr,Uint16 LEN)
{
	Uint16 ulen;
	for(ulen=0;ulen<LEN;ulen++)
	{
	//	Write_MR25H40_nDW(FlashStAddr+ulen*2,StartAddr+ulen,1);
	}
}

void InitWrFlashF32(Uint16 FlashStAddr,float32 *StartAddr,Uint16 LEN)
{
	Uint16 ulen;
	Uint32 u2temp;

	for(ulen=0;ulen<LEN;ulen++)
	{	
		TRANS_FU.Float_data = *(StartAddr + ulen);
		u2temp = TRANS_FU.Long_data;
		TRANS_FU.Long_data = (TRANS_FU.Long_data<<16)|(u2temp>>16);
	//	Write_MR25H40_nDW(FlashStAddr+ulen*2,&TRANS_FU.Long_data,1);
	}
}



//===========================================================================
// No more.


