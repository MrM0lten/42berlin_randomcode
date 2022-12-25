/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:26:17 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 20:03:47 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_elem(int *arr, int arr_len);

t_2dpoint	*get_best_elem(t_2dpoint **arr)
{
	int	i;
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
	arr_pos = get_elem(totals, arr_len);
	free(totals);
	return (arr[arr_pos]);
}

static int	get_elem(int *arr, int arr_len)
{
	int	temp_val;
	int	arr_pos;
	int	i;

	i = 0;
	arr_pos = 0;
	temp_val = arr[i];
	while (i < arr_len)
	{
		if (temp_val > arr[i])
		{
			temp_val = arr[i];
			arr_pos = i;
		}
		i++;
	}
	return (arr_pos);
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
