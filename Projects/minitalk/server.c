#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "./libft/includes/ft_printf.h"
#include "./libft/includes/libft.h"

int	flag = 1;

void handler(int signal)
{
	static int i;
	static int c;

	if (flag)
	{
		i = 8;
		c = 0;
		flag = 0;
	}
	if (signal == SIGUSR1)
		c |= 1 << (i - 1);
	i--;
	if(i == 0)
	{
		ft_putchar_fd(c,STDOUT_FILENO);
		i = 8;
		c = 0;
	}
}

int main(void)
{
 	struct sigaction sa;

	sa.sa_handler = handler;
	sigaction(SIGUSR1,&sa,NULL);
	sigaction(SIGUSR2,&sa,NULL); 

	ft_printf("PID = %d\n", getpid());
	while(1)
		sleep(1);

	return (0);
}