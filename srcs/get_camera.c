/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:16:02 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/05 21:31:27 bygsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void		push_camera(t_cam *head, t_cam *new_cam, t_rt *rt)
{
	t_cam *current;

	current = head;
	new_cam->next = NULL;
	if (rt->qts.cam == 0)
	{
		head->view = new_cam->view;
		head->pos = new_cam->pos;
		head->fov = new_cam->fov;
		head->next = new_cam->next;
		rt->qts.cam = rt->qts.cam + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_cam *)malloc(sizeof(t_cam));
	current->next->view = new_cam->view;
	current->next->pos = new_cam->pos;
	current->next->fov = new_cam->fov;
	current->next->next = new_cam->next;
	rt->qts.cam = rt->qts.cam + 1;
}

static void		camera_loop(char *line, int i, int check, t_cam *cam)
{
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (check == 0)
			{
				check = get_cam_view(line, check, i, cam);
				i = get_index(line, i);
			}
			else if (check == 3)
			{
				check = get_cam_pos(line, check, i, cam);
				i = get_index(line, i);
			}
			else if (check == 6)
			{
				check = get_cam_fov(line, check, i, cam);
				i = get_index(line, i);
			}
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
}

void			get_camera(char *line, t_rt *rt)
{
	int		i;
	int		check;
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	check = 0;
	i = 1;
	camera_loop(line, i, check, cam);
	push_camera(rt->cam, cam, rt);
	free(cam);
}
