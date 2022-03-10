/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/10 16:35:31 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	check_elements(t_vars *vars)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (vars->map.str[y])
	{
		while (vars->map.str[y][x])
		{
			if (vars->map.str[y][x] == 'C')
				vars->key.collect_in_map++;
			else if (vars->map.str[y][x] == 'P')
				vars->init.ok_p++;
			else if (vars->map.str[y][x] == 'E' && vars->init.ok_e == FALSE)
				vars->init.ok_e = TRUE;
			else if (vars->map.str[y][x] == '1' || vars->map.str[y][x] == '0'
				|| vars->map.str[y][x] == '\n')
				vars->map.is_chest = 0;
			else
				vars->init.nono = TRUE;
			x++;
		}
		x = 0;
		y++;
	}
}

int	render_all(t_vars *vars, char **str, int cnt)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cnt)
	{
		while (str[y][x])
		{
			check_map_render(vars, str, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (TRUE);
}

int	check_borders(t_vars *vars)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (vars->map.str[0][x] != '\n')
	{
		if (vars->map.str[0][x - 1] != '1' ||
			vars->map.str[vars->map.cnt - 1][x - 1] != '1')
		{
			vars->errorlog.errorlog = "\nThe map isn't delimited by borders\n";
			return (FALSE);
		}
		x++;
	}
	while (y < vars->map.height / 32)
	{
		if (vars->map.str[y][0] != '1' || vars->map.str[y][x - 1] != '1')
		{
			vars->errorlog.errorlog = "\nThe map isn't delimited by borders\n";
			return (FALSE);
		}
		y++;
	}
	return (TRUE);
}

int	check_map_render(t_vars *vars, char **str, int x, int y)
{
	if (str[y][x] == '0')
		render_floor(vars, x * 32, y * 32);
	else if ((str[y][x] == '1' && ((vars->wall.walleye == 7)
			|| (vars->wall.walleye == 3) || vars->wall.walleye == 21)))
		render_walleye(vars, x * 32, y * 32);
	else if (str[y][x] == '1')
		render_wall(vars, x * 32, y * 32);
	else if (str[y][x] == 'C')
		render_collectibles(vars, x * 32, y * 32);
	else if (str[y][x] == 'E')
		render_chest(vars, x * 32, y * 32);
	else if (str[y][x] == 'P')
	{
		vars->player.looking_direction = RIGHT;
		player_load_asset(vars, x * 32, y * 32);
	}
	return (TRUE);
}

int	keep_confirming(t_vars *vars)
{
	if (vars->init.ok_p > 1)
	{
		vars->errorlog.errorlog
			= "\nToo many starting postions for the player in the map\n";
		return (FALSE);
	}
	else if (vars->init.ok_e == FALSE)
	{
		vars->errorlog.errorlog = "\nNo exit in the map\n";
		return (FALSE);
	}
	else if (vars->init.nono == TRUE)
	{
		vars->errorlog.errorlog = "\nThere is an unknows character in the map";
		return (FALSE);
	}
	return (TRUE);
}
