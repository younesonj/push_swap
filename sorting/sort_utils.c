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

void    set_target(t_list **stack_a, t_list **stack_b)
{
    t_list *curr_a = *stack_a;
    t_list *small = search_smallest(stack_b);

    while (curr_a != NULL)
    {
        t_list *curr_b = *stack_b;
        int tmp = small->value;
        curr_a->target = small;
        while (curr_b != NULL)
        {
            if ((curr_a->value > curr_b->value) && (curr_b->value > tmp))
            {
                curr_a->target = curr_b;
                tmp = curr_b->value;
            }
            curr_b = curr_b->next;
        }

        if (curr_a->value < tmp)
            curr_a->target = search_biggest(stack_b);

        curr_a = curr_a->next;
    }
}


int compare_big(int a, int b)
{
    if (a > b)
        return(a);
    return (b);
}

void    set_cost_to_push(t_list   *a, int len_a, int len_b)
{
    while (a)
    {
        if (a->is_in_top == 1) 
        {
            if (a->target->is_in_top == 1) // 1 - 1
                a->cost_to_push = compare_big(a->index, a->target->index);
            else // 1 - 0
                a->cost_to_push = a->index + (len_b - a->target->index);
        }
        else
        {
            if (a->target->is_in_top == 1) // 0 - 1
                a->cost_to_push = (len_a - a->index) + a->target->index;
            else   // 0 - 0
                a->cost_to_push = compare_big((len_a - a->index), (len_b - a->target->index));
        }
        a= a->next;
    }
}