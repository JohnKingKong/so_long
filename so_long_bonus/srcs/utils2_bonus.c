/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/30 14:23:49 by jvigneau         ###   ########          */
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
			move_ennemies(vars, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (TRUE);
}


int	move_ennemies(t_vars *vars, int x, int y)
{
	int direction;
	int i = 0;

	if (++vars->ennemies.timer > 300 || vars->ennemies.timer < 0)
	{
		srand(time(NULL));
		while (i <= vars->ennemies.num)
		{
			direction = rand() % 4;
			if (x == vars->ennemies.positions[i][1] && y == vars->ennemies.positions[i][0])
			{
				if (collision_ennemies(vars, x, y, direction) == TRUE)
				{
					if (direction == 0)
					{
						render_floor(vars, x * 32, y * 32);
						vars->ennemies.positions[i][1] = x + 1;	
						mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->ennemies.img, (x + 1) * 32, (y) * 32);
					}
					if (direction == 1)
					{
						render_floor(vars, x * 32, y * 32);
						vars->ennemies.positions[i][1] = x - 1;
						mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->ennemies.img, (x - 1) * 32, (y) * 32);
					}
					if (direction == 2)
					{
						render_floor(vars, x * 32, y * 32);
						vars->ennemies.positions[i][0] = y + 1;
						mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->ennemies.img, (x) * 32, (y + 1) * 32);
					}
					if (direction == 3)
					{
						render_floor(vars, x * 32, y * 32);
						vars->ennemies.positions[i][0] = y - 1;
						mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->ennemies.img, (x) * 32, (y - 1) * 32);
					}
				}
			}
			i++;
		}
		vars->ennemies.timer = 0;
	}
	return (TRUE);

}

int	collision_ennemies(t_vars *vars, int x, int y, int direction)
{
	int i = 0;
	if (direction == 0)
	{
		while (i <= vars->ennemies.num)
		{
			if (x + 1 == vars->ennemies.positions[i][1] && vars->ennemies.positions[i][0] == y)
				return (FALSE);
			i++;
		}
		if ((vars->map.str[y][x + 1] >= '1' && vars->map.str[y][x + 1] <= '9') || vars->map.str[y][x + 1] == 'Y'
			|| vars->map.str[y][x + 1] == 'C' || vars->map.str[y][x + 1] == 'E' || vars->map.str[y][x + 1] == 'K')
			return (FALSE);
		if (vars->player.pos_x / 32 == x + 1 && vars->player.pos_y / 32 == y)
		{
			printf("\n\n Oh no!!!! You got touched by a stranger and then you died!!!!\n\n");
			x_to_close(vars);
			return (FALSE);
		}
	}
	else if (direction == 1)
	{
		while (i <= vars->ennemies.num)
		{
			if (x - 1 == vars->ennemies.positions[i][1] && vars->ennemies.positions[i][0] == y)
				return (FALSE);
			i++;
		}
		if ((vars->map.str[y][x - 1] >= '1' && vars->map.str[y][x - 1] <= '9') || vars->map.str[y][x - 1] == 'Y'
			|| vars->map.str[y][x - 1] == 'C' || vars->map.str[y][x - 1] == 'K' || vars->map.str[y][x - 1] == 'E')
				return (FALSE);
		if (vars->player.pos_x / 32 == x - 1 && vars->player.pos_y / 32 == y)
		{
			printf("\n\n Oh no!!!! You got touched by a stranger and then you died!!!!\n\n");
			x_to_close(vars);
			return (FALSE);
		}
	}
	else if (direction == 2)
	{
		while (i <= vars->ennemies.num)
		{
			if (y + 1 == vars->ennemies.positions[i][0] && vars->ennemies.positions[i][1] == x)
				return (FALSE);
			i++;
		}
		if ((vars->map.str[y + 1][x] >= '1' && vars->map.str[y + 1][x] <= '9') || vars->map.str[y + 1][x] == 'Y'
			|| vars->map.str[y + 1][x] == 'E' || vars->map.str[y + 1][x] == 'K' || vars->map.str[y + 1][x] == 'C')
			return (FALSE);
		if (vars->player.pos_y / 32 == y + 1 && vars->player.pos_x / 32 == x)
		{
			printf("\n\n Oh no!!!! You got touched by a stranger and then you died!!!!\n\n");
			x_to_close(vars);
			return (FALSE);
		}
	}
	else if (direction == 3)
	{
		while (i <= vars->ennemies.num)
		{
			if (y - 1 == vars->ennemies.positions[i][0] && vars->ennemies.positions[i][1] == x)
				return (FALSE);
			i++;
		}
		if ((vars->map.str[y - 1][x] >= '1' && vars->map.str[y - 1][x] <= '9') || vars->map.str[y - 1][x] == 'Y'
			|| vars->map.str[y - 1][x] == 'E' || vars->map.str[y - 1][x] == 'C' || vars->map.str[y - 1][x] == 'K')
			return (FALSE);
		if (vars->player.pos_y / 32 == y - 1 && vars->player.pos_x / 32 == x)
		{
			printf("\n\n Oh no!!!! You got touched by a stranger and then you died!!!!\n\n");
			x_to_close(vars);
			return (FALSE);
		}
	}
	return (TRUE);
}

void	text_box(t_vars *vars, int x, int y)
{
	if (vars->map.str[y][x] == 'C' || vars->map.str[y][x] == 'K')
		render_key(vars, x * 32, y * 32);
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
			vars->errorlog.errorlog = "The map isn't delimited by borders\n";
			return (FALSE);
		}
		x++;
	}
	while (y < vars->map.height / 32)
	{
		if (vars->map.str[y][0] != '1' || vars->map.str[y][x - 1] != '1')
		{
			vars->errorlog.errorlog = "The map isn't delimited by borders\n";
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
	if (keep_confirming(vars) == TRUE)
		return (TRUE);
	return (FALSE);
}
