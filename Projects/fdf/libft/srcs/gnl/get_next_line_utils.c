/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:14:35 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/16 11:36:00 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../includes/get_next_line.h"

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	if (!s || s[i] == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr1(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] != '\0')
		return (i);
	else
		return (0);
}

char	*ft_strjoin1(char *s1, char *s2, size_t s2_len)
{
	char	*ptr;
	size_t	len;
	size_t	i;
	size_t	s1_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen1(s1);
	len = s1_len + s2_len;
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < s1_len)
			ptr[i] = s1[i];
		else
			ptr[i] = s2[i - s1_len];
		i++;
	}
	ptr[i] = '\0';
	free(s1);
	s1 = 0;
	return (ptr);
}

void	ft_bzero1(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

char	*trim_buffer(char *buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen1(buffer);
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
