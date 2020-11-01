/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:49:03 by lcouto            #+#    #+#             */
/*   Updated: 2020/11/01 17:42:51 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_matrix	create_matrix(int row, int col)
{
	t_matrix		new;
	int				i;
	int				j;

	i = 0;
	new.col = col;
	new.row = row;
	new.matrix = (double**)ec_malloc(sizeof(double*) * row);
	while (i < row)
	{
		new.matrix[i] = (double*)ec_malloc(sizeof(double) * col);
		j = 0;
		while (j < col)
		{
			new.matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new);
}

void		free_matrix(t_matrix matrix)
{
	size_t	i;

	i = 0;
	while (i < matrix.row)
	{
		free(matrix.matrix[i]);
		i++;
	}
	free(matrix.matrix);
}

int			comp_matrix(t_matrix m1, t_matrix m2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (m1.row != m2.row || m1.col != m2.col)
		return (0);
	while (i < m1.row)
	{
		j = 0;
		while (j < m1.col)
		{
			if (double_equal(m1.matrix[i][j], m2.matrix[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_matrix	mult_matrix(t_matrix m1, t_matrix m2)
{
	t_matrix	new;
	size_t		i;
	size_t		j;
	size_t		z;

	i = 0;
	new = create_matrix(m1.row, m1.col);
	while (i < new.row)
	{
		j = 0;
		while (j < new.col)
		{
			z = 0;
			while (z < new.row)
			{
				new.matrix[i][j] += (m1.matrix[i][z] * m2.matrix[z][j]);
				z++;
			}
			j++;
		}
		i++;
	}
	return (new);
}

t_tuple		mult_matrix_tuple(t_matrix m1, t_tuple t1)
{
	t_tuple		new_t;
	double		*new;
	size_t		i;
	size_t		j;
	double		current[4];

	i = 0;
	new = ec_calloc(4, sizeof(double));
	current[0] = t1.x;
	current[1] = t1.y;
	current[2] = t1.z;
	current[3] = t1.w;
	while (i < m1.row)
	{
		j = 0;
		while (j < m1.col)
		{
			new[i] += (m1.matrix[i][j] * current[j]);
			j++;
		}
		i++;
	}
	new_t = create_tuple(new[0], new[1], new[2], round(new[3]));
	free(new);
	return (new_t);
}
