unsigned char reverse_bits(unsigned char octet)
{
	return( (octet & ox80 >> 7)&
			(octet & ox40 >> 5)&
			(octet & ox20 >> 3)&
			(octet & ox10 >> 1)&
			(octet & ox8 << 1)&
			(octet & ox4 << 3)&
			(octet & ox2 << 5)&
			(octet & ox1 << 7))
}

#include<stdio.h>
int main ()
{
	unsigned char octet;
	octet = 
