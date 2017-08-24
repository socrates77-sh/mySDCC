

;mc32p7022 header file
;
; 

;define must write at first row

INDF    EQU     0X180  
INDF0   EQU     0X180
INDF1   EQU     0X181
INDF2   EQU     0X182
HIBYTE  EQU     0X183
FSR     EQU     0X184
FSR0    EQU     0X184
FSR1    EQU     0X185
PCL     EQU     0X186
STATUS  EQU     0X187
MCR     EQU     0X188
INDF3   EQU     0X189   
INTE    EQU     0X18A
INTF    EQU     0X18B
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
ADVR0   EQU     0X1B4
ADVR1   EQU     0X1B5
ADVR2   EQU     0X1B6
ADRH    EQU     0X1B8
ADRL    EQU     0X1B9
KEYCR0  EQU     0X1BC
KEYCR1  EQU     0X1BD
OSCCAL  EQU     0X1FB



;MCR 
#define         GIE             MCR,7
#define         T0              MCR,5
#define         PD              MCR,4
;#define         MINT1
  

;STATUS bit 
#define         Z       STATUS,2
#define         DC      STATUS,1
#define         C       STATUS,0 


;INTE0
; 1=enable, 0=disable
#define         ADIE    INTE,6
#define         I2CIE   INTE,5
#define         T2IE    INTE,4
#define         INT1IE  INTE,3
#define         INT0IE  INTE,2
#define         T1IE    INTE,1
#define         T0IE    INTE,0

;TIME0
#define         TC0EN           T0CR,7
#define         PWM0OUT         T0CR,6
#define         BUZZ0OUT        T0CR,5
#define         T0PS1           T0CR,4
#define         T0PTS0          T0CR,3
;#define         T0PR2

;OSCM
#define         STBL    OSCM,5
#define         STBH    OSCM,4
#define         CLKS    OSCM,2
#define         LFEN    OSCM,1
#define         HFEN    OSCM,0          

;TIME0
#define         TC1EN           T1CR,7
#define         PWM1OUT         T1CR,6
#define         BUZZ1OUT        T1CR,5
#define         T1PS1           T1CR,4
#define         T1PTS0          T1CR,3

;INTFLAG
;1=active ,
#define         ADIF    INTFLAG,6 
#define         I2CIF   INTFLAG,5
#define         T2IF    INTFLAG,4
#define         INT1IF  INTFLAG,3
#define         INT0IF  INTFLAG,2
#define         T1IF    INTFLAG,1
#define         T0IF    INTFLAG,0


;-------------------------------------------------------
;timer2
;----------------------------
;T2CR
#define			TC2EN				T2CR,7
#define 		T2MODE			T2CR,6


;TK0CRH
#define					TK0JE		TK0CRH,5
#define					TK0RCE	TK0CRH,4
#define					TK0CLR	TK0CRH,3
;TK1CRH
#define					TK1JE		TK1CRH,5
#define					TK1RCE	TK1CRH,4
#define					TK1CLR	TK1CRH,3
;TK2CRH
#define					TK2JE		TK2CRH,5
#define					TK2RCE	TK2CRH,4
#define					TK2CLR	TK2CRH,3


;TKnCRL
#define					TK0IF		TK0CRL,7
#define					TK0IE		TK0CRL,6
					
;TKnCRL
#define					TK1IF		TK1CRL,7
#define					TK1IE		TK1CRL,6

;TKnCRL
#define					TK2IF		TK2CRL,7
#define					TK2IE		TK2CRL,6

;ADCR0
#define	        ADEOC   ADCR0,1
#define	        ADON    ADCR0,0      

;I2CCR
#define			HCF			I2CCR,7 ;data send end flag
#define			HAAS		I2CCR,6      ;addr matching flag 
#define			HBB			I2CCR,5				;
#define			HTX			I2CCR,4
#define			TXAK		I2CCR,3
#define			SRW			I2CCR,2
#define			HEN			I2CCR,1
#define			RXAK		I2CCR,0

;-------adc chanal----------------------------------------
#define         AD0     0X00
#define         AD1     0X10
#define         AD2     0X20
#define         AD3     0X30
#define         AD4     0X40
#define         AD5     0X50
#define         AD6     0X60
#define         AD7     0X70
#define         LDO     0X80
#define         AD_VDD          0XD0
#define         AD_VDD_4DIV     0XE0
#define         AD_VDD_2DIV     0XF0

