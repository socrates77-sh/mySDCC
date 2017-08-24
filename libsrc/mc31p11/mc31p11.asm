;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.4 (Jan 22 2015) (Linux)
; This file was generated Thu Jan 22 23:34:23 2015
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"mc31p11.c"
	list	p=31p11
	radix dec
	include "mc31p11.inc"
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
	global	_MCRbits
	global	_INTECONbits
	global	_INTFLAGbits
	global	_IOP0bits
	global	_OEP0bits
	global	_PUP0bits
	global	_DKWP0bits
	global	_IOP1bits
	global	_OEP1bits
	global	_PUP1bits
	global	_DKWP1bits
	global	_DKWbits
	global	_INDF
	global	_FSR
	global	_PCL
	global	_STATUS
	global	_MCR
	global	_INTECON
	global	_INTFLAG
	global	_IOP0
	global	_OEP0
	global	_PUP0
	global	_DKWP0
	global	_IOP1
	global	_OEP1
	global	_PUP1
	global	_DKWP1
	global	_DKW

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc31p11_0	udata_ovr	0x0000
_INDF
	res	1
UD_abs_mc31p11_1	udata_ovr	0x0001
_FSR
	res	1
UD_abs_mc31p11_2	udata_ovr	0x0002
_PCL
	res	1
UD_abs_mc31p11_3	udata_ovr	0x0003
_STATUSbits
_STATUS
	res	1
UD_abs_mc31p11_4	udata_ovr	0x0004
_MCRbits
_MCR
	res	1
UD_abs_mc31p11_5	udata_ovr	0x0005
_INTECONbits
_INTECON
	res	1
UD_abs_mc31p11_6	udata_ovr	0x0006
_INTFLAGbits
_INTFLAG
	res	1
UD_abs_mc31p11_7	udata_ovr	0x0007
_IOP0bits
_IOP0
	res	1
UD_abs_mc31p11_8	udata_ovr	0x0008
_OEP0bits
_OEP0
	res	1
UD_abs_mc31p11_9	udata_ovr	0x0009
_PUP0bits
_PUP0
	res	1
UD_abs_mc31p11_a	udata_ovr	0x000a
_DKWP0bits
_DKWP0
	res	1
UD_abs_mc31p11_b	udata_ovr	0x000b
_IOP1bits
_IOP1
	res	1
UD_abs_mc31p11_c	udata_ovr	0x000c
_OEP1bits
_OEP1
	res	1
UD_abs_mc31p11_d	udata_ovr	0x000d
_PUP1bits
_PUP1
	res	1
UD_abs_mc31p11_e	udata_ovr	0x000e
_DKWP1bits
_DKWP1
	res	1
UD_abs_mc31p11_f	udata_ovr	0x000f
_DKWbits
_DKW
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
code_mc31p11	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
