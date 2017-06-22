

;mc32p7311 header file
;
; 

;define must write at first row
       
INDF0   EQU     0x180
INDF1   EQU     0x181
INDF2   EQU     0x182
HIBYTE  EQU     0x183
FSR0    EQU     0x184
FSR1    EQU     0x185
PCL     EQU     0x186
PFLAG   EQU     0x187
MCR     EQU     0x188
INDF3   EQU     0x189   
INTE    EQU     0x18A
INTF    EQU     0x18B
DRVCR   EQU     0x18C
KBCR    EQU     0x18E

IOP0    EQU     0x190
OEP0    EQU     0x191
PUP0    EQU     0x192
PDP0    EQU     0x193
IOP1    EQU     0x194
OEP1    EQU     0x195
PUP1    EQU     0x196
PDP1    EQU     0x197

T0CR    EQU     0x198
T0CNT   EQU     0x199
T0LOAD  EQU     0x19A
T0DATA  EQU     0x19B
T1CR    EQU     0x19C
T1CNT   EQU     0x19D
T1LOAD  EQU     0x19E
T1DATA  EQU     0x19F

T2CR    EQU     0x1A0
T2CNT   EQU     0x1A1
T2LOAD  EQU     0x1A2
T2DATA  EQU     0x1A3
T3CR    EQU     0x1A4
T3CNT   EQU     0x1A5
T3LOAD  EQU     0x1A6

PWM0DE  EQU     0x1A8
PWM1DE  EQU     0x1A9
PWM2DE  EQU     0x1AA
PWMCR0  EQU     0x1AC
PWMCR1  EQU     0x1AD
OSCM    EQU     0x1AE
LVDCR   EQU     0x1AF

ADCR0   EQU     0x1B0
ADCR1   EQU     0x1B1
ADCR2   EQU     0x1B2

ADRH    EQU     0x1B4
ADRL    EQU     0x1B5
ANSEL0  EQU     0x1B6
ANSEL1  EQU     0x1B7

VBGCAL  EQU     0x1F8
OSCCALH EQU     0x1FB
OSCCALL EQU     0x1FC

#define		STATUS		PFLAG
#define		INDF		  INDF0
#define		FSR		    FSR0
#define		P0HCON		PUP0
#define		P1HCON		PUP1
#define		INTECON		INTE
#define		INTFLAG   INTF	


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

;pflag bit 
#define         Z               PFLAG,2
#define         DC              PFLAG,1
#define         C               PFLAG,0

;MCR 
#define         GIE             MCR,7
#define         T0              MCR,5
#define         PD              MCR,4
#define         MINT11          MCR,3
#define         MINT10          MCR,2
#define         MINT01          MCR,1
#define         MINT00          MCR,0

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
#define         T3IE    INTE,7
#define         ADIE    INTE,6
#define         T2IE    INTE,5
#define         KBIE    INTE,4
#define         INT1IE  INTE,3
#define         INT0IE  INTE,2
#define         T1IE    INTE,1
#define         T0IE    INTE,0

;INTF
#define         T3IF    INTFLAG,7
#define         ADIF    INTFLAG,6 
#define         T2IF    INTFLAG,5
#define         KBIF    INTFLAG,4
#define         INT1IF  INTFLAG,3
#define         INT0IF  INTFLAG,2
#define         T1IF    INTFLAG,1
#define         T0IF    INTFLAG,0

;DRVCR
#define         DRVS    DRVCR,7
#define         LDRVS   DRVCR,6 
#define         PDRVS   DRVCR,5
#define         PDRVS0  DRVCR,4
#define         PDLYS1  DRVCR,3
#define         PDLYS0  DRVCR,2
#define         PSPDS1  DRVCR,1
#define         PSPDS0  DRVCR,0

;KBCR
#define         KBCR6   KBCR,6 
#define         KBCR5   KBCR,5
#define         KBCR4   KBCR,4
#define         KBCR3   KBCR,3
#define         KBCR2   KBCR,2
#define         KBCR1   KBCR,1
#define         KBCR0   KBCR,0

;IOP0
#define         P05D    IOP0,5
#define         P04D    IOP0,4
#define         P03D    IOP0,3
#define         P02D    IOP0,2
#define         P01D    IOP0,1
#define         P00D    IOP0,0

;OEP0
#define         P05OE    OEP0,5
#define         P04OE    OEP0,4
#define         P03OE    OEP0,3
#define         P02OE    OEP0,2
#define         P01OE    OEP0,1
#define         P00OE    OEP0,0

;PUP0
#define         P05PU    PUP0,5
#define         P04PU    PUP0,4
#define         P03PU    PUP0,3
#define         P02PU    PUP0,2
#define         P01PU    PUP0,1
#define         P00PU    PUP0,0

;PDP0
#define         P05PD    PDP0,5
#define         P04PD    PDP0,4
#define         P03PD    PDP0,3
#define         P02PD    PDP0,2
#define         P01PD    PDP0,1
#define         P00PD    PDP0,0

;IOP1
#define         P17D    IOP1,7
#define         P16D    IOP1,6
#define         P15D    IOP1,5
#define         P14D    IOP1,4
#define         P13D    IOP1,3
#define         P12D    IOP1,2
#define         P11D    IOP1,1
#define         P10D    IOP1,0

;OEP1
#define         P17OE    OEP1,7
#define         P16OE    OEP1,6
#define         P15OE    OEP1,5
#define         P14OE    OEP1,4
#define         P13OE    OEP1,3
#define         P12OE    OEP1,2
#define         P11OE    OEP1,1
#define         P10OE    OEP1,0

;PUP1
#define         P17PU    PUP1,7
#define         P16PU    PUP1,6
#define         P15PU    PUP1,5
#define         P14PU    PUP1,4
#define         P13PU    PUP1,3
#define         P12PU    PUP1,2
#define         P11PU    PUP1,1
#define         P10PU    PUP1,0

;PDP1
#define         P17PD    PDP1,7
#define         P16PD    PDP1,6
#define         P15PD    PDP1,5
#define         P14PD    PDP1,4
#define         P13PD    PDP1,3
#define         P12PD    PDP1,2
#define         P11PD    PDP1,1
#define         P10PD    PDP1,0

;T0CR
#define         TC0EN           T0CR,7
#define         PWM0OE          T0CR,6
#define         BUZ0OE          T0CR,5
#define         T0PS1           T0CR,4
#define         T0PS0           T0CR,3
#define         T0PR2           T0CR,2
#define         T0PR1           T0CR,1
#define         T0PR0           T0CR,0

;T0CNT
#define         T0C7    T0CNT,7
#define         T0C6    T0CNT,6
#define         T0C5    T0CNT,5
#define         T0C4    T0CNT,4
#define         T0C3    T0CNT,3
#define         T0C2    T0CNT,2
#define         T0C1    T0CNT,1
#define         T0C0    T0CNT,0

;T0LOAD
#define         T0LOAD7    T0LOAD,7
#define         T0LOAD6    T0LOAD,6
#define         T0LOAD5    T0LOAD,5
#define         T0LOAD4    T0LOAD,4
#define         T0LOAD3    T0LOAD,3
#define         T0LOAD2    T0LOAD,2
#define         T0LOAD1    T0LOAD,1
#define         T0LOAD0    T0LOAD,0

;T0DATA
#define         T0DATA7    T0DATA,7
#define         T0DATA6    T0DATA,6
#define         T0DATA5    T0DATA,5
#define         T0DATA4    T0DATA,4
#define         T0DATA3    T0DATA,3
#define         T0DATA2    T0DATA,2
#define         T0DATA1    T0DATA,1
#define         T0DATA0    T0DATA,0

;T1CR
#define         TC1EN           T1CR,7
#define         PWM1OE          T1CR,6
#define         BUZ1OE          T1CR,5
#define         T1PS1           T1CR,4
#define         T1PS0           T1CR,3
#define         T1PR2           T1CR,2
#define         T1PR1           T1CR,1
#define         T1PR0           T1CR,0

;T1CNT
#define         T1C7    T1CNT,7
#define         T1C6    T1CNT,6
#define         T1C5    T1CNT,5
#define         T1C4    T1CNT,4
#define         T1C3    T1CNT,3
#define         T1C2    T1CNT,2
#define         T1C1    T1CNT,1
#define         T1C0    T1CNT,0

;T1LOAD
#define         T1LOAD7    T1LOAD,7
#define         T1LOAD6    T1LOAD,6
#define         T1LOAD5    T1LOAD,5
#define         T1LOAD4    T1LOAD,4
#define         T1LOAD3    T1LOAD,3
#define         T1LOAD2    T1LOAD,2
#define         T1LOAD1    T1LOAD,1
#define         T1LOAD0    T1LOAD,0

;T1DATA
#define         T1DATA7    T1DATA,7
#define         T1DATA6    T1DATA,6
#define         T1DATA5    T1DATA,5
#define         T1DATA4    T1DATA,4
#define         T1DATA3    T1DATA,3
#define         T1DATA2    T1DATA,2
#define         T1DATA1    T1DATA,1
#define         T1DATA0    T1DATA,0

;T2CR
#define         TC2EN           T2CR,7
#define         PWM2OE          T2CR,6
#define         BUZ2OE          T2CR,5
#define         T2PS1           T2CR,4
#define         T2PS0           T2CR,3
#define         T2PR2           T2CR,2
#define         T2PR1           T2CR,1
#define         T2PR0           T2CR,0

;T2CNT
#define         T2C7    T2CNT,7
#define         T2C6    T2CNT,6
#define         T2C5    T2CNT,5
#define         T2C4    T2CNT,4
#define         T2C3    T2CNT,3
#define         T2C2    T2CNT,2
#define         T2C1    T2CNT,1
#define         T2C0    T2CNT,0

;T2LOAD
#define         T2LOAD7    T2LOAD,7
#define         T2LOAD6    T2LOAD,6
#define         T2LOAD5    T2LOAD,5
#define         T2LOAD4    T2LOAD,4
#define         T2LOAD3    T2LOAD,3
#define         T2LOAD2    T2LOAD,2
#define         T2LOAD1    T2LOAD,1
#define         T2LOAD0    T2LOAD,0

;T2DATA
#define         T2DATA7    T2DATA,7
#define         T2DATA6    T2DATA,6
#define         T2DATA5    T2DATA,5
#define         T2DATA4    T2DATA,4
#define         T2DATA3    T2DATA,3
#define         T2DATA2    T2DATA,2
#define         T2DATA1    T2DATA,1
#define         T2DATA0    T2DATA,0

;T3CR
#define         TC3EN           T3CR,7
#define         T3PS1           T3CR,4
#define         T3PS0           T3CR,3
#define         T3PR2           T3CR,2
#define         T3PR1           T3CR,1
#define         T3PR0           T3CR,0

;T3CNT
#define         T3C7    T3CNT,7
#define         T3C6    T3CNT,6
#define         T3C5    T3CNT,5
#define         T3C4    T3CNT,4
#define         T3C3    T3CNT,3
#define         T3C2    T3CNT,2
#define         T3C1    T3CNT,1
#define         T3C0    T3CNT,0

;T3LOAD
#define         T3LOAD7    T3LOAD,7
#define         T3LOAD6    T3LOAD,6
#define         T3LOAD5    T3LOAD,5
#define         T3LOAD4    T3LOAD,4
#define         T3LOAD3    T3LOAD,3
#define         T3LOAD2    T3LOAD,2
#define         T3LOAD1    T3LOAD,1
#define         T3LOAD0    T3LOAD,0

;PWM0DE
#define         PWM0DE2    PWM0DE,2
#define         PWM0DE1    PWM0DE,1
#define         PWM0DE0    PWM0DE,0

;PWM1DE
#define         PWM1DE2    PWM1DE,2
#define         PWM1DE1    PWM1DE,1
#define         PWM1DE0    PWM1DE,0

;PWM2DE
#define         PWM2DE2    PWM2DE,2
#define         PWM2DE1    PWM2DE,1
#define         PWM2DE0    PWM2DE,0

;PWMCR0
#define         FPWMEN     PWMCR0,7
#define         PWM2INV    PWMCR0,6
#define         PWM1INV    PWMCR0,5
#define         PWM0INV    PWMCR0,4
#define         FPWMR1     PWMCR0,3
#define         FPWMR0     PWMCR0,2
#define         FPWMF1     PWMCR0,1
#define         FPWMF0     PWMCR0,0

;PWMCR1
#define         TMRCKS1    PWMCR1,4
#define         TMRCKS0    PWMCR1,3
#define         PMODE2     PWMCR1,2
#define         PMODE1     PWMCR1,1
#define         PMODE0     PWMCR1,0

;OSCM
#define         STBL    OSCM,5
#define         STBH    OSCM,4
#define         CLKS    OSCM,2
#define         LFEN    OSCM,1
#define         HFEN    OSCM,0          

;LVDCR
#define         LVDEN    LVDCR,7
#define         LVDS3    LVDCR,6
#define         LVDS2    LVDCR,5
#define         LVDS1    LVDCR,4
#define         LVDS0    LVDCR,3
#define         LVDF     LVDCR,0

;ADCR0
#define         ADCHS3    ADCR0,7
#define         ADCHS2    ADCR0,6
#define         ADCHS1    ADCR0,5
#define         ADCHS0    ADCR0,4
#define         ADLEN     ADCR0,3
#define         ADEOC     ADCR0,1
#define         ADON      ADCR0,0

;ADCR1
#define         ADCKS2    ADCR1,7
#define         ADCKS1    ADCR1,6
#define         ADCKS0    ADCR1,5
#define         ADTST     ADCR1,4
#define         RESS0     ADCR1,3
#define         VRS2      ADCR1,2
#define         VRS1      ADCR1,1
#define         VRS0      ADCR1,0

;ADCR2
#define         ADSMP3    ADCR2,3
#define         ADSMP2    ADCR2,2
#define         ADSMP1    ADCR2,1
#define         ADSMP0    ADCR2,0

;ADRH
#define         ADR11     ADRH,7
#define         ADR10     ADRH,6
#define         ADR9      ADRH,5
#define         ADR8      ADRH,4
#define         ADR7      ADRH,3
#define         ADR6      ADRH,2
#define         ADR5      ADRH,1
#define         ADR4      ADRH,0

;ADRL
#define         ADR3      ADRL,3
#define         ADR2      ADRL,2
#define         ADR1      ADRL,1
#define         ADR0      ADRL,0

;ANSEL0
#define         P12ANS    ANSEL0,7
#define         P11ANS    ANSEL0,6
#define         P05ANS    ANSEL0,5
#define         P04ANS    ANSEL0,4
#define         P03ANS    ANSEL0,3
#define         P02ANS    ANSEL0,2
#define         P01ANS    ANSEL0,1
#define         P00ANS    ANSEL0,0

;ANSEL1
#define         P15ANS    ANSEL1,1
#define         P14ANS    ANSEL1,0

;VBGCAL
#define         VBGCAL7    VBGCAL,7
#define         VBGCAL6    VBGCAL,6
#define         VBGCAL5    VBGCAL,5
#define         VBGCAL4    VBGCAL,4
#define         VBGCAL3    VBGCAL,3
#define         VBGCAL2    VBGCAL,2
#define         VBGCAL1    VBGCAL,1
#define         VBGCAL0    VBGCAL,0

;OSCCALL
#define         OSCCAL7    OSCCALL,7
#define         OSCCAL6    OSCCALL,6
#define         OSCCAL5    OSCCALL,5
#define         OSCCAL4    OSCCALL,4
#define         OSCCAL3    OSCCALL,3
#define         OSCCAL2    OSCCALL,2
#define         OSCCAL1    OSCCALL,1
#define         OSCCAL0    OSCCALL,0

;OSCCALH
#define         OSCCAL10   OSCCALH,2
#define         OSCCAL9    OSCCALH,1
#define         OSCCAL8    OSCCALH,0
