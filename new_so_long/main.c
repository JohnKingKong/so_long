/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/19 12:01:09 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/so_long.h"

int	var_init(t_vars *vars)
{
	vars->chest.for_chest = 0;
	vars->key.num[0] = '1';
	vars->key.collect_in_map = 0;
	vars->key.animation_coin = 0;
	vars->player.animation = 0;
	vars->player.num = 1;
	vars->wall.animation = 0;
	vars->wall.num = 1;
	vars->wall.walleye = 0;
	vars->init.ok_p = 0;
	vars->init.ok_e = FALSE;
	vars->init.ok_0 = FALSE;
	vars->player.nb_moves = 0;
	vars->errorlog.errorlog = malloc(sizeof(char) * 1000);
	if (!vars->errorlog.errorlog)
		return (FALSE);
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		err_map;

	if (!var_init(&vars))
		return (-1);
	if (ac == 2)
		vars.map.path = av[1];
	printf("%s\n", vars.map.path);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	if (init_all(&vars) == TRUE)
	{
		err_map = read_map(&vars);
		if (err_map == FALSE)
		{
			printf("\033[0;31mERROR !\n%s", vars.errorlog.errorlog);
			return (0);
		}
	}
	mlx_hook(vars.mlx_win, 2, 0, &handle_keypress_windows, &vars);
	mlx_hook(vars.mlx_win, 17, 0, &x_to_close, &vars);
	mlx_loop_hook(vars.mlx, &animation_coin, &vars);
	mlx_loop(vars.mlx);
	return (TRUE);
}
