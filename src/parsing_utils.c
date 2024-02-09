/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac < fsulvac@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:44:53 by fsulvac           #+#    #+#             */
/*   Updated: 2024/02/09 14:49:46 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_extract_values(t_list *lst, int *values)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		values[i++] = lst->value;
		lst = lst->next;
	}
}

static void	ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	init_index(t_list *lst)
{
	int		*values;
	t_list	*current;
	size_t	i;

	values = (int *)malloc(lst_size(&lst) * sizeof(int));
	ft_extract_values(lst, values);
	ft_bubble_sort(values, lst_size(&lst));
	current = lst;
	i = 0;
	while (i < lst_size(&lst))
	{
		while (current != NULL)
		{
			if (current->value == values[i])
				current->index = i;
			current = current->next;
		}
		i++;
		current = lst;
	}
	free(values);
}

void	ft_free_list(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
