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

;----- INDF0 Bits ---------------------------------------------------

#define		INDF00    	INDF0,0
#define		INDF01    	INDF0,1
#define		INDF02    	INDF0,2
#define		INDF03    	INDF0,3
#define		INDF04    	INDF0,4
#define		INDF05    	INDF0,5
#define		INDF06    	INDF0,6
#define		INDF07    	INDF0,7

;----- INDF1 Bits ---------------------------------------------------

#define		INDF10    	INDF1,0
#define		INDF11    	INDF1,1
#define		INDF12    	INDF1,2
#define		INDF13    	INDF1,3
#define		INDF14    	INDF1,4
#define		INDF15    	INDF1,5
#define		INDF16    	INDF1,6
#define		INDF17    	INDF1,7

;----- INDF2 Bits ---------------------------------------------------

#define		INDF20    	INDF2,0
#define		INDF21    	INDF2,1
#define		INDF22    	INDF2,2
#define		INDF23    	INDF2,3
#define		INDF24    	INDF2,4
#define		INDF25    	INDF2,5
#define		INDF26    	INDF2,6
#define		INDF27    	INDF2,7

;----- HIBYTE Bits ---------------------------------------------------

#define		HIBYTE0   	HIBYTE,0
#define		HIBYTE1   	HIBYTE,1
#define		HIBYTE2   	HIBYTE,2
#define		HIBYTE3   	HIBYTE,3
#define		HIBYTE4   	HIBYTE,4
#define		HIBYTE5   	HIBYTE,5
#define		HIBYTE6   	HIBYTE,6
#define		HIBYTE7   	HIBYTE,7

;----- FSR0 Bits ---------------------------------------------------

#define		SFR00     	FSR0,0
#define		SFR01     	FSR0,1
#define		SFR02     	FSR0,2
#define		SFR03     	FSR0,3
#define		SFR04     	FSR0,4
#define		SFR05     	FSR0,5
#define		SFR06     	FSR0,6
#define		SFR07     	FSR0,7

;----- FSR1 Bits ---------------------------------------------------

#define		SFR10     	FSR1,0
#define		SFR11     	FSR1,1
#define		SFR12     	FSR1,2
#define		SFR13     	FSR1,3
#define		SFR14     	FSR1,4
#define		SFR15     	FSR1,5
#define		SFR16     	FSR1,6
#define		SFR17     	FSR1,7

;----- PCL Bits ---------------------------------------------------

#define		PC0       	PCL,0
#define		PC1       	PCL,1
#define		PC2       	PCL,2
#define		PC3       	PCL,3
#define		PC4       	PCL,4
#define		PC5       	PCL,5
#define		PC6       	PCL,6
#define		PC7       	PCL,7

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

;----- INDF3 Bits ---------------------------------------------------

#define		INDF30    	INDF3,0
#define		INDF31    	INDF3,1
#define		INDF32    	INDF3,2
#define		INDF33    	INDF3,3
#define		INDF34    	INDF3,4
#define		INDF35    	INDF3,5
#define		INDF36    	INDF3,6
#define		INDF37    	INDF3,7

;----- INTE Bits ---------------------------------------------------

#define		T0IE      	INTE,0
#define		T1IE      	INTE,1
#define		INT0IE    	INTE,2
#define		INT1IE    	INTE,3
#define		IICIE     	INTE,5
#define		ADIE      	INTE,6

;----- INTF Bits ---------------------------------------------------

#define		T0IF      	INTF,0
#define		T1IF      	INTF,1
#define		INT0IF    	INTF,2
#define		INT1IF    	INTF,3
#define		IICIF     	INTF,5
#define		ADIF      	INTF,6

;----- OSCM Bits ---------------------------------------------------

#define		HFEN      	OSCM,0
#define		LFEN      	OSCM,1
#define		CLKS      	OSCM,2
#define		STBH      	OSCM,4
#define		STBL      	OSCM,5

;----- LVDCR Bits ---------------------------------------------------

#define		LVDF      	LVDCR,0
#define		VLVDS0    	LVDCR,3
#define		VLVDS1    	LVDCR,4
#define		VLVDS2    	LVDCR,5
#define		VLVDS3    	LVDCR,6
#define		LVDEN     	LVDCR,7

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

;----- RUPSEL Bits ---------------------------------------------------

#define		IICRS     	RUPSEL,7

;----- IOP1 Bits ---------------------------------------------------

#define		P10D      	IOP1,0
#define		P11D      	IOP1,1

;----- OEP1 Bits ---------------------------------------------------

#define		P10OE     	OEP1,0
#define		P11OE     	OEP1,1

;----- PUP1 Bits ---------------------------------------------------

#define		P10PU     	PUP1,0
#define		P11PU     	PUP1,1

;----- T0CR Bits ---------------------------------------------------

#define		T0PRS0    	T0CR,0
#define		T0PRS1    	T0CR,1
#define		T0PRS2    	T0CR,2
#define		T0CKS0    	T0CR,3
#define		T0CKS1    	T0CR,4
#define		BUZ0OE    	T0CR,5
#define		PWM0OE    	T0CR,6
#define		T0EN      	T0CR,7

;----- T0CNT Bits ---------------------------------------------------

#define		T0CNT0    	T0CNT,0
#define		T0CNT1    	T0CNT,1
#define		T0CNT2    	T0CNT,2
#define		T0CNT3    	T0CNT,3
#define		T0CNT4    	T0CNT,4
#define		T0CNT5    	T0CNT,5
#define		T0CNT6    	T0CNT,6
#define		T0CNT7    	T0CNT,7

;----- T0LOAD Bits ---------------------------------------------------

#define		T0LOAD0   	T0LOAD,0
#define		T0LOAD1   	T0LOAD,1
#define		T0LOAD2   	T0LOAD,2
#define		T0LOAD3   	T0LOAD,3
#define		T0LOAD4   	T0LOAD,4
#define		T0LOAD5   	T0LOAD,5
#define		T0LOAD6   	T0LOAD,6
#define		T0LOAD7   	T0LOAD,7

;----- T0DATA Bits ---------------------------------------------------

#define		T0DATA0   	T0DATA,0
#define		T0DATA1   	T0DATA,1
#define		T0DATA2   	T0DATA,2
#define		T0DATA3   	T0DATA,3
#define		T0DATA4   	T0DATA,4
#define		T0DATA5   	T0DATA,5
#define		T0DATA6   	T0DATA,6
#define		T0DATA7   	T0DATA,7

;----- T1CR Bits ---------------------------------------------------

#define		T1PRS0    	T1CR,0
#define		T1PRS1    	T1CR,1
#define		T1PRS2    	T1CR,2
#define		T1CKS0    	T1CR,3
#define		T1CKS1    	T1CR,4
#define		BUZ1OE    	T1CR,5
#define		PWM1OE    	T1CR,6
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

;----- T1DATA Bits ---------------------------------------------------

#define		T1DATA0   	T1DATA,0
#define		T1DATA1   	T1DATA,1
#define		T1DATA2   	T1DATA,2
#define		T1DATA3   	T1DATA,3
#define		T1DATA4   	T1DATA,4
#define		T1DATA5   	T1DATA,5
#define		T1DATA6   	T1DATA,6
#define		T1DATA7   	T1DATA,7

;----- ADCR0 Bits ---------------------------------------------------

#define		ADCHS0    	ADCR0,0
#define		ADCHS1    	ADCR0,1
#define		ADCHS2    	ADCR0,2
#define		ADCHS3    	ADCR0,3
#define		ADCKS0    	ADCR0,4
#define		ADCKS1    	ADCR0,5
#define		CHOPEN    	ADCR0,6
#define		ADEN      	ADCR0,7

;----- ADCR1 Bits ---------------------------------------------------

#define		ADGAS0    	ADCR1,0
#define		ADGAS1    	ADCR1,1
#define		ADGAS2    	ADCR1,2
#define		ADGAS3    	ADCR1,3
#define		ADSPS0    	ADCR1,4
#define		ADSPS1    	ADCR1,5
#define		ADSPS2    	ADCR1,6
#define		ADSPS3    	ADCR1,7

;----- ADCR2 Bits ---------------------------------------------------

#define		ADVRS     	ADCR2,0
#define		LDOEN     	ADCR2,1
#define		VLDOS1    	ADCR2,2
#define		VLDOS0    	ADCR2,3
#define		AD2EN     	ADCR2,4
#define		AD1EN     	ADCR2,5
#define		AD0EN     	ADCR2,6

;----- ADRH Bits ---------------------------------------------------

#define		ADR16     	ADRH,0
#define		ADR17     	ADRH,1
#define		ADR18     	ADRH,2
#define		ADR19     	ADRH,3
#define		ADR20     	ADRH,4
#define		ADR21     	ADRH,5
#define		ADR22     	ADRH,6
#define		ADR23     	ADRH,7

;----- ADRM Bits ---------------------------------------------------

#define		ADR8      	ADRM,0
#define		ADR9      	ADRM,1
#define		ADR10     	ADRM,2
#define		ADR11     	ADRM,3
#define		ADR12     	ADRM,4
#define		ADR13     	ADRM,5
#define		ADR14     	ADRM,6
#define		ADR15     	ADRM,7

;----- IICCR Bits ---------------------------------------------------

#define		RACK      	IICCR,0
#define		IICEN     	IICCR,1
#define		MSTCMD    	IICCR,2
#define		SACK      	IICCR,3
#define		IICM0D    	IICCR,4
#define		IICBUSY   	IICCR,5
#define		IICAAS    	IICCR,6
#define		IICE0F    	IICCR,7

;----- IICAR Bits ---------------------------------------------------

#define		IICAD0    	IICAR,1
#define		IICAD1    	IICAR,2
#define		IICAD2    	IICAR,3
#define		IICAD3    	IICAR,4
#define		IICAD4    	IICAR,5
#define		IICAD5    	IICAR,6
#define		IICAD6    	IICAR,7

;----- IICDR Bits ---------------------------------------------------

#define		IICDT0    	IICDR,0
#define		IICDT1    	IICDR,1
#define		IICDT2    	IICDR,2
#define		IICDT3    	IICDR,3
#define		IICDT4    	IICDR,4
#define		IICDT6    	IICDR,6
#define		IICDT7    	IICDR,7

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
