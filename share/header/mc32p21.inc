		LIST
;mc32p21.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __32P21
		MESSG "Processor-header file mismatch.  Verify selected processor."
	ENDIF

;==========================================================================
;
;	Register Definitions
;
;==========================================================================

;----- Register Files ---------------------------------------------------

INDF      		EQU		H'0180'
INDF0     		EQU		H'0180'
INDF1     		EQU		H'0181'
INDF2     		EQU		H'0182'
HIBYTE    		EQU		H'0183'
FSR       		EQU		H'0184'
FSR0      		EQU		H'0184'
FSR1      		EQU		H'0185'
PCL       		EQU		H'0186'
STATUS    		EQU		H'0187'
MCR       		EQU		H'0188'
INDF3     		EQU		H'0189'
INTE      		EQU		H'018A'
INTF      		EQU		H'018B'
IOP0      		EQU		H'0190'
OEP0      		EQU		H'0191'
PUP0      		EQU		H'0192'
ANSEL     		EQU		H'0193'
IOP1      		EQU		H'0194'
OEP1      		EQU		H'0195'
PUP1      		EQU		H'0196'
KBIM      		EQU		H'0197'
T0CR      		EQU		H'01A0'
T0CNT     		EQU		H'01A1'
T0LOAD    		EQU		H'01A2'
T0DATA    		EQU		H'01A3'
T1CR      		EQU		H'01A4'
T1CNT     		EQU		H'01A5'
T1LOAD    		EQU		H'01A6'
T1DATA    		EQU		H'01A7'
LVDCR     		EQU		H'01AD'
OSCM      		EQU		H'01AE'
ADCR0     		EQU		H'01B0'
ADCR1     		EQU		H'01B1'
ADRH      		EQU		H'01B4'
ADRL      		EQU		H'01B5'
OSCAL     		EQU		H'01FB'

;----- STATUS Bits ---------------------------------------------------

C         		EQU		H'0000'
DC        		EQU		H'0001'
Z         		EQU		H'0002'

;----- MCR Bits ---------------------------------------------------

PD        		EQU		H'0004'
TO        		EQU		H'0005'
GIE       		EQU		H'0007'

;----- INTE Bits ---------------------------------------------------

T0IE      		EQU		H'0000'
T1IE      		EQU		H'0001'
INT0IE    		EQU		H'0002'
INT1IE    		EQU		H'0003'
KBIE      		EQU		H'0004'
ADIE      		EQU		H'0006'

;----- INTF Bits ---------------------------------------------------

T0IF      		EQU		H'0000'
T1IF      		EQU		H'0001'
INT0IF    		EQU		H'0002'
INT1IF    		EQU		H'0003'
KBIF      		EQU		H'0004'
ADIF      		EQU		H'0006'

;----- IOP0 Bits ---------------------------------------------------

P00       		EQU		H'0000'
P01       		EQU		H'0001'
P02       		EQU		H'0002'
P03       		EQU		H'0003'
P04       		EQU		H'0004'

;----- OEP0 Bits ---------------------------------------------------

P00OE     		EQU		H'0000'
P01OE     		EQU		H'0001'
P02OE     		EQU		H'0002'
P03OE     		EQU		H'0003'
P04OE     		EQU		H'0004'

;----- PUP0 Bits ---------------------------------------------------

P00PU     		EQU		H'0000'
P01PU     		EQU		H'0001'
P02PU     		EQU		H'0002'
P03PU     		EQU		H'0003'
P04PU     		EQU		H'0004'

;----- ANSEL Bits ---------------------------------------------------

P00ANS    		EQU		H'0000'
P01ANS    		EQU		H'0001'
P02ANS    		EQU		H'0002'
P03ANS    		EQU		H'0003'
P04ANS    		EQU		H'0004'
P12ANS    		EQU		H'0005'
P13ANS    		EQU		H'0006'

;----- IOP1 Bits ---------------------------------------------------

P10       		EQU		H'0000'
P11       		EQU		H'0001'
P12       		EQU		H'0002'
P13       		EQU		H'0003'
P14       		EQU		H'0004'
P15       		EQU		H'0005'
P16       		EQU		H'0006'

;----- OEP1 Bits ---------------------------------------------------

P10OE     		EQU		H'0000'
P11OE     		EQU		H'0001'
P12OE     		EQU		H'0002'
P13OE     		EQU		H'0003'
P14OE     		EQU		H'0004'
P15OE     		EQU		H'0005'
P16OE     		EQU		H'0006'

;----- PUP1 Bits ---------------------------------------------------

P10PU     		EQU		H'0000'
P11PU     		EQU		H'0001'
P12PU     		EQU		H'0002'
P13PU     		EQU		H'0003'
P14PU     		EQU		H'0004'
P15PU     		EQU		H'0005'
P16PU     		EQU		H'0006'

;----- KBIM Bits ---------------------------------------------------

KBIM0     		EQU		H'0000'
KBIM1     		EQU		H'0001'
KBIM2     		EQU		H'0002'
KBIM3     		EQU		H'0003'
KBIM4     		EQU		H'0004'
KBIM5     		EQU		H'0005'
KBIM6     		EQU		H'0006'

;----- T0CR Bits ---------------------------------------------------

BUZ0OE    		EQU		H'0005'
PWM0OE    		EQU		H'0006'
TC0EN     		EQU		H'0007'

;----- T1CR Bits ---------------------------------------------------

BUZ1OE    		EQU		H'0005'
PWM1OE    		EQU		H'0006'
TC1EN     		EQU		H'0007'

;----- LVDCR Bits ---------------------------------------------------

LVDF      		EQU		H'0000'
LVDEN     		EQU		H'0007'

;----- OSCM Bits ---------------------------------------------------

HFEN      		EQU		H'0000'
LFEN      		EQU		H'0001'
CLKS      		EQU		H'0002'
STBH      		EQU		H'0004'
STBL      		EQU		H'0005'

;----- ADCR0 Bits ---------------------------------------------------

ADON      		EQU		H'0000'
ADEOC     		EQU		H'0001'

;----- ADCR1 Bits ---------------------------------------------------


;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'1FF'
	__BADRAM H'80'-H'17F'
	__BADRAM H'18C'-H'18F'
	__BADRAM H'198'-H'19F'
	__BADRAM H'1A8'-H'1AC'
	__BADRAM H'1AF'
	__BADRAM H'1B2'-H'1B3'
	__BADRAM H'1B6'-H'1FA'
	__BADRAM H'1FC'-H'1FF'


;==========================================================================
;
;	Configuration Bits
;
;==========================================================================

_CONFIG1  		EQU		H'8001'
_CONFIG0  		EQU		H'8000'

;OPBIT1

;OPBIT0
_CP_ALL         	EQU		H'7FFF'
_WDT_ALWAYS_OFF 	EQU		H'FFFC'
_WDT_SLEEP_OFF  	EQU		H'FFFD'
_WDT_ALWAYS_ON  	EQU		H'FFFF'
_PTWRT_4_4      	EQU		H'DFF3'
_PTWRT_16_16    	EQU		H'DFF7'
_PTWRT_64_64    	EQU		H'DFFB'
_PTWRT_256_256  	EQU		H'DFFF'
_PTWRT_4_512    	EQU		H'FFF3'
_PTWRT_16_1024  	EQU		H'FFF7'
_PTWRT_64_2048  	EQU		H'FFFB'
_PTWRT_256_4096 	EQU		H'FFFF'
_FCPU_2T        	EQU		H'FF8F'
_FCPU_4T        	EQU		H'FF9F'
_FCPU_8T        	EQU		H'FFAF'
_FCPU_16T       	EQU		H'FFBF'
_FCPU_32T       	EQU		H'FFCF'
_FCPU_64T       	EQU		H'FFDF'
_FCPU_128T      	EQU		H'FFEF'
_FCPU_256T      	EQU		H'FFFF'
_MCLR_ON        	EQU		H'FFFF'
_MCLR_OFF       	EQU		H'FF7F'
_HRC_LRC        	EQU		H'FCFF'
_HRC_LXT        	EQU		H'FDFF'
_HXT_LRC        	EQU		H'FEFF'
_VLVR_160       	EQU		H'E3FF'
_VLVR_185       	EQU		H'E7FF'
_VLVR_205       	EQU		H'EBFF'
_VLVR_218       	EQU		H'EFFF'
_VLVR_232       	EQU		H'F3FF'
_VLVR_245       	EQU		H'F7FF'
_VLVR_305       	EQU		H'FBFF'
_VLVR_360       	EQU		H'FFFF'

		LIST
