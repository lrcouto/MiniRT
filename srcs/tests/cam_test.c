/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrcouto <lrcouto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:41:58 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/12/29 19:07:311 by lrcouto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ray_for_pixel_cam_test(t_rt *rt)
{
	t_cam	*cam;
	t_ray	ray;
	t_matrix	rot;
	t_matrix	trans;

	cam = (t_cam *)ec_malloc(sizeof(t_cam));
	cam->fov = M_PI / 2;
	cam->transform = create_id_matrix();
	camera_pixel_size(rt, cam);

	ray = ray_for_pixel(cam, 100, 50);
	printf("\nRAY 1 -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);
	printf("\nRAY 1 -> direction(%f, %f, %f, %d)\n", ray.direction.x, ray.direction.y, ray.direction.z, ray.direction.w);

	ray = ray_for_pixel(cam, 0, 0);
	printf("\nRAY 2 -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);
	printf("\nRAY 2 -> direction(%f, %f, %f, %d)\n", ray.direction.x, ray.direction.y, ray.direction.z, ray.direction.w);

	free_matrix(cam->transform);
	rot = rotate_y(M_PI / 4);
	trans = translation(0, -2, 5);
	cam->transform = mult_matrix(rot, trans);
	ray = ray_for_pixel(cam, 100, 50);
	printf("\nRAY 3 -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);
	printf("\nRAY 3 -> direction(%f, %f, %f, %d)\n", ray.direction.x, ray.direction.y, ray.direction.z, ray.direction.w);

	free_matrix(rot);
	free_matrix(trans);
	free_matrix(cam->transform);
	free(cam);
}