
;mc32p5212 header file
;define must write at first row

GOTOMTP macro x
        org 0x4000+x
        endm
       
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
INTE0   EQU     0X1BA
INTF0   EQU     0X1BB
OSCM    EQU     0X1BC
LVDCR   EQU     0X1BD

MTPADH  EQU     0X1C0
MTPADL  EQU     0X1C1
MTPDB   EQU     0X1C2
MTPMD   EQU     0X1C3
MTPCTR  EQU     0X1C4
IOP1    EQU     0X1C8
OEP1    EQU     0X1C9
PUP1    EQU     0X1CA
DKWP1   EQU     0X1CE

IOP2    EQU     0X1D0
OEP2    EQU     0X1D1
PUP2    EQU     0X1D2
DKWP2   EQU     0X1D6
T0CR    EQU     0X1D8
T0LOADH EQU     0X1D9
T0LOADL EQU     0X1DA
T0LATRH EQU     0X1DB
T0LATRL EQU     0X1DC
T0LATFH EQU     0X1DD
T0LATFL EQU     0X1DE

T1CR    EQU     0X1E0
T1DATA  EQU     0X1E1
T1LOAD  EQU     0X1E2

OPCR0   EQU     0X1E4
OPCR1   EQU     0X1E5
DKW0    EQU     0X1E6
DKW1    EQU     0X1E7

#define		STATUS		PFLAG
#define		INDF		  INDF0
#define		FSR		    FSR0
#define		INTE	    INTE0
#define		INTF  	  INTF0
#define		INTECON		INTE
#define		INTFLAG	  INTF

; ----- INDF0 Bits --------------------------------------------
#define INDF00          INDF0,0          /* bit 0 */
#define INDF01          INDF0,1        	/* bit 1 */
#define INDF02          INDF0,2          /* bit 2 */
#define INDF03          INDF0,3        	/* bit 3 */
#define INDF04          INDF0,4        	/* bit 4 */
#define INDF05          INDF0,5        	/* bit 5 */
#define INDF06          INDF0,6        	/* bit 6 */
#define INDF07          INDF0,7        	/* bit 7 */

; ----- INDF1 Bits --------------------------------------------
#define INDF10          INDF1,0          /* bit 0 */
#define INDF11          INDF1,1          /* bit 1 */
#define INDF12          INDF1,2          /* bit 2 */
#define INDF13          INDF1,3          /* bit 3 */
#define INDF14          INDF1,4          /* bit 4 */
#define INDF15          INDF1,5          /* bit 5 */
#define INDF16          INDF1,6          /* bit 6 */
#define INDF17          INDF1,7          /* bit 7 */

; ----- INDF2 Bits --------------------------------------------
#define INDF20          INDF2,0          /* bit 0 */
#define INDF21          INDF2,1          /* bit 1 */
#define INDF22          INDF2,2          /* bit 2 */
#define INDF23          INDF2,3          /* bit 3 */
#define INDF24          INDF2,4          /* bit 4 */
#define INDF25          INDF2,5          /* bit 5 */
#define INDF26          INDF2,6          /* bit 6 */
#define INDF27          INDF2,7          /* bit 7 */

; ----- HIBYTE Bits --------------------------------------------
#define HIBYTE0         HIBYTE,0         /* bit 0 */
#define HIBYTE1         HIBYTE,1         /* bit 1 */
#define HIBYTE2         HIBYTE,2         /* bit 2 */
#define HIBYTE3         HIBYTE,3         /* bit 3 */
#define HIBYTE4         HIBYTE,4         /* bit 4 */
#define HIBYTE5         HIBYTE,5         /* bit 5 */
#define HIBYTE6         HIBYTE,6         /* bit 6 */
#define HIBYTE7         HIBYTE,7         /* bit 7 */

; ----- FSR0 Bits ---------------------------------------------
#define FSR00           FSR0,0          /* bit 0 */
#define FSR01           FSR0,1          /* bit 1 */
#define FSR02           FSR0,2          /* bit 2 */
#define FSR03           FSR0,3          /* bit 3 */
#define FSR04           FSR0,4          /* bit 4 */
#define FSR05           FSR0,5          /* bit 5 */
#define FSR06           FSR0,6          /* bit 6 */
#define FSR07           FSR0,7          /* bit 7 */

; ----- FSR1 Bits ---------------------------------------------
#define FSR10           FSR1,0          /* bit 0 */
#define FSR11           FSR1,1          /* bit 1 */
#define FSR12           FSR1,2          /* bit 2 */
#define FSR13           FSR1,3          /* bit 3 */
#define FSR14           FSR1,4          /* bit 4 */
#define FSR15           FSR1,5          /* bit 5 */
#define FSR16           FSR1,6          /* bit 6 */
#define FSR17           FSR1,7          /* bit 7 */

; ----- PCL Bits ---------------------------------------------
#define PC0             PCL,0          /* bit 0 */
#define PC1             PCL,1          /* bit 1 */
#define PC2             PCL,2          /* bit 2 */
#define PC3             PCL,3          /* bit 3 */
#define PC4             PCL,4          /* bit 4 */
#define PC5             PCL,5          /* bit 5 */
#define PC6             PCL,6          /* bit 6 */
#define PC7             PCL,7          /* bit 7 */

;PFLAG bit 
#define         Z               PFLAG,2
#define         DC              PFLAG,1
#define         C               PFLAG,0 
                                
;MCR                            
#define         GIE             MCR,7
#define         TO              MCR,5
#define         PD              MCR,4
#define         MINT11          MCR,3
#define	        MINT10	        MCR,2
#define	        MINT01	        MCR,1
#define	        MINT00	        MCR,0 

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
#DEFINE         MTPIE           INTE,7                              
#DEFINE         LVDIE           INTE,5
#DEFINE         INT1IE          INTE,3
#DEFINE         INT0IE          INTE,2
#DEFINE         T1IE            INTE,1
#define         T0IE            INTE,0
                                
;INTF      
#DEFINE         MTPIF           INTF,7                     
#DEFINE         T0RF            INTF,6
#DEFINE         LVDIF           INTF,5
#DEFINE         INT1IF          INTF,3
#DEFINE         INT0IF          INTF,2
#DEFINE         T1IF            INTF,1
#DEFINE         T0IF            INTF,0
                                
;OSCM                           
#define         STBL            OSCM,5
#define         STBH            OSCM,4
#define         CLKS            OSCM,2
#define         LFEN            OSCM,1
#define         HFEN            OSCM,0

;LVDCR
#define         LVDEN           LVDCR,7
#define         LVDS            LVDCR,3
#define         LVDF            LVDCR,0 

;MTPADH                                  
#define         MTPAD9          MTPADH,5 
#define         MTPAD8          MTPADH,4 
#define         MTPAD7          MTPADH,3 
#define         MTPAD6          MTPADH,2 
#define         MTPAD5          MTPADH,1 
#define         MTPAD4          MTPADH,0 

;MTPADL                                  
#define         MTPAD3          MTPADL,3 
#define         MTPAD2          MTPADL,2 
#define         MTPAD1          MTPADL,1 
#define         MTPAD0          MTPADL,0 

;MTPDB
#define         MTPDB7 	        MTPDB,7
#define         MTPDB6 	        MTPDB,6
#define         MTPDB5 	        MTPDB,5
#define         MTPDB4 	        MTPDB,4
#define         MTPDB3 	        MTPDB,3
#define         MTPDB2 	        MTPDB,2
#define         MTPDB1 	        MTPDB,1
#define         MTPDB0          MTPDB,0

;MTPMD  
#define         MTPEN           MTPMD,7
#define         CHIPERS         MTPMD,4
#define         PAGEERS         MTPMD,3
#define         PAGEWR          MTPMD,2
#define         BYTEWR          MTPMD,1
#define         BYTERD          MTPMD,0

;MTPCTR
#define         MTPBUSY         MTPCTR,7
#define         MTPTOUT         MTPCTR,6
#define         MTPLD           MTPCTR,2
#define         MTPWR           MTPCTR,1
#define         MTPRD           MTPCTR,0

;IOP1
#define         P17D  	        IOP1,7
#define         P16D  	        IOP1,6
#define         P15D  	        IOP1,5
#define         P14D  	        IOP1,4
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
#define         P16PU           PUP1,6
#define         P15PU           PUP1,5
#define         P14PU           PUP1,4
#define         P13PU           PUP1,3
#define         P12PU           PUP1,2
#define         P11PU           PUP1,1
#define         P10PU           PUP1,0

;DKWP1
#define         P16DKW  	      DKWP1,6
#define         P15DKW  	      DKWP1,5
#define         P14DKW  	      DKWP1,4
#define         P13DKW  	      DKWP1,3
#define         P12DKW  	      DKWP1,2
#define         P11DKW  	      DKWP1,1
#define         P10DKW	        DKWP1,0

;IOP2
#define         P27D  	        IOP2,7
#define         P26D  	        IOP2,6
#define         P25D  	        IOP2,5
#define         P24D  	        IOP2,4
#define         P22D  	        IOP2,2
#define         P21D  	        IOP2,1

;OEP2
#define         P27OE           OEP2,7
#define         P26OE           OEP2,6
#define         P25OE           OEP2,5
#define         P24OE           OEP2,4
#define         P22OE           OEP2,2
#define         P21OE           OEP2,1

;PUP2
#define         P27PU           PUP2,7
#define         P26PU           PUP2,6
#define         P25PU           PUP2,5
#define         P24PU           PUP2,4
#define         P22PU           PUP2,2
#define         P21PU           PUP2,1

;DKWP2
#define         P27DKW  	      DKWP2,7
#define         P26DKW  	      DKWP2,6
#define         P25DKW  	      DKWP2,5
#define         P24DKW  	      DKWP2,4
#define         P22DKW  	      DKWP2,2
#define         P21DKW  	      DKWP2,1

;T0CR
#define         TC0EN           T0CR,7
#define         T0MOD1          T0CR,6
#define         T0MOD0          T0CR,5
#define         T0PS1           T0CR,4
#define         T0PS0           T0CR,3
#define         T0PR2           T0CR,2
#define         T0PR1           T0CR,1
#define         T0PR0           T0CR,0

;T0LOADH
#define         T0LOADH7        T0LOADH,7
#define         T0LOADH6        T0LOADH,6
#define         T0LOADH5        T0LOADH,5
#define         T0LOADH4        T0LOADH,4
#define         T0LOADH3        T0LOADH,3
#define         T0LOADH2        T0LOADH,2
#define         T0LOADH1        T0LOADH,1
#define         T0LOADH0        T0LOADH,0

;T0LOADL
#define         T0LOADL7        T0LOADL,7
#define         T0LOADL6        T0LOADL,6
#define         T0LOADL5        T0LOADL,5
#define         T0LOADL4        T0LOADL,4
#define         T0LOADL3        T0LOADL,3
#define         T0LOADL2        T0LOADL,2
#define         T0LOADL1        T0LOADL,1
#define         T0LOADL0        T0LOADL,0

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

;T1CR
#define         TC1EN           T1CR,7
#define         T1MOD1          T1CR,6
#define         T1MOD0          T1CR,5
#define         T1PS1           T1CR,4
#define         T1PS0           T1CR,3
#define	        T1PR2 	        T1CR,2
#define	        T1PR1 	        T1CR,1
#define	        T1PR0 	        T1CR,0

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

;OPCR0
#define         OPAE            OPCR0,7
#define         OPAM            OPCR0,6
#define         OPFC5           OPCR0,5
#define         OPFC4           OPCR0,4
#define         OPFC3           OPCR0,3
#define         OPFC2           OPCR0,2
#define         OPFC1           OPCR0,1
#define         OPFC0           OPCR0,0

;OPCR1
#define         IRIN            OPCR1,7
#define         VSEL            OPCR1,6
#define         FSEL1           OPCR1,3
#define         FSEL0           OPCR1,2
#define         CSEL1           OPCR1,1
#define         CSEL0           OPCR1,0

;DKW0
#define         DKWE            DKW0,7
#define         IROS            DKW0,6
#define         IROT            DKW0,5         
#define         WSEL0           DKW0,4
#define         WSEL1           DKW0,3
#define         RSEL            DKW0,2     

;DKW1
#define         IRES1           DKW1,5         
#define         IRES0           DKW1,4
#define         LSEL11          DKW1,3
#define         LSEL10          DKW1,2
#define         LSEL01          DKW1,1
#define         LSEL00          DKW1,0 