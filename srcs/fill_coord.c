/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 20:15:45 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/06 21:33:44 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_coord		fill_coord(double x, double y, double z)
{
	t_coord	fill;

	fill.x = x;
	fill.y = y;
	fill.z = z;
	return (fill);
}
