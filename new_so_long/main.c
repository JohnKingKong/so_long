/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/01 10:58:56 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/so_long.h"

int	var_init(t_vars *vars, int ac, char **av)
{
	vars->chest.for_chest = 0;
	vars->key.num = 1;
	vars->key.collect_in_map = 0;
	vars->key.collect_on_player = 0;
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
	vars->map.len_start = 0;
	vars->map.len_end = 0;
	vars->map.cnt = 0;
	if (keep_initing(vars, ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	keep_initing(t_vars *vars, int ac, char **av)
{
	if (ac == 2)
		vars->map.path = av[1];
	else
		vars->map.path = "utils/map.ber";
	if (!ft_strnstr(vars->map.path, ".ber", ft_strlen(vars->map.path)))
	{
		vars->errorlog.errorlog = "\nThe file chosen isn't a .ber!!\n";
		return (FALSE);
	}
	return (TRUE);
}

int	map_loaded(t_vars *vars)
{
	char	*path;

	path = ft_substr(vars->map.path, 6, 8);
	printf("\033[0;37mMap loaded : \033[0;32m%s\n", path);
	free(path);
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		err_map;
	int		cnt;

	cnt = 0;
	if (var_init(&vars, ac, av) == FALSE)
	{
		printf("\n\033[0;31mERROR !\n%s\n", vars.errorlog.errorlog);
		return (FALSE);
	}
	err_map = read_map(&vars);
	if (err_map == FALSE)
	{
		printf("\n\033[0;31mERROR !\n%s\n", vars.errorlog.errorlog);
		free_mamma(&vars);
		return (FALSE);
	}
	map_loaded(&vars);
	mlx_hook(vars.mlx_win, 2, 0, &handle_keypress_windows, &vars);
	mlx_hook(vars.mlx_win, 17, 0, &x_to_close, &vars);
	mlx_loop_hook(vars.mlx, &animation_coin, &vars);
	mlx_loop(vars.mlx);
	return (TRUE);
}
