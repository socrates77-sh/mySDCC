		LIST
;mc35p7041.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __35P7041
		MESSG "Processor-header file mismatch.  Verify selected processor."
	ENDIF

;==========================================================================
;
;	Register Definitions
;
;==========================================================================

;----- Register Files ---------------------------------------------------

INDF      		EQU		H'00E7'
HIBYTE    		EQU		H'0082'
FSR0      		EQU		H'0083'
FSR1      		EQU		H'0084'
PCH       		EQU		H'00CF'
PCL       		EQU		H'00CE'
STATUS    		EQU		H'0086'
PFLAG     		EQU		H'0086'
ZEROTR    		EQU		H'008E'
OSCCAL    		EQU		H'008F'
WKCR0     		EQU		H'00A0'
WKCR5     		EQU		H'00A5'
ADIOS0    		EQU		H'00AD'
ADIOS1    		EQU		H'00AE'
ADIOS2    		EQU		H'00AF'
ADCR0     		EQU		H'00B1'
ADCR1     		EQU		H'00B2'
ADRH      		EQU		H'00B3'
ADRL      		EQU		H'00B4'
ADCR2     		EQU		H'00B5'
OEP0      		EQU		H'00B8'
EINTCR    		EQU		H'00BF'
OEP4      		EQU		H'00C4'
OEP5      		EQU		H'00C5'
INTF      		EQU		H'00C8'
INTE      		EQU		H'00C9'
OSCM      		EQU		H'00CA'
WDTCR     		EQU		H'00CC'
T1LDR     		EQU		H'00CD'
IOP0      		EQU		H'00D0'
IOP4      		EQU		H'00D4'
IOP5      		EQU		H'00D5'
T0CR      		EQU		H'00D8'
T0CNT     		EQU		H'00D9'
T1CR      		EQU		H'00DA'
T1CNT     		EQU		H'00DB'
BUZCR     		EQU		H'00DC'
MCR       		EQU		H'00DF'
PUP0      		EQU		H'00E0'
PUP4      		EQU		H'00E4'
PUP5      		EQU		H'00E5'
PWMCR0    		EQU		H'00E8'
PWMCR1    		EQU		H'00E9'
PWMCNT    		EQU		H'00EA'
PWMADT    		EQU		H'00EB'
PWMBDT    		EQU		H'00EC'
PWMCDT    		EQU		H'00ED'
PWMPD     		EQU		H'00EE'
STKR0L    		EQU		H'00F0'
STKR0H    		EQU		H'00F1'
STKR1L    		EQU		H'00F2'
STKR1H    		EQU		H'00F3'
STKR2L    		EQU		H'00F4'
STKR2H    		EQU		H'00F5'
STKR3L    		EQU		H'00F6'
STKR3H    		EQU		H'00F7'
STKR4L    		EQU		H'00F8'
STKR4H    		EQU		H'00F9'
STKR5L    		EQU		H'00FA'
STKR5H    		EQU		H'00FB'
STKR6L    		EQU		H'00FC'
STKR6H    		EQU		H'00FD'
STKR7L    		EQU		H'00FE'
STKR7H    		EQU		H'00FF'

;----- STATUS Bits ---------------------------------------------------

Z         		EQU		H'0000'
DC        		EQU		H'0001'
C         		EQU		H'0002'

;----- PFLAG Bits ---------------------------------------------------

LVD24     		EQU		H'0004'
LVD36     		EQU		H'0005'

;----- ZEROTR Bits ---------------------------------------------------

ZEROTR0   		EQU		H'0000'
ZEROTR1   		EQU		H'0001'
ZEROTR2   		EQU		H'0002'
ZEROTR3   		EQU		H'0003'
ZEROTR4   		EQU		H'0004'
ZOTEN0    		EQU		H'0006'
ZOTEN1    		EQU		H'0007'

;----- WKCR0 Bits ---------------------------------------------------

P00WK     		EQU		H'0000'
P01WK     		EQU		H'0001'
P02WK     		EQU		H'0002'
P03WK     		EQU		H'0003'
P04WK     		EQU		H'0004'
P05WK     		EQU		H'0005'
P06WK     		EQU		H'0006'
P07WK     		EQU		H'0007'

;----- WKCR5 Bits ---------------------------------------------------

P50WK     		EQU		H'0000'
P51WK     		EQU		H'0001'
P52WK     		EQU		H'0002'
P53WK     		EQU		H'0003'
P54WK     		EQU		H'0004'

;----- ADIOS0 Bits ---------------------------------------------------

AN5EN     		EQU		H'0000'
AN9EN     		EQU		H'0007'

;----- ADIOS1 Bits ---------------------------------------------------

AN8EN     		EQU		H'0002'
AN7EN     		EQU		H'0003'
AN6EN     		EQU		H'0004'

;----- ADIOS2 Bits ---------------------------------------------------

AN0EN     		EQU		H'0000'
AN1EN     		EQU		H'0001'
AN2EN     		EQU		H'0002'
AN3EN     		EQU		H'0003'
AN4EN     		EQU		H'0004'

;----- ADCR0 Bits ---------------------------------------------------

ADCHS0    		EQU		H'0000'
ADCHS1    		EQU		H'0001'
ADCHS2    		EQU		H'0002'
ADCHS3    		EQU		H'0003'
GCHS      		EQU		H'0004'
ADEOC     		EQU		H'0005'
ADSTR     		EQU		H'0006'
ADEN      		EQU		H'0007'

;----- ADCR1 Bits ---------------------------------------------------

ADSPS0    		EQU		H'0000'
ADSPS1    		EQU		H'0001'
ADSPS2    		EQU		H'0002'
ADSPS3    		EQU		H'0003'
ADCKS0    		EQU		H'0004'
ADCKS1    		EQU		H'0005'
ADCKS2    		EQU		H'0006'
ADRSEL    		EQU		H'0007'

;----- ADCR2 Bits ---------------------------------------------------

VRS0      		EQU		H'0000'
VRS1      		EQU		H'0001'
EVRS      		EQU		H'0007'

;----- OEP0 Bits ---------------------------------------------------

P00OE     		EQU		H'0000'
P01OE     		EQU		H'0001'
P02OE     		EQU		H'0002'
P03OE     		EQU		H'0003'
P04OE     		EQU		H'0004'
P05OE     		EQU		H'0005'
P06OE     		EQU		H'0006'
P07OE     		EQU		H'0007'

;----- EINTCR Bits ---------------------------------------------------

MINT00    		EQU		H'0003'
MINT01    		EQU		H'0004'

;----- OEP4 Bits ---------------------------------------------------

P40OE     		EQU		H'0000'
P41OE     		EQU		H'0001'
P42OE     		EQU		H'0002'
P43OE     		EQU		H'0003'
P44OE     		EQU		H'0004'

;----- OEP5 Bits ---------------------------------------------------

P50OE     		EQU		H'0000'
P51OE     		EQU		H'0001'
P52OE     		EQU		H'0002'
P53OE     		EQU		H'0003'
P54OE     		EQU		H'0004'

;----- INTF Bits ---------------------------------------------------

INT0IF    		EQU		H'0000'
PWMIF     		EQU		H'0003'
T0IF      		EQU		H'0004'
T1IF      		EQU		H'0005'
ADIF      		EQU		H'0007'

;----- INTE Bits ---------------------------------------------------

INT0IE    		EQU		H'0000'
PWMIE     		EQU		H'0003'
T0IE      		EQU		H'0004'
T1IE      		EQU		H'0005'
ADIE      		EQU		H'0007'

;----- OSCM Bits ---------------------------------------------------

HFDE      		EQU		H'0001'
CLKS      		EQU		H'0002'
CPUM0     		EQU		H'0003'
CPUM1     		EQU		H'0004'

;----- IOP0 Bits ---------------------------------------------------

P00D      		EQU		H'0000'
P01D      		EQU		H'0001'
P02D      		EQU		H'0002'
P03D      		EQU		H'0003'
P04D      		EQU		H'0004'
P05D      		EQU		H'0005'
P06D      		EQU		H'0006'
P07D      		EQU		H'0007'

;----- IOP4 Bits ---------------------------------------------------

P40D      		EQU		H'0000'
P41D      		EQU		H'0001'
P42D      		EQU		H'0002'
P43D      		EQU		H'0003'
P44D      		EQU		H'0004'

;----- IOP5 Bits ---------------------------------------------------

P50D      		EQU		H'0000'
P51D      		EQU		H'0001'
P52D      		EQU		H'0002'
P53D      		EQU		H'0003'
P54D      		EQU		H'0004'

;----- T0CR Bits ---------------------------------------------------

T0CKS1    		EQU		H'0002'
T0CKS2    		EQU		H'0003'
T0PRS0    		EQU		H'0004'
T0PRS1    		EQU		H'0005'
T0PRS2    		EQU		H'0006'
T0EN      		EQU		H'0007'

;----- T1CR Bits ---------------------------------------------------

PWM1OE    		EQU		H'0000'
BUZ1OE    		EQU		H'0001'
T1CKS1    		EQU		H'0002'
T1CKS2    		EQU		H'0003'
T1PRS0    		EQU		H'0004'
T1PRS1    		EQU		H'0005'
T1PRS2    		EQU		H'0006'
T1EN      		EQU		H'0007'

;----- BUZCR Bits ---------------------------------------------------

BUZPRS0   		EQU		H'0005'
BUZPRS1   		EQU		H'0006'
BUZEN     		EQU		H'0007'

;----- MCR Bits ---------------------------------------------------

STKP0     		EQU		H'0000'
STKP1     		EQU		H'0001'
STKP2     		EQU		H'0002'
GIE       		EQU		H'0007'

;----- PUP0 Bits ---------------------------------------------------

P00PU     		EQU		H'0000'
P01PU     		EQU		H'0001'
P02PU     		EQU		H'0002'
P03PU     		EQU		H'0003'
P04PU     		EQU		H'0004'
P05PU     		EQU		H'0005'
P06PU     		EQU		H'0006'
P07PU     		EQU		H'0007'

;----- PUP4 Bits ---------------------------------------------------

P40PU     		EQU		H'0000'
P41PU     		EQU		H'0001'
P42PU     		EQU		H'0002'
P43PU     		EQU		H'0003'
P44PU     		EQU		H'0004'

;----- PUP5 Bits ---------------------------------------------------

P50PU     		EQU		H'0000'
P51PU     		EQU		H'0001'
P52PU     		EQU		H'0002'
P53PU     		EQU		H'0003'
P54PU     		EQU		H'0004'

;----- PWMCR0 Bits ---------------------------------------------------

PWMAOF    		EQU		H'0000'
PWMBOF    		EQU		H'0001'
PWMCOF    		EQU		H'0002'
PWMPRS0   		EQU		H'0004'
PWMPRS1   		EQU		H'0005'
PWMPRS2   		EQU		H'0006'
PWMEN     		EQU		H'0007'

;----- PWMCR1 Bits ---------------------------------------------------

PWMAOE    		EQU		H'0005'
PWMBOE    		EQU		H'0006'
PWMCOE    		EQU		H'0007'

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'FF'
	__BADRAM H'80'-H'81'
	__BADRAM H'85'
	__BADRAM H'87'-H'9F'
	__BADRAM H'A1'-H'A4'
	__BADRAM H'A6'-H'AC'
	__BADRAM H'B0'
	__BADRAM H'B6'-H'B7'
	__BADRAM H'B9'-H'BE'
	__BADRAM H'C0'-H'C3'
	__BADRAM H'C6'-H'C7'
	__BADRAM H'D1'-H'D3'
	__BADRAM H'D6'-H'D7'
	__BADRAM H'DD'-H'DE'
	__BADRAM H'E1'-H'E3'
	__BADRAM H'E6'
	__BADRAM H'EF'


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
