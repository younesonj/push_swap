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

void	pa(t_list **a, t_list **b, int sign)
{
	if (len_list(b) < 1)
		return ;
	push_list(b, a);
	if (sign == 1)
		ft_printf("pa\n");
}

void	pb(t_list **b, t_list **a, int sign)
{
	if (len_list(a) < 1)
		return ;
	push_list(a, b);
	if (sign == 1)
		ft_printf("pb\n");
}
