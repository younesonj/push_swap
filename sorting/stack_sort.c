#include "../push_swap.h"

void    set_target(t_list **stack_a, t_list **stack_b)
{
    t_list *curr_a = *stack_a;
    t_list *small = search_smallest(stack_b);

    while (curr_a != NULL)
    {
        t_list *curr_b = *stack_b;
        int tmp = small->value;
        curr_a->target = small;
        while (curr_b != NULL)
        {
            if ((curr_a->value > curr_b->value) && (curr_b->value > tmp))
            {
                curr_a->target = curr_b;
                tmp = curr_b->value;
            }
            curr_b = curr_b->next;
        }

        if (curr_a->value < tmp)
            curr_a->target = search_biggest(stack_b);

        curr_a = curr_a->next;
    }
}

void    stack_sort(t_list **stack_a, t_list **stack_b)
{
    pb(stack_b, stack_a);
    pb(stack_b, stack_a);
    while (*stack_a)
    {
        set_positions(stack_a);
        set_positions(stack_b);
        set_target(stack_a, stack_b);
        
    }
}