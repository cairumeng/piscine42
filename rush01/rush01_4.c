#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*g_input;
int		g_n;
int		**g_solution;
int		g_find;

int			ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			get_n(void)
{
	int	len;
	int	i;

	i = 3;
	len = ft_strlen(g_input);
	while (i <= 9 && i >= 3)
	{
		if (i * 8 - 1 == len)
			return (i);
		i++;
	}
	return (-1);
}

void		free_solution(void)
{
	int	i;

	i = 0;
	while (i < g_n)
	{
		free(g_solution[i]);
		i++;
	}
	free(g_solution);
}

void		init_solution(void)
{
	int	i;
	int	j;

	i = 0;
	g_solution = (int**)malloc(g_n * sizeof(int*));
	while (i < g_n)
	{
		g_solution[i] = (int*)malloc(g_n * sizeof(int));
		j = 0;
		while (j < g_n)
		{
			g_solution[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		print_error(void)
{
	write(1, "Error\n", 6);
}
