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

# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include "./minilibx-linux/mlx.h"

typedef struct  s_program
{
    void *mlx;
    void *win;
}               t_program;


#endif
