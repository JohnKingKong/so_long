/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:48:56 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/22 17:46:23 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

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

int	player_render(t_vars *vars, int x, int y)
{
	if (vars->player.looking_direction == UP && collision_wall(vars, UP)
		&& collision_keylock(vars, UP))
		move_up(vars, x, y);
	else if (vars->player.looking_direction == DOWN
		&& collision_wall(vars, DOWN) && collision_keylock(vars, DOWN))
		move_down(vars, x, y);
	else if (vars->player.looking_direction == LEFT
		&& collision_wall(vars, LEFT) && collision_keylock(vars, LEFT))
		move_left(vars, x, y);
	else if (vars->player.looking_direction == RIGHT
		&& collision_wall(vars, RIGHT) && collision_keylock(vars, RIGHT))
		move_right(vars, x, y);
	return (TRUE);
}

int	render_exit(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->exit.img, x, y);
	vars->chest.pos_chest_x = x;
	vars->chest.pos_chest_y = y;
	return (TRUE);
}

int	render_key(t_vars *vars, int x, int y)
{
	if (vars->key.on == FALSE)
	{
		vars->key.on = TRUE;
		render_floor(vars, x, y);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->key.img_key, x, y);
		vars->map.str[y / 32][x / 32] = 'K';
	}
	else if (vars->key.on == TRUE
		&& vars->map.str[y / 32][x / 32] == 'K')
	{
		render_floor(vars, x, y);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->key.img_key, x, y);
	}
	else
		render_collectibles(vars, x, y);
	return (TRUE);
}

// int	scores(t_vars *vars)
// {

// }