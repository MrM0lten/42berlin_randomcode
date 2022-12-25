/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:49:09 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 18:52:23 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

int	largest_from_zero(int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else
	{
		if (a < b)
			return (a * -1);
		else
			return (b * -1);
	}
}

int	is_array_sorted(t_stack *stack_a)
{
	size_t	i;

	i = stack_a->max_size - stack_a->size;
	while (i < stack_a->max_size - 1)
	{
		if (stack_a->array[i] > stack_a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	calc_smallest_rot(t_stack *stack, int elem_pos)
{
	int	top;
	int	mid;

	top = stack->max_size - stack->size;
	mid = (top + stack->max_size) / 2;
	if (elem_pos <= mid)
		return (elem_pos - top);
	else
		return ((elem_pos - stack->max_size));
}

