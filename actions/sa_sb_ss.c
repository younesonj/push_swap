#include "../push_swap.h"

void    swap_first_two(t_list **list)
{
    t_list  *first = *list;
    t_list  *second = (*list)->next;

    first->next = second->next;
    second->next = first;

    *list = second;
}

void    sa_or_sb(t_list **list, char c)
{
    swap_list (list);
    ft_printf("s%c\n", c);

}

void    ss(t_list **stack_a, t_list **stack_b)
{
    swap_list (stack_a);
    swap_list (stack_b);
    ft_printf("ss\n");
}
