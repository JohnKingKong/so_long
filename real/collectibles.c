/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:49:38 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/22 16:07:52 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"
#include <stdio.h>

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

int	collect_it(t_vars *vars)
{
	if (vars->img.str[(vars->img.player_y / 32)]
		[(vars->img.player_x / 32)] == 'C')
	{
		vars->img.has_key = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

int	chest(t_vars *vars)
{
	if (vars->img.str[(vars->img.player_y / 32)][(vars->img.player_x / 32)] == 'Y')
		return (TRUE);
	return (FALSE);
}