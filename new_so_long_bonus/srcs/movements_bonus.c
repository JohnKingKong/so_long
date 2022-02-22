/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/22 16:14:54 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	move_up(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i <= 32)
	{
		vars->player.pos_y = y - i;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player.img_up,
			vars->player.pos_x, vars->player.pos_y);
		render_floor(vars, x, y - i);
		i++;
	}
	check_collect(vars, x / 32, (y / 32) - 1);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player.img_up,
		vars->player.pos_x, vars->player.pos_y);
	render_floor(vars, x, y);
	vars->player.nb_moves++;
	print_moves(vars);
	return (TRUE);
}

int	move_down(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i <= 32)
	{
		vars->player.pos_y = y + i;
		player_load_asset(vars, vars->player.pos_x, vars->player.pos_y);
		render_floor(vars, x, y + i);
		i++;
	}
	check_collect(vars, x / 32, (y / 32) + 1);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player.img_down,
		vars->player.pos_x, vars->player.pos_y);
	render_floor(vars, x, y);
	vars->player.nb_moves++;
	print_moves(vars);
	return (TRUE);
}

int	move_left(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i <= 32)
	{
		vars->player.pos_x = x - i;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player.img_left,
			vars->player.pos_x, vars->player.pos_y);
		render_floor(vars, x - i, y);
		i++;
	}
	check_collect(vars, (x / 32) - 1, y / 32);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player.img_left,
		vars->player.pos_x, vars->player.pos_y);
	render_floor(vars, x, y);
	vars->player.nb_moves++;
	print_moves(vars);
	return (TRUE);
}

int	move_right(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i <= 32)
	{
		vars->player.pos_x = x + i;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_right, vars->player.pos_x, vars->player.pos_y);
		render_floor(vars, x + i, y);
		i++;
	}
	check_collect(vars, (x / 32) + 1, y / 32);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player.img_right,
		vars->player.pos_x, vars->player.pos_y);
	render_floor(vars, x, y);
	vars->player.nb_moves++;
	print_moves(vars);
	return (TRUE);
}

int	check_collect(t_vars *vars, int x, int y)
{
	if (vars->map.str[y][x] == 'C')
	{
		vars->key.collect_on_player++;
		vars->map.str[y][x] = '0';
	}
	if (vars->map.str[y][x] == 'K')
	{
		vars->key.collect_on_player++;
		vars->map.str[y][x] = '0';
		vars->player.has_key = TRUE;
	}
	return (TRUE);
}
