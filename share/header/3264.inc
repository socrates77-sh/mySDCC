

;mc32p64 header file
;
; 

;define must write at first row
       
INDF0   EQU     0X1B0
INDF1   EQU     0X1B1
INDF2   EQU     0X1B2
HIBYTE  EQU     0X1B3
FSR0    EQU     0X1B4
FSR1    EQU     0X1B5
PCL     EQU     0X1B6
PFLAG   EQU     0X1B7
MCR     EQU     0X1B8
INDF3   EQU     0X1B9   
INTE    EQU     0X1BA
INTF    EQU     0X1BB
OSCM    EQU     0X1BC
IOP0    EQU     0X1C0
OEP0    EQU     0X1C1
PUP0    EQU     0X1C2
IOP1    EQU     0X1C4
OEP1    EQU     0X1C5
PUP1    EQU     0X1C6
IOP2    EQU     0X1C8
OEP2    EQU     0X1C9
PUP2    EQU     0X1CA
IOP3    EQU     0X1CC
OEP3    EQU     0X1CD
PUP3    EQU     0X1CE
T0CR    EQU     0X1D0
T0CNT   EQU     0X1D1
T0LOAD  EQU     0X1D2
T0DATA  EQU     0X1D3
T1CR    EQU     0X1D4
T1CNT   EQU     0X1D5
T1LOAD  EQU     0X1D6
T1DATA  EQU     0X1D7
T2CR    EQU     0X1D8
T2CNTH  EQU     0X1D9
T2CNTL  EQU     0X1DA
T2LOADH EQU     0X1DB
T2LOADL EQU     0X1DC
TK0CRH  EQU     0X1E0
TK0CRL  EQU     0X1E1
TK0CNTH EQU     0X1E2
TK0CNTL EQU     0X1E3
TK1CRH  EQU     0X1E4
TK1CRL  EQU     0X1E5
TK1CNTH EQU     0X1E6
TK1CNTL EQU     0X1E7
TK2CRH  EQU     0X1E8
TK2CRL  EQU     0X1E9
TK2CNTH EQU     0X1EA
TK2CNTL EQU     0X1EB
ADCR0   EQU     0X1EC
ADCR1   EQU     0X1ED
ADIOS   EQU     0X1ED
ADRH    EQU     0X1EE
ADRL    EQU     0X1EF
I2CCR   EQU     0X1F0
I2CADDR EQU     0X1F1
I2CDATA EQU     0X1F2
OSCCAL  EQU     0X1FB

#define		STATUS		PFLAG
#define		INDF		  INDF0
#define		FSR		    FSR0
#define		INTECON		INTE
#define		INTFLAG	  INTF

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

;MCR 
#define         GIE       MCR,7
#define         T0        MCR,5
#define         PD        MCR,4
#define	        MINT11	  MCR,3
#define	        MINT10	  MCR,2
#define	        MINT01	  MCR,1
#define	        MINT00	  MCR,0 

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
#define         ADIE    INTECON,6
#define         I2CIE   INTECON,5
#define         T2IE    INTECON,4
#define         INT1IE  INTECON,3
#define         INT0IE  INTECON,2
#define         T1IE    INTECON,1
#define         T0IE    INTECON,0

;INTF
#define         ADIF    INTFLAG,6 
#define         I2CIF   INTFLAG,5
#define         T2IF    INTFLAG,4
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

;IOP1
#define         P17D  	        IOP1,7
#define         P16D  	        IOP1,6
#define         P15D  	        IOP1,5
#define         P14D	          IOP1,4
#define         P13D  	        IOP1,3
#define         P12D  	        IOP1,2
#define         P11D  	        IOP1,1
#define         P10D	          IOP1,0

;OEP1
#define         P17OE           OEP1,7
#define         P16OE           OEP1,6
#define         P15OE           OEP1,5
#define         P14OE           OEP1,4
#define         P13OE           OEP1,3
#define         P12OE           OEP1,2
#define         P11OE           OEP1,1
#define         P10OE           OEP1,0

;PUP1
#define         P17PU           PUP1,7
#define         P16PU           PUP1,6
#define         P15PU           PUP1,5
#define         P14PU           PUP1,4
#define         P13PU           PUP1,3
#define         P12PU           PUP1,2
#define         P11PU           PUP1,1
#define         P10PU           PUP1,0

;IOP2
#define         P27D  	        IOP2,7
#define         P26D  	        IOP2,6
#define         P25D  	        IOP2,5
#define         P24D  	        IOP2,4
#define         P23D  	        IOP2,3
#define         P22D  	        IOP2,2
#define         P21D  	        IOP2,1
#define         P20D	          IOP2,0

;OEP2
#define         P27OE           OEP2,7
#define         P26OE           OEP2,6
#define         P25OE           OEP2,5
#define         P24OE           OEP2,4
#define         P23OE           OEP2,3
#define         P22OE           OEP2,2
#define         P21OE           OEP2,1
#define         P20OE           OEP2,0

;PUP2
#define         P27PU           PUP2,7
#define         P26PU           PUP2,6
#define         P25PU           PUP2,5
#define         P24PU           PUP2,4
#define         P23PU           PUP2,3
#define         P22PU           PUP2,2
#define         P21PU           PUP2,1
#define         P20PU           PUP2,0

;IOP3
#define         P31D  	        IOP3,1
#define         P30D	          IOP3,0

;OEP3
#define         P31OE           OEP3,1
#define         P30OE           OEP3,0

;PUP3
#define         P31PU           PUP3,1
#define         P30PU           PUP3,0

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
#define         T1PS1           T1CR,4
#define         T1PS0           T1CR,3
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

;T2CR
#define			    TC2EN				    T2CR,7
#define 		    T2MODE			    T2CR,5
#define         T2PS1           T2CR,4
#define         T2PS0           T2CR,3
#define	        T2PR2 	        T2CR,2
#define	        T2PR1 	        T2CR,1
#define	        T2PR0 	        T2CR,0

;T2CNTH
#define         T2C15           T2CNTH,7
#define         T2C14           T2CNTH,6
#define         T2C13           T2CNTH,5
#define         T2C12           T2CNTH,4
#define         T2C11           T2CNTH,3
#define         T2C10           T2CNTH,2
#define         T2C9            T2CNTH,1
#define         T2C8            T2CNTH,0

;T2CNTL
#define         T2C7            T2CNTL,7
#define         T2C6            T2CNTL,6
#define         T2C5            T2CNTL,5
#define         T2C4            T2CNTL,4
#define         T2C3            T2CNTL,3
#define         T2C2            T2CNTL,2
#define         T2C1            T2CNTL,1
#define         T2C0            T2CNTL,0

;T2LOADH
#define         T2LOAD15        T2LOADH,7
#define         T2LOAD14        T2LOADH,6
#define         T2LOAD13        T2LOADH,5
#define         T2LOAD12        T2LOADH,4
#define         T2LOAD11        T2LOADH,3
#define         T2LOAD10        T2LOADH,2
#define         T2LOAD9         T2LOADH,1
#define         T2LOAD8         T2LOADH,0

;T2LOADL
#define         T2LOAD7         T2LOADL,7
#define         T2LOAD6         T2LOADL,6
#define         T2LOAD5         T2LOADL,5
#define         T2LOAD4         T2LOADL,4
#define         T2LOAD3         T2LOADL,3
#define         T2LOAD2         T2LOADL,2
#define         T2LOAD1         T2LOADL,1
#define         T2LOAD0         T2LOADL,0

;TK0CRH
#define					TK0K1		        TK0CRH,7
#define					TK0K0	          TK0CRH,6
#define					TK0JE		        TK0CRH,5
#define					TK0RCE	        TK0CRH,4
#define					TK0CLR	        TK0CRH,3
#define					TK0FQ2		      TK0CRH,2
#define					TK0FQ1	        TK0CRH,1
#define					TK0FQ0	        TK0CRH,0

;TK0CRL
#define					TK0IF		        TK0CRL,7
#define					TK0IE		        TK0CRL,6
#define					TK0FL1		      TK0CRL,5
#define					TK0FL0		      TK0CRL,4
#define					TK0IO3		      TK0CRL,3
#define					TK0IO2		      TK0CRL,2
#define					TK0IO1		      TK0CRL,1
#define					TK0IO0		      TK0CRL,0

;TK0CNTH
#define         TK0C15          TK0CNTH,7
#define         TK0C14          TK0CNTH,6
#define         TK0C13          TK0CNTH,5
#define         TK0C12          TK0CNTH,4
#define         TK0C11          TK0CNTH,3
#define         TK0C10          TK0CNTH,2
#define         TK0C9           TK0CNTH,1
#define         TK0C8           TK0CNTH,0

;TK0CNTL
#define         TK0C7           TK0CNTL,7
#define         TK0C6           TK0CNTL,6
#define         TK0C5           TK0CNTL,5
#define         TK0C4           TK0CNTL,4
#define         TK0C3           TK0CNTL,3
#define         TK0C2           TK0CNTL,2
#define         TK0C1           TK0CNTL,1
#define         TK0C0           TK0CNTL,0

;TK1CRH
#define					TK1K1		        TK1CRH,7
#define					TK1K0	          TK1CRH,6
#define					TK1JE		        TK1CRH,5
#define					TK1RCE	        TK1CRH,4
#define					TK1CLR	        TK1CRH,3
#define					TK1FQ2		      TK1CRH,2
#define					TK1FQ1	        TK1CRH,1
#define					TK1FQ0	        TK1CRH,0
					
;TK1CRL
#define					TK1IF		        TK1CRL,7
#define					TK1IE		        TK1CRL,6
#define					TK1FL1		      TK1CRL,5
#define					TK1FL0		      TK1CRL,4
#define					TK1IO3		      TK1CRL,3
#define					TK1IO2		      TK1CRL,2
#define					TK1IO1		      TK1CRL,1
#define					TK1IO0		      TK1CRL,0

;TK1CNTH
#define         TK1C15          TK1CNTH,7
#define         TK1C14          TK1CNTH,6
#define         TK1C13          TK1CNTH,5
#define         TK1C12          TK1CNTH,4
#define         TK1C11          TK1CNTH,3
#define         TK1C10          TK1CNTH,2
#define         TK1C9           TK1CNTH,1
#define         TK1C8           TK1CNTH,0

;TK1CNTL
#define         TK1C7           TK1CNTL,7
#define         TK1C6           TK1CNTL,6
#define         TK1C5           TK1CNTL,5
#define         TK1C4           TK1CNTL,4
#define         TK1C3           TK1CNTL,3
#define         TK1C2           TK1CNTL,2
#define         TK1C1           TK1CNTL,1
#define         TK1C0           TK1CNTL,0

;TK2CRH
#define					TK2K1		        TK2CRH,7
#define					TK2K0	          TK2CRH,6
#define					TK2JE		        TK2CRH,5
#define					TK2RCE	        TK2CRH,4
#define					TK2CLR	        TK2CRH,3
#define					TK2FQ2		      TK2CRH,2
#define					TK2FQ1	        TK2CRH,1
#define					TK2FQ0	        TK2CRH,0

;TK2CRL
#define					TK2IF		        TK2CRL,7
#define					TK2IE		        TK2CRL,6
#define					TK2FL1		      TK2CRL,5
#define					TK2FL0		      TK2CRL,4
#define					TK2IO3		      TK2CRL,3
#define					TK2IO2		      TK2CRL,2
#define					TK2IO1		      TK2CRL,1
#define					TK2IO0		      TK2CRL,0

;TK2CNTH
#define         TK2C15          TK2CNTH,7
#define         TK2C14          TK2CNTH,6
#define         TK2C13          TK2CNTH,5
#define         TK2C12          TK2CNTH,4
#define         TK2C11          TK2CNTH,3
#define         TK2C10          TK2CNTH,2
#define         TK2C9           TK2CNTH,1
#define         TK2C8           TK2CNTH,0

;TK2CNTL
#define         TK2C7           TK2CNTL,7
#define         TK2C6           TK2CNTL,6
#define         TK2C5           TK2CNTL,5
#define         TK2C4           TK2CNTL,4
#define         TK2C3           TK2CNTL,3
#define         TK2C2           TK2CNTL,2
#define         TK2C1           TK2CNTL,1
#define         TK2C0           TK2CNTL,0

;ADCR0
#define         ADCHS3          ADCR0,7
#define         ADCHS2          ADCR0,6
#define         ADCHS1          ADCR0,5
#define         ADCHS0          ADCR0,4
#define         ADCKS1          ADCR0,3
#define         ADCKS0          ADCR0,2
#define	        ADEOC           ADCR0,1
#define	        ADON            ADCR0,0 

;ADCR1
#define         ADIOS7          ADCR1,7
#define         ADIOS6          ADCR1,6
#define         ADIOS5          ADCR1,5
#define         ADIOS4          ADCR1,4
#define         ADIOS3          ADCR1,3
#define         ADIOS2          ADCR1,2
#define         ADIOS1          ADCR1,1
#define         ADIOS0          ADCR1,0   

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

;I2CCR
#define			    HCF			        I2CCR,7
#define			    HAAS		        I2CCR,6
#define			    HBB			        I2CCR,5
#define			    HTX			        I2CCR,4
#define			    TXAK		        I2CCR,3
#define			    SRW			        I2CCR,2
#define			    HEN			        I2CCR,1
#define			    RXAK		        I2CCR,0

;I2CADDR
#define         I2CAD7          I2CADDR,7
#define         I2CAD6          I2CADDR,6
#define         I2CAD5          I2CADDR,5
#define         I2CAD4          I2CADDR,4
#define         I2CAD3          I2CADDR,3
#define         I2CAD2          I2CADDR,2
#define         I2CAD1          I2CADDR,1
#define         I2CAD0          I2CADDR,0

;I2CDATA
#define         I2CDA7          I2CDATA,7
#define         I2CDA6          I2CDATA,6
#define         I2CDA5          I2CDATA,5
#define         I2CDA4          I2CDATA,4
#define         I2CDA3          I2CDATA,3
#define         I2CDA2          I2CDATA,2
#define         I2CDA1          I2CDATA,1
#define         I2CDA0          I2CDATA,0

;OSCCAL
#define         OSCCAL7         OSCCAL,7
#define         OSCCAL6         OSCCAL,6
#define         OSCCAL5         OSCCAL,5
#define         OSCCAL4         OSCCAL,4
#define         OSCCAL3         OSCCAL,3
#define         OSCCAL2         OSCCAL,2
#define         OSCCAL1         OSCCAL,1
#define         OSCCAL0         OSCCAL,0

