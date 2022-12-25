/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:29:01 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 18:29:03 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (fill_lis_stack(prog, lis, get_max_lis(prog, lis)));
}

int	get_max_lis(t_prog *prog, int *lis)
{
	size_t	i;
	int		lis_max;

	i = 0;
	lis_max = 1;
	while (i < prog->stack_a->max_size)
	{
		if (lis_max < lis[i])
			lis_max = lis[i];
		i++;
	}
	return (lis_max);
}

t_stack	*fill_lis_stack(t_prog *prog, int *lis, int lis_max)
{
	t_stack	*temp;
	size_t	i;
	size_t	j;
	int		*temparr;

	temparr = ft_calloc(lis_max, sizeof(int));
	temp = generate_stack(temparr, (size_t)lis_max, (size_t)lis_max);
	i = prog->stack_a->max_size - 1;
	while (lis_max != lis[i])
		i--;
	j = 0;
	temp->array[j++] = prog->stack_a->array[i];
	while (lis_max != 1)
	{
		if (lis[i] == lis_max - 1)
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
