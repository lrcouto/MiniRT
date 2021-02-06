/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:34:46 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/06 20:50:25 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void			get_y0_y1(t_intersec *intersec1,
t_intersec *intersec2, double *y0_y1, t_ray ray)
{
	double	temp;

	if (intersec1->t > intersec2->t)
	{
		temp = intersec1->t;
		intersec1->t = intersec2->t;
		intersec2->t = temp;
	}
	y0_y1[0] = ray.origin.y + (intersec1->t * ray.direction.y);
	y0_y1[1] = ray.origin.y + (intersec2->t * ray.direction.y);
}

static void			insert_and_push(t_intersec *intersec,
t_cylinder *cylinder, t_intersec *head)
{
	intersec->poly = insert_cylinder(cylinder);
	push_intersec(head, intersec);
}

static void			create_intersec(double *vals, t_intersec *head,
t_cylinder *cylinder, t_ray ray)
{
	t_intersec		intersec1;
	t_intersec		intersec2;
	double			y0_y1[2];
	double			min;
	double			max;

	max = cylinder->height / 2.0;
	min = -1.0 * max;
	intersec1.count = 2;
	intersec2.count = 2;
	intersec1.t = (((-1 * vals[1]) - sqrt(vals[2])) / (2 * vals[0]));
	intersec2.t = (((-1 * vals[1]) + sqrt(vals[2])) / (2 * vals[0]));
	if (vals[2] >= 0 && double_equal(vals[0], 0) == 0)
	{
		get_y0_y1(&intersec1, &intersec2, y0_y1, ray);
		if (min < y0_y1[0] && y0_y1[0] < max)
			insert_and_push(&intersec1, cylinder, head);
		if (min < y0_y1[1] && y0_y1[1] < max)
			insert_and_push(&intersec2, cylinder, head);
	}
	intersect_caps(cylinder, ray, head);
}

static void			get_intersec(t_ray ray,
t_intersec *head, t_cylinder *cylinder)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	double		vals[3];

	a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	b = (2 * ray.origin.x * ray.direction.x) +
		(2 * ray.origin.z * ray.direction.z);
	c = (pow(ray.origin.x, 2) + pow(ray.origin.z, 2)) - 1.0;
	disc = pow(b, 2) - (4 * a * c);
	vals[0] = a;
	vals[1] = b;
	vals[2] = disc;
	create_intersec(vals, head, cylinder, ray);
}

void				intersect_cylinder(t_ray ray, t_cylinder *cylinder,
t_intersec *head)
{
	t_ray			tformed;
	t_matrix		invert;

	if (fabs(ray.direction.y) < EPSILON)
		return ;
	invert = invert_matrix(cylinder->transform);
	tformed = transform_ray(ray, invert);
	free_matrix(invert);
	get_intersec(tformed, head, cylinder);
}
