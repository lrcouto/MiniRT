/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 15:57:15 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/20 20:15:49 by lcouto           ###   ########.fr       */
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

/*
** Holds values for window size.
*/

typedef struct	s_reso
{
	int			width;
	int			height;
}				t_reso;

/*
** Holds values for ambient lighting.
*/

typedef struct	s_ambi
{
	double		light;
	int			red;
	int			gre;
	int			blu;
}				t_ambi;

/*
** Holds values from the .rt file.
*/

typedef struct	s_rt
{
	t_reso		reso;
	t_ambi		ambi;

}				t_rt;

/*
** Holds values needed for MiniLibX's functions.
*/

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*address;
	int			bpp;
	int			line_leng;
	int			endian;
}				t_mlx;



int				get_next_line(int fd, char **line);
void			rt_identify(char *line, t_rt *rt);
void			get_resolution(char *line, t_rt *rt);
void			init_rt(t_rt *rt);
void			rt_window(t_rt *rt);
void			get_ambient(char *line, t_rt *rt);

#endif
