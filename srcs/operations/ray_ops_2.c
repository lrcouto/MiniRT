/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:48:46 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/06 21:54:17 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_polys		insert_sphere(t_sphere *sphere)
{
	t_polys poly;

	poly.obj_type = SPHERE;
	poly.sphere = (t_sphere *)ec_malloc(sizeof(t_sphere));
	poly.sphere->center = sphere->center;
	poly.sphere->color = sphere->color;
	poly.sphere->diameter = sphere->diameter;
	poly.sphere->radius = sphere->radius;
	poly.sphere->transform = sphere->transform;
	poly.sphere->phong = sphere->phong;
	poly.sphere->next = sphere->next;
	return (poly);
}

t_polys		insert_plane(t_plane *plane)
{
	t_polys poly;

	poly.obj_type = PLANE;
	poly.plane = (t_plane *)ec_malloc(sizeof(t_plane));
	poly.plane->color = plane->color;
	poly.plane->norm = plane->norm;
	poly.plane->phong = plane->phong;
	poly.plane->pos = plane->pos;
	poly.plane->transform = plane->transform;
	poly.plane->next = plane->next;
	return (poly);
}

t_polys		insert_square(t_square *square)
{
	t_polys poly;

	poly.obj_type = SQUARE;
	poly.square = (t_square *)ec_malloc(sizeof(t_square));
	poly.square->color = square->color;
	poly.square->norm = square->norm;
	poly.square->phong = square->phong;
	poly.square->center = square->center;
	poly.square->side = square->side;
	poly.square->transform = square->transform;
	poly.square->next = square->next;
	return (poly);
}

t_polys		insert_cylinder(t_cylinder *cylinder)
{
	t_polys poly;

	poly.obj_type = CYLINDER;
	poly.cylinder = (t_cylinder *)ec_malloc(sizeof(t_cylinder));
	poly.cylinder->pos = cylinder->pos;
	poly.cylinder->norm = cylinder->norm;
	poly.cylinder->diameter = cylinder->diameter;
	poly.cylinder->radius = cylinder->radius;
	poly.cylinder->height = cylinder->height;
	poly.cylinder->color = cylinder->color;
	poly.cylinder->phong = cylinder->phong;
	poly.cylinder->transform = cylinder->transform;
	poly.cylinder->next = cylinder->next;
	return (poly);
}

t_polys		insert_triangle(t_triangle *triangle)
{
	t_polys poly;

	poly.obj_type = TRIANGLE;
	poly.triangle = (t_triangle *)ec_malloc(sizeof(t_triangle));
	poly.triangle->color = triangle->color;
	poly.triangle->p1 = triangle->p1;
	poly.triangle->p2 = triangle->p2;
	poly.triangle->p3 = triangle->p3;
	poly.triangle->edgevec_1 = triangle->edgevec_1;
	poly.triangle->edgevec_2 = triangle->edgevec_2;
	poly.triangle->transform = triangle->transform;
	poly.triangle->phong = triangle->phong;
	poly.triangle->next = triangle->next;
	return (poly);
}
