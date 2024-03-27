#include "../push_swap.h"

void    push_list(t_list **src, t_list **dest)
{
    if (len_list(src) < 1)
        return ;
    t_list *head_a = *src;
    t_list *head_b = *dest;

    *src = head_a->next;

    head_a->next = head_b;
    *dest = head_a;
}

void    pa(t_list **a, t_list **b)
{
    push_list(b, a);
    ft_printf("pa\n");
}

void    pb(t_list **b, t_list **a)
{
    push_list(a, b);
    ft_printf("pb\n");
}