#include <mc31p11.h>

void main(void)
{
	unsigned char a, b, c;

	IOP0 = 0x01;
	DKW = IOP0 & 0x55;
	DKW = IOP0 | 0x66;
	DKW = IOP0 ^ 0x66;
	GIE = 1;
	MINT0 = 2;

	a = 1;
	b = 2;
	while(a==3)
	{
		a++;
		b = b + 2;
		c = a + b;
	}

}
