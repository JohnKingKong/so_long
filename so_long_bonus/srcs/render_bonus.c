/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/24 16:56:41 by jvigneau         ###   ########.fr       */
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

int	render_all(t_vars *vars, char **str, int cnt)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cnt)
	{
		while (str[y][x])
		{
			check_map_render(vars, str, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (TRUE);
}
