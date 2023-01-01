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
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include "./libft/includes/get_next_line.h"
# include "./minilibx-linux/mlx.h"

# define ESC 65307
# define BACKSPACE 65288
# define W 119
# define A 97
# define S 115
# define D 100
# define NUM_PLUS 65451
# define NUM_MIN 65453



typedef struct	s_p3
{
	float x;
	float y;
	float z;
}				p3;

typedef struct	s_matrix
{
	float m[4][4];
}				mat4x4;

typedef struct	s_edge
{
	int elem_a;
	int elem_b;
}				edge;

typedef struct s_object
{
	p3 **verticies;
	edge **edges;
	int total_edges;
	int total_verticies;
}				object;

typedef struct  s_program
{
    void *mlx;
    void *win;
	void *img;
	object *obj;
	
}               t_prog;

//vector math
p3 p_add(p3 a, p3 b);
p3 p_sub(p3 a, p3 b);
double vector_len(p3 vec);

//Drawing utils
void drawline(t_prog *prog, p3 a, p3 b, int color);
void draw_object(object *obj, t_prog *prog,int color);
void draw(t_prog *prog,object *obj);

//debugging
void print_point(p3 *p);

mat4x4 generate_mat4x4(void);
void transform_object(object *obj,p3 pos);
void scale_object(object *obj, float factor);

p3 *generate_point(int x, int y, int z);

//projection
void	iso(float *x, float *y, float z);
p3 project(p3 p);

//error handling
void *ft_puterror(int fd,char * filename, char *err_mes);
int validate_filetype(char *file,char *expected);

//input
int handle_input(int keycode, void *param);

//object inits
object *init_object(char *filename);

#endif
