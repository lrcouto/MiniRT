/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:04:41 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/13 19:26:10 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"

typedef struct	s_tuple
{
	double		x;
	double		y;
	double		z;
	int			w;
}				t_tuple;

t_tuple			create_tuple(double x, double y, double z, int w);
t_tuple			add_tuple(t_tuple t1, t_tuple t2);
t_tuple			subtract_tuple(t_tuple t1, t_tuple t2);
t_tuple			negate_tuple(t_tuple t1);
t_tuple			scalar_x_tuple(t_tuple t1, double times);
double			vector_magnitude(t_tuple t1);
t_tuple			normalize_v(t_tuple t1);
double			dot_product(t_tuple t1, t_tuple t2);
t_tuple			cross_product(t_tuple t1, t_tuple t2);

#endif