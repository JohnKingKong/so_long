/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  windows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:54 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/23 13:54:48 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	destroy_erthing(t_vars *vars)
{
	int	cnt;

	mlx_destroy_image(vars->mlx, vars->chest.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->floor.img);
	cnt = 6;
	while (cnt-- > 1)
		mlx_destroy_image(vars->mlx, vars->key.img[cnt]);
	cnt = 4;
	while (cnt-- > 0)
	{
		mlx_destroy_image(vars->mlx, vars->player.img_up[cnt]);
		mlx_destroy_image(vars->mlx, vars->player.img_down[cnt]);
		mlx_destroy_image(vars->mlx, vars->player.img_left[cnt]);
		mlx_destroy_image(vars->mlx, vars->player.img_right[cnt]);
	}
	cnt = 8;
	while (cnt-- > 0)
		mlx_destroy_image(vars->mlx, vars->wall.alt_img[cnt]);
}

int	animation_coin(t_vars *vars)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	timer(vars);
	while (y < vars->map.cnt)
	{
		while (vars->map.str[y][x])
		{
			if (vars->map.str[y][x] == 'C')
				render_collectibles(vars, x * 32, y * 32);
			if (y == vars->player.pos_y / 32 && x == vars->player.pos_x / 32)
				player_load_asset(vars, x * 32, y * 32);
			if (vars->map.str[y][x] == 'Y')
				render_walleye(vars, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
	return (TRUE);
}
