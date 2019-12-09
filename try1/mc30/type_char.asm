;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 0.0.2 (Jun 26 2013) (Linux)
; This file was generated Wed Jun 26 17:07:43 2013
;--------------------------------------------------------
; MC30 port for the 14-bit core
;--------------------------------------------------------
;	.file	"type_char.c"
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
	global	_c_a
	global	_c_b
	global	_uc_a
	global	_uc_b

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
UD_type_char_0	udata
_c_a	res	1

UD_type_char_1	udata
_c_b	res	1

UD_type_char_2	udata
_uc_a	res	1

UD_type_char_3	udata
_uc_b	res	1

;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_type_char_0	udata
r0x1004	res	1
r0x1005	res	1
r0x1006	res	1
r0x1007	res	1
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
code_type_char	code
;***
;  pBlock Stats: dbName = M
;***
;entry:  _main	;Function start
; 2 exit points
;has an exit
;4 compiler assigned registers:
;   r0x1004
;   r0x1005
;   r0x1006
;   r0x1007
;; Starting pCode block
_main	;Function start
; 2 exit points
;	.line	8; "type_char.c"	c_a = MCR;
	MOVAR	_MCR
	MOVRA	_c_a
;	.line	9; "type_char.c"	c_b = KBIM;
	MOVAR	_KBIM
	MOVRA	_c_b
;	.line	10; "type_char.c"	uc_a = MCR;
	MOVAR	_MCR
	MOVRA	_uc_a
;	.line	11; "type_char.c"	uc_b = KBIM;
	MOVAR	_KBIM
	MOVRA	_uc_b
;	.line	13; "type_char.c"	P0 = c_a + c_b;
	MOVAR	_c_b
	ADDAR	_c_a
	MOVRA	_P0
;	.line	14; "type_char.c"	P0 = uc_a + uc_b;
	MOVAR	_uc_b
	ADDAR	_uc_a
	MOVRA	_P0
;	.line	15; "type_char.c"	P1 = c_a - c_b;
	MOVAR	_c_b
	RSUBAR	_c_a
	MOVRA	_P1
;	.line	16; "type_char.c"	P1 = uc_a - uc_b;
	MOVAR	_uc_b
	RSUBAR	_uc_a
	MOVRA	_P1
;;swapping arguments (AOP_TYPEs 1/3)
;;signed compare: left >= lit(0x1=1), size=1, mask=ff
;	.line	18; "type_char.c"	if (c_a > 0) P0 = c_b;
	MOVAR	_c_a
	ADDAI	0x80
	ADDAI	0x7f
	JBSET	STATUS,0
	GOTO	_00106_DS_
;;genSkipc:3244: created from rifx:0xbfe498a4
	MOVAR	_c_b
	MOVRA	_P0
_00106_DS_
;	.line	19; "type_char.c"	if (uc_a > 0) P0 = uc_b;
	MOVAI	0x00
	ORAR	_uc_a
	JBCLR	STATUS,2
	GOTO	_00108_DS_
	MOVAR	_uc_b
	MOVRA	_P0
;;swapping arguments (AOP_TYPEs 1/3)
;;signed compare: left >= lit(0xFFFFFFFE=-2), size=1, mask=ff
_00108_DS_
;	.line	21; "type_char.c"	if (c_a > -3) P0 = c_b;
	MOVAR	_c_a
	ADDAI	0x80
	ADDAI	0x82
	JBSET	STATUS,0
	GOTO	_00111_DS_
;;genSkipc:3244: created from rifx:0xbfe498a4
	MOVAR	_c_b
	MOVRA	_P0
_00111_DS_
;	.line	22; "type_char.c"	if (uc_a > -3) P0 = uc_b;
	MOVAR	_uc_b
	MOVRA	_P0
;	.line	24; "type_char.c"	if (uc_a == (~uc_b)) P0 = uc_b;
	MOVAR	_uc_b
	MOVRA	r0x1004
	CLRR	r0x1005
	COMAR	r0x1004
	MOVRA	r0x1004
	COMAR	r0x1005
	MOVRA	r0x1005
	MOVAR	_uc_a
	MOVRA	r0x1006
	CLRR	r0x1007
	MOVAR	r0x1004
	XORAR	r0x1006
	JBSET	STATUS,2
	GOTO	_00114_DS_
	MOVAR	r0x1005
	XORAR	r0x1007
	JBSET	STATUS,2
	GOTO	_00114_DS_
	MOVAR	_uc_b
	MOVRA	_P0
_00114_DS_
;	.line	26; "type_char.c"	uc_a = uc_b = 0x33;
	MOVAI	0x33
	MOVRA	_uc_b
	MOVAI	0x33
	MOVRA	_uc_a
_00116_DS_
;	.line	28; "type_char.c"	while(1);
	GOTO	_00116_DS_
	RETURN	
; exit point of _main


;	code size estimation:
;	   68+    0 =    68 instructions (  136 byte)

	end
