/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:05 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/15 17:32:13 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "t_list.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

int		ft_abs(int n);
int		ft_atoi(const char *str);
int		ft_puterror(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getword(char *s, size_t start, size_t end);
int		ft_iswsp(int c);

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int value);
int		ft_lstsize(t_list *lst);
int		ft_is_sorted(t_list *list);

#endif