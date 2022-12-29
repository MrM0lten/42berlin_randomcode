/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:01:56 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/09 10:46:30 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t slen)
{
	size_t	n;
	int		i;

	if (*needle == 0)
		return ((char *)haystack);
	n = 0;
	while (haystack[n] != '\0' && n < slen)
	{
		if (haystack[n] == needle[0])
		{
			i = 1;
			while (haystack[i + n] == needle[i]
				&& needle[i] != '\0' && (i + n) < slen)
				i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[n]);
		}
		++n;
	}
	return (0);
}
