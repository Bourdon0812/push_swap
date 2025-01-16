/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:41:25 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 16:55:25 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	apply_operation(t_list **a, t_list **b, char *line)
{
	if (!(ft_strcmp(line, "sa\n")))
		return (swap(a));
	else if (!(ft_strcmp(line, "sb\n")))
		return (swap(b));
	else if (!(ft_strcmp(line, "ss\n")))
		return (swap(a) && swap(b));
	else if (!(ft_strcmp(line, "pa\n")))
		return (push(b, a));
	else if (!(ft_strcmp(line, "pb\n")))
		return (push(a, b));
	else if (!(ft_strcmp(line, "ra\n")))
		return (rotate(a));
	else if (!(ft_strcmp(line, "rb\n")))
		return (rotate(b));
	else if (!(ft_strcmp(line, "rr\n")))
		return (rotate(a) && rotate(b));
	else if (!(ft_strcmp(line, "rra\n")))
		return (rev_rotate(a));
	else if (!(ft_strcmp(line, "rrb\n")))
		return (rev_rotate(b));
	else if (!(ft_strcmp(line, "rrr\n")))
		return (rev_rotate(a) && rev_rotate(b));
	return (-1);
}

static int	run_checker(t_list **a, t_list **b, char *line)
{
	int	check;

	while (line != NULL)
	{
		check = apply_operation(a, b, line);
		if (check <= 0)
		{
			free(line);
			ft_lstclear(a);
			ft_lstclear(b);
			return (check);
		}
		if (ft_is_sorted(*a) && ft_lstsize(*b) <= 0)
			break ;
		free(line);
		line = get_next_line(0);
	}
	if (ft_is_sorted(*a) && ft_lstsize(*b) <= 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(a);
	ft_lstclear(b);
	free(line);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;
	int		check;

	b = NULL;
	if (!check_input(argc, argv))
		return (-1);
	a = convert_to_list(argc, argv);
	line = get_next_line(0);
	check = run_checker(&a, &b, line);
	if (check == -1)
		ft_puterror("Error");
	else if (!check)
		ft_putstr_fd("KO\n", 1);
	get_next_line(-1);
	return (0);
}
