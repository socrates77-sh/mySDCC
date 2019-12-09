
#include <mc30-common.h>
#include "CONST.H"
/*****************************************************************
;	Function : Define variables
;*****************************************************************/
#ifndef _VAR_H_
#define _VAR_H_

uchar	KeyCnt;
uchar	T1s;
uchar	TRedCnt;
uchar	TRed,TGreen,TBlue;
uchar	TRedbak,TGreenbak,TBluebak;
uchar	IRTmr;
uchar	KeyCode;
uchar	Custom;
uchar	CustomRev;
uchar	IRCode1;
uchar	IRCodeRev1;
uchar	BitCnt;
uchar	LongIRCnt;
uchar	IRCnt;
uchar	Color;
uchar	Mode1Cnt;
uchar	delay;
ushort	Tmr;
uchar	TStop;
uchar	Step;
uchar	T40ms,Dly100ms;
uchar	Mode2Cnt2;
uchar	Mode2Cnt3;
uchar	delay05ms;

//;0x30
//IRDate		20

typedef  struct
{
    uchar bit0         : 1;
    uchar bit1         : 1;
    uchar bit2         : 1;
    uchar bit3         : 1;
    uchar bit4         : 1;	
    uchar bit5         : 1; 
    uchar bit6         : 1; 	
    uchar bit7         : 1; 	
} bitn;

volatile bitn	Flag1,Flag2;

//;标志定义-------------------------------------
#define	FOn			Flag1.bit0
#define	FKeyAck		Flag1.bit1
#define	FDirection	Flag1.bit2 
#define	F2ms		Flag1.bit3
#define	FDouble		Flag1.bit4
#define	FIRAck		Flag1.bit5
#define	FLead		Flag1.bit6
#define	FTmr		Flag1.bit7

#define	FLongRKey	Flag2.bit0	
#define	FStop		Flag2.bit1
#define	F4ms		Flag2.bit2
#define	FStep		Flag2.bit3
#define	FMultiColor	Flag2.bit4
#define	FCandle		Flag2.bit5
#define	FLight		Flag2.bit6

#endif


