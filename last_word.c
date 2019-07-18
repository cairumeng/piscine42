#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return i;
}

void put_last_word(char *str)
{
	int n;
	int j;

	n = ft_strlen (str) - 1;
	if (!n)
		ft_putchar('\n');		
	
	while((str[n] == ' '|| str[n] == '\t'))
	{
		if (n == 0)
		{
			ft_putchar('\n');
			return;
		}
		n--;
	}
	j = n;
	while(n >= 0 && (str[n] != ' ' && str[n] != '\t'))
		n--;
	while(n <= j)
	{
		ft_putchar(str[n]);
		n++;
	}
	ft_putchar('\n');
}

int main (int argc, char **argv)
{
	if(argc != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	put_last_word(argv[1]);
	return 0;

}
