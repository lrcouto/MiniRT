/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:06:06 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/10 21:13:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_new_cylinder(t_cylinder *current, t_cylinder *new_cylinder)
{
	current->next = (t_cylinder*)ec_malloc(sizeof(t_cylinder));
	current->next->pos = new_cylinder->pos;
	current->next->norm = new_cylinder->norm;
	current->next->color = new_cylinder->color;
	current->next->transform = new_cylinder->transform;
	current->next->diameter = new_cylinder->diameter;
	current->next->radius = new_cylinder->radius;
	current->next->height = new_cylinder->height;
	current->next->phong = new_cylinder->phong;
	current->next->next = new_cylinder->next;
}

static void		push_cylinder(t_rt *rt, t_cylinder *new_cylinder)
{
	t_cylinder *current;

	current = rt->cylinder;
	new_cylinder->next = NULL;
	if (rt->qts.cy == 0)
	{
		rt->cylinder = (t_cylinder *)ec_malloc(sizeof(t_cylinder));
		rt->cylinder->pos = new_cylinder->pos;
		rt->cylinder->norm = new_cylinder->norm;
		rt->cylinder->diameter = new_cylinder->diameter;
		rt->cylinder->radius = new_cylinder->radius;
		rt->cylinder->height = new_cylinder->height;
		rt->cylinder->transform = new_cylinder->transform;
		rt->cylinder->phong = new_cylinder->phong;
		rt->cylinder->color = new_cylinder->color;
		rt->cylinder->next = new_cylinder->next;
		rt->qts.cy = rt->qts.cy + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	push_new_cylinder(current, new_cylinder);
	rt->qts.cy = rt->qts.cy + 1;
}

static void		loop_get_values(char *line, int *iptr, int *chkptr,
t_cylinder *cylinder)
{
	if (*chkptr == 0)
	{
		*chkptr = get_cylinder_pos(line, *chkptr, *iptr, cylinder);
		*iptr = get_index(line, *iptr);
	}
	else if (*chkptr == 3)
	{
		*chkptr = get_cylinder_norm(line, *chkptr, *iptr, cylinder);
		*iptr = get_index(line, *iptr);
	}
	else if (*chkptr == 6)
	{
		*chkptr = get_cylinder_diameter(line, *chkptr, *iptr, cylinder);
		*iptr = get_index(line, *iptr);
	}
	else if (*chkptr == 7)
	{
		*chkptr = get_cylinder_height(line, *chkptr, *iptr, cylinder);
		*iptr = get_index(line, *iptr);
	}
	else if (*chkptr == 8)
	{
		*chkptr = get_cylinder_color(line, *chkptr, *iptr, cylinder);
		*iptr = get_index(line, *iptr);
	}
}

static int		cylinder_loop(char *line, int i, int check,
t_cylinder *cylinder)
{
	int	*iptr;
	int *chkptr;

	chkptr = &check;
	iptr = &i;
	while (line[*iptr] != '\0' && check < 11)
	{
		if (line[*iptr] == ' ')
			*iptr = *iptr + 1;
		else if ((line[*iptr] >= '0' && line[*iptr] <= '9') ||
		line[*iptr] == '-')
			loop_get_values(line, iptr, chkptr, cylinder);
		else if ((!(line[*iptr] >= '0' && line[*iptr] <= '9')) ||
		(!(line[*iptr] == ' ')))
			errormsg(5);
	}
	return (i);
}

void			get_cylinder(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_cylinder	*cylinder;
	t_phong		newphong;

	cylinder = (t_cylinder *)ec_malloc(sizeof(t_cylinder));
	newphong = default_phong();
	check = 0;
	i = 2;
	i = cylinder_loop(line, i, check, cylinder);
	get_material(&newphong, line, i);
	cylinder->phong.specular = newphong.specular;
	cylinder->phong.shininess = newphong.shininess;
	cylinder->phong.reflect = newphong.reflect;
	render_cylinder_transform(cylinder);
	push_cylinder(rt, cylinder);
	free(cylinder);
}
