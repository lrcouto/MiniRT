/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:54:23 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/06 20:16:20 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void			create_intersec(double t, t_intersec *head,
t_square *square, t_ray ray)
{
	t_intersec		intersec1;
	t_tuple			dist;
	double			border;

	if (t > 0)
	{
		dist = subtract_tuple(ray_position(ray, t), square->center);
		border = square->side * 0.5;
		if ((fabs(dist.x) <= border)
			&& (fabs(dist.y) <= border)
			&& (fabs(dist.z) <= border))
		{
			intersec1.count = 1;
			intersec1.t = t;
			intersec1.poly = insert_square(square);
			push_intersec(head, &intersec1);
		}
	}
}

void				intersect_square(t_ray ray, t_square *square,
t_intersec *head)
{
	double			t;
	t_ray			tformed;
	t_matrix		invert;

	if (fabs(ray.direction.y) < EPSILON)
		return ;
	invert = invert_matrix(square->transform);
	tformed = transform_ray(ray, invert);
	t = (-1 * tformed.origin.y) / tformed.direction.y;
	free_matrix(invert);
	create_intersec(t, head, square, tformed);
}
