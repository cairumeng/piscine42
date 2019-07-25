#include<unistd.h>
#include<stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_op(char **av)
{
	int a;
	int b;
	int c;

	a = atoi(av[1]);
	b = atoi(av[3]);


	if (av[2][0] == '+')
		c = a + b;
	if (av[2][0] == '-')
		c = a - b;
	if (av[2][0] == '*')
		c = a * c;
	if (av[2][0] == '/')
		c = a / b;
	return c;
}

void put_nbr(unsigned int nbr)
{
	while (nbr > 0)
	{
		put_nbr(nbr / 10);
		ft_putchar(nbr % 10);
	}
}

#include<stdio.h>

int main ()
{
	char ** dest[4];
	dest = {"a.out", "13", "+", "2"};
		int a = atoi(dest[1]);
	int b = atoi(dest[3]);


	printf("%d %d", a, b);
	printf("%d", ft_op(dest));
	return 0;
}

/*
int main(int ac, char **av)
{
	int num; 
	unsigned int nbr;

	if(ac != 4)
	{
		ft_putchar('\n');
		return 0;
	}

	num = ft_op(av);
	if (num < 0)
	{
		ft_putchar('-');
		nbr = num * -1;
	}	
	else 
		nbr = num;
	put_nbr(nbr);
	ft_putchar ('\n');
	return 0;
}


*/
