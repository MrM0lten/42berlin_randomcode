/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:43:26 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/06 19:43:27 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "malloc.h"

void	put_object_edge_data(t_object *obj)
{
	int		i;

	obj->edges = (t_edge *)malloc(sizeof(t_edge)
			*((int)obj->dim.y * (int)(obj->dim.x - 1)
				+(int)obj->dim.x * (int)(obj->dim.y - 1)));
	i = 0;
	while (i < obj->tot_verts - 1)
	{
		if ((i - (int)(obj->dim.x -1)) % (int)obj->dim.x != 0)
		{	
			obj->edges[obj->tot_edges].elem_a = i;
			obj->edges[obj->tot_edges].elem_b = i + 1;
			obj->tot_edges++;
		}
		i++;
	}
	i = 0;
	while (i < obj->tot_verts - obj->dim.x)
	{
		obj->edges[obj->tot_edges].elem_a = i;
		obj->edges[obj->tot_edges].elem_b = i + (int)(obj->dim.x);
		obj->tot_edges++;
		i++;
	}
}

void	put_object_vertex_data(t_object *mesh, char **splt, int split_elems)
{
	int		i;
	char	*str_col;

	i = 0;
	while (i < split_elems - 1)
	{
		mesh->verts[mesh->tot_verts].x = i * VERTDIST;
		mesh->verts[mesh->tot_verts].y = mesh->dim.y * VERTDIST;
		mesh->verts[mesh->tot_verts].z = ft_atoi(splt[i]);
		if (ft_poschr(splt[i], ','))
		{
			str_col = ft_substr(splt[i], ft_poschr(splt[i], ',') + 1, 20);
			mesh->verts[mesh->tot_verts].color = ft_hextoi(str_col);
			free (str_col);
		}
		else
			mesh->verts[mesh->tot_verts].color = DEFAULTCOL;
		if (mesh->verts[mesh->tot_verts].z > mesh->dim.z)
			mesh->dim.z = mesh->verts[mesh->tot_verts].z;
		i++;
		mesh->tot_verts++;
	}
}

static t_object	*generate_empty_object(void)
{
	t_object	*mesh;

	mesh = (t_object *)malloc(sizeof(t_object));
	if (!mesh)
		return (NULL);
	mesh->verts = (t_p3 *)malloc(sizeof(t_p3) * VERTEXBUFF);
	if (!mesh->verts)
		return (NULL);
	mesh->tot_verts = 0;
	mesh->tot_edges = 0;
	mesh->pos = make_point(0, 0, 0);
	mesh->rot = make_point(0, 0, 0);
	mesh->scale = make_point(.1, .1, .1);
	mesh->dim = make_point(0, 0, 0);
	return (mesh);
}

t_object	*init_object(char *filename)
{
	int			fd;
	t_object	*obj;

	fd = open(filename, O_RDONLY);
	obj = generate_empty_object();
	parse_fdf_file(fd, obj);
	if (!obj || !obj->verts)
		return (NULL);
	close(fd);
	obj->dim.x = obj->tot_verts / obj->dim.y;
	put_object_edge_data(obj);
	if (!obj->edges)
		return (NULL);
	return (obj);
}

void	free_object(t_object *obj)
{
	if (obj)
	{
		if (obj->edges)
		{
			free(obj->edges);
			obj->edges = NULL;
		}
		if (obj->verts)
		{
			free(obj->verts);
			obj->verts = NULL;
		}
		free(obj);
	}
}
