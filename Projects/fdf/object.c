#include "fdf.h"
#include "malloc.h"

#define VERTEXBUFF 50000
#define FDF_VERTEXDISTANCE 1

int count_elems(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void put_object_edge_data(object *obj)
{
	int i;
	int edge_num;
	size_t tot_edges;

	tot_edges = ((int)obj->object_dim.y * (int)(obj->object_dim.x - 1)+ (int)obj->object_dim.x * (int)(obj->object_dim.y - 1)) ;
	printf("TOTAL EDGES %zu\n",tot_edges);
	obj->edges = (edge *)malloc(sizeof(edge) * tot_edges);
	i = 0;
	edge_num = 0;
	while(i < obj->total_verticies - 1)
	{
		//ft_printf("i = %i, eval to %i\n",i,(i - ((int)obj->object_dim.x -1)) % 19 );
		if((i - (int)(obj->object_dim.x -1)) % (int)obj->object_dim.x != 0) //IMPORTANT THINK ABOUT A WAY TO HAVE DIMENSIONS BE FLOATS note: may not be important due to map handling
		{	
			obj->edges[edge_num].elem_a = i;
			obj->edges[edge_num].elem_b = i+1;
			//ft_printf("connecting <%i,%i>\n",i,i+1);
			edge_num++;
		}
		i++;
	}
	i = 0;
	while(i < obj->total_verticies - obj->object_dim.x)
	{
		//ft_printf("i = %i, eval to %i\n",i,(i - ((int)obj->object_dim.x -1)) % 19 );
		obj->edges[edge_num].elem_a = i;
		obj->edges[edge_num].elem_b = i+(int)(obj->object_dim.x);
		ft_printf("connecting <%i,%i>\n",i,i+(int)(obj->object_dim.x));
		edge_num++;
		i++;
	}
	obj->total_edges = edge_num;
	ft_printf("TOTAL EDGES in edge_num = %i\n", edge_num);
	ft_printf("wtaf\n");
}

void put_object_vertex_data(object *mesh, char **splitline, int split_elems, int y)
{
	int i;

	i = 0;
	while(i < split_elems)
	{
		if(ft_strrchr(splitline[i],','))
		{
			mesh->verticies[mesh->total_verticies].x = i * FDF_VERTEXDISTANCE;
			mesh->verticies[mesh->total_verticies].y = y * FDF_VERTEXDISTANCE;
			mesh->verticies[mesh->total_verticies].z = ft_atoi(ft_substr(splitline[i],0,ft_poschr(splitline[i],',')));
			mesh->vertex_color[mesh->total_verticies] = ft_hextoi(ft_substr(splitline[i],ft_poschr(splitline[i],',') +1,20));
		}
		else
		{
			mesh->verticies[mesh->total_verticies ].x = i * FDF_VERTEXDISTANCE;
			mesh->verticies[mesh->total_verticies ].y = y * FDF_VERTEXDISTANCE;
			mesh->verticies[mesh->total_verticies ].z = ft_atoi(splitline[i]);
			mesh->vertex_color[mesh->total_verticies] = DEFAULTCOL;
		}
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
	mesh->verticies = (p3 *)malloc(sizeof(p3 ) * VERTEXBUFF);
	mesh->vertex_color = (int *)malloc(sizeof(int) * VERTEXBUFF);

	mesh->total_verticies = 0;
	mesh->total_edges = 0;
	mesh->object_dim.z = 0;
	return (mesh);
}

object *parse_fdf_file(int fd)
{
	char *line;
	char **splitline;
	object *mesh;
	int split_elems;
	int y;

	mesh = generate_empty_object();

	line = get_next_line(fd);
	y = 0;
	while(line)
	{
		splitline = ft_split(line, ' ');
		split_elems = count_elems(splitline);
		if(split_elems < VERTEXBUFF - mesh->total_verticies)
			put_object_vertex_data(mesh, splitline, split_elems, y);
		ft_printf("split elems = %i\n", split_elems);
		free_string_arr(splitline);
		free(line);
		line = NULL;
		splitline = NULL;
		line = get_next_line(fd);
		y++;
		split_elems = 0;
	}
	mesh->object_dim.x = mesh->total_verticies / y;
	mesh->object_dim.y = y;
	

	put_object_edge_data(mesh);

	//check how accurate it is, currently seems like it is the case
	mesh->verticies = ft_realloc(mesh->verticies, sizeof(p3) * VERTEXBUFF, sizeof(p3) * mesh->total_verticies);
	mesh->vertex_color = ft_realloc(mesh->vertex_color, sizeof(int) * VERTEXBUFF, sizeof(int) * mesh->total_verticies);

/* 	printf("MALLOC USEFUL SIZE %zu\n",malloc_usable_size(mesh->verticies));
	malloc_stats(); */

	return (mesh);
}

object *init_object(char *filename)
{
	int fd;
	object *obj;

	if(!validate_filetype(filename,".fdf"))
		return (ft_puterror(STDERR_FILENO,filename," .File does not have the proper .fdf format"));
	fd = open(filename,O_RDONLY);
	if(fd == -1)
		return (ft_puterror(STDERR_FILENO,filename," .File does not exist"));

	obj = parse_fdf_file(fd);

	//print_object(obj);
	
	close(fd);
	
	return (obj);
}

int validate_filetype(char *file,char *expected)
{
	int i;

	i = 0;
	while(file[i] && file[i] != '.')
		i++;
	return (ft_strncmp(&file[i],expected, 4));
}

void *ft_puterror(int fd,char * filename, char *err_mes)
{
	ft_putstr_fd("Error ",fd);
	ft_putstr_fd(filename,fd);
	ft_putstr_fd(err_mes,fd);
	return (NULL);
}
void free_string_arr(char **arr)
{
	int i;

	if(arr)
	{
		i = 0;
		while(arr[i])
		{
			free(arr[i]);
			arr[i] = 0;
			i++;
		}
		free(arr);
	}
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