/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarabi <adarabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:52:00 by adarabi           #+#    #+#             */
/*   Updated: 2026/05/19 20:36:53 by adarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;

	len_s1 = 0;
	len_s2 = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len_s1 = ft_strlen(s1);
	if (s2)
		len_s2 = ft_strlen(s2);
	res = malloc(len_s1 + len_s2 + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	if (s1)
		ft_strlcpy(res, s1, len_s1 + 1);
	else
		res[0] = '\0';
	ft_strlcpy(&res[len_s1], s2, len_s2 + 1);
	free(s1);
	return (res);
}

int	ft_chrfind(char *str, int c)
{
	int	idx;

	if (!str)
		return (0);
	idx = 0;
	if (c == '\0')
		return (0);
	while (str[idx] != 0)
	{
		if (str[idx] == (char)c)
			return (1);
		idx++;
	}
	return (0);
}
