/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:55:56 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/05 09:37:00 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ch_dest;
	const char	*ch_src;

	if (!dest && !src)
		return (0);
	ch_dest = dest;
	ch_src = src;
	i = 0;
	while (i < n)
	{
		ch_dest[i] = ch_src[i];
		i++;
	}
	return (dest);
}
