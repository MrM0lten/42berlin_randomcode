/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:04:09 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 22:04:32 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_put_unsigned_nbr(unsigned int n)
{
	char	*nbr_str;
	int		i;

	i = 0;
	if (n == 0)
		i += ft_putchar('0');
	else
	{
		nbr_str = ft_uitoa(n);
		ft_putstr(nbr_str);
		i = ft_strlen(nbr_str);
		free(nbr_str);
	}
	return (i);
}
