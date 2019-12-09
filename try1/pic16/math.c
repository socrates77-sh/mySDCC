#include <mc30p011.h>
#include <math.h>

float c_a;

void main(void)
{
	c_a = 1.13;

	P0 = expf(c_a);

	while(1);
}
