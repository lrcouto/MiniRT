/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:36:57 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/05 21:24:21 by lcouto           ###   ########.fr       */
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

void		push_intersec(t_intersec *head, t_intersec *new)
{
	t_intersec *current;

	current = head;
	new->next = NULL;
	if (current->qty == 0)
	{
		current->count = new->count;
		current->t = new->t;
		current->poly = new->poly;
		current->next = NULL;
		current->qty = current->qty + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_intersec *)ec_malloc(sizeof(t_intersec));
	current->next->count = new->count;
	current->next->t = new->t;
	current->next->poly = new->poly;
	current->next->next = new->next;
	current->next->qty = current->qty + 1;
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

void		set_transform_sphere(t_sphere *sphere, t_matrix transform)
{
	free_matrix(sphere->transform);
	sphere->transform = transform;
}
