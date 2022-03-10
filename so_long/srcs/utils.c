/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/01 10:54:09 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	handle_keypress_windows(int keysum, t_vars *vars)
{	
	if (keysum == Escape)
		x_to_close(vars);
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
	free_mamma(vars);
	vars->mlx_win = NULL;
	destroy_erthing(vars);
	printf("\n\033[0;33m *** Thank you so much for playing!! ");
	printf("Have a nice day! ***\n");
	exit(0);
}

int	free_mamma(t_vars *vars)
{
	int	cnt;

	cnt = 0;
	while (vars->map.str[cnt])
	{
		free(vars->map.str[cnt]);
		cnt++;
	}
	free(vars->map.str);
	return (TRUE);
}

int	timer(t_vars *vars)
{
	if (++vars->key.animation_coin > 10 || vars->key.animation_coin < 0)
	{
		vars->key.num = vars->key.num + 1;
		if (vars->key.num > 6)
			vars->key.num = 1;
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
