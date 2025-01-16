/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:02:00 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 18:24:22 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_contains(char **argv)
{
	int	i;
	int	i2;

	i = -1;
	while (argv[++i] != NULL)
	{
		if (ft_strlen(argv[i]) < 1)
			return (ft_puterror("Error\npas que des nombres\n"));
		i2 = 0;
		while (argv[i][i2] != '\0')
		{
			if (argv[i][i2] != ' ' && argv[i][i2] != '\0')
				break ;
			i2++;
			if (argv[i][i2] == '\0')
				return (ft_puterror("Error\npas que des nombres\n"));
		}
	}
	return (1);
}

static int	check_int(char **argv)
{
	int	i;
	int	i2;

	i = -1;
	while (argv[++i] != NULL)
	{
		i2 = -1;
		if (argv[i][0] == '-' && ft_strlen(argv[i]) <= 1)
			return (ft_puterror("Error\npas que des nombres\n"));
		if (argv[i][0] == '-')
			i2++;
		while (argv[i][++i2] != '\0')
		{
			if (!(argv[i][i2] >= '0' && argv[i][i2] <= '9'))
				return (ft_puterror("Error\npas que des nombres\n"));
		}
	}
	return (1);
}

static int	check_max(char **argv)
{
	int		i;
	long	n;

	i = -1;
	while (argv[++i] != NULL)
	{
		n = ft_atoi(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (ft_puterror("Error\npas que des int\n"));
	}
	return (1);
}

static int	check_dup(char **argv)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i] != NULL)
	{
		n = i + 1;
		while (argv[n] != NULL)
		{
			if (ft_strcmp(argv[n], argv[i]) == 0)
				return (ft_puterror("Error\nIl y a des doublons\n"));
			n++;
		}
		i++;
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	char	**args;

	if (argc <= 1)
		return (0);
	args = argv;
	if (!args)
		return (0);
	if (!check_contains(args))
		return (0);
	if (!check_int(args))
		return (0);
	if (!check_max(args))
		return (0);
	if (!check_dup(args))
		return (0);
	return (1);
}
