/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:55:21 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/07 22:07:29 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void		ft_pixelput(t_cam *cam,
int *coords, int color)
{
	char	*dst;

	dst = cam->address + (coords[1] * cam->line_leng + coords[0] * (cam->bpp / 8));
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
