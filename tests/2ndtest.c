#include <mlx.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include <stdio.h>

#define win_width 1152 
#define win_height 960

#define mlxerr 1

#define RED 0xFF0000
#define GREEN 0x00FF00
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define BLUE 0x0000FF

//struct with data for the image to print to the display
typedef struct	s_data
{
	void	*mlx_img;
	char	*adr;
	int		bpp;
	int		line_len;
	int		endian;
	void	*car_img;
	char	*car_adr;
	int		car_bpp;
	int		car_line_len;
	int		car_endian;
	int		pos_car_x;
	int		pos_car_y;
}				t_data;

//struct with variables needed for mlx
typedef struct	s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}				t_vars;

//struct with the data for rendering a rectangle
typedef struct	s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int color;
}				t_rect;

//function to push a pixel to the display
void	pixput(t_data *img, int x, int y, int color)
{
	char	*pix;
	int		i;

	i = img->bpp - 8;
	pix = img->adr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pix++ = (color >> i) & 0xFF;
		else
			*pix++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

//func to render a empty red circle
int	render_circle(t_data *img)
{
	int p,q,x,y,r,d;

	r = 50;
	p = win_width/2;
	q = win_height/2;
	d = 3 - (2*r);
	x = 0;
	y = r;


	while (x <= y)
	{
		pixput(img, x+p, y+q, RED);
		pixput(img, y+p, x+q, RED);
		pixput(img, -y+p, x+q, RED);
		pixput(img, -x+p, y+q, RED);
		pixput(img, -x+p, -y+q, RED);
		pixput(img, -y+p, -x+q, RED);
		pixput(img, y+p, -x+q, RED);
		pixput(img, x+p, -y+q, RED);
		if (d <= 0)
		{
			d = d + (4*x) + 6;
			x++;
		}
		else if (d>=0)
		{
			d = d + (4*x)-(4*y) + 10;
			x++;
			y--;
		}
	}
	return (0);
}

//func to render multiple different rectangles
int	render_rect(t_data *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			pixput(img, j++, i, rect.color);
		i++;
	}
	return (0);
}

//func to render every single pixel for a solid color background
void	background(t_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	
	while (i < win_height)
	{
		j = 0;
		while (j < win_width)
			pixput(img, j++, i, color);
		i++;
	}
}

//function for the loop hook, necessary to keep rendering to the display
int render (t_vars *vars)
{
	if (vars->mlx_win == NULL)
		return (mlxerr);
	if (!vars->img.mlx_img)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img, 0, 0);
	return (0);
}

//func to import a xpm, in this case a wall tile
int tile_wall(t_vars *vars, int xx, int yy)
{
	void	*tileWall;
	char	*relative_path = "./download.XPM";
	int		img_width;
	int		img_height;
	int		cnt = 0;

	vars->img.mlx_img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
	//while (cnt <= xx)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img, xx, yy);
		//cnt++;
	}
	
	return (0);
}

int	car(t_vars *vars, int xx, int yy)
{
	void	*car;
	char	*carpath = "./car.xpm";
	int		car_width;
	int		car_height;

	vars->img.car_img = mlx_new_image(vars->mlx, win_width, win_height);
	vars->img.car_adr = mlx_get_data_addr(vars->img.car_img, &vars->img.car_bpp, &vars->img.car_line_len, &vars->img.car_endian);	
	vars->img.car_img = mlx_xpm_file_to_image(vars->mlx, carpath, &car_width, &car_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.car_img, xx, yy);
	return (0);
}

//func to hook the diff keypresses
int	handle_keypress(int keysum, t_vars *vars)
{
	int i = 0, j = 0;

	if (keysum == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		vars->mlx_win = NULL;
	}
	else if (keysum == XK_Right)
	{	
		render_rect(&vars->img, (t_rect){vars->img.pos_car_x,vars->img.pos_car_y, 100, 100, BLACK});
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img,vars->img.pos_car_x, vars->img.pos_car_y);
		car(vars, vars->img.pos_car_x+64, vars->img.pos_car_y);
	}
/*	else if (keysum == XK_1)
	{
		background(&vars->img, WHITE);
		render_rect(&vars->img, (t_rect){win_width - 100, win_height - 100, 100, 100, GREEN});
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img, 0, 0);
	}
	else if (keysum == XK_2)
	{
		background(&vars->img, WHITE);
		render_rect(&vars->img, (t_rect){0, 0, 100, 100, RED});
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img, 0, 0);
	}
	else if (keysum == XK_3)
	{
		background(&vars->img, WHITE);
		render_rect(&vars->img, (t_rect){win_width - 100, 0, 100, 100, BLUE});
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img, 0, 0);
	}
	else if (keysum == XK_4)
	{
		background(&vars->img, WHITE);
		render_rect(&vars->img, (t_rect){0, win_height - 100, 100, 100, BLACK});
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img, 0, 0);
	}
	else if (keysum == XK_5)
	{
		background(&vars->img, BLACK);
		render_circle(&vars->img);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img, 0, 0);
	}
	else if (keysum == XK_0)
	{
		background(&vars->img, BLACK);
		render_rect(&vars->img, (t_rect){win_width - 100, win_height - 100, 50, 50, GREEN});
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img, 0, 0);
	}*/
	return (0);
}
//func to hook to to handle the x to quit
int xox(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	vars->mlx_win = NULL;
	return (0);
}

//funct to hook to to handle mouse button press
int handle_mouse(int mousum,int x, int y, t_vars *vars)
{
	/*static int b = 0;
	if (mousum == 1 && b == 0)
	{
		b = 1;
		mlx_clear_window(vars->mlx, vars->mlx_win);
		vars->img.mlx_img = mlx_new_image(vars->mlx, win_width, win_height);
		vars->img.adr = mlx_get_data_addr(vars->img.mlx_img, &vars->img.bpp, &vars->img.line_len, &vars->img.endian);
	}*/
	//if (mousum == 2 && b == 1)
	//{
	//	b = 0;
	//	tile_wall(vars);
	//}
	/*if (mousum == 3)
	{
		render_circle(&vars->img);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.mlx_img, 0, 0);
	}*/
	return (0);
}



int	main(void)
{
	t_vars	vars;
	t_data	img;
	int timer = 0;
	int	map = open("./map.txt", O_RDONLY);
	printf("FD: %d\n", map);
	int	xx = 0;
	int yy = 0;
	char *str;

	vars.mlx = mlx_init();

	if (vars.mlx == NULL)
		return (mlxerr);	
	vars.mlx_win = mlx_new_window(vars.mlx, win_width, win_height, "Test");
	if (vars.mlx_win == NULL)
	{
		free(vars.mlx_win);
		return (mlxerr);
	}
	str = get_next_line(map);
	while (str != NULL)
	{	
		while (str[xx])
		{
			if (str[xx] == 'P')
			{
				vars.img.pos_car_x = xx*64;
				vars.img.pos_car_y = yy*64;
				printf("pos x:%d pos y: %d\n",vars.img.pos_car_x, vars.img.pos_car_y );
				car(&vars, vars.img.pos_car_x, vars.img.pos_car_y);
			}
			else if (str[xx] == '1')
				tile_wall(&vars, xx*64, yy*64);
			xx++;
		}
		xx=0;
		yy++;
		str = get_next_line(map);
	}
	printf("LINE:%s\n",str);

	//vars.img.mlx_img = mlx_new_image(vars.mlx, win_width, win_height);
	//	vars.img.adr = mlx_get_data_addr(vars.img.mlx_img, &vars.img.bpp, &vars.img.line_len, &vars.img.endian);
	
	//tile_wall(&vars);
	mlx_loop_hook(vars.mlx, &render, &vars);
	mlx_hook(vars.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_hook(vars.mlx_win, DestroyNotify, ButtonPressMask, &xox, &vars);
	mlx_hook(vars.mlx_win, ButtonRelease, ButtonReleaseMask, &handle_mouse, &vars);
	mlx_loop(vars.mlx);

	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}