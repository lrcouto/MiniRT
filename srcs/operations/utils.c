/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 00:07:04 by lcouto            #+#    #+#             */
/*   Updated: 2021/01/01 17:11:41 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		double_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}

double	radians_to_degrees(double rad)
{
	return ((rad * 180.0) / M_PI);
}

double	degrees_to_radians(double degr)
{
	return ((degr * M_PI) / 180.0);
}
