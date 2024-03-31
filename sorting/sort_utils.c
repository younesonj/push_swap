#include "../push_swap.h"

t_list  *search_biggest(t_list **list)
{
    t_list *curr = *list;
    t_list *high = *list;
    while (curr != NULL)
    {
        if (high->value < curr->value)
            high = curr;
        curr = curr->next;
    }
    return (high);
}
t_list  *search_smallest(t_list **list)
{
    t_list *curr = *list;
    t_list *less = *list;
    while (curr != NULL)
    {
        if (less->value > curr->value)
            less = curr;
        curr = curr->next;
    }
    return (less);
} 


void    set_positions(t_list **list)
{
    int midd = len_list(list) / 2;
    t_list *curr = *list;
    int i = 0;
    while (curr != NULL)
    {
        curr->index = i;
        if (i <= midd)
            curr->is_in_top = 1;
        else
            curr->is_in_top = 0;
        i++;
        curr = curr->next;
    }
}



