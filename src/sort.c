/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac < fsulvac@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:45:28 by fsulvac           #+#    #+#             */
/*   Updated: 2024/02/09 14:45:29 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_element(t_list **lst)
{
	t_list	*max_element;

	max_element = ft_search_max_value_lst(*lst);
	if (*lst == max_element)
		ra(lst);
	else if ((*lst)->next == max_element)
		rra(lst);
	if ((*lst)->index > (*lst)->next->index)
		sa(lst);
}

void	sort_four_element(t_list **a, t_list **b)
{
	int	min;

	min = ft_get_min_pos(a);
	if (ft_check_sort(a))
		return ;
	else if (min == 1)
		ra(a);
	else if (min == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min == 3)
		rra(a);
	if (ft_check_sort(a))
		return ;
	pb(a, b);
	sort_three_element(a);
	pa(b, a);
}

void	sort_five_element(t_list **a, t_list **b)
{
	int	min;

	min = ft_get_min_pos(a);
	if (ft_check_sort(a))
		return ;
	else if (min == 1)
		ra(a);
	else if (min == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min == 4)
		rra(a);
	if (ft_check_sort(a))
		return ;
	pb(a, b);
	sort_four_element(a, b);
	pa(b, a);
	pa(b, a);
}
