#include "fdf.h"

void print_point(p3 *p)
{
	printf("p.x = <%lf,%lf,%lf>\n",p->x,p->y,p->z);
	printf("---------------------\n");
}


void print_object(object *obj)
{
	int i;
	i = 0;
 	while(i < obj->total_verticies)
	{
		printf("point[%i] = <(%lf,%lf,%lf),col = %i>\n",i,obj->verticies[i].x, obj->verticies[i].y, obj->verticies[i].z, obj->vertex_color[i]);
		i++;
	} 
	ft_printf("total verticies = %i\n",obj->total_verticies);
	ft_printf("total edges = %i\n",obj->total_edges);
	
}