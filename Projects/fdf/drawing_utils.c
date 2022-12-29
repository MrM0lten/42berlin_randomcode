#include "fdf.h"

void drawline(void *mlx_ptr, void *win_ptr, p3 *a, p3 *b, int color)
{
	double len;
	double i;
	double t;
	p3 *temp;

	ft_printf("enteredDrawline\n");
	len = vector_len(p_sub(a,b));
	i = 0;
	while((double)i < len)
	{
		ft_printf("loop\n");
		t = i / len;
		temp = p_sub(a,b);
		print_point(temp);
		mlx_pixel_put(mlx_ptr, win_ptr,(1 - t) * temp->x + b->x,(1 - t) * temp->y + b->y, color);
		i += 0.1;
	}
}

double vector_len(p3 *vec)
{
	return (sqrt(pow(vec->x,2) + pow(vec->y,2) + pow(vec->z,2)));
}

p3 *p_add(p3 *a, p3 *b)
{
	p3 *new;

	new->x = a->x + b->x;
	new->y = a->y + b->y;
	new->z = a->z + b->z;
	return (new);
}

p3 *p_sub(p3 *a, p3 *b)
{
	p3 *new;

	new->x = a->x - b->x;
	new->y = a->y - b->y;
	new->z = a->z - b->z;
	return (new);
}

void print_point(p3 *p)
{
	ft_printf("p.x = %i\n",p->x);
	ft_printf("p.y = %i\n",p->y);
	ft_printf("p.z = %i\n",p->z);
}