		LIST
;mc32p7041.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

	IFNDEF __32P7041
		MESSG "Processor-header file mismatch.  Verify selected processor."
	ENDIF

;==========================================================================
;
;	Register Definitions
;
;==========================================================================

;----- Register Files ---------------------------------------------------

HIBYTE    		EQU		H'0082'
FSR       		EQU		H'0083'
FSR0      		EQU		H'0083'
FSR1      		EQU		H'0084'
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
PCL       		EQU		H'00CE'
PCH       		EQU		H'00CF'
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
INDF      		EQU		H'00E7'
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

;----- PFLAG Bits ---------------------------------------------------

#define		Z         	PFLAG,0
#define		DC        	PFLAG,1
#define		C         	PFLAG,2
#define		LVD24     	PFLAG,4
#define		LVD36     	PFLAG,5
#define		NPD       	PFLAG,6
#define		NTO       	PFLAG,7

;----- ZEROTR Bits ---------------------------------------------------

#define		ZEROTR0   	ZEROTR,0
#define		ZEROTR1   	ZEROTR,1
#define		ZEROTR2   	ZEROTR,2
#define		ZEROTR3   	ZEROTR,3
#define		ZEROTR4   	ZEROTR,4
#define		ZOTEN0    	ZEROTR,6
#define		ZOTEN1    	ZEROTR,7

;----- OSCCAL Bits ---------------------------------------------------

#define		OSCCAL0   	OSCCAL,0
#define		OSCCAL1   	OSCCAL,1
#define		OSCCAL2   	OSCCAL,2
#define		OSCCAL3   	OSCCAL,3
#define		OSCCAL4   	OSCCAL,4
#define		OSCCAL5   	OSCCAL,5
#define		OSCCAL6   	OSCCAL,6
#define		OSCCAL7   	OSCCAL,7

;----- WKCR0 Bits ---------------------------------------------------

#define		P00WK     	WKCR0,0
#define		P01WK     	WKCR0,1
#define		P02WK     	WKCR0,2
#define		P03WK     	WKCR0,3
#define		P04WK     	WKCR0,4
#define		P05WK     	WKCR0,5
#define		P06WK     	WKCR0,6
#define		P07WK     	WKCR0,7

;----- WKCR5 Bits ---------------------------------------------------

#define		P50WK     	WKCR5,0
#define		P51WK     	WKCR5,1
#define		P52WK     	WKCR5,2
#define		P53WK     	WKCR5,3
#define		P54WK     	WKCR5,4

;----- ADIOS0 Bits ---------------------------------------------------

#define		AN5EN     	ADIOS0,0
#define		AN9EN     	ADIOS0,7

;----- ADIOS1 Bits ---------------------------------------------------

#define		AN8EN     	ADIOS1,2
#define		AN7EN     	ADIOS1,3
#define		AN6EN     	ADIOS1,4

;----- ADIOS2 Bits ---------------------------------------------------

#define		AN0EN     	ADIOS2,0
#define		AN1EN     	ADIOS2,1
#define		AN2EN     	ADIOS2,2
#define		AN3EN     	ADIOS2,3
#define		AN4EN     	ADIOS2,4

;----- ADCR0 Bits ---------------------------------------------------

#define		ADCHS0    	ADCR0,0
#define		ADCHS1    	ADCR0,1
#define		ADCHS2    	ADCR0,2
#define		ADCHS3    	ADCR0,3
#define		GCHS      	ADCR0,4
#define		ADEOC     	ADCR0,5
#define		ADSTR     	ADCR0,6
#define		ADEN      	ADCR0,7

;----- ADCR1 Bits ---------------------------------------------------

#define		ADSPS0    	ADCR1,0
#define		ADSPS1    	ADCR1,1
#define		ADSPS2    	ADCR1,2
#define		ADSPS3    	ADCR1,3
#define		ADCKS0    	ADCR1,4
#define		ADCKS1    	ADCR1,5
#define		ADCKS2    	ADCR1,6
#define		ADRSEL    	ADCR1,7

;----- ADCR2 Bits ---------------------------------------------------

#define		VRS0      	ADCR2,0
#define		VRS1      	ADCR2,1
#define		PCHEN     	ADCR2,2
#define		EVRS      	ADCR2,7

;----- OEP0 Bits ---------------------------------------------------

#define		P00OE     	OEP0,0
#define		P01OE     	OEP0,1
#define		P02OE     	OEP0,2
#define		P03OE     	OEP0,3
#define		P04OE     	OEP0,4
#define		P05OE     	OEP0,5
#define		P06OE     	OEP0,6
#define		P07OE     	OEP0,7

;----- EINTCR Bits ---------------------------------------------------

#define		MINT00    	EINTCR,3
#define		MINT01    	EINTCR,4

;----- OEP4 Bits ---------------------------------------------------

#define		P40OE     	OEP4,0
#define		P41OE     	OEP4,1
#define		P42OE     	OEP4,2
#define		P43OE     	OEP4,3
#define		P44OE     	OEP4,4

;----- OEP5 Bits ---------------------------------------------------

#define		P50OE     	OEP5,0
#define		P51OE     	OEP5,1
#define		P52OE     	OEP5,2
#define		P53OE     	OEP5,3
#define		P54OE     	OEP5,4

;----- INTF Bits ---------------------------------------------------

#define		INT0IF    	INTF,0
#define		PWMIF     	INTF,3
#define		T0IF      	INTF,4
#define		T1IF      	INTF,5
#define		ADIF      	INTF,7

;----- INTE Bits ---------------------------------------------------

#define		INT0IE    	INTE,0
#define		PWMIE     	INTE,3
#define		T0IE      	INTE,4
#define		T1IE      	INTE,5
#define		ADIE      	INTE,7

;----- OSCM Bits ---------------------------------------------------

#define		HFDE      	OSCM,1
#define		CLKS      	OSCM,2
#define		CPUM0     	OSCM,3
#define		CPUM1     	OSCM,4

;----- WDTCR Bits ---------------------------------------------------

#define		WDTCR0    	WDTCR,0
#define		WDTCR1    	WDTCR,1
#define		WDTCR2    	WDTCR,2
#define		WDTCR3    	WDTCR,3
#define		WDTCR5    	WDTCR,5
#define		WDTCR6    	WDTCR,6
#define		WDTCR7    	WDTCR,7

;----- T1LDR Bits ---------------------------------------------------

#define		T1LDR0    	T1LDR,0
#define		T1LDR1    	T1LDR,1
#define		T1LDR2    	T1LDR,2
#define		T1LDR3    	T1LDR,3
#define		T1LDR4    	T1LDR,4
#define		T1LDR5    	T1LDR,5
#define		T1LDR6    	T1LDR,6
#define		T1LDR7    	T1LDR,7

;----- PCL Bits ---------------------------------------------------

#define		PC0       	PCL,0
#define		PC1       	PCL,1
#define		PC2       	PCL,2
#define		PC3       	PCL,3
#define		PC4       	PCL,4
#define		PC5       	PCL,5
#define		PC6       	PCL,6
#define		PC7       	PCL,7

;----- PCH Bits ---------------------------------------------------

#define		PC8       	PCH,0
#define		PC9       	PCH,1
#define		PC10      	PCH,2

;----- IOP0 Bits ---------------------------------------------------

#define		P00D      	IOP0,0
#define		P01D      	IOP0,1
#define		P02D      	IOP0,2
#define		P03D      	IOP0,3
#define		P04D      	IOP0,4
#define		P05D      	IOP0,5
#define		P06D      	IOP0,6
#define		P07D      	IOP0,7

;----- IOP4 Bits ---------------------------------------------------

#define		P40D      	IOP4,0
#define		P41D      	IOP4,1
#define		P42D      	IOP4,2
#define		P43D      	IOP4,3

;----- IOP5 Bits ---------------------------------------------------

#define		P50D      	IOP5,0
#define		P51D      	IOP5,1
#define		P52D      	IOP5,2
#define		P53D      	IOP5,3

;----- T0CR Bits ---------------------------------------------------

#define		T1CKS1    	T0CR,2
#define		T1CKS2    	T0CR,3
#define		T0PRS0    	T0CR,4
#define		T0PRS1    	T0CR,5
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

;----- T1CR Bits ---------------------------------------------------

#define		PWM1OE    	T1CR,0
#define		BUZ1OE    	T1CR,1
#define		T1LDEN    	T1CR,2
#define		T1CKS0    	T1CR,3
#define		T1PRS0    	T1CR,4
#define		T1PRS1    	T1CR,5
#define		T1PRS2    	T1CR,6
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

;----- BUZCR Bits ---------------------------------------------------

#define		BUZPRS0   	BUZCR,5
#define		BUZPRS1   	BUZCR,6
#define		BUZEN     	BUZCR,7

;----- MCR Bits ---------------------------------------------------

#define		STKP0     	MCR,0
#define		STKP1     	MCR,1
#define		STKP2     	MCR,2
#define		GIE       	MCR,7

;----- PUP0 Bits ---------------------------------------------------

#define		P00PU     	PUP0,0
#define		P01PU     	PUP0,1
#define		P02PU     	PUP0,2
#define		P03PU     	PUP0,3
#define		P04PU     	PUP0,4
#define		P05PU     	PUP0,5
#define		P06PU     	PUP0,6
#define		P07PU     	PUP0,7

;----- PUP4 Bits ---------------------------------------------------

#define		P40PU     	PUP4,0
#define		P41PU     	PUP4,1
#define		P42PU     	PUP4,2
#define		P43PU     	PUP4,3
#define		P44PU     	PUP4,4

;----- PUP5 Bits ---------------------------------------------------

#define		P50PU     	PUP5,0
#define		P51PU     	PUP5,1
#define		P52PU     	PUP5,2
#define		P53PU     	PUP5,3
#define		P54PU     	PUP5,4

;----- INDF Bits ---------------------------------------------------

#define		INDF0     	INDF,0
#define		INDF1     	INDF,1
#define		INDF2     	INDF,2
#define		INDF3     	INDF,3
#define		INDF4     	INDF,4
#define		INDF5     	INDF,5
#define		INDF6     	INDF,6
#define		INDF7     	INDF,7

;----- PWMCR0 Bits ---------------------------------------------------

#define		PWMAOF    	PWMCR0,0
#define		PWMBOF    	PWMCR0,1
#define		PWMCOF    	PWMCR0,2
#define		PWMPRS0   	PWMCR0,4
#define		PWMPRS1   	PWMCR0,5
#define		PWMPRS2   	PWMCR0,6
#define		PWMEN     	PWMCR0,7

;----- PWMCR1 Bits ---------------------------------------------------

#define		PWMAOE    	PWMCR1,5
#define		PWMBOE    	PWMCR1,6
#define		PWMCOE    	PWMCR1,7

;----- PWMCNT Bits ---------------------------------------------------

#define		PWMCNT0   	PWMCNT,0
#define		PWMCNT1   	PWMCNT,1
#define		PWMCNT2   	PWMCNT,2
#define		PWMCNT3   	PWMCNT,3
#define		PWMCNT4   	PWMCNT,4
#define		PWMCNT5   	PWMCNT,5
#define		PWMCNT6   	PWMCNT,6
#define		PWMCNT7   	PWMCNT,7

;----- PWMADT Bits ---------------------------------------------------

#define		PWMADT0   	PWMADT,0
#define		PWMADT1   	PWMADT,1
#define		PWMADT2   	PWMADT,2
#define		PWMADT3   	PWMADT,3
#define		PWMADT4   	PWMADT,4
#define		PWMADT5   	PWMADT,5
#define		PWMADT6   	PWMADT,6
#define		PWMADT7   	PWMADT,7

;----- PWMBDT Bits ---------------------------------------------------

#define		PWMBDT0   	PWMBDT,0
#define		PWMBDT1   	PWMBDT,1
#define		PWMBDT2   	PWMBDT,2
#define		PWMBDT3   	PWMBDT,3
#define		PWMBDT4   	PWMBDT,4
#define		PWMBDT5   	PWMBDT,5
#define		PWMBDT6   	PWMBDT,6
#define		PWMBDT7   	PWMBDT,7

;----- PWMCDT Bits ---------------------------------------------------

#define		PWMCDT0   	PWMCDT,0
#define		PWMCDT1   	PWMCDT,1
#define		PWMCDT2   	PWMCDT,2
#define		PWMCDT3   	PWMCDT,3
#define		PWMCDT4   	PWMCDT,4
#define		PWMCDT5   	PWMCDT,5
#define		PWMCDT6   	PWMCDT,6
#define		PWMCDT7   	PWMCDT,7

;----- PWMPD Bits ---------------------------------------------------

#define		PWMPD0    	PWMPD,0
#define		PWMPD1    	PWMPD,1
#define		PWMPD2    	PWMPD,2
#define		PWMPD3    	PWMPD,3
#define		PWMPD4    	PWMPD,4
#define		PWMPD5    	PWMPD,5
#define		PWMPD6    	PWMPD,6
#define		PWMPD7    	PWMPD,7

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'FF'
	__BADRAM H'80'-H'81'
	__BADRAM H'85'
	__BADRAM H'87'
	__BADRAM H'88'-H'8D'
	__BADRAM H'90'-H'9F'
	__BADRAM H'A1'-H'A4'
	__BADRAM H'A6'-H'A7'
	__BADRAM H'A8'-H'AC'
	__BADRAM H'B0'
	__BADRAM H'B6'-H'B7'
	__BADRAM H'B9'-H'BE'
	__BADRAM H'C0'-H'C3'
	__BADRAM H'C6'-H'C7'
	__BADRAM H'CB'
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
