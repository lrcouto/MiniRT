/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:05:02 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/06 20:13:16 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void			create_intersec(double t, t_intersec *head,
t_plane *plane)
{
	t_intersec	intersec1;

	if (t > 0)
	{
		intersec1.count = 1;
		intersec1.t = t;
		intersec1.poly = insert_plane(plane);
		push_intersec(head, &intersec1);
	}
}

void				intersect_plane(t_ray ray, t_plane *plane,
t_intersec *head)
{
	double			t;
	t_ray			tformed;
	t_matrix		invert;

	if (fabs(ray.direction.y) < EPSILON)
		return ;
	invert = invert_matrix(plane->transform);
	tformed = transform_ray(ray, invert);
	free_matrix(invert);
	t = (-1 * tformed.origin.y) / tformed.direction.y;
	create_intersec(t, head, plane);
}
