/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:27:50 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/29 20:20:54 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	camera_pixel_size(t_rt *rt, t_cam *cam)
{
	double	half_view;
	double	aspect;

	half_view = tan(cam->fov / 2);
	aspect = (double)rt->reso.width / (double)rt->reso.height;
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

t_ray	ray_for_pixel(t_rt *rt, t_cam *cam, int x, int y)
{
	double		x_offset;
	double		y_offset;
	t_matrix	transform;
	t_tuple		origin;
	t_tuple		direction;

	camera_pixel_size(rt, cam);
	x_offset = (x + 0.5) * cam->pixel_size;
	y_offset = (y + 0.5) * cam->pixel_size;
	transform = invert_matrix(cam->transform);
	origin = mult_matrix_tuple(transform, create_tuple(0, 0, 0, 1));
	direction = normalize_v(subtract_tuple(mult_matrix_tuple(transform,
		create_tuple(cam->half_width - x_offset,
		cam->half_height - y_offset, -1, 1)), origin));
	free_matrix(transform);
	return (create_ray(origin, direction));
}
