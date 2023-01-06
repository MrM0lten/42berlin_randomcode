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

object *create_unitcube()
{
	object *cube;
	p3 p_in[] = {{0.f, 0.f, 0.f, DEFAULTCOL}, {0.f, 0.f, 1.f}, {1.f, 0.f, 1.f}, {1.f, 0.f, 0.f}, {0.f, 1.f, 0.f}, {0.f, 1.f, 1.f}, {1.f, 1.f, 1.f}, {1.f, 1.f, 0.f}};
	cube = (object *)malloc(sizeof(object));
	cube->verticies = (p3 *)malloc(sizeof(p3) * 8);
	cube->edges = (edge *)malloc(sizeof(edge) * 12);
	if(!cube || !cube->verticies || !cube->edges)
		return (NULL);
	cube->total_edges = 12;
	cube->total_verticies = 8;
	int i = 0;
	p3 *temp;
	while (i < 8)
	{
		cube->verticies[i].x = p_in[i].x;
		cube->verticies[i].y = p_in[i].y;
		cube->verticies[i].z = p_in[i].z;
		cube->verticies[i].color = DEFAULTCOL;
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

	p_new.x = p->x;
	p_new.y = p->y;
	p_new.z = p->z;
	p_new.color = p->color;
	return (p_new);
}

int close_programm(void *param)
{
	(void)param;
	printf("close prog was called\n");
	return (0);
}

int main(int ac, char **av)
{
	t_prog *prog;

	prog = malloc(sizeof(t_prog));
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, X_SIZE, Y_SIZE, "PogBrudi");

	if (ac == 1)
		prog->obj = create_unitcube();
	if (av[1] != NULL)
		prog->obj = init_object(av[1]);

	mlx_key_hook(prog->win, &handle_input, prog);
	//mlx_hook(prog->win,17,0L, &close_programm,prog);
	if (prog->obj)
	{
		draw(prog, prog->obj);
		
	}
	mlx_loop(prog->mlx);
	ft_printf("test\n");
	return (0);
}
