/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:22:19 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/29 11:22:43 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int test(int button, int x, int y, void *param)
{
	t_prog *prog = param;
	mlx_pixel_put(prog->mlx, prog->win, x, y, 0xfffafa);

	return (0);
}


object *create_unitcube()
{
	object *cube;
	p3 p_in[] = {{0.f, 0.f, 0.f}, {0.f, 0.f, 1.f}, {1.f, 0.f, 1.f}, {1.f, 0.f, 0.f}, {0.f, 1.f, 0.f}, {0.f, 1.f, 1.f}, {1.f, 1.f, 1.f}, {1.f, 1.f, 0.f}};
	cube = (object *)malloc(sizeof(object));
	cube->verticies = (p3 *)malloc(sizeof(p3) * 8);
	cube->vertex_color = (int *)malloc(sizeof(int) * 8);
	cube->edges = (edge *)malloc(sizeof(edge) * 12);
	cube->total_edges = 12;
	cube->total_verticies = 8;

	int i = 0;
	p3 *temp;
	while (i < 8)
	{
		cube->verticies[i].x = p_in[i].x;
		cube->verticies[i].y = p_in[i].y;
		cube->verticies[i].z = p_in[i].z;
		cube->vertex_color[i] = DEFAULTCOL;
		i++;
	}
	cube->edges[0].elem_a = 0;
	cube->edges[0].elem_b = 1;
	cube->edges[1].elem_a = 1;
	cube->edges[1].elem_b = 2;
	cube->edges[2].elem_a = 2;
	cube->edges[2].elem_b = 3;
	cube->edges[3].elem_a = 3;
	cube->edges[3].elem_b = 0;
	cube->edges[4].elem_a = 4;
	cube->edges[4].elem_b = 5;
	cube->edges[5].elem_a = 5;
	cube->edges[5].elem_b = 6;
	cube->edges[6].elem_a = 6;
	cube->edges[6].elem_b = 7;
	cube->edges[7].elem_a = 7;
	cube->edges[7].elem_b = 4;
	cube->edges[8].elem_a = 0;
	cube->edges[8].elem_b = 4;
	cube->edges[9].elem_a = 1;
	cube->edges[9].elem_b = 5;
	cube->edges[10].elem_a = 2;
	cube->edges[10].elem_b = 6;
	cube->edges[11].elem_a = 3;
	cube->edges[11].elem_b = 7;

	return (cube);
}

// creates non allocated temp point
p3 create_point(p3 *p)
{
	p3 p_new;

	p_new = *p;
	return (p_new);
}

// does all the interesting transformation and projections with the endresult of a 2d projected point
p3 project(p3 p)
{
	iso(&p.x, &p.y, p.z);

	// scale into view
	p.x += 1.0f;
	p.y += 1.0f;
	p.x *= 0.5f * (float)X_SIZE / 2;
	p.y *= 0.5f * (float)Y_SIZE / 2;

	return (p);
}

void draw(t_prog *prog, object *obj)
{
	int i;

	i = 0;
	while (i < obj->total_edges)
	{
		drawline(prog,
				 project(create_point(&obj->verticies[obj->edges[i].elem_a])),
				 project(create_point(&obj->verticies[obj->edges[i].elem_b])),
				 obj->vertex_color[obj->edges[i].elem_b]);
		i++;
	}
}

int main(int ac, char **av)
{
	t_prog *prog;

	prog = malloc(sizeof(t_prog));
	
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, X_SIZE, Y_SIZE, "PogBrudi");
	prog->img.img = mlx_new_image(prog->mlx, X_SIZE, Y_SIZE);
	if (ac == 1)
		prog->obj = create_unitcube();
	if (av[1] != NULL)
		prog->obj = init_object(av[1]);

	mlx_mouse_hook(prog->win, &test, prog);
	mlx_key_hook(prog->win, &handle_input, prog);

	prog->img.addr = mlx_get_data_addr(prog->img.img, &prog->img.bits_per_pixel,
						 &prog->img.line_length, &prog->img.endian);

	if (prog->obj)
	{
		ft_printf("fml\n");
		draw(prog, prog->obj);
		mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img, 0, 0);
		ft_printf("end\n");
		mlx_loop(prog->mlx);
	}

	return (0);
}
