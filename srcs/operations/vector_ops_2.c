/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 19:05:29 by lcouto            #+#    #+#             */
/*   Updated: 2020/11/14 15:38:50 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double		vector_magnitude(t_tuple t1)
{
	return (sqrt((t1.x * t1.x) + (t1.y * t1.y) +
			(t1.z * t1.z) + (t1.w * t1.w)));
}

t_tuple		normalize_v(t_tuple t1)
{
	double magnitude;

	magnitude = vector_magnitude(t1);
	if (magnitude == 0)
	{
		t1.x = 0;
		t1.y = 0;
		t1.z = 0;
		t1.w = 0;
	}
	else
	{
		t1.x = t1.x / magnitude;
		t1.y = t1.y / magnitude;
		t1.z = t1.z / magnitude;
		t1.w = t1.w / magnitude;
	}
	return (t1);
}

double		dot_product(t_tuple t1, t_tuple t2)
{
	double result;

	result = t1.x * t2.x + t1.y * t2.y + t1.z * t2.z + t1.w * t2.w;
	return (result);
}

t_tuple		cross_product(t_tuple t1, t_tuple t2)
{
	t_tuple new;

	new.x = (t1.y * t2.z - t1.z * t2.y);
	new.y = (t1.z * t2.x - t1.x * t2.z);
	new.z = (t1.x * t2.y - t1.y * t2.x);
	new.w = 0;
	return (new);
}
