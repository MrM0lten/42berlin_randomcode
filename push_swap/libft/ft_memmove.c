/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:28:54 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/05 09:03:00 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ch_dest;
	const char	*ch_src;

	ch_dest = dest;
	ch_src = src;
	if (!dest && !src)
		return (0);
	if (ch_src < ch_dest && ch_dest < ch_src + n)
	{
		ch_src += n;
		ch_dest += n;
		while (0 < n)
		{
			--n;
			*--ch_dest = *--ch_src;
		}
	}
	else
	{
		while (0 < n--)
			*ch_dest++ = *ch_src++;
	}
	return (dest);
}
