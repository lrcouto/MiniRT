/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:11:41 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/30 16:10:00 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void				cast_pixel(t_raycaster *rc, t_rt *rt, t_mlx *mlx)
{
	t_color		color;
	t_rgba		lt_output;
	t_comps		comps;
	int			bounce_limit;

	bounce_limit = rt->ray_bounce;
	if (rc->hit)
	{
		prepare_computations(&comps, rt, rc);
		lt_output = shade_hit(comps, rt, bounce_limit);
		normalize_pixel_color(&lt_output);
		color = denorm_color(lt_output);
		if (rc->y <= rt->reso.height && rc->x <= rt->reso.width
		&& rc->x >= 0 && rc->y >= 0)
			ft_pixelput(mlx, rc->x, rc->y,
			create_trgb(0, color.r, color.g, color.b));
	}
	else
		ft_pixelput(mlx, rc->x, rc->y, create_trgb(0, 0, 0, 0));
}

void				raycaster(t_rt *rt, t_mlx *mlx)
{
	t_raycaster	rc;

	rc.y = 0;
	while (rc.y < rt->reso.height)
	{
		rc.x = 0;
		while (rc.x < rt->reso.width)
		{
			rc.intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
			rc.intersec_list = init_intersec_list(rc.intersec_list);
			rc.ray = ray_for_pixel(rt->cam, rc.x, rc.y);
			intersect_all_polys(rt, &rc);
			rc.hit = intersec_hit(rc.intersec_list);
			cast_pixel(&rc, rt, mlx);
			free_intersecs(rc.intersec_list);
			rc.x = rc.x + 1;
		}
		rc.y = rc.y + 1;
		loading_bar(rc.y / rt->reso.height, rt->reso.height);
	}
}

void				canvas(t_rt *rt)
{
	t_mlx	mlx;
	int		max_x;
	int		max_y;

	mlx.mlx = mlx_init();
	mlx_get_screen_size(mlx.mlx, &max_x, &max_y);
	if (rt->reso.width > max_x)
		rt->reso.width = max_x;
	if (rt->reso.height > max_y)
		rt->reso.height = max_y;
	if (rt->reso.width < 1 || rt->reso.height < 1)
		errormsg(3);
	mlx.win = mlx_new_window(mlx.mlx, rt->reso.width,
	rt->reso.height, "MiniRT");
	mlx.img = mlx_new_image(mlx.mlx, rt->reso.width, rt->reso.height);
	mlx.address = mlx_get_data_addr(mlx.img, &mlx.bpp,
	&mlx.line_leng, &mlx.endian);
	if (rt->savefile == 1)
		create_file("savedimage");
	raycaster(rt, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	free_lists(rt);
	mlx_hook(mlx.win, 17, 1L << 17, close_program, 0);
	mlx_key_hook(mlx.win, close_wndw, &mlx);
	mlx_loop(mlx.mlx);
}
