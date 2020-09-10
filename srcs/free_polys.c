/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_polys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:02:17 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/10 19:13:15 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	free_plane(t_rt *rt)
{
	t_plane	*tmp_plane;
	t_plane	*current;

	current = rt->plane;
	while (current != NULL)
	{
		tmp_plane = current;
		printf("PLANE - POS X %lf POS Y %lf POS Z %lf \nPLANE - R %d G %d B %d \nPLANE - NORM %lf \n", current->pos.x, current->pos.y, current->pos.z, current->color.r, current->color.g, current->color.b, current->norm);
		current = current->next;
		free(tmp_plane);
	}
}

void	free_sphere(t_rt *rt)
{
	t_sphere	*tmp_sphere;
	t_sphere	*current;

	current = rt->sphere;
	while (current != NULL)
	{
		tmp_sphere = current;
		printf("SPHERE - CENTER X %lf CENTER Y %lf CENTER Z %lf \nSPHERE - R %d G %d B %d \nSPHERE - DIAMETER %lf \n", current->center.x, current->center.y, current->center.z, current->color.r, current->color.g, current->color.b, current->diameter);
		current = current->next;
		free(tmp_sphere);
	}
}
