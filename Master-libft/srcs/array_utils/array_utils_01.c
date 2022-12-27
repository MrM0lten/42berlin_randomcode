/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:55:24 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/27 20:55:25 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_array(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		ft_printf("%i ", arr[i]);
	ft_printf("\n");
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
