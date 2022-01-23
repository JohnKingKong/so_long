/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:45:03 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/23 11:01:09 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"

int	tile_wall(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./wall1.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (0);
}

int	render_exit(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./wall2.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (0);
}

int	render_player_right(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./player_right.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (0);
}

int	render_player_left(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./player_left.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (0);
}

int	render_player_up(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./player_up.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (0);
}

int	render_player_down(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./player_down.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (0);
}

int	collectible(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./key.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (TRUE);
}

int	render_chest(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./chest_close.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (TRUE);
}

int	open_chest(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./chest_open.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (TRUE);
}

