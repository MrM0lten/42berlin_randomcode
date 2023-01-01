#include "fdf.h"

#define VERTEXBUFF 10000
#define FDF_VERTEXDISTANCE 10

int count_elems(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
/* int ft_hex_to_i(char *str)
{

} */

void put_object_edge_data(object *obj)
{
	int i;
	int j;
	int edge_num;

	obj->edges = (edge *)malloc(sizeof(edge) * 1000);

	i = 0;
	edge_num = 0;
	j = 0;
	while(i < obj->total_verticies - 1)
	{
		if(i % 5 != 0 || i == 0)
		{
			obj->edges[edge_num].elem_a = i;
			obj->edges[edge_num].elem_b = i+1;
			ft_printf("connecting <%i,%i>\n",i,i+1);
			edge_num++;
		}

		
		i++;
		
	}

/* 	while(i < obj->object_dim.y -1)
	{
		j = 0;
		while(j < obj->object_dim.x - 1)
		{
			//edges[edge_num].elem_a = (obj->total_verticies % obj->object_dim.x) + (obj->total_verticies / obj->object_dim.x) * j + j;
			//edges[edge_num].elem_b = (obj->total_verticies % obj->object_dim.x) + (obj->total_verticies / obj->object_dim.x) * j + j +1;
			ft_printf("connecting <%i,%i>\n", ((obj->total_verticies % (int)obj->object_dim.x) + (obj->total_verticies / (int)obj->object_dim.x) * i + i + j),
			(obj->total_verticies % (int)obj->object_dim.x) + (obj->total_verticies / (int)obj->object_dim.x) * i + i + j + 1);
			j++;
			edge_num++;
		}
		i++;
	} */


	//obj->total_edges = edge_num;

	ft_printf("wtaf\n");
}

void put_object_vertex_data(object *mesh, char **splitline, int split_elems, int y)
{
	int i;

	i = 0;
	printf("y = %i\n",y);
	while(i < split_elems)
	{
		if(ft_strrchr(splitline[i],','))
		{
			printf("adasdsa");
			mesh->verticies[mesh->total_verticies + i].x = i * FDF_VERTEXDISTANCE;
			mesh->verticies[mesh->total_verticies + i].y = y * FDF_VERTEXDISTANCE;
			//mesh->verticies[mesh->total_verticies + i].z = ft_atoi(ft_substr(splitline[i],0,ft_strrchr(splitline[i],',')));
			//mesh->vertex_color[mesh->total_verticies + i] = ft_hex_to_i(ft_substr(splitline[i],ft_strrchr(splitline[i],',') +1,20));
		}
		else
		{
			printf("here");
			mesh->verticies[mesh->total_verticies + i].x = i * FDF_VERTEXDISTANCE;
			mesh->verticies[mesh->total_verticies + i].y = y * FDF_VERTEXDISTANCE;
			mesh->verticies[mesh->total_verticies + i].z = ft_atoi(splitline[i]);
			//ft_printf("ft_atoi(splitline[i]) = %i\n",ft_atoi(splitline[i]));
			//print_point(&mesh->verticies[mesh->total_verticies + i]);
			mesh->vertex_color[mesh->total_verticies + i] = DEFAULTCOL;
		}
		i++;
		mesh->total_verticies++;
	}
	
}

object *parse_fdf_file(int fd)
{
	char *line;
	char **splitline;
	object *mesh;
	int split_elems;
	int y;

	mesh = (object *)malloc(sizeof(object));
	mesh->verticies = (p3 *)malloc(sizeof(p3 ) * VERTEXBUFF);
	mesh->vertex_color = (int *)malloc(sizeof(int) * VERTEXBUFF);
	mesh->total_verticies = 0;
	
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
	mesh->object_dim.z = 0; //calculate z later based on max z height
	
	//mesh->total_verticies = ft_realloc(mesh->total_verticies, sizeof(p3) * VertexBuffer, sizeof(p3) * mesh->total_verticies);
	//mesh->vertex_color = ft_realloc(mesh->total_verticies, sizeof(int) * VertexBuffer, sizeof(int) * mesh->total_verticies);



	put_object_edge_data(mesh);
	ft_printf("test\n");
	mesh->edges[0].elem_a = 0;
	mesh->edges[0].elem_b = 1;
	mesh->edges[1].elem_a = 1;
	mesh->edges[1].elem_b = 2;
	mesh->edges[2].elem_a = 1;
	mesh->edges[2].elem_b = 19;
	mesh->total_edges =3;

	//print_object(mesh);
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