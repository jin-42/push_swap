/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:45:48 by moon              #+#    #+#             */
/*   Updated: 2024/01/24 14:45:49 by moon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	int				value;
    long             index;
	struct s_list	*next;
}				t_list;

size_t lst_size(t_list **lst);
void ft_add_back(t_list **lst, t_list *node);
void ft_add_front(t_list **lst, t_list *node);
t_list *ft_new_node(int value);
void	printList(t_list *head);

void sa(t_list **head);
void sb(t_list **head);
void ss(t_list  **stack_a, t_list **stack_b);

void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);

void rra(t_list **stack_a);
void rra(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);

void    pa(t_list  **stack_a, t_list **stack_b);
void    pb(t_list  **stack_a, t_list **stack_b);

t_list	*ft_parsing(int ac, char **av);

void init_index(t_list **lst);
#endif 