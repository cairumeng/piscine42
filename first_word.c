#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_word(char *str)
{
	int i;

	i = 0;
	// skip the espace
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
			
	// meet the next espace
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))	
	{
		ft_putchar(str[i]);
		i++;
	}	

	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	first_word(argv[1]);
	return 0;
}
