/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost_to_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:31:11 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 11:35:32 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	compare_big(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	set_cost_to_push(t_list *a, int len_a, int len_b)
{
	while (a)
	{
		if (a->is_in_top == 1)
		{
			if (a->target->is_in_top == 1)
				a->cost_to_push = compare_big(a->index, a->target->index);
			else
				a->cost_to_push = a->index + (len_b - a->target->index);
		}
		else
		{
			if (a->target->is_in_top == 1)
				a->cost_to_push = (len_a - a->index) + a->target->index;
			else
				a->cost_to_push = compare_big((len_a - a->index), (len_b
							- a->target->index));
		}
		a = a->next;
	}
}
