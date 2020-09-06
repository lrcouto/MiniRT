/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 21:56:59 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/05 23:27:32 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int		check_double_format(char *line, int i)
{
	int j;

	j = i;
	if (line[j] == '-')
		j++;
	if (line[j] >= '0' && line[j] <= '9')
	{
		while (line[j] != '.')
		{
			if (!(line[j] >= '0' && line[j] <= '9'))
				errormsg(14);
			j++;
		}
		j++;
		if (line[j] >= '0' && line[j] <= '9')
		{
			while (line[j] >= '0' && line[j] <= '9')
				j++;
		}
		else if (!(line[j] >= '0' && line[j] <= '9'))
			errormsg(14);
	}
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
