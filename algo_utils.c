#include "../include/push_swap.h"

static t_lst	*ft_search_max_value_lst(t_lst *lst)
{
	t_lst	*max;
	int		max_element;

	max_element = 0;
	while (lst)
	{
		if (lst->nb > max_element)
		{
			max = lst;
			max_element = lst->nb;
		}
		lst = lst->next;
	}
	return (max);
}

void	sort_three_element(t_lst **lst)
{
	t_lst	*max_element;

	max_element = ft_search_max_value_lst(*lst);
	if (*lst == max_element)
		ra(lst);
	else if ((*lst)->next == max_element)
		rra(lst);
	if ((*lst)->value > (*lst)->next->value)
		sa(lst);
}

