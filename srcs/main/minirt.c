/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:01:08 by lcouto            #+#    #+#             */
/*   Updated: 2021/02/15 14:26:28 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void		valid_rtfile(char *filename)
{
	int i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			if (filename[i + 1] == 'r' && filename[i + 2] == 't'
				&& filename[i + 3] == '\0')
				return ;
			else
				errormsg(30);
		}
		i++;
	}
	errormsg(30);
}

static void		check_savefile(t_rt *rt, char *arg)
{
	if (arg && (ft_strncmp(arg, "--save", 7) == 0))
		rt->savefile = 1;
}

static void		parse(t_rt *rt, int fd, t_mlx *mlx)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		rt_identify(line, rt, mlx);
		free(line);
	}
	rt_identify(line, rt, mlx);
	free(line);
	add_ambient_to_lights(rt);
	if (rt->reso.width == 0 || rt->reso.height == 0)
		errormsg(52);
	if (rt->qts.cam == 0)
		ft_putstr_fd(
		"You didn't set up any cameras. I can't render anything!\n", 1);
}

static int		expose_hook(t_mlx *mlx)
{
	return (mlx_put_image_to_window(
		mlx->mlx, mlx->win, mlx->cam->img, 0, 0));
}

int				main(int argc, char **argv)
{
	int		fd;
	t_rt	rt;
	t_mlx	mlx;

	init_rt(&rt);
	mlx.mlx = mlx_init();
	if (argc == 1)
		errormsg(0);
	else if (argc == 2 || (argc == 3 &&
	(ft_strncmp(argv[2], "--save", 7) == 0)))
	{
		check_savefile(&rt, argv[2]);
		valid_rtfile(argv[1]);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			errormsg(51);
	}
	else
		errormsg(1);
	parse(&rt, fd, &mlx);
	canvas(&rt, &mlx);
	mlx_hook(mlx.win, 33, 1L << 17, close_program, 0);
	mlx_hook(mlx.win, 2, 1, next_cam, &mlx);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
