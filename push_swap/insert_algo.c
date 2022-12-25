/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:14:34 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 20:17:50 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_helper1(t_prog *prog, t_2dpoint *arr);
static void	rot_helper2(t_prog *prog, t_2dpoint *arr);

void	insert_algorithm(t_prog *prog)
{
	int			elem;
	size_t		i;
	t_2dpoint	**arr;

	while (prog->stack_b->size > 0)
	{
		arr = generate_points_arr(prog);
		elem = prog->stack_b->max_size - prog->stack_b->size;
		i = 0;
		while (arr[i] != NULL)
		{
			arr[i]->val_a = find_pos_for_val(prog->stack_a,
					prog->stack_b->array[elem]);
			arr[i]->val_b = calc_smallest_rot(prog->stack_b, elem);
			i++;
			elem++;
		}
		rot_and_move(prog, get_best_elem(arr));
		free_points_arr(arr);
		arr = 0;
	}
	rot_to_smallest(prog, prog->stack_a);
}

void	rot_and_move(t_prog *prog, t_2dpoint *arr)
{
	while ((arr->val_a > 0 && arr->val_b > 0))
	{
		put_instruction("rr", prog);
		arr->val_a--;
		arr->val_b--;
	}
	while ((arr->val_a < 0 && arr->val_b < 0))
	{
		put_instruction("rrr", prog);
		arr->val_a++;
		arr->val_b++;
	}
	rot_helper1(prog, arr);
	rot_helper2(prog, arr);
	put_instruction("pa", prog);
}

static void	rot_helper1(t_prog *prog, t_2dpoint *arr)
{
	while (arr->val_a != 0)
	{
		if (arr->val_a > 0)
		{
			put_instruction("ra", prog);
			arr->val_a--;
		}
		if (arr->val_a < 0)
		{
			put_instruction("rra", prog);
			arr->val_a++;
		}
	}
}

static void	rot_helper2(t_prog *prog, t_2dpoint *arr)
{
	while (arr->val_b != 0)
	{
		if (arr->val_b > 0)
		{
			put_instruction("rb", prog);
			arr->val_b--;
		}
		if (arr->val_b < 0)
		{
			put_instruction("rrb", prog);
			arr->val_b++;
		}
	}
}

int	find_pos_for_val(t_stack *stack, int elem_nbr)
{
	int	top;
	int	next_smallest;
	int	elem_pos;
	int	mid;

	top = stack->max_size - stack->size;
	next_smallest = INT_MIN;
	while (top < (int)stack->max_size)
	{
		if (next_smallest < stack->array[top] && stack->array[top] < elem_nbr)
		{
			next_smallest = stack->array[top];
			elem_pos = top;
		}
		top++;
	}
	if (!smaller_elem_exists(stack, elem_nbr))
		elem_pos = get_arr_elem_pos(stack, get_biggest_arr_elem(stack));
	top = stack->max_size - stack->size;
	mid = (top + stack->max_size) / 2;
	if (elem_pos <= mid)
		return (elem_pos - top + 1);
	else
		return (elem_pos - (stack->max_size -1));
}