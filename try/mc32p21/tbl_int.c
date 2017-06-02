#include <mc32p21.h>

const uint utable[] = {
	0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007
};

const int stable[] = {
	0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087
};

void main(void)
{
	unsigned char i;
	volatile int re;

	for (i= 0; i<8; i++)
	{
		re = utable[i];
		re = stable[i];
	}

	while(1);
}
