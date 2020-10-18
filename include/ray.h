/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:06:33 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/18 20:07:46 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minirt.h"

typedef struct	s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}				t_ray;

typedef struct	s_intersec
{
	int			count;
	double		t1;
	double		t2;
}				t_intersec;

/*
** Ray operations.
*/

t_ray			create_ray(t_tuple origin, t_tuple direction);
t_tuple			ray_position(t_ray ray, double t);
t_intersec		intersection(t_ray ray, t_sphere sphere);

#endif