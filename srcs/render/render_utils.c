/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:40:12 by lcouto            #+#    #+#             */
/*   Updated: 2020/11/12 16:07:43 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void		ft_pixelput(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->address + (y * mlx->line_leng + x * (mlx->bpp / 8));
	*(unsigned int*)dst = color;
}

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int			close_wndw(int keycode, t_mlx *mlx)
{
	if (keycode == 0xFF1B)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int			close_program(void *ptr)
{
	ptr = (void *)ptr;
	exit(0);
	return (1);
}

t_tuple		sphere_normal(t_sphere *sphere, t_tuple w_point)
{
	t_tuple		o_point;
	t_tuple		o_normal;
	t_tuple		w_normal;

	o_point = mult_matrix_tuple(invert_matrix(sphere->transform), w_point);
	o_normal = subtract_tuple(o_point, create_tuple(0, 0, 0, 1));
	w_normal = mult_matrix_tuple
(transpose_matrix(invert_matrix(sphere->transform)), o_normal);
	w_normal.w = 0;
	return (normalize_v(w_normal));
}

t_tuple		reflect(t_tuple in, t_tuple normal)
{
	return (subtract_tuple(in,
		scalar_x_tuple(normal,
		(2 * (dot_product(in, normal))))));
}

t_phong		default_phong(void)
{
	t_phong	new;
	
	new.color.r = 1;
	new.color.g = 1;
	new.color.b = 1;
	new.color.a = 1;
	new.diffuse = 0.9;
	new.ambient = 0.1;
	new.specular = 0.9;
	new.shininess = 200.0;
	return (new);
}