/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/24 11:01:19 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	render_floor(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor.img, x, y);
	return (TRUE);
}

int	render_walleye(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->wall.alt_img[vars->wall.num - 1], x, y);
	vars->map.str[y / 32][x / 32] = 'Y';
	vars->wall.walleye++;
	return (TRUE);
}

int	render_wall(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wall.img, x, y);
	vars->wall.walleye++;
	return (TRUE);
}

int	render_collectibles(t_vars *vars, int x, int y)
{
	render_floor(vars, x, y);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->key.img[vars->key.num - 1], x, y);
	vars->chest.for_chest++;
	return (TRUE);
}

int	render_chest(t_vars *vars, int x, int y)
{
	render_floor(vars, x, y);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->chest.img, x, y);
	vars->chest.for_chest++;
	vars->chest.pos_chest_x = x;
	vars->chest.pos_chest_y = y;
	vars->map.str[y / 32][x / 32] = '0';
	return (TRUE);
}
