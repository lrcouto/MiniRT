#include <mlx.h>

typedef struct 	s_data {
	void	*img;
	char	*address;
	int		bpp;
	int		line_leng;
	int		endian;
}			t_data;

void			ft_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_leng + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int				main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		r;
	int		g;
	int		b;
	int		x;
	int		y;

	r = 255;
	g = 0;
	b = 0;
	x = 0;
	y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 255, 255, "Cores!!!");
	img.img = mlx_new_image(mlx, 255, 255);
	img.address = mlx_get_data_addr(img.img, &img.bpp, &img.line_leng, &img.endian);
	while (y < 256)
	{
		x = 0;
		r = 255;
		while (x < 256)
		{
			ft_pixelput(&img, x, y, create_trgb(0,r,g,b));
			r--;
			b++;
			x++;
		}
		y++;
		g++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
