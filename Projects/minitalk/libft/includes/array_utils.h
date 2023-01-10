/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:13:14 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/07 13:15:06 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_UTILS_H
# define ARRAY_UTILS_H

# include "ft_printf.h"

int		is_arr_sorted(int *arr, int len);
void	print_array(int *arr, int size);
int		biggest_arr_elem(int *arr, int len);
int		arr_elem_pos(int *arr, int len, int val);
int		nextbiggest(int *arr, int len, int val);

#endif
