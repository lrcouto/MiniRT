/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:08:06 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/14 20:09:13 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	rt_identify(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		get_resolution(line);
	else
		printf("NOPE.\n");
}
