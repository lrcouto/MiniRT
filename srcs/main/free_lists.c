/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:12:12 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/18 19:10:00 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	free_light(t_rt *rt)
{
	t_light	*tmp_light;
	t_light	*current;

	current = rt->light;
	while (current != NULL)
	{
		tmp_light = current;
		current = current->next;
		free(tmp_light);
	}
}

void	free_camera(t_rt *rt)
{
	t_cam	*tmp_cam;
	t_cam	*current;

	current = rt->cam;
	while (current != NULL)
	{
		tmp_cam = current;
		current = current->next;
		free(tmp_cam);
	}
}

void	free_lists(t_rt *rt)
{
	free_camera(rt);
	free_light(rt);
	free_sphere(rt);
	free_plane(rt);
	free_square(rt);
	free_cylinder(rt);
	free_triangle(rt);
}
