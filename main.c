#include "rush02.h"

char	*get_input(int argc, char **argv)
{
	if (argc == 2)
		return (argv[1]);
	if (argc == 3)
		return (argv[2]);
	return (NULL);
}

int	get_dictionary_fd(int argc, char **argv)
{
	char	*dictionary_name;

	dictionary_name = "numbers.dict";
	if (argc == 3)
		dictionary_name = argv[1];
	return (open(dictionary_name, O_RDONLY));
}

int	main(int argc, char **argv) 
{
	unsigned long	nbr;
	long nb;
	int	dictionary;
	char	*input;

	input = get_input(argc, argv);
	dictionary = get_dictionary_fd(argc, argv);
	if (!input || dictionary < 0 || !is_valid_int(input))
	{
		ft_putstr_err("Error\n");
		close(dictionary);
		return (0);
	}
	nb = ft_atoi(input);
	if (nb < 0)
	{
		ft_putstr("- ");
		nbr = nb * -1;
	} else
		nbr = nb;
	if (!run_convert(dictionary, nbr))
		ft_putstr_err("Dict Error\n");
	close(dictionary);
	return (0); 
}
