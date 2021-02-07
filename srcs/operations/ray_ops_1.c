/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:53:00 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/06 21:54:17 by lcouto           ###   ########.fr       */
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
