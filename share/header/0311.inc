
;MC30P01A.INC  Standard Header File, Version 1.00 by Sinomcu


;==========================================================================
;
;       Revision History
;
;==========================================================================

;Rev:   Date:    Reason:

;1.00   12/06/21 Initial Release

;==========================================================================
;
;       Verify Processor
;
;==========================================================================
;==========================================================================
;
;       Register Definitions
;
;==========================================================================

;----- Register Files------------------------------------------------------

INDF                         EQU     H'0000'
T0CNT                        EQU     H'0001'
PCL                          EQU     H'0002'
STATUS                       EQU     H'0003'
FSR                          EQU     H'0004'
P0                           EQU     H'0005'
P1                           EQU     H'0006'
MCR                          EQU     H'0008'
KBIM                         EQU     H'0009'
PCLATH                       EQU     H'000A'
PDCON                        EQU     H'000B'
ODCON                        EQU     H'000C'
PUCON                        EQU     H'000D'
INTECON                      EQU     H'000E'
INTFLAG                      EQU     H'000F'
T0CR                         EQU     H'0041'
DDR0                         EQU     H'0045'
DDR1                         EQU     H'0046'
TMCR                         EQU     H'004B'
T1CR                         EQU     H'004C'
T1CNT                        EQU     H'004D'
T1LOAD                       EQU     H'004E'
T1DATA                       EQU     H'004F'

;INDF 
#define         INDF7          INDF,7
#define         INDF6          INDF,6
#define         INDF5          INDF,5
#define         INDF4          INDF,4
#define         INDF3          INDF,3
#define         INDF2          INDF,2
#define         INDF1          INDF,1
#define         INDF0          INDF,0

;T0CNT 
#define         T0C7           T0CNT,7
#define         T0C6           T0CNT,6
#define         T0C5           T0CNT,5
#define         T0C4           T0CNT,4
#define         T0C3           T0CNT,3
#define         T0C2           T0CNT,2
#define         T0C1           T0CNT,1
#define         T0C0           T0CNT,0

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
#define	RST	  STATUS,7
#define	TO	  STATUS,4
#define	PD	  STATUS,3
#define	Z	    STATUS,2
#define	DC	  STATUS,1
#define	C	    STATUS,0

;FSR 
#define         FSR5           FSR,5
#define         FSR4           FSR,4
#define         FSR3           FSR,3
#define         FSR2           FSR,2
#define         FSR1           FSR,1
#define         FSR0           FSR,0

;P0 
#define         P03D           P0,3
#define         P02D           P0,2
#define         P01D           P0,1
#define         P00D           P0,0

;P1 
#define         P17D           P1,7
#define         P16D           P1,6
#define         P15D           P1,5
#define         P14D           P1,4
#define         P12D           P1,2
#define         P11D           P1,1
#define         P10D           P1,0

;----- MCR Bits --------------------------------------------------------
#define	WDTEN	MCR,7
#define	EIS	  MCR,6

;KBIM 
#define         KBIM7           KBIM,7
#define         KBIM6           KBIM,6
#define         KBIM5           KBIM,5
#define         KBIM4           KBIM,4
#define         KBIM3           KBIM,3
#define         KBIM2           KBIM,2
#define         KBIM1           KBIM,1
#define         KBIM0           KBIM,0

;----- PCLATH Bits --------------------------------------------------------
#define	PCH1	  PCLATH,1
#define	PCH0	  PCLATH,0

;PDCON
#define         P12PD           PDCON,6
#define         P11PD           PDCON,5
#define         P10PD           PDCON,4
#define         P03PD           PDCON,3
#define         P02PD           PDCON,2
#define         P01PD           PDCON,1
#define         P00PD           PDCON,0

;ODCON
#define         P17OD           ODCON,7
#define         P16OD           ODCON,6
#define         P15OD           ODCON,5
#define         P14OD           ODCON,4
#define         P12OD           ODCON,2
#define         P11OD           ODCON,1
#define         P10OD           ODCON,0

;PUCON
#define         P17PU           PUCON,7
#define         P16PU           PUCON,6
#define         P15PU           PUCON,5
#define         P14PU           PUCON,4
#define         P12PU           PUCON,2
#define         P11PU           PUCON,1
#define         P10PU           PUCON,0

;----- INTECON Bits --------------------------------------------------------
#define	INTE	INTECON
#define	GIE	INTECON,7
#define	INT0IE	INTECON,2
#define	KBIE	INTECON,1
#define	T0IE	INTECON,0

;----- INTFLAG Bits --------------------------------------------------------
#define	INTF	  INTFLAG
#define	INT0IF	INTF,2
#define	KBIF	  INTF,1
#define	T0IF	  INTF,0

;----- T0CR Bits --------------------------------------------------------
#define         INT0M           T0CR,6
#define         T0PTS           T0CR,5
#define         T0SE            T0CR,4
#define         T0PTA           T0CR,3
#define         T0PR2           T0CR,2
#define         T0PR1           T0CR,1
#define         T0PR0           T0CR,0

;DDR0
#define         DDR03           DDR0,3
#define         DDR02           DDR0,2
#define         DDR01           DDR0,1
#define         DDR00           DDR0,0

;DDR1
#define         DDR17           DDR1,7
#define         DDR16           DDR1,6
#define         DDR15           DDR1,5
#define         DDR14           DDR1,4
#define         DDR12           DDR1,2
#define         DDR11           DDR1,1
#define         DDR10           DDR1,0

;------TMCR -----------------
#define TBS     TMCR,7
#define T1IE    TMCR,1
#define T1IF    TMCR,0

;-------T1CR----------
#define TMR1EN  T1CR,7
#define PWMOUT  T1CR,6
#define BUZOUT  T1CR,5
#define T1PTS1  T1CR,4
#define T1PTS0  T1CR,3
#define T1PR2   T1CR,2
#define T1PR1   T1CR,1
#define T1PR0   T1CR,0

;T1CNT
#define T1C7   T1CNT,7
#define T1C6   T1CNT,6
#define T1C5   T1CNT,5
#define T1C4   T1CNT,4
#define T1C3   T1CNT,3
#define T1C2   T1CNT,2
#define T1C1   T1CNT,1
#define T1C0   T1CNT,0

;T1LOAD
#define T1LOAD7   T1LOAD,7
#define T1LOAD6   T1LOAD,6
#define T1LOAD5   T1LOAD,5
#define T1LOAD4   T1LOAD,4
#define T1LOAD3   T1LOAD,3
#define T1LOAD2   T1LOAD,2
#define T1LOAD1   T1LOAD,1
#define T1LOAD0   T1LOAD,0

;T1DATA
#define T1DATA7   T1DATA,7
#define T1DATA6   T1DATA,6
#define T1DATA5   T1DATA,5
#define T1DATA4   T1DATA,4
#define T1DATA3   T1DATA,3
#define T1DATA2   T1DATA,2
#define T1DATA1   T1DATA,1
#define T1DATA0   T1DATA,0
