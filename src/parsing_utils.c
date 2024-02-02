#include "../include/push_swap.h"

static void assign_indexes(t_list **lst)
{
    long i;
    t_list *tmp;

    i = 0;
    tmp = *lst;
    while (tmp != NULL)
    {
        tmp->index = i;
        i++;
        tmp = tmp->next;
    }
}

static void ft_swap_index(t_list *a, t_list *b)
{
    long temp;
    
    temp = a->index;
    a->index = b->index;
    b->index = temp;
}

void init_index(t_list **lst)
{
    t_list *tmp;
    t_list *tmp_j;

    assign_indexes(lst);
    tmp = *lst;
    while (tmp != NULL)
    {
        tmp_j = tmp->next;
        while (tmp_j != NULL)
        {
            if (tmp->value > tmp_j->value && tmp->index < tmp_j->index)
                ft_swap_index(tmp, tmp_j);
            tmp_j = tmp_j->next;
        }
        tmp = tmp->next;
    }
}