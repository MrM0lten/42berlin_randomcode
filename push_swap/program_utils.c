/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:35:12 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/25 20:45:52 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_prog	*initprog(int ac, char**av)
{
	t_prog	*prog;
	int		*stack_a_vals;
	int		*stack_b_vals;
	size_t	stacksize;

	stacksize = get_arg_count(ac, av);
	prog = (t_prog *)malloc(sizeof(t_prog));
	if (!prog)
		return (NULL);
	stack_a_vals = fill_arr(stacksize, av[1]);
	prog->instr_count = 0;
	prog->sim_flag = 0;
	if (!stack_a_vals || !err_arr_is_unique(stack_a_vals, stacksize))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (NULL);
	}
	stack_b_vals = init_zerod_arr(stacksize);
	prog->stack_a = generate_stack(stack_a_vals, stacksize, stacksize);
	prog->stack_b = generate_stack(stack_b_vals, 0, stacksize);
	if (!stack_a_vals || !(prog->stack_a) || !(prog->stack_b))
		return (NULL);
	return (prog);
}

int	*init_zerod_arr(size_t	stacksize)
{
	size_t	i;
	int		*arr;

	i = 0;
	arr = (int *)malloc(stacksize * sizeof(int));
	while (i < stacksize)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

size_t	get_arg_count(int ac, char **av)
{
	size_t	arg_count;
	size_t	word_flag;
	int		i;

	(void)ac;
	arg_count = 0;
	i = 0;
	word_flag = 0;
	while (av[1][i])
	{
		if (av[1][i] != ' ' && word_flag == 0)
		{
			word_flag = 1;
			arg_count++;
		}
		else if (av[1][i] == ' ')
			word_flag = 0;
		i++;
	}
	return (arg_count);
}

int	*fill_arr(size_t size, char *str)
{
	int			*arr;
	int			i;
	size_t		cnt;
	long int	temp;

	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	cnt = 0;
	while (cnt < size)
	{
		while (str[i] == ' ')
			i++;
		temp = special_atoi(&str[i]);
		if ((temp < 0 && temp < INT_MIN) || (temp >= 0 && temp > INT_MAX))
		{
			free(arr);
			return (NULL);
		}
		arr[cnt++] = (int)temp;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	return (arr);
}

long int	special_atoi(const char *str)
{
	long int	total;
	int			flag;
	int			found;

	total = 0;
	flag = 1;
	found = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			total = total * 10 + *str - '0';
		else
			found = 0;
		str++;
	}
	return (flag * total);
}
