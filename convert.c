#include "rush02.h"

void	print_suffix(int n, char* suffix)
{
	if (n && suffix[0])
	{
		ft_putchar(' ');
		ft_putstr(suffix);
	}
}

void	num_to_words(int n, char* suffix, t_dict *dict)
{
	int	nbr;

	nbr = n;
	if (n >= 100)
	{
		ft_putstr(dict->one[n / 100]);
		ft_putchar(' ');
		ft_putstr(dict->other[0]);
		nbr = n % 100;
	}
	if (n >= 100 && nbr > 0)
		ft_putstr(" and ");

	if (nbr > 19)
	{
		ft_putstr(dict->ten[nbr / 10]);
		if (nbr % 10 > 0)
		{
			ft_putchar(' ');
			ft_putstr(dict->one[nbr % 10]);
		}
	}
	else
		if (nbr > 0)    // avoid to print zero
			ft_putstr(dict->one[nbr]);
	print_suffix(n, suffix);
}

void	convert_to_words(unsigned long n, t_dict *dict)
{
	int	num1;
	int	num2;
	int	num3;
	int	num4;

	if (n == 0)
	{
		ft_putstr(dict->one[0]);
		ft_putchar('\n');
		return;
	}
	num1 = n / 1000000000;
	num_to_words(num1, dict->other[3], dict);
	num2 = (n / 1000000) % 1000;
	if (num1 > 0 && num2 > 0)
		ft_putchar(' ');
	num_to_words(num2, dict->other[2], dict);
	num3 = (n / 1000) % 1000;
	if ((num1 > 0 || num2 > 0) && num3 > 0)
		ft_putchar(' ');
	num_to_words(num3, dict->other[1], dict);
	if (n > 1000 && n % 1000)
		ft_putchar(' ');
	num4 = n % 1000;
	num_to_words(num4, "", dict);
	ft_putchar('\n');
}

int	run_convert(int dictionary, unsigned long nbr)
{
	char	buff[1000000];
	t_dict	dict;
	int	size;

	size = read(dictionary, buff, 1000000);
	buff[size] = '\0';

	if (!is_valid_dictionary(buff))
		return (0);
	parse_dictionary(buff, &dict);
	convert_to_words(nbr, &dict); 
	return (1);
}
