/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:42:53 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/06 19:42:54 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

//allocates space for a point on the heap and returns a pointer to it
t_p3	*generate_point(int x, int y, int z)
{
	t_p3	*p;

	p = (t_p3 *)malloc(sizeof(t_p3));
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

t_p3	make_point(double x, double y, double z)
{
	t_p3	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

// creates non allocated temp point
t_p3	create_point(t_p3 *p)
{
	t_p3	p_new;

	p_new.x = p->x;
	p_new.y = p->y;
	p_new.z = p->z;
	p_new.color = p->color;
	return (p_new);
}
