;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 0.0.2 (Jun 26 2013) (Linux)
; This file was generated Wed Jun 26 16:35:31 2013
;--------------------------------------------------------
; MC30 port for the 14-bit core
;--------------------------------------------------------
;	.file	"initSys.c"
	list	p=30p011
	radix dec
	include "mc30p011.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
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
	global	_InitialSys
	global	_InitalRAM

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
code_initSys	code
;***
;  pBlock Stats: dbName = C
;***
;entry:  _InitalRAM	;Function start
; 2 exit points
;has an exit
;; Starting pCode block
_InitalRAM	;Function start
; 2 exit points
;	.line	59; "initSys.c"	T1s = 250;
	MOVAI	0xfa
	MOVRA	_T1s
	RETURN	
; exit point of _InitalRAM

;***
;  pBlock Stats: dbName = C
;***
;entry:  _InitialSys	;Function start
; 2 exit points
;has an exit
;; Starting pCode block
_InitialSys	;Function start
; 2 exit points
;	.line	10; "initSys.c"	pRed = 1;
	BSET	_P1bits,0
;	.line	11; "initSys.c"	pGreen = 1;
	BSET	_P1bits,1
;	.line	12; "initSys.c"	pBlue = 1;
	BSET	_P1bits,2
;	.line	14; "initSys.c"	DDR0 = 0;
	CLRR	_DDR0
;	.line	15; "initSys.c"	DDR1 = 0;
	CLRR	_DDR1
;	.line	16; "initSys.c"	DDR1 |= 0x08;
	BSET	_DDR1,3
;	.line	17; "initSys.c"	PDCON = 0xFF;                    
	MOVAI	0xff
	MOVRA	_PDCON
;	.line	18; "initSys.c"	PUCON = 0xFF;
	MOVAI	0xff
	MOVRA	_PUCON
;	.line	19; "initSys.c"	ODCON = 0;
	CLRR	_ODCON
;	.line	23; "initSys.c"	T0CR = 1;
	MOVAI	0x01
	MOVRA	_T0CR
;	.line	24; "initSys.c"	T0CNT = CT0;
	MOVAI	0xf0
	MOVRA	_T0CNT
;	.line	25; "initSys.c"	T0IE = 1;		//;开定时中断
	BSET	_INTECONbits,0
;	.line	31; "initSys.c"	TMCR = 0;
	CLRR	_TMCR
;	.line	32; "initSys.c"	T1CR = 0x86;
	MOVAI	0x86
	MOVRA	_T1CR
;	.line	33; "initSys.c"	T1LOAD = 249;
	MOVAI	0xf9
	MOVRA	_T1LOAD
;	.line	34; "initSys.c"	T1DATA = 0;
	CLRR	_T1DATA
;	.line	37; "initSys.c"	MCR = 0x80;                    
	MOVAI	0x80
	MOVRA	_MCR
;	.line	39; "initSys.c"	KBIM = 0;                      
	CLRR	_KBIM
	RETURN	
; exit point of _InitialSys


;	code size estimation:
;	   29+    0 =    29 instructions (   58 byte)

	end
