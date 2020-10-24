/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:48:46 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/24 20:40:21 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_polys		insert_sphere(t_sphere *sphere)
{
	t_polys poly;

	poly.obj_type = 0;
	poly.sphere = (t_sphere *)ec_malloc(sizeof(t_sphere));
	poly.sphere->center = sphere->center;
	poly.sphere->color = sphere->color;
	poly.sphere->diameter = sphere->diameter;
	poly.sphere->radius = sphere->radius;
	poly.sphere->next = sphere->next;

	return (poly);
}

t_polys		insert_plane(t_plane *plane)
{
	t_polys poly;

	poly.obj_type = 1;
	poly.plane = plane;

	return (poly);
}

t_polys		insert_square(t_square *square)
{
	t_polys poly;

	poly.obj_type = 2;
	poly.square = square;

	return (poly);
}

t_polys		insert_cylinder(t_cylinder *cylinder)
{
	t_polys poly;

	poly.obj_type = 3;
	poly.cylinder = cylinder;

	return (poly);
}

t_polys		insert_triangle(t_triangle *triangle)
{
	t_polys poly;

	poly.obj_type = 4;
	poly.triangle = triangle;

	return (poly);
}