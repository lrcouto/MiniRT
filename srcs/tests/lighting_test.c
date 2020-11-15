/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:14:54 by lcouto            #+#    #+#             */
/*   Updated: 2020/11/14 16:46:48 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	lighting_test(void)
{
	t_ltargs args;
	t_rgba	result;

	args.pos = create_tuple(0, 0, 0, 1);
	args.phong = default_phong();
	args.light.pos = create_tuple(0, 0, -10, 1);
	args.light.intensity = create_rgba(1, 1, 1, 1);
	args.eye_v = create_tuple(0, 0, -1, 0);
	args.normal_v = create_tuple(0, 0, -1, 0);
	result = lighting(args);
	printf("TESTE 1: R: %f G: %f B: %f\n", result.r, result.g, result.b);

	args.eye_v = create_tuple(0, (sqrt(2) / 2), (sqrt(2) / 2), 0);
	args.normal_v = create_tuple(0, 0, -1, 0);
	result = lighting(args);
	printf("TESTE 2: R: %f G: %f B: %f\n", result.r, result.g, result.b);

	args.light.pos = create_tuple(0, 10, -10, 1);
	args.eye_v = create_tuple(0, 0, -1, 0);
	args.normal_v = create_tuple(0, 0, -1, 0);
	result = lighting(args);
	printf("TESTE 3: R: %f G: %f B: %f\n", result.r, result.g, result.b);

	args.eye_v = create_tuple(0, (-1 * (sqrt(2) / 2)), (-1 * (sqrt(2) / 2)), 0);
	result = lighting(args);
	printf("TESTE 4: R: %f G: %f B: %f\n", result.r, result.g, result.b);

	args.light.pos = create_tuple(0, 0, 10, 1);
	args.eye_v = create_tuple(0, 0, -1, 0);
	result = lighting(args);
	printf("TESTE 5: R: %f G: %f B: %f\n", result.r, result.g, result.b);
}