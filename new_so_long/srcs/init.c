/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:44:01 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/24 10:56:34 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	init_all(t_vars *vars)
{
	char	*path;
	int		width;
	int		height;

	path = "./assets/collectibles/chest_close.xpm";
	vars->chest.img = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/wall.xpm";
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/floor.xpm";
	vars->floor.img = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/collectibles/coin_1.xpm";
	vars->key.img[0] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/collectibles/coin_2.xpm";
	vars->key.img[1] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	init_all2(vars, path, width, height);
	return (TRUE);
}

void	init_all2(t_vars *vars, char *path, int width, int height)
{
	path = "./assets/collectibles/coin_3.xpm";
	vars->key.img[2] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/collectibles/coin_4.xpm";
	vars->key.img[3] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/collectibles/coin_5.xpm";
	vars->key.img[4] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/collectibles/coin_6.xpm";
	vars->key.img[5] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_up1.xpm";
	vars->player.img_up[0] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_up2.xpm";
	vars->player.img_up[1] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_up3.xpm";
	vars->player.img_up[2] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_up4.xpm";
	vars->player.img_up[3] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	init_all3(vars, path, width, height);
}

void	init_all3(t_vars *vars, char *path, int width, int height)
{
	path = "./assets/player/player_down1.xpm";
	vars->player.img_down[0] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_down2.xpm";
	vars->player.img_down[1] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_down3.xpm";
	vars->player.img_down[2] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_down4.xpm";
	vars->player.img_down[3] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_left1.xpm";
	vars->player.img_left[0] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_left2.xpm";
	vars->player.img_left[1] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_left3.xpm";
	vars->player.img_left[2] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_left4.xpm";
	vars->player.img_left[3] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	init_all4(vars, path, width, height);
}

void	init_all4(t_vars *vars, char *path, int width, int height)
{
	path = "./assets/player/player_right1.xpm";
	vars->player.img_right[0] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_right2.xpm";
	vars->player.img_right[1] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_right3.xpm";
	vars->player.img_right[2] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/player/player_right4.xpm";
	vars->player.img_right[3] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/walleye1.xpm";
	vars->wall.alt_img[0] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/walleye1.xpm";
	vars->wall.alt_img[1] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/walleye1.xpm";
	vars->wall.alt_img[2] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/walleye1.xpm";
	vars->wall.alt_img[3] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	init_all5(vars, path, width, height);
}

void	init_all5(t_vars *vars, char *path, int width, int height)
{
	path = "./assets/background/walleye2.xpm";
	vars->wall.alt_img[4] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/walleye3.xpm";
	vars->wall.alt_img[5] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/walleye3.xpm";
	vars->wall.alt_img[6] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/walleye4.xpm";
	vars->wall.alt_img[7] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
	path = "./assets/background/walleye4.xpm";
	vars->wall.alt_img[8] = mlx_xpm_file_to_image(vars->mlx, path,
			&width, &height);
}
