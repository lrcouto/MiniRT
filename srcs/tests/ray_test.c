/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:52:19 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/24 20:52:05 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	test_ray_position(void)
{
	t_tuple	origin;
	t_tuple	direction;
	t_tuple	position;
	t_ray	ray;

	origin = create_tuple(2, 3, 4, 1);
	direction = create_tuple(1, 0, 0, 0);

	ray = create_ray(origin, direction);

	printf("\nRAY POSITION\n");
	position = ray_position(ray, 0);
	printf("TIME: 0 -> point(%f, %f, %f, %d)", position.x, position.y, position.z, position.w);
	printf("\n");

	position = ray_position(ray, 1);
	printf("TIME: 1 -> point(%f, %f, %f, %d)", position.x, position.y, position.z, position.w);
	printf("\n");

	position = ray_position(ray, -1);
	printf("TIME: -1 -> point(%f, %f, %f, %d)", position.x, position.y, position.z, position.w);
	printf("\n");

	position = ray_position(ray, 2.5);
	printf("TIME: 2.5 -> point(%f, %f, %f, %d)", position.x, position.y, position.z, position.w);
	printf("\n");
}

void	test_intersection(t_rt *rt)
{
	t_ray		ray;
	t_sphere	sphere;
	t_intersec	new;

	ray = create_ray(create_tuple(0, 0, 0, 1), create_tuple(0, 0, 1, 0));
	sphere.center = rt->sphere->center;
	sphere.diameter = rt->sphere->diameter;
	sphere.radius = rt->sphere->radius;

	new = intersect_sphere(ray, sphere);
	printf("\nRAY-SPHERE INTERSECTION\n");
	printf("\nRAY -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);
	printf("\nRAY -> direction(%f, %f, %f, %d)\n", ray.direction.x, ray.direction.y, ray.direction.z, ray.direction.w);
	printf("\nSPHERE-CENTER -> point(%f, %f, %f, %d)\n", sphere.center.x, sphere.center.y, sphere.center.z, sphere.center.w);
	printf("COUNT: %d, T1: %f, T2: %f\n", new.count, new.t1, new.t2);
	free(new.poly.sphere);
}
