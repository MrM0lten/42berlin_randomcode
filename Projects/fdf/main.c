/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:22:19 by jisserst          #+#    #+#             */
/*   Updated: 2023/01/06 19:43:21 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_programm(void *param)
{
	t_prog	*prog;

	prog = param;
	mlx_loop_end(prog->mlx);
	printf("close prog was called\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_prog	*prog;

	if (av[1] == NULL || ac != 2 || !is_valid_file(av[1]))
	{
		ft_printf("test\n");
		return (0);
	}
	prog = malloc(sizeof(t_prog));
	if (!prog)
		return (0);
	prog->iso = 1;
	prog->obj = init_object(av[1]);
	if (prog->obj == NULL)
		return (shutdown_programm(prog));
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, X_SIZE, Y_SIZE, "FdF");
	prog->img.img = mlx_new_image(prog->mlx, X_SIZE, Y_SIZE);
	if (!prog->mlx || !prog->win || !prog->img.img)
		return (shutdown_programm(prog));
	mlx_hook(prog->win, 17, 0L, &close_programm, prog);
	mlx_key_hook(prog->win, &handle_input, prog);
	draw(prog, prog->obj);
	mlx_loop(prog->mlx);
	shutdown_programm(prog);
	return (0);
}

void	terminate(char *message)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit (0);
}

int	shutdown_programm(t_prog *prog)
{
	if (prog->img.img)
		mlx_destroy_image(prog->mlx, prog->img.img);
	if (prog->win)
		mlx_destroy_window(prog->mlx, prog->win);
	if (prog->mlx)
	{
		mlx_destroy_display(prog->mlx);
		free(prog->mlx);
	}
	if (prog->obj)
		free_object(prog->obj);
	free(prog);
	return (0);
}
