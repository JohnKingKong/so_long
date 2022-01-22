/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yolo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:54 by jvigneau          #+#    #+#             */
/*   Updated: 2022/01/22 16:25:25 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef YOLO_H
# define YOLO_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

enum e_window 
{
	WIN_HEIGHT = 1152,
	WIN_WIDTH = 960,
	MLX_ERROR = 1
};

enum e_directions 
{
	kVK_RightArrow = 0x7C,
	kVK_LeftArrow = 0x7B,
	kVK_UpArrow = 0x7E,
	kVK_DownArrow = 0x7D,
	kVK_Escape = 0x35
};

enum e_bool
{
	TRUE = 0,
	FALSE = 1,
};

typedef struct s_data
{
	void	*img;
	char	*adr;
	int		bpp;
	int		line_len;
	int		endian;
	int		player_x;
	int		player_y;
	char	*str[10000];
	int		has_key;
}				t_data;

typedef struct s_vars 
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
} 				t_vars;

int	tile_wall(t_vars *vars, int x, int y);
int	collectible(t_vars *vars, int x, int y);
int	render_player_right(t_vars *vars, int x, int y);
int	render_player_left(t_vars *vars, int x, int y);
int	render_player_up(t_vars *vars, int x, int y);
int	render_player_down(t_vars *vars, int x, int y);
int	collect_it(t_vars *vars);
int	render_chest(t_vars *vars, int x, int y);
int	chest(t_vars *vars);
int	open_chest(t_vars *vars, int x, int y);
int	handle_keypress(int	keysum, t_vars *vars);
int	x_toclose(t_vars *vars);
int	read_map(t_vars *vars);
int	render(t_vars *vars, char **str, int y, int cnt);
int	player_right(t_vars *vars);
int	player_left(t_vars *vars);
int	player_up(t_vars *vars);
int	player_down(t_vars *vars);
int	collision_wall_right(t_vars *vars);
int	collision_wall_left(t_vars *vars);
int	collision_wall_up(t_vars *vars);
int	collision_wall_down(t_vars *vars);
int	collision_chest_right(t_vars *vars);
int	collision_chest_left(t_vars *vars);
int	collision_chest_up(t_vars *vars);
int	collision_chest_down(t_vars *vars);
#endif