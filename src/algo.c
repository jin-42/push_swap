/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@42.lyon.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:44:44 by fsulvac           #+#    #+#             */
/*   Updated: 2024/02/13 17:43:03 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_check_sort(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static void	ft_radix_with_index(t_list **lst_a, t_list **lst_b)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = lst_size(lst_a);
	j = 0;
	while (ft_check_sort(lst_a) == false)
	{
		i = 0;
		while (i < size)
		{
			if (((*lst_a)->value >> j) & 1)
				ra(lst_a);
			else
				pb(lst_a, lst_b);
			i++;
		}
		while (*lst_b)
			pa(lst_a, lst_b);
		j++;
	}
}

static void	ft_choose_sort(t_list **a, t_list **b)
{
	if (lst_size(a) == 2)
		sa(a);
	else if (lst_size(a) == 3)
		sort_three_element(a);
	else if (lst_size(a) == 4)
		sort_four_element(a, b);
	else if (lst_size(a) == 5)
		sort_five_element(a, b);
	else if (lst_size(a) >= 6)
		ft_radix_with_index(a, b);
	ft_free_list(*a);
	ft_free_list(*b);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**strs;

	if (ac > 2)
		strs = av + 1;
	else if (ac == 2)
		strs = ft_split(av[1], ' ');
	else
		return (ft_printf("Error syntaxe", 1));
	lst_a = ft_parsing(strs);
	if (lst_a == NULL)
		return (1);
	lst_b = NULL;
	ft_choose_sort(&lst_a, &lst_b);
	return (0);
}
