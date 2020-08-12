/*
** THIS MOTHERFUCKER CRASHED MY COMPUTER. Run at your own risk.
** DO NOT make the little square go outsite the window boundaries.
*/

#include <mlx.h>
#include <stdio.h>

typedef struct 	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*address;
	int		bpp;
	int		line_leng;
	int		endian;
	int		offset_x;
	int		offset_y;
}			t_vars;

void			ft_pixelput(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->address + (y * vars->line_leng + x * (vars->bpp / 8));
	*(unsigned int*)dst = color;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int				render_next_frame(t_vars *vars)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	vars->img = mlx_new_image(vars->mlx, 800, 600);
	vars->address = mlx_get_data_addr(vars->img, &vars->bpp, &vars->line_leng, &vars->endian);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	while ((y + vars->offset_y) < (vars->offset_y + 21))
	{
	x = 0;
	while ((x + vars->offset_x) < (vars->offset_x + 21))
	{
		ft_pixelput(vars, (x + vars->offset_x), (y + vars->offset_y), create_trgb(0, 0, 150, 255));
		x++;
	}
	y++;
	}
	return (0);
}

int				keypress(int keycode, t_vars *vars, void *p)
{
    if (keycode == 0xFF1B)
		mlx_destroy_window(vars->mlx, vars->win);
	else if (keycode == 0x64)
		vars->offset_x = vars->offset_x + 10;
	return (0);
}

int				main(void)
{
	t_vars	vars;

	vars.offset_x = 0;
	vars.offset_y = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Wheeee!!!");
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_key_hook(vars.win, keypress, &vars);
	mlx_loop(vars.mlx);
}
