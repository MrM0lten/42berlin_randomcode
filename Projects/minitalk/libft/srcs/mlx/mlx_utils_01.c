/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:57:33 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/08 13:57:41 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include <math.h>

double	vector_len(t_p3 vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

t_p3	p_add(t_p3 a, t_p3 b)
{
	t_p3	new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	new.z = a.z + b.z;
	return (new);
}

t_p3	p_sub(t_p3 a, t_p3 b)
{
	t_p3	new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	new.z = a.z - b.z;
	return (new);
}

t_p3	make_point(double x, double y, double z)
{
	t_p3	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
