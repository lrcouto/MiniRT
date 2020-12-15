/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:52:33 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/13 18:57:022 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void print_intersec(t_intersec *intersec_list)
{
	t_intersec	*tmp_intersec;
	t_intersec	*current;

	current = intersec_list;
	while (current != NULL)
	{
		tmp_intersec = current;
		current = current->next;
		printf("T: %f\n", tmp_intersec->t);
	}
}

void				intersect_world_test(t_rt *rt)
{
	t_ray ray;
	t_intersec *intersec_list;
	t_sphere *current;

	render_sphere_transform(rt->sphere);
	intersec_list = (t_intersec *)ec_malloc(sizeof(t_intersec));
	intersec_list = init_intersec_list(intersec_list);

	ray = create_ray(create_tuple(0, 0, -5, 1), create_tuple(0, 0, 1, 0));

	current = rt->sphere;
	while(current->next != NULL)
	{
		intersect_sphere(ray, current, intersec_list);

		current = current->next;
	}
	intersect_sphere(ray, current, intersec_list);

	print_intersec(intersec_list);

	free_intersecs(intersec_list);
}

void	test_multiple_transforms(void)
{
	t_sphere	*sphere;
	t_tuple		s_normal;
	t_matrix	scale;
	t_matrix	rotate;

	scale = scaling(1, 0.5, 1);
	rotate = rotate_z(M_PI / 5);
	sphere = (t_sphere *)ec_malloc(sizeof(t_sphere));
	sphere->center = create_tuple(0, 0, 0, 1);
	sphere->transform = mult_matrix(scale, rotate);
	sphere->radius = 0.5;
	sphere->diameter = 1;
	
	s_normal = sphere_normal(sphere, create_tuple(0, sqrt(2) / 2, (sqrt(2) / 2) * -1, 1));
	printf("point(%f, %f, %f, %d)", s_normal.x, s_normal.y, s_normal.z, s_normal.w);
	free_matrix(sphere->transform);
	free_matrix(scale);
	free_matrix(rotate);
}

void	test_view_transformation(void)
{
	size_t	i;
	size_t	j;
	t_matrix trans;
	
	trans = view_transform(create_tuple(1, 3, 2, 1), create_tuple(4, -2, 8, 1), create_tuple(1, 1, 0, 0));
	i = 0;
	while (i < trans.row)
	{
		j = 0;
		while (j < trans.col)
		{
			printf(" %f ", trans.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	free_matrix(trans);
}