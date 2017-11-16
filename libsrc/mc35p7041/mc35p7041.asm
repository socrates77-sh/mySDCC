;--------------------------------------------------------
; File Created by SN-SDCC : SinoMCU ANSI-C Compiler
; Version 1.0.0 (Sep 28 2017) (MINGW32)
; This file was generated Tue Nov 14 18:38:33 2017
;--------------------------------------------------------
; MC35 port for the RISC core
;--------------------------------------------------------
;	.file	"mc35p7041.c"
	list	p=2K7041
	radix dec
	include "2K7041.inc"
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
	global	_INDF
	global	_HIBYTE
	global	_FSR
	global	_FSR0
	global	_FSR1
	global	_PCH
	global	_PCL
	global	_STATUS

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_mc35p7041_82	udata_ovr	0x0082
_HIBYTE
	res	1
UD_abs_mc35p7041_83	udata_ovr	0x0083
_FSR
_FSR0
	res	1
UD_abs_mc35p7041_84	udata_ovr	0x0084
_FSR1
	res	1
UD_abs_mc35p7041_86	udata_ovr	0x0086
_STATUSbits
_STATUS
	res	1
UD_abs_mc35p7041_ce	udata_ovr	0x00ce
_PCL
	res	1
UD_abs_mc35p7041_cf	udata_ovr	0x00cf
_PCH
	res	1
UD_abs_mc35p7041_e7	udata_ovr	0x00e7
_INDF
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
code_mc35p7041	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
