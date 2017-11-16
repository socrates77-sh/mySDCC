		LIST
;mc35p7041.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __2K7041
		MESSG "Processor-header file mismatch.  Verify selected processor."
	ENDIF

;==========================================================================
;
;	Register Definitions
;
;==========================================================================

;----- Register Files ---------------------------------------------------

INDF      		EQU		H'00E7'
HIBYTE    		EQU		H'0082'
FSR       		EQU		H'0083'
FSR0      		EQU		H'0083'
FSR1      		EQU		H'0084'
PCH       		EQU		H'00CF'
PCL       		EQU		H'00CE'
STATUS    		EQU		H'0086'

;----- STATUS Bits ---------------------------------------------------

Z         		EQU		H'0000'
DC        		EQU		H'0001'
C         		EQU		H'0002'

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'FF'
	__BADRAM H'80'-H'81'
	__BADRAM H'85'
	__BADRAM H'87'-H'9F'
	__BADRAM H'A1'-H'A4'
	__BADRAM H'A6'-H'AC'
	__BADRAM H'B0'
	__BADRAM H'B6'-H'B7'
	__BADRAM H'B9'-H'BE'
	__BADRAM H'C0'-H'C3'
	__BADRAM H'C6'-H'C7'
	__BADRAM H'D1'-H'D3'
	__BADRAM H'D6'-H'D7'
	__BADRAM H'DD'-H'DE'
	__BADRAM H'E1'-H'E3'
	__BADRAM H'E6'
	__BADRAM H'EF'


;==========================================================================
;
;	Configuration Bits
;
;==========================================================================

_CONFIG1  		EQU		H'8001'
_CONFIG0  		EQU		H'8000'

;OPBIT1

;OPBIT0

		LIST
