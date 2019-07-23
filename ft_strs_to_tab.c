#include <stdlib.h>
#include "ft_stock_str.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	char *dest;
	int n;
	int i;
	
	n = ft_strlen(src); 
	i = 0;	
	dest = (char*)malloc((n + 1) * sizeof(char));
	while (*src)
	{
		 dest[i] = *src;
	 	 src++;	 
		 i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *tab;
	int i;

	tab = (t_stock_str*)malloc((ac + 1) * sizeof (t_stock_str));
	if (!tab)
		return (NULL);
	i = 0;
	while(i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
