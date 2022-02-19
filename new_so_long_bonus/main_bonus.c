/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/19 14:19:08 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/so_long_bonus.h"

int	var_init(t_vars *vars, int ac, char **av)
{
	vars->chest.for_chest = 0;
	vars->key.num[0] = '1';
	vars->key.collect_in_map = 0;
	vars->key.animation_coin = 0;
	vars->player.animation = 0;
	vars->player.num = 1;
	vars->wall.animation = 0;
	vars->wall.num = 1;
	vars->init.rdm = 0;
	vars->map.cnt = 0;
	vars->init.ok_p = 0;
	vars->init.ok_e = FALSE;
	vars->player.nb_moves = 0;
	vars->text.on_or_off = FALSE;
	vars->player.looking_direction = RIGHT;
	srand(time(NULL));
	temp_init(vars, ac, av);
	return (TRUE);
}

int	temp_init(t_vars *vars, int ac, char **av)
{
	char	*path;

	if (ac == 2)
		vars->map.path = av[1];
	else
		vars->map.path = "./utils/map.txt";
	path = ft_substr(vars->map.path, 8, 8);
	printf("\033[0;37mMap loaded : \033[0;32m%s\n", path);
	free (path);
	return (TRUE);
}

void	check_elements(t_vars *vars)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (vars->map.str[y])
	{
		while (vars->map.str[y][x])
		{
			if (vars->map.str[y][x] == 'C')
				vars->key.collect_in_map++;
			else if (vars->map.str[y][x] == 'P')
				vars->init.ok_p++;
			else if (vars->map.str[y][x] == 'E' && vars->init.ok_e == FALSE)
				vars->init.ok_e = TRUE;
			x++;
		}
		x = 0;
		y++;
	}
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		cnt;
	int		err_map;

	var_init(&vars, ac, av);
	err_map = read_map(&vars);
	if (err_map == FALSE)
	{
		cnt = 0;
		while (vars.map.str[cnt])
		{
			free(vars.map.str[cnt]);
			cnt++;
		}
		free(vars.map.str);
		printf("\033[0;31m\nERROR!!!!!\n%s\n", vars.errorlog.errorlog);
		return (0);
	}
	mlx_string_put(vars.mlx, vars.mlx_win, 40, 32, 0xFFBE149A,
		"Number Of Moves :0");
	mlx_hook(vars.mlx_win, 2, 0, &handle_keypress_windows, &vars);
	mlx_hook(vars.mlx_win, 17, 0, &x_to_close, &vars);
	mlx_loop_hook(vars.mlx, &print_moves, &vars);
	mlx_loop_hook(vars.mlx, &animation_coin, &vars);
	mlx_loop(vars.mlx);
	return (TRUE);
}
