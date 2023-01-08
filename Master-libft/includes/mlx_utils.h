/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:41:06 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/05 13:32:40 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <math.h>

typedef struct s_p3
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_p3;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imgdata;

double	vector_len(t_p3 vec);
t_p3	p_add(t_p3 a, t_p3 b);
t_p3	p_sub(t_p3 a, t_p3 b);
t_p3	make_point(double x, double y, double z);

void	put_pixel(t_imgdata *data, int x, int y, int color);
#endif