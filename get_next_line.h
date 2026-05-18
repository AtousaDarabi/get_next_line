/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarabi <adarabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:51:44 by adarabi           #+#    #+#             */
/*   Updated: 2026/05/18 22:01:50 by adarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

void    ft_strlcpy(char *dst, char *src, size_t size);
size_t  ft_strlen(char *str);
int     ft_chrfind(char *str, int c);
char    *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);

#endif
