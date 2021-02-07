/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 20:36:19 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/06 20:54:22 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int			check_cap(t_ray ray, double t)
{
	double x;
	double z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	if ((pow(x, 2) + pow(z, 2)) <= 1)
		return (1);
	return (0);
}

void				intersect_caps(t_cylinder *cylinder, t_ray ray,
t_intersec *head)
{
	double			min;
	double			max;
	t_intersec		intersec1;
	t_intersec		intersec2;

	max = cylinder->height / 2.0;
	min = -1.0 * max;
	intersec1.count = 2;
	intersec1.t = (min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, intersec1.t))
	{
		intersec1.poly = insert_cylinder(cylinder);
		push_intersec(head, &intersec1);
	}
	intersec2.count = 2;
	intersec2.t = (max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, intersec2.t))
	{
		intersec2.poly = insert_cylinder(cylinder);
		push_intersec(head, &intersec2);
	}
}
