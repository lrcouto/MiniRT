/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_p3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:19:39 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/11 16:32:07 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int		get_x_p3(char *line, int check, int *idx, double *xyz)
{
	xyz[0] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_y_p3(char *line, int check, int *idx, double *xyz)
{
	xyz[1] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_z_p3(char *line, int check, int *idx, double *xyz)
{
	xyz[2] = get_coord(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

int				get_triangle_p3(char *line, int check, int i,
t_triangle *triangle)
{
	double	*xyz;
	int		*idx;

	idx = &i;
	xyz = (double *)malloc((sizeof(double) * 3));
	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[*idx] >= '0' && line[*idx] <= '9') || line[*idx] == '-')
		{
			if (check == 6)
				check = get_x_p3(line, check, idx, xyz);
			else if (check == 7)
				check = get_y_p3(line, check, idx, xyz);
			else if (check == 8)
				check = get_z_p3(line, check, idx, xyz);
		}
		*idx = *idx + 1;
	}
	if (check != 9)
		errormsg(28);
	triangle->p3 = fill_coord(xyz[0], xyz[1], xyz[2]);
	free(xyz);
	return (check);
}
