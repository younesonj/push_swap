/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:38:25 by younajja          #+#    #+#             */
/*   Updated: 2024/04/27 15:21:18 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_moves(t_list **stack_a, t_list **stack_b, char *s)
{
	if (ft_strcmp(s, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(s, "pb\n") == 0)
		pb(stack_b, stack_a, 0);
	else if (ft_strcmp(s, "ra\n") == 0)
		ra_or_rb(stack_a, 'a', 0);
	else if (ft_strcmp(s, "rb\n") == 0)
		ra_or_rb(stack_b, 'b', 0);
	else if (ft_strcmp(s, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(s, "rra\n") == 0)
		rra_or_rrb(stack_a, 'a', 0);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rra_or_rrb(stack_b, 'b', 0);
	else if (ft_strcmp(s, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strcmp(s, "sa\n") == 0)
		sa_or_sb(stack_a, 'a', 0);
	else if (ft_strcmp(s, "sb\n") == 0)
		sa_or_sb(stack_b, 'b', 0);
	else if (ft_strcmp(s, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else
		ft_exit_msg();
}

void	ft_checker(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		ft_moves(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	if (check_is_sorted(stack_a) == 1 && !(*stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	check_args(av);
	ft_norme(&stack_a, ac, av);
	ft_checker(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
}
