/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:00:25 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/13 17:27:44 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		get_index(char *line, int i)
{
	int j;

	j = i;
	while ((line[j] >= '0' && line[j] <= '9') ||
			line[j] == '.' || line[j] == ',' || line[j] == '-')
		j++;
	if (line[j] != ' ' && line[j] != '\0')
		errormsg(5);
	return (j);
}
