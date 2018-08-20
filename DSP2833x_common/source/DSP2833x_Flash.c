/* ��ʷ�汾
// Version: V1.0
// Date: 	Dec 21, 2010
// Author:	csc @QH
//==========================================================================
// Version: V1.1
// Date: 	Dec 21, 2010
// Author:	csc @QH

//==========================================================================
// 
// �ļ���:	DSP2833x_Flash.c
//
// ��;:	DSP28335��Flash�Ĵ�����ʼ��
//
// ˵��:	InitFlash����������RAM������

//==========================================================================
*/

#include "DSP2833x_Device.h"  
#include "DSP2833x_GlobalPrototypes.h"  
//��fnInitFlash��λ��ramfuncs�ռ䣬����flash������
#pragma CODE_SECTION(fnInitFlash, "ramfuncs");
 void fnInitFlash(void)
 {
   //#if FLASH_LOAD 
     //  MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);//ramfuncs��flash���Ƶ�ram������
   //#endif
   EALLOW;
   //ʹ��flash��ˮ�߲���
   FlashRegs.FOPT.bit.ENPIPE = 1;
   //Flashҳ���ȡ�ȴ�ʱ�䣬SYSCLKOUT�ı���
   FlashRegs.FBANKWAIT.bit.PAGEWAIT = 5;
   //Flash�����ȡ�ȴ�ʱ�䣬SYSCLKOUT�ı���
   FlashRegs.FBANKWAIT.bit.RANDWAIT = 5;
   //OTP��ȡ�ȴ�ʱ�䣬SYSCLKOUT�ı���
   FlashRegs.FOTPWAIT.bit.OTPWAIT = 8;
   FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;
   FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;
   EDIS;
   asm(" RPT #1 || NOP");
}

//==========================================================================
// End of file.
//==========================================================================


























