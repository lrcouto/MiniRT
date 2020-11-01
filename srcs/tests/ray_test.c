/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:52:19 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/31 19:53:07 by lcouto           ###   ########.fr       */
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
	t_intersec	*intersec_list;
	t_intersec	*hit;

	intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
	intersec_list = init_intersec_list(intersec_list);

	sphere.center = rt->sphere->center;
	sphere.diameter = rt->sphere->diameter;
	sphere.radius = rt->sphere->radius;
	
	printf("\nRAY-SPHERE INTERSECTION\n");
	printf("\nSPHERE-CENTER -> point(%f, %f, %f, %d)\n", sphere.center.x, sphere.center.y, sphere.center.z, sphere.center.w);

	// RAY 1
	ray = create_ray(create_tuple(1, 0, -13, 1), create_tuple(0, 0, 1, 0));
	intersect_sphere(ray, &sphere, intersec_list);
	printf("\nRAY 1 -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);

	// RAY 2
	ray = create_ray(create_tuple(0, 1, -10, 1), create_tuple(0, 0, 1, 0));
	intersect_sphere(ray, &sphere, intersec_list);
	printf("\nRAY 2 -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);

	// RAY 3
	ray = create_ray(create_tuple(-1, 0, -8, 1), create_tuple(0, 0, 1, 0));
	intersect_sphere(ray, &sphere, intersec_list);
	printf("\nRAY 3 -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);

	// RAY 4
	ray = create_ray(create_tuple(0.5, 0.5, -15, 1), create_tuple(0, 0, 1, 0));
	intersect_sphere(ray, &sphere, intersec_list);
	printf("\nRAY 4 -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);

	hit = intersec_hit(intersec_list);

	if (!hit)
		printf("NO HIT!\n");
	else 
		printf("HIT! T1: %f, T2: %f\n", hit->t1, hit->t2);

	free_intersecs(intersec_list);
}

void	test_transform_ray(void)
{
	t_ray		ray;
	t_ray		new;
	t_matrix	matrix;

	ray.origin = create_tuple(1, 2, 3, 1);
	ray.direction = create_tuple(0, 1, 0, 0);
	matrix = translation(3, 4, 5);
	new = transform_ray(ray, matrix);
	printf("\nOG RAY -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);
	printf("\nOG RAY -> direction(%f, %f, %f, %d)\n", ray.direction.x, ray.direction.y, ray.direction.z, ray.direction.w);
	printf("\nNEW RAY - TRANSLATE -> origin(%f, %f, %f, %d)\n", new.origin.x, new.origin.y, new.origin.z, new.origin.w);
	printf("\nNEW RAY - TRANSLATE -> direction(%f, %f, %f, %d)\n", new.direction.x, new.direction.y, new.direction.z, new.direction.w);
	free_matrix(matrix);
	matrix = scaling(2, 3, 4);
	new = transform_ray(ray, matrix);
	printf("\nNEW RAY - SCALING -> origin(%f, %f, %f, %d)\n", new.origin.x, new.origin.y, new.origin.z, new.origin.w);
	printf("\nNEW RAY - SCALING -> direction(%f, %f, %f, %d)\n", new.direction.x, new.direction.y, new.direction.z, new.direction.w);
	free_matrix(matrix);
}

void	test_sphere_ray_transform(t_rt *rt)
{
	t_ray		ray;
	t_sphere	sphere;
	t_intersec	*intersec_list;

	intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
	intersec_list = init_intersec_list(intersec_list);

	sphere.center = rt->sphere->center;
	sphere.diameter = rt->sphere->diameter;
	sphere.radius = rt->sphere->radius;
	sphere.transform = rt->sphere->transform;

	ray.origin = create_tuple(0, 0, -5, 1);
	ray.direction = create_tuple(0, 0, 1, 0);
	printf("\nOG RAY -> origin(%f, %f, %f, %d)\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);
	printf("\nOG RAY -> direction(%f, %f, %f, %d)\n", ray.direction.x, ray.direction.y, ray.direction.z, ray.direction.w);

	set_transform_sphere(&sphere, scaling(2, 2, 2));
	intersect_sphere(ray, &sphere, intersec_list);

	set_transform_sphere(&sphere, translation(5, 0, 0));
	intersect_sphere(ray, &sphere, intersec_list);
	
	free_matrix(sphere.transform);
	free_intersecs(intersec_list);
}

void	test_canvas(t_rt *rt)
{
	t_ray	ray;
	t_intersec	*intersec_list;

	intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
	intersec_list = init_intersec_list(intersec_list);
	ray.origin = create_tuple(0, 0, -5, 1);
	ray.direction = create_tuple(-0.1924500, 0.1924500, 0.9622504, 0);
	intersect_sphere(ray, rt->sphere, intersec_list);

	free_intersecs(intersec_list);
}