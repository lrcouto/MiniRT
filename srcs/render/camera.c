/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:27:50 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 18:35:14 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	camera_pixel_size(t_rt *rt, t_cam *cam)
{
	double	half_view;
	double	aspect;
	double	rad;

	rad = degrees_to_radians(cam->fov);
	half_view = tan(rad / 2);
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

t_ray	ray_for_pixel(t_cam *cam, int x, int y)
{
	double		x_offset;
	double		y_offset;
	t_tuple		direction;

	x_offset = (x + 0.5) * cam->pixel_size;
	y_offset = (y + 0.5) * cam->pixel_size;
	direction = normalize_v(subtract_tuple(mult_matrix_tuple(cam->transform,
		create_tuple(cam->half_width - x_offset,
		cam->half_height - y_offset, -1, 1)), cam->origin));
	return (create_ray(cam->origin, direction));
}
