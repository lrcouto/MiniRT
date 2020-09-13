/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:42:20 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/10 19:13:15 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void		push_sphere(t_sphere *head, t_sphere *new_sphere, t_rt *rt)
{
	t_sphere *current;

	current = head;
	new_sphere->next = NULL;
	if (rt->qts.sp == 0)
	{
		head->center = new_sphere->center;
		head->diameter = new_sphere->diameter;
		head->color = new_sphere->color;
		head->next = new_sphere->next;
		rt->qts.sp = rt->qts.sp + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_sphere *)malloc(sizeof(t_sphere));
	current->next->center = new_sphere->center;
	current->next->diameter = new_sphere->diameter;
	current->next->color = new_sphere->color;
	current->next->next = new_sphere->next;
	rt->qts.sp = rt->qts.sp + 1;
}

static int		get_sphere_diameter(char *line, int check, int i,
t_sphere *sphere)
{
	double	diameter;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] >= '0' || line[i] <= '9') && check == 3)
		{
			diameter = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	sphere->diameter = diameter;
	return (check);
}

static void		sphere_loop(char *line, int i, int check, t_sphere *sphere)
{
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (check == 0)
			{
				check = get_sphere_center(line, check, i, sphere);
				i = get_index(line, i);
			}
			else if (check == 3)
			{
				check = get_sphere_diameter(line, check, i, sphere);
				i = get_index(line, i);
			}
			else if (check == 4)
			{
				check = get_sphere_color(line, check, i, sphere);
				i = get_index(line, i);
			}
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
}

void			get_sphere(char *line, t_rt *rt)
{
	int			i;
	int			check;
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	check = 0;
	i = 2;
	sphere_loop(line, i, check, sphere);
	push_sphere(rt->sphere, sphere, rt);
	free(sphere);
}
