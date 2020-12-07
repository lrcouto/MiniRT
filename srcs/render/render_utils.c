/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:40:12 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/06 20:443:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_tuple		sphere_normal(t_sphere *sphere, t_tuple w_point)
{
	t_tuple		o_point;
	t_tuple		o_normal;
	t_tuple		w_normal;
	t_matrix	inv_trans;
	t_matrix	transp_trans;

	inv_trans = invert_matrix(sphere->transform);
	transp_trans = transpose_matrix(inv_trans);
	o_point = mult_matrix_tuple(inv_trans, w_point);
	o_normal = subtract_tuple(o_point, create_tuple(0, 0, 0, 1));
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
	new.ambient = 0.05;
	new.specular = 0.9;
	new.shininess = 200.0;
	return (new);
}

static void	set_light_params(t_comps *args, t_ltparams *params)
{
	params->effective_color = rgba_to_tuple(mult_color(args->phong.color,
	args->light.intensity));
	params->light_v = normalize_v(subtract_tuple(args->light.pos, args->position));
	params->ambient = scalar_x_tuple(params->effective_color,
		args->phong.ambient);
	params->light_dot_normal = dot_product(params->light_v, args->normal_vec);
}

t_rgba		lighting(t_comps args)
{
	t_ltparams params;

	set_light_params(&args, &params);
	if (params.light_dot_normal < 0)
	{
		params.diffuse = create_tuple(0, 0, 0, 0);
		params.specular = create_tuple(0, 0, 0, 0);
	}
	else
	{
		params.diffuse = scalar_x_tuple(params.effective_color,
		(args.phong.diffuse * params.light_dot_normal));
		params.reflect_v = reflect(negate_tuple(params.light_v), args.normal_vec);
		params.reflect_dot_eye = dot_product(params.reflect_v, args.eye_vec);
		if (params.reflect_dot_eye <= 0)
			params.specular = create_tuple(0, 0, 0, 0);
		else
			params.specular = scalar_x_tuple(rgba_to_tuple(
			args.light.intensity), args.phong.specular *
			(pow(params.reflect_dot_eye, args.phong.shininess)));
	}
	return (tuple_to_rgba(add_tuple(params.ambient,
	add_tuple(params.diffuse, params.specular))));
}
