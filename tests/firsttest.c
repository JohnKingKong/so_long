#include <mlx.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdio.h>

typedef struct s_data {
    
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}              t_data;

typedef struct s_vars {
    void    *mlx;
    void    *mlx_win;
}              t_vars;

void    my_pixel_put(t_data *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

/*int key_presses(int keysum, t_vars *vars, t_data img)
{ 
    int     i = 0, j = 0;
    float   k = 0; 

    img.img = mlx_new_image(vars->mlx, 1755, 975);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

    if (keysum == xk_escape) // escape to close
        mlx_destroy_window(vars->mlx, vars->mlx_win);
    if (keysum == xk_1) // filled blue square
    {
        while (j < 100)
        {
            while (i < 100)
            {
                my_pixel_put(&img, i, j, 0x0000ff00);
                i++;
            }
            i = 0;
            j++;
        }
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
    }
    if (keysum == xk_2) // empty green square
    {
        i = 200;
        j = 200;
        while (i < 400)
        {
            my_pixel_put(&img, i, j, 0x000000ff);
            i++;
        }
        while (j < 400)
        {
            my_pixel_put(&img, i, j, 0x000000ff);
            j++;
        }
        while (i > 200)
        {
            my_pixel_put(&img, i, j, 0x000000ff);
            i--;
        }   
        while (j > 200)
        {
            my_pixel_put(&img, i, j, 0x000000ff);
            j--;
        }  
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
    } 
    if (keysum == xk_3) // empty red triangle
    {
        i = 500;
        j = 500;
        while (i > 300)
        {
            my_pixel_put(&img, i, j, 0x00ff0000);
            i--;
            j++;
        }
        i = 500;
        j = 500;
        while (i < 700)
        {
            my_pixel_put(&img, i, j, 0x00ff0000);
            i++;
            j++;
        }
        i = 300;
        while (i < 700)
        {
            my_pixel_put(&img, i, j, 0x00ff0000);
            i++;
        }
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
    }
    if (keysum == xk_4) // filled yellow pentagon kinda thing   y
    {
        i = 800;
        j = 300;
        while (k < 200)
        {
            while (i > 700)
            {
                my_pixel_put(&img, i+k, j+k, 0x0091aa34);
                i--;
                j++;
            }
            i = 800;
            j = 300;
            k+=0.5;
        }
        k = 0;
        i = 799;
        while (k < 200)
        {
            while (i > 699)
            {
                my_pixel_put(&img, i+k, j+k, 0x0091aa34);
                i--;
                j++;
            }
            i = 799;
            j = 300;
            k += 0.5;
        }
        k = 0;
        i = 800;
        j = 300;
        while (k < 200)
        {
            while (i < 900)
            {
                my_pixel_put(&img, i-k, j+k, 0x0091aa34);
                 i++;
                j++;
            }
            i = 800;
            j = 300;
            k+=0.5;
        }

        k = 0;
        i = 799;
        j = 300;
        while (k < 200)
        {
            while (i < 901)
            {
                my_pixel_put(&img, i-k, j+k, 0x0091aa34);
                i++;
                j++;
            }
            i = 799;
            j = 300;
            k += 0.5;
        }
        
       i = 700;
       j = 500;
       while (j < 600)
       {
            while (i < 900)
            {
                my_pixel_put(&img, i, j, 0x0091aa34);
                i++;
            }
            i = 700;
            j++;
        }
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
    }
    return (0);
}*
/*int mouse(int mousum, t_vars *vars, t_data img)
{
    int     i = 0, j = 0;
    float   k = 0; 

    /*img.img = mlx_new_image(vars->mlx, 1755, 975);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
    if (mousum)
    {

        while (j < 100)
        {
            while (i < 100)
            {
                my_pixel_put(&img, i, j, 0x0000ff00);
                i++;
            }
            i = 0;
            j++;
        }
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
    printf("YOLOOOOOOOOOOOOO\n");
    }
    return (0);
}*/

/*int mouse_move(int mousymove, t_vars *vars)
{
    XQueryPointer();
    return 42;
}*/

int noevents(void *data)
{
    return (0);
}

int main()
{
    int     i = 0, j = 0;
    t_data  img; 
    t_vars  vars;

    vars.mlx = mlx_init();
    if(vars.mlx)
    {

        vars.mlx_win = mlx_new_window(vars.mlx, 1755, 975, "YOLO");

        mlx_loop_hook(vars.mlx, &noevents, &vars);
      //  mlx_mouse_hook(vars.mlx_win, &mouse, &vars);
      //  mlx_key_hook(vars.mlx_win, &key_presses, &vars);
       // mlx_hook(vars.mlx_win, MotionNotify, PointerMotionMask, &mouse_move, &vars);

        mlx_loop(vars.mlx);

        mlx_destroy_display(vars.mlx);
        free(vars.mlx);
    }
}
