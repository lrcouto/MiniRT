/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:01:19 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/11 16:31:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	rt_id_polys(char *line, t_rt *rt)
{
	if (ft_strncmp(line, "sp ", 3) == 0)
		get_sphere(line, rt);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		get_plane(line, rt);
	else if (ft_strncmp(line, "sq ", 3) == 0)
		get_square(line, rt);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		get_cylinder(line, rt);
	else if (ft_strncmp(line, "tr ", 3) == 0)
		get_triangle(line, rt);
}

static int	valid_poly(char *line)
{
	if (ft_strncmp(line, "sp ", 3) == 0 || ft_strncmp(line, "pl ", 3) == 0 ||
	ft_strncmp(line, "sq ", 3) == 0 || ft_strncmp(line, "cy ", 3) == 0 ||
	ft_strncmp(line, "tr ", 3) == 0)
		return (1);
	else
		return (0);
}

void		rt_identify(char *line, t_rt *rt)
{
	if (line[0] == 'R' && line[1] == ' ')
	{
		rt->qts.reso = rt->qts.reso + 1;
		if (rt->qts.reso > 1)
			errormsg(9);
		get_resolution(line, rt);
	}
	else if (line[0] == 'A' && line[1] == ' ')
	{
		rt->qts.ambi = rt->qts.ambi + 1;
		if (rt->qts.ambi > 1)
			errormsg(10);
		get_ambient(line, rt);
	}
	else if (line[0] == 'c' && line[1] == ' ')
		get_camera(line, rt);
	else if (line[0] == 'l' && line[1] == ' ')
		get_light(line, rt);
	else if (valid_poly(line) == 1)
		rt_id_polys(line, rt);
	else if (line[0] == '\n' || line[0] == '\0')
		return ;
	else
		errormsg(2);
}
