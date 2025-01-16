/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:35:18 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/15 14:38:18 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h" 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_has_line(char *str);
char	*ft_strcat(char *str1, char *str2);
void	ft_strncpy(char *dest, char *src, int n);

char	*get_next_line(int fd);

#endif