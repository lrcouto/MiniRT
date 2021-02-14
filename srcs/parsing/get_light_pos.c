/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:23:09 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 21:19:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		get_x_pos(char *line, int check, int *idx, double *xyz)
{
	xyz[0] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_y_pos(char *line, int check, int *idx, double *xyz)
{
	xyz[1] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_z_pos(char *line, int check, int *idx, double *xyz)
{
	xyz[2] = get_coord(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

int				get_light_pos(char *line, int check, int i, t_light *light)
{
	double	*xyz;
	int		*idx;

	idx = &i;
	comma_check(line, *idx, 15);
	xyz = (double *)ec_malloc((sizeof(double) * 3));
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[*idx] >= '0' && line[*idx] <= '9') || line[*idx] == '-')
		{
			if (check == 0)
				check = get_x_pos(line, check, idx, xyz);
			else if (check == 1)
				check = get_y_pos(line, check, idx, xyz);
			else if (check == 2)
				check = get_z_pos(line, check, idx, xyz);
		}
		*idx = *idx + 1;
	}
	if (check != 3)
		errormsg(15);
	light->pos = create_tuple(xyz[0], xyz[1], xyz[2], 1);
	free(xyz);
	return (check);
}
