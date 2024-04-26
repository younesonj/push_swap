/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:23:28 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 11:30:08 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_list(t_list **src, t_list **dest)
{
	t_list	*head_a;
	t_list	*head_b;

	if (len_list(src) < 1)
		return ;
	head_a = *src;
	head_b = *dest;
	*src = head_a->next;
	head_a->next = head_b;
	*dest = head_a;
}

void	pa(t_list **a, t_list **b)
{
	push_list(b, a);
	ft_printf("pa\n");
}

void	pb(t_list **b, t_list **a)
{
	push_list(a, b);
	ft_printf("pb\n");
}
