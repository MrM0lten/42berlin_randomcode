#include "fdf.h"

void transform_object(object *obj,p3 pos)
{
	int i;

	i = 0;
	//ft_printf("entered transform object\n");
	while(i < obj->total_verticies)
	{
		obj->verticies[i].x += pos.x;
		obj->verticies[i].y += pos.y;
		obj->verticies[i].z += pos.z;
		i++;
	}

}
void scale_object(object *obj, float factor)
{
	int i;

	i = 0;
	while(i < obj->total_verticies)
	{
		obj->verticies[i].x *= factor;
		obj->verticies[i].y *= factor;
		obj->verticies[i].z *= factor;
		i++;
	}

}


void	iso(float *x, float *y, float z)
{
	float temp_x;
	float temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(0.523599);
	*y = -z + (temp_x + temp_y) * sin(0.523599);
}

void *ft_realloc(void *old, size_t old_size, size_t new_size)
{
	void *new;
	size_t copy_size;

	new = malloc(new_size);
	copy_size = old_size;
	if(new_size < old_size)
		copy_size = new_size;
	ft_memcpy(new,old,copy_size);
	free(old);
	return (new);
}
