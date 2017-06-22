#ifndef __MC30COMMON_H
#define __MC30COMMON_H

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

#define Nop() 			__asm__("nop")
#define ClrWdt() 		__asm__("clrwdt")
#define Stop() 			__asm__("stop")


typedef struct {
    unsigned char bit0         : 1;
    unsigned char bit1         : 1;
    unsigned char bit2         : 1;
    unsigned char bit3         : 1;
    unsigned char bit4         : 1;     
    unsigned char bit5         : 1; 
    unsigned char bit6         : 1;     
    unsigned char bit7         : 1;     
} BITS_T;

#endif
