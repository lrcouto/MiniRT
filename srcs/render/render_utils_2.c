/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:46:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/30 18:47:46 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void				normalize_pixel_color(t_rgba *lt_output)
{
	if (lt_output->r > 1.0)
		lt_output->r = 1.0;
	if (lt_output->g > 1.0)
		lt_output->g = 1.0;
	if (lt_output->b > 1.0)
		lt_output->b = 1.0;
	if (lt_output->r < 0)
		lt_output->r = 0;
	if (lt_output->g < 0)
		lt_output->g = 0;
	if (lt_output->b < 0)
		lt_output->b = 0;
}

void				loading_bar(double percent, int total)
{
	int			ten;
	static int	counter;

	ten = total / 10;
	if (counter == 0)
		ft_putstr_fd("Rendering... [", 1);
	if (counter == ten)
	{
		ft_putstr_fd("#", 1);
		counter = 0;
	}
	counter++;
	if (percent == 1)
		ft_putstr_fd("] 100%\nDone!\n", 1);
}

int					is_shadowed(t_comps comps, t_rt *rt, t_light *light)
{
	t_tuple	path;
	double	distance;
	t_raycaster	rc;
	int		result;

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

t_tuple			normal_object_type(t_polys poly, t_tuple o_point)
{

	if (poly.obj_type == SPHERE)
		return (subtract_tuple(o_point, create_tuple(0, 0, 0, 1)));
	else if (poly.obj_type == PLANE)
		return (create_tuple(0, 1, 0, 0));
	else if (poly.obj_type == SQUARE)
		return (create_tuple(0, 1, 0, 0));
	else
		return (create_tuple(0, 0, 0, 0));
}

t_rgba			color_at(t_rt *rt, t_ray ray, int bounce)
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

t_rgba			reflect_color(t_comps comps, t_rt *rt, int bounce)
{
	t_ray	reflect_ray;
	t_rgba	color;

	if (comps.phong.reflect == 0 || bounce <= 0)
		return create_rgba(0, 0, 0, 0);
	reflect_ray = create_ray(comps.over_point, comps.reflect_vec);
	color = color_at(rt, reflect_ray, bounce - 1);
	return scalar_color(color, comps.phong.reflect);
}