/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:14:54 by lcouto            #+#    #+#             */
/*   Updated: 2020/11/14 14:25:49 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	lighting_test(void)
{
	t_phong material;
	t_light	light;
	t_tuple	eye_vector;
	t_tuple	normal_vector;
	t_rgba	result;

	material = default_phong();
	light.pos = create_tuple(0, 0, -10, 1);
	light.color.r = 255;
	light.color.g = 255;
	light.color.b = 255;
	light.light = 1.0;
	eye_vector = create_tuple(0, 0, -1, 0);
	normal_vector = create_tuple(0, 0, -1, 0);
	result = lighting(material, light, eye_vector, normal_vector);
	printf("R: %f G: %f B: %f\n", result.r, result.g, result.b);
}