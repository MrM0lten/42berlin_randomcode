/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisserst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:22:19 by jisserst          #+#    #+#             */
/*   Updated: 2022/12/29 11:22:43 by jisserst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int test(int button, int x, int y,void *param)
{
	t_program *prog = param;
	//ft_printf("%i\n",x);
	mlx_pixel_put(prog->mlx,prog->win,x,y,0xfffafa);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_program prog;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "PogBrudi");

	    
    prog.mlx = mlx_ptr;
    prog.win = win_ptr;
	mlx_mouse_hook(win_ptr, &test, &prog);
	
	mlx_loop(mlx_ptr);
	return (0);
}
