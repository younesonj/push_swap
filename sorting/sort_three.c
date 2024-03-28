#include "../push_swap.h"



void    sort_three(t_list **list)
{
    t_list * high = search_biggest(list);
    if ((*list) == high)
        ra_or_rb(list, 'a');
    else if ((*list)->next == high)
        rra_or_rrb(list, 'a');
    if ((*list)->value > (*list)->next->value)
        sa_or_sb(list, 'a');
}
