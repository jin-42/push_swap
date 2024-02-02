#include "../include/push_swap.h"

static void	ft_push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = *(src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pb\n");
}