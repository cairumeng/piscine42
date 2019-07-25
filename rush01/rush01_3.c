#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*g_input;
int		g_n;
int		**g_solution;
int		g_find;

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			print_solution(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_n)
	{
		j = 0;
		while (j < g_n)
		{
			ft_putchar(g_solution[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int				is_valid_solution(void)
{
	int col;

	col = 0;
	while (col < g_n)
	{
		if (!is_valid_col(col, get_col_up(col), get_col_down(col)))
			return (0);
		col++;
	}
	return (1);
}

int				is_number_used(int row, int col, int number)
{
	int i;

	i = 0;
	while (i < col)
	{
		if (g_solution[row][i] == number)
			return (1);
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (g_solution[i][col] == number)
			return (1);
		i++;
	}
	return (0);
}

void			find_solution(int row, int col, int left, int right)
{
	int	number;

	if (g_find)
		return ;
	if (row == g_n && is_valid_solution())
	{
		print_solution();
		g_find = 1;
		return ;
	}
	if (col < g_n)
	{
		number = 1;
		while (number <= g_n)
			if (!is_number_used(row, col, number))
			{
				g_solution[row][col] = number;
				find_solution(row, col + 1, left, right);
				if (col == g_n - 1 && is_valid_row(g_solution[row],
							left, right))
					find_solution(row + 1, 0, get_row_left(row + 1),
							get_row_right(row + 1));
			}
		number++;
	}
}
