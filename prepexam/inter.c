#include<unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

int is_repeated(int i, char *str)
{
	int j;

	j = 0;
	while(j<i)
	{
		if(str[j] == str[i])
			return 1;
		j++;
	}
	return 0;
}

int is_in_both(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(c == str[i])
			return 1;
		i++;
	}
	return 0;
}

/*
#include<stdio.h>
int main(void)
{
	char *test ="international";
	int i = 5;
	printf("%c", test[5]);
	printf("%d", is_repeated(i,test));
	return 0;
}
*/







int main (int ac, char **av)
{
	int i;

	i = 0;
	if(ac !=3)
	{
		ft_putchar('\n');
		return 0;
	}
	while(av[1][i])
	{
		if((!is_repeated(i,av[1])) && is_in_both(av[1][i],av[2]))
				ft_putchar(av[1][i]);

		i++;
	}
	ft_putchar('\n');
	return 0;
}
