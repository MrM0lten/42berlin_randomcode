#include "push_swap.h"
#include <stdio.h>

static int is_array_sorted(t_stack *stack_a);
void rot_to_smallest(t_prog *prog);
t_stack *generate_LIS(t_prog *prog);
void move_unsorted(t_prog *prog, t_stack *lis);
int elem_in_lis(int val, t_stack *lis);

void run_sorting_algo(t_prog *prog)
{
	
	get_state(prog);
	//rotating to smallest number for easy LIS Generation
	rot_to_smallest(prog);
	t_stack *temp = generate_LIS(prog);
	//print_arr(temp->array,temp->max_size);
	move_unsorted(prog, temp);


	//get_stack_info(prog->stack_a);
	//get_stack_info(prog->stack_b);
	//print_arr(temp->array,temp->max_size);
	
	//random might not be useful actually

	get_state(prog);
	free_stack(temp);
	ft_printf("Array Sorted %i\n",is_array_sorted(prog->stack_a));
}

void move_unsorted(t_prog *prog, t_stack *lis)
{
	int push_amnt;
	int top_item;

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