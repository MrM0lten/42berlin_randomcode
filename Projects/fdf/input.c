#include "fdf.h"

int handle_input(int keycode, void *param)
{
	t_prog *prog = param;
	ft_printf("keycode = %i\n",keycode);
	if(keycode == W) //enter
	{
		p3 test= {0,-1,0};
		transform_object(prog->obj,test);
		mlx_clear_window(prog->mlx,prog->win);
		draw(prog,prog->obj);
	}
	if(keycode == S) //enter
	{
		p3 test= {0,1,0};
		transform_object(prog->obj,test);
		mlx_clear_window(prog->mlx,prog->win);
		draw(prog,prog->obj);
	}
	if(keycode == A) //enter
	{
		p3 test= {-1,0,0};
		transform_object(prog->obj,test);
		mlx_clear_window(prog->mlx,prog->win);
		draw(prog,prog->obj);
	}
	if(keycode == D) //enter
	{
		p3 test= {1,0,0};
		transform_object(prog->obj,test);
		mlx_clear_window(prog->mlx,prog->win);
		draw(prog,prog->obj);
	}
	if(keycode == ESC || keycode == 65507 || keycode == 65535 )
	{
		mlx_destroy_window(prog->mlx,prog->win);
		mlx_loop_end(prog->mlx);
	}
	if(keycode == NUM_MIN) //enter
	{
		float test = 0.5;
		scale_object(prog->obj, test);
		mlx_clear_window(prog->mlx,prog->win);
		draw(prog,prog->obj);
	}
	if(keycode == NUM_PLUS) //enter
	{
		float test = 2;
		scale_object(prog->obj, test);
		mlx_clear_window(prog->mlx,prog->win);
		draw(prog,prog->obj);
	}
	
	return (0);
}