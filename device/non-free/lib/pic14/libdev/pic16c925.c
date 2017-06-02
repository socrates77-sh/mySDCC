/* Register definitions for pic16c925.
 * This file was automatically generated by:
 *   inc2h.pl
 *   Copyright (c) 2002, Kevin L. Pauba, All Rights Reserved
 *
 * SDCC is licensed under the GNU Public license (GPL) v2. Note that
 * this license covers the code to the compiler and other executables,
 * tbut explicitly does not cover any code or objects generated by sdcc.
 *
 *
 * For pic device libraries and header files which are derived from
 * Microchip header (.inc) and linker script (.lkr) files Microchip
 * requires that "The header files should state that they are only to be
 * used with authentic Microchip devices" which makes them incompatible
 * with the GPL. Pic device libraries and header files are located at
 * non-free/lib and non-free/include directories respectively.
 * Sdcc should be run with the --use-non-free command line option in
 * order to include non-free header files and libraries.
 *
 * See http://sdcc.sourceforge.net/ for the latest information on sdcc.
 */
#include <pic16c925.h>

__sfr  __at (INDF_ADDR)                    INDF;
__sfr  __at (TMR0_ADDR)                    TMR0;
__sfr  __at (PCL_ADDR)                     PCL;
__sfr  __at (STATUS_ADDR)                  STATUS;
__sfr  __at (FSR_ADDR)                     FSR;
__sfr  __at (PORTA_ADDR)                   PORTA;
__sfr  __at (PORTB_ADDR)                   PORTB;
__sfr  __at (PORTC_ADDR)                   PORTC;
__sfr  __at (PORTD_ADDR)                   PORTD;
__sfr  __at (PORTE_ADDR)                   PORTE;
__sfr  __at (PCLATH_ADDR)                  PCLATH;
__sfr  __at (INTCON_ADDR)                  INTCON;
__sfr  __at (PIR1_ADDR)                    PIR1;
__sfr  __at (TMR1_ADDR)                    TMR1;
__sfr  __at (TMR1L_ADDR)                   TMR1L;
__sfr  __at (TMR1H_ADDR)                   TMR1H;
__sfr  __at (T1CON_ADDR)                   T1CON;
__sfr  __at (TMR2_ADDR)                    TMR2;
__sfr  __at (T2CON_ADDR)                   T2CON;
__sfr  __at (SSPBUF_ADDR)                  SSPBUF;
__sfr  __at (SSPCON_ADDR)                  SSPCON;
__sfr  __at (CCPR1_ADDR)                   CCPR1;
__sfr  __at (CCPR1L_ADDR)                  CCPR1L;
__sfr  __at (CCPR1H_ADDR)                  CCPR1H;
__sfr  __at (CCP1CON_ADDR)                 CCP1CON;
__sfr  __at (ADRESH_ADDR)                  ADRESH;
__sfr  __at (ADCON0_ADDR)                  ADCON0;
__sfr  __at (OPTION_REG_ADDR)              OPTION_REG;
__sfr  __at (TRISA_ADDR)                   TRISA;
__sfr  __at (TRISB_ADDR)                   TRISB;
__sfr  __at (TRISC_ADDR)                   TRISC;
__sfr  __at (TRISD_ADDR)                   TRISD;
__sfr  __at (TRISE_ADDR)                   TRISE;
__sfr  __at (PIE1_ADDR)                    PIE1;
__sfr  __at (PCON_ADDR)                    PCON;
__sfr  __at (PR2_ADDR)                     PR2;
__sfr  __at (SSPADD_ADDR)                  SSPADD;
__sfr  __at (SSPSTAT_ADDR)                 SSPSTAT;
__sfr  __at (ADRESL_ADDR)                  ADRESL;
__sfr  __at (ADCON1_ADDR)                  ADCON1;
__sfr  __at (PORTF_ADDR)                   PORTF;
__sfr  __at (PORTG_ADDR)                   PORTG;
__sfr  __at (PMCON1_ADDR)                  PMCON1;
__sfr  __at (LCDSE_ADDR)                   LCDSE;
__sfr  __at (LCDPS_ADDR)                   LCDPS;
__sfr  __at (LCDCON_ADDR)                  LCDCON;
__sfr  __at (LCDD00_ADDR)                  LCDD00;
__sfr  __at (LCDD01_ADDR)                  LCDD01;
__sfr  __at (LCDD02_ADDR)                  LCDD02;
__sfr  __at (LCDD03_ADDR)                  LCDD03;
__sfr  __at (LCDD04_ADDR)                  LCDD04;
__sfr  __at (LCDD05_ADDR)                  LCDD05;
__sfr  __at (LCDD06_ADDR)                  LCDD06;
__sfr  __at (LCDD07_ADDR)                  LCDD07;
__sfr  __at (LCDD08_ADDR)                  LCDD08;
__sfr  __at (LCDD09_ADDR)                  LCDD09;
__sfr  __at (LCDD10_ADDR)                  LCDD10;
__sfr  __at (LCDD11_ADDR)                  LCDD11;
__sfr  __at (LCDD12_ADDR)                  LCDD12;
__sfr  __at (LCDD13_ADDR)                  LCDD13;
__sfr  __at (LCDD14_ADDR)                  LCDD14;
__sfr  __at (LCDD15_ADDR)                  LCDD15;
__sfr  __at (TRISF_ADDR)                   TRISF;
__sfr  __at (TRISG_ADDR)                   TRISG;
__sfr  __at (PMDATA_ADDR)                  PMDATA;
__sfr  __at (PMADR_ADDR)                   PMADR;
__sfr  __at (PMDATH_ADDR)                  PMDATH;
__sfr  __at (PMADRH_ADDR)                  PMADRH;

//
// bitfield definitions
//
volatile __ADCON0bits_t __at(ADCON0_ADDR) ADCON0bits;
volatile __ADCON1bits_t __at(ADCON1_ADDR) ADCON1bits;
volatile __CCP1CONbits_t __at(CCP1CON_ADDR) CCP1CONbits;
volatile __INTCONbits_t __at(INTCON_ADDR) INTCONbits;
volatile __LCDCONbits_t __at(LCDCON_ADDR) LCDCONbits;
volatile __LCDD00bits_t __at(LCDD00_ADDR) LCDD00bits;
volatile __LCDD01bits_t __at(LCDD01_ADDR) LCDD01bits;
volatile __LCDD02bits_t __at(LCDD02_ADDR) LCDD02bits;
volatile __LCDD03bits_t __at(LCDD03_ADDR) LCDD03bits;
volatile __LCDD04bits_t __at(LCDD04_ADDR) LCDD04bits;
volatile __LCDD05bits_t __at(LCDD05_ADDR) LCDD05bits;
volatile __LCDD06bits_t __at(LCDD06_ADDR) LCDD06bits;
volatile __LCDD07bits_t __at(LCDD07_ADDR) LCDD07bits;
volatile __LCDD08bits_t __at(LCDD08_ADDR) LCDD08bits;
volatile __LCDD09bits_t __at(LCDD09_ADDR) LCDD09bits;
volatile __LCDD10bits_t __at(LCDD10_ADDR) LCDD10bits;
volatile __LCDD11bits_t __at(LCDD11_ADDR) LCDD11bits;
volatile __LCDD12bits_t __at(LCDD12_ADDR) LCDD12bits;
volatile __LCDD13bits_t __at(LCDD13_ADDR) LCDD13bits;
volatile __LCDD14bits_t __at(LCDD14_ADDR) LCDD14bits;
volatile __LCDD15bits_t __at(LCDD15_ADDR) LCDD15bits;
volatile __LCDPSbits_t __at(LCDPS_ADDR) LCDPSbits;
volatile __LCDSEbits_t __at(LCDSE_ADDR) LCDSEbits;
volatile __OPTION_REGbits_t __at(OPTION_REG_ADDR) OPTION_REGbits;
volatile __PCONbits_t __at(PCON_ADDR) PCONbits;
volatile __PIE1bits_t __at(PIE1_ADDR) PIE1bits;
volatile __PIR1bits_t __at(PIR1_ADDR) PIR1bits;
volatile __PMCON1bits_t __at(PMCON1_ADDR) PMCON1bits;
volatile __PORTAbits_t __at(PORTA_ADDR) PORTAbits;
volatile __PORTBbits_t __at(PORTB_ADDR) PORTBbits;
volatile __PORTCbits_t __at(PORTC_ADDR) PORTCbits;
volatile __PORTDbits_t __at(PORTD_ADDR) PORTDbits;
volatile __PORTEbits_t __at(PORTE_ADDR) PORTEbits;
volatile __PORTFbits_t __at(PORTF_ADDR) PORTFbits;
volatile __PORTGbits_t __at(PORTG_ADDR) PORTGbits;
volatile __SSPCONbits_t __at(SSPCON_ADDR) SSPCONbits;
volatile __SSPSTATbits_t __at(SSPSTAT_ADDR) SSPSTATbits;
volatile __STATUSbits_t __at(STATUS_ADDR) STATUSbits;
volatile __T1CONbits_t __at(T1CON_ADDR) T1CONbits;
volatile __T2CONbits_t __at(T2CON_ADDR) T2CONbits;
volatile __TRISAbits_t __at(TRISA_ADDR) TRISAbits;
volatile __TRISBbits_t __at(TRISB_ADDR) TRISBbits;
volatile __TRISCbits_t __at(TRISC_ADDR) TRISCbits;
volatile __TRISDbits_t __at(TRISD_ADDR) TRISDbits;
volatile __TRISEbits_t __at(TRISE_ADDR) TRISEbits;
volatile __TRISFbits_t __at(TRISF_ADDR) TRISFbits;
volatile __TRISGbits_t __at(TRISG_ADDR) TRISGbits;

