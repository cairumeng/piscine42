#include "rush02.h"

/**
 * free a 2 dimension array's memory
 */
void	free_array(char** array, unsigned int size)
{
	int	i;
	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * find c's usage time in str
 */
int	ft_frequence(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return counter;
}

