/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:54:21 by fsulvac           #+#    #+#             */
/*   Updated: 2024/01/24 14:31:24 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	void *content;
	struct s_list *n;
	struct s_list *p;
} t_list;

t_list *ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->n = NULL;
	new->p = NULL;
	new->content = content;
	return (new);
}

t_list	*ft_lstadd_front(t_list **lst, t_list *new)
