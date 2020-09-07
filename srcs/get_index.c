/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 20:18:04 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/06 21:33:44 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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
