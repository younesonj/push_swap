/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:23:34 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 11:29:51 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate_list(t_list **list)
{
	t_list	*first;
	t_list	*prev;
	t_list	*curr;
	t_list	*last;

	if (len_list(list) == 1)
		return ;
	first = *list;
	curr = *list;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	last = curr;
	prev->next = NULL;
	last->next = first;
	*list = last;
}

void	rra_or_rrb(t_list **list, char c)
{
	rrotate_list(list);
	ft_printf("rr%c\n", c);
}

void	rrr(t_list **a, t_list **b)
{
	rrotate_list(a);
	rrotate_list(b);
	ft_printf("rrr\n");
}
