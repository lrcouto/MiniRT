/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:46:42 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/05 20:36:13 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void				render_sphere_transform(t_sphere *head)
{
	double	factor;
	t_sphere *current;

	current = head;
	while(1)
	{
		factor = current->radius;
		set_transform_sphere(current, scaling(factor, factor, factor));
		if (current->next == NULL)
			break;
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
