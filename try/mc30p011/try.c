#include <mc30p011.h>

uchar fun1(uchar a, uchar b)
{
	b = a + b;
	return b;
}

void main(void)
{
	uchar a;
	a = DDR0;
	fun1(a, 0);
}
