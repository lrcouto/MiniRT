/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:37:55 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/31 20:56:18 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void			raycaster(t_rt *rt, t_mlx *mlx)
{
	int		x;
	int		y;
	double	world_x;
	double	world_y;
	double	pixelsize;
	double	wall_size;
	t_ray	ray;
	t_intersec	*intersec_list;
	t_intersec	*hit;

	wall_size = rt->reso.width;
	pixelsize = (double)wall_size / (double)rt->reso.width;
	ray.origin = create_tuple(0, 0, -1.01, 1);
	y = 0;
	while (y < rt->reso.height)
	{
		world_y = ((wall_size / 2) - (pixelsize * y));
		x = 0;
		while (x < rt->reso.width)
		{
			intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
			intersec_list = init_intersec_list(intersec_list);

			world_x = (((wall_size / 2) * -1) + (pixelsize * x));
			ray.direction = normalize_v(subtract_tuple(create_tuple(world_x, world_y, 10, 1), ray.origin));
			// set_transform_sphere(rt->sphere, scaling(1, 1, 1));
			intersect_sphere(ray, rt->sphere, intersec_list);
			hit = intersec_hit(intersec_list);
			// printf("\nX: %d, Y: %d\n", x, y);
			if (hit)
			{
				// printf("\nHIT! T1: %f, T2: %f\n", hit->t1, hit->t2);
				if (y <= rt->reso.height && x <= rt->reso.width && x >= 0 && y >= 0)
					ft_pixelput(mlx, x, y, create_trgb(0, hit->poly.sphere->color.r, hit->poly.sphere->color.g, hit->poly.sphere->color.b));
			}
			free_intersecs(intersec_list);
			x++;
		}
		y++;
	}
}

void			canvas(t_rt *rt)
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
	mlx.address = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_leng, &mlx.endian);
	
	raycaster(rt, &mlx);
	
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	free_lists(rt);
	mlx_key_hook(mlx.win, close_wndw, &mlx);
	mlx_loop(mlx.mlx);
}