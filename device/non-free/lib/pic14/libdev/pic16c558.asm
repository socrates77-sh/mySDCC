;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.2.0 #8004 (Aug 21 2017) (MINGW32)
; This file was generated Mon Aug 21 13:39:14 2017
;--------------------------------------------------------
; PIC port for the 14-bit core
;--------------------------------------------------------
;	.file	"pic16c558.c"
	list	p=16c558
	radix dec
	include "p16c558.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------

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
	global	_INTCONbits
	global	_OPTION_REGbits
	global	_PCONbits
	global	_PORTAbits
	global	_PORTBbits
	global	_STATUSbits
	global	_TRISAbits
	global	_TRISBbits
	global	_INDF
	global	_TMR0
	global	_PCL
	global	_STATUS
	global	_FSR
	global	_PORTA
	global	_PORTB
	global	_PCLATH
	global	_INTCON
	global	_OPTION_REG
	global	_TRISA
	global	_TRISB
	global	_PCON

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_pic16c558_0	udata_ovr	0x0000
_INDF
	res	1
UD_abs_pic16c558_1	udata_ovr	0x0001
_TMR0
	res	1
UD_abs_pic16c558_2	udata_ovr	0x0002
_PCL
	res	1
UD_abs_pic16c558_3	udata_ovr	0x0003
_STATUSbits
_STATUS
	res	1
UD_abs_pic16c558_4	udata_ovr	0x0004
_FSR
	res	1
UD_abs_pic16c558_5	udata_ovr	0x0005
_PORTAbits
_PORTA
	res	1
UD_abs_pic16c558_6	udata_ovr	0x0006
_PORTBbits
_PORTB
	res	1
UD_abs_pic16c558_a	udata_ovr	0x000a
_PCLATH
	res	1
UD_abs_pic16c558_b	udata_ovr	0x000b
_INTCONbits
_INTCON
	res	1
UD_abs_pic16c558_81	udata_ovr	0x0081
_OPTION_REGbits
_OPTION_REG
	res	1
UD_abs_pic16c558_85	udata_ovr	0x0085
_TRISAbits
_TRISA
	res	1
UD_abs_pic16c558_86	udata_ovr	0x0086
_TRISBbits
_TRISB
	res	1
UD_abs_pic16c558_8e	udata_ovr	0x008e
_PCONbits
_PCON
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
code_pic16c558	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
