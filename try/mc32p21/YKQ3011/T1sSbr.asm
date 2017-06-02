;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 0.0.2 (Jun 26 2013) (Linux)
; This file was generated Wed Jun 26 16:35:31 2013
;--------------------------------------------------------
; MC30 port for the 14-bit core
;--------------------------------------------------------
;	.file	"T1sSbr.c"
	list	p=30p011
	radix dec
	include "mc30p011.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_IROffKeySbr
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
	global	_T1sSbr

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
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
code_T1sSbr	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  _T1sSbr	;Function start
; 2 exit points
;has an exit
;functions called:
;   _IROffKeySbr
;   _IROffKeySbr
;   _IROffKeySbr
;   _IROffKeySbr
;; Starting pCode block
_T1sSbr	;Function start
; 2 exit points
;	.line	9; "T1sSbr.c"	if (--T1s != 0) return;
	DECR	_T1s
	MOVAI	0x00
	ORAR	_T1s
	JBCLR	STATUS,2
	GOTO	_00106_DS_
	GOTO	_00115_DS_
_00106_DS_
;	.line	10; "T1sSbr.c"	T1s = 250;
	MOVAI	0xfa
	MOVRA	_T1s
;	.line	12; "T1sSbr.c"	if (!FOn)
	JBCLR	_Flag1,0
	GOTO	_00110_DS_
;	.line	14; "T1sSbr.c"	if (--TStop == 0) IROffKeySbr();
	DECR	_TStop
	MOVAI	0x00
	ORAR	_TStop
	JBSET	STATUS,2
	GOTO	_00108_DS_
	CALL	_IROffKeySbr
_00108_DS_
;	.line	15; "T1sSbr.c"	return;
	GOTO	_00115_DS_
_00110_DS_
;	.line	17; "T1sSbr.c"	if (!FTmr) return;
	JBCLR	_Flag1,7
	GOTO	_00112_DS_
	GOTO	_00115_DS_
_00112_DS_
;	.line	18; "T1sSbr.c"	if (--Tmr == 0) IROffKeySbr();
	MOVAI	0xff
	ADDRA	_Tmr
	JBSET	STATUS,0
	DECR	(_Tmr + 1)
	MOVAR	_Tmr
	ORAR	(_Tmr + 1)
	JBSET	STATUS,2
	GOTO	_00115_DS_
	CALL	_IROffKeySbr
_00115_DS_
	RETURN	
; exit point of _T1sSbr


;	code size estimation:
;	   30+    0 =    30 instructions (   60 byte)

	end
