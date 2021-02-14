/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:42:20 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 16:52:54 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_new_sphere(t_sphere *current, t_sphere *new_sphere)
{
	current->next = (t_sphere *)ec_malloc(sizeof(t_sphere));
	current->next->center = new_sphere->center;
	current->next->diameter = new_sphere->diameter;
	current->next->radius = new_sphere->radius;
	current->next->color = new_sphere->color;
	current->next->transform = new_sphere->transform;
	current->next->phong = new_sphere->phong;
	current->next->next = new_sphere->next;
}

static void		push_sphere(t_rt *rt, t_sphere *new_sphere)
{
	t_sphere *current;

	current = rt->sphere;
	new_sphere->next = NULL;
	if (rt->qts.sp == 0)
	{
		rt->sphere = (t_sphere *)ec_malloc(sizeof(t_sphere));
		rt->sphere->center = new_sphere->center;
		rt->sphere->diameter = new_sphere->diameter;
		rt->sphere->radius = new_sphere->radius;
		rt->sphere->color = new_sphere->color;
		rt->sphere->phong = new_sphere->phong;
		rt->sphere->transform = new_sphere->transform;
		rt->sphere->next = new_sphere->next;
		rt->qts.sp = rt->qts.sp + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	push_new_sphere(current, new_sphere);
	rt->qts.sp = rt->qts.sp + 1;
}

static int		loop_get_values(char *line, int i, int *chkptr,
t_sphere *sphere)
{
	if (*chkptr == 0)
	{
		*chkptr = get_sphere_center(line, *chkptr, i, sphere);
		i = get_index(line, i);
	}
	else if (*chkptr == 3)
	{
		*chkptr = get_sphere_diameter(line, *chkptr, i, sphere);
		i = get_index(line, i);
	}
	else if (*chkptr == 4)
	{
		*chkptr = get_sphere_color(line, *chkptr, i, sphere);
		i = get_index(line, i);
	}
	return (i);
}

static int		sphere_loop(char *line, int i, int check, t_sphere *sphere)
{
	int *chkptr;

	chkptr = &check;
	while (line[i] != '\0' && check < 7)
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			i = loop_get_values(line, i, chkptr, sphere);
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
	return (i);
}

void			get_sphere(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_sphere	*sphere;
	t_phong		newphong;

	sphere = (t_sphere *)ec_malloc(sizeof(t_sphere));
	newphong = default_phong();
	check = 0;
	i = 2;
	i = sphere_loop(line, i, check, sphere);
	get_material(&newphong, line, i);
	sphere->phong.specular = newphong.specular;
	sphere->phong.shininess = newphong.shininess;
	sphere->phong.reflect = newphong.reflect;
	render_sphere_transform(sphere);
	push_sphere(rt, sphere);
	free(sphere);
}
