		LIST
;mc32t7333.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================



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
PFLAG     		EQU		H'0187'
MCR       		EQU		H'0188'
INDF3     		EQU		H'0189'
INTE      		EQU		H'018A'
INTF      		EQU		H'018B'
OSCM      		EQU		H'018C'
KBCR      		EQU		H'018F'
IOP0      		EQU		H'0190'
OEP0      		EQU		H'0191'
PUP0      		EQU		H'0192'
PDP0      		EQU		H'0193'
IOP1      		EQU		H'0194'
OEP1      		EQU		H'0195'
PUP1      		EQU		H'0196'
PDP1      		EQU		H'0197'
IOP2      		EQU		H'0198'
OEP2      		EQU		H'0199'
PUP2      		EQU		H'019A'
PDP2      		EQU		H'019B'
T0CR      		EQU		H'01A0'
T0CNT     		EQU		H'01A1'
T0LOAD    		EQU		H'01A2'
T0DATA    		EQU		H'01A3'
T1CR      		EQU		H'01A4'
T1CNT     		EQU		H'01A5'
T1LOAD    		EQU		H'01A6'
T1DATA    		EQU		H'01A7'
IICCR     		EQU		H'01B0'
IICSR     		EQU		H'01B1'
IICDR     		EQU		H'01B2'
ADCR0     		EQU		H'01B8'
ADCR1     		EQU		H'01B9'
ADRH      		EQU		H'01BA'
ADRL      		EQU		H'01BB'
ADIOS0    		EQU		H'01BC'
ADIOS1    		EQU		H'01BD'
OSADJCR   		EQU		H'01BE'

;----- PCL Bits ---------------------------------------------------


;----- PFLAG Bits ---------------------------------------------------

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
IICIE     		EQU		H'0005'
ADIE      		EQU		H'0006'

;----- INTF Bits ---------------------------------------------------

T0IF      		EQU		H'0000'
T1IF      		EQU		H'0001'
INT0IF    		EQU		H'0002'
INT1IF    		EQU		H'0003'
KBIF      		EQU		H'0004'
IICIF     		EQU		H'0005'
ADIF      		EQU		H'0006'

;----- OSCM Bits ---------------------------------------------------

HFEN      		EQU		H'0000'
LFEN      		EQU		H'0001'
CLKS      		EQU		H'0002'
STBH      		EQU		H'0004'
STBL      		EQU		H'0005'

;----- IOP0 Bits ---------------------------------------------------

P00D      		EQU		H'0000'
P01D      		EQU		H'0001'
P02D      		EQU		H'0002'
P03D      		EQU		H'0003'
P04D      		EQU		H'0004'
P05D      		EQU		H'0005'
P06D      		EQU		H'0006'
P07D      		EQU		H'0007'

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
P06PU     		EQU		H'0006'
P07PU     		EQU		H'0007'

;----- PDP0 Bits ---------------------------------------------------

P00PD     		EQU		H'0000'
P01PD     		EQU		H'0001'
P02PD     		EQU		H'0002'
P03PD     		EQU		H'0003'
P04PD     		EQU		H'0004'
P05PD     		EQU		H'0005'
P06PD     		EQU		H'0006'
P07PD     		EQU		H'0007'

;----- IOP1 Bits ---------------------------------------------------

P10D      		EQU		H'0000'
P11D      		EQU		H'0001'
P12D      		EQU		H'0002'
P13D      		EQU		H'0003'
P14D      		EQU		H'0004'
P15D      		EQU		H'0005'
P16D      		EQU		H'0006'
P17D      		EQU		H'0007'

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

;----- PDP1 Bits ---------------------------------------------------

P10PD     		EQU		H'0000'
P11PD     		EQU		H'0001'
P12PD     		EQU		H'0002'
P13PD     		EQU		H'0003'
P14PD     		EQU		H'0004'
P15PD     		EQU		H'0005'
P16PD     		EQU		H'0006'
P17PD     		EQU		H'0007'

;----- IOP2 Bits ---------------------------------------------------

P20D      		EQU		H'0000'
P21D      		EQU		H'0001'
P22D      		EQU		H'0002'
P23D      		EQU		H'0003'
P24D      		EQU		H'0004'
P25D      		EQU		H'0005'

;----- OEP2 Bits ---------------------------------------------------

P20OE     		EQU		H'0000'
P21OE     		EQU		H'0001'
P22OE     		EQU		H'0002'
P23OE     		EQU		H'0003'
P24OE     		EQU		H'0004'
P25OE     		EQU		H'0005'

;----- PUP2 Bits ---------------------------------------------------

P20PU     		EQU		H'0000'
P21PU     		EQU		H'0001'
P22PU     		EQU		H'0002'
P23PU     		EQU		H'0003'
P24PU     		EQU		H'0004'
P25PU     		EQU		H'0005'

;----- PDP2 Bits ---------------------------------------------------

P20PD     		EQU		H'0000'
P21PD     		EQU		H'0001'
P22PD     		EQU		H'0002'
P23PD     		EQU		H'0003'
P24PD     		EQU		H'0004'
P25PD     		EQU		H'0005'

;----- T0CR Bits ---------------------------------------------------

PWM0OE    		EQU		H'0006'
T0EN      		EQU		H'0007'

;----- T1CR Bits ---------------------------------------------------

PWM1OE    		EQU		H'0006'
T1EN      		EQU		H'0007'

;----- IICCR Bits ---------------------------------------------------

IICRDTP   		EQU		H'0001'
IICCKS0   		EQU		H'0004'
IICCKS1   		EQU		H'0005'
IICRS     		EQU		H'0006'
IICEN     		EQU		H'0007'

;----- IICSR Bits ---------------------------------------------------

RACK      		EQU		H'0001'
SACK      		EQU		H'0002'
IICACK    		EQU		H'0003'
IICWR     		EQU		H'0004'
IICRD     		EQU		H'0005'
IICSTP    		EQU		H'0006'
IICSTR    		EQU		H'0007'

;----- ADCR0 Bits ---------------------------------------------------

ADEN      		EQU		H'0000'
ADEOC     		EQU		H'0001'

;----- ADCR1 Bits ---------------------------------------------------

ADRSEL    		EQU		H'0007'

;----- ADIOS0 Bits ---------------------------------------------------

AN0EN     		EQU		H'0000'
AN1EN     		EQU		H'0001'
AN2EN     		EQU		H'0002'
AN3EN     		EQU		H'0003'
AN4EN     		EQU		H'0004'
AN5EN     		EQU		H'0005'
AN6EN     		EQU		H'0006'
AN7EN     		EQU		H'0007'

;----- ADIOS1 Bits ---------------------------------------------------

AN8EN     		EQU		H'0000'
AN9EN     		EQU		H'0001'
AN10EN    		EQU		H'0002'
AN11EN    		EQU		H'0003'
AN12EN    		EQU		H'0004'
AN13EN    		EQU		H'0005'

;----- OSADJCR Bits ---------------------------------------------------

OSADJEN   		EQU		H'0007'

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'1FF'
	__BADRAM H'18D'-H'18E'
	__BADRAM H'19C'-H'19F'
	__BADRAM H'1A8'-H'1AF'
	__BADRAM H'1B3'-H'1B7'
	__BADRAM H'1BF'
	__BADRAM H'1C0'-H'1FF'


;==========================================================================
;
;	Configuration Bits
;
;==========================================================================

_CONFIG1  		EQU		H'1FE1'
_CONFIG0  		EQU		H'1FE0'

;OPBIT1

;OPBIT0

		LIST
