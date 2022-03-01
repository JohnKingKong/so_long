/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:48:56 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/24 11:20:17 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	player_load_asset(t_vars *vars, int x, int y)
{
	vars->player.pos_x = x;
	vars->player.pos_y = y;
	render_floor(vars, x, y);
	put_img_player(vars, x, y);
	return (TRUE);
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
