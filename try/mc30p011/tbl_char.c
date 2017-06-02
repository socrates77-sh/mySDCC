#include <mc30p011.h>

const uchar utable[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
};

const uchar stable[] = {
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87
};

void main(void)
{
	unsigned char i;

	for (i= 0; i<8; i++)
	{
		P0 = utable[i];
		P1 = stable[i];
	}

	while(1);
}
