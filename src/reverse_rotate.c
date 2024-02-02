#include "../include/push_swap.h"

static void	ft_reverse_rotate(t_list **src)
{
	t_list	*tmp;

	if (*src == NULL || (*src)->next == NULL)
		return ;
	tmp = *src;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *src;
	*src = tmp->next;
	tmp->next = NULL;
}

void	rra(t_list **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rra(t_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_reverse_rotate(stack_a);
	ft_printf("rrr\n");
}