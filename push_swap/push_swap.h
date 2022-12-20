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
void visualize_state(t_prog *prog);

#endif