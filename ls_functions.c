/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:36:41 by younajja          #+#    #+#             */
/*   Updated: 2024/03/24 17:38:53 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_ls_end(t_list **list, int value)
{
	t_list	*new_node;
	t_list	*curr;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->value = value;
	new_node->next = NULL;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	curr = *list;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	print_ls(t_list **list)
{
	t_list	*curr;

	curr = *list;
	while (curr != NULL)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->next;
	}
}

void	free_list(t_list **list)
{
	t_list	*curr;
	t_list	*aux;

	curr = *list;
	while (curr != NULL)
	{
		aux = curr->next;
		free(curr);
		curr = aux;
	}
	*list = NULL;
}
