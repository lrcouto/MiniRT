/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:51:08 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/13 18:50:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void			prepare_computations(t_comps *comps, t_rt *rt, t_raycaster *rc)
{
	comps->light = rt->light;
	comps->phong = rc->hit->poly.sphere->phong;
	comps->t = rc->hit->t;
	comps->poly = rc->hit->poly;
	comps->position = ray_position(rc->ray, comps->t);
	comps->eye_vec = negate_tuple(rc->ray.direction);
	comps->normal_vec = sphere_normal(comps->poly.sphere, comps->position);
	if (dot_product(comps->normal_vec, comps->eye_vec) < 0)
	{
		comps->inside = 1;
		comps->normal_vec = negate_tuple(comps->normal_vec);
	}
	else
		comps->inside = 0;
}

t_rgba			shade_hit(t_comps comps)
{
	t_light	*lt;
	t_rgba	lt_color;

	lt = comps.light;
	lt_color = lighting(comps, lt);
	lt = lt->next;
	while (lt)
	{
		lt_color = add_color(lt_color, lighting(comps, lt));
		lt = lt->next;
	}
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
