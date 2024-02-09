/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac < fsulvac@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:57:06 by fsulvac           #+#    #+#             */
/*   Updated: 2024/02/09 14:57:47 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_libft/include/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

size_t				lst_size(t_list **lst);
void				ft_add_back(t_list **lst, t_list *node);
void				ft_add_front(t_list **lst, t_list *node);
t_list				*ft_new_node(int value);
void				print_list(t_list *head);

void				sa(t_list **head);
void				sb(t_list **head);
void				ss(t_list **stack_a, t_list **stack_b);

void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);

void				rra(t_list **stack_a);
void				rra(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);

t_list				*ft_parsing(int ac, char **av);
void				ft_free_list(t_list *head);
void				init_index(t_list *lst);
bool				ft_check_sort(t_list **lst);
void				sort_three_element(t_list **lst);
void				sort_four_element(t_list **a, t_list **b);
void				sort_five_element(t_list **a, t_list **b);
t_list				*ft_search_max_value_lst(t_list *lst);
int					ft_get_min_value(t_list **lst);
int					ft_get_min_pos(t_list **lst);
#endif
