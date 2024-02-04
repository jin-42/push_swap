#include "../include/push_swap.h"

static bool	check_char(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == ' ') || (s[i] == '-'))
			i++;
		else
			return (false);
	}
	return (true);
}

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

static void	free_split(char **strs)
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

t_list	*ft_parsing(int ac, char **av)
{
	char	**strs;
	t_list	*lst;

	if (ac != 2)
		return (ft_printf("./push_swap $ARG"), NULL);
	if (check_char(av[1]) == false)
		return (ft_printf("In $ARG, just number and space please !"), NULL);
	strs = ft_split(av[1], ' ');
	if (!strs)
		return (ft_printf("Error in split, strs is NULL"), NULL);
	lst = split_to_lst(strs);
	free_split(strs);
	if (lst == NULL)
		return (ft_printf("Error in lst, lst is NULL"), NULL);
	if (check_value_identical(&lst) == false)
		return (ft_printf("In lst, they are at least two number identical !"),
			ft_free_list(lst), NULL);
	init_index(lst);
	return (lst);
}