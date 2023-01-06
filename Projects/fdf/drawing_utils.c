#include "fdf.h"

void drawline( t_prog *prog, p3 a, p3 b, int color)
{
	double len;
	double i;
	double t;
	p3 temp;
	p2 val;

	len = vector_len(p_sub(a,b));
	i = 0;
	while(i < len)
	{
		t = i / len;
		temp = p_sub(a,b);
		val.x = (1 - t) * temp.x + b.x;
		val.y = (1 - t) * temp.y + b.y;
		if(val.x < X_SIZE && val.x > 0 && val.y < Y_SIZE && val.y > 0)
			put_pixel(&prog->img,val.x, val.y, color);
		i += 1;
	}
}

void drawline2( t_prog *prog, p3 a, p3 b, int color)
{
	p3	delta;
	p3	inc;

	//dont print anything if any of the 2 points are outside the screen
	if(a.x > X_SIZE || a.x < 0 || a.y > Y_SIZE || a.y < 0)
		return ;

	delta.x = ft_abs(b.x - a.x);
	delta.y = ft_abs(b.y - a.y);
	if(delta.x > delta.y)
	{
		inc.x = delta.x/delta.x;
		inc.y = delta.y/delta.x;
	}
	else
	{
		inc.x = delta.x/delta.y;
		inc.y = delta.y/delta.y;
	}

	while (a.x != b.x || a.y != b.y)
	{
		put_pixel(&prog->img,a.x, a.y, color);
		if(a.x < b.x)
			a.x += inc.x;
		else
			a.x -= inc.x;
		if(a.y < b.y)
			a.y += inc.y;
		else
			a.y -= inc.y;
	}

}

double vector_len(p3 vec)
{
	return (sqrt(pow(vec.x,2) + pow(vec.y,2) + pow(vec.z,2)));
}

void put_pixel(img_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_new_image(t_prog *prog, int x, int y)
{
	if(prog->img.img)
		mlx_destroy_image(prog->mlx,prog->img.img); //may not work properly
	prog->img.img = mlx_new_image(prog->mlx, x, y);
	prog->img.addr = mlx_get_data_addr(prog->img.img, &prog->img.bits_per_pixel,
						 &prog->img.line_length, &prog->img.endian);
}

void draw(t_prog *prog, object *obj)
{
	int i;

	i = 0;
	put_new_image(prog, X_SIZE, Y_SIZE);
	while (i < obj->total_edges)
	{
		drawline(prog,
				 project(create_point(&obj->verticies[obj->edges[i].elem_a]),prog),
				 project(create_point(&obj->verticies[obj->edges[i].elem_b]),prog),
				 obj->verticies[obj->edges[i].elem_a].color);
		i++;
	}
	mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img, 0, 0);
}