/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 20:46:59 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/06 21:33:44 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int		get_cam_view(char *line, int check, int i, t_cam *cam)
{
	double	x;
	double	y;
	double	z;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if (((line[i] >= '0' && line[i] <= '9') ||
			line[i] == '-') && check == 0)
		{
			x = get_coord(line, i);
			i = get_index_nocomma(line, i);
			check++;
		}
		else if (((line[i] >= '0' && line[i] <= '9') ||
				line[i] == '-') && check == 1)
		{
			y = get_coord(line, i);
			i = get_index_nocomma(line, i);
			check++;
		}
		else if (((line[i] >= '0' && line[i] <= '9') ||
				line[i] == '-') && check == 2)
		{
			z = get_coord(line, i);
			i = get_index_nocomma(line, i);
			check++;
		}
		i++;
	}
	if (check != 3)
		errormsg(12);
	cam->view = fill_coord(x, y, z);
	return (check);
}
