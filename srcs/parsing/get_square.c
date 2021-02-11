/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:58:57 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/10 21:19:34 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_new_square(t_square *current, t_square *new_square)
{
	current->next = (t_square *)ec_malloc(sizeof(t_square));
	current->next->center = new_square->center;
	current->next->norm = new_square->norm;
	current->next->side = new_square->side;
	current->next->color = new_square->color;
	current->next->phong = new_square->phong;
	current->next->transform = new_square->transform;
	current->next->next = new_square->next;
}

static void		push_square(t_rt *rt, t_square *new_square)
{
	t_square *current;

	current = rt->square;
	new_square->next = NULL;
	if (rt->qts.sq == 0)
	{
		rt->square = (t_square *)ec_malloc(sizeof(t_square));
		rt->square->center = new_square->center;
		rt->square->norm = new_square->norm;
		rt->square->side = new_square->side;
		rt->square->color = new_square->color;
		rt->square->phong = new_square->phong;
		rt->square->transform = new_square->transform;
		rt->square->next = new_square->next;
		rt->qts.sq = rt->qts.sq + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	push_new_square(current, new_square);
	rt->qts.sq = rt->qts.sq + 1;
}

static int		loop_get_values(char *line, int i, int *chkptr,
t_square *square)
{
	if (*chkptr == 0)
	{
		*chkptr = get_square_center(line, *chkptr, i, square);
		i = get_index(line, i);
	}
	else if (*chkptr == 3)
	{
		*chkptr = get_square_norm(line, *chkptr, i, square);
		i = get_index(line, i);
	}
	else if (*chkptr == 6)
	{
		*chkptr = get_square_side(line, *chkptr, i, square);
		i = get_index(line, i);
	}
	else if (*chkptr == 7)
	{
		*chkptr = get_square_color(line, *chkptr, i, square);
		i = get_index(line, i);
	}
	return (i);
}

static int		square_loop(char *line, int i, int check, t_square *square)
{
	int *chkptr;

	chkptr = &check;
	while (line[i] != '\0' && check < 10)
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			i = loop_get_values(line, i, chkptr, square);
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
	return (i);
}

void			get_square(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_square	*square;
	t_phong		newphong;

	square = (t_square *)ec_malloc(sizeof(t_square));
	newphong = default_phong();
	check = 0;
	i = 2;
	i = square_loop(line, i, check, square);
	get_material(&newphong, line, i);
	square->phong.specular = newphong.specular;
	square->phong.shininess = newphong.shininess;
	square->phong.reflect = newphong.reflect;
	render_square_transform(square);
	push_square(rt, square);
	free(square);
}
