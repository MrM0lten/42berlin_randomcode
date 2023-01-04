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

void put_image(t_prog *prog, int x, int y)
{
	int i;
	int j;

	i = 0;
	
	//clear image first
	while(i < Y_SIZE)
	{
		j = -1;
		while(++j < X_SIZE)
			put_pixel(&prog->img,j,i,0x0);
		i++;
	}
	mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img, x, y);
}