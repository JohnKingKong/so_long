/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:46:43 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/21 15:06:56 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"

int	player_right(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, 64, 64);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, vars->img.player_x, vars->img.player_y);
	vars->img.player_x = vars->img.player_x + 64;
	player(vars, vars->img.player_x, vars->img.player_y);
	return (0);
}

int	player_left(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, 64, 64);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, vars->img.player_x, vars->img.player_y);
	vars->img.player_x = vars->img.player_x - 64;
	player(vars, vars->img.player_x, vars->img.player_y);
	return (0);
}

int	player_up(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, 64, 64);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, vars->img.player_x, vars->img.player_y);
	vars->img.player_y = vars->img.player_y - 64;
	player(vars, vars->img.player_x, vars->img.player_y);
	return (0);
}

int	player_down(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, 64, 64);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, vars->img.player_x, vars->img.player_y);
	vars->img.player_y = vars->img.player_y + 64;
	player(vars, vars->img.player_x, vars->img.player_y);
	return (0);
}
