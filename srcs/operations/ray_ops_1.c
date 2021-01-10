/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:45:27 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/100 19:12:19:19 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray				create_ray(t_tuple origin, t_tuple direction)
{
	t_ray new;

	new.origin = origin;
	new.direction = direction;
	return (new);
}

t_tuple				ray_position(t_ray ray, double t)
{
	return (add_tuple(ray.origin, scalar_x_tuple(ray.direction, t)));
}
