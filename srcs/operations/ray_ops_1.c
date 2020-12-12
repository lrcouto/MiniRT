/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:45:27 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/12 19:40:57 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray				create_ray(t_tuple origin, t_tuple direction)
{
	t_ray new;

	new.origin = origin;
	new.direction = direction;
	return (new);
}

t_tuple				ray_position(t_ray ray, double t)
{
	return (add_tuple(ray.origin, scalar_x_tuple(ray.direction, t)));
}

static void			create_intersec(double *vals, t_intersec *head,
t_sphere *sphere)
{
	t_intersec	intersec1;
	t_intersec	intersec2;

	if (vals[2] >= 0)
	{
		intersec1.count = 2;
		intersec2.count = 2;
		intersec1.t = (((-1 * vals[1]) - sqrt(vals[2])) / (2 * vals[0]));
		intersec2.t = (((-1 * vals[1]) + sqrt(vals[2])) / (2 * vals[0]));
		intersec1.poly = insert_sphere(sphere);
		intersec2.poly = insert_sphere(sphere);
		push_intersec(head, &intersec1);
		push_intersec(head, &intersec2);
	}
}

static void			get_intersec(t_ray ray, t_tuple sphere_to_ray,
t_intersec *head, t_sphere *sphere)
{
	double		dot;
	double		vals[3];

	vals[0] = dot_product(ray.direction, ray.direction);
	vals[1] = 2 * dot_product(ray.direction, sphere_to_ray);
	dot = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	vals[2] = ((vals[1] * vals[1]) - (4 * vals[0] * dot));
	create_intersec(vals, head, sphere);
}

void				intersect_sphere(t_ray ray, t_sphere *sphere,
t_intersec *head)
{
	t_tuple			sphere_to_ray;
	t_ray			tformed;
	t_matrix		invert;

	invert = invert_matrix(sphere->transform);
	tformed = transform_ray(ray, invert);
	free_matrix(invert);
	sphere_to_ray = subtract_tuple(tformed.origin, sphere->center);
	get_intersec(tformed, sphere_to_ray, head, sphere);
}
