#include "fdf.h"

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
		transform_object(prog->obj,make_point(0,-1,0));
	if(keycode == S)
		transform_object(prog->obj, make_point(0,1,0));
	if(keycode == A)
		transform_object(prog->obj,make_point(-1,0,0));
	if(keycode == D)
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
		prog->obj->rot.x += 0.25;
	if(keycode == NUM4) //rotx
		prog->obj->rot.x -= 0.25;
	if(keycode == NUM2) //roty
		prog->obj->rot.y += 0.25;
	if(keycode == NUM5) //roty
		prog->obj->rot.y -= 0.25;
	if(keycode == NUM3) //rotz
		prog->obj->rot.z += 0.25;
	if(keycode == NUM6) //rotz
		prog->obj->rot.z -= 0.25;
	if(keycode == BACKSPACE)
		prog->obj->rot = make_point(0,0,0);

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