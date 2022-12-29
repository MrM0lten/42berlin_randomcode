/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:34:26 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/02 10:28:10 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *dst, int c, size_t length)
{
	size_t			i;
	unsigned char	*ch_ptr;
	unsigned char	ch;

	ch_ptr = dst;
	i = 0;
	ch = c;
	while (i < length)
	{
		ch_ptr[i] = ch;
		i++;
	}
	return (dst);
}
