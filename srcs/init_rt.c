/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:35:24 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/05 23:27:32 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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
}
