/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:23:36 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 10:23:37 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_list(t_list **list)
{
	t_list	*first;
	t_list	*second;

	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	sa_or_sb(t_list **list, char c)
{
	swap_list(list);
	ft_printf("s%c\n", c);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_list(stack_a);
	swap_list(stack_b);
	ft_printf("ss\n");
}
