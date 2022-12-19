/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:35:17 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 21:55:22 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	print_arguments(va_list args, char c);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total_chars;
	int		i;

	va_start(args, str);
	total_chars = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			total_chars += print_arguments(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			total_chars++;
		}	
		i++;
	}
	va_end(args);
	return (total_chars);
}

static int	print_arguments(va_list args, char c)
{
	int	item_length;

	item_length = 0;
	if (c == 'c')
		item_length += ft_putchar(va_arg(args, int));
	else if (c == 's')
		item_length += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		item_length += ft_put_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		item_length += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		item_length += ft_put_unsigned_nbr(va_arg(args, unsigned int));
	else if (c == 'x')
		item_length += ft_put_hexnbr(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		item_length += ft_put_hexnbr(va_arg(args, unsigned int), 1);
	else if (c == '%')
		item_length += ft_putchar('%');
	return (item_length);
}
