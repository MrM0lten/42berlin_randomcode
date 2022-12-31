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
#define Y_SIZE 500
#define X_SIZE 500
#define ASPECT_RATIO X_SIZE/Y_SIZE

int test(int button, int x, int y,void *param)
{
	t_prog *prog = param;
	mlx_pixel_put(prog->mlx,prog->win,x,y,0xfffafa);
	return (0);
}
int close_prog(int keycode, void *param)
{
	t_prog *prog = param;
	if(keycode == 65307 || keycode == 65507 || keycode == 65535 )
	{
		mlx_destroy_window(prog->mlx,prog->win);
		mlx_loop_end(prog->mlx);
	}
	return (0);
}

p3 matmult(mat4x4 m, p3 p)
{
	p3 temp;

	temp = p;
	p.x = temp.x * m.m[0][0] + temp.y * m.m[1][0] + temp.z * m.m[2][0] + m.m[3][0];
	p.y = temp.x * m.m[0][1] + temp.y * m.m[1][1] + temp.z * m.m[2][1] + m.m[3][1];
	p.z = temp.x * m.m[0][2] + temp.y * m.m[1][2] + temp.z * m.m[2][2] + m.m[3][2];
	float w = temp.x * m.m[0][3] + temp.y * m.m[1][3] + temp.z * m.m[2][3] + m.m[3][3];

	printf("\n");
	printf("[%lf][%lf][%lf][%lf]\n", m.m[0][0],m.m[0][1],m.m[0][2],m.m[0][3]);
	printf("[%lf][%lf][%lf][%lf]\n", m.m[1][0],m.m[1][1],m.m[1][2],m.m[1][3]);
	printf("[%lf][%lf][%lf][%lf]\n", m.m[2][0],m.m[2][1],m.m[2][2],m.m[2][3]);
	printf("[%lf][%lf][%lf][%lf]\n", m.m[3][0],m.m[3][1],m.m[3][2],m.m[3][3]); 

	if(w != 0.0f)
	{
		p.x /= w;
		p.y /= w;
		p.z /= w;
	}
	return (p);
}

object *create_unitcube()
{
	object *cube;
	p3 p_in[] =	{{0.f,0.f,0.f},{0.f,0.f,1.f},{1.f,0.f,1.f},{1.f,0.f,0.f},
					{0.f,1.f,0.f},{0.f,1.f,1.f},{1.f,1.f,1.f},{1.f,1.f,0.f}};
	cube =(object *)malloc(sizeof(object));
	cube->verticies = (p3 **)malloc(sizeof(p3 *) * 8);
	cube->edges = (edge **)malloc(sizeof(edge *) * 12);
	cube->total_edges = 12;
	cube->total_verticies = 8;

	int i = 0;
	p3 *temp;
	while(i < 8)
	{
		cube->verticies[i] = generate_point(p_in[i].x,p_in[i].y,p_in[i].z);
		i++;
	}
	i = 0;
	while(i < 12)
	{
		cube->edges[i] = (edge *)ft_calloc(sizeof(edge),1);
		i++;
	}
	cube->edges[0]->elem_a = 0;
	cube->edges[0]->elem_b = 1;
	cube->edges[1]->elem_a = 1;
	cube->edges[1]->elem_b = 2;
	cube->edges[2]->elem_a = 2;
	cube->edges[2]->elem_b = 3;
	cube->edges[3]->elem_a = 3;
	cube->edges[3]->elem_b = 0;
	cube->edges[4]->elem_a = 4;
	cube->edges[4]->elem_b = 5;
	cube->edges[5]->elem_a = 5;
	cube->edges[5]->elem_b = 6;
	cube->edges[6]->elem_a = 6;
	cube->edges[6]->elem_b = 7;
	cube->edges[7]->elem_a = 7;
	cube->edges[7]->elem_b = 4;
	cube->edges[8]->elem_a = 0;
	cube->edges[8]->elem_b = 4;
	cube->edges[9]->elem_a = 1;
	cube->edges[9]->elem_b = 5;
	cube->edges[10]->elem_a = 2;
	cube->edges[10]->elem_b = 6;
	cube->edges[11]->elem_a = 3;
	cube->edges[11]->elem_b = 7;

/* 	int i =0;
	while(i < 8)
	{
		print_point(&cube->verticies[i]);
		i++;
	} */
	
	return (cube);
}

//creates non allocated temp point
p3 create_point(p3 *p)
{
	p3 p_new;

	p_new = *p;
	return (p_new);
}

//does all the interesting transformation and projections with the endresult of a 2d projected point
p3 project(p3 p)
{
	iso(&p.x,&p.y,p.z);

	//scale into view
	p.x += 1.0f;
	p.y += 1.0f;
	p.x *= 0.5f * (float)X_SIZE / 2;
	p.y *= 0.5f * (float)Y_SIZE / 2;

	return (p);
}

void draw(t_prog *prog,object *obj)
{
	int i;

	i =0;
	while(i < obj->total_edges)
	{
		drawline(prog,
		project(create_point(obj->verticies[obj->edges[i]->elem_a])),
		project(create_point(obj->verticies[obj->edges[i]->elem_b])),
		0x228b22);
		i++;
	}
}

int	main(void)
{

	t_prog prog;
	p3 p_in[] =	{{0.f,0.f,0.f},{0.f,0.f,1.f},{1.f,0.f,1.f},{1.f,0.f,0.f},
					{0.f,1.f,0.f},{0.f,1.f,1.f},{1.f,1.f,1.f},{1.f,1.f,0.f}};
	p3 p_out[] =	{{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f}};
	int i = 0;

    prog.mlx = mlx_init();
    prog.win = mlx_new_window(prog.mlx, X_SIZE, Y_SIZE, "PogBrudi");
	mlx_mouse_hook(prog.win, &test, &prog);
	mlx_key_hook(prog.win, &close_prog, &prog);

	object *cube = create_unitcube();
	 i =0;
	 ft_printf("\n\n\n");
	draw(&prog,cube);




	ft_printf("fml\n");
	mlx_loop(prog.mlx);
	
	
	return (0);
}


