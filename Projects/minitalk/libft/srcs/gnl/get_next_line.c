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

char	*fill_buffer(int fd, char *buffer);
char	*get_new_line(char *buffer);
char	*free_and_fail(char *buffer, char *rtn_str);

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

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	if (rtn_str == NULL)
		rtn_str = ft_calloc(1, sizeof(char));
	if (!rtn_str)
		return (free_and_fail(buffer, rtn_str));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_and_fail(buffer, rtn_str));
		rtn_str = ft_strjoin1(rtn_str, buffer, bytes_read);
		if (!rtn_str)
			return (free_and_fail(buffer, rtn_str));
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (rtn_str);
}

char	*free_and_fail(char *buffer, char *rtn_str)
{
	free(buffer);
	free(rtn_str);
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
