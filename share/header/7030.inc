		LIST
;mc32p7030.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

;	IFNDEF __32P7030
;		MESSG "Processor-header file mismatch.  Verify selected processor."
;	ENDIF

;==========================================================================
;
;	Register Definitions
;
;==========================================================================

;----- Register Files ---------------------------------------------------

HIBYTE    		EQU		H'0082'
FSR0      		EQU		H'0083'
FSR1      		EQU		H'0084'
PFLAG     		EQU		H'0086'
ANSEL     		EQU		H'00AE'
VREF      		EQU		H'00AF'
ADCR      		EQU		H'00B1'
ADRH      		EQU		H'00B2'
ADRL      		EQU		H'00B3'
OEP0      		EQU		H'00B8'
PEDGE     		EQU		H'00BF'
OEP4      		EQU		H'00C4'
OEP5      		EQU		H'00C5'
INTF      		EQU		H'00C8'
INTE      		EQU		H'00C9'
OSCM      		EQU		H'00CA'
WDTR      		EQU		H'00CC'
T0D       		EQU		H'00CD'
PCL       		EQU		H'00CE'
PCH       		EQU		H'00CF'
IOP0      		EQU		H'00D0'
IOP4      		EQU		H'00D4'
IOP5      		EQU		H'00D5'
TXCR      		EQU		H'00D8'
T0CR      		EQU		H'00DA'
T0C       		EQU		H'00DB'
T1CR      		EQU		H'00DC'
T1C       		EQU		H'00DD'
T1D       		EQU		H'00DE'
STKP      		EQU		H'00DF'
PUP0      		EQU		H'00E0'
PUP4      		EQU		H'00E4'
PUP5      		EQU		H'00E5'
INDF      		EQU		H'00E7'
STK3L     		EQU		H'00F8'
STK3H     		EQU		H'00F9'
STK2L     		EQU		H'00FA'
STK2H     		EQU		H'00FB'
STK1L     		EQU		H'00FC'
STK1H     		EQU		H'00FD'
STK0L     		EQU		H'00FE'
STK0H     		EQU		H'00FF'

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

;----- PFLAG Bits ---------------------------------------------------

Z         		EQU		H'0000'
DC        		EQU		H'0001'
C         		EQU		H'0002'
LVD24     		EQU		H'0004'
LVD36     		EQU		H'0005'
NPD       		EQU		H'0006'
NT0       		EQU		H'0007'

;----- ANSEL Bits ---------------------------------------------------

P40ANS    		EQU		H'0000'
P41ANS    		EQU		H'0001'
P42ANS    		EQU		H'0002'
P43ANS    		EQU		H'0003'
P44ANS    		EQU		H'0004'

;----- VREF Bits ---------------------------------------------------

VRS0      		EQU		H'0000'
VRS1      		EQU		H'0001'
VREFS     		EQU		H'0007'

;----- ADCR Bits ---------------------------------------------------

ADCHS0    		EQU		H'0000'
ADCHS1    		EQU		H'0001'
ADCHS2    		EQU		H'0002'
GCHS      		EQU		H'0004'
ADEOC     		EQU		H'0005'
ADST      		EQU		H'0006'
ADON      		EQU		H'0007'

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
ADCKS0    		EQU		H'0004'
ADCKS1    		EQU		H'0006'

;----- OEP0 Bits ---------------------------------------------------

P00OE     		EQU		H'0000'
P01OE     		EQU		H'0001'
P02OE     		EQU		H'0002'
P03OE     		EQU		H'0003'

;----- PEDGE Bits ---------------------------------------------------

MINT00    		EQU		H'0003'
MINT01    		EQU		H'0004'

;----- OEP4 Bits ---------------------------------------------------

P40OE     		EQU		H'0000'
P41OE     		EQU		H'0001'
P42OE     		EQU		H'0002'
P43OE     		EQU		H'0003'
P44OE     		EQU		H'0004'

;----- OEP5 Bits ---------------------------------------------------

P53OE     		EQU		H'0003'
P54OE     		EQU		H'0004'

;----- INTF Bits ---------------------------------------------------

INT0IF    		EQU		H'0000'
INT1IF    		EQU		H'0001'
T0IF      		EQU		H'0005'
T1IF      		EQU		H'0006'
ADIF      		EQU		H'0007'

;----- INTE Bits ---------------------------------------------------

INT0IE    		EQU		H'0000'
INT1IE    		EQU		H'0001'
T0IE      		EQU		H'0005'
T1IE      		EQU		H'0006'
ADIE      		EQU		H'0007'

;----- OSCM Bits ---------------------------------------------------

HOFF      		EQU		H'0001'
CLKS      		EQU		H'0002'
CPUM0     		EQU		H'0003'
CPUM1     		EQU		H'0004'

;----- WDTR Bits ---------------------------------------------------

WDTR0     		EQU		H'0000'
WDTR1     		EQU		H'0001'
WDTR2     		EQU		H'0002'
WDTR3     		EQU		H'0003'
WDTR4     		EQU		H'0004'
WDTR5     		EQU		H'0005'
WDTR6     		EQU		H'0006'
WDTR7     		EQU		H'0007'

;----- T0D Bits ---------------------------------------------------

T0D0      		EQU		H'0000'
T0D1      		EQU		H'0001'
T0D2      		EQU		H'0002'
T0D3      		EQU		H'0003'
T0D4      		EQU		H'0004'
T0D5      		EQU		H'0005'
T0D6      		EQU		H'0006'
T0D7      		EQU		H'0007'

;----- PCL Bits ---------------------------------------------------

PC0       		EQU		H'0000'
PC1       		EQU		H'0001'
PC2       		EQU		H'0002'
PC3       		EQU		H'0003'
PC4       		EQU		H'0004'
PC5       		EQU		H'0005'
PC6       		EQU		H'0006'
PC7       		EQU		H'0007'

;----- PCH Bits ---------------------------------------------------

PC8       		EQU		H'0000'
PC9       		EQU		H'0001'

;----- IOP0 Bits ---------------------------------------------------

P00D      		EQU		H'0000'
P01D      		EQU		H'0001'
P02D      		EQU		H'0002'
P03D      		EQU		H'0003'
P04D      		EQU		H'0004'

;----- IOP4 Bits ---------------------------------------------------

P40D      		EQU		H'0000'
P41D      		EQU		H'0001'
P42D      		EQU		H'0002'
P43D      		EQU		H'0003'
P44D      		EQU		H'0004'

;----- IOP5 Bits ---------------------------------------------------

P53D      		EQU		H'0003'
P54D      		EQU		H'0004'

;----- TXCR Bits ---------------------------------------------------

T0GE      		EQU		H'0001'
T0PTSX    		EQU		H'0002'
T1PTSX    		EQU		H'0003'

;----- T0CR Bits ---------------------------------------------------

PWM0OE    		EQU		H'0000'
BUZ0OE    		EQU		H'0001'
T0ALOAD   		EQU		H'0002'
T0PTS     		EQU		H'0003'
T0PR0     		EQU		H'0004'
T0PR1     		EQU		H'0005'
T0PR2     		EQU		H'0006'
TC0EN     		EQU		H'0007'

;----- T0C Bits ---------------------------------------------------

T0C0      		EQU		H'0000'
T0C1      		EQU		H'0001'
T0C2      		EQU		H'0002'
T0C3      		EQU		H'0003'
T0C4      		EQU		H'0004'
T0C5      		EQU		H'0005'
T0C6      		EQU		H'0006'
T0C7      		EQU		H'0007'

;----- T1CR Bits ---------------------------------------------------

PWM1OE    		EQU		H'0000'
BUZ1OE    		EQU		H'0001'
T1ALOAD   		EQU		H'0002'
T1PTS     		EQU		H'0003'
T1PR0     		EQU		H'0004'
T1PR1     		EQU		H'0005'
T1PR2     		EQU		H'0006'
TC1EN     		EQU		H'0007'

;----- T1C Bits ---------------------------------------------------

T1C0      		EQU		H'0000'
T1C1      		EQU		H'0001'
T1C2      		EQU		H'0002'
T1C3      		EQU		H'0003'
T1C4      		EQU		H'0004'
T1C5      		EQU		H'0005'
T1C6      		EQU		H'0006'
T1C7      		EQU		H'0007'

;----- T1D Bits ---------------------------------------------------

T1D0      		EQU		H'0000'
T1D1      		EQU		H'0001'
T1D2      		EQU		H'0002'
T1D3      		EQU		H'0003'
T1D4      		EQU		H'0004'
T1D5      		EQU		H'0005'
T1D6      		EQU		H'0006'
T1D7      		EQU		H'0007'

;----- STKP Bits ---------------------------------------------------

STKP0     		EQU		H'0000'
STKP1     		EQU		H'0001'
STKP2     		EQU		H'0002'
GIE       		EQU		H'0007'

;----- PUP0 Bits ---------------------------------------------------

P00PU     		EQU		H'0000'
P01PU     		EQU		H'0001'
P02PU     		EQU		H'0002'
P03PU     		EQU		H'0003'

;----- PUP4 Bits ---------------------------------------------------

P40PU     		EQU		H'0000'
P41PU     		EQU		H'0001'
P42PU     		EQU		H'0002'
P43PU     		EQU		H'0003'
P44PU     		EQU		H'0004'

;----- PUP5 Bits ---------------------------------------------------

P53PU     		EQU		H'0003'
P54PU     		EQU		H'0004'

;----- INDF Bits ---------------------------------------------------

INDF0     		EQU		H'0000'
INDF1     		EQU		H'0001'
INDF2     		EQU		H'0002'
INDF3     		EQU		H'0003'
INDF4     		EQU		H'0004'
INDF5     		EQU		H'0005'
INDF6     		EQU		H'0006'
INDF7     		EQU		H'0007'

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'FF'
	__BADRAM H'80'-H'81'
	__BADRAM H'85'
	__BADRAM H'87'-H'AD'
	__BADRAM H'B0'
	__BADRAM H'B4'-H'B7'
	__BADRAM H'B9'-H'BE'
	__BADRAM H'C0'-H'C3'
	__BADRAM H'C6'-H'C7'
	__BADRAM H'CB'
	__BADRAM H'D1'-H'D3'
	__BADRAM H'D6'-H'D7'
	__BADRAM H'D9'
	__BADRAM H'E1'-H'E3'
	__BADRAM H'E6'
	__BADRAM H'E8'-H'F7'


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
