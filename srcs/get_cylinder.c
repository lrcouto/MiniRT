/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:06:06 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/11 15:55:53 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void		push_cylinder(t_cylinder *head, t_cylinder *new_cylinder,
t_rt *rt)
{
	t_cylinder *current;

	current = head;
	new_cylinder->next = NULL;
	if (rt->qts.cy == 0)
	{
		head->pos = new_cylinder->pos;
		head->norm = new_cylinder->norm;
		head->diameter = new_cylinder->diameter;
		head->height = new_cylinder->height;
		head->color = new_cylinder->color;
		head->next = new_cylinder->next;
		rt->qts.cy = rt->qts.cy + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_cylinder *)malloc(sizeof(t_cylinder));
	current->next->pos = new_cylinder->pos;
	current->next->norm = new_cylinder->norm;
	current->next->diameter = new_cylinder->diameter;
	current->next->height = new_cylinder->height;
	current->next->color = new_cylinder->color;
	current->next->next = new_cylinder->next;
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
	else if (*chkptr == 4)
	{
		*chkptr = get_cylinder_diameter(line, *chkptr, *iptr, cylinder);
		*iptr = get_index(line, *iptr);
	}
	else if (*chkptr == 5)
	{
		*chkptr = get_cylinder_height(line, *chkptr, *iptr, cylinder);
		*iptr = get_index(line, *iptr);
	}
	else if (*chkptr == 6)
	{
		*chkptr = get_cylinder_color(line, *chkptr, *iptr, cylinder);
		*iptr = get_index(line, *iptr);
	}
}

static void		cylinder_loop(char *line, int i, int check,
t_cylinder *cylinder)
{
	int	*iptr;
	int *chkptr;

	chkptr = &check;
	iptr = &i;
	while (line[*iptr] != '\0')
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
}

void			get_cylinder(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	check = 0;
	i = 2;
	cylinder_loop(line, i, check, cylinder);
	push_cylinder(rt->cylinder, cylinder, rt);
	free(cylinder);
}
