/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:33:08 by fsulvac           #+#    #+#             */
/*   Updated: 2024/01/28 16:08:35 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}				t_list;

void	printList(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

/*-------------------------------------------*/
/* -----------------S W A P -----------------*/
/*-------------------------------------------*/
void    ft_swap(t_list **head)
{
    t_list *first;
    t_list *second;

    if (*head == NULL || (*head)->next == NULL)
        return (*head);
    first = *head;
    second = (*head)->next;
    first->next = second->next;
    second->next = first;
    *head = second;
    return *head;
}

void sa(t_list **head)
{
    ft_swap(head);
    ft_printf("sa\n");
}

void sb(t_list **head)
{
    ft_swap(head);
    ft_printf("sb\n");
}

void ss(t_list  **stack_a, t_list **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    ft_printf("ss\n");
}

/*-------------------------------------------*/
/*----------------- P U S H -----------------*/
/*-------------------------------------------*/
void ft_push(t_list **dest, t_list **src)
{
    t_list  *tmp;

    if (!(*src))
        return ;
    tmp = *src;
    *src = *(src)->next;
    tmp -> next = *dest;
    *dest = tmp;
}

void    pa(t_list  **stack_a, t_list **stack_b)
{
    ft_push(stack_a, stack_b);
    ft_printf("pa\n");
}

void    pb(t_list  **stack_a, t_list **stack_b)
{
    ft_push(stack_b, stack_a);
    ft_printf("pb\n");
}

/*-------------------------------------------*/
/*--------------- R O T A T E ---------------*/
/*-------------------------------------------*/

void ft_rotate(t_list **src)
{
    t_list *tmp;

    if (*src == NULL || (*src)->next == NULL)
        return;
    tmp = *src;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = *src;
    *src = (*src)->next; 
    tmp->next->next = NULL;
}

void    ra(t_list **stack_a)
{
    ft_rotate(stack_a);
    ft_printf("ra\n");
}

void    rb(t_list **stack_b)
{
    ft_rotate(stack_b);
    ft_printf("rb\n");
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_printf("rr\n");
}

/*------------------------------------------------------*/
/*-------------- R E V E R S E / R O T A T E -----------*/
/*------------------------------------------------------*/

void ft_reverse_rotate(t_list **src)
{
    t_list *tmp;

    if (*src == NULL || (*src)->next == NULL)
        return ;
    tmp = *src;
    while(tmp->next->next != NULL) 
        tmp = tmp->next;
    tmp->next->next = *src;
    *src = tmp->next;
    tmp->next = NULL;
}

void rra(t_list **stack_a)
{
    ft_reverse_rotate(stack_a);
    ft_printf("rra\n");
}

void rra(t_list **stack_b)
{
    ft_reverse_rotate(stack_b);
    ft_printf("rrb\n");
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    ft_reverse_rotate(stack_b);
    ft_reverse_rotate(stack_a);
    ft_printf("rrr\n");
}


/* ------------------------------- */
/*          P A R S I N G          */
/* --------------------------------*/

