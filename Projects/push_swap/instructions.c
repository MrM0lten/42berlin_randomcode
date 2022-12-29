/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:25:16 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 20:28:04 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack *stack)
{
	size_t	i;
	int		temp;

	if (stack->size < 2)
		return ;
	i = stack->max_size - stack->size;
	temp = stack->array[i];
	stack->array[i] = stack->array[i + 1];
	stack->array[i + 1] = temp;
}

void	rot_stack(t_stack *stack)
{
	size_t	i;
	int		temp;

	i = stack->max_size - stack->size;
	temp = stack->array[i];
	while (i < stack->max_size -1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = temp;
}

void	rvrs_rot_stack(t_stack *stack)
{
	size_t	i;
	size_t	elems;
	int		temp;

	i = stack->max_size - 1;
	elems = stack->max_size - stack->size;
	temp = stack->array[i];
	while (i > elems)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[i] = temp;
}

void	push_stack(t_stack *from, t_stack *to)
{
	size_t	from_i;
	size_t	to_i;

	if (from->size < 1)
		return ;
	from_i = from->max_size - from->size;
	to_i = to->max_size - to->size;
	if (from->size > 0)
		to->array[to_i - 1] = from->array[from_i];
	from->array[from_i] = 0;
	from->size--;
	to->size++;
}
