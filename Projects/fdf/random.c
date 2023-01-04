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
void scale_object(object *obj, p3 factor)
{
	int i;

	i = 0;
	while(i < obj->total_verticies)
	{
		obj->verticies[i].x *= factor.x;
		obj->verticies[i].y *= factor.y;
		obj->verticies[i].z *= factor.z;
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

size_t	ft_poschr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] != '\0' || (char)c == '\0')
		return (i);
	else
		return (0);
}

int ft_hextoi(char *str)
{
	int i;
	int rtn;
	int byte;

	i = 0;
	rtn = 0;
	if(str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while(str[i]) //could have also done it with rtn = rtn * 16 -(15 -character)
	{
		if(str[i] >= 'a' && str[i] <= 'f')
			byte = str[i] - 'a' + 10;
		else if(str[i] >= 'A' && str[i] <= 'F')
			byte = str[i] - 'A' + 10;
		else
			byte = str[i] - '0';
		rtn = (rtn << 4) | (byte & 0xF);
		i++;
	}
	return (rtn);
} 