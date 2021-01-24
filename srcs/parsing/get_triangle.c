/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:11:17 by gsenra-a          #+#    #+#             */
/*   Updated: 2021/01/23 20:32:07 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_triangle(t_rt *rt, t_triangle *new_triangle)
{
	t_triangle *current;

	current = rt->triangle;
	new_triangle->next = NULL;
	if (rt->qts.tr == 0)
	{
		rt->triangle = (t_triangle *)ec_malloc(sizeof(t_triangle));
		rt->triangle->p1 = new_triangle->p1;
		rt->triangle->p2 = new_triangle->p2;
		rt->triangle->p3 = new_triangle->p3;
		rt->triangle->color = new_triangle->color;
		rt->triangle->next = new_triangle->next;
		rt->qts.tr = rt->qts.tr + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_triangle *)ec_malloc(sizeof(t_triangle));
	current->next->p1 = new_triangle->p1;
	current->next->p2 = new_triangle->p2;
	current->next->p3 = new_triangle->p3;
	current->next->color = new_triangle->color;
	current->next->next = new_triangle->next;
	rt->qts.tr = rt->qts.tr + 1;
}

static int		loop_get_values(char *line, int i, int *chkptr,
t_triangle *triangle)
{
	if (*chkptr == 0)
	{
		*chkptr = get_triangle_p1(line, *chkptr, i, triangle);
		i = get_index(line, i);
	}
	else if (*chkptr == 3)
	{
		*chkptr = get_triangle_p2(line, *chkptr, i, triangle);
		i = get_index(line, i);
	}
	else if (*chkptr == 6)
	{
		*chkptr = get_triangle_p3(line, *chkptr, i, triangle);
		i = get_index(line, i);
	}
	else if (*chkptr == 9)
	{
		*chkptr = get_triangle_color(line, *chkptr, i, triangle);
		i = get_index(line, i);
	}
	return (i);
}

static void		triangle_loop(char *line, int i, int check,
t_triangle *triangle)
{
	int *chkptr;

	chkptr = &check;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			i = loop_get_values(line, i, chkptr, triangle);
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
}

void			get_triangle(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_triangle	*triangle;

	triangle = (t_triangle *)ec_malloc(sizeof(t_triangle));
	check = 0;
	i = 2;
	triangle_loop(line, i, check, triangle);
	push_triangle(rt, triangle);
	free(triangle);
}
