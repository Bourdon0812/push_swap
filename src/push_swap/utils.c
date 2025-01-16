/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:30:35 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 14:29:01 by ilbonnev         ###   ########.fr       */
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

char	**split_args(int argc, char **argv, int *size)
{
	char	**split;
	char	*str;
	int		i;

	str = ft_strdup("");
	if (argc == 2)
		str = ft_strjoin(str, argv[1]);
	else
	{
		i = 0;
		while (++i != argc)
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, argv[i]);
		}
	}
	split = ft_split(str, ' ');
	free(str);
	if (split == NULL)
		return (NULL);
	*size = arraylen(split);
	return (split);
}

t_list	*convert_to_list(int argc, char **argv, int *size)
{
	char	**split;
	t_list	*new;
	t_list	*args;
	int		i;

	split = split_args(argc, argv, size);
	if (!split)
		return (free_tab(split), split = NULL, NULL);
	args = NULL;
	i = 0;
	while (i < *size)
	{
		new = ft_lstnew(ft_atoi(split[i]));
		if (!new)
		{
			ft_lstclear(&args);
			free_tab(split);
			return (NULL);
		}
		ft_lstadd_back(&args, new);
		i++;
	}
	free_tab(split);
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
