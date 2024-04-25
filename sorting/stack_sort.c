#include "../push_swap.h"

t_list  *search_smallest_cost(t_list **list)
{
    Node *curr = *list;
    Node *min = *list;
    while (curr != NULL)
    {
        if (min->cost_to_push > curr->cost_to_push)
            min = curr;
        curr = curr->next;
    }
    return (min);
} 


void	push(t_list **stack_a, t_list **stack_b)
{}

void    stack_sort(t_list **stack_a, t_list **stack_b)
{
    pb(stack_b, stack_a);
    pb(stack_b, stack_a);
    while (*stack_a)
    {
        set_positions(stack_a);
        set_positions(stack_b);
        set_target(stack_a, stack_b);
        set_cost_to_push(*stack_a, len_list(stack_a), len_list(stack_b));
		push(stack_a, stack_b);
        
    }
}