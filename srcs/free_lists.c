/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:12:12 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/11 15:55:53 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

/*
** TODO: Remove printfs.
*/

void	free_light(t_rt *rt)
{
	t_light	*tmp_light;
	t_light	*current;

	current = rt->light;
	while (current != NULL)
	{
		tmp_light = current;
		printf("LIGHT - POS X %lf POS Y %lf POS Z %lf \nLIGHT - R %d G %d B %d \nLIGHT - INTENSITY %lf \n", current->pos.x, current->pos.y, current->pos.z, current->color.r, current->color.g, current->color.b, current->light);
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
		printf("CAMERA - VIEW X %lf VIEW Y %lf VIEW Z %lf \nCAMERA - POS X %lf VIEW Y %lf VIEW Z %lf \nCAMERA - FOV %d \n", current->view.x, current->view.y, current->view.z, current->pos.x, current->pos.y, current->pos.z, current->fov);
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
}
