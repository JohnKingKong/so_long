/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:45:03 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/21 14:52:41 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"

int	tile_wall(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./wall.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (0);
}

int	player(t_vars *vars, int x, int y)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./player.xpm";
	vars->img.img = mlx_xpm_file_to_image(vars->mlx, path,
			&img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->img.img, x, y);
	return (0);
}
