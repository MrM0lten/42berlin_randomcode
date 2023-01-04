#include "fdf.h"

int handle_input(int keycode, void *param)
{
	t_prog *prog = param;
	ft_printf("keycode = %i\n",keycode);
	if(keycode == W) //enter
	{
		p3 test= {0,-1,0};
		transform_object(prog->obj,test);
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == S) //enter
	{
		p3 test= {0,1,0};
		transform_object(prog->obj,test);
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == A) //enter
	{
		p3 test= {-1,0,0};
		transform_object(prog->obj,test);
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == D) //enter
	{
		p3 test= {1,0,0};
		transform_object(prog->obj,test);
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == ESC || keycode == 65507 || keycode == 65535 )
	{
		mlx_destroy_window(prog->mlx,prog->win);
		mlx_loop_end(prog->mlx);
	}
	if(keycode == NUM_MIN) //enter
	{
		p3 test= {.5,.5,.5};
		scale_object(prog->obj, test);
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == NUM_PLUS) //enter
	{
		p3 test= {2,2,2};
		scale_object(prog->obj, test);
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == NUMPOINT) //scale Z
	{
		p3 test= {1,1,0.5};
		scale_object(prog->obj, test);
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == NUMZERO) //scale XY
	{
		p3 test= {2,2,1};
		scale_object(prog->obj, test);
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == NUM4) //scale XY
	{
		prog->rot.x += 0.05;
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == NUM8) //scale XY
	{
		prog->rot.y += 0.05;
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	if(keycode == NUM6) //scale XY
	{
		prog->rot.z += 0.05;
		put_image(prog,0,0);
		draw(prog,prog->obj);
	}
	
	return (0);
}