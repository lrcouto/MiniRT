/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:37:20 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 16:56:20 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_new_plane(t_plane *current, t_plane *new_plane)
{
	current->next = (t_plane*)ec_malloc(sizeof(t_plane));
	current->next->pos = new_plane->pos;
	current->next->norm = new_plane->norm;
	current->next->color = new_plane->color;
	current->next->transform = new_plane->transform;
	current->next->phong = new_plane->phong;
	current->next->next = new_plane->next;
}

static void		push_plane(t_rt *rt, t_plane *new_plane)
{
	t_plane *current;

	current = rt->plane;
	new_plane->next = NULL;
	if (rt->qts.pl == 0)
	{
		rt->plane = (t_plane*)ec_malloc(sizeof(t_plane));
		rt->plane->pos = new_plane->pos;
		rt->plane->norm = new_plane->norm;
		rt->plane->color = new_plane->color;
		rt->plane->phong = new_plane->phong;
		rt->plane->transform = new_plane->transform;
		rt->plane->next = new_plane->next;
		rt->qts.pl = rt->qts.pl + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	push_new_plane(current, new_plane);
	rt->qts.pl = rt->qts.pl + 1;
}

static int		loop_get_values(char *line, int i, int *chkptr,
t_plane *plane)
{
	if (*chkptr == 0)
	{
		*chkptr = get_plane_pos(line, *chkptr, i, plane);
		i = get_index(line, i);
	}
	else if (*chkptr == 3)
	{
		*chkptr = get_plane_norm(line, *chkptr, i, plane);
		i = get_index(line, i);
	}
	else if (*chkptr == 6)
	{
		*chkptr = get_plane_color(line, *chkptr, i, plane);
		i = get_index(line, i);
	}
	return (i);
}

static int		plane_loop(char *line, int i, int check, t_plane *plane)
{
	int *chkptr;

	chkptr = &check;
	while (line[i] != '\0' && check < 9)
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			i = loop_get_values(line, i, chkptr, plane);
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
	return (i);
}

void			get_plane(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_plane		*plane;
	t_phong		newphong;

	plane = (t_plane *)ec_malloc(sizeof(t_plane));
	newphong = default_phong();
	check = 0;
	i = 2;
	i = plane_loop(line, i, check, plane);
	get_material(&newphong, line, i);
	plane->phong.specular = newphong.specular;
	plane->phong.shininess = newphong.shininess;
	plane->phong.reflect = newphong.reflect;
	render_plane_transform(plane);
	push_plane(rt, plane);
	free(plane);
}
