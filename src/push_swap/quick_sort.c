/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:09:09 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 15:10:48 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_to_b(t_list **a, t_list **b)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_lstsize(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && pushed < size / 2 && i < size)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

void	last_sort(t_list **a)
{
	int	size;
	int	min_index_pos;

	size = ft_lstsize(*a);
	min_index_pos = get_min_index_pos(a);
	if (min_index_pos > size / 2)
	{
		while (min_index_pos < size)
		{
			rra(a);
			min_index_pos++;
		}
	}
	else
	{
		while (min_index_pos > 0)
		{
			ra(a);
			min_index_pos--;
		}
	}
}

void	best_move(t_list **a, t_list **blist)
{
	t_list	*b;
	int		best;
	int		cost;
	int		target_cost;

	b = *blist;
	best = INT_MAX;
	while (b)
	{
		if (ft_abs(b->cost) + ft_abs(b->target_cost) < ft_abs(best))
		{
			best = ft_abs(b->cost) + ft_abs(b->target_cost);
			cost = b->cost;
			target_cost = b->target_cost;
		}
		b = b->next;
	}
	set_best_moov(a, blist, cost, target_cost);
}

void	quick_sort(t_list **a, t_list **b)
{
	if (ft_is_sorted(*a))
		return ;
	move_to_b(a, b);
	sorts3(a);
	while (*b)
	{
		set_target_pos(a, b);
		set_cost(a, b);
		best_move(a, b);
	}
	if (!ft_is_sorted(*a))
		last_sort(a);
}
