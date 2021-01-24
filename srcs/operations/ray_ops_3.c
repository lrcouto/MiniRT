/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:36:57 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/23 18:48:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_intersec	*init_intersec_list(t_intersec *list)
{
	list->count = 0;
	list->t = 0;
	list->qty = 0;
	list->next = NULL;
	return (list);
}

t_intersec	*intersec_hit(t_intersec *head)
{
	t_intersec	*hit;
	t_intersec	*tmp_intersec;
	t_intersec	*current;

	current = head;
	hit = NULL;
	while (current != NULL)
	{
		tmp_intersec = current;
		if (!hit && tmp_intersec->t >= 0)
			hit = tmp_intersec;
		else if (tmp_intersec->t >= 0 && tmp_intersec->t < hit->t)
			hit = tmp_intersec;
		current = current->next;
	}
	if (hit && hit->count == 0)
		hit = NULL;
	return (hit);
}

t_ray		transform_ray(t_ray ray, t_matrix transform)
{
	t_ray	new;

	new.origin = mult_matrix_tuple(transform, ray.origin);
	new.direction = mult_matrix_tuple(transform, ray.direction);
	return (new);
}
