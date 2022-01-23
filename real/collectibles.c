/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:49:38 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/23 13:32:25 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"
#include <stdio.h>

int	collect_it(t_vars *vars)
{
	if (vars->img.str[(vars->img.player_y / 32)]
		[(vars->img.player_x / 32)] == 'C')
	{
		vars->img.has_key = vars->img.has_key + 1;
		vars->img.str[vars->img.player_y / 32][vars->img.player_x / 32] = '0';	
		return (TRUE);
	}
	return (FALSE);
}

int	chest(t_vars *vars)
{
	if (vars->img.str[(vars->img.player_y / 32)][(vars->img.player_x / 32)] == 'Y')
		return (TRUE);
	return (FALSE);
}