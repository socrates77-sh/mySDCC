		LIST
;mc32p5314.inc    Standard Header File, Version 1.00 by Sinomcu
		NOLIST

;==========================================================================
;
;	Verify Processor
;
;==========================================================================

;	IFNDEF __32P5314
;		MESSG "Processor-header file mismatch.  Verify selected processor."
;	ENDIF

;==========================================================================
;
;	Register Definitions
;
;==========================================================================

;----- Register Files ---------------------------------------------------

LCDDS00   		EQU		H'0100'
LCDDS01   		EQU		H'0101'
LCDDS02   		EQU		H'0102'
LCDDS03   		EQU		H'0103'
LCDDS04   		EQU		H'0104'
LCDDS05   		EQU		H'0105'
LCDDS06   		EQU		H'0106'
LCDDS07   		EQU		H'0107'
LCDDS08   		EQU		H'0108'
LCDDS09   		EQU		H'0109'
LCDDS10   		EQU		H'010A'
LCDDS11   		EQU		H'010B'
LCDDS12   		EQU		H'010C'
LCDDS13   		EQU		H'010D'
LCDDS14   		EQU		H'010E'
LCDDS15   		EQU		H'010F'
LCDDS16   		EQU		H'0110'
LCDDS17   		EQU		H'0111'
LCDDS18   		EQU		H'0112'
LCDDS19   		EQU		H'0113'
LCDDS20   		EQU		H'0114'
LCDDS21   		EQU		H'0115'
LCDDS22   		EQU		H'0116'
LCDDS23   		EQU		H'0117'
LCDDS24   		EQU		H'0118'
LCDDS25   		EQU		H'0119'
LCDDS26   		EQU		H'011A'
LCDDS27   		EQU		H'011B'
LCDDS28   		EQU		H'011C'
LCDDS29   		EQU		H'011D'
INDF0     		EQU		H'01B0'
INDF1     		EQU		H'01B1'
INDF2     		EQU		H'01B2'
HIBYTE    		EQU		H'01B3'
FSR0      		EQU		H'01B4'
FSR1      		EQU		H'01B5'
PCL       		EQU		H'01B6'
PFLAG     		EQU		H'01B7'
MCR       		EQU		H'01B8'
INDF3     		EQU		H'01B9'
INTE      		EQU		H'01BA'
INTF      		EQU		H'01BB'
OSCM      		EQU		H'01BC'
LVDCR     		EQU		H'01BD'
LXTCR     		EQU		H'01BE'
IOP0      		EQU		H'01C0'
OEP0      		EQU		H'01C1'
PUP0      		EQU		H'01C2'
DKWP0     		EQU		H'01C3'
IOP1      		EQU		H'01C4'
OEP1      		EQU		H'01C5'
PUP1      		EQU		H'01C6'
LCDIOSP1  		EQU		H'01C7'
IOP2      		EQU		H'01C8'
OEP2      		EQU		H'01C9'
PUP2      		EQU		H'01CA'
LCDIOSP2  		EQU		H'01CB'
IOP3      		EQU		H'01CC'
OEP3      		EQU		H'01CD'
PUP3      		EQU		H'01CE'
LCDIOSP3  		EQU		H'01CF'
IOP4      		EQU		H'01D0'
OEP4      		EQU		H'01D1'
PUP4      		EQU		H'01D2'
LCDIOSP4  		EQU		H'01D3'
IOP5      		EQU		H'01D4'
OEP5      		EQU		H'01D5'
PUP5      		EQU		H'01D6'
LCDIOSP5  		EQU		H'01D7'
T0CR0     		EQU		H'01D8'
T0CR1     		EQU		H'01D9'
T0LOADH   		EQU		H'01DC'
T0LOADL   		EQU		H'01DD'
T0DATAH   		EQU		H'01DE'
T0DATAL   		EQU		H'01DF'
T0LATRH   		EQU		H'01E0'
T0LATRL   		EQU		H'01E1'
T0LATFH   		EQU		H'01E2'
T0LATFL   		EQU		H'01E3'
T1CR      		EQU		H'01E4'
T1DATA    		EQU		H'01E5'
T1LOAD    		EQU		H'01E6'
ADCR0     		EQU		H'01E8'
ADCR1     		EQU		H'01E9'
ADCR2     		EQU		H'01EA'
ADDRH     		EQU		H'01EC'
ADDRL     		EQU		H'01ED'
OPCR0     		EQU		H'01F0'
OPCR1     		EQU		H'01F1'
LCDCR0    		EQU		H'01F2'
LCDCR1    		EQU		H'01F3'
DKW       		EQU		H'01F4'
KBCR      		EQU		H'01F5'
LCDDRV    		EQU		H'01F6'

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
LVDIE     		EQU		H'0005'
ADIE      		EQU		H'0007'

;----- INTF Bits ---------------------------------------------------

T0IF      		EQU		H'0000'
T1IF      		EQU		H'0001'
INT0IF    		EQU		H'0002'
INT1IF    		EQU		H'0003'
KBIF      		EQU		H'0004'
LVDIF     		EQU		H'0005'
T0RF      		EQU		H'0006'
ADIF      		EQU		H'0007'

;----- OSCM Bits ---------------------------------------------------

HFEN      		EQU		H'0000'
LFEN      		EQU		H'0001'
CLKS      		EQU		H'0002'
STBH      		EQU		H'0004'
STBL      		EQU		H'0005'

;----- LVDCR Bits ---------------------------------------------------

LVDF      		EQU		H'0000'
LVDS0     		EQU		H'0003'
LVDS1     		EQU		H'0004'
LVDS2     		EQU		H'0005'
LVDS3     		EQU		H'0006'
LVDEN     		EQU		H'0007'

;----- LXTCR Bits ---------------------------------------------------

LPEN0     		EQU		H'0000'
LPEN1     		EQU		H'0001'
LPEN2     		EQU		H'0002'
FILS      		EQU		H'0003'
VDLSEL    		EQU		H'0004'

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

;----- DKWP0 Bits ---------------------------------------------------

P00DKW    		EQU		H'0000'
P01DKW    		EQU		H'0001'
P02DKW    		EQU		H'0002'
P03DKW    		EQU		H'0003'
P04DKW    		EQU		H'0004'
P05DKW    		EQU		H'0005'
P06DKW    		EQU		H'0006'
P07DKW    		EQU		H'0007'

;----- IOP1 Bits ---------------------------------------------------

P10D      		EQU		H'0000'
P11D      		EQU		H'0001'
P12D      		EQU		H'0002'
P13D      		EQU		H'0003'
P14D      		EQU		H'0004'
P15D      		EQU		H'0005'
P16D      		EQU		H'0006'
P17D      		EQU		H'0007'

;----- OEP1 Bits ---------------------------------------------------

P10OE     		EQU		H'0000'
P11OE     		EQU		H'0001'
P12OE     		EQU		H'0002'
P13OE     		EQU		H'0003'
P14OE     		EQU		H'0004'
P15OE     		EQU		H'0005'
P16OE     		EQU		H'0006'
P17OE     		EQU		H'0007'

;----- PUP1 Bits ---------------------------------------------------

P10PU     		EQU		H'0000'
P11PU     		EQU		H'0001'
P12PU     		EQU		H'0002'
P13PU     		EQU		H'0003'
P14PU     		EQU		H'0004'
P15PU     		EQU		H'0005'
P16PU     		EQU		H'0006'
P17PU     		EQU		H'0007'

;----- LCDIOSP1 Bits ---------------------------------------------------

LCDIOSP10 		EQU		H'0000'
LCDIOSP11 		EQU		H'0001'
LCDIOSP12 		EQU		H'0002'
LCDIOSP13 		EQU		H'0003'
LCDIOSP14 		EQU		H'0004'
LCDIOSP15 		EQU		H'0005'
LCDIOSP16 		EQU		H'0006'
LCDIOSP17 		EQU		H'0007'

;----- IOP2 Bits ---------------------------------------------------

P20D      		EQU		H'0000'
P21D      		EQU		H'0001'
P22D      		EQU		H'0002'
P23D      		EQU		H'0003'
P24D      		EQU		H'0004'
P25D      		EQU		H'0005'
P26D      		EQU		H'0006'
P27D      		EQU		H'0007'

;----- OEP2 Bits ---------------------------------------------------

P20OE     		EQU		H'0000'
P21OE     		EQU		H'0001'
P22OE     		EQU		H'0002'
P23OE     		EQU		H'0003'
P24OE     		EQU		H'0004'
P25OE     		EQU		H'0005'
P26OE     		EQU		H'0006'
P27OE     		EQU		H'0007'

;----- PUP2 Bits ---------------------------------------------------

P20PU     		EQU		H'0000'
P21PU     		EQU		H'0001'
P22PU     		EQU		H'0002'
P23PU     		EQU		H'0003'
P24PU     		EQU		H'0004'
P25PU     		EQU		H'0005'
P26PU     		EQU		H'0006'
P27PU     		EQU		H'0007'

;----- LCDIOSP2 Bits ---------------------------------------------------

LCDIOSP20 		EQU		H'0000'
LCDIOSP21 		EQU		H'0001'
LCDIOSP22 		EQU		H'0002'
LCDIOSP23 		EQU		H'0003'
LCDIOSP24 		EQU		H'0004'
LCDIOSP25 		EQU		H'0005'
LCDIOSP26 		EQU		H'0006'
LCDIOSP27 		EQU		H'0007'

;----- IOP3 Bits ---------------------------------------------------

P30D      		EQU		H'0000'
P31D      		EQU		H'0001'
P32D      		EQU		H'0002'
P33D      		EQU		H'0003'
P34D      		EQU		H'0004'
P35D      		EQU		H'0005'
P36D      		EQU		H'0006'
P37D      		EQU		H'0007'

;----- OEP3 Bits ---------------------------------------------------

P30OE     		EQU		H'0000'
P31OE     		EQU		H'0001'
P32OE     		EQU		H'0002'
P33OE     		EQU		H'0003'
P34OE     		EQU		H'0004'
P35OE     		EQU		H'0005'
P36OE     		EQU		H'0006'
P37OE     		EQU		H'0007'

;----- PUP3 Bits ---------------------------------------------------

P30PU     		EQU		H'0000'
P31PU     		EQU		H'0001'
P32PU     		EQU		H'0002'
P33PU     		EQU		H'0003'
P34PU     		EQU		H'0004'
P35PU     		EQU		H'0005'
P36PU     		EQU		H'0006'
P37PU     		EQU		H'0007'

;----- LCDIOSP3 Bits ---------------------------------------------------

LCDIOSP30 		EQU		H'0000'
LCDIOSP31 		EQU		H'0001'
LCDIOSP32 		EQU		H'0002'
LCDIOSP33 		EQU		H'0003'
LCDIOSP34 		EQU		H'0004'
LCDIOSP35 		EQU		H'0005'
LCDIOSP36 		EQU		H'0006'
LCDIOSP37 		EQU		H'0007'

;----- IOP4 Bits ---------------------------------------------------

P40D      		EQU		H'0000'
P41D      		EQU		H'0001'
P42D      		EQU		H'0002'
P43D      		EQU		H'0003'
P44D      		EQU		H'0004'
P45D      		EQU		H'0005'
P46D      		EQU		H'0006'
P47D      		EQU		H'0007'

;----- OEP4 Bits ---------------------------------------------------

P40OE     		EQU		H'0000'
P41OE     		EQU		H'0001'
P42OE     		EQU		H'0002'
P43OE     		EQU		H'0003'
P44OE     		EQU		H'0004'
P45OE     		EQU		H'0005'
P46OE     		EQU		H'0006'
P47OE     		EQU		H'0007'

;----- PUP4 Bits ---------------------------------------------------

P40PU     		EQU		H'0000'
P41PU     		EQU		H'0001'
P42PU     		EQU		H'0002'
P43PU     		EQU		H'0003'
P44PU     		EQU		H'0004'
P45PU     		EQU		H'0005'
P46PU     		EQU		H'0006'
P47PU     		EQU		H'0007'

;----- LCDIOSP4 Bits ---------------------------------------------------

LCDIOSP40 		EQU		H'0000'
LCDIOSP41 		EQU		H'0001'
LCDIOSP42 		EQU		H'0002'
LCDIOSP43 		EQU		H'0003'
LCDIOSP44 		EQU		H'0004'
LCDIOSP45 		EQU		H'0005'
LCDIOSP46 		EQU		H'0006'
LCDIOSP47 		EQU		H'0007'

;----- IOP5 Bits ---------------------------------------------------

P50D      		EQU		H'0000'
P51D      		EQU		H'0001'
P52D      		EQU		H'0002'
P53D      		EQU		H'0003'
P54D      		EQU		H'0004'
P55D      		EQU		H'0005'

;----- OEP5 Bits ---------------------------------------------------

P50OE     		EQU		H'0000'
P51OE     		EQU		H'0001'
P52OE     		EQU		H'0002'
P53OE     		EQU		H'0003'
P54OE     		EQU		H'0004'
P55OE     		EQU		H'0005'

;----- PUP5 Bits ---------------------------------------------------

P50PU     		EQU		H'0000'
P51PU     		EQU		H'0001'
P52PU     		EQU		H'0002'
P53PU     		EQU		H'0003'
P55PU     		EQU		H'0005'

;----- LCDIOSP5 Bits ---------------------------------------------------

LCDIOSP50 		EQU		H'0000'
LCDIOSP51 		EQU		H'0001'

;----- T0CR0 Bits ---------------------------------------------------

T0PR0     		EQU		H'0000'
T0PR1     		EQU		H'0001'
T0PR2     		EQU		H'0002'
T0PTS0    		EQU		H'0003'
T0PTS1    		EQU		H'0004'
T0MOD0    		EQU		H'0005'
T0MOD1    		EQU		H'0006'
TC0EN     		EQU		H'0007'

;----- T0CR1 Bits ---------------------------------------------------

FPWMB0    		EQU		H'0000'
FPWMB1    		EQU		H'0001'
FPWMA0    		EQU		H'0002'
FPWMA1    		EQU		H'0003'
FPWMS     		EQU		H'0004'
PWMEN     		EQU		H'0006'
FPWMEN    		EQU		H'0007'

;----- T0LOADL Bits ---------------------------------------------------

T0LOADL0  		EQU		H'0000'
T0LOADL1  		EQU		H'0001'
T0LOADL2  		EQU		H'0002'
T0LOADL3  		EQU		H'0003'
T0LOADL4  		EQU		H'0004'
T0LOADL5  		EQU		H'0005'
T0LOADL6  		EQU		H'0006'
T0LOADL7  		EQU		H'0007'

;----- T0DATAH Bits ---------------------------------------------------

T0DATAH0  		EQU		H'0000'
T0DATAH1  		EQU		H'0001'
T0DATAH2  		EQU		H'0002'
T0DATAH3  		EQU		H'0003'
T0DATAH4  		EQU		H'0004'
T0DATAH5  		EQU		H'0005'
T0DATAH6  		EQU		H'0006'
T0DATAH7  		EQU		H'0007'

;----- T0DATAL Bits ---------------------------------------------------

T0DATAL0  		EQU		H'0000'
T0DATAL1  		EQU		H'0001'
T0DATAL2  		EQU		H'0002'
T0DATAL3  		EQU		H'0003'
T0DATAL4  		EQU		H'0004'
T0DATAL5  		EQU		H'0005'
T0DATAL6  		EQU		H'0006'
T0DATAL7  		EQU		H'0007'

;----- T0LATRH Bits ---------------------------------------------------

T0LATRH0  		EQU		H'0000'
T0LATRH1  		EQU		H'0001'
T0LATRH2  		EQU		H'0002'
T0LATRH3  		EQU		H'0003'
T0LATRH4  		EQU		H'0004'
T0LATRH5  		EQU		H'0005'
T0LATRH6  		EQU		H'0006'
T0LATRH7  		EQU		H'0007'

;----- T0LATRL Bits ---------------------------------------------------

T0LATRL0  		EQU		H'0000'
T0LATRL1  		EQU		H'0001'
T0LATRL2  		EQU		H'0002'
T0LATRL3  		EQU		H'0003'
T0LATRL4  		EQU		H'0004'
T0LATRL5  		EQU		H'0005'
T0LATRL6  		EQU		H'0006'
T0LATRL7  		EQU		H'0007'

;----- T0LATFH Bits ---------------------------------------------------

T0LATFH0  		EQU		H'0000'
T0LATFH1  		EQU		H'0001'
T0LATFH2  		EQU		H'0002'
T0LATFH3  		EQU		H'0003'
T0LATFH4  		EQU		H'0004'
T0LATFH5  		EQU		H'0005'
T0LATFH6  		EQU		H'0006'
T0LATFH7  		EQU		H'0007'

;----- T0LATFL Bits ---------------------------------------------------

T0LATFL0  		EQU		H'0000'
T0LATFL1  		EQU		H'0001'
T0LATFL2  		EQU		H'0002'
T0LATFL3  		EQU		H'0003'
T0LATFL4  		EQU		H'0004'
T0LATFL5  		EQU		H'0005'
T0LATFL6  		EQU		H'0006'
T0LATFL7  		EQU		H'0007'

;----- T1CR Bits ---------------------------------------------------

T1PR0     		EQU		H'0000'
T1PR1     		EQU		H'0001'
T1PR2     		EQU		H'0002'
T1PTS0    		EQU		H'0003'
T1PTS1    		EQU		H'0004'
T1MOD0    		EQU		H'0005'
T1MOD1    		EQU		H'0006'
TC1EN     		EQU		H'0007'

;----- T1DATA Bits ---------------------------------------------------

T1DATA0   		EQU		H'0000'
T1DATA1   		EQU		H'0001'
T1DATA2   		EQU		H'0002'
T1DATA3   		EQU		H'0003'
T1DATA4   		EQU		H'0004'
T1DATA5   		EQU		H'0005'
T1DATA6   		EQU		H'0006'
T1DATA7   		EQU		H'0007'

;----- T1LOAD Bits ---------------------------------------------------

T1LOAD0   		EQU		H'0000'
T1LOAD1   		EQU		H'0001'
T1LOAD2   		EQU		H'0002'
T1LOAD3   		EQU		H'0003'
T1LOAD4   		EQU		H'0004'
T1LOAD5   		EQU		H'0005'
T1LOAD6   		EQU		H'0006'
T1LOAD7   		EQU		H'0007'

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

ADIOS0    		EQU		H'0000'
ADIOS1    		EQU		H'0001'
ADIOS2    		EQU		H'0002'
ADIOS3    		EQU		H'0003'
ADIOS4    		EQU		H'0004'
ADIOS5    		EQU		H'0005'
ADIOS6    		EQU		H'0006'
ADIOS7    		EQU		H'0007'

;----- ADCR2 Bits ---------------------------------------------------

VREXT     		EQU		H'0000'
VREFRES   		EQU		H'0001'

;----- OPCR0 Bits ---------------------------------------------------

OPFC0     		EQU		H'0000'
OPFC1     		EQU		H'0001'
OPFC2     		EQU		H'0002'
OPFC3     		EQU		H'0003'
OPFC4     		EQU		H'0004'
OPFC5     		EQU		H'0005'
OPAM      		EQU		H'0006'
OPAE      		EQU		H'0007'

;----- OPCR1 Bits ---------------------------------------------------

CSEL0     		EQU		H'0000'
CSEL1     		EQU		H'0001'
FSEL0     		EQU		H'0002'
FSEL1     		EQU		H'0003'
VSEL      		EQU		H'0006'
IRIN      		EQU		H'0007'

;----- LCDCR0 Bits ---------------------------------------------------

LCDRS0    		EQU		H'0000'
LCDRS1    		EQU		H'0001'
LCDSPEED  		EQU		H'0002'
VLCDS     		EQU		H'0003'
LCDDUTY   		EQU		H'0004'
LCDSP0    		EQU		H'0005'
LCDSP1    		EQU		H'0006'
LCDEN     		EQU		H'0007'

;----- LCDCR1 Bits ---------------------------------------------------

FLCD0     		EQU		H'0000'
FLCD1     		EQU		H'0001'
LCDCKS    		EQU		H'0002'
LCDM      		EQU		H'0003'

;----- DKW Bits ---------------------------------------------------

DSELEN    		EQU		H'0000'
DRVS      		EQU		H'0001'
RSEL      		EQU		H'0002'
WSEL0     		EQU		H'0003'
WSEL1     		EQU		H'0004'
IROT      		EQU		H'0005'
IROS      		EQU		H'0006'
DKWE      		EQU		H'0007'

;----- KBCR Bits ---------------------------------------------------

KBCR0     		EQU		H'0000'
KBCR1     		EQU		H'0001'
KBCR2     		EQU		H'0002'
KBCR3     		EQU		H'0003'
KBCR4     		EQU		H'0004'
KBCR5     		EQU		H'0005'
KBCR6     		EQU		H'0006'
KBCR7     		EQU		H'0007'

;----- LCDDRV Bits ---------------------------------------------------

LCDDRVP06 		EQU		H'0000'
LCDDRVP22 		EQU		H'0001'
LCDDRVP23 		EQU		H'0002'

;==========================================================================
;
;	RAM Definition
;
;==========================================================================

	__MAXRAM H'1FF'
	__BADRAM H'11E'-H'1AF'
	__BADRAM H'1BF'
	__BADRAM H'1DA'-H'1DB'
	__BADRAM H'1E7'
	__BADRAM H'1EB'
	__BADRAM H'1EE'-H'1EF'
	__BADRAM H'1F7'-H'1FF'


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
