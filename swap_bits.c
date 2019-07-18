#include <stdio.h>

unsigned char	swap_bits(unsigned char c)
{
	return (((c & 0xf0) >> 4) | ((c & 0xf) << 4));
}

int	main()
{
	printf("%d, %d\n", 123, swap_bits(123));
	return 0;
}
