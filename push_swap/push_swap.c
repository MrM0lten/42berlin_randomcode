
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"


/* int main(int ac, char**av)
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
} */


#include <stdlib.h>

int val_in_array(int *arr_a, int elems, int val)
{
	int i;

	i = 0;
	while(i < elems)
	{
		if(arr_a[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int *fill_arr_randomly(int *arr_a, int elems)
{
	int i;
	int *arr;
	int rnd_val;

	i = 0;
	rnd_val = 0;
	arr = (int *)malloc(sizeof(int) * elems);
	while(i < elems)
	{

		rnd_val = random() / 1000000;
		while(val_in_array(arr, elems, rnd_val))
		{
			rnd_val = random() / 1000000;
		}
		arr[i] = rnd_val;
		arr_a[i] = rnd_val;
		i++;
	}
	return(arr);
}

int main(int ac, char **av)
{
	t_prog *prog;
	int elems;
	int iterations;
	int *arr_a;
	int *arr_b;

	elems = ft_atoi(av[1]); 
	iterations = ft_atoi(av[2]);


	(void)ac;
	while(iterations)
	{
		prog = (t_prog *)malloc(sizeof(t_prog));
		arr_a = (int *)malloc(sizeof(int) * elems);
		arr_b = (int *)malloc(sizeof(int) * elems);

		

		prog->stack_a = generate_stack(fill_arr_randomly(arr_a,elems),elems,elems);
		prog->stack_b = generate_stack(arr_b,0,elems);
		//get_state(prog);
		//print_arr(arr_a,elems);
		run_sorting_algo(prog);
		iterations--;
		if(is_array_sorted(prog->stack_a))
		{
			//print_arr(arr_a,elems);
			//print_arr(prog->stack_a->array,elems);
			ft_printf("SUCCESS = Array is sorted properly\n");
		}
		else
		{
			ft_printf("\n");
			print_arr(arr_a,elems);
			print_arr(prog->stack_a->array,elems);
			ft_printf("FAIL = Array is not sorted properly\n");
		}
		//print_arr(prog->stack_a->array,elems);
		//get_state(prog);
		free_prog(prog);

	}
	return (0);
}