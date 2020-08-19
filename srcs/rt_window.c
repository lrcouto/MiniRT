/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:23:52 by lcouto            #+#    #+#             */
/*   Updated: 2020/08/18 18:27:38 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int		close_wndw(int keycode, t_mlx *mlx)
{
	if (keycode == 0xFF1B)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

void			rt_window(t_rt *rt)
{
	t_mlx	mlx;
	int		max_x;
	int		max_y;

	mlx.mlx = mlx_init();
	mlx_get_screen_size(mlx.mlx, &max_x, &max_y);
	if (rt->reso.width > max_x)
		rt->reso.width = max_x;
	if (rt->reso.height > max_y)
		rt->reso.height = max_y;
	if (rt->reso.width < 1 || rt->reso.height < 1)
	{
		printf("Error: invalid window size parameter");
		exit(0);
	}
	mlx.win = mlx_new_window(mlx.mlx, rt->reso.width, rt->reso.height, "A Window!");
	mlx_key_hook(mlx.win, close_wndw, &mlx);
	mlx_loop(mlx.mlx);
}
