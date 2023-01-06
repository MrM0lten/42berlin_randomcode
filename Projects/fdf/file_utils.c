/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:42:47 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/06 19:42:48 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate_filetype(char *file, char *expected)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	return (ft_strncmp(&file[i], expected, 4));
}

int	ft_puterror(int fd, char *filename, char *err_mes)
{
	ft_putstr_fd("Error ", fd);
	ft_putstr_fd(filename, fd);
	ft_putstr_fd(err_mes, fd);
	return (0);
}

int	is_valid_file(char *filename)
{
	int	fd;

	if (!validate_filetype(filename, ".fdf"))
		return (ft_puterror(STDERR_FILENO, filename,
				" .File does not have the proper .fdf format"));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_puterror(STDERR_FILENO, filename, " .File does not exist"));
	close(fd);
	return (1);
}

t_object	*parse_fdf_file(int fd, t_object *mesh)
{
	char	*line;
	char	**splitline;
	int		split_elems;
	size_t	buff;

	buff = VERTEXBUFF;
	line = get_next_line(fd);
	while (line)
	{
		splitline = ft_split(line, ' ');
		split_elems = count_elems(splitline);
		if (split_elems > buff - mesh->total_verticies)
		{
			mesh->verticies = ft_realloc(mesh->verticies, sizeof(t_p3) * buff,
					sizeof(t_p3) * (buff * 2));
			buff *= 2;
		}
		put_object_vertex_data(mesh, splitline, split_elems);
		free_string_arr(splitline);
		free(line);
		line = get_next_line(fd);
		mesh->object_dim.y++;
	}
	mesh->object_dim.x = mesh->total_verticies / mesh->object_dim.y;
	mesh->verticies = ft_realloc(mesh->verticies, sizeof(t_p3) * buff,
			sizeof(t_p3) * mesh->total_verticies);
	put_object_edge_data(mesh);
	return (mesh);
}

void	free_string_arr(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = 0;
			i++;
		}
		free(arr);
	}
}
