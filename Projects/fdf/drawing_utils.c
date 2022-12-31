#include "fdf.h"

void drawline( t_prog *prog, p3 a, p3 b, int color)
{
	double len;
	double i;
	double t;
	p3 temp;

	len = vector_len(p_sub(a,b));
	printf("%lf\n",len);
	i = 0;
	while(i < len)
	{
		t = i / len;
		temp = p_sub(a,b);
		mlx_pixel_put(prog->mlx, prog->win,(1 - t) * temp.x + b.x,(1 - t) * temp.y + b.y, color);
		i += 1;
	}
}

double vector_len(p3 vec)
{
	return (sqrt(pow(vec.x,2) + pow(vec.y,2) + pow(vec.z,2)));
}