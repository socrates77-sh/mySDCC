;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.2.0 #8004 (Aug 21 2017) (MINGW32)
; This file was generated Mon Aug 21 13:39:09 2017
;--------------------------------------------------------
; PIC port for the 14-bit core
;--------------------------------------------------------
;	.file	"pic12f629.c"
	list	p=12f629
	radix dec
	include "p12f629.inc"
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
	global	_CMCONbits
	global	_EECON1bits
	global	_GPIObits
	global	_INTCONbits
	global	_IOCbits
	global	_IOCBbits
	global	_OPTION_REGbits
	global	_OSCCALbits
	global	_PCONbits
	global	_PIE1bits
	global	_PIR1bits
	global	_STATUSbits
	global	_T1CONbits
	global	_TRISIObits
	global	_VRCONbits
	global	_WPUbits
	global	_INDF
	global	_TMR0
	global	_PCL
	global	_STATUS
	global	_FSR
	global	_GPIO
	global	_PCLATH
	global	_INTCON
	global	_PIR1
	global	_TMR1
	global	_TMR1L
	global	_TMR1H
	global	_T1CON
	global	_CMCON
	global	_OPTION_REG
	global	_TRISIO
	global	_PIE1
	global	_PCON
	global	_OSCCAL
	global	_WPU
	global	_IOC
	global	_IOCB
	global	_VRCON
	global	_EEDAT
	global	_EEDATA
	global	_EEADR
	global	_EECON1
	global	_EECON2

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
UD_abs_pic12f629_0	udata_ovr	0x0000
_INDF
	res	1
UD_abs_pic12f629_1	udata_ovr	0x0001
_TMR0
	res	1
UD_abs_pic12f629_2	udata_ovr	0x0002
_PCL
	res	1
UD_abs_pic12f629_3	udata_ovr	0x0003
_STATUSbits
_STATUS
	res	1
UD_abs_pic12f629_4	udata_ovr	0x0004
_FSR
	res	1
UD_abs_pic12f629_5	udata_ovr	0x0005
_GPIObits
_GPIO
	res	1
UD_abs_pic12f629_a	udata_ovr	0x000a
_PCLATH
	res	1
UD_abs_pic12f629_b	udata_ovr	0x000b
_INTCONbits
_INTCON
	res	1
UD_abs_pic12f629_c	udata_ovr	0x000c
_PIR1bits
_PIR1
	res	1
UD_abs_pic12f629_e	udata_ovr	0x000e
_TMR1
_TMR1L
	res	1
UD_abs_pic12f629_f	udata_ovr	0x000f
_TMR1H
	res	1
UD_abs_pic12f629_10	udata_ovr	0x0010
_T1CONbits
_T1CON
	res	1
UD_abs_pic12f629_19	udata_ovr	0x0019
_CMCONbits
_CMCON
	res	1
UD_abs_pic12f629_81	udata_ovr	0x0081
_OPTION_REGbits
_OPTION_REG
	res	1
UD_abs_pic12f629_85	udata_ovr	0x0085
_TRISIObits
_TRISIO
	res	1
UD_abs_pic12f629_8c	udata_ovr	0x008c
_PIE1bits
_PIE1
	res	1
UD_abs_pic12f629_8e	udata_ovr	0x008e
_PCONbits
_PCON
	res	1
UD_abs_pic12f629_90	udata_ovr	0x0090
_OSCCALbits
_OSCCAL
	res	1
UD_abs_pic12f629_95	udata_ovr	0x0095
_WPUbits
_WPU
	res	1
UD_abs_pic12f629_96	udata_ovr	0x0096
_IOCbits
_IOCBbits
_IOC
_IOCB
	res	1
UD_abs_pic12f629_99	udata_ovr	0x0099
_VRCONbits
_VRCON
	res	1
UD_abs_pic12f629_9a	udata_ovr	0x009a
_EEDAT
_EEDATA
	res	1
UD_abs_pic12f629_9b	udata_ovr	0x009b
_EEADR
	res	1
UD_abs_pic12f629_9c	udata_ovr	0x009c
_EECON1bits
_EECON1
	res	1
UD_abs_pic12f629_9d	udata_ovr	0x009d
_EECON2
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
code_pic12f629	code

;	code size estimation:
;	    0+    0 =     0 instructions (    0 byte)

	end
