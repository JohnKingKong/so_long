/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cinematics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/14 16:31:37 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

/*int render_cinematic(t_vars *vars)
{
	char	*path;
	int width;
	int height;

	path = "./assets/cinematics/cinematic_1.xpm";
	vars->cine.img = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->cine.img, 0, 0);
	printf("%s\n", path);
	
	return (TRUE);
}*/

int	timer(t_vars *vars)
{
	if (++vars->key.animation_coin > 10 || vars->key.animation_coin < 0)
	{
		vars->key.num[0] = vars->key.num[0] + 1;
		if (vars->key.num[0] > '6')
			vars->key.num[0] = '1';
		vars->key.animation_coin = 0;
	}
	if (++vars->player.animation > 19 || vars->player.animation < 0)
	{
		vars->player.num = vars->player.num + 1;
		if (vars->player.num > 4)
			vars->player.num = 1;
		vars->player.animation = 0;
	}
	if (++vars->wall.animation > 40 || vars->wall.animation < 0)
	{
		vars->wall.num = vars->wall.num + 1;
		if (vars->wall.num > 8)
			vars->wall.num = 1;
		vars->wall.animation = 0;
	}
	return (TRUE);
}

int	animation_coin(t_vars *vars)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	timer(vars);
	while (y < vars->map.cnt)
	{
		while (vars->map.str[y][x])
		{
			if (vars->map.str[y][x] == 'C')
				render_collectibles(vars, x * 32, y * 32);
			if (y == vars->player.pos_y / 32 && x == vars->player.pos_x / 32)
				player_load_asset(vars, x * 32, y * 32);
			if (vars->map.str[y][x] == 'Y')
				render_walleye(vars, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
	return (TRUE);
}
// int	init_erthing(t_vars *vars)