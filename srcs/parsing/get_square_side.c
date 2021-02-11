/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:35:59 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/10 18:30:06 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		get_square_side(char *line, int check, int i, t_square *square)
{
	double	side;

	while (line[i] != ' ' && line[i] != '\0')
	{
		if ((line[i] >= '0' || line[i] <= '9') && check == 6)
		{
			side = get_coord(line, i);
			i = get_index(line, i);
			check++;
		}
		i++;
	}
	square->side = side;
	return (check);
}
