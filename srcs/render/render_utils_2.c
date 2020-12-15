/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:46:42 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/13 18:02:46 by lcouto           ###   ########.fr       */
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
