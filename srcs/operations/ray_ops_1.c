/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:45:27 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/31 19:34:39 by lcouto           ###   ########.fr       */
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

static t_intersec	create_intersec(double a, double b, double discriminant)
{
	t_intersec	intersec;

	if (discriminant < 0)
		intersec.count = 0;
	else
	{
		intersec.count = 2;
		intersec.t1 = (((-1 * b) - sqrt(discriminant)) / (2 * a));
		intersec.t2 = (((-1 * b) + sqrt(discriminant)) / (2 * a));
	}
	return (intersec);
}

static t_intersec	get_intersec(t_ray ray, t_tuple sphere_to_ray)
{
	double		a;
	double		b;
	double		c;
	double		discriminant;

	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(ray.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = ((b * b) - (4 * a * c));
	return (create_intersec(a, b, discriminant));
}

void				intersect_sphere(t_ray ray, t_sphere *sphere,
t_intersec *head)
{
	t_tuple		sphere_to_ray;
	t_intersec	new;
	t_ray		tformed;
	t_matrix		invert;

	invert = invert_matrix(sphere->transform);
	tformed = transform_ray(ray, invert);
	free_matrix(invert);
	sphere_to_ray = subtract_tuple(tformed.origin, sphere->center);
	new = get_intersec(tformed, sphere_to_ray);
	new.poly = insert_sphere(sphere);
	push_intersec(head, &new);
}
