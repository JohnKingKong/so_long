/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/19 12:36:45 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	render_floor(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor.img, x, y);
	return (TRUE);
}

void	render_walleye(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->wall.alt_img[vars->wall.num - 1], x, y);
	vars->map.str[y / 32][x / 32] = 'Y';
}

void	render_wall(t_vars *vars, int x, int y)
{
	if (vars->map.wall_nb[y / 32][x / 32] == 9)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.img[0], x, y);
	else if (vars->map.wall_nb[y / 32][x / 32] == 8)
		render_walleye(vars, x, y);
	else
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wall.img
		[vars->map.wall_nb[y / 32][x / 32]], x, y);
}

void	put_img_player(t_vars *vars, int x, int y)
{
	if (vars->player.looking_direction == RIGHT)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_right[vars->player.num - 1], x, y);
	else if (vars->player.looking_direction == LEFT)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_left[vars->player.num - 1], x, y);
	else if (vars->player.looking_direction == UP)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_up[vars->player.num - 1], x, y);
	else if (vars->player.looking_direction == DOWN)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_down[vars->player.num - 1], x, y);
}

int	player_load_asset(t_vars *vars, int x, int y)
{
	vars->player.pos_x = x;
	vars->player.pos_y = y;
	render_floor(vars, x, y);
	put_img_player(vars, x, y);
	return (TRUE);
}
