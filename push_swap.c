#include "push_swap.h"

char    **read_numbers(char **arr_nb, int size)
{
    char **res;
    char *s = ft_strdup("");
    int i = 1;
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
void    free_strs(char **strs)
{
    int i = 0;
    while (strs[i])
        free(strs[i++]);
    free(strs);
}


int main (int ac, char **av)
{
    t_list *stack_a = NULL;
    //t_list *b;

    if (ac < 2)
        ft_exit_msg("Number of arguments!");
    char **strs = read_numbers(av, ac);

    ft_check_nbrs(strs);
    check_overflow(strs);
    // int j = 0;
    // while (strs[j])
    //     ft_printf("\"%s\"\n", strs[j++]);

    int len = len_strs(strs);
    int *tab = convert_strs_tab(strs);
    free_strs(strs);

    int_check_doubles(tab, len);

    int i = 0;
    while (i < len)
        insert_ls_end(&stack_a, tab[i++]);
    free(tab);

    if (check_is_sorted(&stack_a) == 1)
    {
        free_list(&stack_a);
        exit(0);
    }
    if (len_list(&stack_a) == 2)
        sa_or_sb(&stack_a, 'a');




    print_ls(&stack_a);
    free_list(&stack_a);

    return (0);
}


