#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	is_uppercase(char c)
{
	return c >= 'A' && c <= 'Z';
}

int	is_lowercase(char c)
{
	return c >= 'a' && c <= 'z';
}

char uppercase(char c)
{
	return c + ('A' - 'a');
}

char lowercase(char c)
{
	return c + ('a' - 'A');
}

void	ft_captilize(char *str)
{
	int i = 0;
	int flag = 1;

	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t'))
		{
			flag = 1;
			ft_putchar(str[i]);
		}
		else 
		{
			if (is_lowercase(str[i]) && flag == 1)
			{
				ft_putchar(uppercase(str[i]));
			}
			else if (is_uppercase(str[i]) && flag == 0)
			{
				ft_putchar(lowercase(str[i]));
			}
			else 
			{
				ft_putchar(str[i]);
			}
			flag = 0;
		}
		i++;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{

	ft_captilize(argv[1]);
	return 0;
}

