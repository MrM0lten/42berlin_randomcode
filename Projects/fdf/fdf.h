/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:19:43 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 20:24:51 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include <math.h>
# include <stdio.h>

# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include "./minilibx-linux/mlx.h"


typedef struct  s_program
{
    void *mlx;
    void *win;
}               t_prog;

typedef struct	s_p3
{
	int x;
	int y;
	int z;
}				p3;

//vector math
p3 *p_add(p3 *a, p3 *b);
p3 *p_sub(p3 *a, p3 *b);
double vector_len(p3 *vec);

//Drawing utils
void drawline(void *mlx_ptr, void *win_ptr, p3 *a, p3 *b, int color);

//debugging
void print_point(p3 *p);


#endif
