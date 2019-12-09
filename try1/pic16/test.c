#include <pic18f1220.h>

#define uchar unsigned char

typedef union
{
	    struct {
			    uchar bit0:1;
				uchar bit1:1;
				uchar bit2:1;
				uchar bit3:1;
				uchar bit4:1;
				uchar bit5:1;
				uchar bit6:1;
				uchar bit7:1;
				};
} bitn;


volatile bitn Flag1;
int k;

#define F4ms Flag1.bit2


void main(void)
{
	unsigned char a, b, c;
	unsigned short i, j;

	PORTA = 0x01;

	k=0;

	F4ms = 1;
	F4ms = !F4ms;

	a = 1;
	b = 2;

    for(i=0; i<10; i++) F4ms = ~F4ms;

	for(j=0; j<100; j++) F4ms = ~F4ms;


	while(a==3)
	{
		a++;
		b = b + 2;
		c = a + b;
	}

}
