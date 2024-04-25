#include "../push_swap.h"

t_list  *search_smallest_cost(t_list **list)
{
    t_list *curr = *list;
    t_list *min = *list;
    while (curr != NULL)
    {
        if (min->cost_to_push > curr->cost_to_push)
            min = curr;
        curr = curr->next;
    }
    return (min);
} 


void	push(t_list **stack_a, t_list **stack_b)
{
	t_list *node_to_push = search_smallest_cost(stack_a);
	//rrr
	if (node_to_push->is_in_top == 1 && node_to_push->target->is_in_top == 1)
	{
		while (*stack_a != node_to_push && *stack_b != node_to_push->target)
			rr(stack_a, stack_b);
		set_positions(stack_a);
		set_positions(stack_b);
	}
	//rr
	else if (node_to_push->is_in_top == 0 && node_to_push->target->is_in_top == 0)
	{
		while (*stack_a != node_to_push && *stack_b != node_to_push->target)
			rrr(stack_a, stack_b);
		set_positions(stack_a);
		set_positions(stack_b);
	}
	// ra rra
	while ((*stack_a) != node_to_push)
	{
		if (node_to_push->is_in_top == 1)
			ra_or_rb(stack_a, 'a');
		else if (node_to_push->is_in_top == 0)
			rra_or_rrb(stack_a, 'a');
	}
	//rrb rb
	while ((*stack_b) != node_to_push->target)
	{
		if (node_to_push->target->is_in_top == 1)
			ra_or_rb(stack_b, 'b');
		else if (node_to_push->target->is_in_top == 0)
			rra_or_rrb(stack_b, 'b');
	}
	pb(stack_b, stack_a);
}

void    stack_sort(t_list **stack_a, t_list **stack_b)
{
    pb(stack_b, stack_a);
    pb(stack_b, stack_a);
    while ((*stack_a) != NULL)
    {
        set_positions(stack_a);
        set_positions(stack_b);
        set_target(stack_a, stack_b);
        set_cost_to_push(*stack_a, len_list(stack_a), len_list(stack_b));
		push(stack_a, stack_b);
    }
}