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

#include "../../includes/array_utils.h"
//checks if an array is sorted
int	is_arr_sorted(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
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
		ft_printf("elem[%i] = %i \n", i, arr[i]);
}

// returns the position of the biggest element in a given array
int	biggest_arr_elem(int *arr, int len)
{
	int	val;
	int	i;
	int	j;

	i = 0;
	j = 0;
	val = arr[i];
	while (i < len)
	{
		if (arr[i] > val)
		{
			val = arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}

//returns the position of the first occurrance of val
int	arr_elem_pos(int *arr, int len, int val)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

//searches entire array and returns the next biggest value
int	nextbiggest(int *arr, int len, int val)
{
	int	i;
	int	next;

	i = 0;
	next = biggest_arr_elem(arr, len);
	while (i < len)
	{
		if (arr[i] > val && arr[i] < next)
		{
			next = arr[i];
		}
		i++;
	}
	return (next);
}
