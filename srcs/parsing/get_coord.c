/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:00:12 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/12 00:56:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int		verification_loop(char *line, int j)
{
	while (line[j] != '.' && line[j] != '\0')
	{
		if (!(line[j] >= '0' && line[j] <= '9'))
		{
			if (line[j] == ',' || line[j] == ' ')
				return (j);
			errormsg(14);
		}
		j++;
	}
	if (line[j] != '\0')
		j++;
	if ((line[j] >= '0' && line[j] <= '9') && line[j] != '\0')
	{
		while (line[j] >= '0' && line[j] <= '9')
			j++;
	}
	else if ((!(line[j] >= '0' && line[j] <= '9')) && line[j] != '\0')
		errormsg(14);
	return (j);
}

static int		check_double_format(char *line, int i)
{
	int j;

	j = i;
	if (line[j] == '-')
		j++;
	if (line[j] >= '0' && line[j] <= '9')
		j = verification_loop(line, j);
	else
		errormsg(14);
	return (j);
}

double			get_coord(char *line, int i)
{
	double	coord;
	char	*temp;
	int		j;

	j = check_double_format(line, i);
	temp = ft_substr(line, i, i + j);
	coord = ft_atof(temp);
	free(temp);
	return (coord);
}
