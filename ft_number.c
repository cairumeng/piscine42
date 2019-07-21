int	is_number_char(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(char *str)
{
	long nbr = 0;
	int sign;

	sign = 1;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str)
	{
		if (is_number_char(*str))
			nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (sign * nbr);
}

int	is_valid_int(char *str)
{
	while (*str && (*str == '-' || *str == '+'))
	{
		str++;
	}
	while (*str)
	{
		if (!(is_number_char(*str) || *str == ','))
			return (0);
		str++;
	}
	return (1);
}
