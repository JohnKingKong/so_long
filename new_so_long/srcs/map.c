/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/01 18:02:30 by jvigneau         ###   ########.fr       */
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
	vars->map.len_start = len_n_seek(temp, '\0') - 2;
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
		printf("\033[0;31mERROR !\nThe path or the map isn't valid\n");
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
		!= vars->map.len_end - 1)
	{
		vars->errorlog.errorlog = "\nThe map must be a rectangle!\n";
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
		vars->errorlog.errorlog = "\nNo Collectibles in the map\n";
		return (FALSE);
	}
	else if (vars->init.ok_p <= 0)
	{
		vars->errorlog.errorlog
			= "\nNo starting position for the player in the map\n";
		return (FALSE);
	}
	else if (vars->init.ok_p > 1)
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
	return (TRUE);
}
