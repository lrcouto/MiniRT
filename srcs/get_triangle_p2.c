/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:00:30 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/09/11 16:31:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int		get_x_p2(char *line, int check, int *idx, double *xyz)
{
	xyz[0] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_y_p2(char *line, int check, int *idx, double *xyz)
{
	xyz[1] = get_coord(line, *idx);
	*idx = get_index_nocomma(line, *idx);
	check++;
	return (check);
}

static int		get_z_p2(char *line, int check, int *idx, double *xyz)
{
	xyz[2] = get_coord(line, *idx);
	*idx = get_index(line, *idx);
	check++;
	return (check);
}

int				get_triangle_p2(char *line, int check, int i,
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
			if (check == 3)
				check = get_x_p2(line, check, idx, xyz);
			else if (check == 4)
				check = get_y_p2(line, check, idx, xyz);
			else if (check == 5)
				check = get_z_p2(line, check, idx, xyz);
		}
		*idx = *idx + 1;
	}
	if (check != 6)
		errormsg(28);
	triangle->p2 = fill_coord(xyz[0], xyz[1], xyz[2]);
	free(xyz);
	return (check);
}
