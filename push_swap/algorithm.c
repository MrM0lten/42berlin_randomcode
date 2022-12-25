/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:22:35 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 17:31:14 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*generate_lis(t_prog *prog);
void	move_unsorted(t_prog *prog, t_stack *lis);
int		elem_in_lis(int val, t_stack *lis);
t_stack *fill_lis_stack(t_prog *prog, int *lis, int lis_max);

void	run_sorting_algo(t_prog *prog)
{
	t_stack	*temp;

	if (is_array_sorted(prog->stack_a))
		return ;
	if (arr_sorted_needs_rot(prog->stack_a))
	{
		rot_to_smallest(prog, prog->stack_a);
		return ;
	}
	if (prog->stack_a->max_size == 3)
	{
		put_instruction("sa", prog);
		rot_to_smallest(prog, prog->stack_a);
		return ;
	}
	if (prog->stack_a->max_size > 3 && prog->stack_a->max_size < 6)
	{
		brute_force(prog);
		return ;
	}
	temp = generate_lis(prog);
	move_unsorted(prog, temp);
	free_stack(temp);
	insert_algorithm(prog);
}

void	brute_force(t_prog *prog)
{
	put_instruction("pb", prog);
	put_instruction("pb", prog);
	if (!arr_sorted_needs_rot(prog->stack_a))
		put_instruction("sa", prog);
	insert_algorithm(prog);
}

void	move_unsorted(t_prog *prog, t_stack *lis)
{
	int	push_amnt;
	int	top_item;

	if (lis->max_size < 2)
	{
		while (prog->stack_a->size > 2)
			put_instruction("pb", prog);
		return ;
	}
	push_amnt = prog->stack_a->max_size - lis->max_size;
	top_item = prog->stack_a->max_size - prog->stack_a->size;
	while (push_amnt > 0)
	{
		if (!elem_in_lis(prog->stack_a->array[top_item], lis))
		{
			put_instruction("pb", prog);
			push_amnt--;
			top_item++;
		}
		else
			put_instruction("ra", prog);
	}
}

int	elem_in_lis(int val, t_stack *lis)
{
	size_t	i;

	i = 0;
	while (i < lis->max_size)
	{
		if (lis->array[i] == val)
			return (1);
		i++;
	}
	return (0);
}

t_stack	*generate_lis(t_prog *prog)
{
	int		*lis;
	size_t	i;	
	size_t	j;
	int		lis_max;

	lis = malloc(sizeof(int) * prog->stack_a->max_size);
	if (!lis)
		return (NULL);
	i = 0;
	while (i < prog->stack_a->max_size)
		lis[i++] = 1;
	i = 1; 
	while (i < prog->stack_a->max_size)
	{
		j = 0;
		while (j < i)
		{
			if (prog->stack_a->array[i] > prog->stack_a->array[j] 
			&& lis[i] <= lis[j])
				lis[i] = 1 + lis[j];
			j++;
		}
		i++;
	}
	i = 0;
	lis_max = 0;
	while (i < prog->stack_a->max_size)
	{
		if (lis_max < lis[i])
			lis_max = lis[i];
		i++;
	}
	return (fill_lis_stack(prog, lis, lis_max));
}

t_stack *fill_lis_stack(t_prog *prog, int *lis, int lis_max)
{
	t_stack	*temp;
	size_t	i;
	size_t	j;
	int		*temparr;
	//generate temp stack with the alreay sorted values
	temparr = ft_calloc(lis_max,sizeof(int));
	temp = generate_stack(temparr,(size_t)lis_max,(size_t)lis_max); 
	i = prog->stack_a->max_size - 1;
	while(lis_max != lis[i])
		i--;
	j = 0;
	temp->max_size = lis_max;
	temp->size = lis_max;
	temp->array[j++] = prog->stack_a->array[i];
	while(lis_max != 1)
	{
		if(lis[i] == lis_max - 1)
		{
			temp->array[j] = prog->stack_a->array[i];
			j++;
			lis_max--;
		}
		i--;
	}
	free(lis);
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
