#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

typedef struct s_stack
{
	int *array;
	size_t size;
	size_t max_size;

} t_stack;

typedef struct s_prog
{
	t_stack *stack_a;
	t_stack *stack_b;

} t_prog;

typedef struct s_2Dpoint
{
	int val_a;
	int val_b;

} t_2Dpoint;

//debugging utils
void get_stack_info(t_stack *stack);
void get_state(t_prog *prog);
void print_arr(int *arr, int size);
void print2D_arr(t_2Dpoint **arr);

//instructions
void put_instruction(char *instruction, t_prog *prog);
void stack_swap(t_stack *stack);
void rot_stack(t_stack *stack);
void rvrs_rot_stack(t_stack *stack);
void push_stack(t_stack *from,t_stack *to);

//algo's
void run_sorting_algo(t_prog *prog);
void insert_algorithm(t_prog *prog);
int calc_smallest_rot(t_stack *stack, int elem);

//program & struct utils
t_stack *generate_stack(int *values,size_t num, size_t stacksize);
t_prog *initprog(int ac, char**av);
void free_prog(t_prog *prog);
void free_stack(t_stack *stack);
t_2Dpoint **generate_points_arr(t_prog *prog);
void free_points_arr(t_2Dpoint **arr);

//error Handling
void error_handler(char *message);
int err_arr_is_unique(int *arr, int len);

#endif