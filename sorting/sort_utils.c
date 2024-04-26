/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:24:04 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 11:31:35 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*search_biggest(t_list **list)
{
	t_list	*curr;
	t_list	*high;

	curr = *list;
	high = *list;
	while (curr != NULL)
	{
		if (high->value < curr->value)
			high = curr;
		curr = curr->next;
	}
	return (high);
}

t_list	*search_smallest(t_list **list)
{
	t_list	*curr;
	t_list	*less;

	curr = *list;
	less = *list;
	while (curr != NULL)
	{
		if (less->value > curr->value)
			less = curr;
		curr = curr->next;
	}
	return (less);
}

void	set_positions(t_list **list)
{
	int		midd;
	t_list	*curr;
	int		i;

	midd = len_list(list) / 2;
	curr = *list;
	i = 0;
	while (curr != NULL)
	{
		curr->index = i;
		if (i <= midd)
			curr->is_in_top = 1;
		else
			curr->is_in_top = 0;
		i++;
		curr = curr->next;
	}
}

void	set_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr_a;
	t_list	*small;
	t_list	*curr_b;
	int		tmp;

	curr_a = *stack_a;
	small = search_smallest(stack_b);
	while (curr_a != NULL)
	{
		curr_b = *stack_b;
		tmp = small->value;
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
