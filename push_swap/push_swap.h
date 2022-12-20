#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
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

//debugging utils
void get_stack_info(t_stack *stack);
void get_state(t_prog *prog);

//instructions
void manage_instruction(char *instruction, t_prog *prog);
void stack_swap(t_stack *stack);
void rot_stack(t_stack *stack);
void rvrs_rot_stack(t_stack *stack);
void push_stack(t_stack *from,t_stack *to);
void run_sorting_algo(t_prog *prog);

#endif