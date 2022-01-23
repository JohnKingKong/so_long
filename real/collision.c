/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:31:25 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/23 13:54:09 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"

int	collision_wall_right(t_vars *vars)
{
	if (vars->img.str[vars->img.player_y / 32]
		[(vars->img.player_x / 32) + 1] == '1')
		return (TRUE);
	return (FALSE);
}

int	collision_wall_left(t_vars *vars)
{
	if (vars->img.str[vars->img.player_y / 32]
		[(vars->img.player_x / 32) - 1] == '1')
		return (TRUE);
	return (FALSE);
}

int	collision_wall_up(t_vars *vars)
{
	if (vars->img.str[(vars->img.player_y / 32) - 1]
		[(vars->img.player_x / 32)] == '1')
		return (TRUE);
	return (FALSE);
}

int	collision_wall_down(t_vars *vars)
{
	if (vars->img.str[(vars->img.player_y / 32) + 1]
		[(vars->img.player_x / 32)] == '1')
		return (TRUE);
	return (FALSE);
}

int	collision_chest_right(t_vars *vars)
{
	if (vars->img.player_y / 32 == vars->img.pos_chest_y &&
		(vars->img.player_x / 32) + 1 == vars->img.pos_chest_x)
			return (TRUE);
	return (FALSE);
}

int	collision_chest_left(t_vars *vars)
{
	if (vars->img.player_y / 32 == vars->img.pos_chest_y &&
		(vars->img.player_x / 32) - 1 == vars->img.pos_chest_x)
			return (TRUE);
	return (FALSE);
}

int	collision_chest_up(t_vars *vars)
{
	if ((vars->img.player_y / 32) - 1 == vars->img.pos_chest_y &&
		(vars->img.player_x / 32) == vars->img.pos_chest_x)
			return (TRUE);
	return (FALSE);
}

int	collision_chest_down(t_vars *vars)
{
	if ((vars->img.player_y / 32) + 1 == vars->img.pos_chest_y &&
		(vars->img.player_x / 32)== vars->img.pos_chest_x)
			return (TRUE);
	return (FALSE);
}

int	collision_exit_right(t_vars *vars)
{
	if (vars->img.player_y == vars->img.exit_y
		&& (vars->img.player_x + 32) == vars->img.exit_x
		&& vars->img.has_chest == FALSE)
		return (TRUE);
	return (FALSE);
}

int	collision_exit_left(t_vars *vars)
{
	if (vars->img.player_y == vars->img.exit_y
		&& (vars->img.player_x - 32) == vars->img.exit_x
		&& vars->img.has_chest == FALSE)
		return (TRUE);
	return (FALSE);
}

int	collision_exit_up(t_vars *vars)
{
	if ((vars->img.player_y - 32) == vars->img.exit_y
		&& (vars->img.player_x) == vars->img.exit_x
		&& vars->img.has_chest == FALSE)
		return (TRUE);
	return (FALSE);
}
int	collision_exit_down(t_vars *vars)
{
	if ((vars->img.player_y + 32) == vars->img.exit_y
		&& (vars->img.player_x) == vars->img.exit_x
		&& vars->img.has_chest == FALSE)
		return (TRUE);
	return (FALSE);
}
