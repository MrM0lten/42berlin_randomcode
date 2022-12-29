/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:33:57 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 20:33:59 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instruction_helper(char *instruction, t_prog *prog);

void	put_instruction(char *instruction, t_prog *prog)
{
	if (!ft_strncmp(instruction, "sa", 3))
		stack_swap(prog->stack_a);
	if (!ft_strncmp(instruction, "sb", 3))
		stack_swap(prog->stack_b);
	if (!ft_strncmp(instruction, "ss", 3))
	{
		stack_swap(prog->stack_a);
		stack_swap(prog->stack_b);
	}
	if (!ft_strncmp(instruction, "ra", 3))
		rot_stack(prog->stack_a);
	if (!ft_strncmp(instruction, "rb", 3))
		rot_stack(prog->stack_b);
	instruction_helper(instruction, prog);
	prog->instr_count++;
	if (prog->sim_flag == 0)
		ft_printf("%s\n", instruction);
}

static void	instruction_helper(char *instruction, t_prog *prog)
{
	if (!ft_strncmp(instruction, "rr", 3))
	{
		rot_stack(prog->stack_a);
		rot_stack(prog->stack_b);
	}
	if (!ft_strncmp(instruction, "pa", 3))
		push_stack(prog->stack_b, prog->stack_a);
	if (!ft_strncmp(instruction, "pb", 3))
		push_stack(prog->stack_a, prog->stack_b);
	if (!ft_strncmp(instruction, "rra", 3))
		rvrs_rot_stack(prog->stack_a);
	if (!ft_strncmp(instruction, "rrb", 3))
		rvrs_rot_stack(prog->stack_b);
	if (!ft_strncmp(instruction, "rrr", 3))
	{
		rvrs_rot_stack(prog->stack_a);
		rvrs_rot_stack(prog->stack_b);
	}
}
