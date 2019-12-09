#include <pic16f1507.h>

typedef unsigned char uchar;
#define Nop() 			__asm__("nop")

uchar global_a;

uchar fun1(uchar a, uchar b)
{
	uchar i;
	for(i=0; i<a; i++)
		b += a;

	return b;
}

uchar fun2(uchar a, uchar b)
{
	uchar i;
	for(i=0; i<3; i++)
		b -= a;

	return b;
}

void fun3()
{
	uchar i;
	for(i=0; i<3; i++)
	{
		//P0 = ~P0;
		Nop();
	}

}

void main(void)
{
	uchar b;

	global_a = PORTC;
	b = PORTB;

	PORTA = fun1(global_a, b);
	PORTB = fun2(global_a, b);
	fun3();

	while(1);
}
