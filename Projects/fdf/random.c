#include "fdf.h"

mat4x4 generate_mat4x4(void)
{
	mat4x4 m = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

	return (m);
}
void transform_object(object *obj,p3 pos)
{
	int i;

	i = 0;
	while(i < obj->total_verticies)
	{
		obj->verticies[i]->x += pos.x;
		obj->verticies[i]->y += pos.y;
		obj->verticies[i]->z += pos.z;
		i++;
	}

}
void scale_object(object *obj, float factor)
{
	int i;

	i = 0;
	while(i < obj->total_verticies)
	{
		obj->verticies[i]->x *= factor;
		obj->verticies[i]->y *= factor;
		obj->verticies[i]->z *= factor;
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

void free_object(object *obj)
{
	int i;

	i = -1;
	if(obj)
	{
		if(obj->edges)
		{
			while(++i < obj->total_edges)
				free(obj->edges[i]);
			free(obj->edges);
		}
		if(obj->verticies)
		{
			i = -1;
			while(++i < obj->total_verticies)
				free(obj->verticies[i]);
			free(obj->verticies);
		}
		free(obj);
	}
}