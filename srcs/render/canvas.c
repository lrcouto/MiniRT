/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:11:41 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 19:08:50 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void				cast_pixel(t_raycaster *rc, t_rt *rt,
t_mlx *mlx, t_cam *cam)
{
	t_color		color;
	t_rgba		lt_output;
	t_comps		comps;
	int			bounce_limit;
	int			coord[2];

	bounce_limit = rt->ray_bounce;
	coord[0] = rc->x;
	coord[1] = rc->y;
	if (rc->hit)
	{
		prepare_computations(&comps, rt, rc);
		lt_output = shade_hit(comps, rt, bounce_limit);
		normalize_pixel_color(&lt_output);
		color = denorm_color(lt_output);
		if (rc->y <= rt->reso.height && rc->x <= rt->reso.width
		&& rc->x >= 0 && rc->y >= 0)
			ft_pixelput(cam, coord, mlx,
			create_trgb(0, color.r, color.g, color.b));
	}
	else
		ft_pixelput(cam, coord, mlx, create_trgb(0, 0, 0, 0));
}

void				raycaster(t_rt *rt, t_mlx *mlx, t_cam *cam)
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
			rc.ray = ray_for_pixel(cam, rc.x, rc.y);
			intersect_all_polys(rt, &rc);
			rc.hit = intersec_hit(rc.intersec_list);
			cast_pixel(&rc, rt, mlx, cam);
			free_intersecs(rc.intersec_list);
			rc.x = rc.x + 1;
		}
		rc.y = rc.y + 1;
		loading_bar(rc.y / rt->reso.height, rt->reso.height, rt);
	}
}

void				canvas(t_rt *rt, t_mlx *mlx)
{
	create_images(rt, mlx);
	if (rt->savefile == 1)
		exit(0);
	else
	{
		mlx->win = mlx_new_window(mlx->mlx, rt->reso.width,
		rt->reso.height, "MiniRT");
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->cam->img, 0, 0);
	}
}
