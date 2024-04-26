/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:23:20 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 11:21:26 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int ac, char **strs)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	if (ac < 2)
		exit (1);
	while (strs[i])
	{
		count = 0;
		j = 0;
		if (ft_strlen(strs[i]) == 0)
			ft_exit_msg();
		while (strs[i][j])
		{
			if (strs[i][j] != 32)
				count++;
			j++;
		}
		if (count == 0)
			ft_exit_msg();
		i++;
	}
	return (0);
}

char	**read_numbers(char **arr_nb, int size)
{
	char	**res;
	char	*s;
	int		i;

	s = ft_strdup("");
	i = 1;
	while (i < size)
	{
		s = ft_strjoin(s, arr_nb[i]);
		s = ft_strjoin(s, " ");
		i++;
	}
	res = ft_split(s, ' ');
	free(s);
	return (res);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	sorting_all(t_list **stack_a, t_list **stack_b)
{
	if (check_is_sorted(stack_a) == 1)
	{
		free_list(stack_a);
		exit(0);
	}
	if (len_list(stack_a) == 2)
		sa_or_sb(stack_a, 'a');
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
	int		len;
	int		*tab;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	check_args(ac, av);
	ft_check_nbrs(read_numbers(av, ac));
	check_overflow(read_numbers(av, ac));
	len = len_strs(read_numbers(av, ac));
	tab = convert_strs_tab(read_numbers(av, ac));
	free_strs(read_numbers(av, ac));
	int_check_doubles(tab, len);
	i = 0;
	while (i < len)
		insert_ls_end(&stack_a, tab[i++]);
	free(tab);
	sorting_all(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
