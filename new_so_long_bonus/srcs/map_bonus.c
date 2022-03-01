/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/01 17:46:03 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	malloc_map(t_vars *vars)
{
	char	*temp;

	vars->map.fd = open(vars->map.path, O_RDONLY);
	if (vars->map.fd < 0)
		return (FALSE);
	temp = get_next_line(vars->map.fd);
	if (!temp)
		exit(0);
	vars->map.len_start = len_n_seek(temp, '\0') - 2;
	vars->map.str = malloc(sizeof(t_vars)
			* vars->map.len_start);
	close(vars->map.fd);
	free(temp);
	if (!vars->map.str)
		return (FALSE);
	return (TRUE);
}

int	read_map(t_vars *vars)
{
	vars->map.cnt = 0;
	if (malloc_map(vars) == FALSE)
	{
		printf("\033[0;31mERROR !\nThe path to the map isn't valid\n");
		exit(0);
	}
	vars->map.fd = open (vars->map.path, O_RDONLY);
	vars->map.str[vars->map.cnt] = get_next_line(vars->map.fd);
	vars->map.width = vars->map.len_start * 32;
	while (vars->map.str[vars->map.cnt])
	{
		vars->map.cnt++;
		vars->map.str[vars->map.cnt] = get_next_line(vars->map.fd);
	}
	vars->map.height = vars->map.cnt * 32;
	vars->map.len_end = len_n_seek(vars->map.str[vars->map.cnt - 1], '\0');
	close(vars->map.fd);
	if (map_validity(vars) == TRUE)
	{
		if (map_true(vars) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}

int	map_true(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (FALSE);
	vars->mlx_win = mlx_new_window(vars->mlx, vars->map.width,
			vars->map.height, "So long!");
	if (vars->mlx_win == NULL)
		return (FALSE);
	init_all(vars);
	render_all(vars, vars->map.str, vars->map.cnt);
	return (TRUE);
}

int	check_map_render(t_vars *vars, char **str, int x, int y)
{
	if (str[y][x] == '0')
		render_floor(vars, x * 32, y * 32);
	else if (str[y][x] == 'Y')
		render_walleye(vars, x * 32, y * 32);
	else if (str[y][x] == 'C' || str[y][x] == 'K')
		render_key(vars, x * 32, y * 32);
	else if (str[y][x] == 'E')
		render_exit(vars, x * 32, y * 32);
	else if (str[y][x] == 'P')
	{
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
	if (vars->map.width == vars->map.height || vars->map.len_start != vars->map.len_end - 1)
	{
		printf("len start : %d, len end: %d\n", vars->map.len_start, vars->map.len_end - 1);
		printf("width : %d, heigth  %d\n", vars->map.width, vars->map.height);
		vars->errorlog.errorlog = "The map must be a rectangle!";
		return (FALSE);
	}
	else if (check_borders(vars) == FALSE)
		return (FALSE);
	else if (confirm_elements(vars) == FALSE)
		return (FALSE);
	else
		return (TRUE);
}
