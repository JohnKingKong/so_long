/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/23 13:36:55 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"

/*int	handle_keypress(int keysum, t_vars *vars)
{
	if (keysum == kVK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		vars->mlx_win = NULL;
		exit(0);
	}
	if (keysum == kVK_RightArrow)
		player_right(vars);
	if (keysum == kVK_LeftArrow)
		player_left(vars);
	if (keysum == kVK_UpArrow)
		player_up(vars);
	if (keysum == kVK_DownArrow)
		player_down(vars);
	return (TRUE);
}*/

int	x_toclose(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	vars->mlx_win = NULL;
	exit (0);
	return (TRUE);
}

int	render(t_vars *vars, char **str, int y, int cnt)
{
	int	x;

	x = 0;
	while (str[cnt][x])
	{
		if (str[cnt][x] == 'P')
		{
			vars->img.player_x = x * 32;
			vars->img.player_y = y * 32;
			render_player_right(vars, vars->img.player_x, vars->img.player_y);
		}
		else if (str[cnt][x] == '1')
			tile_wall(vars, x * 32, y * 32);
		else if (str[cnt][x] == 'C' && vars->img.is_chest != 3)
		{
			collectible(vars, x * 32, y * 32);
			vars->img.is_chest++;
			vars->img.nb_keys = vars->img.nb_keys + 1;
		}
		else if (str[cnt][x] == 'C' && vars->img.is_chest == 3)
		{
			vars->img.is_chest++;
			vars->img.pos_chest_x = x;
			vars->img.pos_chest_y = y; 
			str[cnt][x] = '0';
			render_chest(vars, x * 32, y * 32);
		}
		else if (str[cnt][x] == 'E')
		{
			render_exit(vars, x * 32, y * 32);
			vars->img.exit_x = x * 32;
			vars->img.exit_y = y * 32;
		}
		x++;
	}
	return (TRUE);
}

int	read_map(t_vars *vars)
{
	int		cnt;
	int		map;
	int		y;

	cnt = 0;
	y = 0;
	map = open("./map.txt", O_RDONLY);
	if (map < 0)
		return (1);
	vars->img.str[cnt] = get_next_line(map);
	while (vars->img.str[cnt])
	{
		render(vars, vars->img.str, y, cnt);
		y++;
		cnt++;
		vars->img.str[cnt] = get_next_line(map);
	}
	return (TRUE);
}
