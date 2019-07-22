#include <stdio.h>
#include <stdlib.h>

int	is_base_valid(char *base)
{
	int	len;
	int	i;
	char	c;

	len = 0;
	while (base[len])
	{
		c = base[len];
		if (c == '+' || c == '-' || c == ' ' || 
		c == '\t' || c == '\n' || c == ' ' ||
		c == '\v' || c == '\f' || c == '\r')
			return (0);
		i = 0;
		while (i < len && base[i])
		{
			if (base[i] == c)
				return (0);
			i++;
		}
		len++;
	}
	if (len < 2)
		return (0);
	return (1);
}

int	get_number_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	i;
	int base_length;

	base_length = 0;
	while (base[base_length])
		base_length++;
	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i])
		result = result * base_length + get_number_in_base(base, str[i++]);
	return (sign * result);
}

int	get_result_length(unsigned int nbr, char *base, int base_length)
{
	int	result_length;

	result_length = 0;
	while (nbr >= base_length)
	{
		nbr = nbr / base_length;
		result_length++;
	}
	return (result_length + 1);
}

void	ft_putnbr_base(char* result, int pos, unsigned int nbr, char *base, int base_length)
{
	if (nbr >= base_length)
		ft_putnbr_base(result, pos + 1, nbr / base_length, base, base_length);
	result[pos] = base[nbr % base_length];
}
