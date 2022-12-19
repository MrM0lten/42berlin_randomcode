/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:05:02 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/10 22:05:28 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	get_digits(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ptr;
	int		c;

	c = get_digits(n);
	ptr = (char *)malloc(c * sizeof(char) + 1);
	if (!ptr)
		return (0);
	*(ptr + c) = '\0';
	while (c--)
	{
		*(ptr + c) = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}
