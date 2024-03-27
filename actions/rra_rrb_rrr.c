#include "../push_swap.h"

void    rrotate_list(t_list **list)
{
    if (len_list(list) == 1)
        return ;
    t_list *first = *list;
    t_list *prev;
    t_list *curr = *list;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    t_list *last = curr;

    prev->next = NULL;
    last->next = first;
    *list = last;
}

void    rra_or_rrb(t_list **list, char c)
{
    rrotate_list(list);
    ft_printf("rr%c\n", c);
}

void    rrr(t_list **a, t_list **b)
{
    rrotate_list(a);
    rrotate_list(b);
    ft_printf("rrr\n");
}