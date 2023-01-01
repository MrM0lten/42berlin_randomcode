#include "fdf.h"

object *init_object(char *filename)
{
	int fd;
	char *line;
	char **splitline;

	if(!validate_filetype(filename,".fdf"))
		return (ft_puterror(STDERR_FILENO,filename," .File does not have the proper .fdf format"));
	fd = open(filename,O_RDONLY);
	if(fd == -1)
		return (ft_puterror(STDERR_FILENO,filename," .File does not exist"));
	printf("yay");

	line = get_next_line(fd);
	while(line)
	{
		splitline = ft_split(line, ' ');
		free_string_arr(splitline);
		free(line);
	}
	return (NULL);
}

int validate_filetype(char *file,char *expected)
{
	int i;

	i = 0;
	while(file[i] && file[i] != '.')
		i++;
	
	return (!ft_strncmp(&file[i],expected, 4));
}

void *ft_puterror(int fd,char * filename, char *err_mes)
{
	ft_putstr_fd("Error\n",fd);
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
	int i;

	i = -1;
	if(obj)
	{
		if(obj->edges)
		{
			while(++i < obj->total_edges)
				free(obj->edges[i]);
			free(obj->edges);
		}
		if(obj->verticies)
		{
			i = -1;
			while(++i < obj->total_verticies)
				free(obj->verticies[i]);
			free(obj->verticies);
		}
		free(obj);
	}
}