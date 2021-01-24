/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polys_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:39:51 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/24 19:41:46 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_matrix		normal_rotation_matrix(t_tuple normal)
{
	double		angle;
	double		vals[3];
	t_tuple		axis;
	t_matrix	rotation;

	rotation = create_matrix(4, 4);
	angle = acos(dot_product(normal, create_tuple(0, 1, 0, 0)));
	axis = cross_product(normal, create_tuple(0, 1, 0, 0));
	vals[0] = cos(angle);
	vals[1] = sin(angle);
	vals[2] = 1.0 - vals[0];
	rotation.matrix[0][0] = vals[0] + (pow(axis.x, 2) * vals[2]);
	rotation.matrix[0][1] = (axis.x * axis.y * vals[2]) - (axis.z * vals[1]);
	rotation.matrix[0][2] = (axis.x * axis.z * vals[2]) + (axis.y * vals[1]);
	rotation.matrix[1][0] = (axis.y * axis.z * vals[2]) + (axis.z * vals[1]);
	rotation.matrix[1][1] = vals[0] + (pow(axis.y, 2) * vals[2]);
	rotation.matrix[1][2] = (axis.y * axis.z * vals[2]) - (axis.x * vals[1]);
	rotation.matrix[2][0] = (axis.z * axis.x * vals[2]) - (axis.y * vals[1]);
	rotation.matrix[2][1] = (axis.z * axis.y * vals[2]) + (axis.x * vals[1]);
	rotation.matrix[2][2] = vals[0] + (pow(axis.z, 2) * vals[2]);
	rotation.matrix[3][3] = 1;
	return (rotation);
}

void				render_sphere_transform(t_sphere *sphere)
{
	t_matrix	translate;
	t_matrix	scale;
	t_matrix	transform;

	translate = translation(sphere->center.x,
		sphere->center.y, sphere->center.z);
	scale = scaling(sphere->radius, sphere->radius, sphere->radius);
	transform = mult_matrix(scale, translate);
	sphere->transform = transform;
	free_matrix(translate);
	free_matrix(scale);
}

void				render_plane_transform(t_plane *plane)
{
	t_matrix	translate;
	t_matrix	rotate;
	t_matrix	transform;

	translate = translation(plane->pos.x,
		plane->pos.y, plane->pos.z);
	rotate = normal_rotation_matrix(plane->norm);
	transform = mult_matrix(translate, rotate);
	plane->transform = transform;
	free_matrix(translate);
	free_matrix(rotate);
}