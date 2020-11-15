/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:42:35 by lcouto            #+#    #+#             */
/*   Updated: 2020/11/14 15:24:28 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_rgba	add_color(t_rgba c1, t_rgba c2)
{
	t_rgba	new;

	new.r = c1.r + c2.r;
	new.g = c1.g + c2.g;
	new.b = c1.b + c2.b;
	return (new);
}

t_rgba	subt_color(t_rgba c1, t_rgba c2)
{
	t_rgba	new;

	new.r = c1.r - c2.r;
	new.g = c1.g - c2.g;
	new.b = c1.b - c2.b;
	return (new);
}

t_rgba	scalar_color(t_rgba color, double scalar)
{
	t_rgba	new;

	new.r = color.r * scalar;
	new.g = color.g * scalar;
	new.b = color.b * scalar;
	return (new);
}

t_rgba	mult_color(t_rgba c1, t_rgba c2)
{
	t_rgba	new;

	new.r = c1.r * c2.r;
	new.g = c1.g * c2.g;
	new.b = c1.b * c2.b;
	new.a = 1;
	return (new);
}
