/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:22:35 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 18:28:51 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	rot_to_smallest(t_prog *prog, t_stack *stack)
{
	size_t	i;
	size_t	pos;
	int		val;

	i = 0;
	pos = 0;
	val = stack->array[i];
	while ((size_t)i < stack->max_size)
	{
		if (stack->array[i] < val)
		{
			val = stack->array[i];
			pos = i;
		}	
		i++;
	}
	if ((size_t)pos <= (stack->max_size / 2))
	{
		while (pos-- != 0)
			put_instruction("ra", prog);
		return ;
	}
	while ((size_t)pos++ < stack->max_size)
		put_instruction("rra", prog);
}
