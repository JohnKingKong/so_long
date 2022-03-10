/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:22 by jvigneau          #+#    #+#             */
/*   Updated: 2022/03/08 16:07:38 by jvigneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <time.h>
# include <stdlib.h>

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

typedef struct s_text
{
	void	*box_img;
	char	*message;
	void	*box_txt;
	void	*coins_txt;
	int		on_or_off;
	int		txt_num;
}				t_text;

typedef struct s_floor
{
	void	*img;

}			t_floor;

typedef struct s_exit
{
	void	*img;
}				t_exit;

typedef struct s_chest
{
	void	*img;
	int		pos_chest_x;
	int		pos_chest_y;
	int		for_chest;
}				t_chest;

typedef struct s_wall
{
	void	*img[9];
	void	*alt_img[9];
	int		animation;
	int		num;
}				t_wall;

typedef struct s_key
{
	void	*img[7];
	void	*img_key;
	int		collect_in_map;
	int		collect_on_player;
	int		animation_coin;
	int		num[0];
	char	savior;
	int		on;
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
	int		has_key;
}				t_player;

typedef struct s_ennemies
{
	void	*img;
	int		***positions;
	int		**spawner_location;
	int		num;
}				t_ennemies;

typedef struct s_map
{
	char	**str;
	int		fd;
	int		cnt;
	int		width;
	int		height;
	int		is_chest;
	int		pos_exit_y;
	char	*path;
	int		wall_nb[1000][1000];
	int		len_start;
	int		len_end;
}				t_map;

typedef struct s_init
{
	int		o;
	int		rdm;
	int		ok_p;
	int		ok_e;
	int		nono;
}				t_init;

typedef struct s_errolog
{
	char	*errorlog;
}				t_errorlog;

typedef struct s_score
{
	int	score;
}				t_score;

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
	t_ennemies	ennemies;
	t_text		text;
	t_init		init;
	t_errorlog	errorlog;
	t_exit		exit;
	t_score		score;
}				t_vars;

// misc render functions
int		render_all(t_vars *vars, char **str, int cnt);
int		player_load_asset(t_vars *vars, int x, int y);
int		render_floor(t_vars *vars, int x, int y);
void	render_wall(t_vars *vars, int x, int y);
int		render_collectibles(t_vars *vars, int x, int y);
int		render_chest(t_vars *vars, int x, int y);
void	render_walleye(t_vars *vars, int x, int y);
void	put_img_player(t_vars *vars, int x, int y);
int		player_render(t_vars *vars, int x, int y);
int		render_exit(t_vars *vars, int x, int y);
int		render_key(t_vars *vars, int x, int y);
// init functions
int		var_init(t_vars *vars, int ac, char **av);
int		init_all(t_vars *vars);
void	init_all2(t_vars *vars, char *path, int width, int height);
void	init_all3(t_vars *vars, char *path, int width, int height);
void	init_all4(t_vars *vars, char *path, int width, int height);
void	init_all5(t_vars *vars, char *path, int width, int height);
void	init_all6(t_vars *vars, char *path, int width, int height);
void	init_all7(t_vars *vars, char *path, int width, int height);
int		keep_initing(t_vars *vars, int ac, char **av);
int		map_loaded(t_vars *vars);
// player movement functions
int		move_up(t_vars *vars, int x, int y);
int		move_down(t_vars *vars, int x, int y);
int		move_right(t_vars *vars, int x, int y);
int		move_left(t_vars *vars, int x, int y);
// misc hooks
int		handle_keypress_windows(int keysum, t_vars *vars);
int		moves_key(int keysum, t_vars *vars);
int		animation_coin(t_vars *vars);
int		timer(t_vars *vars);
void	text_box(t_vars *vars, int x, int y);
int		print_score(t_vars *vars);
// map related functions
int		malloc_map(t_vars *var);
int		read_map(t_vars *vars);
int		map_validity(t_vars *vars);
int		check_map_render(t_vars *vars, char **str, int x, int y);
int		confirm_elements(t_vars *vars);
void	check_elements(t_vars *vars);
int		check_borders(t_vars *vars);
void	rdm_walls(t_vars *vars, int x, int y);
int		map_true(t_vars *vars);
int		keep_confirming(t_vars *vars);
// collisions functions
int		collision_wall(t_vars *vars, int direction);
int		collision_wall_2(t_vars *vars, int direction);
int		collision_keylock(t_vars *vars, int direction);
int		check_collect(t_vars *vars, int x, int y);
int		check_for_text(t_vars *vars);
// destroyssssssss
void	destroy_erthing(t_vars *vars);
void	error_map_exit(t_vars *vars);
int		x_to_close(t_vars *vars);
// moves counter
int		print_moves(t_vars *vars);
int		print_box(t_vars *vars);

#endif
