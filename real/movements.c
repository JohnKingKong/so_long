/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:46:43 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/22 16:24:42 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"

int	player_right(t_vars *vars)
{
	if (collision_wall_right(vars) == FALSE && collision_chest_right(vars) == FALSE)
	{
		/*if (vars->img.has_key == TRUE && collect_it(vars) == TRUE)
		{
			vars->img.player_x = vars->img.player_x + 32;
			render_player_right(vars, vars->img.player_x, vars->img.player_y);
		}*/
		 //else
		{
			vars->img.img = mlx_new_image(vars->mlx, 32, 32);
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->img.img, vars->img.player_x, vars->img.player_y);
			vars->img.player_x = vars->img.player_x + 32;
			render_player_right(vars, vars->img.player_x, vars->img.player_y);
		}
		collect_it(vars);
	}
	return (0);
}

int	player_left(t_vars *vars)
{
	if (collision_wall_left(vars) == FALSE && collision_chest_left(vars) == FALSE)
	{
		chest(vars);
		vars->img.img = mlx_new_image(vars->mlx, 32, 32);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->img.img, vars->img.player_x, vars->img.player_y);
		vars->img.player_x = vars->img.player_x - 32;
		render_player_left(vars, vars->img.player_x, vars->img.player_y);
		collect_it(vars);
	}
	return (0);
}

int	player_up(t_vars *vars)
{
	if (collision_wall_up(vars) == FALSE && collision_chest_up(vars) == FALSE)
	{
		chest(vars);
		vars->img.img = mlx_new_image(vars->mlx, 32, 32);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->img.img, vars->img.player_x, vars->img.player_y);
		vars->img.player_y = vars->img.player_y - 32;
		render_player_up(vars, vars->img.player_x, vars->img.player_y);
		collect_it(vars);
	}
	return (0);
}

int	player_down(t_vars *vars)
{
	if (collision_wall_down(vars) == FALSE && collision_chest_down(vars) == FALSE)
	{
		chest(vars);
		vars->img.img = mlx_new_image(vars->mlx, 32, 32);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->img.img, vars->img.player_x, vars->img.player_y);
		vars->img.player_y = vars->img.player_y + 32;
		render_player_down(vars, vars->img.player_x, vars->img.player_y);
		collect_it(vars);
	}
	return (0);
}
