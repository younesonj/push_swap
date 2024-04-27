/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:46:41 by younajja          #+#    #+#             */
/*   Updated: 2024/04/27 15:23:20 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **strs)
{
	int	i;
	int	count;
	int	j;

	i = 0;
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

void	ft_norme(t_list **stack_a, int ac, char **av)
{
	int		i;
	char	**strs;
	int		len;
	int		*tab;

	i = 0;
	strs = read_numbers(av, ac);
	ft_check_nbrs(strs);
	check_overflow(strs);
	len = len_strs(strs);
	tab = convert_strs_tab(strs);
	free_strs(strs);
	int_check_doubles(tab, len);
	i = 0;
	while (i < len)
		insert_ls_end(stack_a, tab[i++]);
	free(tab);
}
