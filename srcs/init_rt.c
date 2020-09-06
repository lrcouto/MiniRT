/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:35:24 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/06 01:12:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	init_camera(t_rt *rt)
{
	t_cam	*basecam;

	basecam = NULL;
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

void	init_rt(t_rt *rt)
{
	t_reso	reso;
	t_ambi	ambi;

	reso.width = 0;
	reso.height = 0;
	reso.qty = 0;
	ambi.light = 0.0;
	ambi.color.b = 0;
	ambi.color.r = 0;
	ambi.color.g = 0;
	ambi.qty = 0;
	rt->reso = reso;
	rt->ambi = ambi;
	init_camera(rt);
}
