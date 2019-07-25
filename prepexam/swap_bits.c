unsigned char swap_bits(unsigned char octet)
{
	return((octet & oxF0>>4)&(octet &oxF<<4));
}	
