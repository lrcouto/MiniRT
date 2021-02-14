/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:47:39 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 21:14:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		get_x_norm(char *line, int check, int *idx, double *xyz)
{
	xyz[0] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_y_norm(char *line, int check, int *idx, double *xyz)
{
	xyz[1] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_z_norm(char *line, int check, int *idx, double *xyz)
{
	xyz[2] = get_coord(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

int				get_square_norm(char *line, int check, int i, t_square *square)
{
	double	*xyz;
	int		*idx;

	idx = &i;
	comma_check(line, *idx, 24);
	xyz = (double *)ec_malloc((sizeof(double) * 3));
	while (line[*idx] != ' ' && line[*idx] != '\0')
	{
		if (line[*idx] == '1' || line[*idx] == '0' || line[*idx] == '-')
		{
			if (check == 3)
				check = get_x_norm(line, check, idx, xyz);
			else if (check == 4)
				check = get_y_norm(line, check, idx, xyz);
			else if (check == 5)
				check = get_z_norm(line, check, idx, xyz);
		}
		*idx = *idx + 1;
	}
	if ((xyz[0] > 1 || xyz[0] < -1) || (xyz[1] > 1 || xyz[1] < -1) ||
		(xyz[2] > 1 || xyz[2] < -1) || (check != 6))
		errormsg(24);
	square->norm = create_tuple(xyz[0], xyz[1], xyz[2], 0);
	free(xyz);
	return (check);
}
