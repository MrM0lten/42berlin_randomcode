/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:43:04 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/06 19:43:05 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline( t_prog *prog, t_p3 a, t_p3 b, int color)
{
	double	len;
	double	i;
	double	t;
	t_p3		temp;
	t_p2		val;

	if (a.x >= X_SIZE || a.x <= 0 || a.y >= Y_SIZE || a.y <= 0
		|| b.x >= X_SIZE || b.x <= 0 || b.y >= Y_SIZE || b.y <= 0)
		return ;
	len = vector_len(p_sub(a, b));
	i = 0;
	while (i < len)
	{
		t = i / len;
		temp = p_sub(a, b);
		val.x = (1 - t) * temp.x + b.x;
		val.y = (1 - t) * temp.y + b.y;
		put_pixel(&prog->img, val.x, val.y, color);
		i += 1;
	}
}

double	vector_len(t_p3 vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

void	put_pixel(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_new_image(t_prog *prog, int x, int y)
{
	if (prog->img.img)
		mlx_destroy_image(prog->mlx, prog->img.img);
	prog->img.img = mlx_new_image(prog->mlx, x, y);
	prog->img.addr = mlx_get_data_addr(prog->img.img, &prog->img.bits_per_pixel,
			&prog->img.line_length, &prog->img.endian);
}

void	draw(t_prog *prog, t_object *obj)
{
	int	i;

	i = 0;
	put_new_image(prog, X_SIZE, Y_SIZE);
	while (i < obj->tot_edges)
	{
		drawline(prog,
			project(create_point(&obj->verts[obj->edges[i].elem_a]), prog),
			project(create_point(&obj->verts[obj->edges[i].elem_b]), prog),
			obj->verts[obj->edges[i].elem_a].color);
		i++;
	}
	mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img, 0, 0);
}
