/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:55:21 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/13 16:57:19 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void		ft_pixelput(t_cam *cam, int *coords,
t_mlx *mlx, int color)
{
	char	*dst;

	dst = cam->address + (coords[1] * mlx->line_leng +
	coords[0] * (mlx->bpp / 8));
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
