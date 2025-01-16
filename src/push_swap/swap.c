/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:33:15 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/15 17:23:21 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap(t_list **list)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	if (ft_lstsize(*list) <= 1)
		return (0);
	first = *list;
	second = first->next;
	if (!first && !second)
		ft_puterror("Error\n probleme rencontre lors du swap");
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	return (1);
}

int	sa(t_list **a)
{
	if (!swap(a))
		return (0);
	ft_putstr_fd("sa\n", 1);
	return (1);
}

int	sb(t_list **b)
{
	if (!swap(b))
		return (0);
	ft_putstr_fd("sb\n", 1);
	return (1);
}

int	ss(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1 || ft_lstsize(*b) <= 1)
		return (0);
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
	return (1);
}