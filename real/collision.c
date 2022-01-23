/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:31:25 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/22 16:25:45 by jvigneau         ###   ########.fr       */
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
	if (vars->img.str[vars->img.player_y / 32]
		[(vars->img.player_x / 32) + 1] == 'Y')
		return (TRUE);
	return (FALSE);
}

int	collision_chest_left(t_vars *vars)
{
	if (vars->img.str[vars->img.player_y / 32]
		[(vars->img.player_x / 32) - 1] == 'Y')
		return (TRUE);
	return (FALSE);
}

int	collision_chest_up(t_vars *vars)
{
	if ((vars->img.str[vars->img.player_y / 32) - 1]
		[(vars->img.player_x / 32)] == 'Y')
		return (TRUE);
	return (FALSE);
}

int	collision_chest_down(t_vars *vars)
{
	if ((vars->img.str[vars->img.player_y / 32) + 1]
		[(vars->img.player_x / 32)] == 'Y')
		return (TRUE);
	return (FALSE);
}
