#include <mc30p011.h>

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
	for(i=0; i<a; i++)
		b -= a;

	return b;
}

void main(void)
{
	uchar b;

	global_a = MCR;
	b = DDR0;

	P0 = fun1(global_a, b);
	P1 = fun2(global_a, b);

	while(1);
}
