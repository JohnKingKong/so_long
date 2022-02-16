/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/02/15 19:19:34 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/so_long_bonus.h"

int	var_init(t_vars *vars)
{
	vars->chest.for_chest = 0;
	vars->key.num[0] = '1';
	vars->key.keys_in_map = 0;
	vars->key.animation_coin = 0;
	vars->player.animation = 0;
	vars->player.num = 1;
	vars->wall.animation = 0;
	vars->wall.num = 1;
	vars->init.rdm = 0;
	vars->map.cnt = 0;
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		err_map;
	char	*path;

	srand(time(NULL));
	var_init(&vars);
	if (ac == 2)
		vars.map.path = av[1];
	else
		vars.map.path = "./utils/map.txt";
	path = ft_substr(vars.map.path, 8, 8);
	printf("\033[0;37mMap loaded : \033[0;32m%s\n", path);
	free (path);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	if (init_all(&vars) == TRUE)
	{
		err_map = read_map(&vars);
		close(vars.map.fd);
		if (err_map == FALSE)
			return (-1);
	}
	mlx_hook(vars.mlx_win, 2, 0, &handle_keypress_windows, &vars);
	mlx_hook(vars.mlx_win, 17, 0, &x_to_close, &vars);
	mlx_loop_hook(vars.mlx, &animation_coin, &vars);
	mlx_loop(vars.mlx);
	return (TRUE);
}
