/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:38:28 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/16 16:53:08 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H
# define T_LIST_H

typedef struct s_list	t_list;

struct			s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost;
	int				target_cost;
	t_list			*next;
};

#endif