/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/19 14:09:32 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	malloc_map(t_vars *vars)
{
	vars->map.str = malloc(sizeof(t_vars) * 1000);
	if (!vars->map.str)
		return (FALSE);
	return (TRUE);
}

int	read_map(t_vars *vars)
{
	malloc_map(vars);
	vars->map.fd = open(vars->map.path, O_RDONLY);
	if (vars->map.fd < 0)
	{
		vars->errorlog.errorlog = "The path to the map is corrupt!\n";
		return (FALSE);
	}
	vars->map.str[vars->map.cnt] = get_next_line(vars->map.fd);
	vars->map.width = (ft_strlen(vars->map.str[vars->map.cnt]) - 2) * 32;
	while (vars->map.str[vars->map.cnt])
	{
		vars->map.cnt++;
		vars->map.str[vars->map.cnt] = get_next_line(vars->map.fd);
	}
	vars->map.height = vars->map.cnt * 32;
	close(vars->map.fd);
	if (map_validity(vars) == TRUE)
	{
		printf("ok p %d\n", vars->init.ok_p);
		vars->mlx = mlx_init();
		if (vars->mlx == NULL)
			return (FALSE);
		init_all(vars);
		vars->mlx_win = mlx_new_window(vars->mlx, vars->map.width,
				vars->map.height, "So long!");
		if (vars->mlx_win == NULL)
			return (FALSE);
		render_all(vars, vars->map.str, vars->map.cnt);
		return (TRUE);
	}
	return (FALSE);
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

int	check_map_render(t_vars *vars, char **str, int x, int y)
{
	if (str[y][x] == '0')
		render_floor(vars, x * 32, y * 32);
	else if (str[y][x] == 'Y')
		render_walleye(vars, x * 32, y * 32);
	else if (str[y][x] == 'C' && vars->chest.for_chest != 3)
		render_collectibles(vars, x * 32, y * 32);
	else if ((str[y][x] == 'C' && vars->chest.for_chest == 3))
		render_chest(vars, x * 32, y * 32);
	else if (str[y][x] == 'c')
		render_chest(vars, x * 32, y * 32);
	else if (str[y][x] == 'P')
	{
		vars->player.looking_direction = RIGHT;
		player_load_asset(vars, x * 32, y * 32);
		vars->map.str[y][x] = '0';
	}
	else if (str[y][x] == '1')
		rdm_walls(vars, x, y);
	else
		render_wall(vars, x * 32, y * 32);
	return (TRUE);
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
