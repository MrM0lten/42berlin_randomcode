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
			*((int)obj->object_dim.y * (int)(obj->object_dim.x - 1)
				+(int)obj->object_dim.x * (int)(obj->object_dim.y - 1)));
	i = 0;
	while (i < obj->total_verticies - 1)
	{
		if ((i - (int)(obj->object_dim.x -1)) % (int)obj->object_dim.x != 0)
		{	
			obj->edges[obj->total_edges].elem_a = i;
			obj->edges[obj->total_edges].elem_b = i + 1;
			obj->total_edges++;
		}
		i++;
	}
	i = 0;
	while (i < obj->total_verticies - obj->object_dim.x)
	{
		obj->edges[obj->total_edges].elem_a = i;
		obj->edges[obj->total_edges].elem_b = i + (int)(obj->object_dim.x);
		obj->total_edges++;
		i++;
	}
}

void	put_object_vertex_data(t_object *mesh, char **splitline, int split_elems)
{
	int		i;
	char	*str_col;

	i = 0;
	while (i < split_elems)
	{
		mesh->verticies[mesh->total_verticies].x = i * FDF_VERTEXDISTANCE;
		mesh->verticies[mesh->total_verticies].y = mesh->object_dim.y
			* FDF_VERTEXDISTANCE;
		mesh->verticies[mesh->total_verticies].z = ft_atoi(splitline[i]);
		if (ft_poschr(splitline[i], ','))
		{
			str_col = ft_substr(splitline[i],
					ft_poschr(splitline[i], ',') + 1, 20);
			mesh->verticies[mesh->total_verticies].color = ft_hextoi(str_col);
			free (str_col);
		}
		else
			mesh->verticies[mesh->total_verticies].color = DEFAULTCOL;
		if (mesh->verticies[mesh->total_verticies].z > mesh->object_dim.z)
			mesh->object_dim.z = mesh->verticies[mesh->total_verticies].z;
		i++;
		mesh->total_verticies++;
	}
}

static t_object	*generate_empty_object(void)
{
	t_object	*mesh;

	mesh = (t_object *)malloc(sizeof(t_object));
	if (!mesh)
		return (NULL);
	mesh->verticies = (t_p3 *)malloc(sizeof(t_p3) * VERTEXBUFF);
	if (!mesh->verticies)
		return (NULL);
	mesh->total_verticies = 0;
	mesh->total_edges = 0;
	mesh->pos = make_point(0, 0, 0);
	mesh->rot = make_point(0, 0, 0);
	mesh->scale = make_point(1, 1, 1);
	mesh->object_dim = make_point(0, 0, 0);
	return (mesh);
}

t_object	*init_object(char *filename)
{
	int		fd;
	t_object	*obj;

	fd = open(filename, O_RDONLY);
	obj = generate_empty_object();
	obj = parse_fdf_file(fd, obj);
	if (!obj)
		return (NULL);
	close(fd);
	return (obj);
}

void	free_object(t_object *obj)
{
	if (obj)
	{
		if (obj->edges)
			free(obj->edges);
		if (obj->verticies)
			free(obj->verticies);
		free(obj);
	}
}
