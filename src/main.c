/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:42:31 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 17:15:29 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		size;

	size = 1;
	if (!check_input(argc - 1, argv + 1))
		return (-1);
	a = convert_to_list(argc - 1, argv + 1);
	size = argc - 1;
	b = NULL;
	set_index(a, size + 1);
	sort(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
