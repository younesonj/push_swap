#include "../push_swap.h"

void    swap_list(t_list **list)
{
    t_list  *first = *list;
    t_list  *second = (*list)->next;

    first->next = second->next;
    second->next = first;

    *list = second;
}

void    sa_and_sb(t_list **list, char c)
{
    swap_list (list);
    if (c == 'a')
        ft_printf("sa\n");
    else
        ft_printf("sb\n");
}
