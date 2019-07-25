#include <stdlib.h>
#include <stdio.h>
 
int     *ft_range(int start, int end)
{
	 int n ;
	 int * dest;
     int * head;
	 head = dest;
	if (end == start)
	{
		n = 1;
		dest = (int *) malloc (n * sizeof (int));
		*dest = start;
	}
	else if (end > start)
	{
		n = end - start + 1;

	dest = (int *) malloc (n * sizeof (int));
		while (start <= end)
		{
			*dest = start;
			dest++;
			start++;
		}
	}
	else
	{
		n = start - end +1;
dest = (int *) malloc (n * sizeof (int));
		while( start >= end )
		{
			*dest = start;
			dest ++;
			start++;
		}
	}
	return head;
}

int main ()
	
{
	int * result = ft_range (-3, 2);
	int i;
	i = 0;
		
	while (i<= 6)
	{
		printf("%d",result[i]);
		i++;
	}
	free (result);
	return 0;

}
