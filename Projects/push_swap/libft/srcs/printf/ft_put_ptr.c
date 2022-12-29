/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:02:11 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 22:02:14 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	calc_hex_digits(unsigned long long nbr)
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

static void	ft_print_hex(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_print_hex(nbr / 16);
		nbr %= 16;
	}
	if (nbr > 9 && nbr < 16)
		ft_putchar(nbr - 10 + 'a');
	else
		ft_putchar(nbr + '0');
}

int	ft_put_ptr(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i += ft_putstr("(nil)");
	else
	{
		i += ft_putstr("0x");
		i += calc_hex_digits(nbr);
		ft_print_hex(nbr);
	}
	return (i);
}
