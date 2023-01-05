#include "fdf.h"

int handle_input(int keycode, void *param)
{
	t_prog *prog = param;
	ft_printf("keycode = %i\n",keycode);
	if(keycode == ESC || keycode == 65507 || keycode == 65535 )
	{
		mlx_destroy_window(prog->mlx,prog->win);
		mlx_loop_end(prog->mlx);
	}
	if(keycode == W) //enter
		transform_object(prog->obj,make_point(0,-1,0));
	if(keycode == S) //enter
		transform_object(prog->obj, make_point(0,1,0));
	if(keycode == A) //enter
		transform_object(prog->obj,make_point(-1,0,0));
	if(keycode == D) //enter
		transform_object(prog->obj, make_point(1,0,0));
	if(keycode == NUM_MIN) //enter
		scale_object(prog->obj, make_point(0.5f,0.5f,0.5f));
	if(keycode == NUM_PLUS) //enter
		scale_object(prog->obj, make_point(2,2,2));
	if(keycode == NUMPOINT) //scale Z
		scale_object(prog->obj, make_point(1,1,0.5));
	if(keycode == NUMZERO) //scale XY
		scale_object(prog->obj, make_point(2,2,1));
	if(keycode == NUM1) //rotx
		prog->rot.x += 0.25;
	if(keycode == NUM4) //rotx
		prog->rot.x -= 0.25;
	if(keycode == NUM2) //roty
		prog->rot.y += 0.25;
	if(keycode == NUM5) //roty
		prog->rot.y -= 0.25;
	if(keycode == NUM3) //rotz
		prog->rot.z += 0.25;
	if(keycode == NUM6) //rotz
		prog->rot.z -= 0.25;
	if(keycode == BACKSPACE)
		prog->rot = make_point(0,0,0);
	if(keycode == NUM9) 
	{
		while(1)
		{
			prog->rot.x += 0.25;
			draw(prog,prog->obj);
		}	
	}

	draw(prog,prog->obj);
	return (0);
}