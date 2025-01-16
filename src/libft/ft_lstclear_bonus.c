/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:30:20 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/15 15:29:31 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst)
{
	if (lst && *lst)
	{
		ft_lstclear(&(*lst)->next);
		ft_lstdelone(*lst);
		*lst = NULL;
	}
}
