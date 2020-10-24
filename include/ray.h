/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:06:33 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/24 20:19:53 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minirt.h"

typedef struct			s_ray
{
	t_tuple				origin;
	t_tuple				direction;
}						t_ray;

/*
** Intersection -> obj_type: sphere 0, plane 1, square 2, cylinder 3 or triangle 4.
*/

typedef struct			s_polys {
	int					obj_type;
	t_sphere			*sphere;
	t_plane				*plane;
	t_square			*square;
	t_cylinder			*cylinder;
	t_triangle			*triangle;
}						t_polys;

typedef struct			s_intersec
{
	int					count;
	double				t1;
	double				t2;
	t_polys				poly;
	struct s_intersec	*next;
}						t_intersec;

/*
** Ray operations.
*/

t_ray					create_ray(t_tuple origin, t_tuple direction);
t_tuple					ray_position(t_ray ray, double t);
t_intersec				intersect_sphere(t_ray ray, t_sphere sphere);
t_polys					insert_sphere(t_sphere *sphere);
t_polys					insert_plane(t_plane *plane);
t_polys					insert_square(t_square *square);
t_polys					insert_cylinder(t_cylinder *cylinder);
t_polys					insert_triangle(t_triangle *triangle);

#endif