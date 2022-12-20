/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:02:10 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/09 10:15:55 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	total;
	int	flag;
	int	found;

	total = 0;
	flag = 1;
	found = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			total = total * 10 + *str - '0';
		else
			found = 0;
		str++;
	}
	return (flag * total);
}
