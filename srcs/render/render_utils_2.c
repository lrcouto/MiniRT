/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:46:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 17:07:13 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int					is_shadowed(t_comps comps, t_rt *rt, t_light *light)
{
	t_tuple		path;
	double		distance;
	t_raycaster	rc;
	int			result;

	path = subtract_tuple(light->pos, comps.over_point);
	distance = vector_magnitude(path);
	rc.intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
	rc.intersec_list = init_intersec_list(rc.intersec_list);
	rc.ray = create_ray(comps.over_point, normalize_v(path));
	intersect_all_polys(rt, &rc);
	rc.hit = intersec_hit(rc.intersec_list);
	if (rc.hit && rc.hit->t < distance)
		result = 1;
	else
		result = 0;
	free_intersecs(rc.intersec_list);
	return (result);
}

static t_tuple		get_cylinder_normal(t_polys poly, t_tuple o_point)
{
	double		dist;
	double		min;
	double		max;

	max = poly.cylinder->height / 2.0;
	min = -1.0 * max;
	dist = pow(o_point.x, 2) + pow(o_point.z, 2);
	if (dist < 1 && (o_point.y >= max - EPSILON))
		return (create_tuple(0, 1, 0, 0));
	else if (dist < 1 && (o_point.y <= min + EPSILON))
		return (create_tuple(0, -1, 0, 0));
	else
		return (create_tuple(o_point.x, 0, o_point.z, 0));
}

t_tuple				normal_object_type(t_polys poly, t_tuple o_point)
{
	if (poly.obj_type == SPHERE)
		return (subtract_tuple(o_point, create_tuple(0, 0, 0, 1)));
	else if (poly.obj_type == PLANE)
		return (create_tuple(0, 1, 0, 0));
	else if (poly.obj_type == SQUARE)
		return (create_tuple(0, 1, 0, 0));
	else if (poly.obj_type == CYLINDER)
		return (get_cylinder_normal(poly, o_point));
	else if (poly.obj_type == TRIANGLE)
		return (normalize_v(cross_product(poly.triangle->edgevec_2,
		poly.triangle->edgevec_1)));
	else
		return (create_tuple(0, 0, 0, 0));
}

t_rgba				color_at(t_rt *rt, t_ray ray, int bounce)
{
	t_raycaster	rc;
	t_rgba		color;
	t_comps		comps;

	rc.intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
	rc.intersec_list = init_intersec_list(rc.intersec_list);
	rc.ray = ray;
	intersect_all_polys(rt, &rc);
	rc.hit = intersec_hit(rc.intersec_list);
	if (rc.hit)
	{
		prepare_computations(&comps, rt, &rc);
		color = shade_hit(comps, rt, bounce);
		normalize_pixel_color(&color);
	}
	else
		color = create_rgba(0, 0, 0, 0);
	free_intersecs(rc.intersec_list);
	return (color);
}

t_rgba				reflect_color(t_comps comps, t_rt *rt, int bounce)
{
	t_ray	reflect_ray;
	t_rgba	color;

	if (comps.phong.reflect == 0 || bounce <= 0)
		return (create_rgba(0, 0, 0, 0));
	reflect_ray = create_ray(comps.over_point, comps.reflect_vec);
	color = color_at(rt, reflect_ray, bounce - 1);
	return (scalar_color(color, comps.phong.reflect));
}
