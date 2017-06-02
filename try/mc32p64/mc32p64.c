#include <mc32p64.h>

void main(void)
{
	unsigned char a, b, c;

	IOP0 = 0x01;
	MCR = OEP1 & 0x55;
	MCR = OEP1 | 0x66;
	MCR = OEP1 ^ 0x66;
	OSCM = 1;

	a = 1;
	b = 2;
	while(a==3)
	{
		a++;
		b = b + 2;
		c = a + b;
	}

}
