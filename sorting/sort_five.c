/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:23:58 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 10:23:59 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*sml;

	while (len_list(stack_a) > 3)
	{
		set_positions(stack_a);
		sml = search_smallest(stack_a);
		while ((*stack_a) != sml)
		{
			if (sml->is_in_top == 1)
				ra_or_rb(stack_a, 'a', 1);
			else
				rra_or_rrb(stack_a, 'a', 1);
		}
		pb(stack_b, stack_a, 1);
	}
	sort_three(stack_a);
	while ((*stack_b) != NULL)
		pa(stack_a, stack_b, 1);
}
