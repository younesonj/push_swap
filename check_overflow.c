/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:21:42 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 10:38:45 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker_atoi(char c, int neg, char c1)
{
	if (c == '8' && neg == -1 && c1 == 0)
		return (0);
	else
		return (1);
}

int	ft_atoi_pro_max(char *str)
{
	int	i;
	int	neg;
	int	res;
	int	prev_res;

	prev_res = 0;
	res = 0;
	neg = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev_res = res;
		res = res * 10 + (str[i] - 48);
		if ((res / 10) != prev_res)
			return (checker_atoi(str[i], neg, str[i + 1]));
		i++;
	}
	return (0);
}

void	check_overflow(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (ft_atoi_pro_max(strs[i]) == 1 && ft_strlen(strs[i]) >= 10)
		{
			free_strs(strs);
			ft_exit_msg();
		}
		i++;
	}
}
