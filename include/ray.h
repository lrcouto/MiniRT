/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:06:33 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/07 22:07:29 by lcouto           ###   ########.fr       */
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
	double				t;
	t_polys				poly;
	unsigned long long	qty;
	struct s_intersec	*next;
}						t_intersec;

typedef struct			s_raycaster
{
	int					x;
	int					y;
	t_ray				ray;
	t_intersec			*intersec_list;
	t_intersec			*hit;
}						t_raycaster;

/*
** Ray operations.
*/

t_ray					create_ray(t_tuple origin, t_tuple direction);
t_tuple					ray_position(t_ray ray, double t);
t_ray					transform_ray(t_ray ray, t_matrix transform);

/*
** Intersection operations.
*/

t_polys					insert_sphere(t_sphere *sphere);
t_polys					insert_plane(t_plane *plane);
t_polys					insert_square(t_square *square);
t_polys					insert_cylinder(t_cylinder *cylinder);
t_polys					insert_triangle(t_triangle *triangle);
t_intersec				*init_intersec_list(t_intersec *list);
void					push_intersec(t_intersec *head, t_intersec *new);
t_intersec				*intersec_hit(t_intersec *head);
void					intersect_sphere(t_ray ray, t_sphere *sphere,
						t_intersec *head);
void					intersect_plane(t_ray ray, t_plane *plane,
t_intersec *head);
void					intersect_square(t_ray ray, t_square *square,
t_intersec *head);
void					intersect_cylinder(t_ray ray, t_cylinder *cylinder,
t_intersec *head);
void					intersect_triangle(t_ray ray, t_triangle *triangle,
t_intersec *head);

#endif
