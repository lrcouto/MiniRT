/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:58:06 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/31 20:01:35 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_matrix	rotate_x(double rad)
{
	t_matrix	transform;

	transform = create_matrix(4, 4);
	transform.matrix[0][0] = 1;
	transform.matrix[1][1] = cos(rad);
	transform.matrix[1][2] = -1 * sin(rad);
	transform.matrix[2][1] = sin(rad);
	transform.matrix[2][2] = cos(rad);
	transform.matrix[3][3] = 1;
	return (transform);
}

t_matrix	rotate_y(double rad)
{
	t_matrix	transform;

	transform = create_matrix(4, 4);
	transform.matrix[0][0] = cos(rad);
	transform.matrix[1][1] = 1;
	transform.matrix[0][2] = sin(rad);
	transform.matrix[2][0] = -1 * sin(rad);
	transform.matrix[2][2] = cos(rad);
	transform.matrix[3][3] = 1;
	return (transform);
}

t_matrix	rotate_z(double rad)
{
	t_matrix	transform;

	transform = create_matrix(4, 4);
	transform.matrix[0][0] = cos(rad);
	transform.matrix[0][1] = -1 * sin(rad);
	transform.matrix[1][0] = sin(rad);
	transform.matrix[1][1] = cos(rad);
	transform.matrix[2][2] = 1;
	transform.matrix[3][3] = 1;
	return (transform);
}

t_matrix	shearing(t_shear shear)
{
	t_matrix	transform;

	transform = create_matrix(4, 4);
	transform.matrix[0][0] = 1;
	transform.matrix[1][1] = 1;
	transform.matrix[2][2] = 1;
	transform.matrix[3][3] = 1;
	transform.matrix[0][1] = shear.xy;
	transform.matrix[0][2] = shear.xz;
	transform.matrix[1][0] = shear.yx;
	transform.matrix[1][2] = shear.yz;
	transform.matrix[2][0] = shear.zx;
	transform.matrix[2][1] = shear.zy;
	return (transform);
}

t_matrix	create_id_matrix(void)
{
	t_matrix	idmatrix;

	idmatrix = create_matrix(4, 4);
	idmatrix.matrix[0][0] = 1;
	idmatrix.matrix[1][1] = 1;
	idmatrix.matrix[2][2] = 1;
	idmatrix.matrix[3][3] = 1;
	return (idmatrix);
}
