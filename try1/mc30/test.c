#include <mc30p011.h>

void main(void)
{
	unsigned char a, b, c;

	DDR1 = 0x01;
	KBIM = DDR1 & 0x55;
	KBIM = DDR1 | 0x66;
	KBIM = DDR1 ^ 0x66;
	KBIE = 1;

	a = 1;
	b = 2;
	while(a==3)
	{
		a++;
		b = b + 2;
		c = a + b;
	}

}
