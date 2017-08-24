;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:30:19 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc30p011.c"
	list	p=30p011
	radix dec
	include "mc30p011.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------

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
	global	_STATUSbits
	global	_P0bits
	global	_P1bits
	global	_MCRbits
	global	_KBIMbits
	global	_PDCONbits
	global	_ODCONbits
	global	_PUCONbits
	global	_INTECONbits
	global	_INTFLAGbits
	global	_T0CRbits
	global	_DDR0bits
	global	_DDR1bits
	global	_TMCRbits
	global	_T1CRbits
	global	_INDF
	global	_T0CNT
	global	_PCL
	global	_STATUS
	global	_FSR
	global	_P0
	global	_P1
	global	_MCR
	global	_KBIM
	global	_PCLATH
	global	_PDCON
	global	_ODCON
	global	_PUCON
	global	_INTECON
	global	_INTFLAG
	global	_T0CR
	global	_DDR0
	global	_DDR1
	global	_TMCR
	global	_T1CR
	global	_T1CNT
	global	_T1LOAD
	global	_T1DATA

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc30p011_0	udata_ovr	0x0000
_INDF
	res	1
UD_abs_mc30p011_1	udata_ovr	0x0001
_T0CNT
	res	1
UD_abs_mc30p011_2	udata_ovr	0x0002
_PCL
	res	1
UD_abs_mc30p011_3	udata_ovr	0x0003
_STATUSbits
_STATUS
	res	1
UD_abs_mc30p011_4	udata_ovr	0x0004
_FSR
	res	1
UD_abs_mc30p011_5	udata_ovr	0x0005
_P0bits
_P0
	res	1
UD_abs_mc30p011_6	udata_ovr	0x0006
_P1bits
_P1
	res	1
UD_abs_mc30p011_8	udata_ovr	0x0008
_MCRbits
_MCR
	res	1
UD_abs_mc30p011_9	udata_ovr	0x0009
_KBIMbits
_KBIM
	res	1
UD_abs_mc30p011_a	udata_ovr	0x000a
_PCLATH
	res	1
UD_abs_mc30p011_b	udata_ovr	0x000b
_PDCONbits
_PDCON
	res	1
UD_abs_mc30p011_c	udata_ovr	0x000c
_ODCONbits
_ODCON
	res	1
UD_abs_mc30p011_d	udata_ovr	0x000d
_PUCONbits
_PUCON
	res	1
UD_abs_mc30p011_e	udata_ovr	0x000e
_INTECONbits
_INTECON
	res	1
UD_abs_mc30p011_f	udata_ovr	0x000f
_INTFLAGbits
_INTFLAG
	res	1
UD_abs_mc30p011_41	udata_ovr	0x0041
_T0CRbits
_T0CR
	res	1
UD_abs_mc30p011_45	udata_ovr	0x0045
_DDR0bits
_DDR0
	res	1
UD_abs_mc30p011_46	udata_ovr	0x0046
_DDR1bits
_DDR1
	res	1
UD_abs_mc30p011_4b	udata_ovr	0x004b
_TMCRbits
_TMCR
	res	1
UD_abs_mc30p011_4c	udata_ovr	0x004c
_T1CRbits
_T1CR
	res	1
UD_abs_mc30p011_4d	udata_ovr	0x004d
_T1CNT
	res	1
UD_abs_mc30p011_4e	udata_ovr	0x004e
_T1LOAD
	res	1
UD_abs_mc30p011_4f	udata_ovr	0x004f
_T1DATA
	res	1
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
code_mc30p011	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
