

int max(int *tab, unsigned int len)
{
	unsigned int i;
	int max;

	i = 0;
	max = tab[0];
	if(len == 0)
		return 0;
	while (i < len)
	{
		if(tab[i]>max)
			max = tab[i];
		i++;
	}
	return(max);
}

#include <stdio.h>

int main ()
{
	int tab[5]= {};
	printf("%d", max(tab, 0));
	return 0;
}
