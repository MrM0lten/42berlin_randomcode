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
	p2	sign;
	p3	cur;

	//dont print anything if any of the 2 points are outside the screen
	if(a.x > X_SIZE && a.x < 0 && b.y > Y_SIZE && b.y < 0)
		return ;

	delta.x = ft_abs(b.x - a.x);
	delta.y = ft_abs(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		put_pixel(&prog->img,cur.x, cur.y, color);
		
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