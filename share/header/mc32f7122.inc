		LIST
;mc32f7122.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __32P7122
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
LCDCR     		EQU		H'018F'
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
T0EFR     		EQU		H'01A4'
T1CR      		EQU		H'01A5'
T1CNT     		EQU		H'01A6'
T1LOAD    		EQU		H'01A7'
T2CR      		EQU		H'01A8'
T2CNT     		EQU		H'01A9'
T2LOAD    		EQU		H'01AA'
T2EFR     		EQU		H'01AC'
T3CR      		EQU		H'01AD'
T3CNT     		EQU		H'01AE'
T3LOAD    		EQU		H'01AF'
IICCR     		EQU		H'01B0'
IICAR     		EQU		H'01B1'
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
PPGCR     		EQU		H'01C0'
PPGLOAD   		EQU		H'01C1'
PPGTDL    		EQU		H'01C2'
PPGTDB    		EQU		H'01C3'
OPACR     		EQU		H'01C4'
OPACLR    		EQU		H'01C5'
CPCR      		EQU		H'01C8'
CPSR      		EQU		H'01C9'
CPVR0     		EQU		H'01CA'
CPVR1     		EQU		H'01CB'
CP0CLR    		EQU		H'01CC'
CP1CLR    		EQU		H'01CD'
CP2CLR    		EQU		H'01CE'
CP3CLR    		EQU		H'01CF'

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
#define		LVDIE     	INTE,4
#define		IICIE     	INTE,5
#define		ADIE      	INTE,6
#define		PPGTIE    	INTE,7

;----- INTF Bits ---------------------------------------------------

#define		T0IF      	INTF,0
#define		T1IF      	INTF,1
#define		INT0IF    	INTF,2
#define		INT1IF    	INTF,3
#define		LVDIF     	INTF,4
#define		IICIF     	INTF,5
#define		ADIF      	INTF,6
#define		PPGTIF    	INTF,7

;----- OSCM Bits ---------------------------------------------------

#define		HFEN      	OSCM,0
#define		LFEN      	OSCM,1
#define		CLKS      	OSCM,2
#define		STBH      	OSCM,4
#define		STBL      	OSCM,5

;----- INTE1 Bits ---------------------------------------------------

#define		T2IE      	INTE1,0
#define		T3IE      	INTE1,1
#define		CP1IE     	INTE1,5
#define		CP2IE     	INTE1,6
#define		CP3IE     	INTE1,7

;----- INTF1 Bits ---------------------------------------------------

#define		T2IF      	INTF1,0
#define		T3IF      	INTF1,1
#define		CP1IF     	INTF1,5
#define		CP2IF     	INTF1,6
#define		CP3IF     	INTF1,7

;----- LCDCR Bits ---------------------------------------------------

#define		LVDF      	LCDCR,0
#define		VLVDS     	LCDCR,4
#define		LVDEN     	LCDCR,7

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

;----- OEP2 Bits ---------------------------------------------------

#define		P20OE     	OEP2,0
#define		P21OE     	OEP2,1

;----- PUP2 Bits ---------------------------------------------------

#define		P20PU     	PUP2,0
#define		P21PU     	PUP2,1

;----- PDP2 Bits ---------------------------------------------------

#define		P20PD     	PDP2,0
#define		P21PD     	PDP2,1

;----- T0CR Bits ---------------------------------------------------

#define		T0PRS0    	T0CR,0
#define		T0PRS1    	T0CR,1
#define		T0PRS2    	T0CR,2
#define		T0CKS0    	T0CR,3
#define		T0CKS1    	T0CR,4
#define		BUZ0OE    	T0CR,5
#define		PWM0OE    	T0CR,6
#define		T0EN      	T0CR,7

;----- T0EFR Bits ---------------------------------------------------

#define		PWMOD0    	T0EFR,0
#define		PWMOD1    	T0EFR,1
#define		PWMOD2    	T0EFR,2

;----- T1CR Bits ---------------------------------------------------

#define		T1PRS0    	T1CR,0
#define		T1PRS1    	T1CR,1
#define		T1PRS2    	T1CR,2
#define		T1CKS0    	T1CR,3
#define		T1CKS1    	T1CR,4
#define		T1EN      	T1CR,7

;----- T1CNT Bits ---------------------------------------------------

#define		T1CNT0    	T1CNT,0
#define		T1CNT1    	T1CNT,1
#define		T1CNT2    	T1CNT,2
#define		T1CNT3    	T1CNT,3
#define		T1CNT4    	T1CNT,4
#define		T1CNT5    	T1CNT,5
#define		T1CNT6    	T1CNT,6
#define		T1CNT7    	T1CNT,7

;----- T1LOAD Bits ---------------------------------------------------

#define		T1LOAD0   	T1LOAD,0
#define		T1LOAD1   	T1LOAD,1
#define		T1LOAD2   	T1LOAD,2
#define		T1LOAD3   	T1LOAD,3
#define		T1LOAD4   	T1LOAD,4
#define		T1LOAD5   	T1LOAD,5
#define		T1LOAD6   	T1LOAD,6
#define		T1LOAD7   	T1LOAD,7

;----- T2CR Bits ---------------------------------------------------

#define		T2PRS0    	T2CR,0
#define		T2PRS1    	T2CR,1
#define		T2PRS2    	T2CR,2
#define		T2CKS0    	T2CR,3
#define		T2CKS1    	T2CR,4
#define		T2MOD     	T2CR,6
#define		T2EN      	T2CR,7

;----- T2CNT Bits ---------------------------------------------------

#define		T2CNT0    	T2CNT,0
#define		T2CNT1    	T2CNT,1
#define		T2CNT2    	T2CNT,2
#define		T2CNT3    	T2CNT,3
#define		T2CNT4    	T2CNT,4
#define		T2CNT5    	T2CNT,5
#define		T2CNT6    	T2CNT,6
#define		T2CNT7    	T2CNT,7

;----- T2LOAD Bits ---------------------------------------------------

#define		T2LOAD0   	T2LOAD,0
#define		T2LOAD1   	T2LOAD,1
#define		T2LOAD2   	T2LOAD,2
#define		T2LOAD3   	T2LOAD,3
#define		T2LOAD4   	T2LOAD,4
#define		T2LOAD5   	T2LOAD,5
#define		T2LOAD6   	T2LOAD,6
#define		T2LOAD7   	T2LOAD,7

;----- T2EFR Bits ---------------------------------------------------

#define		T2PLS     	T2EFR,0
#define		T2PIS     	T2EFR,1

;----- T3CR Bits ---------------------------------------------------

#define		T3PRS0    	T3CR,0
#define		T3PRS1    	T3CR,1
#define		T3PRS2    	T3CR,2
#define		T3CKS0    	T3CR,3
#define		T3CKS1    	T3CR,4
#define		T3MOD     	T3CR,6
#define		T3EN      	T3CR,7

;----- T3CNT Bits ---------------------------------------------------

#define		T3CNT0    	T3CNT,0
#define		T3CNT1    	T3CNT,1
#define		T3CNT2    	T3CNT,2
#define		T3CNT3    	T3CNT,3
#define		T3CNT4    	T3CNT,4
#define		T3CNT5    	T3CNT,5
#define		T3CNT6    	T3CNT,6
#define		T3CNT7    	T3CNT,7

;----- T3LOAD Bits ---------------------------------------------------

#define		T3LOAD0   	T3LOAD,0
#define		T3LOAD1   	T3LOAD,1
#define		T3LOAD2   	T3LOAD,2
#define		T3LOAD3   	T3LOAD,3
#define		T3LOAD4   	T3LOAD,4
#define		T3LOAD5   	T3LOAD,5
#define		T3LOAD6   	T3LOAD,6
#define		T3LOAD7   	T3LOAD,7

;----- IICCR Bits ---------------------------------------------------

#define		RACK      	IICCR,0
#define		IICEN     	IICCR,1
#define		MSTCMD    	IICCR,2
#define		SACK      	IICCR,3
#define		IICMOD    	IICCR,4
#define		IICBUSY   	IICCR,5
#define		IICAAS    	IICCR,6
#define		IICEOF    	IICCR,7

;----- IICAR Bits ---------------------------------------------------

#define		IICAD0    	IICAR,1
#define		IICAD1    	IICAR,2
#define		IICAD2    	IICAR,3
#define		IICAD3    	IICAR,4
#define		IICAD4    	IICAR,5
#define		IICAD5    	IICAR,6
#define		IICAD6    	IICAR,7

;----- EECR Bits ---------------------------------------------------

#define		EERW      	EECR,6
#define		EETRIG    	EECR,7

;----- ADCR0 Bits ---------------------------------------------------

#define		ADEN      	ADCR0,0
#define		ADEOC     	ADCR0,1
#define		ADVRS     	ADCR0,2
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

#define		P00ADS    	ADIOS0,0
#define		P01ADS    	ADIOS0,1
#define		P02ADS    	ADIOS0,2
#define		P03ADS    	ADIOS0,3
#define		P04ADS    	ADIOS0,4
#define		P05ADS    	ADIOS0,5
#define		P06ADS    	ADIOS0,6
#define		P07ADS    	ADIOS0,7

;----- ADIOS1 Bits ---------------------------------------------------

#define		P10ADS    	ADIOS1,0
#define		P11ADS    	ADIOS1,1
#define		P12ADS    	ADIOS1,2
#define		P13ADS    	ADIOS1,3
#define		P14ADS    	ADIOS1,4
#define		P15ADS    	ADIOS1,5
#define		P16ADS    	ADIOS1,6
#define		P17ADS    	ADIOS1,7

;----- OSADJCR Bits ---------------------------------------------------

#define		OSADJTR0  	OSADJCR,0
#define		OSADJTR1  	OSADJCR,1
#define		OSADJTR2  	OSADJCR,2
#define		OSADJTR3  	OSADJCR,3
#define		OSADJTR4  	OSADJCR,4
#define		OSADJTR5  	OSADJCR,5
#define		OSADJEN   	OSADJCR,7

;----- PPGCR Bits ---------------------------------------------------

#define		PPGPRS0   	PPGCR,0
#define		PPGPRS1   	PPGCR,1
#define		PPGSTR    	PPGCR,2
#define		TRIGSYN   	PPGCR,3
#define		PSTPEN    	PPGCR,4
#define		PSTREN    	PPGCR,5
#define		POLEV     	PPGCR,6
#define		PPGEN     	PPGCR,7

;----- PPGLOAD Bits ---------------------------------------------------

#define		PGLOAD0   	PPGLOAD,0
#define		PGLOAD1   	PPGLOAD,1
#define		PGLOAD2   	PPGLOAD,2
#define		PGLOAD3   	PPGLOAD,3
#define		PGLOAD4   	PPGLOAD,4
#define		PGLOAD5   	PPGLOAD,5
#define		PGLOAD6   	PPGLOAD,6
#define		PGLOAD7   	PPGLOAD,7

;----- PPGTDL Bits ---------------------------------------------------

#define		PPGTDL0   	PPGTDL,0
#define		PPGTDL1   	PPGTDL,1
#define		PPGTDL2   	PPGTDL,2
#define		PPGTDL3   	PPGTDL,3
#define		PPGTDL4   	PPGTDL,4
#define		PPGTDL5   	PPGTDL,5
#define		PGLOAD8   	PPGTDL,6
#define		PGLOAD9   	PPGTDL,7

;----- PPGTDB Bits ---------------------------------------------------

#define		PPGTDB0   	PPGTDB,0
#define		PPGTDB1   	PPGTDB,1
#define		PPGTDB2   	PPGTDB,2
#define		PPGTDB3   	PPGTDB,3
#define		PPGTDB4   	PPGTDB,4
#define		PPGTDB5   	PPGTDB,5
#define		PPGTEG    	PPGTDB,6
#define		PPGTIS    	PPGTDB,7

;----- OPACR Bits ---------------------------------------------------

#define		OPAPS0    	OPACR,0
#define		OPAPS1    	OPACR,1
#define		OPAOS0    	OPACR,2
#define		OPAOS1    	OPACR,3
#define		OPAOP     	OPACR,6
#define		OPAEN     	OPACR,7

;----- OPACLR Bits ---------------------------------------------------

#define		OPADLR0   	OPACLR,0
#define		OPADLR1   	OPACLR,1
#define		OPADLR2   	OPACLR,2
#define		OPADLR3   	OPACLR,3
#define		OPADLR4   	OPACLR,4
#define		OPADLR5   	OPACLR,5
#define		OPACLRS   	OPACLR,6
#define		OPAMOD    	OPACLR,7

;----- CPCR Bits ---------------------------------------------------

#define		CP0EN     	CPCR,0
#define		CP1EN     	CPCR,1
#define		CP2EN     	CPCR,2
#define		CP3EN     	CPCR,3
#define		CP1NS     	CPCR,4
#define		CP3NS0    	CPCR,5
#define		CP3NS1    	CPCR,6

;----- CPSR Bits ---------------------------------------------------

#define		CP0OP     	CPSR,0
#define		CP1OP     	CPSR,1
#define		CP2OP     	CPSR,2
#define		CP3OP     	CPSR,3

;----- CPVR0 Bits ---------------------------------------------------

#define		CP1VS0    	CPVR0,0
#define		CP1VS1    	CPVR0,1
#define		CP1VS2    	CPVR0,2
#define		CP1VS3    	CPVR0,3
#define		CP2VS0    	CPVR0,4
#define		VP2VS1    	CPVR0,5
#define		CP2VS2    	CPVR0,6
#define		CP2VS3    	CPVR0,7

;----- CPVR1 Bits ---------------------------------------------------

#define		CP3VS0    	CPVR1,0
#define		CP3VS1    	CPVR1,1
#define		CP3VS2    	CPVR1,2
#define		CP3VS3    	CPVR1,3
#define		CP3VS4    	CPVR1,4

;----- CP0CLR Bits ---------------------------------------------------

#define		CP0CLR0   	CP0CLR,0
#define		CP0CLR1   	CP0CLR,1
#define		CP0CLR2   	CP0CLR,2
#define		CP0CLR3   	CP0CLR,3
#define		CP0CLR4   	CP0CLR,4
#define		CP0CLR5   	CP0CLR,5
#define		CP0CLRS   	CP0CLR,6
#define		CP0MOD    	CP0CLR,7

;----- CP1CLR Bits ---------------------------------------------------

#define		CP1CLR0   	CP1CLR,0
#define		CP1CLR1   	CP1CLR,1
#define		CP1CLR2   	CP1CLR,2
#define		CP1CLR3   	CP1CLR,3
#define		CP1CLR4   	CP1CLR,4
#define		CP1CLR5   	CP1CLR,5
#define		CP1CLRS   	CP1CLR,6
#define		CP1MOD    	CP1CLR,7

;----- CP2CLR Bits ---------------------------------------------------

#define		CP2CLR0   	CP2CLR,0
#define		CP2CLR1   	CP2CLR,1
#define		CP2CLR2   	CP2CLR,2
#define		CP2CLR3   	CP2CLR,3
#define		CP2CLR4   	CP2CLR,4
#define		CP2CLR5   	CP2CLR,5
#define		CP2CLRS   	CP2CLR,6
#define		CP2MOD    	CP2CLR,7

;----- CP3CLR Bits ---------------------------------------------------

#define		CP3CLR0   	CP3CLR,0
#define		CP3CLR1   	CP3CLR,1
#define		CP3CLR2   	CP3CLR,2
#define		CP3CLR3   	CP3CLR,3
#define		CP3CLR4   	CP3CLR,4
#define		CP3CLR5   	CP3CLR,5
#define		CP3CLRS   	CP3CLR,6
#define		CP3MOD    	CP3CLR,7

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'1FF'
	__BADRAM H'100'-H'17F'
	__BADRAM H'19C'-H'19F'
	__BADRAM H'1AB'
	__BADRAM H'1B3'
	__BADRAM H'1BF'
	__BADRAM H'1C6'-H'1C7'
	__BADRAM H'1D0'-H'1FF'


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
