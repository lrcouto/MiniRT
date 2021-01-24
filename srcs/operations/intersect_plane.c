/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:05:02 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/24 17:10:25 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void			create_intersec(double t, t_intersec *head,
t_plane *plane)
{
	t_intersec	intersec1;

	if (t > 0)
	{
		intersec1.count = 1;
		intersec1.t = t;
		intersec1.poly = insert_plane(plane);
		push_intersec(head, &intersec1);
	}
}

// static void			get_intersec(t_ray ray, t_tuple plane_to_ray,
// t_intersec *head, t_plane *plane)
// {
// 	double		dot;
// 	double		vals[3];

// 	vals[0] = dot_product(ray.direction, ray.direction);
// 	vals[1] = 2 * dot_product(ray.direction, plane_to_ray);
// 	dot = dot_product(plane_to_ray, plane_to_ray) - 1;
// 	vals[2] = ((vals[1] * vals[1]) - (4 * vals[0] * dot));
// 	create_intersec(vals, head, plane);
// }

void				intersect_plane(t_ray ray, t_plane *plane,
t_intersec *head)
{
	double			t;
	t_ray			tformed;
	t_matrix		invert;

	if (fabs(ray.direction.y) < EPSILON)
		return;

	invert = invert_matrix(plane->transform); // maybe invert when sphere its created
	tformed = transform_ray(ray, invert);
	free_matrix(invert);
	t = (-1 * tformed.origin.y) / tformed.direction.y;
	create_intersec(t, head, plane);
}