/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:43:08 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/06 19:43:09 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void toggle_iso(t_prog *prog)
{
	if(prog->iso)
		prog->iso = 0;
	else
		prog->iso = 1;
}

int handle_input(int keycode, void *param)
{
	t_prog *prog = param;
	ft_printf("keycode = %i\n",keycode);
	if(keycode == ESC)
	{
		mlx_loop_end(prog->mlx);
		return (0);
	}
	if(keycode == W)
		prog->obj->pos.y -= 0.5;
	if(keycode == S)
		prog->obj->pos.y += 0.5;
	if(keycode == A)
		prog->obj->pos.x -= 0.5;
	if(keycode == D)
		prog->obj->pos.x += 0.5;
	if(keycode == LEFTCTRL)
		prog->obj->pos.z -= 0.5;
	if(keycode == LEFTSHIFT)
		prog->obj->pos.z += 0.5;
	if(keycode == NUM_MIN)
	{
		prog->obj->scale.x *= 0.8;
		prog->obj->scale.y *= 0.8;
		prog->obj->scale.z *= 0.8;
	}
	if(keycode == NUM_PLUS)
	{
		prog->obj->scale.x *= 1.2;
		prog->obj->scale.y *= 1.2;
		prog->obj->scale.z *= 1.2;
	}
	if(keycode == NUMPOINT) //scale Z
		prog->obj->scale.z *= 0.9;
	if(keycode == NUM1) //rotx in degrees
		prog->obj->rot.x += 10;
	if(keycode == NUM4) //rotx in degrees
		prog->obj->rot.x -= 10;
	if(keycode == NUM2) //roty in degrees
		prog->obj->rot.y += 10;
	if(keycode == NUM5) //roty in degrees
		prog->obj->rot.y -= 10;
	if(keycode == NUM3) //rotz in degrees
		prog->obj->rot.z += 10;
	if(keycode == NUM6) //rotz in degrees
		prog->obj->rot.z -= 10;
	if(keycode == NUM9) //rotz in degrees
		prog->obj->rot.z = 1.5708;
	if(keycode == NUM7)
		toggle_iso(prog);
	if(keycode == BACKSPACE)
	{
		prog->obj->rot = make_point(0,0,0);
		prog->obj->pos = make_point(1,0,0);
		prog->obj->scale = make_point(.01,.01,.01);
	}
	if(keycode == T)
		prog->obj->rot = make_point(0,0,0);
	if(keycode == F)
		prog->obj->rot = make_point(90,0,0);
	if(keycode == B)
		prog->obj->rot = make_point(-90,0,180);
	if(keycode == L)
		prog->obj->rot = make_point(90,90,0);
	if(keycode == R)
		prog->obj->rot = make_point(90,270,0);
	draw(prog,prog->obj);
	return (0);
}


void shutdown_programm(t_prog *prog)
{
	mlx_destroy_image(prog->mlx,prog->img.img);
	mlx_destroy_window(prog->mlx,prog->win);
	mlx_destroy_display(prog->mlx);
	free_object(prog->obj);

	free(prog->mlx);
	free(prog);
	ft_printf("shutdown complete\n");
}
