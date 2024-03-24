#include "push_swap.h"

void    insert_ls_end(t_list **list,int value)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        exit(EXIT_FAILURE);
    new_node->value = value;
    new_node->next = NULL;
    if (*list == NULL)
    {
        *list = new_node;
        return ;
    }
    t_list *curr = *list;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

void    print_ls(t_list **list)
{
    t_list *curr = *list;
    while (curr != NULL)
    {
        ft_printf("%d\n", curr->value);
        curr = curr->next;
    }
}

void    free_list(t_list **list)
{
    t_list *curr = *list;
    while (curr != NULL)
    {
        t_list *aux = curr->next;
        free(curr);
        curr = aux;
    }
    *list = NULL;
}