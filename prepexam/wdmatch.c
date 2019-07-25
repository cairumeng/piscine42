#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return i;
}

void wdmatch(char *str1, char *str2)
{
	int i;
	int j;
	int count;
	int len;

	i = 0;
	j = 0;
	count = 0;
	while(str1[i] && str2[j])
	{
		if(str1[i] == str2[j])
		{
			count++;
			i++;
		}
		j++;
	}
	len = ft_strlen(str1);
	if( count == len)
		write(1,str1,len);
	ft_putchar('\n');
}




int main (int ac, char **av)
{
	if (ac !=3)
	{
		ft_putchar('\n');
		return 0;
	}

	wdmatch(av[1], av[2]);
	return 0;
	}
	
