#include "push_swap.h"

t_prog *initprog(int ac, char**av)
{
	t_prog *prog;
	int *stack_a_vals;
	int *stack_b_vals;
	size_t stacksize;
	size_t i;

	stacksize = ac - 1;
	prog = (t_prog *)malloc(sizeof(t_prog));
	if(!prog)
		return (NULL);
	stack_a_vals = (int *)malloc(stacksize * sizeof(int));
	stack_b_vals = (int *)malloc(stacksize * sizeof(int));


	i = 0;
	while(i < stacksize)
	{
		stack_a_vals[i] = ft_atoi(av[i + 1]);
		stack_b_vals[i] = 0;
		i++;
	}
	if(!err_arr_is_unique(stack_a_vals, stacksize))
		 return (NULL);
	prog->stack_a = generate_stack(stack_a_vals, stacksize, stacksize);
	prog->stack_b = generate_stack(stack_b_vals, 0, stacksize);
	if(!stack_a_vals || !(prog->stack_a) || !(prog->stack_b))
		return (NULL);
	return (prog);
}

t_stack *generate_stack(int *values,size_t num, size_t stacksize)
{
	t_stack *stack;
	//size_t i;
	if(!values)
		return (NULL);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if(!stack)
		return (NULL);
	
	stack->array = values;
	stack->max_size = stacksize;
	stack->size = num;
	return (stack);
}

void free_prog(t_prog *prog)
{
	free_stack(prog->stack_a);
	free_stack(prog->stack_b);
	free(prog);
	prog = NULL;
}

void free_stack(t_stack *stack)
{
	free(stack->array);
	stack->array = NULL;
	free(stack);
	stack = NULL;
}