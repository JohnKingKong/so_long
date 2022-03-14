/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/14 11:23:08 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	malloc_map(t_vars *vars)
{
	int		map;
	char	*temp;

	map = open(vars->map.path, O_RDONLY);
	if (map < 0)
		return (FALSE);
	temp = get_next_line(map);
	if (!temp)
	{
		printf("\033[0;31m\nERROR !\nThe map file is empty or corrupt!!\n\n");
		exit (0);
	}
	vars->map.len_start = len_n_seek(temp, '\0') - 1;
	vars->map.str = malloc(sizeof(t_vars)
			* vars->map.len_start);
	close(map);
	free(temp);
	if (!vars->map.str)
		return (FALSE);
	return (TRUE);
}

int	read_map(t_vars *vars)
{
	int	map;

	vars->map.cnt = 0;
	if (malloc_map(vars) == FALSE)
	{
		printf("\033[0;31m\nERROR !\nThe path or the map isn't valid\n\n");
		exit(0);
	}
	map = open (vars->map.path, O_RDONLY);
	vars->map.str[vars->map.cnt] = get_next_line(map);
	vars->map.width = vars->map.len_start * 32;
	while (vars->map.str[vars->map.cnt])
	{
		vars->map.cnt++;
		vars->map.str[vars->map.cnt] = get_next_line(map);
	}
	vars->map.height = vars->map.cnt * 32;
	vars->map.len_end = len_n_seek(vars->map.str[vars->map.cnt - 1], '\0');
	close(map);
	if (map_validity(vars) == TRUE)
	{
		if (map_works(vars) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}

int	map_works(t_vars *vars)
{
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

int	map_validity(t_vars *vars)
{
	if (vars->map.width == vars->map.height || vars->map.len_start
		!= vars->map.len_end)
	{
		vars->errorlog.errorlog = "The map must be a rectangle!\n";
		return (FALSE);
	}
	if (check_borders(vars) == FALSE)
		return (FALSE);
	if (confirm_elements(vars) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	confirm_elements(t_vars *vars)
{
	check_elements(vars);
	if (vars->key.collect_in_map == 0)
	{
		vars->errorlog.errorlog = "No Collectibles in the map";
		return (FALSE);
	}
	else if (vars->init.ok_p <= 0)
	{
		vars->errorlog.errorlog
			= "No starting position for the player in the map";
		return (FALSE);
	}
	if (keep_confirming(vars) == FALSE)
		return (FALSE);
	return (TRUE);
}
