#include <stdio.h>

int	is_prime(int nbr)
{
	int i = 2;
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
		{
			return 0;
		}	
		i++;
	}
	return 1;
}

int	prime_sum(int nbr)
{
	int i = 2;
	int sum = 0;

	if (nbr < 2)
		return 0;

	while (i <= nbr)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	return sum;
}

int	main()
{
	printf("%d\n", prime_sum(-1));	//0
	printf("%d\n", prime_sum(2));	//2
	printf("%d\n", prime_sum(3));	//5
	printf("%d\n", prime_sum(21));	//77
	
	return 0;
}
