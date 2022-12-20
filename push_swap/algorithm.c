#include "push_swap.h"

static int is_array_sorted(t_stack *stack_a);
void rot_to_smallest(t_prog *prog);

void run_sorting_algo(t_prog *prog)
{
	
	get_state(prog);
	//calculate the LIS
	rot_to_smallest(prog);
	get_state(prog);

	//random might not be useful actually
	ft_printf("Array Sorted %i\n",is_array_sorted(prog->stack_a));
	
}

void rot_to_smallest(t_prog *prog)
{
	size_t i;
	size_t pos;
	int val;

	i = 0;
	pos = 0;
	val = prog->stack_a->array[i];
	while((size_t)i < prog->stack_a->max_size)
	{
		if(prog->stack_a->array[i] < val)
		{
			val = prog->stack_a->array[i];
			pos = i;
		}	
		i++;
	}
	if((size_t)pos <= (prog->stack_a->max_size / 2))
	{
		while(pos-- != 0)
			put_instruction("ra",prog);
	}
	else
	{
		while((size_t)pos++ < prog->stack_a->max_size)
			put_instruction("rra",prog);
	}
}

static int is_array_sorted(t_stack *stack_a)
{
	size_t i;
	if(stack_a->size != stack_a->max_size)
		return (0);
	i = 0;
	while(i < stack_a->max_size - 1)
	{
		if(stack_a->array[i] > stack_a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}