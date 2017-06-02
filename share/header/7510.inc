
;MC32P7510.INC  Standard Header File, Version 1.00 by Sinomcu

;----- Register Files------------------------------------------------------
INDF0		EQU    	0x180
INDF1		EQU    	0x181	
INDF2		EQU    	0x182	
HIBYTE	EQU    	0x183		
FSR0		EQU    	0x184	
FSR1		EQU    	0x185	
PCL			EQU    	0x186
PFLAG		EQU    	0x187	

MCR			EQU    	0x188
INDF3		EQU    	0x189	
INTE0		EQU    	0x18a	
INTF0		EQU    	0x18b	

IOP0		EQU    	0x190	
OEP0    EQU    	0x191                
PUP0    EQU    	0x192       
PDP0    EQU    	0x193
IOP1    EQU    	0x194                  
OEP1    EQU    	0x195                
PUP1    EQU    	0x196                
PDP1    EQU    	0x197      
                                 
T0CR		EQU    	0x1a0	
T0CNT   EQU    	0x1a1                
T0LOAD  EQU    	0x1a2                
T0DATA  EQU    	0x1a3                
T1CR    EQU    	0x1a4                
T1CNT   EQU    	0x1a5                
T1LOAD  EQU    	0x1a6                
T1DATA  EQU    	0x1a7                
                      
AUCR    EQU    	0x1a8
KBCR    EQU    	0x1a9                  
OSCM    EQU    	0x1ae                
LVDCR   EQU    	0x1af               

ADCR0		EQU    	0x1b0	
ADCR1   EQU    	0x1b1                
AN0SEL  EQU    	0x1b2                
AN1SEL  EQU    	0x1b3                 
ADRH    EQU    	0x1b4                                  
ADRL    EQU    	0x1b5
          
OSCCAL	EQU	    0x1fb

#define		STATUS		PFLAG
#define		INDF		  INDF0
#define		FSR		    FSR0
#define		P0HCON		PUP0
#define		P1HCON		PUP1
#define		INTECON		INTE0
#define		INTEFLAG	INTF0	

;----- STATUS Bits --------------------------
#define	Z	STATUS,2
#define	DC	STATUS,1
#define	C	STATUS,0

;----- MCR Bits --------------------------
#define	GIE	MCR,7

;-----  P2HCON Bits -----------------------
#define	P20PH	P2HCON,0
#define	P21PH	P2HCON,1
#define	P22PH	P2HCON,2
#define	P23PH	P2HCON,3
#define	P24PH	P2HCON,4
#define	P25PH	P2HCON,5
#define	P26PH	P2HCON,6
#define	P27PH	P2HCON,7
;----- INTECON Bits --------------------------
#define	INTE	INTECON
#define	ADIE	INTECON,6
#define	KBIE	INTECON,4
#define	INT1IE	 INTECON,3
#define	INT0IE	 INTECON,2
#define	T1IE	INTECON,1
#define	T0IE	INTECON,0

;----- INTEFLAG Bits --------------------------
#define	INTF	INTEFLAG
#define	ADIF	INTF,6
#define	KBIF	INTF,4
#define	INT1IF	INTF,3
#define	INT0IF	INTF,2
#define	T1IF	INTF,1
#define	T0IF	INTF,0
;----- UCR Bits--------------------------
#define	OPEN	UCR,4
#define	EPEN	UCR,3
#define	UARTEN	UCR,2
;----- UFR ----------------------
#define FREF	UFR,7
#define	PAEF	UFR,6
#define	OVEF	UFR,5
#define	TSEF	UFR,4
#define	RDAF	UFR,1
#define	TREF	UFR,0
;---- ADCR0 Bits -----------------
#define	   ADCKS_16	0<<1	;Fcpu/16
#define	   ADCKS_8 	1<<1	;Fcpu/8
#define	   ADCKS_4 	2<<1	;Fcpu/4
#define	   ADCKS_2 	2<<1	;Fcpu/2
#define	   ADCHS_0	0<<4	;AN0
#define	   ADCHS_1	1<<4	;AN1
#define	   ADCHS_2	2<<4	;AN2
#define	   ADCHS_3	3<<4	;AN3
#define	   ADCHS_4	4<<4	;AN4
#define	   ADCHS_5	5<<4	;AN5
#define	   ADCHS_6	6<<4	;AN6
#define 	ADEN		ADCR0,0
#define	ADEOC		ADCR0,1
;---- ADCR1 Bits -----------------
#define	   ADV_ADD	3	;VDD
#define	   ADV_4V	2	;4V
#define	   ADV_3V	1	;3V
#define	   ADV_2V	0	;2V
#define	   ADV_EX	4	;外部参考电压
;----- LCDCR0 Bits --------------------------
#define	LCDEN	LCDCR0,7
#define	VLCDS	LCDCR0,3
;----- T0CR  Bits ----------------
#define	TC0EN	T0CR,7
#define	PWM0OUT	T0CR,6
#define	BUZ0OUT	T0CR,5

;----- T1CR  Bits ----------------
#define	TC1EN	T1CR,7
#define	PWM1OUT	T1CR,6
#define	BUZ1OUT	T1CR,5

;----- OSCM  Bits ----------------
#define	STBL	OSCM,5
#define	STBH	OSCM,4
#define	CLKS	OSCM,2
#define	LFEN	OSCM,1
#define	HFEN	OSCM,0

;-----  POWCR Bits -------
#define LDOEN	POWCR,7
#define	ENB	POWCR,6
;-----  LVDCR Bits -------
#define LVD	PLVDCR,7
#define	LVDS	PLVDCR,6
;***********DDR1 DDR2 **********
#define	DDR10	DDR1,0
#define	DDR11	DDR1,1
#define	DDR12	DDR1,2
#define	DDR13	DDR1,3

#define	DDR20	DDR2,0
#define	DDR21	DDR2,1
#define	DDR22	DDR2,2
#define	DDR23	DDR2,3
#define	DDR24	DDR2,4
#define	DDR25	DDR2,5
#define	DDR26	DDR2,6
#define	DDR27	DDR2,7
;******************************


;#define	inca	addai 1
