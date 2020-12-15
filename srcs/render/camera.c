/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:27:50 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/15 17:17:09 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	camera_pixel_size(t_rt *rt, t_cam *cam)
{
	double	half_view;
	double	aspect;

	half_view = tan(cam->fov / 2);
	aspect = rt->reso.width / rt->reso.height;
	if (aspect >= 1)
	{
		cam->half_width = half_view;
		cam->half_height = half_view / aspect;
	}
	else
	{
		cam->half_width = half_view * aspect;
		cam->half_height = half_view;
	}

	cam->pixel_size = (cam->half_width * 2) / rt->reso.width;
}

t_ray	ray_for_pixel(t_rt *rt, t_raycaster *rc, int x, int y)
{
	double		x_offset;
	double		y_offset;
	t_matrix	transform;
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;

	camera_pixel_size(rt, rt->cam);
	x_offset = (x + 0.5) * rt->cam->pixel_size;
	y_offset = (y + 0.5) * rt->cam->pixel_size;
	rc->world_x = rt->cam->half_width - x_offset;
	rc->world_y = rt->cam->half_height - y_offset;
	transform = invert_matrix(rt->cam->transform);
	pixel = mult_matrix_tuple(transform, create_tuple(rc->world_x, rc->world_y, -1, 1));
	origin = mult_matrix_tuple(transform, create_tuple(0, 0, 0, 1));
	direction = normalize_v(subtract_tuple(pixel, origin));
	return (create_ray(origin, direction));
}