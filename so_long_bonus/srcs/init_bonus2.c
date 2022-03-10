/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:07:40 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/10 15:23:36 by jvigneau         ###   ########.fr       */
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
	vars->text.box_txt = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "assets/collectibles/key.xpm";
	vars->key.img_key = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "assets/others/coins.xpm";
	vars->text.coins_txt = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
}

int	keep_confirming(t_vars *vars)
{
	if (vars->init.ok_p > 1)
	{
		vars->errorlog.errorlog
			= "Too many starting postions for the player in the map\n";
		return (FALSE);
	}
	if (vars->init.ok_e <= 0)
	{
		vars->errorlog.errorlog = "No exit in the map\n";
		return (FALSE);
	}
	if (vars->init.ok_e > 1)
	{
		vars->errorlog.errorlog = "Too many exits in the map!\n";
		return (FALSE);
	}
	if (vars->init.nono == TRUE)
	{
		vars->errorlog.errorlog
			= "There's an unknown character in the map file";
		return (FALSE);
	}
	return (TRUE);
}
