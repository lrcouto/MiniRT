/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:06:33 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/31 19:33:05 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# define SPHERE 0
# define PLANE 1
# define SQUARE 2
# define CYLINDER 3
# define TRIANGLE 4

# include "minirt.h"

typedef struct			s_ray
{
	t_tuple				origin;
	t_tuple				direction;
}						t_ray;

/*
** Intersection -> obj_type: sphere 0, plane 1, square 2,
** cylinder 3 or triangle 4.
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
	unsigned long long	qty;
	struct s_intersec	*next;
}						t_intersec;

/*
** Ray operations.
*/

t_ray					create_ray(t_tuple origin, t_tuple direction);
t_tuple					ray_position(t_ray ray, double t);
void					intersect_sphere(t_ray ray, t_sphere *sphere,
						t_intersec *head);
t_polys					insert_sphere(t_sphere *sphere);
t_polys					insert_plane(t_plane *plane);
t_polys					insert_square(t_square *square);
t_polys					insert_cylinder(t_cylinder *cylinder);
t_polys					insert_triangle(t_triangle *triangle);
t_intersec				*init_intersec_list(t_intersec *list);
void					push_intersec(t_intersec *head, t_intersec *new);
t_intersec				*intersec_hit(t_intersec *head);
t_ray					transform_ray(t_ray ray, t_matrix transform);
void					set_transform_sphere(t_sphere *sphere, t_matrix transform);

#endif
