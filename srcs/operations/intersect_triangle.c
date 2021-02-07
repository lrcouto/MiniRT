/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:07:05 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/06 21:54:17 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void			create_intersec(double t, t_intersec *head,
t_triangle *triangle)
{
	t_intersec	intersec1;

	if (t > 0)
	{
		intersec1.count = 1;
		intersec1.t = t;
		intersec1.poly = insert_triangle(triangle);
		push_intersec(head, &intersec1);
	}
}

/*
** Had to put parameters in an ugly array
** because of Norminette.
** 0 = t | 1 = f | 2 = u | 3 = v
*/

static void			get_intersec(t_ray ray,
t_intersec *head, t_triangle *triangle)
{
	t_tuple			dir_cross_e2;
	double			det;
	t_tuple			p1_to_origin;
	t_tuple			origin_cross_e1;
	double			params[4];

	dir_cross_e2 = cross_product(ray.direction, triangle->edgevec_2);
	det = dot_product(triangle->edgevec_1, dir_cross_e2);
	if (fabs(det) < EPSILON)
		return ;
	params[1] = 1.0 / det;
	p1_to_origin = subtract_tuple(ray.origin, triangle->p1);
	params[2] = params[1] * dot_product(p1_to_origin, dir_cross_e2);
	if (params[2] < 0 || params[2] > 1)
		return ;
	origin_cross_e1 = cross_product(p1_to_origin, triangle->edgevec_1);
	params[3] = params[1] * dot_product(ray.direction, origin_cross_e1);
	if (params[3] < 0 || (params[2] + params[3]) > 1)
		return ;
	params[0] = params[1] * dot_product(triangle->edgevec_2, origin_cross_e1);
	create_intersec(params[0], head, triangle);
}

void				intersect_triangle(t_ray ray, t_triangle *triangle,
t_intersec *head)
{
	t_ray			tformed;
	t_matrix		invert;

	invert = invert_matrix(triangle->transform);
	tformed = transform_ray(ray, invert);
	free_matrix(invert);
	get_intersec(tformed, head, triangle);
}
