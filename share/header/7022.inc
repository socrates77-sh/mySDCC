

;mc32p7022 header file
;
; 

;define must write at first row

INDF0   EQU     0X180
INDF1   EQU     0X181
INDF2   EQU     0X182
HIBYTE  EQU     0X183
FSR0    EQU     0X184
FSR1    EQU     0X185
PCL     EQU     0X186
PFLAG   EQU     0X187
MCR     EQU     0X188
INDF3   EQU     0X189   
INTE0   EQU     0X18A
INTF0   EQU     0X18B
IOP0    EQU     0X190
OEP0    EQU     0X191
PUP0    EQU     0X192
PDP0    EQU     0X193
KBCR    EQU     0X197
T0CR0   EQU     0X1A0
T0CNT   EQU     0X1A1
T0LOAD  EQU     0X1A2
T00DATA EQU     0X1A3
T1CR    EQU     0X1A4
T1CNT   EQU     0X1A5
T1LOAD  EQU     0X1A6
T1DATA  EQU     0X1A7
T0CR1   EQU     0X1A8
T01DATA EQU     0X1A9
LXTCR   EQU     0X1AC
LVDCR   EQU     0X1AD
OSCM    EQU     0X1AE
ADCR0   EQU     0X1B0
ADCR1   EQU     0X1B1
ADCR2   EQU     0X1B2
ADIOS   EQU     0X1B3
ADRH    EQU     0X1B8
ADRL    EQU     0X1B9
KEYCR0  EQU     0X1BC
KEYCR1  EQU     0X1BD

#define		STATUS		PFLAG
#define		INDF		  INDF0
#define		FSR		    FSR0
#define		INTE		  INTE0
#define		INTF	    INTF0
#define		INTECON		INTE
#define		INTFLAG 	INTF

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

;----- STATUS Bits --------------------------
#define	Z	  STATUS,2
#define	DC	STATUS,1
#define	C	  STATUS,0

;----- MCR Bits --------------------------
#define	GIE	    MCR,7
#define	TO	    MCR,5
#define	PD	    MCR,4
#define	MINT11	MCR,3
#define	MINT10	MCR,2
#define	MINT01	MCR,1
#define	MINT00	MCR,0

;INDF3 
#define         INDF37          INDF3,7
#define         INDF36          INDF3,6
#define         INDF35          INDF3,5
#define         INDF34          INDF3,4
#define         INDF33          INDF3,3
#define         INDF32          INDF3,2
#define         INDF31          INDF3,1
#define         INDF30          INDF3,0 

;INTE0
#define         ADIE    INTE,6
#define         LVDIE   INTE,5
#define         KBIE    INTE,4
#define         INT1IE  INTE,3
#define         INT0IE  INTE,2
#define         T1IE    INTE,1
#define         T0IE    INTE,0

;INTF0
#define         ADIF    INTFLAG,6 
#define         LVDIF   INTFLAG,5
#define         KBIF    INTFLAG,4
#define         INT1IF  INTFLAG,3
#define         INT0IF  INTFLAG,2
#define         T1IF    INTFLAG,1
#define         T0IF    INTFLAG,0

;IOP0
#define         P07D  	        IOP0,7
#define         P06D  	        IOP0,6
#define         P05D  	        IOP0,5
#define         P04D  	        IOP0,4
#define         P03D  	        IOP0,3
#define         P02D  	        IOP0,2
#define         P01D  	        IOP0,1
#define         P00D	          IOP0,0

;OEP0
#define         P07OE           OEP0,7
#define         P06OE           OEP0,6
#define         P05OE           OEP0,5
#define         P04OE           OEP0,4
#define         P03OE           OEP0,3
#define         P02OE           OEP0,2
#define         P01OE           OEP0,1
#define         P00OE           OEP0,0

;PUP0
#define         P07PU           PUP0,7
#define         P06PU           PUP0,6
#define         P05PU           PUP0,5
#define         P04PU           PUP0,4
#define         P03PU           PUP0,3
#define         P02PU           PUP0,2
#define         P01PU           PUP0,1
#define         P00PU           PUP0,0

;PDP0
#define         P06PD           PDP0,6
#define         P05PD           PDP0,5
#define         P04PD           PDP0,4
#define         P03PD           PDP0,3
#define         P02PD           PDP0,2
#define         P01PD           PDP0,1
#define         P00PD           PDP0,0

;KBCR 
#define         KBCR7           KBCR,7
#define         KBCR6           KBCR,6
#define         KBCR5           KBCR,5
#define         KBCR4           KBCR,4
#define         KBCR3           KBCR,3
#define         KBCR2           KBCR,2
#define         KBCR1           KBCR,1
#define         KBCR0           KBCR,0	

;T0CR0
#define         TC0EN           T0CR0,7
#define         PWM00OE         T0CR0,6
#define         BUZ00OE         T0CR0,5
#define         T0PTS1          T0CR0,4
#define         T0PTS0          T0CR0,3
#define         T0PR2           T0CR0,2
#define         T0PR1           T0CR0,1
#define         T0PR0           T0CR0,0

;T0CR1
#define         PWM01OE         T0CR1,6
#define         BUZ01OE         T0CR1,5

;T0CNT
#define         T0C7            T0CNT,7
#define         T0C6            T0CNT,6
#define         T0C5            T0CNT,5
#define         T0C4            T0CNT,4
#define         T0C3            T0CNT,3
#define         T0C2            T0CNT,2
#define         T0C1            T0CNT,1
#define         T0C0            T0CNT,0

;T0LOAD
#define         T0LOAD7         T0LOAD,7
#define         T0LOAD6         T0LOAD,6
#define         T0LOAD5         T0LOAD,5
#define         T0LOAD4         T0LOAD,4
#define         T0LOAD3         T0LOAD,3
#define         T0LOAD2         T0LOAD,2
#define         T0LOAD1         T0LOAD,1
#define         T0LOAD0         T0LOAD,0

;T00DATA
#define         T00DATA7        T00DATA,7
#define         T00DATA6        T00DATA,6
#define         T00DATA5        T00DATA,5
#define         T00DATA4        T00DATA,4
#define         T00DATA3        T00DATA,3
#define         T00DATA2        T00DATA,2
#define         T00DATA1        T00DATA,1
#define         T00DATA0        T00DATA,0

;T01DATA
#define         T01DATA7        T01DATA,7
#define         T01DATA6        T01DATA,6
#define         T01DATA5        T01DATA,5
#define         T01DATA4        T01DATA,4
#define         T01DATA3        T01DATA,3
#define         T01DATA2        T01DATA,2
#define         T01DATA1        T01DATA,1
#define         T01DATA0        T01DATA,0

;T1CR
#define         TC1EN           T1CR,7
#define         PWM1OE          T1CR,6
#define         BUZ1OE          T1CR,5
#define         T1PTS1          T1CR,4
#define         T1PTS0          T1CR,3
#define	        T1PR2 	        T1CR,2
#define	        T1PR1 	        T1CR,1
#define	        T1PR0 	        T1CR,0

;T1CNT
#define         T1C7            T1CNT,7
#define         T1C6            T1CNT,6
#define         T1C5            T1CNT,5
#define         T1C4            T1CNT,4
#define         T1C3            T1CNT,3
#define         T1C2            T1CNT,2
#define         T1C1            T1CNT,1
#define         T1C0            T1CNT,0

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

;LXTCR
#define         VDLSEL  LXTCR,4
#define         FILS    LXTCR,3
#define         LPEN2   LXTCR,2
#define         LPEN1   LXTCR,1
#define         LPEN0   LXTCR,0

;-----  LVDCR Bits -------
#define         LVDEN	  LVDCR,7
#define	        LVDS3	  LVDCR,6
#define	        LVDS2	  LVDCR,5
#define	        LVDS1	  LVDCR,4
#define	        LVDS0	  LVDCR,3
#define	        LVDF	  LVDCR,0

;OSCM
#define         STBL    OSCM,5
#define         STBH    OSCM,4
#define         CLKS    OSCM,2
#define         LFEN    OSCM,1
#define         HFEN    OSCM,0

;ADCR0
#define         ADCHS3          ADCR0,6
#define         ADCHS2          ADCR0,5
#define         ADCHS1          ADCR0,4
#define         ADCHS0          ADCR0,3
#define	        ADEOC           ADCR0,1
#define	        ADST            ADCR0,1
#define	        ADON            ADCR0,0 

;ADCR1
#define         ADTEN           ADCR1,7
#define         ADREF3          ADCR1,6
#define         ADREF2          ADCR1,5
#define         ADREF1          ADCR1,4
#define         ADREF0          ADCR1,3
#define         ADCKS1          ADCR1,2
#define         ADCKS0          ADCR1,1

;ADCR2
#define         ADSMP3          ADCR2,3
#define         ADSMP2          ADCR2,2
#define         ADSMP1          ADCR2,1
#define         ADSMP0          ADCR2,0

;ADIOS
#define         ADIOS6          ADIOS,6
#define         ADIOS5          ADIOS,5
#define         ADIOS4          ADIOS,4
#define         ADIOS3          ADIOS,3
#define         ADIOS2          ADIOS,2
#define         ADIOS1          ADIOS,1
#define         ADIOS0          ADIOS,0   

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

;KEYCR0
#define         MOSDIS          KEYCR0,7
#define         KEYEN           KEYCR0,0

;KEYCR1
#define         CMPVS1          KEYCR1,7
#define         CMPVS0          KEYCR1,6
#define         KEYVS1          KEYCR1,5
#define         KEYVS0          KEYCR1,4
#define         DFILS1          KEYCR1,3
#define         DFILS0          KEYCR1,2
#define         CMPHYS          KEYCR1,1
#define         KEYFLG          KEYCR1,1 


