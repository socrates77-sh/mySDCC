		LIST
;mc9902.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __99P2
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
PFLAG     		EQU		H'0187'
MCR       		EQU		H'0188'
INDF3     		EQU		H'0189'
INTE      		EQU		H'018A'
INTF      		EQU		H'018B'
OSCM      		EQU		H'018C'
LVDCR     		EQU		H'018D'
IOP0      		EQU		H'0190'
OEP0      		EQU		H'0191'
PUP0      		EQU		H'0192'
RUPSEL    		EQU		H'0193'
IOP1      		EQU		H'0194'
OEP1      		EQU		H'0195'
PUP1      		EQU		H'0196'
T0CR      		EQU		H'01A0'
T0CNT     		EQU		H'01A1'
T0LOAD    		EQU		H'01A2'
T0DATA    		EQU		H'01A3'
T1CR      		EQU		H'01A4'
T1CNT     		EQU		H'01A5'
T1LOAD    		EQU		H'01A6'
T1DATA    		EQU		H'01A7'
ADCR0     		EQU		H'01B0'
ADCR1     		EQU		H'01B1'
ADCR2     		EQU		H'01B2'
ADRH      		EQU		H'01B4'
ADRM      		EQU		H'01B5'
ADRL      		EQU		H'01B6'
IICCR     		EQU		H'01B8'
IICAR     		EQU		H'01B9'
IICDR     		EQU		H'01BA'

STATUS			EQU		PFLAG

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
I2CIE     		EQU		H'0005'
ADIE      		EQU		H'0006'

;----- INTF Bits ---------------------------------------------------

T0IF      		EQU		H'0000'
T1IF      		EQU		H'0001'
INT0IF    		EQU		H'0002'
INT1IF    		EQU		H'0003'
I2CIF     		EQU		H'0005'
ADIF      		EQU		H'0006'

;----- OSCM Bits ---------------------------------------------------

HFEN      		EQU		H'0000'
LFEN      		EQU		H'0001'
CLKS      		EQU		H'0002'
STBH      		EQU		H'0004'
STBL      		EQU		H'0005'

;----- LVDCR Bits ---------------------------------------------------

LVDF      		EQU		H'0000'
LVDEN     		EQU		H'0007'

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

;----- RUPSEL Bits ---------------------------------------------------

I2CRS     		EQU		H'0007'

;----- IOP1 Bits ---------------------------------------------------

P10D      		EQU		H'0000'
P11D      		EQU		H'0001'

;----- OEP1 Bits ---------------------------------------------------

P10OE     		EQU		H'0000'
P11OE     		EQU		H'0001'

;----- PUP1 Bits ---------------------------------------------------

P10PU     		EQU		H'0000'
P11PU     		EQU		H'0001'

;----- T0CR Bits ---------------------------------------------------

BUZ0OE    		EQU		H'0005'
PWM0OE    		EQU		H'0006'
T0EN      		EQU		H'0007'

;----- T1CR Bits ---------------------------------------------------

BUZ1OE    		EQU		H'0005'
PWM1OE    		EQU		H'0006'
T1EN      		EQU		H'0007'

;----- ADCR0 Bits ---------------------------------------------------

CHOPEN    		EQU		H'0006'
ADEN      		EQU		H'0007'

;----- ADCR1 Bits ---------------------------------------------------


;----- ADCR2 Bits ---------------------------------------------------

ADVRS     		EQU		H'0000'
LDOEN     		EQU		H'0001'
VLDOS1    		EQU		H'0002'
VLDOS0    		EQU		H'0003'
AD2EN     		EQU		H'0004'
AD1EN     		EQU		H'0005'
AD0EN     		EQU		H'0006'

;----- ADRH Bits ---------------------------------------------------

ADR16     		EQU		H'0000'
ADR17     		EQU		H'0001'
ADR18     		EQU		H'0002'
ADR19     		EQU		H'0003'
ADR20     		EQU		H'0004'
ADR21     		EQU		H'0005'
ADR22     		EQU		H'0006'
ADR23     		EQU		H'0007'

;----- ADRM Bits ---------------------------------------------------

ADR8      		EQU		H'0000'
ADR9      		EQU		H'0001'
ADR10     		EQU		H'0002'
ADR11     		EQU		H'0003'
ADR12     		EQU		H'0004'
ADR13     		EQU		H'0005'
ADR14     		EQU		H'0006'
ADR15     		EQU		H'0007'

;----- IICCR Bits ---------------------------------------------------

RACK      		EQU		H'0000'
IICEN     		EQU		H'0001'
MSTCMD    		EQU		H'0002'
SACK      		EQU		H'0003'
IICM0D    		EQU		H'0004'
IICBUSY   		EQU		H'0005'
IICAAS    		EQU		H'0006'
IICE0F    		EQU		H'0007'

;----- IICAR Bits ---------------------------------------------------


;----- IICDR Bits ---------------------------------------------------


;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'1FF'
	__BADRAM H'80'-H'17F'
	__BADRAM H'18E'-H'18F'
	__BADRAM H'197'
	__BADRAM H'198'-H'19F'
	__BADRAM H'1A8'-H'1AF'
	__BADRAM H'1B3'
	__BADRAM H'1B7'
	__BADRAM H'1BB'-H'1BF'
	__BADRAM H'1C0'-H'1FF'


;==========================================================================
;
;	Configuration Bits
;
;==========================================================================

_CONFIG1  		EQU		H'0FED'
_CONFIG0  		EQU		H'0FEC'

;OPBIT1

;OPBIT0

		LIST
