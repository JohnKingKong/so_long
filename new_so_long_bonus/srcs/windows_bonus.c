/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:13:42 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/22 10:59:32 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	print_moves(t_vars *vars)
{
	int		i;
	char	*num;

	i = 32;
	while (i <= 256)
	{
		render_floor(vars, i, 32);
		i = i + 32;
	}
	mlx_string_put(vars->mlx, vars->mlx_win, 40, 32, 0xFFBE149A,
		"Number Of Moves : ");
	num = ft_itoa(vars->player.nb_moves);
	mlx_string_put(vars->mlx, vars->mlx_win, 215, 32, 0xFFBE149A, num);
	free(num);
	return (TRUE);
}

int	print_box(t_vars *vars)
{
	if (vars->text.on_or_off == TRUE)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->text.box_img,
			vars->map.width / 3, vars->map.height / 3);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->errorlog.nokey,
		vars->map.width / 3 + 50, vars->map.height / 3 + 25);
	return (TRUE);
}

void	rdm_walls(t_vars *vars, int x, int y)
{
	vars->init.rdm = rand() % 50;
	if (vars->init.rdm > 7)
		vars->map.wall_nb[y][x] = 9;
	else if (vars->init.rdm == 7)
		vars->map.wall_nb[y][x] = 8;
	else
		vars->map.wall_nb[y][x] = vars->init.rdm + 1;
	vars->map.str[y][x] = vars->map.wall_nb[y][x] + 48;
	render_wall(vars, x * 32, y * 32);
}

int	render_collectibles(t_vars *vars, int x, int y)
{
	render_floor(vars, x, y);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->key.img[vars->key.num[0]], x, y);
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
	vars->map.str[y / 32][x / 32] = 'c';
	return (TRUE);
}
