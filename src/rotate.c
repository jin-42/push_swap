/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac < fsulvac@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:45:24 by fsulvac           #+#    #+#             */
/*   Updated: 2024/02/09 14:46:42 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_rotate(t_list **src)
{
	t_list	*tmp;

	if (*src == NULL || (*src)->next == NULL)
		return ;
	tmp = *src;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *src;
	*src = (*src)->next;
	tmp->next->next = NULL;
}

void	ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
