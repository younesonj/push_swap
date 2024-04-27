/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:23:20 by younajja          #+#    #+#             */
/*   Updated: 2024/04/27 15:18:21 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_all(t_list **stack_a, t_list **stack_b)
{
	if (check_is_sorted(stack_a) == 1)
	{
		free_list(stack_a);
		exit(0);
	}
	if (len_list(stack_a) == 2)
		sa_or_sb(stack_a, 'a', 1);
	else if (len_list(stack_a) == 3)
		sort_three(stack_a);
	else if (len_list(stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		stack_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		exit(1);
	check_args(av);
	stack_a = NULL;
	stack_b = NULL;
	ft_norme(&stack_a, ac, av);
	sorting_all(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
