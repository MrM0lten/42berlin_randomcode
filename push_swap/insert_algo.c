#include "push_swap.h"

void insert_algorithm(t_prog *prog)
{
	ft_printf("-------------------------------------\n");
	ft_printf("-------------------------------------\n");
	get_state(prog);
	int elem;
	size_t i;
	t_2Dpoint **arr;


	arr = generate_points_arr(prog);
	elem = prog->stack_b->max_size - prog->stack_b->size; // get top most element of stack b
	//get element at B[i]

	ft_printf("prog->stack_b->size = %i\n",(int)prog->stack_b->size);
	i = 0;
	while(arr[i] != NULL)
	{
		arr[i]->val_a = find_pos_for_val(prog->stack_a, prog->stack_b->array[elem]);
		arr[i]->val_b = calc_smallest_rot(prog->stack_b, elem);
		i++;
		elem++;
	}
	print2D_arr(arr);
	free_points_arr(arr);
}



//get the next smallest number from elem number, figure out position and calculate how many moves it takes to move it to the bottom (array[max_size])
// use midpoint to determine if val is pos or negative
int find_pos_for_val(t_stack *stack, int elem_nbr)
{
	int top;
	int next_smallest;
	int elem_pos;
	int mid;

	top = stack->max_size - stack->size;
	next_smallest = INT_MIN; //will not work with negative numbers! write helper function to return smallest nmb
	while(top < (int)stack->max_size)
	{
		if(next_smallest < stack->array[top] && stack->array[top] < elem_nbr)
		{
			next_smallest = stack->array[top];
			elem_pos = top;
		}
		top++;
	}
	ft_printf("elem_pos = %i,elem = %i, next_smallest = %i\n",elem_pos,elem_nbr,next_smallest);
	top = stack->max_size - stack->size;
	mid = (top + stack->max_size)/ 2;
	ft_printf("elem_pos = %i,top = %i, mid = %i\n",elem_pos,top,mid);
	if(elem_pos <= mid)
	{
		ft_printf("return %i - %i + 1 = %i\n",elem_pos,top,elem_pos - top  + 1);
		return (elem_pos - top  + 1);
	}
	else
	{
		printf("------------------------------------\n");
		printf("%i - %i = %i\n",elem_pos,(int)stack->max_size,elem_pos - (int)stack->max_size);
		return (elem_pos - (stack->max_size -1));
		return (0);
	}


	
}

//calculates the mid point of the active elements, tries to reach the top with as little moves as possible. mid point will define if positive or negative.
int calc_smallest_rot(t_stack *stack, int elem_pos)
{
	int top;
	int mid;

	top = stack->max_size - stack->size;
	mid = (top + stack->max_size)/ 2;

	ft_printf("top = %i\n",top);
	ft_printf("mid = %i\n",mid);
	ft_printf("elem_pos = %i\n",elem_pos);
	if(elem_pos <= mid)
		return (elem_pos - top);
	else
		return((elem_pos - stack->max_size));

}

t_2Dpoint **generate_points_arr(t_prog *prog)
{
	t_2Dpoint **arr;
	size_t i;

	arr = (t_2Dpoint **)malloc(sizeof(t_2Dpoint *) * (prog->stack_b->size + 1));
	i = 0;
	while(i < prog->stack_b->size)
	{
		arr[i] = (t_2Dpoint *)malloc(sizeof(t_2Dpoint));
		arr[i]->val_a = 0;
		arr[i]->val_b = 0;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
void free_points_arr(t_2Dpoint **arr)
{
	size_t i;

	i = 0;
	while(arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}