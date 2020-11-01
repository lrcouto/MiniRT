/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_polys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:50:39 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/31 20:02:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void		init_triangle(t_rt *rt)
{
	t_triangle	*basetriangle;

	basetriangle = (t_triangle *)ec_malloc(sizeof(t_triangle));
	basetriangle->p1.x = 0;
	basetriangle->p1.y = 0;
	basetriangle->p1.z = 0;
	basetriangle->p1.w = 0;
	basetriangle->p2.x = 0;
	basetriangle->p2.y = 0;
	basetriangle->p2.z = 0;
	basetriangle->p2.w = 0;
	basetriangle->p3.x = 0;
	basetriangle->p3.y = 0;
	basetriangle->p3.z = 0;
	basetriangle->p3.w = 0;
	basetriangle->color.r = 0;
	basetriangle->color.g = 0;
	basetriangle->color.b = 0;
	basetriangle->next = NULL;
	rt->triangle = basetriangle;
}

void		init_cylinder(t_rt *rt)
{
	t_cylinder	*basecylinder;

	basecylinder = (t_cylinder *)ec_malloc(sizeof(t_cylinder));
	basecylinder->pos.x = 0;
	basecylinder->pos.y = 0;
	basecylinder->pos.z = 0;
	basecylinder->pos.w = 0;
	basecylinder->norm = 0;
	basecylinder->diameter = 0;
	basecylinder->height = 0;
	basecylinder->color.r = 0;
	basecylinder->color.g = 0;
	basecylinder->color.b = 0;
	basecylinder->next = NULL;
	rt->cylinder = basecylinder;
}

void		init_square(t_rt *rt)
{
	t_square	*basesquare;

	basesquare = (t_square *)ec_malloc(sizeof(t_square));
	basesquare->center.x = 0;
	basesquare->center.y = 0;
	basesquare->center.z = 0;
	basesquare->center.w = 0;
	basesquare->norm = 0;
	basesquare->side = 0;
	basesquare->color.r = 0;
	basesquare->color.g = 0;
	basesquare->color.b = 0;
	basesquare->next = NULL;
	rt->square = basesquare;
}

void		init_plane(t_rt *rt)
{
	t_plane	*baseplane;

	baseplane = (t_plane *)ec_malloc(sizeof(t_plane));
	baseplane->pos.x = 0;
	baseplane->pos.y = 0;
	baseplane->pos.z = 0;
	baseplane->pos.w = 0;
	baseplane->norm = 0;
	baseplane->color.r = 0;
	baseplane->color.g = 0;
	baseplane->color.b = 0;
	baseplane->next = NULL;
	rt->plane = baseplane;
}

void		init_sphere(t_rt *rt)
{
	t_sphere	*basesphere;

	basesphere = (t_sphere *)ec_malloc(sizeof(t_sphere));
	basesphere->center.x = 0;
	basesphere->center.y = 0;
	basesphere->center.z = 0;
	basesphere->center.w = 0;
	basesphere->diameter = 0;
	basesphere->color.r = 0;
	basesphere->color.g = 0;
	basesphere->color.b = 0;
	basesphere->transform = create_id_matrix();
	basesphere->next = NULL;
	rt->sphere = basesphere;
}
