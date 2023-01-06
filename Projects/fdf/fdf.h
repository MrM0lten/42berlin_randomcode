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
# define NUM1 65436
# define NUM2 65433
# define NUM3 65435
# define NUM4 65430
# define NUM5 65437
# define NUM6 65432
# define NUM7 65429
# define NUM8 65431
# define NUM9 65434

# define DEFAULTCOL 0xfffafa

#define Y_SIZE 1000
#define X_SIZE 1000
#define ASPECT_RATIO X_SIZE / Y_SIZE

#define VERTEXBUFF 1000
#define FDF_VERTEXDISTANCE 1


typedef struct	s_p3
{
	double x;
	double y;
	double z;
	int color;
}				p3;

typedef struct	s_p2
{
	int x;
	int y;
	int color;
}				p2;

typedef struct	s_edge
{
	int elem_a;
	int elem_b;
}				edge;

typedef struct s_object
{
	p3 *verticies;
	edge *edges;
	p3 object_dim;
	p3 rot;
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
void print_object(object *obj);

void transform_object(object *obj,p3 pos);
void scale_object(object *obj, p3 factor);

p3 *generate_point(int x, int y, int z); //allocated
p3 create_point(p3 *p); //non alocated
p3 make_point(double x,double y,double z);

//projection
p3 project(p3 p,t_prog *prog);
void iso(double *x, double *y, double z);
void rotate_x(double *y, double *z, double alpha);
void rotate_y(double *x, double *z, double beta);
void rotate_z(double *x, double *y, double gamma);

//error handling
int validate_filetype(char *file,char *expected);
void shutdown_programm(t_prog *prog);

//input
int handle_input(int keycode, void *param);

//Map Parsing
object *init_object(char *filename);
void free_object(object *obj);
void free_string_arr(char **arr);
void put_object_vertex_data(object *mesh, char **splitline, int split_elems);
void put_object_edge_data(object *obj);
void read_fdf_file(int fd);
int is_valid_file(char *filename);
object *parse_fdf_file(int fd, object *mesh);
int count_elems(char **str);

//general utility, use for libft later
void *ft_realloc(void *old, size_t old_size, size_t new_size);
int ft_puterror(int fd,char * filename, char *err_mes);
size_t	ft_poschr(const char *str, int c);
int ft_hextoi(char *str);
void put_pixel(img_data *data, int x, int y, int color);
void put_new_image(t_prog *prog, int x, int y);
int ft_abs(int x);
int ft_round(double nbr);

#endif
