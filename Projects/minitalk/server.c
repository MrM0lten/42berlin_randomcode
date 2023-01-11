/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:37:29 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/11 13:37:30 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "./libft/includes/ft_printf.h"
#include "./libft/includes/libft.h"

void	handler(int signal)
{
	static int	i = 8;
	static char	c = 0;

	if (signal == SIGUSR1)
		c |= 1 << (i - 1);
	i--;
	if (i == 0)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		i = 8;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction		sa;

	(void)av;
	if (ac != 1)
		return (0);
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID = %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
