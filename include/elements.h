/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:49:18 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/12 21:51:47 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "minirt.h"

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
	t_tuple				view;
	t_tuple				pos;
	double				fov;
	double				half_height;
	double				half_width;
	double				pixel_size;
	t_tuple				origin;
	t_matrix			transform;
	void				*img;
	char				*address;
	struct s_cam		*next;
}						t_cam;

/*
** Holds values for lights.
*/

typedef struct			s_light
{
	t_tuple				pos;
	double				light;
	t_color				color;
	t_rgba				intensity;
	struct s_light		*next;
}						t_light;

/*
** Holds values for a Phong material.
*/

typedef struct			s_phong
{
	t_rgba				color;
	double				diffuse;
	double				ambient;
	double				specular;
	double				shininess;
	double				reflect;
}						t_phong;

/*
** Arguments to be used in the lighting function.
*/

typedef struct			s_ltargs
{
	t_phong				phong;
	t_light				light;
	t_tuple				pos;
	t_tuple				eye_v;
	t_tuple				normal_v;
}						t_ltargs;

/*
** Variables to be used in the lighting function.
*/

typedef struct			s_ltparams
{
	double				light_dot_normal;
	double				reflect_dot_eye;
	t_tuple				effective_color;
	t_tuple				light_v;
	t_tuple				ambient;
	t_tuple				diffuse;
	t_tuple				specular;
	t_tuple				reflect_v;
}						t_ltparams;

/*
** Holds values for spheres.
*/

typedef struct			s_sphere
{
	t_tuple				center;
	double				diameter;
	double				radius;
	t_color				color;
	t_matrix			transform;
	t_phong				phong;
	struct s_sphere		*next;
}						t_sphere;

/*
** Holds values for planes.
*/

typedef struct			s_plane
{
	t_tuple				pos;
	t_tuple				norm;
	t_color				color;
	t_phong				phong;
	t_matrix			transform;
	struct s_plane		*next;
}						t_plane;

/*
** Holds values for squares.
*/

typedef struct			s_square
{
	t_tuple				center;
	t_tuple				norm;
	double				side;
	t_color				color;
	t_phong				phong;
	t_matrix			transform;
	struct s_square		*next;
}						t_square;

/*
** Holds values for cylinder.
*/

typedef struct			s_cylinder
{
	t_tuple				pos;
	t_tuple				norm;
	double				diameter;
	double				radius;
	double				height;
	t_color				color;
	t_phong				phong;
	t_matrix			transform;
	struct s_cylinder	*next;
}						t_cylinder;

/*
** Holds values for triangle.
*/

typedef struct			s_triangle
{
	t_tuple				p1;
	t_tuple				p2;
	t_tuple				p3;
	t_color				color;
	t_phong				phong;
	t_tuple				edgevec_1;
	t_tuple				edgevec_2;
	t_matrix			transform;
	struct s_triangle	*next;
}						t_triangle;

/*
** Initializes phong material with default values.
*/

t_phong					default_phong(void);

#endif
