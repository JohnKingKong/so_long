/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/15 19:22:11 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	render_floor(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floor.img, x, y);
	return (TRUE);
}

int	render_walleye(t_vars *vars, int x, int y)
{
	if (vars->wall.num == 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.alt_img[0], x, y);
	else if (vars->wall.num == 2)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.alt_img[1], x, y);
	else if (vars->wall.num == 3)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.alt_img[2], x, y);
	else if (vars->wall.num == 4)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.alt_img[3], x, y);
	else if (vars->wall.num == 5)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.alt_img[4], x, y);
	else if (vars->wall.num == 6)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.alt_img[5], x, y);
	else if (vars->wall.num == 7)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.alt_img[6], x, y);
	else if (vars->wall.num == 8)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.alt_img[7], x, y);
	else if (vars->wall.num == 9)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.alt_img[8], x, y);
	vars->map.str[y / 32][x / 32] = 'Y';
	return (TRUE);
}

int	render_wall(t_vars *vars, int x, int y)
{
	vars->init.rdm = rand() % 50;
	if (vars->init.rdm > 7)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.img[0], x, y);
	else if (vars->init.rdm == 0)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.img[1], x, y);
	else if (vars->init.rdm == 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.img[2], x, y);
	else if (vars->init.rdm == 2)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.img[3], x, y);
	else if (vars->init.rdm == 3)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.img[4], x, y);
	else if (vars->init.rdm == 4)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.img[5], x, y);
	else if (vars->init.rdm == 5)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.img[6], x, y);
	else if (vars->init.rdm == 6)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->wall.img[7], x, y);
	else if (vars->init.rdm == 7)
		render_walleye(vars, x, y);
	return (TRUE);
}

int	render_collectibles(t_vars *vars, int x, int y)
{
	render_floor(vars, x, y);
	if (vars->key.num[0] == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->key.img_1, x, y);
	else if (vars->key.num[0] == '2')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->key.img_2, x, y);
	else if (vars->key.num[0] == '3')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->key.img_3, x, y);
	else if (vars->key.num[0] == '4')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->key.img_4, x, y);
	else if (vars->key.num[0] == '5')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->key.img_5, x, y);
	else if (vars->key.num[0] == '6')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->key.img_6, x, y);
	vars->chest.for_chest++;
	vars->key.keys_in_map = vars->key.keys_in_map + 1;
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
