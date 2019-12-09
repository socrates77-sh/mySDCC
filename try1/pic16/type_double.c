#include <mc30p011.h>

double c_a;

void main(void)
{
	c_a = 1.13;

	P0 = c_a;

	while(1);
}
