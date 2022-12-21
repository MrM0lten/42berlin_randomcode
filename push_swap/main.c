
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

t_stack *generate_stack(int *values,size_t num, size_t stacksize);
t_prog *initprog(int ac, char**av);

int main(int ac, char**av)
{
	t_prog *prog;

	//do proper error handling
	if(ac < 2)
		return 0;
	prog = initprog(ac,av);
	if(prog)
	{
		run_sorting_algo(prog);
	}
	return (0);
}

t_prog *initprog(int ac, char**av)
{
	int *values;
	size_t stacksize;
	size_t i;
	t_prog *prog;

	stacksize = ac-1;
	values = malloc(sizeof(int) * stacksize);
	prog = malloc(sizeof(prog));
	i = 0;
	while(i < stacksize)
	{
		values[i] = ft_atoi(av[i + 1]);
		i++;
	}
	prog = malloc(sizeof(t_prog));
	prog->stack_a = generate_stack(values, stacksize, stacksize);
	prog->stack_b = generate_stack(NULL, 0, stacksize);
	if(!values || !(prog->stack_a) || !(prog->stack_b))
		return (0);
	free(values);
	return (prog);
}

t_stack *generate_stack(int *values,size_t num, size_t stacksize)
{
	t_stack *stack;
	size_t i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if(!stack)
		return (NULL);
	i = 0;
	stack->array = malloc(stacksize * sizeof(int));
	if(values != 0 && num  != 0)
	{
		while(i < stacksize)
		{
			stack->array[i] = values[i];
			i++;
		}
			
	}
	stack->max_size = stacksize;
	stack->size = num;
	return (stack);


}