/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:22:52 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/27 22:29:55 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_matrix	transpose_matrix(t_matrix src)
{
	t_matrix	new;
	size_t		i;
	size_t		j;

	new = create_matrix(src.row, src.col);
	i = 0;
	while (i < src.row)
	{
		j = 0;
		while (j < src.col)
		{
			new.matrix[i][j] = src.matrix[j][i];
			j++;
		}
		i++;
	}
	return (new);
}

t_matrix	get_submatrix(t_matrix src, int rmrow, int rmcol)
{
	t_matrix	new;
	size_t		i;
	size_t		j;
	int			x;
	int			y;

	new = create_matrix(src.row - 1, src.col - 1);
	x = 0;
	i = 0;
	while (i < new.row)
	{
		x = (x == rmrow) ? x + 1 : x;
		j = 0;
		y = 0;
		while (j < new.col)
		{
			y = (y == rmcol) ? y + 1 : y;
			new.matrix[i][j] = src.matrix[x][y];
			j++;
			y++;
		}
		i++;
		x++;
	}
	return (new);
}

double		det_2x2(t_matrix mat)
{
	double	result;

	result = mat.matrix[0][0] * mat.matrix[1][1] -
	mat.matrix[0][1] * mat.matrix[1][0];
	return (result);
}

double		det_3x3(t_matrix mat)
{
	double	result;

	result = (mat.matrix[0][0] * mat.matrix[1][1] * mat.matrix[2][2] +
			mat.matrix[0][1] * mat.matrix[1][2] * mat.matrix[2][0] +
			mat.matrix[0][2] * mat.matrix[1][0] * mat.matrix[2][1])
			-
			(mat.matrix[2][0] * mat.matrix[1][1] * mat.matrix[0][2] +
			mat.matrix[2][1] * mat.matrix[1][2] * mat.matrix[0][0] +
			mat.matrix[2][2] * mat.matrix[1][0] * mat.matrix[0][1]);
	return (result);
}

double		cofactor_4x4(t_matrix mat, int row, int col)
{
	double		cofactor;
	t_matrix	sub_mat;

	sub_mat = get_submatrix(mat, row, col);
	cofactor = (row + col) % 2 == 0 ? det_3x3(sub_mat) :
	(-1 * det_3x3(sub_mat));
	free_matrix(sub_mat);
	return (cofactor);
}
