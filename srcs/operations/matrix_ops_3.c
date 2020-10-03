/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <gsenra-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 22:27:42 by lcouto            #+#    #+#             */
/*   Updated: 2020/10/03 17:46:41 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double		det_4x4(t_matrix mat)
{
	double		*sub_cof;
	size_t		i;
	double		result;

	sub_cof = ec_malloc(sizeof(double) * 4);
	i = 0;
	while (i < mat.col)
	{
		sub_cof[i] = cofactor_4x4(mat, 0, i);
		i++;
	}
	result = mat.matrix[0][0] * sub_cof[0] + mat.matrix[0][1] * sub_cof[1]
		+ mat.matrix[0][2] * sub_cof[2] + mat.matrix[0][3] * sub_cof[3];
	free(sub_cof);
	return (result);
}

t_matrix	scalar_matrix(t_matrix mat, double times)
{
	t_matrix	new;
	size_t		i;
	size_t		j;

	i = 0;
	new = create_matrix(mat.row, mat.col);
	while (i < new.row)
	{
		j = 0;
		while (j < new.col)
		{
			new.matrix[i][j] = mat.matrix[i][j] * times;
			j++;
		}
		i++;
	}
	return (new);
}

t_matrix	invert_matrix(t_matrix mat)
{
	t_matrix		new;
	t_matrix		transp;
	double			det;
	size_t			i;
	size_t			j;

	new = create_matrix(mat.row, mat.col);
	det = det_4x4(mat);
	i = 0;
	while (i < mat.row)
	{
		j = 0;
		while (j < mat.col)
		{
			new.matrix[i][j] = cofactor_4x4(mat, i, j);
			j++;
		}
		i++;
	}
	transp = transpose_matrix(new);
	free_matrix(new);
	new = scalar_matrix(transp, 1 / det);
	free_matrix(transp);
	return (new);
}

t_matrix	translation(double x, double y, double z)
{
	t_matrix	transform;

	transform = create_matrix(4, 4);
	transform.matrix[0][0] = 1;
	transform.matrix[1][1] = 1;
	transform.matrix[2][2] = 1;
	transform.matrix[3][3] = 1;

	transform.matrix[0][3] = x;
	transform.matrix[1][3] = y;
	transform.matrix[2][3] = z;

	return (transform);
}
