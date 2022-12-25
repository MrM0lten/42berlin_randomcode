/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:48:39 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 20:48:40 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*generate_stack(int *values, size_t num, size_t stacksize)
{
	t_stack	*stack;

	if (!values)
		return (NULL);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = values;
	stack->max_size = stacksize;
	stack->size = num;
	return (stack);
}

void	free_prog(t_prog *prog)
{
	free_stack(prog->stack_a);
	free_stack(prog->stack_b);
	free(prog);
	prog = NULL;
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	stack->array = NULL;
	free(stack);
	stack = NULL;
}
