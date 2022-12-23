
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int main(int ac, char**av)
{
	t_prog *prog;

	//do proper error handling
	if(ac < 2)
		return 0;
	prog = initprog(ac,av);
	if(!prog)
		return (0);
	
	//get_state(prog);
	run_sorting_algo(prog);
	//get_state(prog);
	//ft_printf("Array Sorted %i\n",is_array_sorted(prog->stack_a));


	free_prog(prog);
	return (0);
}