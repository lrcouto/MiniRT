#include <mlx.h>
#include <stdio.h>

typedef struct  s_vars {
    void		*mlx;
    void		*win;
}				t_vars;

int				close(int keycode, t_vars *vars)
{
    if (keycode == 0xFF1B)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int				mouse_win1(int button,int x,int y, void *p)
{
	printf("Mouse in Win1, button %d at %dx%d.\n",button,x,y);
	return (0);
}

int				main(void)
{
    t_vars		vars;

	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
    mlx_key_hook(vars.win, close, &vars);
	mlx_mouse_hook(vars.win, mouse_win1, &vars);
    mlx_loop(vars.mlx);
}
