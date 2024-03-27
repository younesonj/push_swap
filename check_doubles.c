/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:30:20 by younajja          #+#    #+#             */
/*   Updated: 2024/03/25 19:26:31 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_strs(char **strs)
{
	int	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

int	*convert_strs_tab(char **strs)
{
	int	i;
	int	len;
	int	*tab;

	i = 0;
	len = len_strs(strs);
	tab = (int *)malloc(len * sizeof(int));
	while (i < len)
	{
		tab[i] = ft_atoi(strs[i]);
		i++;
	}
	return (tab);
}

void	int_check_doubles(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				ft_exit_msg("Double number!");
			}
			j++;
		}
		i++;
	}
}
