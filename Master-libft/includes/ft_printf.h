/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:30:48 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 21:56:19 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../includes/libft.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_put_unsigned_nbr(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_put_hexnbr(unsigned int nbr, int flag_is_upper);
int		ft_put_ptr(unsigned long long nbr);

#endif
