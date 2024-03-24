/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:45:45 by younajja          #+#    #+#             */
/*   Updated: 2024/03/24 17:23:53 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_msg(char *str)
{
	ft_printf("Error! %s", str);
	exit(1);
}

int	ft_check_is_digit(char **strs, int i, int j)
{
	while (strs[i][j])
	{
		if (!(strs[i][j] >= '0' && strs[i][j] <= '9'))
		{
			free_strs(strs);
			ft_exit_msg("Enter digits!");
		}
		j++;
	}
	return (j);
}

void	ft_check_number_existant(char **strs, int sign, int j)
{
	if (sign == j)
	{
		free_strs(strs);
		ft_exit_msg("");
	}
}

void	ft_check_nb_sign(char **strs, int sign)
{
	if (sign > 1)
	{
		free_strs(strs);
		ft_exit_msg("More than sign before a number!");
	}
}

void	ft_check_nbrs(char **strs)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (strs[i])
	{
		j = 0;
		sign = 0;
		if (strs[i][j] == '-' || strs[i][j] == '+')
		{
			while ((strs[i][j] == '-' || strs[i][j] == '+') && strs[i][j])
			{
				j++;
				sign++;
			}
		}
		ft_check_nb_sign(strs, sign);
		j = ft_check_is_digit(strs, i, j);
		ft_check_number_existant(strs, sign, j);
		i++;
	}
}
