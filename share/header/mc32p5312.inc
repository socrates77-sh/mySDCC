

;mc32p5312 header file 


;define must write at first row

INDF    EQU     0x01B0       
INDF0   EQU     0X01B0
INDF1   EQU     0X01B1
INDF2   EQU     0X01B2
HIBYTE  EQU     0X01B3
FSR     EQU     0x01B4
FSR0    EQU     0X01B4
FSR1    EQU     0X01B5
PCL     EQU     0X01B6
STATUS  EQU     0X01B7
MCR     EQU     0X01B8
INDF3   EQU     0X01B9   
INTE    EQU     0X01BA
INTF    EQU     0X01BB
OSCM    EQU     0X01BC
LVDCR   EQU     0X01BD
LXTCR   EQU     0X01BE

IOP0    EQU     0X01C0
OEP0    EQU     0X01C1
PUP0    EQU     0X01C2
DKWP0   EQU     0X01C3
IOP1    EQU     0X01C4
OEP1    EQU     0X01C5
PUP1    EQU     0X01C6
DKWP1   EQU     0X01C7
T0CR    EQU     0X01C8
T0CNT   EQU     0X01C9
T0LOAD  EQU     0X01CA
T0DATA  EQU     0X01CB
T1CR    EQU     0X01CC
T1CNT   EQU     0X01CD
T1LOAD  EQU     0X01CE
T1DATA  EQU	0X01CF

LCDCR0  EQU     0X01D0
LCDCR1  EQU     0X01D1
LCDISP0 EQU     0X01D2
LCDISP1 EQU     0X01D3
DKW     EQU     0X01D4


;INDF0
#define         INDF07    INDF0,7
#define         INDF06    INDF0,6
#define         INDF05    INDF0,5
#define         INDF04    INDF0,4
#define         INDF03    INDF0,3
#define         INDF02    INDF0,2
#define         INDF01    INDF0,1
#define         INDF00    INDF0,0

;INDF1
#define         INDF17    INDF1,7
#define         INDF16    INDF1,6
#define         INDF15    INDF1,5
#define         INDF14    INDF1,4
#define         INDF13    INDF1,3
#define         INDF12    INDF1,2
#define         INDF11    INDF1,1
#define         INDF10    INDF1,0

;INDF2
#define         INDF27    INDF2,7
#define         INDF26    INDF2,6
#define         INDF25    INDF2,5
#define         INDF24    INDF2,4
#define         INDF23    INDF2,3
#define         INDF22    INDF2,2
#define         INDF21    INDF2,1
#define         INDF20    INDF2,0

;HIBYTE
#define         HIBYTE7   HIBYTE,7
#define         HIBYTE6   HIBYTE,6
#define         HIBYTE5   HIBYTE,5
#define         HIBYTE4   HIBYTE,4
#define         HIBYTE3   HIBYTE,3
#define         HIBYTE2   HIBYTE,2
#define         HIBYTE1   HIBYTE,1
#define         HIBYTE0   HIBYTE,0

;FSR0
#define         FSR07     FSR0,7
#define         FSR06     FSR0,6
#define         FSR05     FSR0,5
#define         FSR04     FSR0,4
#define         FSR03     FSR0,3
#define         FSR02     FSR0,2
#define         FSR01     FSR0,1
#define         FSR00     FSR0,0

;FSR1
#define         FSR17     FSR1,7
#define         FSR16     FSR1,6
#define         FSR15     FSR1,5
#define         FSR14     FSR1,4
#define         FSR13     FSR1,3
#define         FSR12     FSR1,2
#define         FSR11     FSR1,1
#define         FSR10     FSR1,0

;PCL
#define         PC7       PCL,7
#define         PC6       PCL,6
#define         PC5       PCL,5
#define         PC4       PCL,4
#define         PC3       PCL,3
#define         PC2       PCL,2
#define         PC1       PCL,1
#define         PC0       PCL,0

;STATUS
#define         Z         STATUS,2
#define         DC        STATUS,1
#define         C         STATUS,0

;MCR 
#define         GIE       MCR,7
#define         TO        MCR,5
#define         PD        MCR,4
#define         MINT11    MCR,3
#define         MINT10    MCR,2
#define         MINT01    MCR,1
#define         MINT00    MCR,0

;INDF3
#define         INDF37    INDF3,7
#define         INDF36    INDF3,6
#define         INDF35    INDF3,5
#define         INDF34    INDF3,4
#define         INDF33    INDF3,3
#define         INDF32    INDF3,2
#define         INDF31    INDF3,1
#define         INDF30    INDF3,0 

;INTE
; 1=enable, 0=disable
;#define         ADIE      INTE,7
#define         LVDIE     INTE,5
;#define         KBIE      INTE,4
#define         INT1IE    INTE,3
#define         INT0IE    INTE,2
#define         T1IE      INTE,1
#define         T0IE      INTE,0

;INTF
;1=active ,
;#define         ADIF      INTF,7 
;#define         T0RF      INTF,6
#define         LVDIF     INTF,5
;#define         KBIF      INTF,4
#define         INT1IF    INTF,3
#define         INT0IF    INTF,2
#define         T1IF      INTF,1
#define         T0IF      INTF,0

;OSCM
#define         STBL      OSCM,5
#define         STBH      OSCM,4
#define         CLKS      OSCM,2
#define         LFEN      OSCM,1
#define         HFEN      OSCM,0

;LVDCR
#define         LVDEN     LVDCR,7
#define         LVDS3     LVDCR,6
#define         LVDS2     LVDCR,5
#define         LVDS1     LVDCR,4
#define         LVDS0     LVDCR,3
#define         LVDF      LVDCR,0

;LXTCR
#define         VDSEL     LXTCR,4
#define         FILS      LXTCR,3
#define         LPEN2     LXTCR,2
#define         LPEN1     LXTCR,1
#define         LPEN0     LXTCR,0

;IOP0
#define	        IOP07     IOP0,7
#define         IOP06  	  IOP0,6
#define         IOP05  	  IOP0,5
#define         IOP04	    IOP0,4
#define         IOP03 	  IOP0,3
#define         IOP02  	  IOP0,2
#define         IOP01 	  IOP0,1
#define         IOP00	    IOP0,0

;OEP0
#define         P07OE     OEP0,7
#define         P06OE     OEP0,6
#define         P05OE     OEP0,5
#define         P04OE     OEP0,4
#define         P03OE     OEP0,3
#define         P02OE     OEP0,2
#define         P01OE     OEP0,1
#define         P00OE     OEP0,0

;PUP0
#define         P07PU     PUP0,7
#define         P06PU     PUP0,6
#define         P05PU     PUP0,5
#define         P04PU     PUP0,4
#define         P03PU     PUP0,3
#define         P02PU     PUP0,2
#define         P01PU     PUP0,1
#define         P00PU     PUP0,0

;DKWP0
#define         P07DKW    DKWP0,7
#define         P06DKW    DKWP0,6
#define         P05DKW    DKWP0,5
#define         P04DKW    DKWP0,4
#define         P03DKW    DKWP0,3
#define         P02DKW    DKWP0,2
#define         P01DKW    DKWP0,1
#define         P00DKW    DKWP0,0

;IOP1
#define         IOP17	  IOP1,7
#define         IOP16  	  IOP1,6
#define         IOP15  	  IOP1,5
#define         IOP14	  IOP1,4
#define         IOP13 	  IOP1,3
#define         IOP12  	  IOP1,2
#define         IOP11 	  IOP1,1
#define         IOP10	  IOP1,0

;OEP1
#define         P17OE     OEP1,7
#define         P16OE     OEP1,6
#define         P15OE     OEP1,5
#define         P14OE     OEP1,4
#define         P13OE     OEP1,3
#define         P12OE     OEP1,2
#define         P11OE     OEP1,1
#define         P10OE     OEP1,0

;PUP1
#define         P17PU     PUP1,7
#define         P16PU     PUP1,6
#define         P15PU     PUP1,5
#define         P14PU     PUP1,4
#define         P13PU     PUP1,3
#define         P12PU     PUP1,2
#define         P11PU     PUP1,1
#define         P10PU     PUP1,0

;DKWP1
#define         P17DKW    DKWP1,7
#define         P16DKW    DKWP1,6
#define         P15DKW    DKWP1,5
#define         P14DKW    DKWP1,4
#define         P13DKW    DKWP1,3
#define         P12DKW    DKWP1,2
#define         P11DKW    DKWP1,1
#define         P10DKW    DKWP1,0

;-------------------------------------------------------
;timer0
;----------------------------
;T0CR
#define         TC0EN     T0CR,7
#define         PWM0OE    T0CR,6
#define         BUZ0OE    T0CR,5
#define         T0PTS1    T0CR,4
#define         T0PTS0    T0CR,3
#define         T0PR2     T0CR,2
#define         T0PR1     T0CR,1
#define         T0PR0     T0CR,0

;T0CNT
#define         T0C7      T0CNT,7
#define         T0C6      T0CNT,6
#define         T0C5      T0CNT,5
#define         T0C4      T0CNT,4
#define         T0C3      T0CNT,3
#define         T0C2      T0CNT,2
#define         T0C1      T0CNT,1
#define         T0C0      T0CNT,0

;T0LOAD
#define         T0LOAD7   T0LOAD,7
#define         T0LOAD6   T0LOAD,6
#define         T0LOAD5   T0LOAD,5
#define         T0LOAD4   T0LOAD,4
#define         T0LOAD3   T0LOAD,3
#define         T0LOAD2   T0LOAD,2
#define         T0LOAD1   T0LOAD,1
#define         T0LOAD0   T0LOAD,0

;T0DATA
#define         T0DATA7   T0DATA,7
#define         T0DATA6   T0DATA,6
#define         T0DATA5   T0DATA,5
#define         T0DATA4   T0DATA,4
#define         T0DATA3   T0DATA,3
#define         T0DATA2   T0DATA,2
#define         T0DATA1   T0DATA,1
#define         T0DATA0   T0DATA,0

;-------------------------------------------------------
;timer1
;----------------------------
;T1CR
#define         TC1EN     T1CR,7
#define         PWM1OE    T1CR,6
#define         BUZ1OE    T1CR,5
#define         T1PTS1    T1CR,4
#define         T1PTS0    T1CR,3
#define         T1PR2     T1CR,2
#define         T1PR1     T1CR,1
#define         T1PR0     T1CR,0

;T1CNT
#define         T1C7      T1CNT,7
#define         T1C6      T1CNT,6
#define         T1C5      T1CNT,5
#define         T1C4      T1CNT,4
#define         T1C3      T1CNT,3
#define         T1C2      T1CNT,2
#define         T1C1      T1CNT,1
#define         T1C0      T1CNT,0

;T1LOAD
#define         T1LOAD7   T1LOAD,7
#define         T1LOAD6   T1LOAD,6
#define         T1LOAD5   T1LOAD,5
#define         T1LOAD4   T1LOAD,4
#define         T1LOAD3   T1LOAD,3
#define         T1LOAD2   T1LOAD,2
#define         T1LOAD1   T1LOAD,1
#define         T1LOAD0   T1LOAD,0

;T1DATA
#define         T1DATA7   T1DATA,7
#define         T1DATA6   T1DATA,6
#define         T1DATA5   T1DATA,5
#define         T1DATA4   T1DATA,4
#define         T1DATA3   T1DATA,3
#define         T1DATA2   T1DATA,2
#define         T1DATA1   T1DATA,1
#define         T1DATA0   T1DATA,0

;LCDCR0
#define         LCDEN     LCDCR0,5
#define         LCDSP1    LCDCR0,4
#define         LCDSP0	  LCDCR0,3
#define         LCDSPEED  LCDCR0,2
#define         LCDRS1	  LCDCR0,1
#define         LCDRS0    LCDCR0,0

;LCDCR1
#define         LCDLED    LCDCR1,4
#define         LCDM      LCDCR1,3
#define         LCDCKS    LCDCR1,2
#define         FLCD1     LCDCR1,1
#define         FLCD0     LCDCR1,0

;LCDSP0
#define         LCDSP04   LCDSP0,4
#define         LCDSP03   LCDSP0,3

;LCDSP1
#define         LCDSP16   LCDSP1,6
#define         LCDSP15   LCDSP1,5
#define         LCDSP14   LCDSP1,4
#define         LCDSP13   LCDSP1,3
#define         LCDSP12   LCDSP1,2
#define         LCDSP11   LCDSP1,1
#define         LCDSP10   LCDSP1,0

;DKW
#define         DKWE      DKW,5
#define         WSEL1     DKW,4
#define         WSEL0 	  DKW,3
#define         RSEL  	  DKW,2
#define         IROUTEN   DKW,1
#define         IROUTS    DKW,0
