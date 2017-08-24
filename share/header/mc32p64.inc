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
T2IE      		EQU		H'0004'
I2CIE     		EQU		H'0005'
ADIE      		EQU		H'0006'

;----- INTF Bits ---------------------------------------------------

T0IF      		EQU		H'0000'
T1IF      		EQU		H'0001'
INT0IF    		EQU		H'0002'
INT1IF    		EQU		H'0003'
T2IF      		EQU		H'0004'
I2CIF     		EQU		H'0005'
ADIF      		EQU		H'0006'

;----- OSCM Bits ---------------------------------------------------

HFEN      		EQU		H'0000'
LFEN      		EQU		H'0001'
CLKS      		EQU		H'0002'
STBH      		EQU		H'0004'
STBL      		EQU		H'0005'

;----- IOP0 Bits ---------------------------------------------------

P00       		EQU		H'0000'
P01       		EQU		H'0001'
P02       		EQU		H'0002'
P03       		EQU		H'0003'
P04       		EQU		H'0004'
P05       		EQU		H'0005'
P06       		EQU		H'0006'
P07       		EQU		H'0007'

;----- OEP0 Bits ---------------------------------------------------

P00OE     		EQU		H'0000'
P01OE     		EQU		H'0001'
P02OE     		EQU		H'0002'
P03OE     		EQU		H'0003'
P04OE     		EQU		H'0004'
P05OE     		EQU		H'0005'
P06OE     		EQU		H'0006'
P07OE     		EQU		H'0007'

;----- PUP0 Bits ---------------------------------------------------

P00PU     		EQU		H'0000'
P01PU     		EQU		H'0001'
P02PU     		EQU		H'0002'
P03PU     		EQU		H'0003'
P04PU     		EQU		H'0004'
P05PU     		EQU		H'0005'

;----- IOP1 Bits ---------------------------------------------------

P10       		EQU		H'0000'
P11       		EQU		H'0001'
P12       		EQU		H'0002'
P13       		EQU		H'0003'
P14       		EQU		H'0004'
P15       		EQU		H'0005'
P16       		EQU		H'0006'
P17       		EQU		H'0007'

;----- OEP1 Bits ---------------------------------------------------

P10OE     		EQU		H'0000'
P11OE     		EQU		H'0001'
P12OE     		EQU		H'0002'
P13OE     		EQU		H'0003'
P14OE     		EQU		H'0004'
P15OE     		EQU		H'0005'
P16OE     		EQU		H'0006'
P17OE     		EQU		H'0007'

;----- PUP1 Bits ---------------------------------------------------

P10PU     		EQU		H'0000'
P11PU     		EQU		H'0001'
P12PU     		EQU		H'0002'
P13PU     		EQU		H'0003'
P14PU     		EQU		H'0004'
P15PU     		EQU		H'0005'
P16PU     		EQU		H'0006'
P17PU     		EQU		H'0007'

;----- IOP2 Bits ---------------------------------------------------

P20       		EQU		H'0000'
P21       		EQU		H'0001'
P22       		EQU		H'0002'
P23       		EQU		H'0003'
P24       		EQU		H'0004'
P25       		EQU		H'0005'
P26       		EQU		H'0006'
P27       		EQU		H'0007'

;----- OEP2 Bits ---------------------------------------------------

P20OE     		EQU		H'0000'
P21OE     		EQU		H'0001'
P22OE     		EQU		H'0002'
P23OE     		EQU		H'0003'
P24OE     		EQU		H'0004'
P25OE     		EQU		H'0005'
P26OE     		EQU		H'0006'
P27OE     		EQU		H'0007'

;----- PUP2 Bits ---------------------------------------------------

P20PU     		EQU		H'0000'
P21PU     		EQU		H'0001'
P22PU     		EQU		H'0002'
P23PU     		EQU		H'0003'
P24PU     		EQU		H'0004'
P25PU     		EQU		H'0005'
P26PU     		EQU		H'0006'
P27PU     		EQU		H'0007'

;----- IOP3 Bits ---------------------------------------------------

P30       		EQU		H'0000'
P31       		EQU		H'0001'

;----- OEP3 Bits ---------------------------------------------------

P30OE     		EQU		H'0000'
P31OE     		EQU		H'0001'

;----- PUP3 Bits ---------------------------------------------------

P30PU     		EQU		H'0000'
P31PU     		EQU		H'0001'

;----- T0CR Bits ---------------------------------------------------

BUZ0OE    		EQU		H'0005'
PWM0OE    		EQU		H'0006'
TC0EN     		EQU		H'0007'

;----- T1CR Bits ---------------------------------------------------

BUZ1OE    		EQU		H'0005'
PWM1OE    		EQU		H'0006'
TC1EN     		EQU		H'0007'

;----- T2CR Bits ---------------------------------------------------

T2MOD     		EQU		H'0005'
TC2EN     		EQU		H'0007'

;----- TK0CRH Bits ---------------------------------------------------

TK0CLR    		EQU		H'0003'
TK0RCE    		EQU		H'0004'
TK0JE     		EQU		H'0005'

;----- TK0CRL Bits ---------------------------------------------------

TK0IE     		EQU		H'0006'
TK0IF     		EQU		H'0007'

;----- TK1CRH Bits ---------------------------------------------------

TK1CLR    		EQU		H'0003'
TK1RCE    		EQU		H'0004'
TK1JE     		EQU		H'0005'

;----- TK1CRL Bits ---------------------------------------------------

TK1IE     		EQU		H'0006'
TK1IF     		EQU		H'0007'

;----- TK2CRH Bits ---------------------------------------------------

TK2CLR    		EQU		H'0003'
TK2RCE    		EQU		H'0004'
TK2JE     		EQU		H'0005'

;----- TK2CRL Bits ---------------------------------------------------

TK2IE     		EQU		H'0006'
TK2IF     		EQU		H'0007'

;----- ADCR0 Bits ---------------------------------------------------

ADON      		EQU		H'0000'
ADEOC     		EQU		H'0001'

;----- ADCR1 Bits ---------------------------------------------------

ADIOS0    		EQU		H'0000'
ADIOS1    		EQU		H'0001'
ADOIS2    		EQU		H'0002'
ADIOS3    		EQU		H'0003'
ADIOS4    		EQU		H'0004'
ADIOS5    		EQU		H'0005'
ADOIS6    		EQU		H'0006'
ADIOS7    		EQU		H'0007'

;----- I2CCR Bits ---------------------------------------------------

RXAK      		EQU		H'0000'
HEN       		EQU		H'0001'
SRW       		EQU		H'0002'
TXAK      		EQU		H'0003'
HTX       		EQU		H'0004'
HBB       		EQU		H'0005'
HAAS      		EQU		H'0006'
HCF       		EQU		H'0007'

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
