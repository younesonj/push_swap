#include "push_swap.h"

void    ft_exit_msg(char *str)
{
    ft_printf("Error! %s", str);
    exit(1);
}

void    ft_check_nbrs(char **strs)
{
    int i = 0;
    while (strs[i])
    {
        int j = 0;
        int sign = 0;
        if (strs[i][j] == '-' || strs[i][j] == '+')
        {
            while ((strs[i][j] == '-' || strs[i][j] == '+') && strs[i][j])
            {
                j++;
                sign++;
            }
        }
        if (sign > 1)
        {
            free_strs(strs);
            ft_exit_msg("More than one sign in a number!");
        }
        while (strs[i][j])
        {
            if (!(strs[i][j] >= '0' && strs[i][j] <= '9'))
            {
                free_strs(strs);
                ft_exit_msg("Enter digits!");
            }
            j++;
        }
        if (sign == j)
        {
            free_strs(strs);
            ft_exit_msg("Enter number!");
        }
        i++;
    }
}

int ft_atoi_pro_max(char *str)
{
	int	i;
	int	neg;
	int	res;
    int prev_res;

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
        {
		    if (str[i] == '8' && neg == -1 && str[i + 1] == 0)
		        return 0;
            else
                return (1);
		}
		i++;
	}
	return (0);
}

void    check_overflow(char **strs)
{
    int i = 0;
    while (strs[i])
    {
        if (ft_atoi_pro_max(strs[i]) == 1 && ft_strlen(strs[i]) >= 10)
        {
            free_strs(strs);
            ft_exit_msg("Overflow Detected!");
        }
        i++;
    }
}