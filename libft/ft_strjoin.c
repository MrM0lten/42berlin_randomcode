/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:46:01 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 18:28:31 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (!s1 && !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			ptr[i] = s1[i];
		else
			ptr[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
