/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:45:35 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 16:11:13 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	ls;
	size_t	i;

	if (!s)
		return (NULL);
	ls = ft_strlen(s);
	if (len > ls)
		len = ls;
	if (ls < start)
		len = 0;
	if (start == ls - 1 && len)
		len = 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	if (start < ls)
		ft_strlcpy(ptr, s + start, len + 1);
	else
		ptr[i] = '\0';
	return (ptr);
}
