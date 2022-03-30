/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/30 13:45:14 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/so_long_bonus.h"

int	var_init(t_vars *vars, int ac, char **av)
{
	vars->key.num[0] = 1;
	vars->key.collect_in_map = 0;
	vars->key.collect_on_player = 0;
	vars->key.animation_coin = 0;
	vars->player.animation = 0;
	vars->player.num = 1;
	vars->wall.animation = 0;
	vars->wall.num = 1;
	vars->init.rdm = 0;
	vars->map.cnt = 0;
	vars->init.ok_p = 0;
	vars->init.ok_e = 0;
	vars->player.nb_moves = 0;
	vars->text.on_or_off = FALSE;
	vars->player.looking_direction = RIGHT;
	vars->key.on = FALSE;
	vars->player.has_key = FALSE;
	vars->text.txt_num = 0;
	vars->score.score = 1000;
	srand(time(NULL));
	if (keep_initing(vars, ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	keep_initing(t_vars *vars, int ac, char **av)
{
	vars->map.len_start = 0;
	vars->map.len_end = 0;
	vars->init.nono = FALSE;
	vars->ennemies.init = 0;
	vars->ennemies.num = 0;
	if (ac != 2)
	{
		vars->errorlog.errorlog = "You have to pass a path to a map file!\n";
		return (FALSE);
	}
	if (ac == 2)
		vars->map.path = av[1];
	if (!ft_strnstr(vars->map.path, ".ber\0\n", ft_strlen(vars->map.path))
		|| vars->map.path[ft_strlen(vars->map.path) - 4] != '.')
	{
		vars->errorlog.errorlog = "The file chosen isn't a .ber!!\n";
		return (FALSE);
	}
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
			else if (vars->map.str[y][x] == 'E')
				vars->init.ok_e++;
			else if (vars->map.str[y][x] == '1' || vars->map.str[y][x] == '0'
				|| vars->map.str[y][x] == '\n')
				vars->map.is_chest = 0;
			else
				vars->init.nono = TRUE;
			x++;
		}
		x = 0;
		y++;
	}
}

void	error_map_exit(t_vars *vars)
{
	int	cnt;

	cnt = 0;
	while (vars->map.str[cnt])
	{
		free(vars->map.str[cnt]);
		cnt++;
	}
	free(vars->map.str);
	printf("\033[0;31m\nERROR!!!!!\n%s\n", vars->errorlog.errorlog);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		err_map;

	if (var_init(&vars, ac, av) == FALSE)
	{
		printf("\033[0;31m\nERROR !!!!!!\n%s\n", vars.errorlog.errorlog);
		return (FALSE);
	}
	err_map = read_map(&vars);
	if (err_map == FALSE)
	{
		error_map_exit(&vars);
		return (FALSE);
	}
	map_loaded(&vars);
	mlx_string_put(vars.mlx, vars.mlx_win, 40, 32, 0xFFBE149A,
		"Number Of Moves :0");
	mlx_string_put(vars.mlx, vars.mlx_win, 40, 64, 0xFFBE149A, "SCORE : 0");
	mlx_hook(vars.mlx_win, 2, 0, &handle_keypress_windows, &vars);
	mlx_hook(vars.mlx_win, 17, 0, &x_to_close, &vars);
	mlx_loop_hook(vars.mlx, &print_moves, &vars);
	mlx_loop_hook(vars.mlx, &animation_coin, &vars);
	mlx_loop(vars.mlx);
	return (TRUE);
}
