#include <file.h>

void		rush(void)
{
	g_find = 0;
	g_n = get_n();
	if (g_n != -1)
	{
		init_solution();
		find_solution(0, 0, get_row_left(0), get_row_right(0));
		free_solution();
	}
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error();
	}
	else
	{
		g_input = argv[1];
		rush();
		if (!g_find)
		{
			print_error();
		}
	}
	return (0);
}
