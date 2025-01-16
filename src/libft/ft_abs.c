/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:34:06 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/15 16:11:29 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
