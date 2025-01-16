/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:30:35 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 17:16:25 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_tab(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

t_list	*convert_to_list(int argc, char **argv)
{
	char	**split;
	t_list	*new;
	t_list	*args;
	int		i;

	split = argv;
	args = NULL;
	i = 0;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(split[i]));
		if (!new)
		{
			ft_lstclear(&args);
			return (NULL);
		}
		ft_lstadd_back(&args, new);
		i++;
	}
	return (args);
}

void	set_index(t_list *a, int size)
{
	t_list	*ptr;
	t_list	*high;
	int		value;

	while (--size > 0)
	{
		ptr = a;
		value = INT_MIN;
		high = NULL;
		while (ptr != NULL)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				high = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (high != NULL)
			high->index = size;
	}
}
