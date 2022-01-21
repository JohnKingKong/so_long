/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:46:43 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/21 14:48:55 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yolo.h"

int	main(void)
{
	t_vars	vars;

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
	mlx_hook(vars.mlx_win, 2, 0, &handle_keypress, &vars);
	mlx_hook(vars.mlx_win, 17, 0, &x_toclose, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
}