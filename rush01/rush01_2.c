#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*g_input;
int		g_n;
int		**g_solution;
int		g_find;

int			is_valid_row_right(int *current_row, int right)
{
	int	current_right;
	int	max;
	int	i;

	current_right = 1;
	max = current_row[g_n - 1];
	i = g_n - 2;
	while (i >= 0)
	{
		if (current_row[i] > max)
		{
			current_right++;
			max = current_row[i];
		}
		i--;
	}
	return (current_right == right);
}

int			is_valid_row(int *current_row, int left, int right)
{
	return (is_valid_row_left(current_row, left) &&
			is_valid_row_right(current_row, right));
}

int			is_valid_col_up(int col, int up)
{
	int	current_up;
	int	max;
	int	i;

	current_up = 1;
	max = g_solution[0][col];
	i = 1;
	while (i < g_n)
	{
		if (g_solution[i][col] > max)
		{
			current_up++;
			max = g_solution[i][col];
		}
		i++;
	}
	return (current_up == up);
}

int			is_valid_col_down(int col, int down)
{
	int	current_down;
	int	max;
	int	i;

	current_down = 1;
	max = g_solution[g_n - 1][col];
	i = g_n - 2;
	while (i >= 0)
	{
		if (g_solution[i][col] > max)
		{
			current_down++;
			max = g_solution[i][col];
		}
		i--;
	}
	return (current_down == down);
}

int			is_valid_col(int col, int up, int down)
{
	return (is_valid_col_up(col, up) && is_valid_col_down(col, down));
}
