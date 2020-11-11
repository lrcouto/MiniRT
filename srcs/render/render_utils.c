/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:40:12 by lcouto            #+#    #+#             */
/*   Updated: 2020/11/11 20:04:24 by lcouto           ###   ########.fr       */
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
