#include "push_swap.h"

t_list    *search_highest_t_list(t_list **list)
{
    t_list *curr = *list;
    t_list *high = *list;
    while (curr != NULL)
    {
        if (high->value < curr->value)
            high = curr;
        curr = curr->next;
    }
    return (high);
}

void    sort_three(t_list **list)
{
    t_list * high = search_highest_t_list(list);
    if ((*list) == high)
        ra_or_rb(list, 'a');
    else if ((*list)->next == high)
        rra_or_rrb(list, 'a');
    if ((*list)->value > (*list)->next->value)
        sa_or_sb(list, 'a');
}