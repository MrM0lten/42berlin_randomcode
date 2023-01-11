/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:37:42 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/11 13:37:43 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "./libft/includes/libft.h"

void	send_bits(int pid, char c)
{
	int	i;
	int	byte;

	i = 7;
	while (i >= 0)
	{
		byte = (c >> i) & 1L;
		if (byte == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(150);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid == 0)
		return (0);
	i = 0;
	while (av[2][i])
	{
		send_bits(pid, av[2][i]);
		i++;
	}
	usleep(100);
	send_bits(pid, '\n');
	return (0);
}
