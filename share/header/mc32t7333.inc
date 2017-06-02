		LIST
;mc32t7333.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __32P7333
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
INTE1     		EQU		H'018D'
INTF1     		EQU		H'018E'
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
T1CR      		EQU		H'01A8'
T1CNTH    		EQU		H'01A9'
T1CNTL    		EQU		H'01AA'
T1LOADH   		EQU		H'01AB'
T1LOADL   		EQU		H'01AC'
T1DATAH   		EQU		H'01AD'
T1DATAL   		EQU		H'01AE'
IICCR     		EQU		H'01B0'
IICSR     		EQU		H'01B1'
IICDR     		EQU		H'01B2'
EECR      		EQU		H'01B4'
EEMASK    		EQU		H'01B5'
EEAR      		EQU		H'01B6'
EEDR      		EQU		H'01B7'
ADCR0     		EQU		H'01B8'
ADCR1     		EQU		H'01B9'
ADRH      		EQU		H'01BA'
ADRL      		EQU		H'01BB'
ADIOS0    		EQU		H'01BC'
ADIOS1    		EQU		H'01BD'
OSADJCR   		EQU		H'01BE'
T2CR      		EQU		H'01C0'
T2CNTH    		EQU		H'01C1'
T2CNTL    		EQU		H'01C2'
T2LOADH   		EQU		H'01C3'
T2LOADL   		EQU		H'01C4'
T3CR      		EQU		H'01C5'
T3CNT     		EQU		H'01C6'
T3LOAD    		EQU		H'01C7'
SCON      		EQU		H'01C8'
SCON      		EQU		H'01C8'
SBUF      		EQU		H'01C9'
SADDR     		EQU		H'01CA'
SADEN     		EQU		H'01CB'

;----- PCL Bits ---------------------------------------------------


;----- PFLAG Bits ---------------------------------------------------

#define		C         	PFLAG,0
#define		DC        	PFLAG,1
#define		Z         	PFLAG,2

;----- MCR Bits ---------------------------------------------------

#define		MINT00    	MCR,0
#define		MINT01    	MCR,1
#define		MINT10    	MCR,2
#define		MINT11    	MCR,3
#define		PD        	MCR,4
#define		TO        	MCR,5
#define		GIE       	MCR,7

;----- INTE Bits ---------------------------------------------------

#define		T0IE      	INTE,0
#define		T1IE      	INTE,1
#define		INT0IE    	INTE,2
#define		INT1IE    	INTE,3
#define		KBIE      	INTE,4
#define		IICIE     	INTE,5
#define		ADIE      	INTE,6
#define		UARTIE    	INTE,7

;----- INTF Bits ---------------------------------------------------

#define		T0IF      	INTF,0
#define		T1IF      	INTF,1
#define		INT0IF    	INTF,2
#define		INT1IF    	INTF,3
#define		KBIF      	INTF,4
#define		IICIF     	INTF,5
#define		ADIF      	INTF,6
#define		UARTIF    	INTF,7

;----- OSCM Bits ---------------------------------------------------

#define		HFEN      	OSCM,0
#define		LFEN      	OSCM,1
#define		CLKS      	OSCM,2
#define		STBH      	OSCM,4
#define		STBL      	OSCM,5

;----- INTE1 Bits ---------------------------------------------------

#define		T2IE      	INTE1,0
#define		T3IE      	INTE1,1
#define		INT2IE    	INTE1,2
#define		INT3IE    	INTE1,3

;----- INTF1 Bits ---------------------------------------------------

#define		T2IF      	INTF1,0
#define		T3IF      	INTF1,1
#define		INT2IF    	INTF1,2
#define		INT3IF    	INTF1,3

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

;----- PDP0 Bits ---------------------------------------------------

#define		P00PD     	PDP0,0
#define		P01PD     	PDP0,1
#define		P02PD     	PDP0,2
#define		P03PD     	PDP0,3
#define		P04PD     	PDP0,4
#define		P05PD     	PDP0,5
#define		P06PD     	PDP0,6
#define		P07PD     	PDP0,7

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

;----- PDP1 Bits ---------------------------------------------------

#define		P10PD     	PDP1,0
#define		P11PD     	PDP1,1
#define		P12PD     	PDP1,2
#define		P13PD     	PDP1,3
#define		P14PD     	PDP1,4
#define		P15PD     	PDP1,5
#define		P16PD     	PDP1,6
#define		P17PD     	PDP1,7

;----- IOP2 Bits ---------------------------------------------------

#define		P20D      	IOP2,0
#define		P21D      	IOP2,1
#define		P22D      	IOP2,2
#define		P23D      	IOP2,3
#define		P24D      	IOP2,4
#define		P25D      	IOP2,5

;----- OEP2 Bits ---------------------------------------------------

#define		P20OE     	OEP2,0
#define		P21OE     	OEP2,1
#define		P22OE     	OEP2,2
#define		P23OE     	OEP2,3
#define		P24OE     	OEP2,4
#define		P25OE     	OEP2,5

;----- PUP2 Bits ---------------------------------------------------

#define		P20PU     	PUP2,0
#define		P21PU     	PUP2,1
#define		P22PU     	PUP2,2
#define		P23PU     	PUP2,3
#define		P24PU     	PUP2,4
#define		P25PU     	PUP2,5

;----- PDP2 Bits ---------------------------------------------------

#define		P20PD     	PDP2,0
#define		P21PD     	PDP2,1
#define		P22PD     	PDP2,2
#define		P23PD     	PDP2,3
#define		P24PD     	PDP2,4
#define		P25PD     	PDP2,5

;----- T0CR Bits ---------------------------------------------------

#define		T0PRS0    	T0CR,0
#define		T0PRS1    	T0CR,1
#define		T0PRS2    	T0CR,2
#define		T0CKS0    	T0CR,3
#define		T0CKS1    	T0CR,4
#define		BUZ0OE    	T0CR,5
#define		PWM0OE    	T0CR,6
#define		T0EN      	T0CR,7

;----- T1CR Bits ---------------------------------------------------

#define		T1PRS0    	T1CR,0
#define		T1PRS1    	T1CR,1
#define		T1PRS2    	T1CR,2
#define		T1CKS0    	T1CR,3
#define		T1CKS1    	T1CR,4
#define		PWM1OE    	T1CR,6
#define		T1EN      	T1CR,7

;----- IICCR Bits ---------------------------------------------------

#define		IICIMS    	IICCR,0
#define		IICRDTP   	IICCR,1
#define		IICTYP0   	IICCR,2
#define		IICTYP1   	IICCR,3
#define		IICCKS0   	IICCR,4
#define		IICCKS1   	IICCR,5
#define		IICRS     	IICCR,6
#define		IICEN     	IICCR,7

;----- IICSR Bits ---------------------------------------------------

#define		RACK      	IICSR,1
#define		SACK      	IICSR,2
#define		IICACK    	IICSR,3
#define		IICWR     	IICSR,4
#define		IICRD     	IICSR,5
#define		IICSTP    	IICSR,6
#define		IICSTR    	IICSR,7

;----- EECR Bits ---------------------------------------------------

#define		EERW      	EECR,6
#define		EETRIG    	EECR,7

;----- ADCR0 Bits ---------------------------------------------------

#define		ADEN      	ADCR0,0
#define		ADEOC     	ADCR0,1
#define		VRS0      	ADCR0,2
#define		VRS1      	ADCR0,3
#define		ADCHS0    	ADCR0,4
#define		ADCHS1    	ADCR0,5
#define		ADCHS2    	ADCR0,6
#define		ADCHS3    	ADCR0,7

;----- ADCR1 Bits ---------------------------------------------------

#define		ADSPS0    	ADCR1,0
#define		ADSPS1    	ADCR1,1
#define		ADCKS0    	ADCR1,4
#define		ADCKS1    	ADCR1,5
#define		ADRSEL    	ADCR1,7

;----- ADIOS0 Bits ---------------------------------------------------

#define		AN0EN     	ADIOS0,0
#define		AN1EN     	ADIOS0,1
#define		AN2EN     	ADIOS0,2
#define		AN3EN     	ADIOS0,3
#define		AN4EN     	ADIOS0,4
#define		AN5EN     	ADIOS0,5
#define		AN6EN     	ADIOS0,6
#define		AN7EN     	ADIOS0,7

;----- ADIOS1 Bits ---------------------------------------------------

#define		AN8EN     	ADIOS1,0
#define		AN9EN     	ADIOS1,1
#define		AN10EN    	ADIOS1,2
#define		AN11EN    	ADIOS1,3
#define		AN12EN    	ADIOS1,4
#define		AN13EN    	ADIOS1,5

;----- OSADJCR Bits ---------------------------------------------------

#define		OSADJTR0  	OSADJCR,0
#define		OSADJTR1  	OSADJCR,1
#define		OSADJTR2  	OSADJCR,2
#define		OSADJTR3  	OSADJCR,3
#define		OSADJTR4  	OSADJCR,4
#define		OSADJTR5  	OSADJCR,5
#define		OSADJEN   	OSADJCR,7

;----- T2CR Bits ---------------------------------------------------

#define		T2PRS0    	T2CR,0
#define		T2PRS1    	T2CR,1
#define		T2PRS2    	T2CR,2
#define		T2CKS0    	T2CR,3
#define		T2CKS1    	T2CR,4
#define		SSTAT     	T2CR,5
#define		SMOD      	T2CR,6
#define		T2EN      	T2CR,7

;----- T3CR Bits ---------------------------------------------------

#define		T3PRS0    	T3CR,0
#define		T3PRS1    	T3CR,1
#define		T3PRS2    	T3CR,2
#define		T3CKS0    	T3CR,3
#define		T3CKS1    	T3CR,4
#define		T3EN      	T3CR,7

;----- SCON Bits ---------------------------------------------------

#define		RI        	SCON,0
#define		TI        	SCON,1
#define		RB8       	SCON,2
#define		TB8       	SCON,3
#define		REN       	SCON,4
#define		SM2       	SCON,5
#define		SM1       	SCON,6
#define		SM0       	SCON,7

;----- SCON Bits ---------------------------------------------------

#define		TXCOL     	SCON,5
#define		RXOV      	SCON,6
#define		FE        	SCON,7

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
