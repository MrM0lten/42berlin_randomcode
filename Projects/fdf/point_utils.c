#include "fdf.h"

p3 p_add(p3 a, p3 b)
{
	p3 new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	new.z = a.z + b.z;
	return (new);
}

p3 p_sub(p3 a, p3 b)
{
	p3 new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	new.z = a.z - b.z;
	return (new);
}
//allocates space for a point on the heap and returns a pointer to it
p3 *generate_point(int x, int y, int z)
{
	p3 *p;

	p = (p3 *)malloc(sizeof(p3));
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

p3 make_point(float x,float y,float z)
{
	p3 p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}