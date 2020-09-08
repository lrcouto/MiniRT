/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:10:35 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/08 15:52:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int			get_color(char *line, int i)
{
	int		color;
	char	*temp;
	int		j;

	j = i;
	if (line[j] == '-')
		errormsg(8);
	if (line[j] >= '0' && line[j] <= '9')
	{
		while (line[j] >= '0' && line[j] <= '9')
			j++;
	}
	temp = ft_substr(line, i, i + j);
	color = ft_atoi(temp);
	free(temp);
	if (color > 255 || color < 0)
		errormsg(8);
	return (color);
}
