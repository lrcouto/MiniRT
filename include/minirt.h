/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-aniehes <gsenra-aniehes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 15:57:15 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/05 22:49:23 byniehesgsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "../libft/libft.h"
# include "mlx_int.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <ctype.h>
# include <stdio.h>

typedef struct		s_qts
{
	int			reso;
	int			ambi;
	int			cam;
	int			lt;
	int			sp;
	int			pl;
	int			sq;
	int			cy;
	int			tr;
}					t_qts;

/*
** Holds values for X, Y, Z coordinates.
*/

typedef struct		s_coord
{
	double		x;
	double		y;
	double		z;
}					t_coord;

/*
** Holds values for RGB colors.
*/

typedef struct		s_color
{
	int			r;
	int			g;
	int			b;
}					t_color;

/*
** Holds values for window size.
*/

typedef struct		s_reso
{
	int			width;
	int			height;
}					t_reso;

/*
** Holds values for ambient lighting.
*/

typedef struct		s_ambi
{
	double		light;
	t_color		color;
}					t_ambi;

/*
** Holds values for cameras.
*/

typedef struct		s_cam
{
	t_coord			view;
	t_coord			pos;
	int				fov;
	struct s_cam	*next;
}					t_cam;

/*
** Holds values from the .rt file.
*/

typedef struct		s_rt
{
	t_reso		reso;
	t_ambi		ambi;
	t_cam		*cam;
	t_qts		qts;

}					t_rt;

/*
** Holds values needed for MiniLibX's functions.
*/

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*address;
	int			bpp;
	int			line_leng;
	int			endian;
}					t_mlx;

void				rt_identify(char *line, t_rt *rt);
void				get_resolution(char *line, t_rt *rt);
void				init_rt(t_rt *rt);
void				rt_window(t_rt *rt);
void				get_ambient(char *line, t_rt *rt);
void				errormsg(int errornum);
double				ft_atof(char s[]);
void				get_camera(char *line, t_rt *rt);
double				get_coord(char *line, int i);
void				free_lists(t_rt *rt);
t_coord				fill_coord(double x, double y, double z);
int					get_index(char *line, int i);
int					get_index_nocomma(char *line, int i);
int					get_cam_view(char *line, int check, int i, t_cam *cam);
int					get_cam_pos(char *line, int check, int i, t_cam *cam);
int					get_cam_fov(char *line, int check, int i, t_cam *cam);
void				get_ambient(char *line, t_rt *rt);
int					get_ambi_rgb(char *line, int check, int i, t_ambi *ambi);
t_color				fill_color(int r, int g, int b);
int					get_color(char *line, int i);

#endif
