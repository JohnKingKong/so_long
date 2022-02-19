/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/10 17:22:36 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"


int	handle_keypress_windows(int keysum, t_vars *vars)
{	
	int	cnt;

	cnt = 0;
	if (keysum == Escape)
	{
		while (vars->map.str[cnt])
		{
			free(vars->map.str[cnt]);
			cnt++;
		}
		free(vars->map.str);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		vars->mlx_win = NULL;
		exit(0);
	}
	if (keysum == key_d || keysum == key_a || keysum == key_s
		|| keysum == key_w)
		moves_key(keysum, vars);
	return (TRUE);
}

int	moves_key(int keysum, t_vars *vars)
{
	if (keysum == key_a)
		vars->player.looking_direction = LEFT;
	else if (keysum == key_d)
		vars->player.looking_direction = RIGHT;
	else if (keysum == key_w)
		vars->player.looking_direction = UP;
	else if (keysum == key_s)
		vars->player.looking_direction = DOWN;
	player_render(vars, vars->player.pos_x, vars->player.pos_y);
	return (TRUE);
}

int	x_to_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	vars->mlx_win = NULL;
	exit (0);
}
