#include "../include/push_swap"

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

t_list	*ft_new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	ft_add_front(t_list **lst, t_list *node)
{
	if (node)
	{
		node->next = *lst;
		*lst = node;
	}
}

void	ft_add_back(t_list **lst, t_list *node)
{
	t_list	*tmp;

	if (!lst)
	{
		*lst = node;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

size_t	lst_size(t_list **lst)
{
	size_t i;

	i = 1;
	if (!lst)
		return (0);
	t_list *tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}