#include<unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_letter(char c)
{
	return (('a'<= c && c <= 'z')||('A'<= c && c <= 'Z'));
}

void alpha_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if('a'<= str[i] && str[i]<= 'z')
			ft_putchar('a' + 'z' - str[i]);
		else if('A'<= str[i] && str[i]<= 'Z')
			ft_putchar('A' + 'Z' - str[i]);
		else 
			ft_putchar(str[i]);
		i++;
	}
}

int main (int ac, char **av)
{
	int i;

	i = 0;
	if(ac != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	alpha_mirror(av[1]);
	ft_putchar ('\n');
	return 0;
}	
