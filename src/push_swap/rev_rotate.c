/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:58:34 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/15 17:21:07 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rev_rotate(t_list **list)
{
	t_list	*bot;
	t_list	*top;

	if (ft_lstsize(*list) <= 1)
		return (0);
	top = *list;
	bot = ft_lstlast(top);
	while (top)
	{
		if (top->next->next == NULL)
		{
			top->next = NULL;
			break ;
		}
		top = top->next;
	}
	bot->next = *list;
	*list = bot;
	return (1);
}

int	rra(t_list **a)
{
	if (!rev_rotate(a))
		return (0);
	ft_putstr_fd("rra\n", 1);
	return (1);
}

int	rrb(t_list **b)
{
	if (!rev_rotate(b))
		return (0);
	ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	rrr(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1 || ft_lstsize(*b) <= 1)
		return (0);
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}
