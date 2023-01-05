#include "fdf.h"

void drawline( t_prog *prog, p3 a, p3 b, int color)
{
	double len;
	double i;
	double t;
	p3 temp;
	int x;
	int y;

	len = vector_len(p_sub(a,b));
	//printf("%lf\n",len);
	i = 0;
	while(i < len)
	{
		t = i / len;
		temp = p_sub(a,b);
		//mlx_pixel_put(prog->mlx, prog->win,(1 - t) * temp.x + b.x,(1 - t) * temp.y + b.y, color);
		//ft_printf("trying to put a pixel at <%i,%i>\n",(1 - t) * temp.x + b.x, (1 - t) * temp.y + b.y);
		x = (1 - t) * temp.x + b.x;
		y = (1 - t) * temp.y + b.y;
		if(x < X_SIZE && x > 0 && y < Y_SIZE && y > 0)
			put_pixel(&prog->img,x, y, color);
		i += 1;
	}
}

void drawline2( t_prog *prog, p3 a, p3 b, int color)
{
	int dx;
	int dy;
	int p;

/* 	print_point(&a);
	print_point(&b); */

/* 	if(a.x < X_SIZE && a.x > 0 && a.y < Y_SIZE && a.y > 0)
		return ;
	
	dx = a.x - b.x;
	dy = a.y - b.y;
	p = 2 * dy - dx;

	while(a.x <= b.x)
	{
		put_pixel(&prog->img,(int)a.x, (int)a.y, color);
		a.x += 1;
		if(p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			a.y++;
		}
	} */

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
		free(prog->img.img);
	prog->img.img = mlx_new_image(prog->mlx, X_SIZE, Y_SIZE);
	prog->img.addr = mlx_get_data_addr(prog->img.img, &prog->img.bits_per_pixel,
						 &prog->img.line_length, &prog->img.endian);
}