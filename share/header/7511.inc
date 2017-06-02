

;mc32p7511 header file
;
; 

;define must write at first row
       
INDF0       EQU     0x180
INDF1       EQU     0x181
INDF2       EQU     0x182
HIBYTE      EQU     0x183
FSR0        EQU     0x184
FSR1        EQU     0x185
PCL         EQU     0x186
PFLAG       EQU     0x187
MCR         EQU     0x188
INDF3       EQU     0x189   
INTE0       EQU     0x18A
INTF0       EQU     0x18B
IOP0        EQU     0x190
OEP0        EQU     0x191
PUP0        EQU     0x192
PDP0        EQU     0x193
IOP1        EQU     0x194
OEP1        EQU     0x195
PUP1        EQU     0x196
PDP1        EQU     0x197
PWM0DE      EQU     0x198
PWM1DE      EQU     0x199
T0CR        EQU     0x1A0
T0CNT       EQU     0x1A1
T0LOAD      EQU     0x1A2
T0DATA      EQU     0x1A3
T1CR        EQU     0x1A4
T1CNT       EQU     0x1A5
T1LOAD      EQU     0x1A6
T1DATA      EQU     0x1A7
AUCR        EQU     0x1A8
KBCR        EQU     0x1A9
OSCM        EQU     0x1AE
LVDCR       EQU     0x1AF
ADCR0       EQU     0x1B0
ADCR1       EQU     0x1B1
AN0SEL      EQU     0x1B2
AN1SEL      EQU     0x1B3
ADRH        EQU     0x1B4
ADRL        EQU     0x1B5
ADCR2       EQU     0x1B6
OSCCAL      EQU     0x1FA

#define         STATUS          PFLAG
#define         INDF              INDF0
#define         FSR                 FSR0
#define         P0HCON          PUP0
#define         P1HCON          PUP1
#define         INTECON         INTE
#define         INTFLAG   INTF

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
#define         Z               PFLAG,2
#define         DC              PFLAG,1
#define         C               PFLAG,0

;MCR 
#define         GIE             MCR,7
#define         TO              MCR,5
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

;INTE0
#define         ADIE            INTE0,6
#define         LVDIE           INTE0,5
#define         KBIE            INTE0,4
#define         INT1IE          INTE0,3
#define         INT0IE          INTE0,2
#define         T1IE            INTE0,1
#define         T0IE            INTE0,0

;INTF0
#define         ADIF            VREFH,6
#define         LVDIF           VREFH,5
#define         KBIF            VREFH,4
#define         INT1IF          VREFH,3
#define         INT0IF          VREFH,2
#define         T1IF            VREFH,1
#define         T0IF            VREFH,0

;IOP0
#define         P06D  	        IOP0,6
#define         P05D  	        IOP0,5
#define         P04D	          IOP0,4
#define         P03D  	        IOP0,3
#define         P02D  	        IOP0,2
#define         P01D  	        IOP0,1
#define         P00D	          IOP0,0

;OEP0
#define         P06OE           OEP0,6
#define         P05OE           OEP0,5
#define         P04OE           OEP0,4
#define         P03OE           OEP0,3
#define         P02OE           OEP0,2
#define         P01OE           OEP0,1
#define         P00OE           OEP0,0

;PUP0
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

;IOP1
#define         P16D  	        IOP1,6
#define         P15D  	        IOP1,5
#define         P14D	          IOP1,4
#define         P13D  	        IOP1,3
#define         P12D  	        IOP1,2
#define         P11D  	        IOP1,1
#define         P10D	          IOP1,0

;OEP1
#define         P16OE           OEP1,6
#define         P15OE           OEP1,5
#define         P14OE           OEP1,4
#define         P13OE           OEP1,3
#define         P12OE           OEP1,2
#define         P11OE           OEP1,1
#define         P10OE           OEP1,0

;PUP1
#define         P16PU           PUP1,6
#define         P15PU           PUP1,5
#define         P14PU           PUP1,4
#define         P13PU           PUP1,3
#define         P12PU           PUP1,2
#define         P11PU           PUP1,1
#define         P10PU           PUP1,0

;PDP1
#define         P16PD           PDP1,6
#define         P15PD           PDP1,5
#define         P14PD           PDP1,4
#define         P13PD           PDP1,3
#define         P12PD           PDP1,2
#define         P11PD           PDP1,1
#define         P10PD           PDP1,0

;PWM0DE
#define         PWM0INV         PWM0DE,4
#define         PMODE0          PWM0DE,3
#define         PWM0DE2         PWM0DE,2
#define         PWM0DE1         PWM0DE,1
#define         PWM0DE0         PWM0DE,0

;PWM1DE
#define         PWM1INV         PWM1DE,4
#define         PMODE1          PWM1DE,3
#define         PWM1DE2         PWM1DE,2
#define         PWM1DE1         PWM1DE,1
#define         PWM1DE0         PWM1DE,0

;T0CR
#define         TC0EN           T0CR,7
#define         PWM0OE          T0CR,6
#define         BUZ0OE          T0CR,5
#define         T0PTS1          T0CR,4
#define         T0PTS0          T0CR,3
#define         T0PR2           T0CR,2
#define         T0PR1           T0CR,1
#define         T0PR0           T0CR,0

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

;T0DATA
#define         T0DATA7         T0DATA,7
#define         T0DATA6         T0DATA,6
#define         T0DATA5         T0DATA,5
#define         T0DATA4         T0DATA,4
#define         T0DATA3         T0DATA,3
#define         T0DATA2         T0DATA,2
#define         T0DATA1         T0DATA,1
#define         T0DATA0         T0DATA,0

;T1CR
#define         TC1EN           T1CR,7
#define         PWM1OE          T1CR,6
#define         BUZ1OE          T1CR,5
#define         T1PTS1          T1CR,4
#define         T1PTS0          T1CR,3
#define         T1PR2           T1CR,2
#define         T1PR1           T1CR,1
#define         T1PR0           T1CR,0

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

;AUCR
#define         DRVEN           AUCR,7
#define         SPDSL           AUCR,6
#define         P04WP           AUCR,5
#define         P13SP           AUCR,4
#define         P01DV           AUCR,3
#define         P11DV           AUCR,2
#define         PMOS1ON         AUCR,1
#define         NMOS0ON         AUCR,0

;KBCR
#define         KBCR6           KBCR,6
#define         KBCR5           KBCR,5
#define         KBCR4           KBCR,4
#define         KBCR3           KBCR,3
#define         KBCR2           KBCR,2
#define         KBCR1           KBCR,1
#define         KBCR0           KBCR,0

;OSCM
#define         STBL            OSCM,5
#define         STBH            OSCM,4
#define         CLKS            OSCM,2
#define         LFEN            OSCM,1
#define         HFEN            OSCM,0

;LVDCR
#define         LVDEN           LVDCR,7
#define         LVDS3           LVDCR,6
#define         LVDS2           LVDCR,5
#define         LVDS1           LVDCR,4
#define         LVDS0           LVDCR,3
#define         LVDF            LVDCR,0

;ADCR0
#define         ADCHS3          ADCR0,7
#define         ADCHS2          ADCR0,6
#define         ADCHS1          ADCR0,5
#define         ADCHS0          ADCR0,4
#define         ADLEN           ADCR0,3
#define         ADEOC           ADCR0,1
#define         ADON            ADCR0,0

;ADCR1
#define         ADCKS2          ADCR1,7
#define         ADCKS1          ADCR1,6
#define         ADCKS0          ADCR1,5
#define         ADTST           ADCR1,4
#define         RESS0           ADCR1,3
#define         VRS2            ADCR1,2
#define         VRS1            ADCR1,1
#define         VRS0            ADCR1,0

;ADCR2
#define         ADSMP3          ADCR2,3
#define         ADSMP2          ADCR2,2
#define         ADSMP1          ADCR2,1
#define         ADSMP0          ADCR2,0

;AN0SEL
#define         P06ANS          AN0SEL,6
#define         P05ANS          AN0SEL,5
#define         P04ANS          AN0SEL,4
#define         P03ANS          AN0SEL,3
#define         P02ANS          AN0SEL,2
#define         P01ANS          AN0SEL,1
#define         P00ANS          AN0SEL,0

;AN1SEL
#define         P16ANS          AN1SEL,6
#define         P15ANS          AN1SEL,5
#define         P14ANS          AN1SEL,4
#define         P13ANS          AN1SEL,3
#define         P12ANS          AN1SEL,2
#define         P11ANS          AN1SEL,1
#define         P10ANS          AN1SEL,0

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
