/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/18 14:31:38 by jvigneau         ###   ########.fr       */
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
		vars->text.on_or_off = TRUE;
		print_box(vars);
		return (TRUE);
	}
	if (direction == DOWN && vars->player.pos_y + 32 == vars->chest.pos_chest_y
		&& vars->player.pos_x == vars->chest.pos_chest_x)
		return (TRUE);
	if (direction == LEFT && vars->player.pos_x - 32 == vars->chest.pos_chest_x
		&& vars->player.pos_y == vars->chest.pos_chest_y)
		return (TRUE);
	if (direction == RIGHT && vars->player.pos_x + 32 == vars->chest.pos_chest_x
		&& vars->player.pos_y == vars->chest.pos_chest_y)
		return (TRUE);
	return (FALSE);
}
