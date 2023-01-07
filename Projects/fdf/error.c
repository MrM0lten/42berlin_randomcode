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
