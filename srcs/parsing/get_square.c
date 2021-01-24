/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:58:57 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/23 20:29:12 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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
		rt->square->next = new_square->next;
		rt->qts.sq = rt->qts.sq + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_square *)ec_malloc(sizeof(t_square));
	current->next->center = new_square->center;
	current->next->norm = new_square->norm;
	current->next->side = new_square->side;
	current->next->color = new_square->color;
	current->next->next = new_square->next;
	rt->qts.sq = rt->qts.sq + 1;
}

static int		get_square_norm(char *line, int check, int i,
t_square *square)
{
	double	norm;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] >= '0' || line[i] <= '9') && check == 3)
		{
			norm = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	if (norm > 1 || norm < -1)
		errormsg(24);
	square->norm = norm;
	return (check);
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
	else if (*chkptr == 4)
	{
		*chkptr = get_square_side(line, *chkptr, i, square);
		i = get_index(line, i);
	}
	else if (*chkptr == 5)
	{
		*chkptr = get_square_color(line, *chkptr, i, square);
		i = get_index(line, i);
	}
	return (i);
}

static void		square_loop(char *line, int i, int check, t_square *square)
{
	int *chkptr;

	chkptr = &check;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			i = loop_get_values(line, i, chkptr, square);
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
}

void			get_square(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_square	*square;

	square = (t_square *)ec_malloc(sizeof(t_square));
	check = 0;
	i = 2;
	square_loop(line, i, check, square);
	push_square(rt, square);
	free(square);
}
