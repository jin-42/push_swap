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

#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*n;
	struct s_list	*p;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
#endif 