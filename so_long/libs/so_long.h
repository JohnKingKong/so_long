/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/14 11:29:46 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"

enum e_bool
{
	TRUE = 0,
	FALSE = 1,
};

enum e_directions
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3,
	STATIC = 4,
};

enum e_keys_on_Mac
{
	key_d = 0x02,
	key_a = 0x00,
	key_w = 0x0D,
	key_s = 0x01,
	Escape = 0x35
};

typedef struct s_error
{
	char	*message;
}				t_error;

typedef struct s_floor
{
	void	*img;

}			t_floor;

typedef struct s_chest
{
	void	*img;
	int		pos_chest_x;
	int		pos_chest_y;
	int		for_chest;
}				t_chest;

typedef struct s_wall
{
	void	*img;
	void	*alt_img[9];
	void	*alt_alt_img;
	int		animation;
	int		num;
	int		walleye;
}				t_wall;

typedef struct s_key
{
	void	*img[6];
	int		collect_in_map;
	int		collect_on_player;
	int		animation_coin;
	int		num;
}				t_key;

typedef struct s_player
{
	void	*img_up[4];
	void	*img_down[4];
	void	*img_left[4];
	void	*img_right[4];
	int		looking_direction;
	int		has_chest;
	int		pos_x;
	int		pos_y;
	int		sword_out;
	int		animation;
	int		num;
	int		nb_moves;
}				t_player;

typedef struct s_map
{
	char	**str;
	int		cnt;
	int		width;
	int		height;
	int		is_chest;
	char	*path;
	int		len_start;
	int		len_end;
}				t_map;

typedef struct s_init
{
	int		o;
	int		rdm;
	int		ok_p;
	int		ok_e;
	int		ok_0;
	int		nono;
}				t_init;

typedef struct s_errolog
{
	char	*errorlog;
}				t_errorlog;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_player	player;
	t_chest		chest;
	t_key		key;
	t_wall		wall;
	t_floor		floor;
	t_error		error;
	t_init		init;
	t_errorlog	errorlog;
}				t_vars;

// misc render functions
int		render_all(t_vars *vars, char **str, int cnt);
int		player_load_asset(t_vars *vars, int x, int y);
int		render_floor(t_vars *vars, int x, int y);
int		render_wall(t_vars *vars, int x, int y);
int		render_collectibles(t_vars *vars, int x, int y);
int		render_chest(t_vars *vars, int x, int y);
int		animation_coin(t_vars *vars);
int		check_map_render(t_vars *vars, char **str, int x, int y);
int		render_walleye(t_vars *vars, int x, int y);
void	put_img_player(t_vars *vars, int x, int y);
// init and destroy functions
int		var_init(t_vars *vars, int ac, char **av);
int		keep_initing(t_vars *vars, int ac, char **av);
int		map_loaded(t_vars *vars);
int		init_all(t_vars *vars);
void	init_all2(t_vars *vars, char *path, int width, int height);
void	init_all3(t_vars *vars, char *path, int width, int height);
void	init_all4(t_vars *vars, char *path, int width, int height);
void	init_all5(t_vars *vars, char *path, int width, int height);
int		player_render(t_vars *vars, int x, int y);
void	destroy_erthing(t_vars *vars);
// player movement functions
int		move_up(t_vars *vars, int x, int y);
int		move_down(t_vars *vars, int x, int y);
int		move_right(t_vars *vars, int x, int y);
int		move_left(t_vars *vars, int x, int y);
// misc hooks
int		handle_keypress_windows(int keysum, t_vars *vars);
int		moves_key(int keysum, t_vars *vars);
int		x_to_close(t_vars *vars);
int		free_mamma(t_vars *vars);
// map related functions
int		malloc_map(t_vars *vars);
int		read_map(t_vars *vars);
int		map_validity(t_vars *vars);
int		map_works(t_vars *vars);
int		keep_confirming(t_vars *vars);
// pixels related functions
int		get_back_pixels(t_vars *vars);
void	pixput(t_vars *vars, int x, int y, int color);
//cinematics related functions
int		render_cinematic(t_vars *vars);
// collisions functions
int		collision_wall(t_vars *vars, int direction);
int		collision_keylock(t_vars *vars, int direction);
int		check_for_all_collect(t_vars *vars);
//fucntions for timer
int		timer(t_vars *vars);
void	check_elements(t_vars *vars);
int		confirm_elements(t_vars *vars);
int		check_borders(t_vars *vars);

#endif