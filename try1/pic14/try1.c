//#include <pic16f1507.h>

unsigned int uc_a;

volatile __at (0x20) unsigned char ram0;
volatile __at (0x21) unsigned char ram1;

void main(void)
{
   	uc_a = (ram1<<2) + ram0;
   	ram1 = (uc_a)>>8;

   	while(1);
}

