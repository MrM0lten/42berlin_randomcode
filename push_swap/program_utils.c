#include "push_swap.h"

t_prog *initprog(int ac, char**av)
{
	t_prog *prog;
	int *stack_a_vals;
	int *stack_b_vals;
	size_t stacksize;
	size_t i;

	stacksize = get_arg_count(ac, av);
	if (stacksize < 2)
		return (NULL);
	
	prog = (t_prog *)malloc(sizeof(t_prog));
	if(!prog)
		return (NULL);
	stack_a_vals = fill_arr(stacksize, av[1]);
	//print_arr(stack_a_vals,stacksize);
	stack_b_vals = (int *)malloc(stacksize * sizeof(int));
	if(!err_arr_is_unique(stack_a_vals, stacksize))
		 return (NULL);
	i = 0;
	while(i < stacksize)
	{
		stack_b_vals[i] = 0;
		i++;
	}

	prog->stack_a = generate_stack(stack_a_vals, stacksize, stacksize);
	prog->stack_b = generate_stack(stack_b_vals, 0, stacksize);
	if(!stack_a_vals || !(prog->stack_a) || !(prog->stack_b))
		return (NULL);
	return (prog);
}

size_t get_arg_count(int ac, char** av)
{
	size_t arg_count;
	size_t word_flag;
	int i;

	(void)ac;
	arg_count = 0;
	i = 0;
	word_flag = 0;
	while(av[1][i])
	{
		if (av[1][i] != ' ' && word_flag == 0)
		{
			word_flag = 1;
			arg_count++;
		}
		else if (av[1][i] == ' ')
			word_flag = 0;
		i++;
	}
	return (arg_count);
}

int *fill_arr(size_t size, char* str)
{
	int *arr;
	int i;
	size_t cnt;

	if(size < 2)
		return (NULL);

	arr = (int *)malloc(size * sizeof(int));
	if(!arr)
		return (NULL);
	i = 0;
	cnt = 0; 
	while(cnt < size)
	{
		while(str[i] == ' ')
			i++;
		arr[cnt] = ft_atoi(&str[i]);
		//printf("arr[cnt] = %i\n",arr[cnt]);
		cnt++;
		while(str[i] != ' ')
			i++;
		i++;
	}
	//ft_printf("%i\n",cnt);
	return (arr);
}

t_stack *generate_stack(int *values,size_t num, size_t stacksize)
{
	t_stack *stack;

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