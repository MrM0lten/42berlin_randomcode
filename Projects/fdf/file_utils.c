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

int	is_valid_file(char *filename)
{
	int	fd;

	if (!validate_filetype(filename, ".fdf"))
		terminate("File does not have the proper .fdf format");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		terminate("File does not exist");
	close(fd);
	return (1);
}

static void	check_buff(size_t *buff, int split_elems, t_object * mesh)
{
	if (split_elems > *buff - mesh->tot_verts)
	{
		mesh->verts = ft_realloc(mesh->verts, sizeof(t_p3) * (*buff),
				sizeof(t_p3) * (*buff * 2));
		if(!mesh->verts)
			terminate("vertex reallocation failed");
		*buff *= 2;
	}
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
		check_buff(&buff, split_elems, mesh);
		put_object_vertex_data(mesh, splitline, split_elems);
		free_string_arr(splitline);
		free(line);
		line = get_next_line(fd);
		mesh->dim.y++;
	}
	mesh->dim.x = mesh->tot_verts / mesh->dim.y;
	mesh->verts = ft_realloc(mesh->verts, sizeof(t_p3) * buff,
			sizeof(t_p3) * mesh->tot_verts);
	put_object_edge_data(mesh);
	if(!mesh->verts || !mesh->edges)
		return (NULL);
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
