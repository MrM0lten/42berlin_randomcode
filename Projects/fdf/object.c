#include "fdf.h"
#include "malloc.h"

void put_object_edge_data(object *obj)
{
	int i;
	size_t tot_edges;

	tot_edges = ((int)obj->object_dim.y * (int)(obj->object_dim.x - 1) + (int)obj->object_dim.x * (int)(obj->object_dim.y - 1)) ;
	obj->edges = (edge *)malloc(sizeof(edge) * tot_edges);
	i = 0;
	while(i < obj->total_verticies - 1)
	{
		if((i - (int)(obj->object_dim.x -1)) % (int)obj->object_dim.x != 0)
		{	
			obj->edges[obj->total_edges].elem_a = i;
			obj->edges[obj->total_edges].elem_b = i+1;
			obj->total_edges++;
		}
		i++;
	}
	i = 0;
	while(i < obj->total_verticies - obj->object_dim.x)
	{
		obj->edges[obj->total_edges].elem_a = i;
		obj->edges[obj->total_edges].elem_b = i+(int)(obj->object_dim.x);
		obj->total_edges++;
		i++;
	}
}

void put_object_vertex_data(object *mesh, char **splitline, int split_elems)
{
	int i;
	char *str_col;

	i = 0;
	while(i < split_elems)
	{
		mesh->verticies[mesh->total_verticies].x = i * FDF_VERTEXDISTANCE;
		mesh->verticies[mesh->total_verticies].y = mesh->object_dim.y * FDF_VERTEXDISTANCE;
		mesh->verticies[mesh->total_verticies].z = ft_atoi(splitline[i]);
		if(ft_poschr(splitline[i],','))
		{
			str_col = ft_substr(splitline[i],ft_poschr(splitline[i],',') +1,20);
			mesh->verticies[mesh->total_verticies].color = ft_hextoi(str_col);
			free (str_col);
		}
		else
			mesh->verticies[mesh->total_verticies].color = DEFAULTCOL;
		if(mesh->verticies[mesh->total_verticies ].z > mesh->object_dim.z)
			mesh->object_dim.z = mesh->verticies[mesh->total_verticies ].z;
		i++;
		mesh->total_verticies++;
	}
}

static object *generate_empty_object()
{
	object *mesh;
	mesh = (object *)malloc(sizeof(object));
	if(!mesh)
		return (NULL);
	mesh->verticies = (p3 *)malloc(sizeof(p3 ) * VERTEXBUFF);
	if(!mesh->verticies)
		return (NULL);
	mesh->total_verticies = 0;
	mesh->total_edges = 0;
	mesh->rot = make_point(0,0,0);
	mesh->object_dim = make_point(0,0,0);
	return (mesh);
}

object *init_object(char *filename)
{
	int fd;
	object *obj;

	fd = open(filename,O_RDONLY);
	obj = generate_empty_object();
	obj = parse_fdf_file(fd, obj);
	if(!obj)
		return (NULL);
	
	close(fd);
	return (obj);
}

void free_object(object *obj)
{
	if(obj)
	{
		if(obj->edges)
			free(obj->edges);
		if(obj->verticies)
			free(obj->verticies);
		free(obj);
	}
}