/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:39:51 by younajja          #+#    #+#             */
/*   Updated: 2024/04/26 11:49:01 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct t_list
{
	int				value;
	int				index;
	int				is_in_top;
	int				cost_to_push;
	struct t_list	*target;
	struct t_list	*next;
}					t_list;

void				insert_ls_end(t_list **list, int value);
void				free_list(t_list **list);
void				ft_check_nbrs(char **strs);
void				ft_exit_msg(void);
int					len_strs(char **strs);
int					*convert_strs_tab(char **strs);
void				int_check_doubles(int *tab, int size);
void				free_strs(char **strs);
void				check_overflow(char **strs);
int					check_is_sorted(t_list **list);
int					len_list(t_list **list);
void				sa_or_sb(t_list **list, char c);
void				ss(t_list **stack_a, t_list **stack_b);
int					len_list(t_list **list);
void				rra_or_rrb(t_list **list, char c);
void				rrr(t_list **a, t_list **b);
void				ra_or_rb(t_list **list, char c);
void				rr(t_list **list_a, t_list **list_b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **b, t_list **a);
void				sort_three(t_list **list);
t_list				*search_biggest(t_list **list);
t_list				*search_smallest(t_list **list);
void				set_positions(t_list **list);
void				sort_five(t_list **stack_a, t_list **stack_b);
void				set_target(t_list **stack_a, t_list **stack_b);
void				set_cost_to_push(t_list *a, int len_a, int len_b);
void				stack_sort(t_list **stack_a, t_list **stack_b);
void				stack_sort_ra_up(t_list	**stack_a, t_list *node_to_push);
void				stack_sort_rrb_down(t_list **stack_b, t_list *node_to_push);

#endif