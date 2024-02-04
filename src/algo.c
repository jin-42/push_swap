#include "../include/push_swap.h"

static bool ft_check_sort(t_list **lst) {
    t_list *tmp = *lst;

    while (tmp != NULL && tmp->next != NULL) {
        if (tmp->value > tmp->next->value)
            return false;
        tmp = tmp->next;
    }
    return true;
}

static void	ft_radix_with_index(t_list **lst_a, t_list **lst_b) {
	size_t	i;
	size_t	j;
	size_t	size;

	size = lst_size(lst_a);
	j = 0;
	while (ft_check_sort(lst_a) == false) {
		i = 0;
		while (i < size) {
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

static void	ft_choose_sort(t_lst **a, t_lst **b)
{
	if (lst_size(a) == 2)
		sa(&a); 
	else if (lst_size(a) == 3)
		sort_three_element(&a);
	else if (lst_size(a) == 4)
		sort_four_element(&a, &b);
	else if (lst_size(a) == 5)
		sort_five_element(&a, &b);
	else if (lst_size(a) >= 6)
	    ft_radix_with_index(&a, &b);
}

int main(int ac, char **av) {
    t_list *lst_a;
    t_list *lst_b;

    lst_a = ft_parsing(ac, av);
    if (lst_a == NULL)
        return 1;
    lst_b = NULL;
    ft_choose_sort(&lst_a, &lst_b);
    printList(lst_a);
    ft_free_list(lst_a);
    return 0;
}