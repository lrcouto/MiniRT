/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_polys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:02:17 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/13 17:27:44 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	free_triangle(t_rt *rt)
{
	t_triangle	*tmp_triangle;
	t_triangle	*current;

	current = rt->triangle;
	while (current != NULL)
	{
		tmp_triangle = current;
		printf("TRIANGLE - P1 X %lf P1 Y %lf P1 Z %lf \nTRIANGLE - P2 X %lf P2 Y %lf P2 Z %lf \nTRIANGLE - P3 X %lf P3 Y %lf P3 Z %lf \nTRIANGLE - R %d G %d B %d \n", current->p1.x, current->p1.y, current->p1.z, current->p2.x, current->p2.y, current->p2.z, current->p3.x, current->p3.y, current->p3.z, current->color.r, current->color.g, current->color.b);
		current = current->next;
		free(tmp_triangle);
	}
}

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
