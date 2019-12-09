;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 0.0.2 (Jun 26 2013) (Linux)
; This file was generated Wed Jun 26 16:35:31 2013
;--------------------------------------------------------
; MC30 port for the 14-bit core
;--------------------------------------------------------
;	.file	"YKQ3011.c"
	list	p=30p011
	radix dec
	include "mc30p011.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_InitialSys
	extern	_InitalRAM
	extern	_Mode2Sbr
	extern	_MColorSbr
	extern	_T1sSbr
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
	extern	__sdcc_gsinit_startup
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	_main
	global	_KeyCnt
	global	_T1s
	global	_TRedCnt
	global	_TRed
	global	_TGreen
	global	_TBlue
	global	_TRedbak
	global	_TGreenbak
	global	_TBluebak
	global	_IRTmr
	global	_KeyCode
	global	_Custom
	global	_CustomRev
	global	_IRCode1
	global	_IRCodeRev1
	global	_BitCnt
	global	_LongIRCnt
	global	_IRCnt
	global	_Color
	global	_Mode1Cnt
	global	_delay
	global	_Tmr
	global	_TStop
	global	_Step
	global	_T40ms
	global	_Dly100ms
	global	_Mode2Cnt2
	global	_Mode2Cnt3
	global	_delay05ms
	global	_Flag1
	global	_Flag2

	global PSAVE
	global SSAVE
	global WSAVE
	global STK12
	global STK11
	global STK10
	global STK09
	global STK08
	global STK07
	global STK06
	global STK05
	global STK04
	global STK03
	global STK02
	global STK01
	global STK00

sharebank udata_ovr 0x0010
PSAVE	res 1
SSAVE	res 1
WSAVE	res 1
STK12	res 1
STK11	res 1
STK10	res 1
STK09	res 1
STK08	res 1
STK07	res 1
STK06	res 1
STK05	res 1
STK04	res 1
STK03	res 1
STK02	res 1
STK01	res 1
STK00	res 1

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
UD_YKQ3011_0	udata
_KeyCnt	res	1

UD_YKQ3011_1	udata
_T1s	res	1

UD_YKQ3011_2	udata
_TRedCnt	res	1

UD_YKQ3011_3	udata
_TRed	res	1

UD_YKQ3011_4	udata
_TGreen	res	1

UD_YKQ3011_5	udata
_TBlue	res	1

UD_YKQ3011_6	udata
_TRedbak	res	1

UD_YKQ3011_7	udata
_TGreenbak	res	1

UD_YKQ3011_8	udata
_TBluebak	res	1

UD_YKQ3011_9	udata
_IRTmr	res	1

UD_YKQ3011_10	udata
_KeyCode	res	1

UD_YKQ3011_11	udata
_Custom	res	1

UD_YKQ3011_12	udata
_CustomRev	res	1

UD_YKQ3011_13	udata
_IRCode1	res	1

UD_YKQ3011_14	udata
_IRCodeRev1	res	1

UD_YKQ3011_15	udata
_BitCnt	res	1

UD_YKQ3011_16	udata
_LongIRCnt	res	1

UD_YKQ3011_17	udata
_IRCnt	res	1

UD_YKQ3011_18	udata
_Color	res	1

UD_YKQ3011_19	udata
_Mode1Cnt	res	1

UD_YKQ3011_20	udata
_delay	res	1

UD_YKQ3011_21	udata
_Tmr	res	2

UD_YKQ3011_22	udata
_TStop	res	1

UD_YKQ3011_23	udata
_Step	res	1

UD_YKQ3011_24	udata
_T40ms	res	1

UD_YKQ3011_25	udata
_Dly100ms	res	1

UD_YKQ3011_26	udata
_Mode2Cnt2	res	1

UD_YKQ3011_27	udata
_Mode2Cnt3	res	1

UD_YKQ3011_28	udata
_delay05ms	res	1

UD_YKQ3011_29	udata
_Flag1	res	1

UD_YKQ3011_30	udata
_Flag2	res	1

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
; reset vector 
;--------------------------------------------------------
STARTUP	code 0x0000
	goto	__sdcc_gsinit_startup
;--------------------------------------------------------
; code
;--------------------------------------------------------
code_YKQ3011	code
;***
;  pBlock Stats: dbName = M
;***
;entry:  _main	;Function start
; 2 exit points
;has an exit
;functions called:
;   _InitialSys
;   _InitalRAM
;   _Mode2Sbr
;   _MColorSbr
;   _T1sSbr
;   _InitialSys
;   _InitalRAM
;   _Mode2Sbr
;   _MColorSbr
;   _T1sSbr
;; Starting pCode block
_main	;Function start
; 2 exit points
;	.line	16; "YKQ3011.c"	GIE = 0;    
	BCLR	_INTECONbits,7
	clrwdt
;	.line	18; "YKQ3011.c"	InitialSys();
	CALL	_InitialSys
;	.line	19; "YKQ3011.c"	InitalRAM();
	CALL	_InitalRAM
;	.line	20; "YKQ3011.c"	FMultiColor = 1;
	BSET	_Flag2,4
;	.line	21; "YKQ3011.c"	FOn = 1;
	BSET	_Flag1,0
;	.line	22; "YKQ3011.c"	pIR = 1;
	BSET	_P1bits,3
;	.line	23; "YKQ3011.c"	KBIE = 1;
	BSET	_INTECONbits,1
;	.line	24; "YKQ3011.c"	KBIM3 = 1;
	BSET	_KBIMbits,3
;	.line	25; "YKQ3011.c"	GIE = 1;
	BSET	_INTECONbits,7
_00138_DS_
;	.line	28; "YKQ3011.c"	if (FStop)
	JBSET	_Flag2,1
	GOTO	_00106_DS_
;	.line	30; "YKQ3011.c"	T1IF = 0;
	BCLR	_TMCRbits,0
;	.line	31; "YKQ3011.c"	T0IF = 0;
	BCLR	_INTFLAGbits,0
	nop
	nop
	nop
	stop
	nop
	nop
	nop
_00106_DS_
;	.line	40; "YKQ3011.c"	if ((delay05ms != 0)||(!FOn))
	MOVAI	0x00
	ORAR	_delay05ms
	JBSET	STATUS,2
	GOTO	_00112_DS_
	JBCLR	_Flag1,0
	GOTO	_00113_DS_
_00112_DS_
;	.line	42; "YKQ3011.c"	pRedC = 1;
	BSET	_DDR1bits,0
;	.line	43; "YKQ3011.c"	pGreenC = 1;
	BSET	_DDR1bits,1
;	.line	44; "YKQ3011.c"	pBlueC = 1;
	BSET	_DDR1bits,2
	GOTO	_00114_DS_
_00113_DS_
;	.line	48; "YKQ3011.c"	if (FMultiColor)
	JBSET	_Flag2,4
	GOTO	_00110_DS_
;	.line	50; "YKQ3011.c"	pRedC = 0;
	BCLR	_DDR1bits,0
;	.line	51; "YKQ3011.c"	pGreenC = 0;
	BCLR	_DDR1bits,1
;	.line	52; "YKQ3011.c"	pBlueC = 0;
	BCLR	_DDR1bits,2
	GOTO	_00114_DS_
_00110_DS_
;	.line	56; "YKQ3011.c"	if (FCandle) Mode2Sbr();
	JBSET	_Flag2,5
	GOTO	_00114_DS_
	CALL	_Mode2Sbr
_00114_DS_
;	.line	59; "YKQ3011.c"	if (F4ms)
	JBSET	_Flag2,2
	GOTO	_00138_DS_
;	.line	61; "YKQ3011.c"	F4ms = 0;
	BCLR	_Flag2,2
	clrwdt
;	.line	63; "YKQ3011.c"	if (delay05ms == 0)
	MOVAI	0x00
	ORAR	_delay05ms
	JBSET	STATUS,2
	GOTO	_00133_DS_
;	.line	65; "YKQ3011.c"	if (FOn)
	JBSET	_Flag1,0
	GOTO	_00134_DS_
;	.line	67; "YKQ3011.c"	if (FMultiColor) MColorSbr();
	JBSET	_Flag2,4
	GOTO	_00128_DS_
	CALL	_MColorSbr
	GOTO	_00134_DS_
_00128_DS_
;	.line	70; "YKQ3011.c"	if (FCandle)
	JBSET	_Flag2,5
	GOTO	_00134_DS_
;	.line	73; "YKQ3011.c"	if (++T40ms > 10)
	INCR	_T40ms
;;swapping arguments (AOP_TYPEs 1/3)
;;unsigned compare: left >= lit(0xB=11), size=1
	MOVAI	0x0b
	RSUBAR	_T40ms
	JBSET	STATUS,0
	GOTO	_00134_DS_
;;genSkipc:3244: created from rifx:0xbfee59d4
;	.line	75; "YKQ3011.c"	T40ms = 0;
	CLRR	_T40ms
;	.line	76; "YKQ3011.c"	if (FDirection)
	JBSET	_Flag1,2
	GOTO	_00121_DS_
;	.line	78; "YKQ3011.c"	if (++Mode2Cnt3 > 50) FDirection = 0;
	INCR	_Mode2Cnt3
;;swapping arguments (AOP_TYPEs 1/3)
;;unsigned compare: left >= lit(0x33=51), size=1
	MOVAI	0x33
	RSUBAR	_Mode2Cnt3
	JBSET	STATUS,0
	GOTO	_00134_DS_
;;genSkipc:3244: created from rifx:0xbfee59d4
	BCLR	_Flag1,2
	GOTO	_00134_DS_
_00121_DS_
;	.line	82; "YKQ3011.c"	if (--Mode2Cnt3 < 10) FDirection = 1;
	DECR	_Mode2Cnt3
;;unsigned compare: left < lit(0xA=10), size=1
	MOVAI	0x0a
	RSUBAR	_Mode2Cnt3
	JBCLR	STATUS,0
	GOTO	_00134_DS_
;;genSkipc:3244: created from rifx:0xbfee59d4
	BSET	_Flag1,2
	GOTO	_00134_DS_
_00133_DS_
;	.line	89; "YKQ3011.c"	else --delay05ms;
	DECR	_delay05ms
_00134_DS_
;	.line	90; "YKQ3011.c"	T1sSbr();
	CALL	_T1sSbr
	GOTO	_00138_DS_
	RETURN	
; exit point of _main


;	code size estimation:
;	   73+    0 =    73 instructions (  146 byte)

	end
