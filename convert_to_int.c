#include "push_swap.h"

int len_strs(char **strs)
{
    int len = 0;
    while (strs[len])
        len++;
    return (len);
}

int *convert_strs_tab(char **strs)
{
    int i = 0;
    int len = len_strs(strs);
    int *tab = (int *)malloc(len * sizeof(int));
    while (i < len)
    {
        tab[i] = ft_atoi(strs[i]);
        i++;
    }
    return (tab);
}

void    int_check_doubles(int *tab, int size)
{
    int i = 0;
    while (i < size)
    {
        int j = i + 1;
        while (j < size)
        {
            if (tab[i] == tab[j])
                ft_exit_msg("Double number!");
            j++;
        }
        i++;
    }
}