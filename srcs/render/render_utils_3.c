/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:58:12 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 17:07:49 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static t_matrix	calculate_orientation(t_tuple left, t_tuple true_up,
t_tuple forward, t_tuple from)
{
	t_matrix	temp;
	t_matrix	translate;
	t_matrix	orientation;

	temp = create_matrix(4, 4);
	temp.matrix[0][0] = left.x;
	temp.matrix[0][1] = left.y;
	temp.matrix[0][2] = left.z;
	temp.matrix[1][0] = true_up.x;
	temp.matrix[1][1] = true_up.y;
	temp.matrix[1][2] = true_up.z;
	temp.matrix[2][0] = -1.0 * forward.x;
	temp.matrix[2][1] = -1.0 * forward.y;
	temp.matrix[2][2] = -1.0 * forward.z;
	temp.matrix[3][3] = 1.0;
	translate = translation(-1.0 * from.x, -1.0 * from.y, -1.0 * from.z);
	orientation = mult_matrix(temp, translate);
	free_matrix(temp);
	free_matrix(translate);
	return (orientation);
}

t_matrix		view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		up_normal;
	t_tuple		left;
	t_tuple		true_up;

	forward = normalize_v(subtract_tuple(to, from));
	up_normal = normalize_v(up);
	left = cross_product(forward, up_normal);
	true_up = cross_product(left, forward);
	return (calculate_orientation(left, true_up, forward, from));
}

void			intersect_all_polys(t_rt *rt, t_raycaster *rc)
{
	intersect_all_spheres(rt, rc);
	intersect_all_planes(rt, rc);
	intersect_all_squares(rt, rc);
	intersect_all_cylinders(rt, rc);
	intersect_all_triangles(rt, rc);
}

void			normalize_pixel_color(t_rgba *lt_output)
{
	if (lt_output->r > 1.0)
		lt_output->r = 1.0;
	if (lt_output->g > 1.0)
		lt_output->g = 1.0;
	if (lt_output->b > 1.0)
		lt_output->b = 1.0;
	if (lt_output->r < 0)
		lt_output->r = 0;
	if (lt_output->g < 0)
		lt_output->g = 0;
	if (lt_output->b < 0)
		lt_output->b = 0;
}

void			loading_bar(double percent, int total, t_rt *rt)
{
	int			ten;
	static int	counter;
	char		*camera;

	ten = total / 10;
	if (counter == 0)
		ft_putstr_fd("Rendering... \n▒", 1);
	if (counter == ten)
	{
		ft_putstr_fd("▒", 1);
		counter = 0;
	}
	counter++;
	if (percent == 1)
	{
		camera = ft_itoa(rt->qts.cam);
		ft_putstr_fd(" 100%\n", 1);
		ft_putstr_fd("Camera ", 1);
		ft_putstr_fd(camera, 1);
		ft_putstr_fd(" rendered successfully.\n", 1);
		free(camera);
	}
}
