/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:42:40 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/06 19:42:41 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_point(t_p3 *p)
{
	printf(" <%lf,%lf,%lf> col = %i\n",p->x,p->y,p->z,p->color);
}
void print_object(t_object *obj)
{
	int i;
	i = 0;
 	while(i < obj->tot_verts)
	{
		printf("point[%i] = <(%lf,%lf,%lf),col = %i>\n",i,obj->verts[i].x, obj->verts[i].y, obj->verts[i].z, obj->verts[i].color);
		i++;
	}
	i = 0;
	while(i < obj->tot_edges)
	{
		printf("p[%i]",i);
		print_point(&obj->verts[obj->edges[i].elem_a]);
		printf(" ----- ");
		print_point(&obj->verts[obj->edges[i].elem_b]);
		printf("\n");
		i++;
	}
	ft_printf("total verticies = %i\n",obj->tot_verts);
	ft_printf("total edges = %i\n",obj->tot_edges);
	ft_printf("Object Dim = <%i,%i,%i>\n",(int)obj->dim.x,(int)obj->dim.y,(int)obj->dim.z);

	
}
