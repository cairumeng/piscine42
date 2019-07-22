#include <stdio.h>
#include <stdlib.h>

int is_base_valid(char *base);
int get_number_in_base(char *base, char c);
int ft_atoi_base(char *str, char *base);
int get_result_length(unsigned int nbr, char *base, int base_length);
void    ft_putnbr_base(char* result, int pos, unsigned int nbr, char *base, int base_length);

char	*ft_strrev_copy(char *str)
{
	int	i;
	int	j;
	char	*dest;

	i = 0;
	while (str[i])
		i++;
	j = i;
	dest = (char*)malloc(sizeof(char) * j);
	i = 0;
	while (str[j - 1])
	{
		dest[i++] = str[j - 1];	
		j--;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa_base(int nbr, char *base, int base_length)
{
	unsigned int	nb;
	char	*result;
	char	*tmp;
	int		result_length;
	int	i;

	result_length = 0;
	if (nbr < 0)
	{
		nb = nbr * -1;	
		result_length++;
	}
	else
		nb = nbr;
	result_length += get_result_length(nb, base, base_length);
	tmp = (char*)malloc(sizeof(char) * result_length);	
	ft_putnbr_base(tmp, 0, nb, base, base_length);
	if (nbr < 0)
		tmp[result_length - 1] = '-';
	tmp[result_length] = '\0';
	result = ft_strrev_copy(tmp);
	free(tmp);
	return (result);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;
	int	base_to_length;

	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	base_to_length = 0;
	while (base_to[base_to_length])
		base_to_length++;
	return (ft_itoa_base(nb, base_to, base_to_length));
}

int main()
{
	printf("%s\n", ft_convert_base("\t---+++--1001", "01", "01234567"));  // display 10010
	printf("%s\n", ft_convert_base("\t---+++--1001", "01", "0123456789"));  // display 10010
	printf("%s\n", ft_convert_base("\n\t\v-F", "0123456789ABCDEF", "01"));  // display F
	printf("%s\n", ft_convert_base("\n\t\v-F", "0123456789ABCDEF", "0123456789"));  // display F
	printf("%s\n", ft_convert_base("17", "01234567", "01")); // display 22	
	printf("%s\n", ft_convert_base("17", "01234567", "0123456789ABCDEF")); // display 22	
	printf("%s\n", ft_convert_base("18", "0123456789", "01")); // display nothing - p is used twice
	printf("%s\n", ft_convert_base("10", "+01", "01")); // display nothing - can't add +, - and other characters
	printf("%s\n", ft_convert_base("18", "", "")); // display nothing - empty base string
//	printf("%s\n", ft_itoa_base(-19, "01", 2));	
//	printf("%s\n", ft_itoa_base(-151, "0123456789ABCDEF", 16));	
//	printf("%s\n", ft_itoa_base(19, "0123456789", 10));	
	return (0);
}
