/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:52:33 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/05 20:30:34 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void print_intersec(t_intersec *intersec_list)
{
	t_intersec	*tmp_intersec;
	t_intersec	*current;

	current = intersec_list;
	while (current != NULL)
	{
		tmp_intersec = current;
		current = current->next;
		printf("T1: %f, T2: %f", tmp_intersec->t1, tmp_intersec->t2);
	}
}

void				intersect_world_test(t_rt *rt)
{
	t_ray ray;
	t_intersec *intersec_list;
	t_sphere *current;

	render_sphere_transform(rt->sphere);
	intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
	intersec_list = init_intersec_list(intersec_list);

	ray = create_ray(create_tuple(0, 0, -5, 1), create_tuple(0, 0, 1, 0));

	current = rt->sphere;
	while(current->next != NULL)
	{
		intersect_sphere(ray, current, intersec_list);

		current = current->next;
	}
	intersect_sphere(ray, current, intersec_list);

	print_intersec(intersec_list);

	free_intersecs(intersec_list);
}