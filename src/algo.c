#include "../include/push_swap.h"

bool	ft_check_sort(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

// size_t	lst_size(t_list **lst)
bool	ft_radix_with_index(t_list **lst_a)
{
	t_list *tmp;
	t_list *lst_b;
	size_t i;
	size_t size_lst;

	lst_b = NULL;
	i = 0;
	tmp = *lst_a;
	len_lst = lst_size(&lst);
	while (i < len_lst)
	{
		if (tmp->index >> i\)
			i++;
	}
}