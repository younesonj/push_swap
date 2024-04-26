/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:23:31 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 10:23:32 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_list(t_list **list)
{
	t_list	*first;
	t_list	*curr;
	t_list	*second;
	t_list	*last;

	if (len_list(list) == 1)
		return ;
	first = *list;
	curr = *list;
	second = (*list)->next;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	last = curr;
	last->next = first;
	first->next = NULL;
	*list = second;
}

void	ra_or_rb(t_list **list, char c)
{
	rotate_list(list);
	ft_printf("r%c\n", c);
}

void	rr(t_list **list_a, t_list **list_b)
{
	rotate_list(list_a);
	rotate_list(list_b);
	ft_printf("rr\n");
}
