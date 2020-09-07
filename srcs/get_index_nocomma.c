/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_nocomma.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 20:24:03 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/06 20:26:11 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int		get_index_nocomma(char *line, int i)
{
	int j;

	j = i;
	while ((line[j] >= '0' && line[j] <= '9') ||
			line[j] == '.' || line[j] == '-')
		j++;
	return (j);
}
