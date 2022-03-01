/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/01 16:27:37 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	collision_wall(t_vars *vars, int direction)
{
	if (direction == UP && (vars->map.str[((vars->player.pos_y) / 32) - 1]
			[(vars->player.pos_x) / 32] == '1'
			|| vars->map.str[((vars->player.pos_y) / 32) - 1]
			[(vars->player.pos_x) / 32] == 'Y'))
		return (TRUE);
	if (direction == DOWN && (vars->map.str[((vars->player.pos_y) / 32) + 1]
			[(vars->player.pos_x) / 32] == '1'
			|| vars->map.str[((vars->player.pos_y) / 32) + 1]
			[(vars->player.pos_x) / 32] == 'Y'))
		return (TRUE);
	if (direction == LEFT && (vars->map.str[(vars->player.pos_y) / 32]
			[((vars->player.pos_x) / 32) - 1] == '1'
			|| vars->map.str[((vars->player.pos_y) / 32)]
			[((vars->player.pos_x) / 32) - 1] == 'Y' ))
		return (TRUE);
	if (direction == RIGHT && (vars->map.str[(vars->player.pos_y) / 32]
			[((vars->player.pos_x) / 32) + 1] == '1'
			|| vars->map.str[((vars->player.pos_y) / 32)]
			[((vars->player.pos_x) / 32) + 1] == 'Y' ))
		return (TRUE);
	return (FALSE);
}

int	collision_keylock(t_vars *vars, int direction)
{
	if (direction == UP && vars->player.pos_y - 32 == vars->chest.pos_chest_y
		&& vars->player.pos_x == vars->chest.pos_chest_x)
	{
		if (check_for_all_collect(vars) == FALSE)
			return (TRUE);
	}
	if (direction == DOWN && vars->player.pos_y + 32 == vars->chest.pos_chest_y
		&& vars->player.pos_x == vars->chest.pos_chest_x)
	{
		if (check_for_all_collect(vars) == FALSE)
			return (TRUE);
	}
	if (direction == LEFT && vars->player.pos_x - 32 == vars->chest.pos_chest_x
		&& vars->player.pos_y == vars->chest.pos_chest_y)
	{
		if (check_for_all_collect(vars) == FALSE)
			return (TRUE);
	}
	if (direction == RIGHT && vars->player.pos_x + 32 == vars->chest.pos_chest_x
		&& vars->player.pos_y == vars->chest.pos_chest_y)
	{
		if (check_for_all_collect(vars) == FALSE)
			return (TRUE);
	}
	return (FALSE);
}

int	check_for_all_collect(t_vars *vars)
{
	if (vars->key.collect_on_player == vars->key.collect_in_map)
	{
		x_to_close(vars);
		return (TRUE);
	}
	return (FALSE);
}
