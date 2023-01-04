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
# include "./libft/includes/array_utils.h"
# include "./minilibx-linux/mlx.h"

# define ESC 65307
# define BACKSPACE 65288
# define W 119
# define A 97
# define S 115
# define D 100
# define NUM_PLUS 65451
# define NUM_MIN 65453
# define NUMPOINT 65439
# define NUMZERO 65438
# define NUM4 65430
# define NUM8 65431
# define NUM6 65432
# define NUM2 65433

# define DEFAULTCOL 0xfffafa

#define Y_SIZE 1000
#define X_SIZE 1000
#define ASPECT_RATIO X_SIZE / Y_SIZE


typedef struct	s_p3
{
	float x;
	float y;
	float z;
}				p3;

typedef struct	s_edge
{
	int elem_a;
	int elem_b;
}				edge;

typedef struct s_object
{
	p3 *verticies;
	int *vertex_color;
	edge *edges;
	p3 object_dim;
	int total_edges;
	int total_verticies;
}				object;

typedef struct	s_imgdata {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				img_data;

typedef struct  s_program
{
    void *mlx;
    void *win;
	img_data img;
	object *obj;
	p3 rot;
}               t_prog;



//vector math
p3 p_add(p3 a, p3 b);
p3 p_sub(p3 a, p3 b);
double vector_len(p3 vec);

//Drawing utils
void drawline(t_prog *prog, p3 a, p3 b, int color);
void drawline2(t_prog *prog, p3 a, p3 b, int color);
void draw_object(object *obj, t_prog *prog,int color);
void draw(t_prog *prog,object *obj);

//debugging
void print_point(p3 *p);
void print_object(object *obj);

void transform_object(object *obj,p3 pos);
void scale_object(object *obj, p3 factor);

p3 *generate_point(int x, int y, int z);

//projection
void iso(float *x, float *y, float z);
p3 project(p3 p,t_prog *prog);
void rotate_x(float *y, float *z, float alpha);
void	rotate_y(float *x, float *z, float beta);
void	rotate_z(float *x, float *y, float gamma);

//error handling
void *ft_puterror(int fd,char * filename, char *err_mes);
int validate_filetype(char *file,char *expected);

//input
int handle_input(int keycode, void *param);

//Map Parsing
object *init_object(char *filename);

void free_string_arr(char **arr);
void put_object_vertex_data(object *mesh, char **splitline, int split_elems, int y);
void read_fdf_file(int fd);

//general utility, use for libft later
void *ft_realloc(void *old, size_t old_size, size_t new_size);
void *ft_puterror(int fd,char * filename, char *err_mes);
size_t	ft_poschr(const char *str, int c);
int ft_hextoi(char *str);
void put_pixel(img_data *data, int x, int y, int color);
void put_image(t_prog *prog, int x, int y);

#endif
