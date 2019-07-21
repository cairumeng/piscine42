#include "rush02.h"

int	run_convert(int dictionary, int nbr)
{
	char buff[4096];
	int size;

	size = read(dictionary, buff, 4096);
	buff[size] = '\0';

	if (!is_valid_dictionary(buff))
	{
		ft_putstr_err("Error\n");
		return 0;
	}
	parse_dictionary(buff, g_one, g_ten, g_other);
	convert_to_words(nbr); 
	return 1;
}

int main(int argc, char **argv) 
{ 
	long nbr;
	char *dictionary_name = "numbers.dict";
	int dictionary;
	char *input;

	if (argc == 2)
		input = argv[1];
	else if (argc == 3)
	{
		input = argv[2];
		dictionary_name = argv[1];
	}
	else
	{
		ft_putstr_err("Error\n");
		return 0;
	}
	dictionary = open(dictionary_name, O_RDONLY);
	if (dictionary < 0 || !is_valid_int(input))
	{
		ft_putstr_err("Error\n");
		close(dictionary);
		return 0;
	}
	nbr = ft_atoi(input);
	if (nbr < 0)
	{
		ft_putstr("- ");
		nbr = nbr * -1;
	}
	run_convert(dictionary, nbr);
	return 0; 
} 

