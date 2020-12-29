/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:37:55 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/29 20:13:59 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void				cast_pixel(t_raycaster *rc, t_rt *rt, t_mlx *mlx)
{
	t_color		color;
	t_rgba		lt_output;
	t_comps		comps;

	if (rc->hit)
	{
		prepare_computations(&comps, rt, rc);
		lt_output = shade_hit(comps);
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

static void			init_raycaster(t_raycaster *rc, t_rt *rt)
{
	rc->wall_size = 20;
	rc->pixel_size = (double)rc->wall_size / (double)rt->reso.width;
	rc->ray.origin = create_tuple(rt->cam->view.x,
		rt->cam->view.y, rt->cam->view.z, 1);
	rc->y = 0;
	rc->x = 0;
	rc->world_x = 0;
	rc->world_y = 0;
}

static void			intersect_all_spheres(t_rt *rt, t_raycaster *rc)
{
	t_sphere	*current_sphere;

	current_sphere = rt->sphere;
	while (current_sphere)
	{
		intersect_sphere(rc->ray, current_sphere, rc->intersec_list);
		current_sphere = current_sphere->next;
	}
}

void				raycaster(t_rt *rt, t_mlx *mlx)
{
	t_raycaster	rc;

	init_raycaster(&rc, rt);
	render_sphere_transform(rt->sphere);
	while (rc.y < rt->reso.height)
	{
		rc.world_y = ((rc.wall_size / 2) - (rc.pixel_size * rc.y));
		rc.x = 0;
		while (rc.x < rt->reso.width)
		{
			rc.intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
			rc.intersec_list = init_intersec_list(rc.intersec_list);
			rc.world_x = (((rc.wall_size / 2) * -1) + (rc.pixel_size * rc.x));
			rc.ray.direction = normalize_v(subtract_tuple(create_tuple(
				rc.world_x, rc.world_y, 10, 1), rc.ray.origin));
			intersect_all_spheres(rt, &rc);
			rc.hit = intersec_hit(rc.intersec_list);
			cast_pixel(&rc, rt, mlx);
			free_intersecs(rc.intersec_list);
			rc.x = rc.x + 1;
		}
		rc.y = rc.y + 1;
	}
}

/*
** void				render(t_rt *rt, t_mlx *mlx)
** {
** 	int x;
** 	int y;
** 
** 	x = 0;
** 	y = 0;
** 	while (y < rt->reso.height)
** 	{
** 		x = 0;
** 		while (x < rt->reso.width)
** 		{
** 
** 		}
** 	}
** }
*/

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
	raycaster(rt, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	free_lists(rt);
	mlx_hook(mlx.win, 17, 1L << 17, close_program, 0);
	mlx_key_hook(mlx.win, close_wndw, &mlx);
	mlx_loop(mlx.mlx);
}
