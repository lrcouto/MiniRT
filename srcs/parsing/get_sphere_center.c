/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_center.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:55:09 by gsenra-a          #+#    #+#             */
/*   Updated: 2021/02/13 21:13:29 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		get_x_center(char *line, int check, int *idx, double *xyz)
{
	xyz[0] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_y_center(char *line, int check, int *idx, double *xyz)
{
	xyz[1] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_z_center(char *line, int check, int *idx, double *xyz)
{
	xyz[2] = get_coord(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

int				get_sphere_center(char *line, int check, int i,
t_sphere *sphere)
{
	double	*xyz;
	int		*idx;

	idx = &i;
	comma_check(line, *idx, 18);
	xyz = (double *)ec_malloc((sizeof(double) * 3));
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[*idx] >= '0' && line[*idx] <= '9') || line[*idx] == '-')
		{
			if (check == 0)
				check = get_x_center(line, check, idx, xyz);
			else if (check == 1)
				check = get_y_center(line, check, idx, xyz);
			else if (check == 2)
				check = get_z_center(line, check, idx, xyz);
		}
		*idx = *idx + 1;
	}
	if (check != 3)
		errormsg(18);
	sphere->center = create_tuple(xyz[0], xyz[1], xyz[2], 1);
	free(xyz);
	return (check);
}

int				get_sphere_diameter(char *line, int check, int i,
t_sphere *sphere)
{
	double	diameter;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] >= '0' || line[i] <= '9') && check == 3)
		{
			diameter = get_single_double(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	if (check != 4 || diameter <= 0)
		errormsg(46);
	sphere->diameter = diameter;
	sphere->radius = diameter / 2;
	return (check);
}
