/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:43:56 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 18:29:42 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	can_trim(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (can_trim(s1[start], set))
		start++;
	while (can_trim(s1[end - 1], set))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	ptr = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}

static int	can_trim(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
