/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:24:07 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 11:48:21 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*search_smallest_cost(t_list **list)
{
	t_list	*curr;
	t_list	*min;

	curr = *list;
	min = *list;
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
	t_list	*node_to_push;

	node_to_push = search_smallest_cost(stack_a);
	if (node_to_push->is_in_top == 1 && node_to_push->target->is_in_top == 1)
	{
		while (*stack_a != node_to_push && *stack_b != node_to_push->target)
			rr(stack_a, stack_b, 1);
		set_positions(stack_a);
		set_positions(stack_b);
	}
	else if (node_to_push->is_in_top == 0
		&& node_to_push->target->is_in_top == 0)
	{
		while (*stack_a != node_to_push && *stack_b != node_to_push->target)
			rrr(stack_a, stack_b, 1);
		set_positions(stack_a);
		set_positions(stack_b);
	}
	stack_sort_ra_up(stack_a, node_to_push);
	stack_sort_rrb_down(stack_b, node_to_push);
	pb(stack_b, stack_a, 1);
}

void	set_bigger_in_top(t_list **stack_b)
{
	t_list	*max;

	max = search_biggest(stack_b);
	set_positions(stack_b);
	if (max->is_in_top == 1)
	{
		while (*stack_b != max)
			ra_or_rb(stack_b, 'b', 1);
	}
	else if (max->is_in_top == 0)
	{
		while (*stack_b != max)
			rra_or_rrb(stack_b, 'b', 1);
	}
}

void	stack_sort(t_list **stack_a, t_list **stack_b)
{
	pb(stack_b, stack_a, 1);
	pb(stack_b, stack_a, 1);
	while ((*stack_a) != NULL)
	{
		set_positions(stack_a);
		set_positions(stack_b);
		set_target(stack_a, stack_b);
		set_cost_to_push(*stack_a, len_list(stack_a), len_list(stack_b));
		push(stack_a, stack_b);
	}
	set_bigger_in_top(stack_b);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
