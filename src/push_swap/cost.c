/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:37:22 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/15 17:06:44 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_cost_a(t_list **a, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
	}
}

void	rotate_cost_b(t_list **b, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
	}
}

void	set_cost(t_list **a, t_list **b)
{
	t_list	*bcopy;
	int		size_a;
	int		size_b;

	bcopy = *b;
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	while (bcopy)
	{
		bcopy->cost = bcopy->pos;
		if (bcopy->pos > size_b / 2)
			bcopy->cost = bcopy->pos - size_b;
		bcopy->target_cost = bcopy->target_pos;
		if (bcopy->target_pos > size_a / 2)
			bcopy->target_cost = bcopy->target_pos - size_a;
		bcopy = bcopy->next;
	}
}

void	set_best_moov(t_list **a, t_list **b, int cost, int target_cost)
{
	if (cost < 0 && target_cost < 0)
	{
		while (cost < 0 && target_cost < 0)
		{
			cost++;
			target_cost++;
			rrr(a, b);
		}
	}
	else if (cost > 0 && target_cost > 0)
	{
		while (cost > 0 && target_cost > 0)
		{
			cost--;
			target_cost--;
			rr(a, b);
		}
	}
	rotate_cost_a(a, &target_cost);
	rotate_cost_b(b, &cost);
	pa(a, b);
}
