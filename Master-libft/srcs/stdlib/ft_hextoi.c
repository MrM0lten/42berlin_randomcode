/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:58:42 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/08 13:58:43 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_hextoi(char *str)
{
	int	i;
	int	rtn;
	int	byte;

	i = 0;
	rtn = 0;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			byte = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			byte = str[i] - 'A' + 10;
		else
			byte = str[i] - '0';
		rtn = (rtn << 4) | (byte & 0xF);
		i++;
	}
	return (rtn);
}
