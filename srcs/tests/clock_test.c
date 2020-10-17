/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:11:21 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/17 18:39:31 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		ft_pixelput(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	
	dst = mlx->address + (y * mlx->line_leng + x * (mlx->bpp / 8));
	*(unsigned int*)dst = color;
}

static int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int		close_wndw(int keycode, t_mlx *mlx)
{
	if (keycode == 0xFF1B)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

static int		is_valid_pixel(int x, int y, t_rt *rt)
{
	if (x < rt->reso.width && y < rt->reso.height && x >= 0 && y >= 0)
		return (1);
	else
		return (0);
}

static void		put_square(t_mlx *mlx, int x, int y, t_rt *rt)
{
	int i;
	int j;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			if (is_valid_pixel(x + i, y + j, rt))
				ft_pixelput(mlx, x + i, j + y, create_trgb(0, rt->ambi.color.r,
				rt->ambi.color.g, rt->ambi.color.b));
			j++;
		}
		i++;
	}
}

void	test_clock(t_rt *rt)
{
	t_mlx		mlx;
	int			max_x;
	int			max_y;
	t_tuple		point;
	t_tuple		printable;
	t_matrix	rotate;
	t_matrix	translate;
	int			i;

	i = 0;
	point = create_tuple(0, -300, 0, 1);
	mlx.mlx = mlx_init();
	mlx_get_screen_size(mlx.mlx, &max_x, &max_y);
	if (rt->reso.width > max_x)
		rt->reso.width = max_x;
	if (rt->reso.height > max_y)
		rt->reso.height = max_y;
	if (rt->reso.width < 1 || rt->reso.height < 1)
		errormsg(3);
	mlx.win = mlx_new_window(mlx.mlx, rt->reso.width, rt->reso.height, "Clock");
	mlx.img = mlx_new_image(mlx.mlx, rt->reso.width, rt->reso.height);
	mlx.address = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_leng, &mlx.endian);
	translate = translation(rt->reso.width/2, rt->reso.height/2, 0);
	while (i < 24)
	{
		rotate = rotate_z(i * M_PI/12);
		printable = mult_matrix_tuple(rotate, point);
		free_matrix(rotate);
		rotate = rotate_y(M_PI/2);
		printable = mult_matrix_tuple(rotate, printable);
		printable = mult_matrix_tuple(translate, printable);
		printf("HOUR: %d -> point(%f, %f, %f, %d)\n", i, printable.x, printable.y, printable.z, printable.w);
		put_square(&mlx, printable.x, printable.y, rt);
		free_matrix(rotate);
		i++;
	}
	free_matrix(translate);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	free_lists(rt);
	mlx_key_hook(mlx.win, close_wndw, &mlx);
	mlx_loop(mlx.mlx);
}