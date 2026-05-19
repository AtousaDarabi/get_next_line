/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarabi <adarabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:51:16 by adarabi           #+#    #+#             */
/*   Updated: 2026/05/19 20:40:13 by adarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_first_line(char *s)
{
	char	*str;
	int		idx;

	if (!s || !s[0])
		return (NULL);
	idx = 0;
	while (s[idx] && s[idx] != '\n')
		idx++;
	str = malloc(sizeof(char) * (idx + (s[idx] == '\n') + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (s[idx] && s[idx] != '\n')
	{
		str[idx] = s[idx];
		idx++;
	}
	if (s[idx] == '\n')
		str[idx++] = '\n';
	str[idx] = 0;
	return (str);
}

char	*line_after(char *s)
{
	char	*str;
	int		idx;
	int		idx2;

	idx = 0;
	idx2 = 0;
	while (s[idx] && s[idx] != '\n')
		idx++;
	if (!s[idx])
	{
		free(s);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(s) - idx + 1));
	if (!str)
	{
		free(s);
		return (NULL);
	}
	idx++;
	while (s[idx])
		str[idx2++] = s[idx++];
	str[idx2] = '\0';
	free(s);
	return (str);
}

static char	*read_loop(int fd, char *s, char *buff)
{
	int	count;

	count = 1;
	while (count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(s);
			return (NULL);
		}
		if (count == 0)
			break ;
		buff[count] = '\0';
		s = ft_strjoin(s, buff);
		if (!s)
			return (NULL);
		if (ft_chrfind(buff, '\n'))
			break ;
	}
	return (s);
}

char	*file_read(int fd, char *s)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(s);
		return (NULL);
	}
	s = read_loop(fd, s, buff);
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*first_line;

	if (fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = file_read(fd, str[fd]);
	if (!str[fd] || !str[fd][0])
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	first_line = get_first_line(str[fd]);
	if (!first_line)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = line_after(str[fd]);
	return (first_line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
//     int     fd;
//     char    *line;

//     fd = open("file-one.txt", O_RDONLY);
//     if (fd < 0)
//         return (1);
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }
