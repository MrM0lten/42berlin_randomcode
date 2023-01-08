/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:00:11 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/08 14:00:12 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	validate_filetype(char *file, char *expected)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (!ft_strncmp(&file[i], expected, 50))
		return (1);
	return (0);
}
