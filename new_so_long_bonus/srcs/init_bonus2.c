/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:07:40 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/19 11:54:20 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

void	init_all6(t_vars *vars, char *path, int width, int height)
{
	path = "./assets/background/wall2.xpm";
	vars->wall.img[1] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/wall3.xpm";
	vars->wall.img[2] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/wall4.xpm";
	vars->wall.img[3] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "assets/background/wall5.xpm";
	vars->wall.img[4] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "assets/background/wall6.xpm";
	vars->wall.img[5] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "assets/background/wall7.xpm";
	vars->wall.img[6] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "assets/background/wall8.xpm";
	vars->wall.img[7] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	init_all7(vars, path, width, height);
}

void	init_all7(t_vars *vars, char *path, int width, int height)
{
	path = "assets/others/box.xpm";
	vars->text.box_img = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "assets/others/nokey.xpm";
	vars->errorlog.nokey = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
}
