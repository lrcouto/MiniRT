/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:36:13 by lniehues          #+#    #+#             */
/*   Updated: 2020/08/08 23:17:54 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

typedef	struct	s_data {
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
}								t_data;

void						my_mlx_pixel_put(t_data *data, int x, int y,
int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void						put_square_to_window(t_data data, int square_size,
int color)
{
	int	counter;
	int	x;
	int	y;

	counter = 0;
	y = 0;
	while (counter < square_size)
	{
		x = 0;
		while (x < square_size)
		{
			my_mlx_pixel_put(&data, x, y, color);
			x += 1;
		}
		y += 1;
		counter += 1;
	}
}

double					deg2rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

void						put_circle_to_window(t_data data, int radius, int screen_width, int screen_height,int color)
{
	double	angle;
	int			x;
	int			y;
	int			center_x;
	int			center_y;
	int 		radius_counter;

	radius_counter = radius;
	center_x = screen_height / 2;
	center_y = screen_width / 2;
	while (radius_counter >= 0)
	{
		angle = 0;
		while (angle < 360)
		{
			x = round(center_x + radius_counter * cos(angle));
			y = round(center_y + radius_counter * sin(angle));
			my_mlx_pixel_put(&data, x, y, color);
			angle += 0.01;
		}
		radius_counter -= 1;
	}
}

int						main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	put_circle_to_window(img, 290, 600, 600, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
