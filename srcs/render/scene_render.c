/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:51:08 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/12 19:46:56 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	prepare_computations(t_comps *comps, t_rt *rt, t_raycaster *rc)
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

t_rgba	shade_hit(t_comps comps)
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
