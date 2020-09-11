/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_polys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:02:17 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/11 15:24:09 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	free_cylinder(t_rt *rt)
{
	t_cylinder	*tmp_cylinder;
	t_cylinder	*current;

	current = rt->cylinder;
	while (current != NULL)
	{
		tmp_cylinder = current;
		printf("CYLINDER - POS X %lf POS Y %lf POS Z %lf \nCYLINDER - R %d G %d B %d \nCYLINDER - NORM %lf \nCYLINDER - DIAMETER %lf \nCYLINDER - HEIGHT %lf \n", current->pos.x, current->pos.y, current->pos.z, current->color.r, current->color.g, current->color.b, current->norm, current->diameter, current->height);
		current = current->next;
		free(tmp_cylinder);
	}
}

void	free_square(t_rt *rt)
{
	t_square	*tmp_square;
	t_square	*current;

	current = rt->square;
	while (current != NULL)
	{
		tmp_square = current;
		printf("SQUARE - CENTER X %lf CENTER Y %lf CENTER Z %lf \nSQUARE - R %d G %d B %d \nSQUARE - NORM %lf \nSQUARE - SIDE %lf \n", current->center.x, current->center.y, current->center.z, current->color.r, current->color.g, current->color.b, current->norm, current->side);
		current = current->next;
		free(tmp_square);
	}
}

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
