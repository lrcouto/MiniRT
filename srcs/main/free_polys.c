/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_polys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:02:17 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/24 20:39:57 by lcouto           ###   ########.fr       */
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
		current = current->next;
		free(tmp_sphere);
	}
}
