#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *head = begin_list;

	while (*head)
	{
		(*f)(head->data);
		head = head->next;
	}
}

