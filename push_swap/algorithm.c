#include "push_swap.h"
#include <stdio.h>

t_stack *generate_LIS(t_prog *prog);
void move_unsorted(t_prog *prog, t_stack *lis);
int elem_in_lis(int val, t_stack *lis);

void run_sorting_algo(t_prog *prog)
{

	if(is_array_sorted(prog->stack_a))
		return ;
	
	if(arr_sorted_needs_rot(prog->stack_a))
	{
		//ft_printf("wtf\n");
		rot_to_smallest(prog,prog->stack_a);
		return ;
	}
	if(prog->stack_a->max_size == 3) //bit hacky but i guess it works
	{
		put_instruction("sa",prog);
		rot_to_smallest(prog,prog->stack_a);
		return ;
	}
	//rot_to_smallest(prog,prog->stack_a);


	t_stack *temp = generate_LIS(prog);
	//printf(" lis size = %zu\n",temp->size);
	if(temp->size == 2 && prog->stack_a->array[0] >prog->stack_a->array[1]) //special case rotating once and regenerating lis will save lots of instructions
	{
		free_stack(temp);
		put_instruction("sa",prog);
		temp = generate_LIS(prog);
	}
	//printf("LIS = %zu",temp->max_size);
	//print_arr(temp->array,temp->max_size);
	
	move_unsorted(prog, temp);
	free_stack(temp);
	insert_algorithm(prog);
}

void move_unsorted(t_prog *prog, t_stack *lis)
{
	int push_amnt;
	int top_item;

	//print_arr(lis->array,lis->max_size);
	//ft_printf("lis max size = %i\n",(int)lis->max_size);
	// edge case when stack is completly reverse
	if(lis->max_size < 2)
	{
		while(prog->stack_a->size > 2)
		{
			put_instruction("pb",prog);
		}
		return ;
	}

	push_amnt = prog->stack_a->max_size - lis->max_size;
	top_item = prog->stack_a->max_size - prog->stack_a->size;
	//ft_printf("push amt = %i, top item = %i\n",push_amnt,top_item);
	
	while(push_amnt > 0)
	{
		//ft_printf("stack a size = %i, top item = %i\n", (int)prog->stack_a->size,top_item);
		if(!elem_in_lis(prog->stack_a->array[top_item], lis))
		{
			put_instruction("pb",prog);
			push_amnt--;
			top_item++;
		}
		else
			put_instruction("ra",prog); //might be worth calculating which rotation direction makes the most sense
		
	}
	
}

int elem_in_lis(int val, t_stack *lis)
{
	size_t i;

	i = 0;
	//ft_printf("checking for sorting\n");
	while(i < lis->max_size)
	{
		//ft_printf("comparing %i against %i\n",lis->array[i] ,(int)val);
		if(lis->array[i] == val)
		{
			return (1);
		}
			
		i++;
	}
	//ft_printf("element not found\n");
	return (0);
}

//finds the longest list of items that are already in order and returns the list of ordered numbers in an array
t_stack *generate_LIS(t_prog *prog)
{
	int *lis;
	int *temparr;
	t_stack *temp;
	size_t i;	
	size_t j;
	int lis_max;

	lis = malloc(sizeof(int) * prog->stack_a->max_size);
	if(!lis)
		return (NULL);
	i = 0;
	while(i < prog->stack_a->max_size)
		lis[i++] = 1;
	//main loop //holy shit thats such a simple loop 
	i = 1; 
	while(i < prog->stack_a->max_size)
	{
		j = 0;
		while(j < i)
		{
			if(prog->stack_a->array[i] > prog->stack_a->array[j] 
			&& lis[i] <= lis[j])
				lis[i] = 1 + lis[j];
			j++;
		}
		i++;
	}
	//print_arr(lis,prog->stack_a->max_size);
	i = 0;
	lis_max = 0; //loop will get the max lis
	while(i < prog->stack_a->max_size)
	{
		if(lis_max < lis[i])
			lis_max = lis[i];
		i++;
	}
	//generate temp stack with the alreay sorted values
	temparr = ft_calloc(lis_max,sizeof(int));
	temp = generate_stack(temparr,(size_t)lis_max,(size_t)lis_max); 
	i = prog->stack_a->max_size - 1;
	while(lis_max != lis[i])
		i--;
	j = 0;

	temp->max_size = lis_max;
	temp->size = lis_max;

	//print_arr(temp->array,temp->max_size);
	//ft_printf("i = %i,prog->stack_a->max_size %i\n",i,(int)prog->stack_a->max_size );
	temp->array[j++] = prog->stack_a->array[i];
	
	while(lis_max != 1)
	{
		if(lis[i] == lis_max - 1)
		{
			//printf("lis max = %i,j = %i \n",lis_max, (int)j);
			temp->array[j] = prog->stack_a->array[i];
			j++;
			lis_max--;
		}
		i--;
	}
	free(lis);
	//print_arr(temp->array ,temp->max_size);
	return (temp);
}

void rot_to_smallest(t_prog *prog,t_stack *stack)
{
	size_t i;
	size_t pos;
	int val;

	i = 0;
	pos = 0;
	val = stack->array[i];
	while((size_t)i < stack->max_size)
	{
		if(stack->array[i] < val)
		{
			val = stack->array[i];
			pos = i;
		}	
		i++;
	}
	if((size_t)pos <= (stack->max_size / 2))
	{
		while(pos-- != 0)
			put_instruction("ra",prog);
	}
	else
	{
		while((size_t)pos++ < stack->max_size)
			put_instruction("rra",prog);
	}
}