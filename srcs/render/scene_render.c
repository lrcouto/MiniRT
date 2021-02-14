/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:51:08 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 17:09:07 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		set_comps_normal_and_phong(t_comps *comps, t_polys poly,
t_matrix transform, t_phong poly_phong)
{
	comps->normal_vec = normal_at(transform,
			comps->position, poly);
	comps->phong = poly_phong;
}

static void		get_poly_props(t_polys poly, t_comps *comps, t_rt *rt)
{
	if (poly.obj_type == SPHERE)
		set_comps_normal_and_phong(comps, poly, poly.sphere->transform,
			poly.sphere->phong);
	if (poly.obj_type == PLANE)
		set_comps_normal_and_phong(comps, poly, poly.plane->transform,
				poly.plane->phong);
	if (poly.obj_type == SQUARE)
		set_comps_normal_and_phong(comps, poly, poly.square->transform,
			poly.square->phong);
	if (poly.obj_type == CYLINDER)
		set_comps_normal_and_phong(comps, poly, poly.cylinder->transform,
			poly.cylinder->phong);
	if (poly.obj_type == TRIANGLE)
		set_comps_normal_and_phong(comps, poly, poly.triangle->transform,
			poly.triangle->phong);
	comps->phong.ambient = rt->ambi.light;
}

void			prepare_computations(t_comps *comps, t_rt *rt, t_raycaster *rc)
{
	comps->light = rt->light;
	comps->t = rc->hit->t;
	comps->poly = rc->hit->poly;
	comps->position = ray_position(rc->ray, comps->t);
	comps->eye_vec = negate_tuple(rc->ray.direction);
	get_poly_props(comps->poly, comps, rt);
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
		lt_color = add_color(lt_color, lighting(comps, lt,
		is_shadowed(comps, rt, lt)));
		lt = lt->next;
	}
	lt_color = add_color(lt_color, reflect_color(comps, rt, bounce));
	return (lt_color);
}
