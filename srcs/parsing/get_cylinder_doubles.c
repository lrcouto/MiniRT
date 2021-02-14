/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_doubles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:48:44 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 18:18:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		get_cylinder_height(char *line, int check, int i,
t_cylinder *cylinder)
{
	double	height;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] >= '0' || line[i] <= '9') && check == 7)
		{
			height = get_single_double(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	if (check != 8 || height <= 0)
		errormsg(48);
	cylinder->height = height;
	return (check);
}

int		get_cylinder_diameter(char *line, int check, int i,
t_cylinder *cylinder)
{
	double	diameter;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] >= '0' || line[i] <= '9') && check == 6)
		{
			diameter = get_single_double(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	if (check != 7 || diameter <= 0)
		errormsg(47);
	cylinder->diameter = diameter;
	cylinder->radius = diameter / 2;
	return (check);
}
