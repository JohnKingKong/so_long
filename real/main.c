/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:46:43 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/23 13:33:46 by jvigneau         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"

int	main(void)
{
	t_vars	vars;

	vars.img.has_key = 0;
	vars.img.nb_keys = 0;
	vars.img.is_chest = 0;
	vars.img.has_chest = FALSE;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.mlx_win = mlx_new_window(vars.mlx, WIN_HEIGHT,
			WIN_WIDTH, "DO it! BaBy");
	if (vars.mlx_win == NULL)
	{
		free(vars.mlx_win);
		return (MLX_ERROR);
	}
	read_map(&vars);
	mlx_hook(vars.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_hook(vars.mlx_win, 17, 0, &x_toclose, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
}
