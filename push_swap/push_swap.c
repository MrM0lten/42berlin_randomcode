
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int main(int ac, char**av)
{
	t_prog *prog;
	size_t stacksize;


	//printf("%s\n",av[1]);
	stacksize = get_arg_count(ac, av);
	//printf("%zu",stacksize);
	if(stacksize < 1)
		return (0);
	//do proper error handling
	if(ac != 2 || !err_arr_is_all_num(av[1]))
	{
		//printf("err is al num issue\n");
		write_error();
		return 0;
	}
		

	
	prog = initprog(ac,av);

	if(!prog)
	{
		return 0;
	}

	
	//get_state(prog);
	run_sorting_algo(prog);
	//get_state(prog);
	//ft_printf("Array Sorted %i\n",is_array_sorted(prog->stack_a));


	free_prog(prog);
	return (0);
}