#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "./libft/includes/libft.h"

void send_bits(int pid, char c)
{
	int i;
	int byte;

	i = 7;
	while(i >= 0)
	{
		byte = (c >> i) & 1L;
		if(byte == 1)
			kill(pid,SIGUSR1);
		else
			kill(pid,SIGUSR2);
		printf("%d", byte);
		i--;
		usleep(1000);
	}
}

int main(int ac, char **av)
{
	int pid;
	int i;

	printf("im the client boiii\n");
	if(ac != 3)
		return (0);
	pid = ft_atoi(av[1]);

	i = 0;
	while(av[2][i])
	{
		send_bits(pid, av[2][i]);
		//usleep(100);
		i++;
	}
	usleep(100);
	send_bits(pid, '\n');
	return (0);
}