/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac < fsulvac@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:50:02 by fsulvac           #+#    #+#             */
/*   Updated: 2024/02/09 15:01:44 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_search_max_value_lst(t_list *lst)
{
	t_list	*max;
	int		max_element;

	max_element = 0;
	while (lst)
	{
		if (lst->index > max_element)
		{
			max = lst;
			max_element = lst->index;
		}
		lst = lst->next;
	}
	return (max);
}

int	ft_get_min_value(t_list **lst)
{
	t_list	*head;
	int		min_value;

	head = *lst;
	min_value = INT_MAX;
	while (head)
	{
		if (head->index < min_value)
			min_value = head->index;
		head = head->next;
	}
	return (min_value);
}

int	ft_get_min_pos(t_list **lst)
{
	t_list		*head;
	int			min_value;
	int			pos;

	head = *lst;
	min_value = ft_get_min_value(lst);
	pos = 0;
	while (head->index != min_value)
	{
		pos++;
		head = head->next;
	}
	return (pos);
}