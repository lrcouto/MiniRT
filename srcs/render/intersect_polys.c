/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_polys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:31:04 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 17:07:13 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void			intersect_all_spheres(t_rt *rt, t_raycaster *rc)
{
	t_sphere	*current_sphere;

	current_sphere = rt->sphere;
	while (current_sphere)
	{
		intersect_sphere(rc->ray, current_sphere, rc->intersec_list);
		current_sphere = current_sphere->next;
	}
}

void			intersect_all_planes(t_rt *rt, t_raycaster *rc)
{
	t_plane	*current_plane;

	current_plane = rt->plane;
	while (current_plane)
	{
		intersect_plane(rc->ray, current_plane, rc->intersec_list);
		current_plane = current_plane->next;
	}
}

void			intersect_all_squares(t_rt *rt, t_raycaster *rc)
{
	t_square	*current_square;

	current_square = rt->square;
	while (current_square)
	{
		intersect_square(rc->ray, current_square, rc->intersec_list);
		current_square = current_square->next;
	}
}

void			intersect_all_cylinders(t_rt *rt, t_raycaster *rc)
{
	t_cylinder	*current_cylinder;

	current_cylinder = rt->cylinder;
	while (current_cylinder)
	{
		intersect_cylinder(rc->ray, current_cylinder, rc->intersec_list);
		current_cylinder = current_cylinder->next;
	}
}

void			intersect_all_triangles(t_rt *rt, t_raycaster *rc)
{
	t_triangle	*current_triangle;

	current_triangle = rt->triangle;
	while (current_triangle)
	{
		intersect_triangle(rc->ray, current_triangle, rc->intersec_list);
		current_triangle = current_triangle->next;
	}
}
