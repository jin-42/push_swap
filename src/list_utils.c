/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac < fsulvac@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:44:38 by fsulvac           #+#    #+#             */
/*   Updated: 2024/02/09 14:56:03 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_printf("\n%d", tmp->value);
		tmp = tmp->next;
	}
}

t_list	*ft_new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	ft_add_front(t_list **lst, t_list *node)
{
	if (node)
	{
		node->next = *lst;
		*lst = node;
	}
}

void	ft_add_back(t_list **lst, t_list *node)
{
	t_list	*tmp;

	if (!lst || !node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
}

size_t	lst_size(t_list **lst)
{
	size_t	i;
	t_list	*tmp;

	i = 1;
	if (!lst)
		return (0);
	tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
