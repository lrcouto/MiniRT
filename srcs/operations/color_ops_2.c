/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:28:55 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/26 20:04:45 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_rgba	normalize_color(int r, int g, int b)
{
	t_rgba	norm;

	norm.r = (double)r / 255;
	norm.g = (double)g / 255;
	norm.b = (double)b / 255;
	norm.a = 1;
	return (norm);
}

t_color	denorm_color(t_rgba norm)
{
	t_color	denorm;

	denorm.r = (int)norm.r * 255;
	denorm.g = (int)norm.g * 255;
	denorm.b = (int)norm.b * 255;
	return (denorm);
}