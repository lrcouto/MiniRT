/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:11:17 by gsenra-a          #+#    #+#             */
/*   Updated: 2021/02/10 21:22:34 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_new_triangle(t_triangle *current, t_triangle *new_triangle)
{
	current->next = (t_triangle *)ec_malloc(sizeof(t_triangle));
	current->next->p1 = new_triangle->p1;
	current->next->p2 = new_triangle->p2;
	current->next->p3 = new_triangle->p3;
	current->next->color = new_triangle->color;
	current->next->phong = new_triangle->phong;
	current->next->transform = new_triangle->transform;
	current->next->edgevec_1 = new_triangle->edgevec_1;
	current->next->edgevec_2 = new_triangle->edgevec_2;
	current->next->next = new_triangle->next;
}

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
		rt->triangle->transform = new_triangle->transform;
		rt->triangle->edgevec_1 = new_triangle->edgevec_1;
		rt->triangle->edgevec_2 = new_triangle->edgevec_2;
		rt->triangle->phong = new_triangle->phong;
		rt->qts.tr = rt->qts.tr + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	push_new_triangle(current, new_triangle);
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

static int		triangle_loop(char *line, int i, int check,
t_triangle *triangle)
{
	int *chkptr;

	chkptr = &check;
	while (line[i] != '\0' && check < 12)
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			i = loop_get_values(line, i, chkptr, triangle);
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
	return (i);
}

void			get_triangle(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_triangle	*triangle;
	t_phong		newphong;

	triangle = (t_triangle *)ec_malloc(sizeof(t_triangle));
	newphong = default_phong();
	check = 0;
	i = 2;
	i = triangle_loop(line, i, check, triangle);
	get_material(&newphong, line, i);
	triangle->phong.specular = newphong.specular;
	triangle->phong.shininess = newphong.shininess;
	triangle->phong.reflect = newphong.reflect;
	triangle->edgevec_1 = subtract_tuple(triangle->p2, triangle->p1);
	triangle->edgevec_2 = subtract_tuple(triangle->p3, triangle->p1);
	triangle->transform = create_id_matrix();
	push_triangle(rt, triangle);
	free(triangle);
}
