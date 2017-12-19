; -----------------------------------------------
; --- extern declared SFRs
; -----------------------------------------------
	extern _PFLAG
	extern _FSR0
	extern _FSR1
	extern _INDF0
	extern _INDF1
	extern _INDF2
	extern _INDF3
	;extern _FSR
	;extern _INDF
	;extern _PCLATH
	extern _PCL
	extern _HIBYTE

C	EQU	0
DC	EQU	1
Z	EQU	2
IRP	EQU	7
	
; -----------------------------------------------
; --- generic pointer access helpers
; -----------------------------------------------

GPTRTAG_DATA	EQU	0x00
GPTRTAG_CODE	EQU	0x80

; setup FSR to point to (STK00:STK01)
setup_fsr  	macro
	movar	STK00
	movra	_FSR1
	movar	STK01
	movra	_FSR0
	endm

inc_fsr	   	macro
   	incr 	_FSR0
   	jbclr	_PFLAG, Z
   	addra	_FSR1
	endm

; dispatch according to gptr type
select_routine	macro	dataptr, codeptr
	; __data pointer tag: 0x00
	xorai	GPTRTAG_DATA
	jbclr	_PFLAG, Z
	goto	dataptr
	; __code pointer tag: 0x80
	xorai	(GPTRTAG_DATA ^ GPTRTAG_CODE)
	jbclr	_PFLAG, Z
	goto	codeptr
	endm

check_data	macro	dataptr
	; __data pointer tag: 0x00
	xorai	GPTRTAG_DATA
	jbclr	_PFLAG, Z
	goto	dataptr
	endm

