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

static void	check_buff(size_t *buff, int split_elems, t_object *mesh)
{
	if (split_elems > *buff - mesh->tot_verts)
	{
		mesh->verts = ft_realloc(mesh->verts, sizeof(t_p3) * (*buff),
				sizeof(t_p3) * (*buff * 2));
		if (!mesh->verts)
			terminate("vertex reallocation failed");
		*buff *= 2;
	}
}

static int	get_map_dim(char *line)
{
	char	**splitline;
	int		count;

	splitline = ft_split(line, ' ');
	count = count_elems(splitline);
	if (splitline[count - 1][0] == '\n')
		count--;
	free_string_arr(splitline);
	return (count);
}

static int	is_valid_line(char *line, char **splitline, int dim,
	int split_elems)
{
	if (splitline[split_elems - 1][0] == '\n')
		split_elems--;
	if (!line || !splitline || dim != split_elems)
	{
		free_string_arr(splitline);
		free(line);
		return (0);
	}
	return (1);
}

int	parse_fdf_file(int fd, t_object *m)
{
	char	*line;
	char	**splitline;
	int		split_elems;
	int		dim;
	size_t	buff;

	buff = VERTEXBUFF;
	line = get_next_line(fd);
	dim = get_map_dim(line);
	while (line)
	{
		splitline = ft_split(line, ' ');
		split_elems = count_elems(splitline);
		if (!is_valid_line(line, splitline, dim, split_elems))
			return (0);
		check_buff(&buff, split_elems, m);
		put_object_vertex_data(m, splitline, split_elems);
		free_string_arr(splitline);
		free(line);
		line = get_next_line(fd);
		m->dim.y++;
	}
	m->verts = ft_realloc(m->verts, sizeof(t_p3) * buff,
			sizeof(t_p3) * m->tot_verts);
	return (1);
}
