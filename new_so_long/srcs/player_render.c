/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:48:56 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/14 15:49:41 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	put_img_player_right(t_vars *vars, int x, int y)
{
	if (vars->player.num == 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_right[0], x, y);
	if (vars->player.num == 2)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_right[1], x, y);
	if (vars->player.num == 3)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_right[2], x, y);
	if (vars->player.num == 4)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_right[3], x, y);
}

void	put_img_player_left(t_vars *vars, int x, int y)
{
	if (vars->player.num == 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_left[0], x, y);
	if (vars->player.num == 2)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_left[1], x, y);
	if (vars->player.num == 3)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_left[2], x, y);
	if (vars->player.num == 4)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_left[3], x, y);
}

void	put_img_player_up(t_vars *vars, int x, int y)
{
	if (vars->player.num == 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_up[0], x, y);
	if (vars->player.num == 2)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_up[1], x, y);
	if (vars->player.num == 3)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_up[2], x, y);
	if (vars->player.num == 4)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_up[3], x, y);
}

void	put_img_player_down(t_vars *vars, int x, int y)
{
	if (vars->player.num == 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_down[0], x, y);
	if (vars->player.num == 2)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_down[1], x, y);
	if (vars->player.num == 3)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_down[0], x, y);
	if (vars->player.num == 4)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->player.img_down[3], x, y);
}

int	player_load_asset(t_vars *vars, int x, int y)
{
	vars->player.pos_x = x;
	vars->player.pos_y = y;
	render_floor(vars, x, y);
	if (vars->player.looking_direction == RIGHT)
		put_img_player_right(vars, x, y);
	else if (vars->player.looking_direction == LEFT)
		put_img_player_left(vars, x, y);
	else if (vars->player.looking_direction == UP)
		put_img_player_up(vars, x, y);
	else if (vars->player.looking_direction == DOWN)
		put_img_player_down(vars, x, y);
	return (TRUE);
}
