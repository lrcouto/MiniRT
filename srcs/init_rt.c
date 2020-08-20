/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:35:24 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/20 15:58:00 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_rt(t_rt *rt)
{
	t_reso	reso;
	t_ambi	ambi;

	reso.width = 0;
	reso.height = 0;
	ambi.light = 0.0;
	ambi.blu = 0;
	ambi.gre = 0;
	ambi.red = 0;
	rt->reso = reso;
	rt->ambi = ambi;
}
