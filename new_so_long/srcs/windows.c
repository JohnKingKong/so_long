/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  windows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:54 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/23 13:54:48 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../libs/so_long.h"
#include <X11/keysym.h>
#include <X11/X.h>

int	handle_keypress(int keysum, t_vars *vars)
{
	if (keysum == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		vars->mlx_win = NULL;
		exit (0);
	}
	else if (keysum == XK_Right)
		player_render(vars, vars->player.pos_x, vars->player.pos_y, RIGHT);
	else if (keysum == XK_Left)
		player_render(vars, vars->player.pos_x, vars->player.pos_y, LEFT);
else if (keysum == XK_Up)
		player_render(vars, vars->player.pos_x, vars->player.pos_y, UP);
	else if (keysum == XK_Down)
		player_render(vars, vars->player.pos_x, vars->player.pos_y, DOWN);
	return (TRUE);
}*/