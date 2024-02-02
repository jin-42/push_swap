#include "../include/push_swap.h"

static void	ft_swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_list **head)
{
	ft_swap(head);
	ft_printf("sa\n");
}

void	sb(t_list **head)
{
	ft_swap(head);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
