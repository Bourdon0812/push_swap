/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:37:29 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 15:08:42 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!ft_lstsize(*from))
		return (0);
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	return (1);
}

int	pa(t_list **a, t_list **b)
{
	if (!push(b, a))
		return (0);
	ft_putstr_fd("pa\n", 1);
	return (1);
}

int	pb(t_list **a, t_list **b)
{
	if (!push(a, b))
		return (0);
	ft_putstr_fd("pb\n", 1);
	return (1);
}
