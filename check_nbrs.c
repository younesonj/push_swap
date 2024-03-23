#include "push_swap.h"

void    ft_exit_msg(char *str)
{
    printf("Error! %s", str);
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
            ft_exit_msg("More than one sign in a number.");
        while (strs[i][j])
        {
            if (!(strs[i][j] >= '0' && strs[i][j] <= '9')) 
                ft_exit_msg("Enter digits !");
            j++;
        }
        if (sign == j)
            ft_exit_msg("Enter number !");
        i++;
    }
}

