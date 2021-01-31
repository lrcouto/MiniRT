/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:51:08 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/10 17:225:05 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	get_poly_props(t_polys poly, t_comps *comps)
{
	if (poly.obj_type == SPHERE)
	{
		comps->normal_vec = normal_at(poly.sphere->transform, comps->position, poly);
		comps->phong = poly.sphere->phong;
	}
	if (poly.obj_type == PLANE)
	{
		comps->normal_vec = normal_at(poly.plane->transform, comps->position, poly);
		comps->phong = poly.plane->phong;
	}
	if (poly.obj_type == SQUARE)
	{
		comps->normal_vec = normal_at(poly.square->transform, comps->position, poly);
		comps->phong = poly.square->phong;
	}
	// if (poly.obj_type == CYLINDER)
	// 	return normal_at(poly.cylinder->transform, position);
	// if (poly.obj_type == TRIANGLE)
	// 	return normal_at(poly.triangle->transform, position);
}

void			 prepare_computations(t_comps *comps, t_rt *rt, t_raycaster *rc)
{
	comps->light = rt->light;
	comps->t = rc->hit->t;
	comps->poly = rc->hit->poly;
	comps->position = ray_position(rc->ray, comps->t);
	comps->eye_vec = negate_tuple(rc->ray.direction);
	// checar type do poly para pegar a normal correta
	get_poly_props(comps->poly, comps);
	if (dot_product(comps->normal_vec, comps->eye_vec) < 0)
	{
		comps->inside = 1;
		comps->normal_vec = negate_tuple(comps->normal_vec);
	}
	else
		comps->inside = 0;
	comps->reflect_vec = reflect(rc->ray.direction, comps->normal_vec);
	comps->over_point = add_tuple(comps->position,
		scalar_x_tuple(comps->normal_vec, EPSILON));
}

t_rgba			shade_hit(t_comps comps, t_rt *rt, int bounce)
{
	t_light	*lt;
	t_rgba	lt_color;

	lt = comps.light;
	lt_color = lighting(comps, lt, is_shadowed(comps, rt, lt));
	lt = lt->next;
	while (lt)
	{
		lt_color = add_color(lt_color, lighting(comps, lt, is_shadowed(comps, rt, lt)));
		lt = lt->next;
	}
	lt_color = add_color(lt_color, reflect_color(comps, rt, bounce));
	return (lt_color);
}

static t_matrix	calculate_orientation(t_tuple left, t_tuple true_up,
t_tuple forward, t_tuple from)
{
	t_matrix	temp;
	t_matrix	translate;
	t_matrix	orientation;

	temp = create_matrix(4, 4);
	temp.matrix[0][0] = left.x;
	temp.matrix[0][1] = left.y;
	temp.matrix[0][2] = left.z;
	temp.matrix[1][0] = true_up.x;
	temp.matrix[1][1] = true_up.y;
	temp.matrix[1][2] = true_up.z;
	temp.matrix[2][0] = -1.0 * forward.x;
	temp.matrix[2][1] = -1.0 * forward.y;
	temp.matrix[2][2] = -1.0 * forward.z;
	temp.matrix[3][3] = 1.0;
	translate = translation(-1.0 * from.x, -1.0 * from.y, -1.0 * from.z);
	orientation = mult_matrix(temp, translate);
	free_matrix(temp);
	free_matrix(translate);
	return (orientation);
}

t_matrix		view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		up_normal;
	t_tuple		left;
	t_tuple		true_up;

	forward = normalize_v(subtract_tuple(to, from));
	up_normal = normalize_v(up);
	left = cross_product(forward, up_normal);
	true_up = cross_product(left, forward);
	return (calculate_orientation(left, true_up, forward, from));
}
