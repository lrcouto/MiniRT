/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:37:55 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/05 19:44:56 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void			init_ltargs(t_ltargs *args, t_rt *rt, t_raycaster *rc)
{
	t_light *lt;

	args->pos = ray_position(rc->ray, rc->hit->t1);
	lt = rt->light;
	args->light = *lt;
	args->phong = rc->hit->poly.sphere->phong;
	args->eye_v = negate_tuple(rc->ray.direction);
	args->normal_v = sphere_normal(rc->hit->poly.sphere, args->pos);
}

void				cast_pixel(t_raycaster *rc, t_rt *rt, t_mlx *mlx)
{
	t_color		color;
	t_rgba		lt_output;
	t_ltargs	args;

	if (rc->hit)
	{
		init_ltargs(&args, rt, rc);
		lt_output = lighting(args);
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
			intersect_sphere(rc.ray, rt->sphere, rc.intersec_list);
			rc.hit = intersec_hit(rc.intersec_list);
			cast_pixel(&rc, rt, mlx);
			free_intersecs(rc.intersec_list);
			rc.x = rc.x + 1;
		}
		rc.y = rc.y + 1;
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
	raycaster(rt, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	free_lists(rt);
	mlx_hook(mlx.win, 17, 1L << 17, close_program, 0);
	mlx_key_hook(mlx.win, close_wndw, &mlx);
	mlx_loop(mlx.mlx);
}
