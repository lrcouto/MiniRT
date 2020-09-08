/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:52:38 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/08 16:49:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int		get_ambi_light(char *line, int check, int i, t_ambi *ambi)
{
	double	light;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] == '1' || line[i] == '0') && check == 0)
		{
			light = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	if (light > 1 || light < 0)
		errormsg(6);
	ambi->light = light;
	return (check);
}

static int		ambient_loop(char *line, int i, int check, t_ambi *ambi)
{
	while (line[i] != '\0')
	{
	if (line[i] == ' ')
		i++;
	else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
	{
		if (check == 0)
		{
			check = get_ambi_light(line, check, i, ambi);
			i = get_index(line, i);
		}
		else if (check == 1)
		{
			check = get_ambi_rgb(line, check, i, ambi);
			i = get_index(line, i);
		}
	}
	else if ((!(line[i] >= '0' && line[i] <= '9')) || (!(line[i] == ' ')))
		errormsg(5);
	}
	return (check);
}

/*
** TODO: remove printf later.
*/

void			get_ambient(char *line, t_rt *rt)
{
	int		i;
	int		check;
	t_ambi	ambi;

	check = 0;
	i = 1;
	check = ambient_loop(line, i, check, &ambi);
	if (check != 4)
		errormsg(7);
	rt->ambi = ambi;
	printf("AMBIENT - LIGHT: %f R: %d G: %d B: %d\n", rt->ambi.light,
	rt->ambi.color.r, rt->ambi.color.g, rt->ambi.color.b);
}
