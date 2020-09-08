/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:00:58 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/08 17:221:15 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void		init_light(t_rt *rt)
{
	t_light	*baselight;
	
	baselight = (t_light *)malloc(sizeof(t_light));
	baselight->pos.x = 0;
	baselight->pos.y = 0;
	baselight->pos.z = 0;
	baselight->light = 0;
	baselight->color.r = 0;
	baselight->color.g = 0;
	baselight->color.b = 0;
	baselight->next = NULL;
	rt->light = baselight;
}

static void		init_qts(t_rt *rt)
{
	rt->qts.reso = 0;
	rt->qts.ambi = 0;
	rt->qts.cam = 0;
	rt->qts.lt = 0;
	rt->qts.sp = 0;
	rt->qts.pl = 0;
	rt->qts.sq = 0;
	rt->qts.cy = 0;
	rt->qts.tr = 0;
}

static void		init_camera(t_rt *rt)
{
	t_cam	*basecam;

	basecam = (t_cam *)malloc(sizeof(t_cam));
	basecam->view.x = 0;
	basecam->view.y = 0;
	basecam->view.z = 0;
	basecam->pos.x = 0;
	basecam->pos.y = 0;
	basecam->pos.z = 0;
	basecam->fov = 0;
	basecam->next = NULL;
	rt->cam = basecam;
}

void			init_rt(t_rt *rt)
{
	t_reso	reso;
	t_ambi	ambi;

	init_qts(rt);
	reso.width = 0;
	reso.height = 0;
	ambi.light = 0.0;
	ambi.color.b = 0;
	ambi.color.r = 0;
	ambi.color.g = 0;
	rt->reso = reso;
	rt->ambi = ambi;
	init_camera(rt);
	init_light(rt);
}
