/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:00:03 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 22:00:24 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putnbr(int n)
{
	char	*nbr_str;
	int		i;

	nbr_str = ft_itoa(n);
	ft_putstr(nbr_str);
	i = ft_strlen(nbr_str);
	free(nbr_str);
	return (i);
}
