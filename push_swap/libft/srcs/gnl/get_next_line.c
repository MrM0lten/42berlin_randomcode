/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:13:52 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 21:06:25 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../includes/get_next_line.h"
#include "../../includes/libft.h"

char	*fill_buffer(int fd, char *buffer);
char	*ft_realloc(char *s1, char *s2, size_t s2_len);
char	*get_new_line(char *buffer);
int		read_failed(int bytes_read, char *buffer, char *rtn_str);
int		write_to_buffer(int fd, char *rtn_str, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fill_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_new_line(buffer);
	buffer = trim_buffer(buffer);
	return (line);
}

char	*fill_buffer(int fd, char *rtn_str)
{
	char	*buffer;
	int		bytes_read;
	int		i;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	if (rtn_str == NULL)
		rtn_str = ft_calloc(1, sizeof(char));
	if (!rtn_str)
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}
	bytes_read = 1;
	i = 0;
	if (!write_to_buffer(fd, rtn_str, buffer))
		return (NULL);
	free(buffer);
	buffer = 0;
	return (rtn_str);
}

int	write_to_buffer(int fd, char *rtn_str, char *buffer)
{
	int		bytes_read;
	int		i;

	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (read_failed(bytes_read, buffer, rtn_str))
			return (0);
		buffer[bytes_read] = '\0';
		rtn_str = ft_strjoin1(rtn_str, buffer, bytes_read);
		if (!rtn_str)
		{
			read_failed(-1, buffer, rtn_str);
			return (0);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		i++;
	}
	return (1);
}

int	read_failed(int bytes_read, char *buffer, char *rtn_str)
{
	if (bytes_read == -1)
	{
		free(buffer);
		free(rtn_str);
		buffer = 0;
		rtn_str = 0;
		return (1);
	}
	return (0);
}

char	*get_new_line(char *buffer)
{
	char	*newline;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	newline = ft_calloc(i + 2, sizeof(char));
	if (!newline)
		return (NULL);
	i += 1;
	while (i--)
		newline[i] = buffer[i];
	return (newline);
}
