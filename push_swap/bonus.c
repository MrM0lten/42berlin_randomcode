#include <stdlib.h>
#include <stdio.h>
#include "./libft/includes/get_next_line.h"
#include "push_swap.h"

static void readline(t_prog *prog);

int main(int ac, char**av)
{
	t_prog *prog;
	size_t stacksize;

	if(ac <= 1)
		return (0);
	stacksize = get_arg_count(ac, av);
	if(stacksize < 1)
		return (0);
	if(ac != 2 || !err_arr_is_all_num(av[1]))
	{
		write_error();
		return 0;
	}
	prog = initprog(ac,av);
	if(!prog)
		return 0;
	readline(prog);
	free_prog(prog);
	return (0);
} 
static void readline(t_prog *prog)
{
	char * str;
	int i;

	prog->sim_flag = 1;
	str = get_next_line(0);
	while(str != NULL)
	{
		i = ft_strlen(str) -1;
		str[i] = '\0';
		put_instruction(str,prog);
		free(str);
		str = get_next_line(0);
	}
	if(is_array_sorted(prog->stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}