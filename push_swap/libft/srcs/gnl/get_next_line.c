/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:13:52 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/16 11:33:06 by jisserst         ###   ########.fr       */
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
char	*trim_buffer(char *buffer);
int		read_failed(int bytes_read, char *buffer, char *rtn_str);

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

	buffer = ft_calloc1((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	if (rtn_str == NULL)
		rtn_str = ft_calloc1(1, sizeof(char));
	if (!rtn_str)
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}
		
	bytes_read = 1;
	i = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (read_failed(bytes_read, buffer, rtn_str))
			return (NULL);
		buffer[bytes_read] = '\0';
		rtn_str = ft_strjoin1(rtn_str, buffer, bytes_read);
		if(!rtn_str)
		{
			read_failed(-1, buffer, rtn_str);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		i++;
	}
	free(buffer);
	buffer = 0;
	return (rtn_str);
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

char	*trim_buffer(char *buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(buffer);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_calloc(len - i + 1, sizeof(char));
	if (!temp)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
		temp[j++] = buffer[i++];
	free(buffer);
	buffer = 0;
	return (temp);
}
