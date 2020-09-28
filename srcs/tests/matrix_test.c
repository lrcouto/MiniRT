/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:37:58 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/27 22:25:42 by lcouto           ###   ########.fr       */
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
	t_matrix	test4;
	t_matrix	idmatrix;
	t_matrix	test5;
	t_matrix	test6;
	test4 = create_matrix(4, 4);
	test4.matrix[0][0] = 1;
	test4.matrix[0][1] = 1;
	test4.matrix[0][2] = 1;
	test4.matrix[0][3] = 1;
	test4.matrix[1][0] = 2;
	test4.matrix[1][1] = 2;
	test4.matrix[1][2] = 2;
	test4.matrix[1][3] = 2;
	test4.matrix[2][0] = 3;
	test4.matrix[2][1] = 3;
	test4.matrix[2][2] = 3;
	test4.matrix[2][3] = 3;
	test4.matrix[3][0] = 4;
	test4.matrix[3][1] = 4;
	test4.matrix[3][2] = 4;
	test4.matrix[3][3] = 4;
	i = 0;
	printf("\nMATRIZ INICIAL\n");
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf(" %f ", test4.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	idmatrix = create_matrix(4, 4);
	idmatrix.matrix[0][0] = 1;
	idmatrix.matrix[0][1] = 0;
	idmatrix.matrix[0][2] = 0;
	idmatrix.matrix[0][3] = 0;
	idmatrix.matrix[1][0] = 0;
	idmatrix.matrix[1][1] = 1;
	idmatrix.matrix[1][2] = 0;
	idmatrix.matrix[1][3] = 0;
	idmatrix.matrix[2][0] = 0;
	idmatrix.matrix[2][1] = 0;
	idmatrix.matrix[2][2] = 1;
	idmatrix.matrix[2][3] = 0;
	idmatrix.matrix[3][0] = 0;
	idmatrix.matrix[3][1] = 0;
	idmatrix.matrix[3][2] = 0;
	idmatrix.matrix[3][3] = 1;
	test5 = transpose_matrix(test4);
	test6 = transpose_matrix(idmatrix);
	i = 0;
	printf("\nMATRIZ TRANSPOSTA\n");
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf(" %f ", test5.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	printf("\nMATRIZ IDENTIDADE TRANSPOSTA\n");
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf(" %f ", test6.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free_matrix(test5);
	free_matrix(test6);
	i = 0;
	printf("\nMATRIZ QUE EU VOU TIRAR UMA SUB\n");
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf(" %f ", idmatrix.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	t_matrix	subm;
	subm = get_submatrix(idmatrix, 0, 0);
	size_t x;
	size_t y;
	x = 0;
	printf("\nSUBMATRIZ\n");
	while (x < subm.row)
	{
		y = 0;
		while (y < subm.col)
		{
			printf(" %f ", subm.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	free_matrix(idmatrix);
	double	result;
	result = det_3x3(subm);
	printf("\nDETERMINANTE: %f\n", result);
	t_matrix	test7;
	test7 = create_matrix(3,3);
	test7.matrix[0][0] = 3;
	test7.matrix[0][1] = 5;
	test7.matrix[0][2] = 0;
	test7.matrix[1][0] = 2;
	test7.matrix[1][1] = -1;
	test7.matrix[1][2] = -7;
	test7.matrix[2][0] = 6;
	test7.matrix[2][1] = -1;
	test7.matrix[2][2] = 5;
	x = 0;
	printf("\nMATRIZ INICIAL 3x3\n");
	while (x < test7.row)
	{
		y = 0;
		while (y < test7.col)
		{
			printf(" %f ", test7.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	result = det_3x3(test7);
	printf("\nDETERMINANTE: %f\n", result);
	free_matrix(subm);
	subm = get_submatrix(test7, 1, 0);
	x = 0;
	printf("\nSUBMATRIZ 2X2\n");
	while (x < subm.row)
	{
		y = 0;
		while (y < subm.col)
		{
			printf(" %f ", subm.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	result = det_2x2(subm);
	printf("\nDETERMINANTE: %f\n", result);
	free_matrix(subm);
	free_matrix(test7);
	free_matrix(test4);
	x = 0;
	printf("\nMATRIZ 4X4\n");
	while (x < test3.row)
	{
		y = 0;
		while (y < test3.col)
		{
			printf(" %f ", test3.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	result = det_4x4(test3);
	printf("\nDETERMINANTE MATRIZ 4X4: %f\n", result);
	free_matrix(test3);

/*
** 	TESTANDO INVERTER AS MATRIZES
*/

	t_matrix	mat_a;
	t_matrix	mat_b;
	t_matrix	mat_c;

	mat_a = create_matrix(4, 4);
	mat_a.matrix[0][0] = 8;
	mat_a.matrix[0][1] = -5;
	mat_a.matrix[0][2] = 9;
	mat_a.matrix[0][3] = 2;
	mat_a.matrix[1][0] = 7;
	mat_a.matrix[1][1] = 5;
	mat_a.matrix[1][2] = 6;
	mat_a.matrix[1][3] = 1;
	mat_a.matrix[2][0] = -6;
	mat_a.matrix[2][1] = 0;
	mat_a.matrix[2][2] = 9;
	mat_a.matrix[2][3] = 6;
	mat_a.matrix[3][0] = -3;
	mat_a.matrix[3][1] = 0;
	mat_a.matrix[3][2] = -9;
	mat_a.matrix[3][3] = -4;
	mat_b = create_matrix(4, 4);
	mat_b.matrix[0][0] = 9;
	mat_b.matrix[0][1] = 3;
	mat_b.matrix[0][2] = 0;
	mat_b.matrix[0][3] = 9;
	mat_b.matrix[1][0] = -5;
	mat_b.matrix[1][1] = -2;
	mat_b.matrix[1][2] = -6;
	mat_b.matrix[1][3] = -3;
	mat_b.matrix[2][0] = -4;
	mat_b.matrix[2][1] = 9;
	mat_b.matrix[2][2] = 6;
	mat_b.matrix[2][3] = 4;
	mat_b.matrix[3][0] = -7;
	mat_b.matrix[3][1] = 6;
	mat_b.matrix[3][2] = 6;
	mat_b.matrix[3][3] = 2;	
	mat_c = mult_matrix(mat_b, mat_a);
	x = 0;
	printf("\nMATRIZ A\n");
	while (x < mat_a.row)
	{
		y = 0;
		while (y < mat_a.col)
		{
			printf(" %f ", mat_a.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	t_matrix	inv_a;
	inv_a = invert_matrix(mat_a);
	x = 0;
	printf("\nMATRIZ A - INVERSO\n");
	while (x < inv_a.row)
	{
		y = 0;
		while (y < inv_a.col)
		{
			printf(" %f ", inv_a.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	x = 0;
	printf("\nMATRIZ B\n");
	while (x < mat_b.row)
	{
		y = 0;
		while (y < mat_b.col)
		{
			printf(" %f ", mat_b.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	t_matrix	inv_b;
	inv_b = invert_matrix(mat_b);
	x = 0;
	printf("\nMATRIZ B - INVERSO\n");
	while (x < inv_b.row)
	{
		y = 0;
		while (y < inv_b.col)
		{
			printf(" %f ", inv_b.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	t_matrix	comp_a;
	comp_a = mult_matrix(mat_c, inv_b);
	x = 0;
	printf("\nCOMP_A IGUAL MAT_A?: %d\n", comp_matrix(comp_a, mat_a));
	t_matrix	comp_b;
	comp_b = mult_matrix(mat_c, inv_a);
	x = 0;
	printf("\nCOMP_B IGUAL MAT_B?: %d\n", comp_matrix(comp_b, mat_b));
	x = 0;
	printf("\nCOMP_B\n");
	while (x < comp_b.row)
	{
		y = 0;
		while (y < comp_b.col)
		{
			printf(" %f ", comp_b.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	free_matrix(mat_a);
	free_matrix(mat_b);
	free_matrix(mat_c);
	free_matrix(inv_a);
	free_matrix(inv_b);
	free_matrix(comp_a);
	free_matrix(comp_b);
}