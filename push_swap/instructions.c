#include "push_swap.h"

void put_instruction(char *instruction, t_prog *prog)
{
	if(!ft_strncmp(instruction,"sa",3))
		stack_swap(prog->stack_a);
	else if(!ft_strncmp(instruction,"sb",3))
		stack_swap(prog->stack_b);
	else if(!ft_strncmp(instruction,"ss",3))
	{
		stack_swap(prog->stack_a);
		stack_swap(prog->stack_b);
	}
	else if(!ft_strncmp(instruction,"ra",3))
		rot_stack(prog->stack_a);
	else if(!ft_strncmp(instruction,"rb",3))
		rot_stack(prog->stack_b);
	else if(!ft_strncmp(instruction,"rr",3))
	{
		rot_stack(prog->stack_a);
		rot_stack(prog->stack_b);
	}
	else if(!ft_strncmp(instruction,"pa",3))
		push_stack(prog->stack_b, prog->stack_a);
	else if(!ft_strncmp(instruction,"pb",3))
		push_stack(prog->stack_a, prog->stack_b);
	else if(!ft_strncmp(instruction,"rra",3))
		rvrs_rot_stack(prog->stack_a);
	else if(!ft_strncmp(instruction,"rrb",3))
		rvrs_rot_stack(prog->stack_b);
	else if(!ft_strncmp(instruction,"rrr",3))
	{
		rvrs_rot_stack(prog->stack_a);
		rvrs_rot_stack(prog->stack_b);
	}
	else
		ft_printf("An Error occured, did you input the right command?\n");

	get_state(prog);
	ft_printf("%s\n",instruction);
}

void stack_swap(t_stack *stack)
{
	size_t i;
	int temp;

	i = stack->max_size - stack->size;
	temp = stack->array[i];
	stack->array[i] = stack->array[i + 1];
	stack->array[i + 1] = temp;
}

void rot_stack(t_stack *stack)
{
	size_t i;
	int temp;

	i = stack->max_size - stack->size;
	temp = stack->array[i];
	while(i < stack->max_size)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i - 1] = temp;
}

void rvrs_rot_stack(t_stack *stack)
{
	size_t i;
	size_t elems;
	int temp;

	i = stack->max_size;
	elems = stack->max_size - stack->size;
	temp = stack->array[i - 1];
	while(i > elems)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[i] = temp;
}
void push_stack(t_stack *from,t_stack *to)
{
	size_t from_i;
	size_t to_i;

	from_i = from->max_size - from->size;
	to_i = to->max_size - to->size;

	if(from->size > 0)
		to->array[to_i - 1] = from->array[from_i];

	from->array[from_i] = 0;
	from->size--;
	to->size++;
}