/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:06:41 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 15:13:32 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sorts2(t_list **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sorts3(t_list **a)
{
	int		max;
	t_list	*tmp;

	tmp = *a;
	max = tmp->index;
	if (ft_is_sorted(*a))
		return ;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	if ((*a)->index == max)
		ra(a);
	else if ((*a)->next->index == max)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sort(t_list **a, t_list **b)
{
	int	size;
	
	size = ft_lstsize(*a);
	if (size == 2)
		sorts2(a);
	else if (size == 3)
		sorts3(b);
	else if (size > 3)
		quick_sort(a, b);
}