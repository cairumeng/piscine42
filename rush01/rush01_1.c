#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*g_input;
int		g_n;
int		**g_solution;
int		g_find;

int			get_col_up(int i)
{
	if (i == 0)
		return (g_input[0] - '0');
	return (g_input[i * 2] - '0');
}

int			get_col_down(int i)
{
	return (g_input[(i + g_n) * 2] - '0');
}

int			get_row_left(int i)
{
	return (g_input[(i + 2 * g_n) * 2] - '0');
}

int			get_row_right(int i)
{
	return (g_input[(i + 3 * g_n) * 2] - '0');
}

int			is_valid_row_left(int *current_row, int left)
{
	int	current_left;
	int	max;
	int	i;

	current_left = 1;
	max = current_row[0];
	i = 1;
	while (i < g_n)
	{
		if (current_row[i] > max)
		{
			current_left++;
			max = current_row[i];
		}
		i++;
	}
	return (current_left == left);
}
