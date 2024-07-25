#include "fdf.h"
#include <stdio.h>

int ft_random(int seed)
{
	static int r;

	r += 1 + (int)(&seed);

	r = (r  << (2 + (seed & 32))) ;

	return (r);
}

int main()
{
	// int i = 0;
	// while (i < 10)
	// {
	printf("rand number = %i\n", abs(ft_random(0)) % 10);
	// 	i++;
	// }
	return (0);
}
