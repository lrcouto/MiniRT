/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:06:37 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/19 18:28:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		push_light(t_light *head, t_light *new_light, t_rt *rt)
{
	t_light *current;

	current = head;
	new_light->next = NULL;
	if (rt->qts.lt == 0)
	{
		head->pos = new_light->pos;
		head->light = new_light->light;
		head->color = new_light->color;
		head->intensity = new_light->intensity;
		head->next = new_light->next;
		rt->qts.lt = rt->qts.lt + 1;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_light *)ec_malloc(sizeof(t_light));
	current->next->pos = new_light->pos;
	current->next->light = new_light->light;
	current->next->color = new_light->color;
	current->next->intensity = new_light->intensity;
	current->next->next = new_light->next;
	rt->qts.lt = rt->qts.lt + 1;
}

static int		get_light_light(char *line, int check, int i, t_light *light)
{
	double	lumi;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] == '1' || line[i] == '0') && check == 3)
		{
			lumi = get_single_double(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	if (lumi > 1 || lumi < 0)
		errormsg(16);
	light->light = lumi;
	return (check);
}

static void		light_loop(char *line, int i, int check, t_light *light)
{
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
		{
			if (check == 0)
			{
				check = get_light_pos(line, check, i, light);
				i = get_index(line, i);
			}
			else if (check == 3)
			{
				check = get_light_light(line, check, i, light);
				i = get_index(line, i);
			}
			else if (check == 4)
			{
				check = get_light_color(line, check, i, light);
				i = get_index(line, i);
			}
		}
		else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
			errormsg(5);
	}
}

void			get_light(char *line, t_rt *rt)
{
	int		i;
	int		check;
	t_light	*light;

	light = (t_light *)ec_malloc(sizeof(t_light));
	check = 0;
	i = 1;
	light_loop(line, i, check, light);
	light->intensity = scalar_color(normalize_color(light->color.r,
					light->color.g, light->color.b), light->light);
	push_light(rt->light, light, rt);
	free(light);
}
