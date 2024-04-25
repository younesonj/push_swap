#include "../push_swap.h"

void    rotate_list(t_list **list)
{
    if (len_list(list) == 1)
        return ;
    t_list *first = *list;
    t_list *curr = *list;
    t_list *second = (*list)->next;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    t_list *last = curr;
    last->next = first;
    first->next = NULL;
    *list = second;

}

void    ra_or_rb(t_list **list, char c)
{
    rotate_list(list);
    ft_printf("r%c\n", c);
}

void    rr(t_list **list_a, t_list **list_b)
{
    rotate_list(list_a);
    rotate_list(list_b);
    ft_printf("rr\n");
}

