;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 0.0.2 (Jun 26 2013) (Linux)
; This file was generated Wed Jun 26 16:35:31 2013
;--------------------------------------------------------
; MC30 port for the 14-bit core
;--------------------------------------------------------
;	.file	"IR.c"
	list	p=30p011
	radix dec
	include "mc30p011.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_ColorSbr
	extern	_STATUSbits
	extern	_P0bits
	extern	_P1bits
	extern	_MCRbits
	extern	_KBIMbits
	extern	_PDCONbits
	extern	_ODCONbits
	extern	_PUCONbits
	extern	_INTECONbits
	extern	_INTFLAGbits
	extern	_DDR0bits
	extern	_DDR1bits
	extern	_TMCRbits
	extern	_T1CRbits
	extern	_KeyCnt
	extern	_T1s
	extern	_TRedCnt
	extern	_TRed
	extern	_TGreen
	extern	_TBlue
	extern	_TRedbak
	extern	_TGreenbak
	extern	_TBluebak
	extern	_IRTmr
	extern	_KeyCode
	extern	_Custom
	extern	_CustomRev
	extern	_IRCode1
	extern	_IRCodeRev1
	extern	_BitCnt
	extern	_LongIRCnt
	extern	_IRCnt
	extern	_Color
	extern	_Mode1Cnt
	extern	_delay
	extern	_Tmr
	extern	_TStop
	extern	_Step
	extern	_T40ms
	extern	_Dly100ms
	extern	_Mode2Cnt2
	extern	_Mode2Cnt3
	extern	_delay05ms
	extern	_Flag1
	extern	_Flag2
	extern	_INDF
	extern	_T0CNT
	extern	_PCL
	extern	_STATUS
	extern	_FSR
	extern	_P0
	extern	_P1
	extern	_MCR
	extern	_KBIM
	extern	_PCLATH
	extern	_PDCON
	extern	_ODCON
	extern	_PUCON
	extern	_INTECON
	extern	_INTFLAG
	extern	_T0CR
	extern	_DDR0
	extern	_DDR1
	extern	_TMCR
	extern	_T1CR
	extern	_T1CNT
	extern	_T1LOAD
	extern	_T1DATA

	extern PSAVE
	extern SSAVE
	extern WSAVE
	extern STK12
	extern STK11
	extern STK10
	extern STK09
	extern STK08
	extern STK07
	extern STK06
	extern STK05
	extern STK04
	extern STK03
	extern STK02
	extern STK01
	extern STK00
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	_IRSbr4
	global	_IRSbr
	global	_IRKeyR
	global	_ColorKeySbr
	global	_IROffKeySbr

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_IR_0	udata
r0x1018	res	1
r0x1019	res	1
r0x101A	res	1
r0x101B	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; code
;--------------------------------------------------------
code_IR	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  _IRSbr4	;Function start
; 2 exit points
;has an exit
;functions called:
;   _IRKeyR
;   _IROffKeySbr
;   _IRKeyR
;   _IRKeyR
;   _IRKeyR
;   _IRKeyR
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _IRKeyR
;   _IROffKeySbr
;   _IRKeyR
;   _IRKeyR
;   _IRKeyR
;   _IRKeyR
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;   _ColorKeySbr
;4 compiler assigned registers:
;   r0x1018
;   r0x1019
;   r0x101A
;   r0x101B
;; Starting pCode block
_IRSbr4	;Function start
; 2 exit points
;	.line	97; "IR.c"	FLead = 0;
	BCLR	_Flag1,6
;	.line	98; "IR.c"	if (IRCodeRev1 != ~IRCode1) return;
	MOVAR	_IRCode1
	MOVRA	r0x1018
	CLRR	r0x1019
	COMAR	r0x1018
	MOVRA	r0x1018
	COMAR	r0x1019
	MOVRA	r0x1019
	MOVAR	_IRCodeRev1
	MOVRA	r0x101A
	CLRR	r0x101B
	MOVAR	r0x1018
	XORAR	r0x101A
	JBSET	STATUS,2
	GOTO	_00237_DS_
	MOVAR	r0x1019
	XORAR	r0x101B
	JBSET	STATUS,2
	GOTO	_00237_DS_
	GOTO	_00137_DS_
_00237_DS_
	GOTO	_00185_DS_
_00137_DS_
;	.line	99; "IR.c"	if (CustomRev != ~Custom) return;
	MOVAR	_Custom
	MOVRA	r0x1018
	CLRR	r0x1019
	COMAR	r0x1018
	MOVRA	r0x1018
	COMAR	r0x1019
	MOVRA	r0x1019
	MOVAR	_CustomRev
	MOVRA	r0x101A
	CLRR	r0x101B
	MOVAR	r0x1018
	XORAR	r0x101A
	JBSET	STATUS,2
	GOTO	_00238_DS_
	MOVAR	r0x1019
	XORAR	r0x101B
	JBSET	STATUS,2
	GOTO	_00238_DS_
	GOTO	_00139_DS_
_00238_DS_
	GOTO	_00185_DS_
_00139_DS_
;	.line	100; "IR.c"	if (Custom != CIDCode) return;
	MOVAI	0x00
	ORAR	_Custom
	JBCLR	STATUS,2
	GOTO	_00141_DS_
	GOTO	_00185_DS_
_00141_DS_
;	.line	102; "IR.c"	if (FIRAck) return;
	JBSET	_Flag1,5
	GOTO	_00143_DS_
	GOTO	_00185_DS_
_00143_DS_
;	.line	103; "IR.c"	FIRAck = 1;
	BSET	_Flag1,5
;	.line	105; "IR.c"	if (IRCodeRev1 == CIRON)
	MOVAR	_IRCodeRev1
	XORAI	0x45
	JBSET	STATUS,2
	GOTO	_00147_DS_
;	.line	107; "IR.c"	if (FOn) return;
	JBSET	_Flag1,0
	GOTO	_00145_DS_
	GOTO	_00185_DS_
_00145_DS_
;	.line	108; "IR.c"	FOn = 1;
	BSET	_Flag1,0
;	.line	109; "IR.c"	FTmr = 0;
	BCLR	_Flag1,7
;	.line	110; "IR.c"	IRKeyR();
	CALL	_IRKeyR
_00147_DS_
;	.line	112; "IR.c"	if (!FOn) return;
	JBCLR	_Flag1,0
	GOTO	_00149_DS_
	GOTO	_00185_DS_
_00149_DS_
;	.line	114; "IR.c"	if (IRCodeRev1 == CIROFF)
	MOVAR	_IRCodeRev1
	XORAI	0x46
	JBSET	STATUS,2
	GOTO	_00151_DS_
;	.line	116; "IR.c"	IROffKeySbr();
	CALL	_IROffKeySbr
;	.line	117; "IR.c"	IRKeyR();
	CALL	_IRKeyR
;	.line	118; "IR.c"	return;
	GOTO	_00185_DS_
_00151_DS_
;	.line	120; "IR.c"	if (IRCodeRev1 == CIRMODE)
	MOVAR	_IRCodeRev1
	XORAI	0x47
	JBSET	STATUS,2
	GOTO	_00153_DS_
;	.line	122; "IR.c"	FCandle = !FCandle;
	CLRR	r0x1018
	JBCLR	_Flag2,5
	INCR	r0x1018
	MOVAR	r0x1018
	MOVAI	0x00
	JBCLR	STATUS,2
	MOVAI	0x01
	MOVRA	r0x1018
	MOVRA	r0x1019
;;100	MOVAR	r0x1019
	RRAR	r0x1018
	JBSET	STATUS,0
	BCLR	_Flag2,5
	JBCLR	STATUS,0
	BSET	_Flag2,5
;	.line	123; "IR.c"	TRedbak = TRed;
	MOVAR	_TRed
	MOVRA	_TRedbak
;	.line	124; "IR.c"	TGreenbak = TGreen;
	MOVAR	_TGreen
	MOVRA	_TGreenbak
;	.line	125; "IR.c"	TBluebak = TBlue;
	MOVAR	_TBlue
	MOVRA	_TBluebak
;	.line	126; "IR.c"	Mode2Cnt3 = 10;
	MOVAI	0x0a
	MOVRA	_Mode2Cnt3
;	.line	127; "IR.c"	FDirection = 0;
	BCLR	_Flag1,2
;	.line	128; "IR.c"	Mode2Cnt2 = 0;
	CLRR	_Mode2Cnt2
;	.line	129; "IR.c"	T40ms = 0xff;
	MOVAI	0xff
	MOVRA	_T40ms
;	.line	130; "IR.c"	IRKeyR();
	CALL	_IRKeyR
;	.line	131; "IR.c"	return;
	GOTO	_00185_DS_
_00153_DS_
;	.line	133; "IR.c"	if (IRCodeRev1 == CIR4H)
	MOVAR	_IRCodeRev1
	XORAI	0x44
	JBSET	STATUS,2
	GOTO	_00156_DS_
;	.line	135; "IR.c"	Tmr = 0x3840;
	MOVAI	0x40
	MOVRA	_Tmr
	MOVAI	0x38
	MOVRA	(_Tmr + 1)
_00154_DS_
;	.line	137; "IR.c"	T1s = 250;
	MOVAI	0xfa
	MOVRA	_T1s
;	.line	138; "IR.c"	FTmr = 1;
	BSET	_Flag1,7
;	.line	139; "IR.c"	IRKeyR();
	CALL	_IRKeyR
;	.line	140; "IR.c"	return;
	GOTO	_00185_DS_
_00156_DS_
;	.line	142; "IR.c"	if (IRCodeRev1 == CIR8H)
	MOVAR	_IRCodeRev1
	XORAI	0x40
	JBSET	STATUS,2
	GOTO	_00158_DS_
;	.line	144; "IR.c"	Tmr = 0x7080;
	MOVAI	0x80
	MOVRA	_Tmr
	MOVAI	0x70
	MOVRA	(_Tmr + 1)
;	.line	145; "IR.c"	goto	IR4HKeySbr1;
	GOTO	_00154_DS_
_00158_DS_
;	.line	147; "IR.c"	if (IRCodeRev1 == CIRMCOLR)
	MOVAR	_IRCodeRev1
	XORAI	0x43
	JBSET	STATUS,2
	GOTO	_00160_DS_
;	.line	149; "IR.c"	FMultiColor = !FMultiColor;
	CLRR	r0x1018
	JBCLR	_Flag2,4
	INCR	r0x1018
	MOVAR	r0x1018
	MOVAI	0x00
	JBCLR	STATUS,2
	MOVAI	0x01
	MOVRA	r0x1018
	MOVRA	r0x1019
;;99	MOVAR	r0x1019
	RRAR	r0x1018
	JBSET	STATUS,0
	BCLR	_Flag2,4
	JBCLR	STATUS,0
	BSET	_Flag2,4
;	.line	150; "IR.c"	IRKeyR();
	CALL	_IRKeyR
;	.line	151; "IR.c"	return;
	GOTO	_00185_DS_
_00160_DS_
;	.line	153; "IR.c"	if (IRCodeRev1 == CIRCOLR1) {i = 0;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x16
	JBSET	STATUS,2
	GOTO	_00162_DS_
	MOVAI	0x00
	CALL	_ColorKeySbr
_00162_DS_
;	.line	154; "IR.c"	if (IRCodeRev1 == CIRCOLR2) {i = 1;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x19
	JBSET	STATUS,2
	GOTO	_00164_DS_
	MOVAI	0x01
	CALL	_ColorKeySbr
_00164_DS_
;	.line	155; "IR.c"	if (IRCodeRev1 == CIRCOLR3) {i = 2;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x0d
	JBSET	STATUS,2
	GOTO	_00166_DS_
	MOVAI	0x02
	CALL	_ColorKeySbr
_00166_DS_
;	.line	156; "IR.c"	if (IRCodeRev1 == CIRCOLR4) {i = 3;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x0c
	JBSET	STATUS,2
	GOTO	_00168_DS_
	MOVAI	0x03
	CALL	_ColorKeySbr
_00168_DS_
;	.line	157; "IR.c"	if (IRCodeRev1 == CIRCOLR5) {i = 4;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x18
	JBSET	STATUS,2
	GOTO	_00170_DS_
	MOVAI	0x04
	CALL	_ColorKeySbr
_00170_DS_
;	.line	158; "IR.c"	if (IRCodeRev1 == CIRCOLR6) {i = 5;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x5e
	JBSET	STATUS,2
	GOTO	_00172_DS_
	MOVAI	0x05
	CALL	_ColorKeySbr
_00172_DS_
;	.line	159; "IR.c"	if (IRCodeRev1 == CIRCOLR7) {i = 6;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x08
	JBSET	STATUS,2
	GOTO	_00174_DS_
	MOVAI	0x06
	CALL	_ColorKeySbr
_00174_DS_
;	.line	160; "IR.c"	if (IRCodeRev1 == CIRCOLR8) {i = 7;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x1c
	JBSET	STATUS,2
	GOTO	_00176_DS_
	MOVAI	0x07
	CALL	_ColorKeySbr
_00176_DS_
;	.line	161; "IR.c"	if (IRCodeRev1 == CIRCOLR9) {i = 8;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x5a
	JBSET	STATUS,2
	GOTO	_00178_DS_
	MOVAI	0x08
	CALL	_ColorKeySbr
_00178_DS_
;	.line	162; "IR.c"	if (IRCodeRev1 == CIRCOLRA) {i = 9;ColorKeySbr(i);};
	MOVAR	_IRCodeRev1
	XORAI	0x42
	JBSET	STATUS,2
	GOTO	_00180_DS_
	MOVAI	0x09
	CALL	_ColorKeySbr
_00180_DS_
;	.line	163; "IR.c"	if (IRCodeRev1 == CIRCOLRB) {i = 10;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x52
	JBSET	STATUS,2
	GOTO	_00182_DS_
	MOVAI	0x0a
	CALL	_ColorKeySbr
_00182_DS_
;	.line	164; "IR.c"	if (IRCodeRev1 == CIRCOLRC) {i = 11;ColorKeySbr(i);}
	MOVAR	_IRCodeRev1
	XORAI	0x4a
	JBSET	STATUS,2
	GOTO	_00185_DS_
	MOVAI	0x0b
	CALL	_ColorKeySbr
_00185_DS_
	RETURN	
; exit point of _IRSbr4

;***
;  pBlock Stats: dbName = C
;***
;entry:  _IROffKeySbr	;Function start
; 2 exit points
;has an exit
;; Starting pCode block
_IROffKeySbr	;Function start
; 2 exit points
;	.line	88; "IR.c"	FOn = 0;
	BCLR	_Flag1,0
;	.line	89; "IR.c"	FStop = 1;
	BSET	_Flag2,1
;	.line	90; "IR.c"	TStop = 3;
	MOVAI	0x03
	MOVRA	_TStop
	RETURN	
; exit point of _IROffKeySbr

;***
;  pBlock Stats: dbName = C
;***
;entry:  _ColorKeySbr	;Function start
; 2 exit points
;has an exit
;functions called:
;   _ColorSbr
;   _IRKeyR
;   _ColorSbr
;   _IRKeyR
;; Starting pCode block
_ColorKeySbr	;Function start
; 2 exit points
;	.line	78; "IR.c"	void ColorKeySbr(uchar i)
	MOVRA	_Color
;	.line	81; "IR.c"	FMultiColor = 0;
	BCLR	_Flag2,4
;	.line	82; "IR.c"	ColorSbr();
	CALL	_ColorSbr
;	.line	83; "IR.c"	IRKeyR();
	CALL	_IRKeyR
;	.line	84; "IR.c"	return;
	RETURN	
; exit point of _ColorKeySbr

;***
;  pBlock Stats: dbName = C
;***
;entry:  _IRKeyR	;Function start
; 2 exit points
;has an exit
;; Starting pCode block
_IRKeyR	;Function start
; 2 exit points
;	.line	76; "IR.c"	Dly100ms = 25;
	MOVAI	0x19
	MOVRA	_Dly100ms
	RETURN	
; exit point of _IRKeyR

;***
;  pBlock Stats: dbName = C
;***
;entry:  _IRSbr	;Function start
; 2 exit points
;has an exit
;functions called:
;   _IRSbr4
;   _IRSbr4
;   _IRSbr4
;   _IRSbr4
;; Starting pCode block
_IRSbr	;Function start
; 2 exit points
;	.line	37; "IR.c"	if (!FLead)									//;未收到头码
	JBCLR	_Flag1,6
	GOTO	_00110_DS_
;;unsigned compare: left < lit(0x41=65), size=1
;	.line	39; "IR.c"	if (IRTmr < CHEAD-5) return;
	MOVAI	0x41
	RSUBAR	_IRTmr
	JBCLR	STATUS,0
	GOTO	_00106_DS_
;;genSkipc:3244: created from rifx:0xbfe81684
	GOTO	_00119_DS_
;;swapping arguments (AOP_TYPEs 1/3)
;;unsigned compare: left >= lit(0x4C=76), size=1
_00106_DS_
;	.line	40; "IR.c"	if (IRTmr > CHEAD+5) return;
	MOVAI	0x4c
	RSUBAR	_IRTmr
	JBSET	STATUS,0
	GOTO	_00108_DS_
;;genSkipc:3244: created from rifx:0xbfe81684
	GOTO	_00119_DS_
_00108_DS_
;	.line	41; "IR.c"	FLead = 1;						//;当前接收到的是头码
	BSET	_Flag1,6
;	.line	42; "IR.c"	Custom = 0;
	CLRR	_Custom
;	.line	43; "IR.c"	CustomRev = 0;
	CLRR	_CustomRev
;	.line	44; "IR.c"	IRCode1 = 0;
	CLRR	_IRCode1
;	.line	45; "IR.c"	IRCodeRev1 = 0;
	CLRR	_IRCodeRev1
;	.line	46; "IR.c"	FIRAck = 0;
	BCLR	_Flag1,5
;	.line	47; "IR.c"	BitCnt = 32;
	MOVAI	0x20
	MOVRA	_BitCnt
;	.line	48; "IR.c"	return;
	GOTO	_00119_DS_
;;swapping arguments (AOP_TYPEs 1/3)
;;unsigned compare: left >= lit(0x29=41), size=1
_00110_DS_
;	.line	51; "IR.c"	if (IRTmr > CCodeR+5) {FLead = 0; return;}
	MOVAI	0x29
	RSUBAR	_IRTmr
	JBSET	STATUS,0
	GOTO	_00112_DS_
;;genSkipc:3244: created from rifx:0xbfe81684
	BCLR	_Flag1,6
	GOTO	_00119_DS_
;;unsigned compare: left < lit(0x1E=30), size=1
_00112_DS_
;	.line	52; "IR.c"	if (IRTmr >= CCodeR-5) 
	MOVAI	0x1e
	RSUBAR	_IRTmr
	JBSET	STATUS,0
	GOTO	_00116_DS_
;;genSkipc:3244: created from rifx:0xbfe81684
;	.line	55; "IR.c"	if (++LongIRCnt >= 6)
	INCR	_LongIRCnt
;;unsigned compare: left < lit(0x6=6), size=1
	MOVAI	0x06
	RSUBAR	_LongIRCnt
	JBSET	STATUS,0
	GOTO	_00114_DS_
;;genSkipc:3244: created from rifx:0xbfe81684
;	.line	57; "IR.c"	FLongRKey = 1;
	BSET	_Flag2,0
;	.line	58; "IR.c"	IRSbr4();
	CALL	_IRSbr4
_00114_DS_
;	.line	60; "IR.c"	return;
	GOTO	_00119_DS_
_00116_DS_
	movai 8 +(26 -8)/2
	rsubar _IRTmr
	rrr _IRCode1
	rrr _IRCodeRev1
	rrr _Custom
	rrr _CustomRev
	
;	.line	72; "IR.c"	if (--BitCnt == 0) IRSbr4();
	DECR	_BitCnt
	MOVAI	0x00
	ORAR	_BitCnt
	JBSET	STATUS,2
	GOTO	_00119_DS_
	CALL	_IRSbr4
_00119_DS_
	RETURN	
; exit point of _IRSbr


;	code size estimation:
;	  276+    0 =   276 instructions (  552 byte)

	end
