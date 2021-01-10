/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:46:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/10 17:25:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void				render_sphere_transform(t_sphere *head)
{
	t_sphere	*current;
	t_matrix	translate;
	t_matrix	scale;
	t_matrix	transform;

	current = head;
	while (1)
	{
		translate = translation(current->center.x,
			current->center.y, current->center.z);
		scale = scaling(current->radius, current->radius, current->radius);
		transform = mult_matrix(scale, translate);
		set_transform_sphere(current, transform);
		free_matrix(translate);
		free_matrix(scale);
		if (current->next == NULL)
			break ;
		current = current->next;
	}
}

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
	intersect_all_spheres(rt, &rc);
	rc.hit = intersec_hit(rc.intersec_list);
	if (rc.hit && rc.hit->t < distance)
		result = 1;
	else
		result = 0;
	free_intersecs(rc.intersec_list);
	return (result);
}
