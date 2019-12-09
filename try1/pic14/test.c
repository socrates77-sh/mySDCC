#include <pic16f1507.h>


     unsigned int      tempa,tempb,tempc;

void main()
{
    PORTA=0XFF;
    PORTB=0XFF;
     
    while(1)
    {
        PORTC=~PORTC;  
          tempa=tempb+0x0400;
          tempc=tempa;
          PORTA=tempc>>8;
          PORTB=tempc & 0x00ff;
    }   
}

