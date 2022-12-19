/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:57:11 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 21:59:29 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_hex_digits(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

static void	ft_print_hex(unsigned int nbr, int flag_is_upper)
{
	if (nbr >= 16)
	{
		ft_print_hex(nbr / 16, flag_is_upper);
		nbr %= 16;
	}
	if (nbr > 9 && nbr < 16)
	{
		if (flag_is_upper)
			ft_putchar(nbr - 10 + 'A');
		else
			ft_putchar(nbr - 10 + 'a');
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

int	ft_put_hexnbr(unsigned int nbr, int flag_is_upper)
{
	int	digits;

	digits = calc_hex_digits(nbr);
	ft_print_hex(nbr, flag_is_upper);
	return (digits);
}
