/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/15 19:25:18 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	handle_keypress_windows(int keysum, t_vars *vars)
{	
	int	cnt;

	cnt = 0;
	if (keysum == Escape)
	{
		while (vars->map.str[cnt])
		{
			free(vars->map.str[cnt]);
			cnt++;
		}
		free(vars->map.str);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		vars->mlx_win = NULL;
		exit(0);
	}
	if (keysum == key_d || keysum == key_a || keysum == key_s
		|| keysum == key_w)
		moves_key(keysum, vars);
	return (TRUE);
}

int	moves_key(int keysum, t_vars *vars)
{
	if (keysum == key_a)
		vars->player.looking_direction = LEFT;
	else if (keysum == key_d)
		vars->player.looking_direction = RIGHT;
	else if (keysum == key_w)
		vars->player.looking_direction = UP;
	else if (keysum == key_s)
		vars->player.looking_direction = DOWN;
	player_render(vars, vars->player.pos_x, vars->player.pos_y);
	return (TRUE);
}

int	x_to_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	vars->mlx_win = NULL;
	exit (0);
}

/*int	destroy_erthing(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->chest.img);
	mlx_destroy_image(vars->mlx, vars->wall.img[0]);
	mlx_destroy_image(vars->mlx, vars->wall.img[1]);
	mlx_destroy_image(vars->mlx, vars->wall.img[2]);
	mlx_destroy_image(vars->mlx, vars->wall.img[3]);
	mlx_destroy_image(vars->mlx, vars->wall.img[4]);
	mlx_destroy_image(vars->mlx, vars->wall.img[5]);
	mlx_destroy_image(vars->mlx, vars->wall.img[6]);
	mlx_destroy_image(vars->mlx, vars->wall.img[7]);
	mlx_destroy_image(vars->mlx, vars->floor.img);
	mlx_destroy_image(vars->mlx, vars->key.img_1);
	mlx_destroy_image(vars->mlx, vars->key.img_2);
	mlx_destroy_image(vars->mlx, vars->key.img_3);
	mlx_destroy_image(vars->mlx, vars->key.img_4);
	mlx_destroy_image(vars->mlx, vars->key.img_5);
	mlx_destroy_image(vars->mlx, vars->key.img_6);
	mlx_destroy_image(vars->mlx, vars->player.img_up[0]);
	mlx_destroy_image(vars->mlx, vars->player.img_up[1]);
	mlx_destroy_image(vars->mlx, vars->player.img_up[2]);
	mlx_destroy_image(vars->mlx, vars->player.img_up[3]);
	mlx_destroy_image(vars->mlx, vars->player.img_down[0]);
	mlx_destroy_image(vars->mlx, vars->player.img_down[1]);
	mlx_destroy_image(vars->mlx, vars->player.img_down[2]);
	mlx_destroy_image(vars->mlx, vars->player.img_down[3]);
	mlx_destroy_image(vars->mlx, vars->player.img_left[0]);
	mlx_destroy_image(vars->mlx, vars->player.img_left[1]);
	mlx_destroy_image(vars->mlx, vars->player.img_left[2]);
	mlx_destroy_image(vars->mlx, vars->player.img_left[3]);
	mlx_destroy_image(vars->mlx, vars->player.img_right[0]);
	mlx_destroy_image(vars->mlx, vars->player.img_right[1]);
	mlx_destroy_image(vars->mlx, vars->player.img_right[2]);
	mlx_destroy_image(vars->mlx, vars->player.img_right[3]);
	mlx_destroy_image(vars->mlx, vars->wall.alt_img[0]);
	mlx_destroy_image(vars->mlx, vars->wall.alt_img[1]);
	mlx_destroy_image(vars->mlx, vars->wall.alt_img[2]);
	mlx_destroy_image(vars->mlx, vars->wall.alt_img[3]);
	mlx_destroy_image(vars->mlx, vars->wall.alt_img[4]);
	mlx_destroy_image(vars->mlx, vars->wall.alt_img[5]);
	mlx_destroy_image(vars->mlx, vars->wall.alt_img[6]);
	mlx_destroy_image(vars->mlx, vars->wall.alt_img[7]);
	mlx_destroy_image(vars->mlx, vars->wall.alt_img[8]);
	return (TRUE);
}*/