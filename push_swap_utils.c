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