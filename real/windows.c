#include "yolo.h"

int	handle_keypress(int keysum, t_vars *vars)
{
	if (keysum == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		vars->mlx_win = NULL;
		exit(0);
	}
	if (keysum == XK_Right)
		player_right(vars);
	if (keysum == XK_Left)
		player_left(vars);
	if (keysum == XK_Up)
		player_up(vars);
	if (keysum == XK_Down)
		player_down(vars);
	return (TRUE);
}