/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_doubles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:48:44 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/11 16:31:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int		get_cylinder_height(char *line, int check, int i,
t_cylinder *cylinder)
{
	double	height;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] >= '0' || line[i] <= '9') && check == 5)
		{
			height = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	cylinder->height = height;
	return (check);
}

int		get_cylinder_diameter(char *line, int check, int i,
t_cylinder *cylinder)
{
	double	diameter;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] >= '0' || line[i] <= '9') && check == 4)
		{
			diameter = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	cylinder->diameter = diameter;
	return (check);
}

int		get_cylinder_norm(char *line, int check, int i,
t_cylinder *cylinder)
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
		errormsg(27);
	cylinder->norm = norm;
	return (check);
}
