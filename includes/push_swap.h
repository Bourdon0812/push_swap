/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:32:48 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 15:52:09 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include <stdio.h>

//ft_check_input.c
int		check_input(int argc, char **argv);

//utils.c
void	free_tab(char **array);
char	arraylen(char **array);
char	**split_args(int argc, char **argv, int *size);
t_list	*convert_to_list(int argc, char **argv);
void	set_index(t_list *a, int size);

//swap.c
int		swap(t_list **list);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);

//push.c
int		push(t_list **from, t_list **to);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);

//rotate.c
int		rotate(t_list **list);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);

//rev_rotate.c
int		rev_rotate(t_list **list);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);

//sort.c
void	sorts2(t_list **a);
void	sorts3(t_list **a);
void	sort(t_list **a, t_list **b);

//cost.c
void	rotate_cost_a(t_list **a, int *cost);
void	rotate_cost_b(t_list **b, int *cost);
void	set_cost(t_list **a, t_list **b);
void	set_best_moov(t_list **a, t_list **b, int cost, int target_cost);

//pos.c
void	set_pos(t_list **list);
int		set_min_target(t_list **list);
int		get_target_pos(t_list **list_a, int b_index);
void	set_target_pos(t_list **list_a, t_list **list_b);
int		get_min_index_pos(t_list **list);

//quick_sort.c
void	move_to_b(t_list **a, t_list **b);
void	last_sort(t_list **a);
void	best_move(t_list **a, t_list **blist);
void	quick_sort(t_list **a, t_list **b);

#endif