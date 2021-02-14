/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:00:00 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 20:10:24 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_new_camera(t_cam *current, t_cam *new_cam)
{
	current->next = (t_cam *)ec_malloc(sizeof(t_cam));
	current->next->view = new_cam->view;
	current->next->pos = new_cam->pos;
	current->next->fov = new_cam->fov;
	current->next->half_height = new_cam->half_height;
	current->next->half_width = new_cam->half_width;
	current->next->pixel_size = new_cam->pixel_size;
	current->next->origin = new_cam->origin;
	current->next->transform = new_cam->transform;
	current->next->img = new_cam->img;
	current->next->address = new_cam->address;
	current->next->next = new_cam->next;
}

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
		head->origin = new_cam->origin;
		head->half_height = new_cam->half_height;
		head->half_width = new_cam->half_width;
		head->pixel_size = new_cam->pixel_size;
		head->transform = new_cam->transform;
		head->img = new_cam->img;
		head->address = new_cam->address;
		head->next = new_cam->next;
		rt->qts.cam = rt->qts.cam + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	push_new_camera(current, new_cam);
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
	int			i;
	int			check;
	t_cam		*cam;
	t_matrix	transform;

	cam = (t_cam *)ec_malloc(sizeof(t_cam));
	check = 0;
	i = 1;
	camera_loop(line, i, check, cam);
	transform = view_transform(cam->view, add_tuple(cam->view,
		cam->pos), cross_product(cross_product(cam->pos,
		create_tuple(0, 1, 0, 0)), cam->pos));
	cam->transform = invert_matrix(transform);
	camera_pixel_size(rt, cam);
	cam->origin = mult_matrix_tuple(cam->transform, create_tuple(0, 0, 0, 1));
	push_camera(rt->cam, cam, rt);
	free_matrix(transform);
	free(cam);
}
