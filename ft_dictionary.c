#include "rush02.h"

void	init_one_array(char **lines, char **one)
{
	int	i;
	char	**cols;
	int	col_count;

	i = 0;
	while (i < 20)
	{
		cols = ft_split(lines[i], ':', &col_count);
		one[i++] = ft_trim(cols[1]);
		free_array(cols, col_count);
	}
}

void	init_ten_array(char **lines, char **ten)
{
	int	i;
	char	**cols;
	int	col_count;

	ten[0] = ft_trim("");
	ten[1] = ft_trim("");
	i = 2;
	while (i < 10)
	{
		cols = ft_split(lines[i + 18], ':', &col_count);
		ten[i++] = ft_trim(cols[1]);
		free_array(cols, col_count);
	}
}

void	parse_dictionary(char *buff, t_dict *dict)
{
	char	**lines;
	char	**cols;
	int	line_count;
	int	i;
	int	col_count;

	lines = ft_split(buff, '\n', &line_count);
	init_one_array(lines, dict->one);
	init_ten_array(lines, dict->ten);

	i = 0;
	while (i < 4)
	{
		cols = ft_split(lines[28 + i], ':', &col_count);
		dict->other[i] = ft_trim(cols[1]);
		free_array(cols, col_count);
		i++;
	}
}

int	is_valid_dictionary(char *buff)
{
	int	i = 0;
	int	line;

	line = 0;
	while (buff[i])
	{
		line++;
		// find numbers
		while (buff[i] && is_number_char(buff[i]))
			i++;
		if (i == 0) //no number or not begin with number
			return (0);	
		while (buff[i] && buff[i] == ' ')
			i++;	// skip ' '
		if (buff[i] && buff[i++] != ':')
			return (0);	// skip :
		while (buff[i] && buff[i] == ' ')
			i++;	//skip ' '
		while (buff[i] && buff[i] != '\n')
			i++;	//skip characters before \n
		if (buff[i] && buff[i++] != '\n')
			return (0);	// skip \n
	}
	if (line != 32)
		return (0);
	return (1);
}
