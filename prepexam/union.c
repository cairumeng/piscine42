#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_not_repeated (int i , char *str)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (str[i] == str[j])
			return 0;
		j++;
	}
	return 1;
}

int is_not_in_both(char c, char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(c == str[i])
			return 0;
		i++;
	}
	return 1;
}

int main (int ac ,char **av)
{
	int i;

	i = 0;
	if (ac != 3)
	{
		ft_putchar('\n');
		return 0;
	}
	while(av[1][i])
	{
	
		if (is_not_repeated(i, av[1]) && is_not_in_both(av[1][i], av[2]) )
			ft_putchar(av[1][i]);
		i++;
	}
	i = 0;
	while(av[2][i])
	{
 		if (is_not_repeated(i, av[2]) && is_not_in_both(av[2][i], av[1]) )
			ft_putchar(av[2][i]);
		i++;
	}
	ft_putchar('\n');
	return 0;

}


