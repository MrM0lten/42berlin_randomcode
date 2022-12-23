#include "push_swap.h"

size_t ft_abs(int i)
{
	if(i < 0)
		return(i * -1);
	return (i);
}

int largest_from_zero(int a, int b)
{
	if(a >= 0 && b >= 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else
	{
		if(a < b)
			return (a * -1);
		else
			return (b * -1);
	}
}

int is_array_sorted(t_stack *stack_a)
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