/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/29 12:03:38 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	collision_wall(t_vars *vars, int direction)
{
	if (direction == UP && ((vars->map.str[((vars->player.pos_y) / 32) - 1]
				[(vars->player.pos_x) / 32] <= '9' && (vars->map.str
					[((vars->player.pos_y) / 32) - 1]
					[(vars->player.pos_x) / 32] >= '1'))
			|| vars->map.str[((vars->player.pos_y) / 32) - 1]
			[(vars->player.pos_x) / 32] == 'Y'))
		return (TRUE);
	if (direction == DOWN && ((vars->map.str[((vars->player.pos_y) / 32) + 1]
				[(vars->player.pos_x) / 32] <= '9' && (vars->map.str
					[((vars->player.pos_y) / 32) + 1]
					[(vars->player.pos_x) / 32] >= '1'))
			|| vars->map.str[((vars->player.pos_y) / 32) + 1]
			[(vars->player.pos_x) / 32] == 'Y'))
		return (TRUE);
	if (collision_wall_2(vars, direction) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	collision_wall_2(t_vars *vars, int direction)
{
	if (direction == LEFT && ((vars->map.str[(vars->player.pos_y) / 32]
				[((vars->player.pos_x) / 32) - 1] <= '9' && (vars->map.str
					[(vars->player.pos_y) / 32]
					[((vars->player.pos_x) / 32) - 1] >= '1'))
			|| vars->map.str[((vars->player.pos_y) / 32)]
			[((vars->player.pos_x) / 32) - 1] == 'Y' ))
		return (TRUE);
	if (direction == RIGHT && ((vars->map.str[(vars->player.pos_y) / 32]
				[((vars->player.pos_x) / 32) + 1] <= '9' && (vars->map.str
					[(vars->player.pos_y) / 32]
					[((vars->player.pos_x) / 32) + 1] >= '1'))
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
		if (check_for_text(vars) == TRUE)
			return (TRUE);
	}
	if (direction == DOWN && vars->player.pos_y + 32 == vars->chest.pos_chest_y
		&& vars->player.pos_x == vars->chest.pos_chest_x)
	{
		if (check_for_text(vars) == TRUE)
			return (TRUE);
	}
	if (direction == LEFT && vars->player.pos_x - 32 == vars->chest.pos_chest_x
		&& vars->player.pos_y == vars->chest.pos_chest_y)
	{
		if (check_for_text(vars) == TRUE)
			return (TRUE);
	}
	if (direction == RIGHT && vars->player.pos_x + 32 == vars->chest.pos_chest_x
		&& vars->player.pos_y == vars->chest.pos_chest_y)
	{
		if (check_for_text(vars) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}

int	check_for_text(t_vars *vars)
{
	if (vars->player.has_key == FALSE)
	{
		vars->text.on_or_off = TRUE;
		print_box(vars);
		return (TRUE);
	}
	else if (vars->key.collect_in_map > vars->key.collect_on_player)
	{
		vars->text.on_or_off = TRUE;
		print_box(vars);
		return (TRUE);
	}
	else if (vars->player.has_key == TRUE)
		x_to_close(vars);
	return (FALSE);
}
