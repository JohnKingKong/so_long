/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/01 18:38:56 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long_bonus.h"

int	handle_keypress_windows(int keysum, t_vars *vars)
{	
	if (keysum == Escape)
		x_to_close(vars);
	if (keysum == key_d || keysum == key_a || keysum == key_s
		|| keysum == key_w)
		moves_key(keysum, vars);
	if (keysum == 0x24 && vars->text.on_or_off == TRUE)
	{
		vars->text.on_or_off = FALSE;
		render_all(vars, vars->map.str, vars->map.cnt);
		print_moves(vars);
	}
	return (TRUE);
}

int	moves_key(int keysum, t_vars *vars)
{
	if (vars->text.on_or_off == FALSE)
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
	}
	return (TRUE);
}

int	x_to_close(t_vars *vars)
{
	int	cnt;

	cnt = 0;
	while (vars->map.str[cnt])
	{
		free(vars->map.str[cnt]);
		cnt++;
	}
	free(vars->map.str);
	vars->mlx_win = NULL;
	destroy_erthing(vars);
	printf("\n\033[0;33m *** Thank you so much for playing!! ");
	printf("Have a nice day! ***\n");
	exit(0);
}

void	destroy_erthing(t_vars *vars)
{
	int	cnt;

	mlx_destroy_image(vars->mlx, vars->chest.img);
	cnt = 8;
	while (cnt-- > 0)
		mlx_destroy_image(vars->mlx, vars->wall.img[cnt]);
	mlx_destroy_image(vars->mlx, vars->floor.img);
	cnt = 7;
	while (cnt-- > 1)
		mlx_destroy_image(vars->mlx, vars->key.img[cnt]);
	cnt = 4;
	while (cnt-- > 0)
	{
		mlx_destroy_image(vars->mlx, vars->player.img_up[cnt]);
		mlx_destroy_image(vars->mlx, vars->player.img_down[cnt]);
		mlx_destroy_image(vars->mlx, vars->player.img_left[cnt]);
		mlx_destroy_image(vars->mlx, vars->player.img_right[cnt]);
	}
	cnt = 8;
	while (cnt-- > 0)
		mlx_destroy_image(vars->mlx, vars->wall.alt_img[cnt]);
}

int	map_loaded(t_vars *vars)
{
	char	*path;

	path = ft_substr(vars->map.path, 6, 8);
	printf("\033[0;37mMap loaded : \033[0;32m%s\n", path);
	free(path);
	return (TRUE);
}
