/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/19 12:05:17 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	malloc_map(t_vars *vars)
{
	vars->map.str = malloc(sizeof(t_vars) * 1000);
	if (!vars->map.str)
		return (FALSE);
	if (!vars->map.str[vars->map.cnt])
		return (FALSE);
	return (TRUE);
}

int	read_map(t_vars *vars)
{
	int	map;

	vars->map.cnt = 0;
	malloc_map(vars);
	map = open(vars->map.path, O_RDONLY);
	if (map < 0)
		return (1);
	vars->map.str[vars->map.cnt] = get_next_line(map);
	vars->map.width = (ft_strlen(vars->map.str[vars->map.cnt]) - 2) * 32;
	while (vars->map.str[vars->map.cnt])
	{
		vars->map.cnt++;
		vars->map.str[vars->map.cnt] = get_next_line(map);
	}
	vars->map.height = vars->map.cnt * 32;
	if (map_validity(vars) == TRUE)
	{
		vars->mlx_win = mlx_new_window(vars->mlx, vars->map.width,
				vars->map.height, "So long!");
		if (vars->mlx_win == NULL)
			return (FALSE);
		render_all(vars, vars->map.str, vars->map.cnt);
		return (TRUE);
	}
	return (FALSE);
}

int	map_validity(t_vars *vars)
{
	if (check_borders(vars) == FALSE)
		return (FALSE);
	if (vars->map.width == vars->map.height)
	{
		vars->errorlog.errorlog = "The map must be a rectangle!";
		return (FALSE);
	}
	if (confirm_elements(vars) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	confirm_elements(t_vars *vars)
{
	check_elements(vars);
	if (vars->key.collect_in_map == 0)
	{
		vars->errorlog.errorlog = "No Collectibles in the map\n";
		return (FALSE);
	}
	else if (vars->init.ok_p <= 0)
	{
		vars->errorlog.errorlog
			= "No starting position for the player in the map\n";
		return (FALSE);
	}
	else if (vars->init.ok_p > 1)
	{
		vars->errorlog.errorlog
			= "Too many starting postions for the player in the map\n";
		return (FALSE);
	}
	else if (vars->init.ok_e == FALSE)
	{
		vars->errorlog.errorlog = "No exit in the map\n";
		return (FALSE);
	}
	return (TRUE);
}

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
			vars->errorlog.errorlog = "The map isn't delimited by borders";
			return (FALSE);
		}
		x++;
	}
	while (y < vars->map.height / 32)
	{
		if (vars->map.str[y][0] != '1' || vars->map.str[y][x - 2] != '1')
		{
			vars->errorlog.errorlog = "The map isn't delimited by borders";
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
	else if (str[y][x] == 'C' && vars->chest.for_chest != 3)
		render_collectibles(vars, x * 32, y * 32);
	else if (str[y][x] == 'C' && vars->chest.for_chest == 3)
		render_chest(vars, x * 32, y * 32);
	else if (str[y][x] == 'P')
	{
		vars->player.looking_direction = RIGHT;
		player_load_asset(vars, x * 32, y * 32);
	}
	return (TRUE);
}
