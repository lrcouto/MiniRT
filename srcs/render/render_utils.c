/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:52:34 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 19:51:27 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_tuple		normal_at(t_matrix transform, t_tuple w_point, t_polys poly)
{
	t_tuple		o_point;
	t_tuple		o_normal;
	t_tuple		w_normal;
	t_matrix	inv_trans;
	t_matrix	transp_trans;

	inv_trans = invert_matrix(transform);
	transp_trans = transpose_matrix(inv_trans);
	o_point = mult_matrix_tuple(inv_trans, w_point);
	o_normal = normal_object_type(poly, o_point);
	w_normal = mult_matrix_tuple(transp_trans, o_normal);
	w_normal.w = 0;
	free_matrix(inv_trans);
	free_matrix(transp_trans);
	return (normalize_v(w_normal));
}

t_tuple		reflect(t_tuple in, t_tuple normal)
{
	return (subtract_tuple(in,
		scalar_x_tuple(normal,
		(2 * (dot_product(in, normal))))));
}

t_phong		default_phong(void)
{
	t_phong	new;

	new.color.r = 1;
	new.color.g = 0.2;
	new.color.b = 1;
	new.color.a = 1;
	new.diffuse = 0.9;
	new.ambient = 0.1;
	new.specular = 0.9;
	new.shininess = 200.0;
	new.reflect = 0.2;
	return (new);
}

static void	set_light_params(t_comps *args, t_ltparams *params, t_light *lt)
{
	params->effective_color = rgba_to_tuple(mult_color(args->phong.color,
	lt->intensity));
	params->light_v = normalize_v(subtract_tuple(lt->pos,
		args->over_point));
	params->ambient = scalar_x_tuple(params->effective_color,
		args->phong.ambient);
	params->light_dot_normal = dot_product(params->light_v, args->normal_vec);
}

t_rgba		lighting(t_comps args, t_light *current_light, int in_shadow)
{
	t_ltparams	params;

	set_light_params(&args, &params, current_light);
	if (params.light_dot_normal < 0 || in_shadow == 1)
	{
		params.diffuse = create_tuple(0, 0, 0, 0);
		params.specular = create_tuple(0, 0, 0, 0);
	}
	else
	{
		params.diffuse = scalar_x_tuple(params.effective_color,
		(args.phong.diffuse * params.light_dot_normal));
		params.reflect_v = reflect(negate_tuple(params.light_v),
			args.normal_vec);
		params.reflect_dot_eye = dot_product(params.reflect_v, args.eye_vec);
		if (params.reflect_dot_eye <= 0)
			params.specular = create_tuple(0, 0, 0, 0);
		else
			params.specular = scalar_x_tuple(rgba_to_tuple(
			current_light->intensity), args.phong.specular *
			(pow(params.reflect_dot_eye, args.phong.shininess)));
	}
	return (tuple_to_rgba(add_tuple(params.ambient,
	add_tuple(params.diffuse, params.specular))));
}
