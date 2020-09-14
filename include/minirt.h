/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:08:11 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/13 17:17:128 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "../libft/libft.h"
# include "mlx_int.h"
# include "elements.h"
# include "vector.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <ctype.h>
# include <stdio.h>

# define EPSILON 0.00001

/*
** Tracks how many of each parameter there is in a given .rt scene.
*/

typedef struct		s_qts
{
	int				reso;
	int				ambi;
	int				cam;
	int				lt;
	int				sp;
	int				pl;
	int				sq;
	int				cy;
	int				tr;
}					t_qts;

/*
** Holds values from the .rt file.
*/

typedef struct		s_rt
{
	t_qts			qts;
	t_reso			reso;
	t_ambi			ambi;
	t_cam			*cam;
	t_light			*light;
	t_sphere		*sphere;
	t_plane			*plane;
	t_square		*square;
	t_cylinder		*cylinder;
	t_triangle		*triangle;
}					t_rt;

/*
** Holds values needed for MiniLibX's functions.
*/

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*address;
	int				bpp;
	int				line_leng;
	int				endian;
}					t_mlx;

/*
** General parsing and error handling functions.
*/

void				init_rt(t_rt *rt);
void				init_sphere(t_rt *rt);
void				init_plane(t_rt *rt);
void				init_square(t_rt *rt);
void				init_cylinder(t_rt *rt);
void				init_triangle(t_rt *rt);
void				errormsg(int errornum);
void				*ec_malloc(size_t size);
void				rt_identify(char *line, t_rt *rt);
int					get_index(char *line, int i);
int					get_index_nocomma(char *line, int i);
double				get_coord(char *line, int i);
t_coord				fill_coord(double x, double y, double z);
int					get_color(char *line, int i);
t_color				fill_color(int r, int g, int b);

/*
** Window resolution parsing functions.
*/

void				get_resolution(char *line, t_rt *rt);

/*
** Ambient light and color parsing functions.
*/

void				get_ambient(char *line, t_rt *rt);
int					get_ambi_rgb(char *line, int check, int i, t_ambi *ambi);

/*
** Camera parsing functions.
*/

void				get_camera(char *line, t_rt *rt);
int					get_cam_view(char *line, int check, int i, t_cam *cam);
int					get_cam_pos(char *line, int check, int i, t_cam *cam);
int					get_cam_fov(char *line, int check, int i, t_cam *cam);

/*
** Light parsing functions.
*/

void				get_light(char *line, t_rt *rt);
int					get_light_pos(char *line, int check, int i, t_light *light);
int					get_light_color(char *line, int check, int i,
					t_light *light);

/*
** Sphere parsing functions.
*/

void				get_sphere(char *line, t_rt *rt);
int					get_sphere_center(char *line, int check, int i,
					t_sphere *light);
int					get_sphere_color(char *line, int check, int i,
					t_sphere *light);

/*
** Plane parsing functions.
*/

void				get_plane(char *line, t_rt *rt);
int					get_plane_pos(char *line, int check, int i, t_plane *light);
int					get_plane_color(char *line, int check, int i,
					t_plane *light);

/*
** Square parsing functions.
*/

void				get_square(char *line, t_rt *rt);
int					get_square_center(char *line, int check, int i,
					t_square *light);
int					get_square_color(char *line, int check, int i,
					t_square *light);
int					get_square_side(char *line, int check, int i,
					t_square *square);

/*
** Cylinder parsing functions.
*/

void				get_cylinder(char *line, t_rt *rt);
int					get_cylinder_pos(char *line, int check, int i,
					t_cylinder *light);
int					get_cylinder_color(char *line, int check, int i,
					t_cylinder *light);
int					get_cylinder_side(char *line, int check, int i,
					t_cylinder *cylinder);
int					get_cylinder_height(char *line, int check, int i,
					t_cylinder *cylinder);
int					get_cylinder_diameter(char *line, int check, int i,
					t_cylinder *cylinder);
int					get_cylinder_norm(char *line, int check, int i,
					t_cylinder *cylinder);

/*
** Triangle parsing functions.
*/

void				get_triangle(char *line, t_rt *rt);
int					get_triangle_p1(char *line, int check, int i,
					t_triangle *light);
int					get_triangle_p2(char *line, int check, int i,
					t_triangle *light);
int					get_triangle_p3(char *line, int check, int i,
					t_triangle *light);
int					get_triangle_color(char *line, int check, int i,
					t_triangle *light);

/*
** Free functions.
*/

void				free_lists(t_rt *rt);
void				free_camera(t_rt *rt);
void				free_light(t_rt *rt);
void				free_sphere(t_rt *rt);
void				free_plane(t_rt *rt);
void				free_square(t_rt *rt);
void				free_cylinder(t_rt *rt);
void				free_triangle(t_rt *rt);

/*
** Float utils
*/

int					double_equal(double a, double b);

/*
** Test functions.
*/

void				rt_window(t_rt *rt);
void  				projectile_test(char *times);

#endif
