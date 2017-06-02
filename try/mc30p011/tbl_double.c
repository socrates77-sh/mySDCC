#include <mc30p011.h>

const double dtable[] = {
	1, 2, 3, 4, 5, 6, 7, 8
};

void main(void)
{
	unsigned char i;
	volatile double re;

	for (i= 0; i<8; i++)
	{
		re = dtable[i];
	}

	while(1);
}
