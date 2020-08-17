/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 15:57:15 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/17 19:38:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <ctype.h>
# include <stdio.h>
// # include "mlx_int.h"

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


int				get_next_line(int fd, char **line);
void			rt_identify(char *line);
void			get_resolution(char *line);

#endif
