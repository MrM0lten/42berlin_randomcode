#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
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
	int sim_flag;
	int instr_count;
	t_stack *stack_a;
	t_stack *stack_b;

} t_prog;

typedef struct s_2dpoint
{
	int val_a;
	int val_b;

} t_2dpoint;

//debugging utils
void get_stack_info(t_stack *stack);
void get_state(t_prog *prog);
void print_arr(int *arr, int size);
void print2D_arr(t_2dpoint **arr);

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
void rot_to_smallest(t_prog *prog,t_stack *stack);
int find_pos_for_val(t_stack *stack, int elem_nbr);
t_2dpoint *get_best_elem(t_2dpoint **arr);
void rot_and_move(t_prog *prog,t_2dpoint *arr);
void brute_force(t_prog *prog);
void	move_unsorted(t_prog *prog, t_stack *lis);

//program & struct utils
size_t get_arg_count(int ac, char** av);
int *fill_arr(size_t size, char* str);
t_stack *generate_stack(int *values,size_t num, size_t stacksize);
t_prog *initprog(int ac, char**av);
void free_prog(t_prog *prog);
void free_stack(t_stack *stack);
t_2dpoint **generate_points_arr(t_prog *prog);
void free_points_arr(t_2dpoint **arr);

//lis utils
int		elem_in_lis(int val, t_stack *lis);
t_stack	*fill_lis_stack(t_prog *prog, int *lis, int lis_max);
int		get_max_lis(t_prog *prog, int *lis);
t_stack	*generate_lis(t_prog *prog);

//annoying
long int	special_atoi(const char *str);
int nextbiggest(int val,t_stack *stack);

//general utils
size_t ft_abs(int i);
int largest_from_zero(int a, int b);
int is_array_sorted(t_stack *stack_a);
int arr_sorted_needs_rot(t_stack *stack_a);
int smaller_elem_exists(t_stack *stack,int cmp_val);
int get_biggest_arr_elem(t_stack *stack);
int get_arr_elem_pos(t_stack *stack,int next_smallest);

//error Handling
void write_error(void);
int err_arr_is_unique(int *arr, int len);
int err_arr_is_all_num(char *str);

#endif