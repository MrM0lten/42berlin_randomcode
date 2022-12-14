/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:15:05 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/07 17:15:06 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	transform_obj(t_object *obj, t_p3 *pos)
{
	pos->x += obj->pos.x;
	pos->y += obj->pos.y;
	pos->z += obj->pos.z;
}

void	scale_obj(t_object *obj, t_p3 *p)
{
	p->x *= obj->scale.x;
	p->y *= obj->scale.y;
	p->z *= obj->scale.z;
}
