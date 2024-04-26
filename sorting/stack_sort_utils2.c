/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:48:40 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 11:51:10 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_sort_ra_up(t_list	**stack_a, t_list *node_to_push)
{
	while ((*stack_a) != node_to_push)
	{
		if (node_to_push->is_in_top == 1)
			ra_or_rb(stack_a, 'a');
		else if (node_to_push->is_in_top == 0)
			rra_or_rrb(stack_a, 'a');
	}
}

void	stack_sort_rrb_down(t_list **stack_b, t_list *node_to_push)
{
	while ((*stack_b) != node_to_push->target)
	{
		if (node_to_push->target->is_in_top == 1)
			ra_or_rb(stack_b, 'b');
		else if (node_to_push->target->is_in_top == 0)
			rra_or_rrb(stack_b, 'b');
	}
}
