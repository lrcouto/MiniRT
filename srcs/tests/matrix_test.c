/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:37:58 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/26 22:35:23 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	matrix_test(int row, int col)
{
	t_matrix	test1;
	t_matrix	test2;
	t_matrix	mult;
	int			i;
	int			j;
	int			isequal;
	
	i = 0;
	test1 = create_matrix(row, col);
	test1.matrix[0][0] = 1;
	test1.matrix[0][1] = 2;
	test1.matrix[0][2] = 3;
	test1.matrix[0][3] = 4;
	test1.matrix[1][0] = 5;
	test1.matrix[1][1] = 6;
	test1.matrix[1][2] = 7;
	test1.matrix[1][3] = 8;
	test1.matrix[2][0] = 9;
	test1.matrix[2][1] = 8;
	test1.matrix[2][2] = 7;
	test1.matrix[2][3] = 6;
	test1.matrix[3][0] = 5;
	test1.matrix[3][1] = 4;
	test1.matrix[3][2] = 3;
	test1.matrix[3][3] = 2;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf(" %f ", test1.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	test2 = create_matrix(row, col);
    test2.matrix[0][0] = -2;
	test2.matrix[0][1] = 1;
	test2.matrix[0][2] = 2;
	test2.matrix[0][3] = 3;
	test2.matrix[1][0] = 3;
	test2.matrix[1][1] = 2;
	test2.matrix[1][2] = 1;
	test2.matrix[1][3] = -1;
	test2.matrix[2][0] = 4;
	test2.matrix[2][1] = 3;
	test2.matrix[2][2] = 6;
	test2.matrix[2][3] = 5;
	test2.matrix[3][0] = 1;
	test2.matrix[3][1] = 2;
	test2.matrix[3][2] = 7;
	test2.matrix[3][3] = 8;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf(" %f ", test2.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	isequal = comp_matrix(test1, test2);
	printf("\n");
	printf("ARE THEY EQUAL? %d\n", isequal);
	mult = mult_matrix(test1, test2);
	i = 0;
	printf("\n");
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf(" %f ", mult.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free_matrix(test1);
	free_matrix(test2);
	free_matrix(mult);

	t_matrix	test3;
	t_tuple		test_tup;
	t_tuple		res_tup;
	test3 = create_matrix(4, 4);
	test3.matrix[0][0] = 1;
	test3.matrix[0][1] = 2;
	test3.matrix[0][2] = 3;
	test3.matrix[0][3] = 4;
	test3.matrix[1][0] = 2;
	test3.matrix[1][1] = 4;
	test3.matrix[1][2] = 4;
	test3.matrix[1][3] = 2;
	test3.matrix[2][0] = 8;
	test3.matrix[2][1] = 6;
	test3.matrix[2][2] = 4;
	test3.matrix[2][3] = 1;
	test3.matrix[3][0] = 0;
	test3.matrix[3][1] = 0;
	test3.matrix[3][2] = 0;
	test3.matrix[3][3] = 1;
	test_tup = create_tuple(1, 2, 3, 1);
	res_tup = mult_matrix_tuple(test3, test_tup);
	printf("\n");
	printf("TUPLA MULTIPLICADA: %f, %f, %f, %d\n", res_tup.x, res_tup.y, res_tup.z, res_tup.w);
	free_matrix(test3);
}