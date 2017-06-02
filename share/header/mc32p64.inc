		LIST
;mc32p64.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __32P64
		MESSG "Processor-header file mismatch.  Verify selected processor."
	ENDIF

;==========================================================================
;
;	Register Definitions
;
;==========================================================================

;----- Register Files ---------------------------------------------------

INDF      		EQU		H'01B0'
INDF0     		EQU		H'01B0'
INDF1     		EQU		H'01B1'
INDF2     		EQU		H'01B2'
HIBYTE    		EQU		H'01B3'
FSR       		EQU		H'01B4'
FSR0      		EQU		H'01B4'
FSR1      		EQU		H'01B5'
PCL       		EQU		H'01B6'
STATUS    		EQU		H'01B7'
MCR       		EQU		H'01B8'
INDF3     		EQU		H'01B9'
INTE      		EQU		H'01BA'
INTF      		EQU		H'01BB'
OSCM      		EQU		H'01BC'
IOP0      		EQU		H'01C0'
OEP0      		EQU		H'01C1'
PUP0      		EQU		H'01C2'
IOP1      		EQU		H'01C4'
OEP1      		EQU		H'01C5'
PUP1      		EQU		H'01C6'
IOP2      		EQU		H'01C8'
OEP2      		EQU		H'01C9'
PUP2      		EQU		H'01CA'
IOP3      		EQU		H'01CC'
OEP3      		EQU		H'01CD'
PUP3      		EQU		H'01CE'
T0CR      		EQU		H'01D0'
T0CNT     		EQU		H'01D1'
T0LOAD    		EQU		H'01D2'
T0DATA    		EQU		H'01D3'
T1CR      		EQU		H'01D4'
T1CNT     		EQU		H'01D5'
T1LOAD    		EQU		H'01D6'
T1DATA    		EQU		H'01D7'
T2CR      		EQU		H'01D8'
T2CNTH    		EQU		H'01D9'
T2CNTL    		EQU		H'01DA'
T2LOADH   		EQU		H'01DB'
T2LOADL   		EQU		H'01DC'
TK0CRH    		EQU		H'01E0'
TK0CRL    		EQU		H'01E1'
TK0CNTH   		EQU		H'01E2'
TK0CNTL   		EQU		H'01E3'
TK1CRH    		EQU		H'01E4'
TK1CRL    		EQU		H'01E5'
TK1CNTH   		EQU		H'01E6'
TK1CNTL   		EQU		H'01E7'
TK2CRH    		EQU		H'01E8'
TK2CRL    		EQU		H'01E9'
TK2CNTH   		EQU		H'01EA'
TK2CNTL   		EQU		H'01EB'
ADCR0     		EQU		H'01EC'
ADCR1     		EQU		H'01ED'
ADRH      		EQU		H'01EE'
ADRL      		EQU		H'01EF'
I2CCR     		EQU		H'01F0'
I2CADDR   		EQU		H'01F1'
I2CDATA   		EQU		H'01F2'

;----- STATUS Bits ---------------------------------------------------

C         		EQU		STATUS,0
DC        		EQU		STATUS,1
Z         		EQU		STATUS,2

;----- MCR Bits ---------------------------------------------------

PD        		EQU		MCR,4
TO        		EQU		MCR,5
GIE       		EQU		MCR,7

;----- INTE Bits ---------------------------------------------------

T0IE      		EQU		INTE,0
T1IE      		EQU		INTE,1
INT0IE    		EQU		INTE,2
INT1IE    		EQU		INTE,3
T2IE      		EQU		INTE,4
I2CIE     		EQU		INTE,5
ADIE      		EQU		INTE,6

;----- INTF Bits ---------------------------------------------------

T0IF      		EQU		INTF,0
T1IF      		EQU		INTF,1
INT0IF    		EQU		INTF,2
INT1IF    		EQU		INTF,3
T2IF      		EQU		INTF,4
I2CIF     		EQU		INTF,5
ADIF      		EQU		INTF,6

;----- OSCM Bits ---------------------------------------------------

HFEN      		EQU		OSCM,0
LFEN      		EQU		OSCM,1
CLKS      		EQU		OSCM,2
STBH      		EQU		OSCM,4
STBL      		EQU		OSCM,5

;----- IOP0 Bits ---------------------------------------------------

P00       		EQU		IOP0,0
P01       		EQU		IOP0,1
P02       		EQU		IOP0,2
P03       		EQU		IOP0,3
P04       		EQU		IOP0,4
P05       		EQU		IOP0,5
P06       		EQU		IOP0,6
P07       		EQU		IOP0,7

;----- OEP0 Bits ---------------------------------------------------

P00OE     		EQU		OEP0,0
P01OE     		EQU		OEP0,1
P02OE     		EQU		OEP0,2
P03OE     		EQU		OEP0,3
P04OE     		EQU		OEP0,4
P05OE     		EQU		OEP0,5
P06OE     		EQU		OEP0,6
P07OE     		EQU		OEP0,7

;----- PUP0 Bits ---------------------------------------------------

P00PU     		EQU		PUP0,0
P01PU     		EQU		PUP0,1
P02PU     		EQU		PUP0,2
P03PU     		EQU		PUP0,3
P04PU     		EQU		PUP0,4
P05PU     		EQU		PUP0,5

;----- IOP1 Bits ---------------------------------------------------

P10       		EQU		IOP1,0
P11       		EQU		IOP1,1
P12       		EQU		IOP1,2
P13       		EQU		IOP1,3
P14       		EQU		IOP1,4
P15       		EQU		IOP1,5
P16       		EQU		IOP1,6
P17       		EQU		IOP1,7

;----- OEP1 Bits ---------------------------------------------------

P10OE     		EQU		OEP1,0
P11OE     		EQU		OEP1,1
P12OE     		EQU		OEP1,2
P13OE     		EQU		OEP1,3
P14OE     		EQU		OEP1,4
P15OE     		EQU		OEP1,5
P16OE     		EQU		OEP1,6
P17OE     		EQU		OEP1,7

;----- PUP1 Bits ---------------------------------------------------

P10PU     		EQU		PUP1,0
P11PU     		EQU		PUP1,1
P12PU     		EQU		PUP1,2
P13PU     		EQU		PUP1,3
P14PU     		EQU		PUP1,4
P15PU     		EQU		PUP1,5
P16PU     		EQU		PUP1,6
P17PU     		EQU		PUP1,7

;----- IOP2 Bits ---------------------------------------------------

P20       		EQU		IOP2,0
P21       		EQU		IOP2,1
P22       		EQU		IOP2,2
P23       		EQU		IOP2,3
P24       		EQU		IOP2,4
P25       		EQU		IOP2,5
P26       		EQU		IOP2,6
P27       		EQU		IOP2,7

;----- OEP2 Bits ---------------------------------------------------

P20OE     		EQU		OEP2,0
P21OE     		EQU		OEP2,1
P22OE     		EQU		OEP2,2
P23OE     		EQU		OEP2,3
P24OE     		EQU		OEP2,4
P25OE     		EQU		OEP2,5
P26OE     		EQU		OEP2,6
P27OE     		EQU		OEP2,7

;----- PUP2 Bits ---------------------------------------------------

P20PU     		EQU		PUP2,0
P21PU     		EQU		PUP2,1
P22PU     		EQU		PUP2,2
P23PU     		EQU		PUP2,3
P24PU     		EQU		PUP2,4
P25PU     		EQU		PUP2,5
P26PU     		EQU		PUP2,6
P27PU     		EQU		PUP2,7

;----- IOP3 Bits ---------------------------------------------------

P30       		EQU		IOP3,0
P31       		EQU		IOP3,1

;----- OEP3 Bits ---------------------------------------------------

P30OE     		EQU		OEP3,0
P31OE     		EQU		OEP3,1

;----- PUP3 Bits ---------------------------------------------------

P30PU     		EQU		PUP3,0
P31PU     		EQU		PUP3,1

;----- T0CR Bits ---------------------------------------------------

BUZ0OE    		EQU		T0CR,5
PWM0OE    		EQU		T0CR,6
TC0EN     		EQU		T0CR,7

;----- T1CR Bits ---------------------------------------------------

BUZ1OE    		EQU		T1CR,5
PWM1OE    		EQU		T1CR,6
TC1EN     		EQU		T1CR,7

;----- T2CR Bits ---------------------------------------------------

T2MOD     		EQU		T2CR,5
TC2EN     		EQU		T2CR,7

;----- TK0CRH Bits ---------------------------------------------------

TK0CLR    		EQU		TK0CRH,3
TK0RCE    		EQU		TK0CRH,4
TK0JE     		EQU		TK0CRH,5

;----- TK0CRL Bits ---------------------------------------------------

TK0IE     		EQU		TK0CRL,6
TK0IF     		EQU		TK0CRL,7

;----- TK1CRH Bits ---------------------------------------------------

TK1CLR    		EQU		TK1CRH,3
TK1RCE    		EQU		TK1CRH,4
TK1JE     		EQU		TK1CRH,5

;----- TK1CRL Bits ---------------------------------------------------

TK1IE     		EQU		TK1CRL,6
TK1IF     		EQU		TK1CRL,7

;----- TK2CRH Bits ---------------------------------------------------

TK2CLR    		EQU		TK2CRH,3
TK2RCE    		EQU		TK2CRH,4
TK2JE     		EQU		TK2CRH,5

;----- TK2CRL Bits ---------------------------------------------------

TK2IE     		EQU		TK2CRL,6
TK2IF     		EQU		TK2CRL,7

;----- ADCR0 Bits ---------------------------------------------------

ADON      		EQU		ADCR0,0
ADEOC     		EQU		ADCR0,1

;----- ADCR1 Bits ---------------------------------------------------

ADIOS0    		EQU		ADCR1,0
ADIOS1    		EQU		ADCR1,1
ADOIS2    		EQU		ADCR1,2
ADIOS3    		EQU		ADCR1,3
ADIOS4    		EQU		ADCR1,4
ADIOS5    		EQU		ADCR1,5
ADOIS6    		EQU		ADCR1,6
ADIOS7    		EQU		ADCR1,7

;----- I2CCR Bits ---------------------------------------------------

RXAK      		EQU		I2CCR,0
HEN       		EQU		I2CCR,1
SRW       		EQU		I2CCR,2
TXAK      		EQU		I2CCR,3
HTX       		EQU		I2CCR,4
HBB       		EQU		I2CCR,5
HAAS      		EQU		I2CCR,6
HCF       		EQU		I2CCR,7

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'1FF'
	__BADRAM H'140'-H'1AF'
	__BADRAM H'1BD'-H'1BF'
	__BADRAM H'1C3'
	__BADRAM H'1C8'
	__BADRAM H'1DD'-H'1DF'
	__BADRAM H'1F3'-H'1FA'
	__BADRAM H'1F4'-H'1FF'


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
