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

	a = atoi(av[1]);
	b = atoi(av[3]);

	if (av[2][0] == '+')
		return a + b;
	if (av[2][0] == '-')
		return a - b;
	if (av[2][0] == '*')
		return a * c;
	if (av[2][0] == '/')
		return a / b;
}

#include<stdio.h>

int main ()
{
	char *dest[4] = {"a.out", "13", "+", "2"};
	
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
