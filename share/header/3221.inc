		LIST
;mc32p7010.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

;	IFNDEF __32P7010
;		MESSG "Processor-header file mismatch.  Verify selected processor."
;	ENDIF

;==========================================================================
;
;	Register Definitions
;
;==========================================================================

;----- Register Files ---------------------------------------------------

INDF0     		EQU		H'0180'
INDF1     		EQU		H'0181'
INDF2     		EQU		H'0182'
HIBYTE    		EQU		H'0183'
FSR0      		EQU		H'0184'
FSR1      		EQU		H'0185'
PCL       		EQU		H'0186'
PFLAG     		EQU		H'0187'
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
KBCR      		EQU		H'0197'
T0CR      		EQU		H'01A0'
T0CNT     		EQU		H'01A1'
T0LOAD    		EQU		H'01A2'
T0DATA    		EQU		H'01A3'
T1CR      		EQU		H'01A4'
T1CNT     		EQU		H'01A5'
T1LOAD    		EQU		H'01A6'
T1DATA    		EQU		H'01A7'
OSCM      		EQU		H'01AE'
LVDCR     		EQU		H'01AF'
ADCR0     		EQU		H'01B0'
ADCR1     		EQU		H'01B1'
ADRH      		EQU		H'01B4'
ADRL      		EQU		H'01B5'
OSCCAL    		EQU		H'01FB'

;----- INDF0 Bits ---------------------------------------------------

INDF00    		EQU		H'0000'
INDF01    		EQU		H'0001'
INDF02    		EQU		H'0002'
INDF03    		EQU		H'0003'
INDF04    		EQU		H'0004'
INDF05    		EQU		H'0005'
INDF06    		EQU		H'0006'
INDF07    		EQU		H'0007'

;----- INDF1 Bits ---------------------------------------------------

INDF10    		EQU		H'0000'
INDF11    		EQU		H'0001'
INDF12    		EQU		H'0002'
INDF13    		EQU		H'0003'
INDF14    		EQU		H'0004'
INDF15    		EQU		H'0005'
INDF16    		EQU		H'0006'
INDF17    		EQU		H'0007'

;----- INDF2 Bits ---------------------------------------------------

INDF20    		EQU		H'0000'
INDF21    		EQU		H'0001'
INDF22    		EQU		H'0002'
INDF23    		EQU		H'0003'
INDF24    		EQU		H'0004'
INDF25    		EQU		H'0005'
INDF26    		EQU		H'0006'
INDF27    		EQU		H'0007'

;----- HIBYTE Bits ---------------------------------------------------

HIBYTE0   		EQU		H'0000'
HIBYTE1   		EQU		H'0001'
HIBYTE2   		EQU		H'0002'
HIBYTE3   		EQU		H'0003'
HIBYTE4   		EQU		H'0004'
HIBYTE5   		EQU		H'0005'
HIBYTE6   		EQU		H'0006'
HIBYTE7   		EQU		H'0007'

;----- FSR0 Bits ---------------------------------------------------

FSR00     		EQU		H'0000'
FSR01     		EQU		H'0001'
FSR02     		EQU		H'0002'
FSR03     		EQU		H'0003'
FSR04     		EQU		H'0004'
FSR05     		EQU		H'0005'
FSR06     		EQU		H'0006'
FSR07     		EQU		H'0007'

;----- FSR1 Bits ---------------------------------------------------

FSR10     		EQU		H'0000'
FSR11     		EQU		H'0001'
FSR12     		EQU		H'0002'
FSR13     		EQU		H'0003'
FSR14     		EQU		H'0004'
FSR15     		EQU		H'0005'
FSR16     		EQU		H'0006'
FSR17     		EQU		H'0007'

;----- PCL Bits ---------------------------------------------------

PC0       		EQU		H'0000'
PC1       		EQU		H'0001'
PC2       		EQU		H'0002'
PC3       		EQU		H'0003'
PC4       		EQU		H'0004'
PC5       		EQU		H'0005'
PC6       		EQU		H'0006'
PC7       		EQU		H'0007'

;----- PFLAG Bits ---------------------------------------------------

C         		EQU		H'0000'
DC        		EQU		H'0001'
Z         		EQU		H'0002'

;----- MCR Bits ---------------------------------------------------

MINT00    		EQU		H'0000'
MINT01    		EQU		H'0001'
MINT10    		EQU		H'0002'
MINT11    		EQU		H'0003'
PD        		EQU		H'0004'
TO        		EQU		H'0005'
GIE       		EQU		H'0007'

;----- INDF3 Bits ---------------------------------------------------

INDF30    		EQU		H'0000'
INDF31    		EQU		H'0001'
INDF32    		EQU		H'0002'
INDF33    		EQU		H'0003'
INDF34    		EQU		H'0004'
INDF35    		EQU		H'0005'
INDF36    		EQU		H'0006'
INDF37    		EQU		H'0007'

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

P00D      		EQU		H'0000'
P01D      		EQU		H'0001'
P02D      		EQU		H'0002'
P03D      		EQU		H'0003'
P04D      		EQU		H'0004'

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

P10D      		EQU		H'0000'
P11D      		EQU		H'0001'
P12D      		EQU		H'0002'
P13D      		EQU		H'0003'
P14D      		EQU		H'0004'
P15D      		EQU		H'0005'
P16D      		EQU		H'0006'

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

;----- KBCR Bits ---------------------------------------------------

KBCR0     		EQU		H'0000'
KBCR1     		EQU		H'0001'
KBCR2     		EQU		H'0002'
KBCR3     		EQU		H'0003'
KBCR4     		EQU		H'0004'
KBCR5     		EQU		H'0005'
KBCR6     		EQU		H'0006'

;----- T0CR Bits ---------------------------------------------------

T0PR0     		EQU		H'0000'
T0PR1     		EQU		H'0001'
T0PR2     		EQU		H'0002'
T0PTS0    		EQU		H'0003'
T0PTS1    		EQU		H'0004'
BUZ0OE    		EQU		H'0005'
PWM0OE    		EQU		H'0006'
TC0EN     		EQU		H'0007'

;----- T0CNT Bits ---------------------------------------------------

T0C0      		EQU		H'0000'
T0C1      		EQU		H'0001'
T0C2      		EQU		H'0002'
T0C3      		EQU		H'0003'
T0C4      		EQU		H'0004'
T0C5      		EQU		H'0005'
T0C6      		EQU		H'0006'
T0C7      		EQU		H'0007'

;----- T0LOAD Bits ---------------------------------------------------

T0LOAD0   		EQU		H'0000'
T0LOAD1   		EQU		H'0001'
T0LOAD2   		EQU		H'0002'
T0LOAD3   		EQU		H'0003'
T0LOAD4   		EQU		H'0004'
T0LOAD5   		EQU		H'0005'
T0LOAD6   		EQU		H'0006'
T0LOAD7   		EQU		H'0007'

;----- T0DATA Bits ---------------------------------------------------

T0DATA0   		EQU		H'0000'
T0DATA1   		EQU		H'0001'
T0DATA2   		EQU		H'0002'
T0DATA3   		EQU		H'0003'
T0DATA4   		EQU		H'0004'
T0DATA5   		EQU		H'0005'
T0DATA6   		EQU		H'0006'
T0DATA7   		EQU		H'0007'

;----- T1CR Bits ---------------------------------------------------

T1PR0     		EQU		H'0000'
T1PR1     		EQU		H'0001'
T1PR2     		EQU		H'0002'
T1PTS0    		EQU		H'0003'
T1PTS1    		EQU		H'0004'
BUZ1OE    		EQU		H'0005'
PWM1OE    		EQU		H'0006'
TC1EN     		EQU		H'0007'

;----- T1CNT Bits ---------------------------------------------------

T1C0      		EQU		H'0000'
T1C1      		EQU		H'0001'
T1C2      		EQU		H'0002'
T1C3      		EQU		H'0003'
T1C4      		EQU		H'0004'
T1C5      		EQU		H'0005'
T1C6      		EQU		H'0006'
T1C7      		EQU		H'0007'

;----- T1LOAD Bits ---------------------------------------------------

T1LOAD0   		EQU		H'0000'
T1LOAD1   		EQU		H'0001'
T1LOAD2   		EQU		H'0002'
T1LOAD3   		EQU		H'0003'
T1LOAD4   		EQU		H'0004'
T1LOAD5   		EQU		H'0005'
T1LOAD6   		EQU		H'0006'
T1LOAD7   		EQU		H'0007'

;----- T1DATA Bits ---------------------------------------------------

T1DATA0   		EQU		H'0000'
T1DATA1   		EQU		H'0001'
T1DATA2   		EQU		H'0002'
T1DATA3   		EQU		H'0003'
T1DATA4   		EQU		H'0004'
T1DATA5   		EQU		H'0005'
T1DATA6   		EQU		H'0006'
T1DATA7   		EQU		H'0007'

;----- OSCM Bits ---------------------------------------------------

HFEN      		EQU		H'0000'
LFEN      		EQU		H'0001'
CLKS      		EQU		H'0002'
STBH      		EQU		H'0004'
STBL      		EQU		H'0005'

;----- LVDCR Bits ---------------------------------------------------

LVDF      		EQU		H'0000'
LVDS0     		EQU		H'0004'
LVDS1     		EQU		H'0005'
LVDS2     		EQU		H'0006'
LVDEN     		EQU		H'0007'

;----- ADCR0 Bits ---------------------------------------------------

ADON      		EQU		H'0000'
ADEOC     		EQU		H'0001'
ADCKS0    		EQU		H'0002'
ADCKS1    		EQU		H'0003'
ADCHS0    		EQU		H'0004'
ADCHS1    		EQU		H'0005'
ADCHS2    		EQU		H'0006'
ADCHS3    		EQU		H'0007'

;----- ADCR1 Bits ---------------------------------------------------

VRS0      		EQU		H'0000'
VRS1      		EQU		H'0001'
VRS2      		EQU		H'0002'

;----- ADRH Bits ---------------------------------------------------

ADR4      		EQU		H'0000'
ADR5      		EQU		H'0001'
ADR6      		EQU		H'0002'
ADR7      		EQU		H'0003'
ADR8      		EQU		H'0004'
ADR9      		EQU		H'0005'
ADR10     		EQU		H'0006'
ADR11     		EQU		H'0007'

;----- ADRL Bits ---------------------------------------------------

ADR0      		EQU		H'0000'
ADR1      		EQU		H'0001'
ADR2      		EQU		H'0002'
ADR3      		EQU		H'0003'

;----- OSCCAL Bits ---------------------------------------------------

OSCCAL0   		EQU		H'0000'
OSCCAL1   		EQU		H'0001'
OSCCAL2   		EQU		H'0002'
OSCCAL3   		EQU		H'0003'
OSCCAL4   		EQU		H'0004'
OSCCAL5   		EQU		H'0005'
OSCCAL6   		EQU		H'0006'
OSCCAL7   		EQU		H'0007'

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

		LIST
