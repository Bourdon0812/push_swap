/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:11:17 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/15 17:16:54 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_pos(t_list **list)
{
	t_list	*ptr;
	int		pos;

	ptr = *list;
	pos = 0;
	while (ptr)
	{
		ptr->pos = pos;
		ptr = ptr->next;
		pos++;
	}
}

int	set_min_target(t_list **list)
{
	t_list	*a;
	int		target_index;
	int		target_pos;

	a = *list;
	target_index = INT_MAX;
	target_pos = 0;
	while (a)
	{
		if (a->index < target_index)
		{
			target_index = a->index;
			target_pos = a->pos;
		}
		a = a->next;
	}
	return (target_pos);
}

int	get_target_pos(t_list **list_a, int b_index)
{
	t_list	*a;
	int		target_index;
	int		target_pos;

	a = *list_a;
	target_index = INT_MAX;
	target_pos = 0;
	while (a)
	{
		if (a->index > b_index && a->index < target_index)
		{
			target_index = a->index;
			target_pos = a->pos;
		}
		a = a->next;
	}
	if (target_index == INT_MAX)
		return (set_min_target(list_a));
	return (target_pos);
}

void	set_target_pos(t_list **list_a, t_list **list_b)
{
	t_list	*b;
	int		target_pos;

	b = *list_b;
	set_pos(list_a);
	set_pos(list_b);
	target_pos = 0;
	while (b)
	{
		target_pos = get_target_pos(list_a, b->index);
		b->target_pos = target_pos;
		b = b->next;
	}
}

int	get_min_index_pos(t_list **list)
{
	t_list	*ptr;
	int		min_index;
	int		pos;

	ptr = *list;
	min_index = INT_MAX;
	set_pos(list);
	pos = ptr->pos;
	while (ptr)
	{
		if (ptr->index < min_index)
		{
			min_index = ptr->index;
			pos = ptr->pos;
		}
		ptr = ptr->next;
	}
	return (pos);
}
