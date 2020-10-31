/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:11:21 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/31 19:35:59 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

typedef struct	s_vars
{
	t_mlx	mlx;
	int		degrees;
	t_reso	reso;
	t_color	color;
}				t_vars;

static int		is_valid_pixel(int x, int y, t_vars *vars)
{
	if (x < vars->reso.width && y < vars->reso.height && x >= 0 && y >= 0)
		return (1);
	else
		return (0);
}

static void		put_square(t_mlx *mlx, int x, int y, t_vars *vars)
{
	int i;
	int j;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			if (is_valid_pixel(x + i, y + j, vars))
				ft_pixelput(mlx, x + i, j + y, create_trgb(0, vars->color.r,
				vars->color.g, vars->color.b));
			j++;
		}
		i++;
	}
}

static int		render_next_frame(t_vars *vars)
{
	t_tuple		point;
	t_tuple		printable;
	t_matrix	rotate;
	t_matrix	translate;
	int			i;

	i = 0;
	point = create_tuple(0, -300, 0, 1);
	translate = translation(vars->reso.width/2, vars->reso.height/2, 0);
	vars->mlx.img = mlx_new_image(vars->mlx.mlx, vars->reso.width, vars->reso.height);
	vars->mlx.address = mlx_get_data_addr(vars->mlx.img, &vars->mlx.bpp, &vars->mlx.line_leng, &vars->mlx.endian);
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win, vars->mlx.img, 0, 0);
	while (i < 24)
	{
		rotate = rotate_z(i * M_PI/12);
		printable = mult_matrix_tuple(rotate, point);
		free_matrix(rotate);
		rotate = rotate_y(degrees_to_radians(vars->degrees));
		printable = mult_matrix_tuple(rotate, printable);
		printable = mult_matrix_tuple(translate, printable);
		//printf("HOUR: %d -> point(%f, %f, %f, %d)\n", i, printable.x, printable.y, printable.z, printable.w);
		put_square(&vars->mlx, printable.x, printable.y, vars);
		free_matrix(rotate);
		i++;
	}
	free_matrix(translate);
	return(0);
}

void	test_clock(t_rt *rt)
{
	t_vars		vars;
	int			max_x;
	int			max_y;

	vars.mlx.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx.mlx, &max_x, &max_y);
	if (rt->reso.width > max_x)
		rt->reso.width = max_x;
	if (rt->reso.height > max_y)
		rt->reso.height = max_y;
	if (rt->reso.width < 1 || rt->reso.height < 1)
		errormsg(3);
	vars.mlx.win = mlx_new_window(vars.mlx.mlx, rt->reso.width, rt->reso.height, "Clock");
	vars.reso = rt->reso;
	vars.color = rt->ambi.color;
	mlx_loop_hook(vars.mlx.mlx, render_next_frame, &vars);
	free_lists(rt);
	mlx_key_hook(vars.mlx.win, close_wndw, &vars);
	mlx_loop(vars.mlx.mlx);
}