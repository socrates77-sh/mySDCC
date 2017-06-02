		LIST
;mc32p7212.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __32P7212
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
PFLAG     		EQU		H'0187'
MCR       		EQU		H'0188'
INDF3     		EQU		H'0189'
INTE      		EQU		H'018A'
INTF      		EQU		H'018B'
IOP0      		EQU		H'0190'
OEP0      		EQU		H'0191'
PUP0      		EQU		H'0192'
IOP1      		EQU		H'0194'
OEP1      		EQU		H'0195'
PUP1      		EQU		H'0196'
IOP2      		EQU		H'0198'
OEP2      		EQU		H'0199'
PUP2      		EQU		H'019A'
IOP3      		EQU		H'019C'
OEP3      		EQU		H'019D'
PUP3      		EQU		H'019E'
T0CR      		EQU		H'01A0'
T0CNT     		EQU		H'01A1'
T0LOAD    		EQU		H'01A2'
T0DATA    		EQU		H'01A3'
T1CR      		EQU		H'01A4'
T1CNT     		EQU		H'01A5'
T1LOAD    		EQU		H'01A6'
T1DATA    		EQU		H'01A7'
LXTCR     		EQU		H'01A8'
PUMP      		EQU		H'01AD'
OSCM      		EQU		H'01AE'
LVDCR     		EQU		H'01AF'
ADCR0     		EQU		H'01B0'
ADCR1     		EQU		H'01B1'
ADCR2     		EQU		H'01B2'
TPSC      		EQU		H'01B3'
ADRH      		EQU		H'01B4'
ADRM      		EQU		H'01B5'
ADRL      		EQU		H'01B6'
LCDCR0    		EQU		H'01B8'
LCDCR1    		EQU		H'01B9'
LCDIOS1   		EQU		H'01BA'
LCDIOS2   		EQU		H'01BB'
LCDDS2    		EQU		H'01C0'
LCDDS3    		EQU		H'01C1'
LCDDS4    		EQU		H'01C2'
LCDDS5    		EQU		H'01C3'
LCDDS6    		EQU		H'01C4'
LCDDS7    		EQU		H'01C5'
LCDDS8    		EQU		H'01C6'
LCDDS9    		EQU		H'01C7'
LCDDS10   		EQU		H'01C8'
LCDDS11   		EQU		H'01C9'
LCDDS12   		EQU		H'01CA'
LCDDS13   		EQU		H'01CB'

;----- PFLAG Bits ---------------------------------------------------

#define		C         	PFLAG,0
#define		DC        	PFLAG,1
#define		Z         	PFLAG,2

;----- MCR Bits ---------------------------------------------------

#define		PD        	MCR,4
#define		TO        	MCR,5
#define		GIE       	MCR,7

;----- INTE Bits ---------------------------------------------------

#define		T0IE      	INTE,0
#define		T1IE      	INTE,1
#define		INT0IE    	INTE,2
#define		INT1IE    	INTE,3
#define		T2IE      	INTE,5
#define		ADIE      	INTE,6
#define		T3IE      	INTE,7

;----- INTF Bits ---------------------------------------------------

#define		T0IF      	INTF,0
#define		T1IF      	INTF,1
#define		INT0IF    	INTF,2
#define		INT1IF    	INTF,3
#define		T2IF      	INTF,5
#define		ADIF      	INTF,6
#define		T3IF      	INTF,7

;----- IOP0 Bits ---------------------------------------------------

#define		P00D      	IOP0,0
#define		P01D      	IOP0,1
#define		P02D      	IOP0,2
#define		P03D      	IOP0,3
#define		P04D      	IOP0,4
#define		P05D      	IOP0,5
#define		P06D      	IOP0,6
#define		P07D      	IOP0,7

;----- OEP0 Bits ---------------------------------------------------

#define		P00OE     	OEP0,0
#define		P01OE     	OEP0,1
#define		P02OE     	OEP0,2
#define		P03OE     	OEP0,3
#define		P04OE     	OEP0,4
#define		P05OE     	OEP0,5
#define		P06OE     	OEP0,6
#define		P07OE     	OEP0,7

;----- PUP0 Bits ---------------------------------------------------

#define		P00PU     	PUP0,0
#define		P01PU     	PUP0,1
#define		P02PU     	PUP0,2
#define		P03PU     	PUP0,3
#define		P04PU     	PUP0,4
#define		P05PU     	PUP0,5
#define		P06PU     	PUP0,6
#define		P07PU     	PUP0,7

;----- IOP1 Bits ---------------------------------------------------

#define		P10D      	IOP1,0
#define		P11D      	IOP1,1
#define		P12D      	IOP1,2
#define		P13D      	IOP1,3
#define		P14D      	IOP1,4
#define		P15D      	IOP1,5

;----- OEP1 Bits ---------------------------------------------------

#define		P10OE     	OEP1,0
#define		P11OE     	OEP1,1
#define		P12OE     	OEP1,2
#define		P13OE     	OEP1,3
#define		P14OE     	OEP1,4
#define		P15OE     	OEP1,5

;----- PUP1 Bits ---------------------------------------------------

#define		P10PU     	PUP1,0
#define		P11PU     	PUP1,1
#define		P12PU     	PUP1,2
#define		P13PU     	PUP1,3
#define		P14PU     	PUP1,4
#define		P15PU     	PUP1,5

;----- IOP2 Bits ---------------------------------------------------

#define		P20D      	IOP2,0
#define		P21D      	IOP2,1
#define		P22D      	IOP2,2
#define		P23D      	IOP2,3
#define		P24D      	IOP2,4
#define		P25D      	IOP2,5
#define		P26D      	IOP2,6
#define		P27D      	IOP2,7

;----- OEP2 Bits ---------------------------------------------------

#define		P20OE     	OEP2,0
#define		P21OE     	OEP2,1
#define		P22OE     	OEP2,2
#define		P23OE     	OEP2,3
#define		P24OE     	OEP2,4
#define		P25OE     	OEP2,5
#define		P26OE     	OEP2,6
#define		P27OE     	OEP2,7

;----- PUP2 Bits ---------------------------------------------------

#define		P20PU     	PUP2,0
#define		P21PU     	PUP2,1
#define		P22PU     	PUP2,2
#define		P23PU     	PUP2,3
#define		P24PU     	PUP2,4
#define		P25PU     	PUP2,5
#define		P26PU     	PUP2,6
#define		P27PU     	PUP2,7

;----- IOP3 Bits ---------------------------------------------------

#define		P30D      	IOP3,0
#define		P31D      	IOP3,1
#define		P32D      	IOP3,2
#define		P33D      	IOP3,3

;----- OEP3 Bits ---------------------------------------------------

#define		P30OE     	OEP3,0
#define		P31OE     	OEP3,1
#define		P32OE     	OEP3,2
#define		P33OE     	OEP3,3

;----- PUP3 Bits ---------------------------------------------------

#define		P30PU     	PUP3,0
#define		P31PU     	PUP3,1
#define		P32PU     	PUP3,2
#define		P33PU     	PUP3,3

;----- T0CR Bits ---------------------------------------------------

#define		BUZ0OE    	T0CR,5
#define		PWM0OE    	T0CR,6
#define		TC0EN     	T0CR,7

;----- T1CR Bits ---------------------------------------------------

#define		BUZ1OE    	T1CR,5
#define		PWM1OE    	T1CR,6
#define		TC1EN     	T1CR,7

;----- LXTCR Bits ---------------------------------------------------

#define		FILS      	LXTCR,3
#define		VDLSEL    	LXTCR,4
#define		RSEL      	LXTCR,5
#define		LDOLPEN   	LXTCR,6

;----- PUMP Bits ---------------------------------------------------

#define		CHP_VPP   	PUMP,2
#define		PGMTIME   	PUMP,3
#define		VCP_CAL   	PUMP,4
#define		CPCKS     	PUMP,5
#define		PUMPEN    	PUMP,6
#define		ERV       	PUMP,7

;----- OSCM Bits ---------------------------------------------------

#define		HFEN      	OSCM,0
#define		LFEN      	OSCM,1
#define		CLKS      	OSCM,2
#define		HIRCOUTEN 	OSCM,3
#define		STBH      	OSCM,4
#define		STBL      	OSCM,5

;----- LVDCR Bits ---------------------------------------------------

#define		LVDF      	LVDCR,0
#define		VBGSEL    	LVDCR,2
#define		LVDEN     	LVDCR,7

;----- ADCR0 Bits ---------------------------------------------------

#define		VREF_ICTL 	ADCR0,4
#define		PGA_EN    	ADCR0,5
#define		CHOP_EN   	ADCR0,6
#define		ADEN      	ADCR0,7

;----- ADCR1 Bits ---------------------------------------------------


;----- ADCR2 Bits ---------------------------------------------------

#define		T_PGA_OUT_ENB	ADCR2,6
#define		T_ADC_IN_RNB	ADCR2,7

;----- TPSC Bits ---------------------------------------------------

#define		PT_TS     	TPSC,2
#define		VBGEN     	TPSC,3
#define		VLDOEN    	TPSC,4
#define		VLDOSL1   	TPSC,5
#define		VLDOSL0   	TPSC,6
#define		ADC_T     	TPSC,7

;----- LCDCR0 Bits ---------------------------------------------------

#define		LCDSPEED  	LCDCR0,2
#define		LCDEN     	LCDCR0,7

;----- LCDCR1 Bits ---------------------------------------------------

#define		LCDCKS    	LCDCR1,2
#define		LCDM      	LCDCR1,3
#define		BEN       	LCDCR1,4

;----- LCDIOS2 Bits ---------------------------------------------------


;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'1FF'
	__BADRAM H'80'-H'17F'
	__BADRAM H'18C'-H'18F'
	__BADRAM H'193'
	__BADRAM H'197'
	__BADRAM H'19B'
	__BADRAM H'19F'
	__BADRAM H'1B7'
	__BADRAM H'1BC'-H'1BF'
	__BADRAM H'1CC'-H'1FF'


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
