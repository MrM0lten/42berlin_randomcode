#include "fdf.h"

void print_point(p3 *p)
{
	printf(" <%lf,%lf,%lf>",p->x,p->y,p->z);
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
	i = 0;
	while(i < obj->total_edges)
	{
		printf("p[%i]",i);
		print_point(&obj->verticies[obj->edges[i].elem_a]);
		printf(" ----- ");
		print_point(&obj->verticies[obj->edges[i].elem_b]);
		printf("\n");
		i++;
	}
	ft_printf("total verticies = %i\n",obj->total_verticies);
	ft_printf("total edges = %i\n",obj->total_edges);
	ft_printf("Object Dim = <%i,%i,%i>\n",(int)obj->object_dim.x,(int)obj->object_dim.y,(int)obj->object_dim.z);

	
}