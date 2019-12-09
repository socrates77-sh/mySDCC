
#include <mc30-common.h>
#include "CONST.H"
/*****************************************************************
;	Function : Define variables
;*****************************************************************/
#ifndef _EXTERNVAR_H_
#define _EXTERNVAR_H_

extern uchar	KeyCnt;
extern uchar	T1s;
extern uchar	TRedCnt;
extern uchar	TRed,TGreen,TBlue;
extern uchar	TRedbak,TGreenbak,TBluebak;
extern uchar	IRTmr;
extern uchar	KeyCode;
extern uchar	Custom;
extern uchar	CustomRev;
extern uchar	IRCode1;
extern uchar	IRCodeRev1;
extern uchar	BitCnt;
extern uchar	LongIRCnt;
extern uchar	IRCnt;
extern uchar	Color;
extern uchar	Mode1Cnt;
extern uchar	delay;
extern ushort	Tmr;
extern uchar	TStop;
extern uchar	Step;
extern uchar	T40ms,Dly100ms;
extern uchar	Mode2Cnt2;
extern uchar	Mode2Cnt3;
extern uchar	delay05ms;

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

extern volatile bitn	Flag1,Flag2;

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


