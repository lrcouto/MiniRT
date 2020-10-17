/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:35:42 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/17 17:08:22 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	test_translation(double mx, double my, double mz, double px, double py, double pz)
{
	t_tuple		pt;
	t_tuple		vec;
	t_tuple		result;
	t_matrix	transform;
	t_matrix	inv;
	size_t		x;
	size_t		y;

	transform = translation(mx, my, mz);
	pt = create_tuple(px, py, pz, 1);
	vec = create_tuple(px, py, pz, 0);
	inv = invert_matrix(transform);

	printf("\nTransform\n");
	while (x < transform.row)
	{
		y = 0;
		while (y < transform.col)
		{
			printf(" %f ", transform.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("\nTranslation(%f, %f, %f) x Point(%f, %f, %f, %d)\n", mx, my, mz, pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(transform, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	printf("\nInverse(%f, %f, %f) x Point(%f, %f, %f, %d)\n", mx, my, mz, pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(inv, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	printf("\nTranslation(%f, %f, %f) x Vector(%f, %f, %f, %d)\n", mx, my, mz, vec.x, vec.y, vec.z, vec.w);
	result = mult_matrix_tuple(transform, vec);
	printf("vector(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	free_matrix(transform);
	free_matrix(inv);
}

void	test_scaling(double mx, double my, double mz, double px, double py, double pz)
{
	t_tuple		pt;
	t_tuple		vec;
	t_tuple		result;
	t_matrix	transform;
	t_matrix	inv;
	size_t		x;
	size_t		y;

	transform = scaling(mx, my, mz);
	pt = create_tuple(px, py, pz, 1);
	vec = create_tuple(px, py, pz, 0);
	inv = invert_matrix(transform);

	printf("\nSCALING\n");
	while (x < transform.row)
	{
		y = 0;
		while (y < transform.col)
		{
			printf(" %f ", transform.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("\nScaling(%f, %f, %f) x Point(%f, %f, %f, %d)\n", mx, my, mz, pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(transform, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	printf("\nInverse(%f, %f, %f) x Point(%f, %f, %f, %d)\n", mx, my, mz, pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(inv, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	printf("\nScaling(%f, %f, %f) x Vector(%f, %f, %f, %d)\n", mx, my, mz, vec.x, vec.y, vec.z, vec.w);
	result = mult_matrix_tuple(transform, vec);
	printf("vector(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	free_matrix(transform);
	free_matrix(inv);
}

void	test_rotation(void)
{
	t_tuple		pt;
	t_tuple		result;
	t_matrix	transform;
	t_matrix	inv;

	transform = rotate_x(M_PI / 2);
	pt = create_tuple(0, 1, 0, 1);
	inv = invert_matrix(transform);

	printf("\nROTATION X\n");
	printf("\nRotation(%f) x Point(%f, %f, %f, %d)\n", M_PI / 2, pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(transform, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	printf("\nInverse(%f) x Point(%f, %f, %f, %d)\n", M_PI / 2, pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(inv, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	printf("\nROTATION Y\n");
	free_matrix(transform);
	transform = rotate_y(M_PI / 2);
	pt = create_tuple(0, 0, 1, 1);

	printf("\nRotation(%f) x Point(%f, %f, %f, %d)\n", M_PI / 2, pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(transform, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	printf("\nROTATION Z\n");
	free_matrix(transform);
	transform = rotate_z(M_PI / 2);
	pt = create_tuple(0, 1, 0, 1);

	printf("\nRotation(%f) x Point(%f, %f, %f, %d)\n", M_PI / 2, pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(transform, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	free_matrix(transform);
	free_matrix(inv);
}

void	test_shearing(void)
{
	t_tuple		pt;
	t_shear		shear;
	t_tuple		result;
	t_matrix	transform;

	shear.xy = 1;
	shear.xz = 0;
	shear.yx = 0;
	shear.yz = 0;
	shear.zx = 0;
	shear.zy = 0;
	transform = shearing(shear);
	pt = create_tuple(2, 3, 4, 1);

	printf("\nSHEARING X in prop Y\n");
	printf("\nShearing() x Point(%f, %f, %f, %d)\n", pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(transform, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	printf("\nSHEARING Y in prop Z\n");
	free_matrix(transform);

	shear.xy = 0;
	shear.xz = 0;
	shear.yx = 0;
	shear.yz = 1;
	shear.zx = 0;
	shear.zy = 0;
	transform = shearing(shear);

	printf("\nShearing() x Point(%f, %f, %f, %d)\n", pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(transform, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	printf("\nSHEARING Z in prop X\n");
	free_matrix(transform);
	
	shear.xy = 0;
	shear.xz = 0;
	shear.yx = 0;
	shear.yz = 0;
	shear.zx = 1;
	shear.zy = 0;
	transform = shearing(shear);

	printf("\nShearing() x Point(%f, %f, %f, %d)\n", pt.x, pt.y, pt.z, pt.w);
	result = mult_matrix_tuple(transform, pt);
	printf("point(%f, %f, %f, %d)", result.x, result.y, result.z, result.w);
	printf("\n");

	free_matrix(transform);
}

void	test_chain_transform(void)
{
	t_tuple		pt;

	t_matrix	transform_rot;
	t_matrix	transform_scal;
	t_matrix	transform_trans;

	t_matrix	transform_result;
	t_matrix	transform_result_final;

	transform_rot = rotate_x(M_PI / 2);
	transform_scal = scaling(5, 5, 5);
	transform_trans = translation(10, 5, 7);

	transform_result = mult_matrix(transform_trans, transform_scal);

	transform_result_final = mult_matrix(transform_result, transform_rot);
	
	pt = create_tuple(1, 0, 1, 1);

	printf("\nCHAINING TRANSFORMATIONS\n");
	printf("BEFORE: point(%f, %f, %f, %d)", pt.x, pt.y, pt.z, pt.w);
	printf("\n");

	pt = mult_matrix_tuple(transform_result_final, pt);

	printf("AFTER: point(%f, %f, %f, %d)", pt.x, pt.y, pt.z, pt.w);
	printf("\n");

	free_matrix(transform_result);
	free_matrix(transform_result_final);
	free_matrix(transform_rot);
	free_matrix(transform_scal);
	free_matrix(transform_trans);
}