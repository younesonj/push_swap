#include "../push_swap.h"

void    sort_five(t_list **stack_a, t_list **stack_b)
{
    t_list *sml; 
    while (len_list(stack_a) > 3)
    {
        set_positions(stack_a);
        sml = search_smallest(stack_a);
        while ((*stack_a) != sml)
        {
            if (sml->is_in_top == 1)
                ra_or_rb(stack_a, 'a');
            else
                rra_or_rrb(stack_a, 'a');
        }
        pb(stack_b, stack_a);
    }
    sort_three(stack_a);
    while ((*stack_b) != NULL)
        pa(stack_a, stack_b);
}

