#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>
void	ft_putstr(char *str);

#ifndef TRUE
# define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

typedef unsigned char	t_bool;

t_bool	ft_is_even(int nbr);

#ifndef EVEN
#define EVEN(nbr) (nbr % 2 == 0)
#endif

#ifndef EVEN_MSG
#define EVEN_MSG "I have an even number of arguments.\n"
#endif

#ifndef ODD_MSG
#define ODD_MSG "I have an odd number of arguments.\n"
#endif

#ifndef SUCCESS
#define SUCCESS 0
#endif

#endif
