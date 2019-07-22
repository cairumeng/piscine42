#include <stdio.h>
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void	ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
	write(1, str, i);
}

void ft_show_tab(struct s_stock_str *par)
{
	int i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

int	main()
{
	char *str[5] = {
		"Hello World1",
		"Hello World2",
		"Hello World3",
		"Hello World4",
		"Hello World5",
	};

	t_stock_str *stocks = ft_strs_to_tab(5, str);
	ft_show_tab(stocks);
}
