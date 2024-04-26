/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:24:01 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 10:24:02 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **list)
{
	t_list	*high;

	high = search_biggest(list);
	if ((*list) == high)
		ra_or_rb(list, 'a', 1);
	else if ((*list)->next == high)
		rra_or_rrb(list, 'a', 1);
	if ((*list)->value > (*list)->next->value)
		sa_or_sb(list, 'a', 1);
}
