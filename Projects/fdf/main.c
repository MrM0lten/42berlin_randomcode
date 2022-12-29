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

 void matrix(float pan, float tilt, float *cp,float *sp, float *ct,float *st)
 {
	*cp = cos(pan);
	*sp = sin(pan);
	*ct = cos(tilt);
	*st = sin(tilt);
 }

int test(int button, int x, int y,void *param)
{
	t_prog *prog = param;
	//ft_printf("%i\n",x);
	mlx_pixel_put(prog->mlx,prog->win,x,y,0xfffafa);
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
int all_one(p3 *in,p3 *out,p3 *view, float cp, float sp, float ct, float st, float l)
{
	p3 d;
	float tt,X,Y,Z;

	d.x = in->x - view->x;
	d.y = in->y - view->y;
	d.z = in->z - view->z;

	tt=((((ct*cp*ct*cp)))+(ct*sp*ct*sp)+(st*st))/(-(ct*cp*d.x)-(ct*sp*d.y) + (st*d.z));
	if(tt<0 || tt>l)
		return (0);

	X=l*((tt*d.x)-(ct*cp));
	Y = l*((ct*sp)-(tt*d.y));
	Z = l*((tt*d.z)+st);

	out->x=(sp * X)+(cp * Y)+(X_SIZE/2);
	out->y=(Y_SIZE/2)-(((cp*X)-(sp*Y))*st)-(Z*ct);

	if(out->x<-100 || out->x > X_SIZE +100 || out->y < -100 || out->y>Y_SIZE+100)
		return (0);
	else
		return (1);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_prog prog;
	float pan = 40;
	float tilt = 83;
	float cp;
	float sp;
	float ct;
	float st;
	float l = 50;
	p3 view = {00,00,00};	

	
	p3 p_arr[] =	{{200,200,200},{300,200,200},{300,200,300},{200,200,300},
					{200,300,200},{300,300,200},{300,300,300},{200,300,300}};
	print_point(&p_arr[0]);
	matrix(pan,tilt,&cp,&sp,&ct,&st);
	int i = 0;
	while(i < 8)
	{
		all_one(&p_arr[i],&p_arr[i],&view,cp,sp,ct,st,l);
		i++;
	}
	print_point(&p_arr[0]);

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "PogBrudi");

    prog.mlx = mlx;
    prog.win = win;


	mlx_mouse_hook(win, &test, &prog);

	

	draw_cube(&prog,&p_arr);
	mlx_loop(mlx);

	
	return (0);
}


