#include "push_swap.h"

static int is_array_sorted(t_stack *stack_a);

void run_sorting_algo(t_prog *prog)
{

	while(!is_array_sorted(prog->stack_a))
	{
		ft_printf("sort you idiot\n");
	}
	ft_printf("Array Sorted\n");
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