;--------------------------------------------------------
; File Created by SN-SDCC : ANSI-C Compiler
; Version 0.0.2 (Jun 26 2013) (Linux)
; This file was generated Fri Jul  5 15:49:23 2013
;--------------------------------------------------------
; MC3X port for the RISC core
;--------------------------------------------------------
;	.file	"main.c"
	list	p=30p011
	radix dec
	include "mc30p011.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_i2cint
	extern	_i2cout
	extern	_i
	extern	_j
	extern	_n
	extern	_table
	extern	__gptrget1
	extern	__sdcc_gsinit_startup
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	_main

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
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_main_0	udata
r0x1002	res	1
r0x1003	res	1
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
code_main	code
;***
;  pBlock Stats: dbName = M
;***
;entry:  _main	;Function start
; 2 exit points
;has an exit
;functions called:
;   _i2cint
;   __gptrget1
;   _i2cout
;   _i2cint
;   __gptrget1
;   _i2cout
;4 compiler assigned registers:
;   r0x1002
;   r0x1003
;   STK01
;   STK00
;; Starting pCode block
_main	;Function start
; 2 exit points
;	.line	9; "main.c"	i2cint();     
	CALL	_i2cint
_00106_DS_
;	.line	12; "main.c"	for(i=0x00;i<=127;++i)
	CLRR	_i
;;swapping arguments (AOP_TYPEs 1/3)
;;unsigned compare: left >= lit(0x80=128), size=1
_00108_DS_
	MOVAI	0x80
	RSUBAR	_i
	JBCLR	STATUS,0
	GOTO	_00106_DS_
;;genSkipc:3244: created from rifx:0xbfe2bb14
;	.line	14; "main.c"	j=table[i]; 
	MOVAR	_i
	ADDAI	(_table + 0)
	MOVRA	r0x1002
	MOVAI	high (_table + 0)
	JBCLR	STATUS,0
	ADDAI	0x01
	MOVRA	r0x1003
	MOVAR	r0x1002
	MOVRA	STK01
	MOVAR	r0x1003
	MOVRA	STK00
	MOVAI	0x80
	CALL	__gptrget1
	MOVRA	_j
;	.line	15; "main.c"	i2cout(); 
	CALL	_i2cout
;	.line	12; "main.c"	for(i=0x00;i<=127;++i)
	INCR	_i
	GOTO	_00108_DS_
	RETURN	
; exit point of _main


;	code size estimation:
;	   24+    0 =    24 instructions (   48 byte)

	end
