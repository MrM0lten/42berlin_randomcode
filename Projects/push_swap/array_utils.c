/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:54:51 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 18:54:52 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nextbiggest(int val, t_stack *stack)
{
	size_t	i;
	int		next;

	i = stack->max_size - stack->size;
	next = get_biggest_arr_elem(stack);
	while (i < stack->max_size)
	{
		if (stack->array[i] > val && stack->array[i] < next)
		{
			next = stack->array[i];
		}
		i++;
	}
	return (next);
}

int	arr_sorted_needs_rot(t_stack *stack_a)
{
	size_t	i;
	int		biggest;
	int		smallest;

	i = stack_a->max_size - stack_a->size;
	biggest = stack_a->array[i];
	smallest = stack_a->array[i];
	while (i < stack_a->max_size)
	{
		if (stack_a->array[i] <= smallest)
			smallest = stack_a->array[i];
		if (stack_a->array[i] >= biggest)
			biggest = stack_a->array[i];
		i++;
	}
	i = stack_a->max_size - stack_a->size - 1;
	while (++i < stack_a->max_size - 1)
	{
		if (stack_a->array[i] == biggest && stack_a->array[i + 1] == smallest)
			continue ;
		if (stack_a->array[i + 1] != nextbiggest(stack_a->array[i], stack_a))
			return (0);
	}
	return (1);
}

int	smaller_elem_exists(t_stack *stack, int cmp_val)
{
	size_t	i;

	i = stack->max_size - stack->size;
	while (i < stack->max_size)
	{
		if (stack->array[i] < cmp_val)
			return (1);
		i++;
	}
	return (0);
}

int	get_biggest_arr_elem(t_stack *stack)
{
	int		val;
	size_t	i;

	i = stack->max_size - stack->size;
	val = stack->array[i];
	while (i < stack->max_size)
	{
		if (stack->array[i] > val)
			val = stack->array[i];
		i++;
	}
	return (val);
}

int	get_arr_elem_pos(t_stack *stack, int val)
{
	size_t	i;

	i = stack->max_size - stack->size;
	while (i < stack->max_size)
	{
		if (stack->array[i] == val)
			return ((int)i);
		i++;
	}
	return (-1);
}
