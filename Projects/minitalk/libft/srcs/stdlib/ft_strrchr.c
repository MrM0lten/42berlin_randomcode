/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:41:17 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/09 10:12:37 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = 0;
	while (*str != '\0')
	{
		if (*str == (char)c)
			ptr = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (ptr);
}
