NAME=libft.a
SRCS=srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS=ft_putchar.o  ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
HEADERS_FOLDER=includes
FLAGS=-Wall -Wextra -Werror

all: 
	gcc $(FLAGS) -I $(HEADERS_FOLDER) -c $(SRCS)
	ar -rv $(NAME) $(OBJECTS)
	ranlib $(NAME)
	mv *.o srcs

clean:
	/bin/rm -f srcs/*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
