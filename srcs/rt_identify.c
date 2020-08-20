/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:08:06 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/20 19:41:04 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	rt_identify(char *line, t_rt *rt)
{
	if (line[0] == 'R' && line[1] == ' ')
		get_resolution(line, rt);
	else if (line[0] == 'A' && line[1] == ' ')
		get_ambient(line, rt);
	else
	{
		ft_putstr_fd("Error: invalid header.\n", 1);
		exit(0);
	}
}
