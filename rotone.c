#include <stdio.h>

int	is_uppercase(char c)
{
	return (c <= 'A' && c >= 'Z');
}
int	is_lowercase(char c)
{
	return (c <= 'a' && c >= 'z');
}

int	is_alpha(char c)
{
	return (c >= 'a' && c <= 'z') || (c <= 'A' && c >= 'Z');
}

char next_alpha(char c)
{
	if (c == 'z' || c == 'Z')
		return c - 25;
	return c + 1;
}

char oppo_alpha(char c)
{
	if (is_uppercase(c))
		return 26 - c + (2 * 'A')';
	if (is_lowercase(c))
		return 26 - c + (2 * 'a')';
}

void	rotone(char *str)
{
	while (*str)
	{
		if (is_alpha(*str))
			//ft_putchar(next_alpha(*str));
			ft_putchar(oppo_alpha(*str));
		else
			ft_putchar(*str);
		str++;
	}
}
