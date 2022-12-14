/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:43:31 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/06 19:43:32 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(double *y, double *z, double alpha)
{
	double	temp_y;
	double	temp_z;

	temp_y = *y;
	temp_z = *z;
	alpha = alpha * M_PI / 180;
	*y = temp_y * cos(alpha) + temp_z * (-sin(alpha));
	*z = temp_y * sin(alpha) + temp_z * cos(alpha);
}

void	rotate_y(double *x, double *z, double beta)
{
	double	temp_x;
	double	temp_z;

	temp_x = *x;
	temp_z = *z;
	beta = beta * M_PI / 180;
	*x = temp_x * cos(beta) + temp_z * sin(beta);
	*z = temp_x * (-sin(beta)) + temp_z * cos(beta);
}

void	rotate_z(double *x, double *y, double gamma)
{
	double	temp_x;
	double	temp_y;

	temp_y = *y;
	temp_x = *x;
	gamma = gamma * M_PI / 180;
	*x = temp_x * cos(gamma) + temp_y * (-sin(gamma));
	*y = temp_x * sin(gamma) + temp_y * cos(gamma);
}

void	iso(double *x, double *y, double z)
{
	double	temp_x;
	double	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(0.523599);
	*y = -z + (temp_x + temp_y) * sin(0.523599);
}

t_p3	project(t_p3 p, t_prog *prog)
{
	scale_obj(prog->obj, &p);
	rotate_x(&p.y, &p.z, prog->obj->rot.x);
	rotate_y(&p.x, &p.z, prog->obj->rot.y);
	rotate_z(&p.x, &p.y, prog->obj->rot.z);
	transform_obj(prog->obj, &p);
	if (prog->iso)
		iso(&p.x, &p.y, p.z);
	p.x += 1.0f;
	p.y += 1.0f;
	p.x *= 0.5f * (float)X_SIZE / 2;
	p.y *= 0.5f * (float)Y_SIZE / 2;
	return (p);
}
