/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 21:59:11 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/06 21:59:14 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	free_lists(t_rt *rt)
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
