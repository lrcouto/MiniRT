/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:18:07 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/07 16:42:330 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	create_images(t_rt *rt, t_mlx *mlx)
{
	t_cam		*current_cam;

	current_cam = rt->cam;
	while (current_cam)
	{
		current_cam->img = mlx_new_image(mlx->mlx, rt->reso.width, rt->reso.height);
		current_cam->address = mlx_get_data_addr(current_cam->img, &mlx->bpp,
			&mlx->line_leng, &mlx->endian);
		raycaster(rt, mlx, current_cam);
		if (rt->savefile == 1)
			create_bmp(rt, mlx, current_cam);
		current_cam = current_cam->next;
	}
}

int			next_cam(int keycode, t_mlx *mlx)
{
	if (keycode == 0xFF1B)
		exit(0);
	if (keycode != 0x20)
	{	printf("keypress\n");
		return (0);
	}
	if (mlx->cam->next)
	{
		mlx->cam = mlx->cam->next;
		mlx_put_image_to_window(
				mlx->mlx, mlx->win, mlx->cam->img, 0, 0);
	}
	else
	{
		mlx->cam = mlx->begin;
		mlx_put_image_to_window(
				mlx->mlx, mlx->win, mlx->cam->img, 0, 0);
	}
	return (1);
}