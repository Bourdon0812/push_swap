/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:45:03 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/15 17:21:50 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rotate(t_list **list)
{
	t_list	*bot;
	t_list	*top;

	if (ft_lstsize(*list) <= 1)
		return (0);
	top = *list;
	bot = ft_lstlast(top);
	*list = top->next;
	top->next = NULL;
	bot->next = top;
	return (1);
}

int	ra(t_list **a)
{
	if (!rotate(a))
		return (0);
	ft_putstr_fd("ra\n", 1);
	return (1);
}

int	rb(t_list **b)
{
	if (!rotate(b))
		return (0);
	ft_putstr_fd("rb\n", 1);
	return (1);
}

int	rr(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1 || ft_lstsize(*b) <= 1)
		return (0);
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
	return (1);
}
