#include "push_swap.h"

void get_stack_info(t_stack *stack)
{
	int i;

	i = 0;
	ft_printf("array = ");
	while((size_t)i < stack->max_size)
	{
		ft_printf("%i ", stack->array[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("size = %i\n",stack->size);
	ft_printf("max size = %i\n",stack->max_size);
	
}
void get_state(t_prog *prog)
{
	int i = 0;
	
	while((size_t)i < prog->stack_a->max_size)
	{
		ft_printf("%i %i\n", prog->stack_a->array[i],prog->stack_b->array[i]);
		i++;
	}
	ft_printf("- -\n");
	ft_printf("a b\n");
	ft_printf("------------------------------------------------\n");
}

void print_arr(int *arr, int size)
{
	int i;

	i = -1;
	while(++i < size)
		ft_printf("%i ",arr[i]);
	ft_printf("\n");
}

void print2D_arr(t_2Dpoint **arr)
{
	size_t i;
	
	i = 0;
	while(arr[i])
	{
		ft_printf("Element[%i] = <%i,%i>\n",i,arr[i]->val_a,arr[i]->val_b);
		i++;
	}
}