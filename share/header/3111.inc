		LIST
;mc31p11.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __31P11
		MESSG "Processor-header file mismatch.  Verify selected processor."
	ENDIF

;==========================================================================
;
;	Register Definitions
;
;==========================================================================

;----- Register Files ---------------------------------------------------

INDF      		EQU		H'0000'
FSR       		EQU		H'0001'
PCL       		EQU		H'0002'
STATUS    		EQU		H'0003'
MCR       		EQU		H'0004'
INTECON   		EQU		H'0005'
INTFLAG   		EQU		H'0006'
IOP0      		EQU		H'0007'
OEP0      		EQU		H'0008'
PUP0      		EQU		H'0009'
DKWP0     		EQU		H'000A'
IOP1      		EQU		H'000B'
OEP1      		EQU		H'000C'
PUP1      		EQU		H'000D'
DKWP1     		EQU		H'000E'
DKW       		EQU		H'000F'

;----- STATUS Bits ---------------------------------------------------

C         		EQU		H'0000'
DC        		EQU		H'0001'
Z         		EQU		H'0002'

;----- MCR Bits ---------------------------------------------------

PD        		EQU		H'0004'
TO        		EQU		H'0005'
GIE       		EQU		H'0007'

;----- INTECON Bits ---------------------------------------------------

INT0IE    		EQU		H'0002'
INT1IE    		EQU		H'0003'

;----- INTFLAG Bits ---------------------------------------------------

INT0IF    		EQU		H'0002'
INT1IF    		EQU		H'0003'

;----- IOP0 Bits ---------------------------------------------------

IOP00     		EQU		H'0000'
IOP01     		EQU		H'0001'
IOP02     		EQU		H'0002'
IOP03     		EQU		H'0003'
IOP04     		EQU		H'0004'
IOP05     		EQU		H'0005'
IOP06     		EQU		H'0006'

;----- OEP0 Bits ---------------------------------------------------

OEP00     		EQU		H'0000'
OEP01     		EQU		H'0001'
OEP02     		EQU		H'0002'
OEP03     		EQU		H'0003'
OEP04     		EQU		H'0004'
OEP05     		EQU		H'0005'
OEP06     		EQU		H'0006'

;----- PUP0 Bits ---------------------------------------------------

PUP00     		EQU		H'0000'
PUP01     		EQU		H'0001'
PUP02     		EQU		H'0002'
PUP03     		EQU		H'0003'
PUP04     		EQU		H'0004'
PUP05     		EQU		H'0005'
PUP06     		EQU		H'0006'

;----- DKWP0 Bits ---------------------------------------------------

DKWP00    		EQU		H'0000'
DKWP01    		EQU		H'0001'
DKWP02    		EQU		H'0002'
DKWP03    		EQU		H'0003'
DKWP04    		EQU		H'0004'
DKWP05    		EQU		H'0005'

;----- IOP1 Bits ---------------------------------------------------

IOP10     		EQU		H'0000'
IOP11     		EQU		H'0001'
IOP12     		EQU		H'0002'
IOP13     		EQU		H'0003'
IOP14     		EQU		H'0004'
IOP15     		EQU		H'0005'
IOP16     		EQU		H'0006'

;----- OEP1 Bits ---------------------------------------------------

OEP10     		EQU		H'0000'
OEP11     		EQU		H'0001'
OEP12     		EQU		H'0002'
OEP13     		EQU		H'0003'
OEP14     		EQU		H'0004'
OEP15     		EQU		H'0005'
OEP16     		EQU		H'0006'

;----- PUP1 Bits ---------------------------------------------------

PUP10     		EQU		H'0000'
PUP11     		EQU		H'0001'
PUP12     		EQU		H'0002'
PUP13     		EQU		H'0003'
PUP14     		EQU		H'0004'
PUP15     		EQU		H'0005'
PUP16     		EQU		H'0006'

;----- DKWP1 Bits ---------------------------------------------------

DKWP10    		EQU		H'0000'
DKWP11    		EQU		H'0001'
DKWP12    		EQU		H'0002'
DKWP13    		EQU		H'0003'
DKWP14    		EQU		H'0004'
DKWP15    		EQU		H'0005'
DKWP16    		EQU		H'0006'

;----- DKW Bits ---------------------------------------------------

RSEL      		EQU		H'0006'
DKWE      		EQU		H'0007'

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'2F'


;==========================================================================
;
;	Configuration Bits
;
;==========================================================================

_CONFIG1  		EQU		H'8001'
_CONFIG0  		EQU		H'8000'

;OPBIT1

;OPBIT0
_CP_ALL         	EQU		H'0FFF'
_WDT_ALWAYS_OFF 	EQU		H'1FFC'
_WDT_SLEEP_OFF  	EQU		H'1FFD'
_WDT_ALWAYS_ON  	EQU		H'1FFF'
_FCPU_2X        	EQU		H'1FF3'
_FCPU_4X        	EQU		H'1FF7'
_FCPU_8X        	EQU		H'1FFB'
_FCPU_16X       	EQU		H'1FFF'

		LIST
