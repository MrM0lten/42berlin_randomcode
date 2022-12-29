/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:53 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/05 09:34:39 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	get_digits(int n)
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

char	*ft_itoa(int n)
{
	char	*ptr;
	long	temp;
	int		c;

	temp = n;
	c = get_digits(n);
	if (n < 0)
	{
		temp *= -1;
		c++;
	}
	ptr = (char *)malloc(c * sizeof(char) + 1);
	if (!ptr)
		return (0);
	*(ptr + c) = '\0';
	while (c--)
	{
		*(ptr + c) = temp % 10 + '0';
		temp = temp / 10;
	}
	if (n < 0)
		*(ptr + 0) = '-';
	return (ptr);
}
