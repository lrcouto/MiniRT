/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:20:12 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/10 19:13:15 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "minirt.h"

/*
** Holds values for X, Y, Z coordinates.
*/

typedef struct			s_coord
{
	double				x;
	double				y;
	double				z;
}						t_coord;

/*
** Holds values for RGB colors.
*/

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

/*
** Holds values for window size.
*/

typedef struct			s_reso
{
	int					width;
	int					height;
}						t_reso;

/*
** Holds values for ambient lighting.
*/

typedef struct			s_ambi
{
	double				light;
	t_color				color;
}						t_ambi;

/*
** Holds values for cameras.
*/

typedef struct			s_cam
{
	t_coord				view;
	t_coord				pos;
	int					fov;
	struct s_cam		*next;
}						t_cam;

/*
** Holds values for lights.
*/

typedef struct			s_light
{
	t_coord				pos;
	double				light;
	t_color				color;
	struct s_light		*next;
}						t_light;

/*
** Holds values for spheres.
*/

typedef struct			s_sphere
{
	t_coord				center;
	double				diameter;
	t_color				color;
	struct s_sphere		*next;
}						t_sphere;

/*
** Holds values for planes.
*/

typedef struct			s_plane
{
	t_coord				pos;
	double				norm;
	t_color				color;
	struct s_plane		*next;
}						t_plane;

/*
** Holds values for squares.
*/

typedef struct			s_square
{
	t_coord				center;
	double				norm;
	double				side;
	t_color				color;
	struct s_square		*next;
}						t_square;

/*
** Holds values for cylinder.
*/

typedef struct			s_cylinder
{
	t_coord				pos;
	double				norm;
	double				diameter;
	double				height;
	t_color				color;
	struct s_cylinder	*next;
}						t_cylinder;

/*
** Holds values for triangle.
*/

typedef struct			s_triangle
{
	t_coord				p1;
	t_coord				p2;
	t_coord				p3;
	t_color				color;
	struct s_triangle	*next;
}						t_triangle;

#endif
