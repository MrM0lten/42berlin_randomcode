/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:14:34 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 19:20:47 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			arr[i]->val_a = find_pos_for_val(prog->stack_a, prog->stack_b->array[elem]);
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

t_2dpoint	*get_best_elem(t_2dpoint **arr)
{
	int	i;
	int	temp_val;
	int	arr_len;
	int	arr_pos;
	int	*totals;

	i = 0;
	while (arr[i] != NULL)
		i++;
	totals = (int *)malloc(sizeof(int) * i);
	arr_len = i;
	i = 0;
	while (arr[i] != NULL)
	{
		if ((arr[i]->val_a >= 0 && arr[i]->val_b >= 0)
			|| (arr[i]->val_a < 0 && arr[i]->val_b < 0))
			totals[i] = largest_from_zero(arr[i]->val_a, arr[i]->val_b);
		else
			totals[i] = ft_abs(arr[i]->val_a) + ft_abs(arr[i]->val_b);
		i++;
	}	
	i = 0;
	arr_pos = 0;
	temp_val = totals[i];
	while (i < arr_len)
	{
		if (temp_val > totals[i])
		{
			temp_val = totals[i];
			arr_pos = i;
		}
		i++;
	}
	free(totals);
	return (arr[arr_pos]);
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
	put_instruction("pa", prog);
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
	{
		next_smallest = get_biggest_arr_elem(stack);
		elem_pos = get_arr_elem_pos(stack, next_smallest);
	}
	top = stack->max_size - stack->size;
	mid = (top + stack->max_size) / 2;
	if (elem_pos <= mid)
		return (elem_pos - top + 1);
	else
		return (elem_pos - (stack->max_size -1));
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

t_2dpoint	**generate_points_arr(t_prog *prog)
{
	t_2dpoint	**arr;
	size_t		i;

	arr = (t_2dpoint **)malloc(sizeof(t_2dpoint *) * (prog->stack_b->size + 1));
	i = 0;
	while (i < prog->stack_b->size)
	{
		arr[i] = (t_2dpoint *)malloc(sizeof(t_2dpoint));
		arr[i]->val_a = 0;
		arr[i]->val_b = 0;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	free_points_arr(t_2dpoint **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
