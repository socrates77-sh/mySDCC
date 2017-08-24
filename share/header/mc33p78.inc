
;mc33p78 header file
;define must write at first row

INDF    EQU     0X01B0       
INDF0   EQU     0X01B0
INDF1   EQU     0X01B1
INDF2   EQU     0X01B2
HIBYTE  EQU     0X01B3
FSR     EQU     0X01B4
FSR0    EQU     0X01B4
FSR1    EQU     0X1B5
PCL     EQU     0X1B6
PFLAG   EQU    0X1B7
STATUS  EQU     0X1B7
MCR     EQU     0X1B8
INDF3   EQU    0X1B9   
INTE    EQU     0X1BA
INTF    EQU     0X1BB
OSCM    EQU     0X1BC
;IOP0    EQU     0X1C0
;OEP0    EQU     0X1C1
;PUP0    EQU     0X1C2
;IOP1    EQU     0X1C4
;OEP1    EQU     0X1C5
;PUP1    EQU     0X1C6
IOP1    EQU     0X1C8
OEP1    EQU     0X1C9
PUP1    EQU     0X1CA

DKWP1    EQU     0X1CE

IOP2    EQU     0X1D0
OEP2    EQU     0X1D1
PUP2    EQU     0X1D2
;T0DATA  EQU     0X1D3
;T1CR    EQU     0X1D4
;T1CNT   EQU     0X1D5
DKWP2   EQU     0X1D6
KBCR    EQU     0X1D7
T0CR    EQU     0X1D8
T0LOADH EQU     0X1D9
T0LOADL  EQU     0X1DA
T0LATFL   EQU     0X1DB
T0LATFH EQU     0X1DC

T0LATRL  EQU     0X1DD
T0LATRH  EQU     0X1DE

T1CR    EQU     0X1E0
T1DATA  EQU     0X1E1
T1LOAD  EQU     0X1E2

OPCR0   EQU     0X1E4
OPCR1   EQU     0X1E5
DKW0    EQU     0X1E6
DKW1    EQU     0X1E7

;pflag bit 
#define         Z       PFLAG,2
#define         DC      PFLAG,1
#define         C       PFLAG,0 

;MCR
#define         GIE     MCR,7
#DEFINE         TO      MCR,5
#DEFINE         PD      MCR,4
#DEFINE         MINT11  MCR,3


;INTE
#define         KBIE    INTE,7
#DEFINE         INT1IE  INTE,3
#DEFINE         INT0IE  INTE,2
#DEFINE         T1IE    INTE,1
#define         T0IE    INTE,0

;INTF
#DEFINE         KBIF    INTF,7
#DEFINE         T0RF    INTF,6
#DEFINE         INT1IF  INTF,3
#DEFINE         INT0IF  INTF,2
#DEFINE         T1IF    INTF,1
#DEFINE         T0IF    INTF,0

;DKW0
#DEFINE         DKWE    DKW0,7
#DEFINE         IROS    DKW0,6
#DEFINE         IROT    DKW0,5         
#DEFINE         WSEL0   DKW0,4
#DEFINE         WSEL1   DKW0,3
#DEFINE         RSEL    DKW0,2
#DEFINE         ISEL1   DKW0,1
#define         ISEL0   DKW0,0 

#define					HFEN		OSCM,0
#define					LFEN		OSCM,1
#define					CLKS		OSCM,2
#define					STBH		OSCM,4
#DEFINE					STBL		OSCM,5

;T0CR
#DEFINE         TC0EN   T0CR,7
;#DEFINE  

;T1CR
#DEFINE         TC1EN   T1CR,7
         
    


