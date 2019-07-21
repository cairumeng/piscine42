#include "rush02.h"

void    print_suffix(int n, char* suffix)
{
    if (n && suffix[0])
    {
        ft_putchar(' ');
        ft_putstr(suffix);
    }
}

void    num_to_words(int n, char* suffix)
{
    int nbr;

    nbr = n;
    if (n >= 100)
    {
        ft_putstr(g_one[n / 100]);
        ft_putchar(' ');
        ft_putstr(g_other[0]);
        nbr = n % 100;
    }
    if (n >= 100 && nbr > 0)
        ft_putchar(' ');
    if (nbr > 19)
    {
        ft_putstr(g_ten[nbr / 10]);
        if (nbr % 10 > 0)
        {
            ft_putchar(' ');
            ft_putstr(g_one[nbr % 10]);
        }
    }
    else
        if (nbr > 0)    // avoid to print zero
            ft_putstr(g_one[nbr]);
    print_suffix(n, suffix);
}

void convert_to_words(unsigned long n)
{
    int num1;
    int num2;
    int num3;
    int num4;

    if (n == 0)
    {
        ft_putstr(g_one[0]);
        ft_putchar('\n');
        return;
    }
    num1 = n / 1000000000;
    num_to_words(num1, g_other[3]);
    num2 = (n / 1000000) % 1000;
    if (num1 > 0 && num2 > 0)
        ft_putchar(' ');
    num_to_words(num2, g_other[2]);
    num3 = (n / 1000) % 1000;
    if ((num1 > 0 || num2 > 0) && num3 > 0)
        ft_putchar(' ');
    num_to_words(num3, g_other[1]);
    if (n > 1000 && n % 1000)
        ft_putstr(" and ");
    num4 = n % 1000;
    num_to_words(num4, "");
    ft_putchar('\n');
}

int run_convert(int dictionary, int nbr)
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