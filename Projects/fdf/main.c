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

void draw_cube(t_prog *prog, p3 *p_arr)
{

	drawline(prog->mlx, prog->win, &p_arr[0], &p_arr[1], 0xfffafa);
	drawline(prog->mlx, prog->win, &p_arr[1], &p_arr[2], 0xfffafa);
	drawline(prog->mlx, prog->win, &p_arr[2], &p_arr[3], 0xfffafa);
	drawline(prog->mlx, prog->win, &p_arr[3], &p_arr[0], 0xfffafa);

	drawline(prog->mlx, prog->win, &p_arr[4], &p_arr[5], 0xfffafa);
	drawline(prog->mlx, prog->win, &p_arr[5], &p_arr[6], 0xfffafa);
	drawline(prog->mlx, prog->win, &p_arr[6], &p_arr[7], 0xfffafa);
	drawline(prog->mlx, prog->win, &p_arr[7], &p_arr[4], 0xfffafa);

	drawline(prog->mlx, prog->win, &p_arr[0], &p_arr[4], 0xfffafa);
	drawline(prog->mlx, prog->win, &p_arr[1], &p_arr[5], 0xfffafa);
	drawline(prog->mlx, prog->win, &p_arr[2], &p_arr[6], 0xfffafa);
	drawline(prog->mlx, prog->win, &p_arr[3], &p_arr[7], 0xfffafa);
}
p3 *convert_p3_to_p2(p3 *p)
{	
	p3 temp;
	temp.x = ASPECT_RATIO*p->x/(p->z * tan((90 / 2)/(180 / M_PI)));
	temp.y = ASPECT_RATIO*p->y/(p->z * tan((90 / 2)/(180 / M_PI)));

	p->x = temp.x;
	p->y = temp.y;
	return (p);
}
void mulitplyMatrixVector(p3 *i, p3 *o)
{
	float fNear = 0.1f;
	float fFar = 1000.0f;
	float fFov = 90.0f;
	float fAspectRatio = X_SIZE / Y_SIZE;
	float fFovRad = 1.0f / tan(fFov *0.5f / 180.0f * M_PI);
	//mat4x4 m_proj;
	float m[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	m[0][0] = fAspectRatio * fFovRad;
	m[1][1] = fFovRad;
	m[2][2] = fFar / (fFar -fNear);
	m[3][2] = (-fFar *fNear) / (fFar - fNear);
	m[2][3] = 1.0f;
	m[3][3] = 0.0f;



	o->x = i->x * m[0][0] + i->y * m[1][0] + i->z * m[2][0] + m[3][0];
	o->y = i->x * m[0][1] + i->y * m[1][1] + i->z * m[2][1] + m[3][1];
	o->z = i->x * m[0][2] + i->y * m[1][2] + i->z * m[2][2] + m[3][2];
	float w = i->x * m[0][3] + i->y * m[1][3] + i->z * m[2][3] + m[3][3];
	printf("\n");
	printf("[%lf][%lf][%lf][%lf]\n", m[0][0],m[0][1],m[0][2],m[0][3]);
	printf("[%lf][%lf][%lf][%lf]\n", m[1][0],m[1][1],m[1][2],m[1][3]);
	printf("[%lf][%lf][%lf][%lf]\n", m[2][0],m[2][1],m[2][2],m[2][3]);
	printf("[%lf][%lf][%lf][%lf]\n", m[3][0],m[3][1],m[3][2],m[3][3]);

	if(w != 0.0f)
	{
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}

} 

int	main(void)
{
	void	*mlx;
	void	*win;
	t_prog prog;
	p3 p_in[] =	{{0.f,0.f,0.f},{0.f,0.f,1.f},{1.f,0.f,1.f},{1.f,0.f,0.f},
					{0.f,1.f,0.f},{0.f,1.f,1.f},{1.f,1.f,1.f},{1.f,1.f,0.f}};
	p3 p_out[] =	{{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f},{0.f,0.f,0.f}};
	int i = 0;


	//translating object into Z +3
	while(i < 8)
	{
		p_in[i].x += 1.0f;
		p_in[i].y += 1.0f;
		p_in[i].z += 1.0f;
		i++;
	}
	 i = 0;
	while(i < 8)
	{
		
		mulitplyMatrixVector(&p_in[i], &p_out[i]);

		//scale into view
		p_out[i].x += 1.0f;
		p_out[i].y += 1.0f;
		p_out[i].x *= 0.5f * (float)X_SIZE / 2;
		p_out[i].y *= 0.5f * (float)Y_SIZE / 2; //adjusted it since screen only has pos vals
		i++;
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, X_SIZE, Y_SIZE, "PogBrudi");
    prog.mlx = mlx;
    prog.win = win;
	mlx_mouse_hook(prog.win, &test, &prog);
	mlx_key_hook(prog.win, &close_prog, &prog);
	
	i =0;
	while(i < 8)
	{
		print_point(&p_in[i]);
		i++;
	}
	ft_printf("\n\n\n");
	i =0;
	while(i < 8)
	{
		mlx_pixel_put(prog.mlx,prog.win,p_out[i].x,p_out[i].y,0x228b22);
		print_point(&p_out[i]);
		i++;
	}




	draw_cube(&prog,&p_out);
	ft_printf("fml\n");
	mlx_loop(prog.mlx);
	
	
	return (0);
}


