/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@42.lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:45:01 by fsulvac           #+#    #+#             */
/*   Updated: 2024/02/13 17:15:27 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*split_to_lst(char **strs)
{
	t_list	*head;
	size_t	i;
	t_list	*node;
	t_list	*tmp;

	head = NULL;
	i = 0;
	while (strs[i] != NULL)
	{
		node = ft_new_node(ft_atoi(strs[i]));
		if (node == NULL)
		{
			while (head != NULL)
			{
				tmp = head->next;
				free(head);
				head = tmp;
			}
			return (NULL);
		}
		ft_add_back(&head, node);
		i++;
	}
	return (head);
}

void	free_split(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static bool	check_value_identical(t_list **head)
{
	t_list	*tmp_i;
	t_list	*tmp_j;

	tmp_i = *head;
	while (tmp_i != NULL)
	{
		tmp_j = tmp_i->next;
		while (tmp_j != NULL)
		{
			if (tmp_i->value == tmp_j->value)
				return (false);
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
	return (true);
}

static bool	error_syntax(const char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || ft_isdigit(str[i])))
		return (true);
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
		return (true);
	while (str[++i])
	{
		if (!(ft_isdigit(str[i])))
			return (true);
	}
	return (false);
}

t_list	*ft_parsing(char **av)
{
	int i;
	t_list *lst;

	i = -1;
	while (av[++i])
	{
		if (error_syntax(av[i]))
			return (ft_printf("In $ARG, just number and space please !"), NULL);
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (ft_printf("Entry superior INT"), NULL);
	}
	lst = split_to_lst(av);
	if (lst == NULL)
		return (ft_printf("Error in lst, lst is NULL"), NULL);
	if (check_value_identical(&lst) == false)
		return (ft_printf("two number are equal !\n"), ft_free_list(lst), NULL);
	init_index(lst);
	return (lst);
}
