/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:05:02 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/10 19:19:40 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void			create_intersec(double *vals, t_intersec *head,
t_plane *plane)
{
	t_intersec	intersec1;
	t_intersec	intersec2;

	if (vals[2] >= 0)
	{
		intersec1.count = 2;
		intersec2.count = 2;
		intersec1.t = (((-1 * vals[1]) - sqrt(vals[2])) / (2 * vals[0]));
		intersec2.t = (((-1 * vals[1]) + sqrt(vals[2])) / (2 * vals[0]));
		intersec1.poly = insert_plane(plane);
		intersec2.poly = insert_plane(plane);
		push_intersec(head, &intersec1);
		push_intersec(head, &intersec2);
	}
}

static void			get_intersec(t_ray ray, t_tuple plane_to_ray,
t_intersec *head, t_plane *plane)
{
	double		dot;
	double		vals[3];

	vals[0] = dot_product(ray.direction, ray.direction);
	vals[1] = 2 * dot_product(ray.direction, plane_to_ray);
	dot = dot_product(plane_to_ray, plane_to_ray) - 1;
	vals[2] = ((vals[1] * vals[1]) - (4 * vals[0] * dot));
	create_intersec(vals, head, plane);
}

void				intersect_plane(t_ray ray, t_plane *plane,
t_intersec *head)
{
	t_tuple			plane_to_ray;
	t_ray			tformed;
	t_matrix		invert;

	invert = invert_matrix(plane->transform); // maybe invert when plane its created
	tformed = transform_ray(ray, invert);
	free_matrix(invert);
	plane_to_ray = subtract_tuple(tformed.origin, create_tuple(0, 0, 0, 1));
	get_intersec(tformed, plane_to_ray, head, plane);
}