

;mc33p116 header file 


;define must write at first row

INDF    EQU     0X1B0       
INDF0    EQU     0X1B0
INDF1    EQU     0X1B1
INDF2    EQU     0X1B2
HIBYTE   EQU     0X1B3
FSR     EQU     0X1B4
FSR0     EQU     0X1B4
FSR1     EQU     0X1B5
PCL      EQU     0X1B6
STATUS    EQU     0X1B7
PFLAG    EQU     0X1B7

MCR      EQU     0X1B8
INDF3    EQU     0X1B9   
INTE     EQU     0X1BA
INTF     EQU     0X1BB
OSCM     EQU     0X1BC
LVDCR    EQU     0X1BD
LXTCR    EQU     0X1BE

IOP0     EQU     0X1C0
OEP0     EQU     0X1C1
PUP0     EQU     0X1C2
DKWP0    EQU     0X1C3
IOP1     EQU     0X1C4
OEP1     EQU     0X1C5
PUP1     EQU     0X1C6
LCDIOSP1 EQU     0X1C7

IOP2     EQU     0X1C8
OEP2     EQU     0X1C9
PUP2     EQU     0X1CA
LCDIOSP2 EQU     0X1CB
IOP3     EQU     0X1CC
OEP3     EQU     0X1CD
PUP3     EQU     0X1CE
LCDIOSP3 EQU     0X1CF

IOP4     EQU     0X1D0
OEP4     EQU     0X1D1
PUP4     EQU     0X1D2
LCDIOSP4 EQU     0X1D3
IOP5     EQU     0X1D4
OEP5     EQU     0X1D5
PUP5     EQU     0X1D6
LCDIOSP5 EQU     0X1D7

T0CR0    EQU     0X1D8
T0CR1    EQU     0X1D9
T0LOADH  EQU     0X1DC
T0LOADL  EQU     0X1DD
T0DATAH  EQU     0X1DE
T0DATAL  EQU     0X1DF

T0LATRH  EQU     0X1E0
T0LATRL  EQU     0X1E1
T0LATFH  EQU     0X1E2
T0LATFL  EQU     0X1E3
T1CR     EQU     0X1E4
T1DATA   EQU     0X1E5
T1LOAD   EQU     0X1E6

ADCR0    EQU     0X1E8
ADCR1    EQU     0X1E9
ADCR2    EQU     0X1EA
ADDRH    EQU     0X1EC
ADDRL    EQU     0X1ED

OPCR0    EQU     0X1F0
OPCR1    EQU     0X1F1
LCDCR0   EQU     0X1F2
LCDCR1   EQU     0X1F3
DKW      EQU     0X1F4
KBCR     EQU     0X1F5
LCDDRV   EQU     0X1F6

#define		INTECON		INTE
#define		INTFLAG	  INTF
#define		ADRH		  ADDRH
#define		ADRL   	  ADDRL

;INDF0 
#define         INDF07          INDF0,7
#define         INDF06          INDF0,6
#define         INDF05          INDF0,5
#define         INDF04          INDF0,4
#define         INDF03          INDF0,3
#define         INDF02          INDF0,2
#define         INDF01          INDF0,1
#define         INDF00          INDF0,0 

;INDF1 
#define         INDF17          INDF1,7
#define         INDF16          INDF1,6
#define         INDF15          INDF1,5
#define         INDF14          INDF1,4
#define         INDF13          INDF1,3
#define         INDF12          INDF1,2
#define         INDF11          INDF1,1
#define         INDF10          INDF1,0

;INDF2 
#define         INDF27          INDF2,7
#define         INDF26          INDF2,6
#define         INDF25          INDF2,5
#define         INDF24          INDF2,4
#define         INDF23          INDF2,3
#define         INDF22          INDF2,2
#define         INDF21          INDF2,1
#define         INDF20          INDF2,0 

;HIBYTE
#define         HIBYTE7         HIBYTE,7
#define         HIBYTE6         HIBYTE,6
#define         HIBYTE5         HIBYTE,5
#define         HIBYTE4         HIBYTE,4
#define         HIBYTE3         HIBYTE,3
#define         HIBYTE2         HIBYTE,2
#define         HIBYTE1         HIBYTE,1
#define         HIBYTE0         HIBYTE,0

;FSR0 
#define         FSR07           FSR0,7
#define         FSR06           FSR0,6
#define         FSR05           FSR0,5
#define         FSR04           FSR0,4
#define         FSR03           FSR0,3
#define         FSR02           FSR0,2
#define         FSR01           FSR0,1
#define         FSR00           FSR0,0 

;FSR1
#define         FSR17           FSR1,7
#define         FSR16           FSR1,6
#define         FSR15           FSR1,5
#define         FSR14           FSR1,4
#define         FSR13           FSR1,3
#define         FSR12           FSR1,2
#define         FSR11           FSR1,1
#define         FSR10           FSR1,0

;PCL 
#define         PC7             PCL,7
#define         PC6             PCL,6
#define         PC5             PCL,5
#define         PC4             PCL,4
#define         PC3             PCL,3
#define         PC2             PCL,2
#define         PC1             PCL,1
#define         PC0             PCL,0

;PFLAG
#define         Z			PFLAG,2
#define         DC		PFLAG,1
#define         C			PFLAG,0

;MCR 
#define         GIE       MCR,7
#define         TO        MCR,5
#define         PD        MCR,4
#define         MINT11		MCR,3
#define         MINT10		MCR,2
#define         MINT01		MCR,1
#define         MINT00		MCR,0

;INDF3 
#define         INDF37          INDF3,7
#define         INDF36          INDF3,6
#define         INDF35          INDF3,5
#define         INDF34          INDF3,4
#define         INDF33          INDF3,3
#define         INDF32          INDF3,2
#define         INDF31          INDF3,1
#define         INDF30          INDF3,0 

;INTE
#define         ADIE    INTE,7
#define         LVDIE   INTE,5
#define         KBIE    INTE,4
#define         INT1IE  INTE,3
#define         INT0IE  INTE,2
#define         T1IE    INTE,1
#define         T0IE    INTE,0

;INTFLAG
#define         ADIF    INTFLAG,7 
#define         T0RF    INTFLAG,6
#define         LVDIF   INTFLAG,5
#define         KBIF    INTFLAG,4
#define         INT1IF  INTFLAG,3
#define         INT0IF  INTFLAG,2
#define         T1IF    INTFLAG,1
#define         T0IF    INTFLAG,0

;OSCM
#define         STBL    OSCM,5
#define         STBH    OSCM,4
#define         CLKS    OSCM,2
#define         LFEN    OSCM,1
#define         HFEN    OSCM,0 

;LVDCR
#define         LVDEN   LVDCR,7 
#define         LVDS3   LVDCR,6
#define         LVDS2   LVDCR,5
#define         LVDS1   LVDCR,4
#define         LVDS0   LVDCR,3
#define         LVDF    LVDCR,0

;LXTCR
#define         VDLSEL  LXTCR,4
#define         FILS    LXTCR,3
#define         LPEN2   LXTCR,2
#define         LPEN1   LXTCR,1
#define         LPEN0   LXTCR,0

;IOP0
#define         P07D  	        IOP0,7
#define         P06D  	        IOP0,6
#define         P05D  	        IOP0,5
#define         P04D  	        IOP0,4
#define         P03D  	        IOP0,3
#define         P02D  	        IOP0,2
#define         P01D  	        IOP0,1
#define         P00D	          IOP0,0

;IOP1
#define         P17D  	        IOP1,7
#define         P16D  	        IOP1,6
#define         P15D  	        IOP1,5
#define         P14D  	        IOP1,4
#define         P13D  	        IOP1,3
#define         P12D  	        IOP1,2
#define         P11D  	        IOP1,1
#define         P10D	          IOP1,0

;IOP2
#define         P27D  	        IOP2,7
#define         P26D  	        IOP2,6
#define         P25D  	        IOP2,5
#define         P24D  	        IOP2,4
#define         P23D  	        IOP2,3
#define         P22D  	        IOP2,2
#define         P21D  	        IOP2,1
#define         P20D	          IOP2,0

;IOP3
#define         P37D  	        IOP3,7
#define         P36D  	        IOP3,6
#define         P35D  	        IOP3,5
#define         P34D  	        IOP3,4
#define         P33D  	        IOP3,3
#define         P32D  	        IOP3,2
#define         P31D  	        IOP3,1
#define         P30D	          IOP3,0

;IOP4
#define         P47D  	        IOP4,7
#define         P46D  	        IOP4,6
#define         P45D  	        IOP4,5
#define         P44D  	        IOP4,4
#define         P43D  	        IOP4,3
#define         P42D  	        IOP4,2
#define         P41D  	        IOP4,1
#define         P40D	          IOP4,0

;IOP5
#define         P55D  	        IOP5,5
#define         P54D  	        IOP5,4
#define         P53D  	        IOP5,3
#define         P52D  	        IOP5,2
#define         P51D  	        IOP5,1
#define         P50D	          IOP5,0

;OEP0
#define         P07OE           OEP0,7
#define         P06OE           OEP0,6
#define         P05OE           OEP0,5
#define         P04OE           OEP0,4
#define         P03OE           OEP0,3
#define         P02OE           OEP0,2
#define         P01OE           OEP0,1
#define         P00OE           OEP0,0

;OEP1
#define         P17OE           OEP1,7
#define         P16OE           OEP1,6
#define         P15OE           OEP1,5
#define         P14OE           OEP1,4
#define         P13OE           OEP1,3
#define         P12OE           OEP1,2
#define         P11OE           OEP1,1
#define         P10OE           OEP1,0

;OEP2
#define         P27OE           OEP2,7
#define         P26OE           OEP2,6
#define         P25OE           OEP2,5
#define         P24OE           OEP2,4
#define         P23OE           OEP2,3
#define         P22OE           OEP2,2
#define         P21OE           OEP2,1
#define         P20OE           OEP2,0

;OEP3
#define         P37OE           OEP3,7
#define         P36OE           OEP3,6
#define         P35OE           OEP3,5
#define         P34OE           OEP3,4
#define         P33OE           OEP3,3
#define         P32OE           OEP3,2
#define         P31OE           OEP3,1
#define         P30OE           OEP3,0

;OEP4
#define         P47OE           OEP4,7
#define         P46OE           OEP4,6
#define         P45OE           OEP4,5
#define         P44OE           OEP4,4
#define         P43OE           OEP4,3
#define         P42OE           OEP4,2
#define         P41OE           OEP4,1
#define         P40OE           OEP4,0

;OEP5
#define         P55OE           OEP5,5
#define         P54OE           OEP5,4
#define         P53OE           OEP5,3
#define         P52OE           OEP5,2
#define         P51OE           OEP5,1
#define         P50OE           OEP5,0

;PUP0
#define         P07PU           PUP0,7
#define         P06PU           PUP0,6
#define         P05PU           PUP0,5
#define         P04PU           PUP0,4
#define         P03PU           PUP0,3
#define         P02PU           PUP0,2
#define         P01PU           PUP0,1
#define         P00PU           PUP0,0

;PUP1
#define         P17PU           PUP1,7
#define         P16PU           PUP1,6
#define         P15PU           PUP1,5
#define         P14PU           PUP1,4
#define         P13PU           PUP1,3
#define         P12PU           PUP1,2
#define         P11PU           PUP1,1
#define         P10PU           PUP1,0

;PUP2
#define         P27PU           PUP2,7
#define         P26PU           PUP2,6
#define         P25PU           PUP2,5
#define         P24PU           PUP2,4
#define         P23PU           PUP2,3
#define         P22PU           PUP2,2
#define         P21PU           PUP2,1
#define         P20PU           PUP2,0

;PUP3
#define         P37PU           PUP3,7
#define         P36PU           PUP3,6
#define         P35PU           PUP3,5
#define         P34PU           PUP3,4
#define         P33PU           PUP3,3
#define         P32PU           PUP3,2
#define         P31PU           PUP3,1
#define         P30PU           PUP3,0

;PUP4
#define         P47PU           PUP4,7
#define         P46PU           PUP4,6
#define         P45PU           PUP4,5
#define         P44PU           PUP4,4
#define         P43PU           PUP4,3
#define         P42PU           PUP4,2
#define         P41PU           PUP4,1
#define         P40PU           PUP4,0

;PUP5
#define         P55PU           PUP5,5
#define         P54PU           PUP5,4
#define         P53PU           PUP5,3
#define         P52PU           PUP5,2
#define         P51PU           PUP5,1
#define         P50PU           PUP5,0

;DKWP0
#define         P07DKW  	      DKWP0,7
#define         P06DKW  	      DKWP0,6
#define         P05DKW  	      DKWP0,5
#define         P04DKW  	      DKWP0,4
#define         P03DKW  	      DKWP0,3
#define         P02DKW  	      DKWP0,2
#define         P01DKW  	      DKWP0,1
#define         P00DKW	        DKWP0,0

;LCDIOSP1 
#define         LCDIOSP17       LCDIOSP1,7
#define         LCDIOSP16       LCDIOSP1,6
#define         LCDIOSP15       LCDIOSP1,5
#define         LCDIOSP14       LCDIOSP1,4
#define         LCDIOSP13       LCDIOSP1,3
#define         LCDIOSP12       LCDIOSP1,2
#define         LCDIOSP11       LCDIOSP1,1
#define         LCDIOSP10       LCDIOSP1,0 

;LCDIOSP2 
#define         LCDIOSP27       LCDIOSP2,7
#define         LCDIOSP26       LCDIOSP2,6
#define         LCDIOSP25       LCDIOSP2,5
#define         LCDIOSP24       LCDIOSP2,4
#define         LCDIOSP23       LCDIOSP2,3
#define         LCDIOSP22       LCDIOSP2,2
#define         LCDIOSP21       LCDIOSP2,1
#define         LCDIOSP20       LCDIOSP2,0 

;LCDIOSP3 
#define         LCDIOSP37       LCDIOSP3,7
#define         LCDIOSP36       LCDIOSP3,6
#define         LCDIOSP35       LCDIOSP3,5
#define         LCDIOSP34       LCDIOSP3,4
#define         LCDIOSP33       LCDIOSP3,3
#define         LCDIOSP32       LCDIOSP3,2
#define         LCDIOSP31       LCDIOSP3,1
#define         LCDIOSP30       LCDIOSP3,0

;LCDIOSP4 
#define         LCDIOSP47       LCDIOSP4,7
#define         LCDIOSP46       LCDIOSP4,6
#define         LCDIOSP45       LCDIOSP4,5
#define         LCDIOSP44       LCDIOSP4,4
#define         LCDIOSP43       LCDIOSP4,3
#define         LCDIOSP42       LCDIOSP4,2
#define         LCDIOSP41       LCDIOSP4,1
#define         LCDIOSP40       LCDIOSP4,0

;LCDIOSP5 
#define         LCDIOSP51       LCDIOSP5,1
#define         LCDIOSP50       LCDIOSP5,0   

;-------------------------------------------------------
;timer0
;----------------------------
;T0CR0
#define			TC0EN				T0CR0,7
#define 		T0MOD1			T0CR0,6
#define			T0MOD0			T0CR0,5
#define 		T0PTS1			T0CR0,4
#define			T0PTS0			T0CR0,3
#define 		T0PR2 			T0CR0,2
#define			T0PR1				T0CR0,1
#define 		T0PR0 			T0CR0,0

;T0CR1
#define			FPWMEN 			T0CR1,7
#define 		PWMEN  			T0CR1,6
#define 		FPWMS 			T0CR1,4
#define			FPWMA1			T0CR1,3
#define 		FPWMA0 			T0CR1,2
#define			FPWMB1			T0CR1,1
#define 		FPWMB0 			T0CR1,0

;T0LOADH
#define         T0LOADH7         T0LOADH,7
#define         T0LOADH6         T0LOADH,6
#define         T0LOADH5         T0LOADH,5
#define         T0LOADH4         T0LOADH,4
#define         T0LOADH3         T0LOADH,3
#define         T0LOADH2         T0LOADH,2
#define         T0LOADH1         T0LOADH,1
#define         T0LOADH0         T0LOADH,0

;T0LOADL
#define         T0LOADL7         T0LOADL,7
#define         T0LOADL6         T0LOADL,6
#define         T0LOADL5         T0LOADL,5
#define         T0LOADL4         T0LOADL,4
#define         T0LOADL3         T0LOADL,3
#define         T0LOADL2         T0LOADL,2
#define         T0LOADL1         T0LOADL,1
#define         T0LOADL0         T0LOADL,0

;T0DATAH
#define         T0DATAH7         T0DATAH,7
#define         T0DATAH6         T0DATAH,6
#define         T0DATAH5         T0DATAH,5
#define         T0DATAH4         T0DATAH,4
#define         T0DATAH3         T0DATAH,3
#define         T0DATAH2         T0DATAH,2
#define         T0DATAH1         T0DATAH,1
#define         T0DATAH0         T0DATAH,0

;T0DATAL
#define         T0DATAL7         T0DATAL,7
#define         T0DATAL6         T0DATAL,6
#define         T0DATAL5         T0DATAL,5
#define         T0DATAL4         T0DATAL,4
#define         T0DATAL3         T0DATAL,3
#define         T0DATAL2         T0DATAL,2
#define         T0DATAL1         T0DATAL,1
#define         T0DATAL0         T0DATAL,0

;T0LATFH
#define         T0LATFH7        T0LATFH,7
#define         T0LATFH6        T0LATFH,6
#define         T0LATFH5        T0LATFH,5
#define         T0LATFH4        T0LATFH,4
#define         T0LATFH3        T0LATFH,3
#define         T0LATFH2        T0LATFH,2
#define         T0LATFH1        T0LATFH,1
#define         T0LATFH0        T0LATFH,0

;T0LATFL
#define         T0LATFL7        T0LATFL,7
#define         T0LATFL6        T0LATFL,6
#define         T0LATFL5        T0LATFL,5
#define         T0LATFL4        T0LATFL,4
#define         T0LATFL3        T0LATFL,3
#define         T0LATFL2        T0LATFL,2
#define         T0LATFL1        T0LATFL,1
#define         T0LATFL0        T0LATFL,0

;T0LATRH
#define         T0LATRH7        T0LOADH,7
#define         T0LATRH6        T0LOADH,6
#define         T0LATRH5        T0LOADH,5
#define         T0LATRH4        T0LOADH,4
#define         T0LATRH3        T0LOADH,3
#define         T0LATRH2        T0LOADH,2
#define         T0LATRH1        T0LOADH,1
#define         T0LATRH0        T0LOADH,0

;T0LATRL
#define         T0LATRL7        T0LATRL,7
#define         T0LATRL6        T0LATRL,6
#define         T0LATRL5        T0LATRL,5
#define         T0LATRL4        T0LATRL,4
#define         T0LATRL3        T0LATRL,3
#define         T0LATRL2        T0LATRL,2
#define         T0LATRL1        T0LATRL,1
#define         T0LATRL0        T0LATRL,0

;-------------------------------------------------------
;timer1
;----------------------------
;T1CR
#define			TC1EN 			T1CR,7
#define 		T1MOD1 			T1CR,6
#define			T1MOD0 			T1CR,5
#define 		T1PTS1 			T1CR,4
#define			T1PTS0			T1CR,3
#define 		T1PR2 			T1CR,2
#define			T1PR1 			T1CR,1
#define 		T1PR0 			T1CR,0

;T1LOAD
#define         T1LOAD7         T1LOAD,7
#define         T1LOAD6         T1LOAD,6
#define         T1LOAD5         T1LOAD,5
#define         T1LOAD4         T1LOAD,4
#define         T1LOAD3         T1LOAD,3
#define         T1LOAD2         T1LOAD,2
#define         T1LOAD1         T1LOAD,1
#define         T1LOAD0         T1LOAD,0

;T1DATA
#define         T1DATA7         T1DATA,7
#define         T1DATA6         T1DATA,6
#define         T1DATA5         T1DATA,5
#define         T1DATA4         T1DATA,4
#define         T1DATA3         T1DATA,3
#define         T1DATA2         T1DATA,2
#define         T1DATA1         T1DATA,1
#define         T1DATA0         T1DATA,0

;ADCR0
#define					ADCHS3		ADCR0,7
#define					ADCHS2  	ADCR0,6
#define					ADCHS1  	ADCR0,5
#define					ADCHS0		ADCR0,4
#define					ADCKS1 		ADCR0,3
#define					ADCKS0  	ADCR0,2
#define					ADEOC  		ADCR0,1
#define					ADON			ADCR0,0

;ADCR1
#define					ADIOS7		ADCR1,7
#define					ADIOS6  	ADCR1,6
#define					ADIOS5  	ADCR1,5
#define					ADIOS4		ADCR1,4
#define					ADIOS3 		ADCR1,3
#define					ADIOS2  	ADCR1,2
#define					ADIOS1 		ADCR1,1
#define					ADIOS0		ADCR1,0

;ADCR2
#define					VREFRES 	ADCR2,1
#define					VREXT			ADCR2,0

;ADRH
#define         ADR11           ADRH,7
#define         ADR10           ADRH,6
#define         ADR9            ADRH,5
#define         ADR8            ADRH,4
#define         ADR7            ADRH,3
#define         ADR6            ADRH,2
#define         ADR5            ADRH,1
#define         ADR4            ADRH,0

;ADRL
#define         ADR3            ADRL,3
#define         ADR2            ADRL,2
#define         ADR1            ADRL,1
#define         ADR0            ADRL,0 

;OPCR0
#define					OPAE  		OPCR0,7
#define					OPAM    	OPCR0,6
#define					OPFC5   	OPCR0,5
#define					OPFC4 		OPCR0,4
#define					OPFC3  		OPCR0,3
#define					OPFC2   	OPCR0,2
#define					OPFC1  		OPCR0,1
#define					OPFC0			OPCR0,0

;OPCR1
#define					IRIN  		OPCR1,7
#define					VSEL    	OPCR1,6
#define					FSEL1 		OPCR1,3
#define					FSEL0   	OPCR1,2
#define					CSEL1 		OPCR1,1
#define					CSEL0		  OPCR1,0

;LCDCR0
#define					LCDEN		    LCDCR0,7
#define					LCDSP1	    LCDCR0,6
#define					LCDSP0	    LCDCR0,5
#define					LCDDUTY	    LCDCR0,4
#define					VLCDS		    LCDCR0,3
#define					LCDSPEED		LCDCR0,2
#define					LCDRS1	    LCDCR0,1
#define					LCDRS0		  LCDCR0,0

;LCDCR1
#define					LCDM		    LCDCR1,3
#define					LCDCKS  		LCDCR1,2
#define					FLCD1	      LCDCR1,1
#define					FLCD0		    LCDCR1,0

;DKW
#define					DKWE		DKW,7
#define					IROS  	DKW,6
#define					IROT  	DKW,5
#define					WSEL1		DKW,4
#define					WSEL0 	DKW,3
#define					RSEL  	DKW,2
#define					DRVS  	DKW,1
#define					DSELEN	DKW,0

;KBCR
#define         KBCR7          KBCR,7
#define         KBCR6          KBCR,6
#define         KBCR5          KBCR,5
#define         KBCR4          KBCR,4
#define         KBCR3          KBCR,3
#define         KBCR2          KBCR,2
#define         KBCR1          KBCR,1
#define         KBCR0          KBCR,0

;LCDDRV
#define         LCDDRVP23      LCDDRV,2
#define         LCDDRVP22      LCDDRV,1
#define         LCDDRVP06      LCDDRV,0

