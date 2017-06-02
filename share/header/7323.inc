		LIST
;mc32p7323.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __32P7323
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
OSCM      		EQU		H'018C'
IOP0      		EQU		H'0190'
OEP0      		EQU		H'0191'
PUP0      		EQU		H'0192'
IOP1      		EQU		H'0194'
OEP1      		EQU		H'0195'
PUP1      		EQU		H'0196'
IOP2      		EQU		H'0198'
OEP2      		EQU		H'0199'
PUP2      		EQU		H'019A'
T0CR      		EQU		H'01A0'
T0CNT     		EQU		H'01A1'
T0LOAD    		EQU		H'01A2'
T0DATA    		EQU		H'01A3'
T1CR      		EQU		H'01A4'
T1CNT     		EQU		H'01A5'
T1LOAD    		EQU		H'01A6'
T1DATA    		EQU		H'01A7'
T2CR      		EQU		H'01A8'
T2CNT     		EQU		H'01A9'
T2LOAD    		EQU		H'01AA'
T2DATA    		EQU		H'01AB'
T3CR      		EQU		H'01AC'
T3CNT     		EQU		H'01AD'
T3LOAD    		EQU		H'01AE'
PWM0DE    		EQU		H'01B0'
PWM1DE    		EQU		H'01B1'
PWM2DE    		EQU		H'01B0'
PWMCR0    		EQU		H'01B4'
PWMCR1    		EQU		H'01B5'
ADCR0     		EQU		H'01B8'
ADCR1     		EQU		H'01B9'
ADRH      		EQU		H'01BC'
ADRL      		EQU		H'01BD'
ANSEL     		EQU		H'01BE'
LEDCR0    		EQU		H'01C0'
LEDCR1    		EQU		H'01C1'
LCDCR0    		EQU		H'01C2'
LCDCR1    		EQU		H'01C3'
LCDIOS0   		EQU		H'01C4'
LCDIOS1   		EQU		H'01C5'
LCDIOS2   		EQU		H'01C6'

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

;----- INTF Bits ---------------------------------------------------

#define		T0IF      	INTF,0
#define		T1IF      	INTF,1
#define		INT0IF    	INTF,2
#define		INT1IF    	INTF,3
#define		T2IF      	INTF,5
#define		ADIF      	INTF,6

;----- OSCM Bits ---------------------------------------------------

#define		HFEN      	OSCM,0
#define		LFEN      	OSCM,1
#define		CLKS      	OSCM,2
#define		STBH      	OSCM,4
#define		STBL      	OSCM,5

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

;----- IOP1 Bits ---------------------------------------------------

#define		P10D      	IOP1,0
#define		P11D      	IOP1,1
#define		P12D      	IOP1,2
#define		P13D      	IOP1,3
#define		P14D      	IOP1,4
#define		P15D      	IOP1,5
#define		P16D      	IOP1,6
#define		P17D      	IOP1,7

;----- OEP1 Bits ---------------------------------------------------

#define		P10OE     	OEP1,0
#define		P11OE     	OEP1,1
#define		P12OE     	OEP1,2
#define		P13OE     	OEP1,3
#define		P14OE     	OEP1,4
#define		P15OE     	OEP1,5
#define		P16OE     	OEP1,6
#define		P17OE     	OEP1,7

;----- PUP1 Bits ---------------------------------------------------

#define		P10PU     	PUP1,0
#define		P11PU     	PUP1,1
#define		P12PU     	PUP1,2
#define		P13PU     	PUP1,3
#define		P14PU     	PUP1,4
#define		P15PU     	PUP1,5
#define		P16PU     	PUP1,6
#define		P17PU     	PUP1,7

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

;----- T0CR Bits ---------------------------------------------------

#define		BUZ0OE    	T0CR,5
#define		PWM0OE    	T0CR,6
#define		TC0EN     	T0CR,7

;----- T1CR Bits ---------------------------------------------------

#define		BUZ1OE    	T1CR,5
#define		PWM1OE    	T1CR,6
#define		TC1EN     	T1CR,7

;----- T2CR Bits ---------------------------------------------------

#define		BUZ2OE    	T2CR,5
#define		PWM2OE    	T2CR,6
#define		TC2EN     	T2CR,7

;----- T3CR Bits ---------------------------------------------------

#define		TC3EN     	T3CR,7

;----- PWMCR0 Bits ---------------------------------------------------

#define		PWM0INV   	PWMCR0,4
#define		FPWM1INV  	PWMCR0,5
#define		PWM2INV   	PWMCR0,6
#define		FPWMEN    	PWMCR0,7

;----- PWMCR1 Bits ---------------------------------------------------


;----- ADCR0 Bits ---------------------------------------------------

#define		ADON      	ADCR0,0
#define		ADEOC     	ADCR0,1

;----- ADCR1 Bits ---------------------------------------------------

#define		ADRSEL    	ADCR1,7

;----- ANSEL Bits ---------------------------------------------------

#define		P14ANS    	ANSEL,0
#define		P15ANS    	ANSEL,1
#define		P16ANS    	ANSEL,2
#define		P17ANS    	ANSEL,3
#define		P23ANS    	ANSEL,4
#define		P24ANS    	ANSEL,5
#define		P06ANS    	ANSEL,6
#define		P13ANS    	ANSEL,7

;----- LEDCR0 Bits ---------------------------------------------------

#define		LEDEN     	LEDCR0,7

;----- LEDCR1 Bits ---------------------------------------------------

#define		LEDCKS    	LEDCR1,6
#define		DRVPS     	LEDCR1,7

;----- LCDCR0 Bits ---------------------------------------------------

#define		LCDSPEED  	LCDCR0,2
#define		LCDEN     	LCDCR0,5
#define		DISPS     	LCDCR0,7

;----- LCDCR1 Bits ---------------------------------------------------

#define		LCDCKS    	LCDCR1,2
#define		LCDM      	LCDCR1,3
#define		LCDBS     	LCDCR1,4

;----- LCDIOS0 Bits ---------------------------------------------------


;----- LCDIOS1 Bits ---------------------------------------------------

#define		SEGIOS9   	LCDIOS1,0
#define		SEGIOS10  	LCDIOS1,1

;----- LCDIOS2 Bits ---------------------------------------------------

#define		SEGIOS1   	LCDIOS2,0
#define		SEGIOS2   	LCDIOS2,1
#define		SEGIOS3   	LCDIOS2,2
#define		SEGIOS4   	LCDIOS2,3
#define		SEGIOS6   	LCDIOS2,5
#define		SEGIOS7   	LCDIOS2,6
#define		SEGIOS8   	LCDIOS2,7

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'1FF'
	__BADRAM H'10B'-H'17F'
	__BADRAM H'18D'-H'18F'
	__BADRAM H'193'
	__BADRAM H'197'
	__BADRAM H'19B'-H'19F'
	__BADRAM H'1AF'
	__BADRAM H'1B3'
	__BADRAM H'1B6'-H'1B7'
	__BADRAM H'1BA'-H'1BB'
	__BADRAM H'1BF'
	__BADRAM H'1C7'
	__BADRAM H'1C8'-H'1FF'


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
