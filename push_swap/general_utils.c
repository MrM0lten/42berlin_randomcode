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

int nextbiggest(int val,t_stack *stack)
{
	size_t i;
	int next;

	i = stack->max_size - stack->size;
	next = get_biggest_arr_elem(stack);
	//printf("next = %i\n", next);
	while(i < stack->max_size)
	{
		if(stack->array[i] >= val && stack->array[i] < next)
			next = stack->array[i];
		i++;
	}
	//printf("next = %i\n", next);
	return (next);
}

int arr_sorted_needs_rot(t_stack *stack_a)
{
	size_t i;
	int biggest;
	int smallest;

	if(stack_a->size != stack_a->max_size)
		return (0);
	i = 0;
	biggest = stack_a->array[i];
	smallest = stack_a->array[i];
	//ft_printf("smallest = %i, biggest = %i\n",smallest,biggest);
	while(i < stack_a->max_size)
	{
		if(stack_a->array[i] <= smallest)
			smallest = stack_a->array[i];
		if(stack_a->array[i] >= biggest)
			biggest = stack_a->array[i];
		i++;
	}
	//ft_printf("smallest = %i, biggest = %i\n",smallest,biggest);
	i = 0;
	while(i < stack_a->max_size - 1)
	{
		if(stack_a->array[i] == biggest && stack_a->array[i + 1] == smallest)
		{
			i++;
			continue;
		}
		//printf("i+1 =%i,next biggest = %i",stack_a->array[i + 1] , nextbiggest(stack_a->array[i],stack_a));
		if(stack_a->array[i] > stack_a->array[i + 1] || stack_a->array[i + 1] != nextbiggest(stack_a->array[i],stack_a))
			return (0);
		i++;
	}
	return (1);
}
int smaller_elem_exists(t_stack *stack,int cmp_val)
{
	size_t i;

	i = stack->max_size - stack->size;
	while(i < stack->max_size)
	{
		if(stack->array[i] < cmp_val)
			return (1);
		i++;
	}
	return (0);
}
int get_biggest_arr_elem(t_stack *stack)
{
	int val;
	size_t i;

	i = stack->max_size - stack->size;
	val = stack->array[i];
	while(i < stack->max_size)
	{
		if(stack->array[i] > val)
			val = stack->array[i];
		i++;
	}

	return (val);
}
int get_arr_elem_pos(t_stack *stack,int val)
{
	size_t i;

	i = stack->max_size - stack->size;
	while(i < stack->max_size)
	{
		if(stack->array[i] == val)
			return ((int)i);
		i++;
	}
	return (-1);
}