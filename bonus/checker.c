#include "../push_swap.h"

void    ft_print_lists(t_list **list)
{
    t_list *curr = *list;
    while (curr != NULL)
    {
        ft_printf("%d\n", curr->value);
        curr = curr->next;
    }
}

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_moves(t_list **stack_a, t_list **stack_b, char *s)
{
	if (ft_strcmp(s, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(s, "pb\n") == 0)
		pb(stack_b, stack_a, 0);
	else if (ft_strcmp(s, "ra\n") == 0)
		ra_or_rb(stack_a, 'a', 0);
	else if (ft_strcmp(s, "rb\n") == 0)
		ra_or_rb(stack_b, 'b', 0);
	else if (ft_strcmp(s, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(s, "rra\n") == 0)
		rra_or_rrb(stack_a, 'a', 0);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rra_or_rrb(stack_b, 'b', 0);
	else if (ft_strcmp(s, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strcmp(s, "sa\n") == 0)
		sa_or_sb(stack_a, 'a', 0);
	else if (ft_strcmp(s, "sb\n") == 0)
		sa_or_sb(stack_b, 'b', 0);
	else if (ft_strcmp(s, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else
		ft_exit_msg();
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
    //ft_print_lists(&stack_a);

	// **********************************************
    char *str = get_next_line(0);
    while (str)
	{
		ft_moves(&stack_a, &stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	
	
	if (check_is_sorted(&stack_a) == 1)
	{
		free_list(&stack_a);
		ft_printf("OK");
	}
	else
	{
		free_list(&stack_a);
		ft_printf("KO");
	}

	//ft_print_lists(&stack_a);

}