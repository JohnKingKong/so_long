/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/22 10:59:11 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	timer(t_vars *vars)
{
	if (++vars->key.animation_coin > 10 || vars->key.animation_coin < 0)
	{
		vars->key.num[0] = vars->key.num[0] + 1;
		if (vars->key.num[0] > 6)
			vars->key.num[0] = 1;
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
			if (vars->text.on_or_off == FALSE)
				text_box(vars, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (TRUE);
}

void	text_box(t_vars *vars, int x, int y)
{
	if (vars->map.str[y][x] == 'C')
		render_collectibles(vars, x * 32, y * 32);
	if (y == vars->player.pos_y / 32
		&& x == vars->player.pos_x / 32)
		player_load_asset(vars, x * 32, y * 32);
	if (vars->map.str[y][x] == 'Y')
		render_walleye(vars, x * 32, y * 32);
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
